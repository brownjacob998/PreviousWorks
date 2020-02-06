Imports System.Web.Mvc
Imports EASendMail

Namespace Controllers
    Public Class GmailOauthController
        Inherits Controller

        ' GET: GmailOauth
        Function Index() As ActionResult
            Dim myTask = _buildDefaultTask()
            Return _mailView(myTask)
        End Function

        <HttpPost>
        <ValidateAntiForgeryToken>
        Public Function Index(ByVal myTask As MailTask) As ActionResult
            _setDefaultViewBagValue()

            If ModelState.IsValid Then

                Try
                    Return _doOauth(myTask)
                Catch ep As Exception
                    ViewBag.SyncSendStatus = ep.Message
                End Try

                Return _mailView(myTask)
            End If

            Dim OauthWrapper = _initOauthWrapper()
            ViewBag.TokenIsExisted = Not String.IsNullOrEmpty(OauthWrapper.OauthProvider.AccessToken)
            Return _mailView(myTask)
        End Function

        ' Please add http://localhost:55659/gmailoauth/token to Authorized redirect URIs in your Google project.
        ' to learn more detail, please refer to GoogleOauthProvider.cs
        Public Function Token(ByVal code As String, ByVal state As String) As ActionResult
            _setDefaultViewBagValue()
            Dim myTask As MailTask = TempMailTaskStore.GetTask(state)

            If myTask Is Nothing Then
                myTask = _buildDefaultTask()
                ViewBag.SyncSendStatus = "Specified mail task is not found in temporal storage, please try it again."
                Return _mailView(myTask)
            End If

            Dim oauthWrapper = _initOauthWrapper()

            Try
                oauthWrapper.AuthorizationCode = code
                oauthWrapper.RequestAccessTokenAndUserEmail()
            Catch ep As Exception
                ViewBag.SyncSendStatus = ep.Message
                Return _mailView(myTask)
            End Try

            If myTask.IsAsyncTask Then
                ViewBag.IsSyncSendSucceeded = True
                ViewBag.SyncSendStatus = "Oauth is completed, ready to send email."
                ViewBag.AutoAsyncSend = True
                ViewBag.TokenIsExisted = Not String.IsNullOrEmpty(oauthWrapper.OauthProvider.AccessToken)
                Return _mailView(myTask)
            End If

            Return _syncSendMail(myTask)
        End Function

        ' Access token is existed, submit email directly from ajax send.
        <HttpPost>
        <ValidateAntiForgeryToken>
        Public Function AsyncSend(ByVal myTask As MailTask) As ActionResult
            Dim oauthWrapper = _initOauthWrapper()

            If oauthWrapper.IsAccessTokenExpired Then

                Try
                    oauthWrapper.RefreshAccessToken()
                Catch
                    AsyncSendMailService.PutErrorStatus(myTask.TaskId, "Failed to refresh access token.")
                    Return Content(myTask.TaskId)
                End Try
            End If

            myTask.AuthType = SmtpAuthType.XOAUTH2
            myTask.User = oauthWrapper.OauthProvider.UserEmail
            myTask.Password = oauthWrapper.OauthProvider.AccessToken
            myTask.IsAuthenticationRequired = True
            myTask.Sender = oauthWrapper.OauthProvider.UserEmail

            AsyncSendMailService.CreateAsyncTask(myTask)
            Return Content(myTask.TaskId)
        End Function

        Public Function QueryAsyncTask(ByVal id As String) As ActionResult
            Dim status As AsyncSendMailStatus = AsyncSendMailService.QueryStatus(id)

            If status Is Nothing Then
                status = New AsyncSendMailStatus()
                status.TaskId = id
                status.Completed = True
                status.HasError = True
                status.Status = "Invalid Task ID"
            End If

            Return Json(status, JsonRequestBehavior.AllowGet)
        End Function

        Public Function ClearToken() As ActionResult
            Dim oauthWrapper = _initOauthWrapper()
            oauthWrapper.OauthProvider.ClearToken()
            oauthWrapper.AuthorizationCode = ""
            Return Content("OK")
        End Function

        Private Function _mailView(ByVal myTask As MailTask) As ActionResult
            ViewBag.Port = DropDownListData.PortList(myTask.Port)
            Return View("Index", myTask)
        End Function

        Private Sub _setDefaultViewBagValue()
            ViewBag.IsSyncSendSucceeded = False
            ViewBag.SyncSendStatus = String.Empty
            ViewBag.AutoAsyncSend = False
            ViewBag.TokenIsExisted = False
        End Sub

        Private Function _buildDefaultTask() As MailTask
            Dim oauthWrapper = _initOauthWrapper()
            Dim myTask = New MailTask()
            myTask.Subject = "Test email from ASP.NET MVC with XOAUTH2"
            myTask.IsAuthenticationRequired = True
            myTask.AuthType = SmtpAuthType.XOAUTH2
            myTask.Server = "smtp.gmail.com"
            myTask.Port = 587
            myTask.IsSslConnection = True
            myTask.Sender = "unspecified"

            Dim body = New StringBuilder()
            body.Append("This sample demonstrates how to send email from ASP.NET MVC with XOAUTH2." & vbCrLf & vbCrLf)
            body.Append("Please apply for your google client_id and client_secret as introduced in GoolgeOauthProvider.cs." & vbCrLf)
            body.Append("If you got ""This app isn't verified"" information, please click ""advanced"" -> Go to ... for test." & vbCrLf)
            myTask.TextBody = body.ToString()

            _setDefaultViewBagValue()
            ViewBag.TokenIsExisted = Not String.IsNullOrEmpty(oauthWrapper.OauthProvider.AccessToken)
            Return myTask
        End Function

        Private Function _doOauth(ByVal myTask As MailTask) As ActionResult
            _setDefaultViewBagValue()
            Dim oauthWrapper = _initOauthWrapper()

            If Not String.IsNullOrEmpty(oauthWrapper.OauthProvider.AccessToken) Then

                If Not oauthWrapper.IsAccessTokenExpired Then
                    Return _syncSendMail(myTask)
                End If

                Try
                    oauthWrapper.RefreshAccessToken()
                    Return _syncSendMail(myTask)
                Catch
                End Try
            End If

            TempMailTaskStore.PutTask(myTask)
            Return Redirect(oauthWrapper.OauthProvider.GenerateFullAuthUri() & "&state=" + myTask.TaskId)
        End Function

        Private Function _syncSendMail(ByVal myTask As MailTask) As ActionResult
            Dim oauthWrapper = _initOauthWrapper()
            ViewBag.TokenIsExisted = Not String.IsNullOrEmpty(oauthWrapper.OauthProvider.AccessToken)

            Try
                myTask.AuthType = SmtpAuthType.XOAUTH2
                myTask.User = oauthWrapper.OauthProvider.UserEmail
                myTask.Password = oauthWrapper.OauthProvider.AccessToken
                myTask.IsAuthenticationRequired = True

                myTask.Sender = oauthWrapper.OauthProvider.UserEmail
                Dim smtp = New SmtpClient()

                Dim server = myTask.BuildServer()
                Dim mail = myTask.BuildMail()

                smtp.SendMail(server, mail)

                ViewBag.IsSyncSendSucceeded = True
                ViewBag.SyncSendStatus = "Message has been submitted to server successfully."
            Catch ep As Exception
                ViewBag.IsSyncSendSucceeded = False
                ViewBag.SyncSendStatus = ep.Message
            End Try

            myTask.TaskId = Guid.NewGuid().ToString()
            Return _mailView(myTask)
        End Function

        '   To use Google OAUTH in your application, you must create a project in Google Developers Console.
        '
        '   - Create your project at https://console.developers.google.com/project.
        '   - Select your project -> APIs & Services -> Dashboard -> Credentials;
        '   - Credentials -> Create Credentials -> OAuth client ID -> Web application or Other (Desktop Application). 
        '       It depends on your application type.
        '
        '   - Input a name for your application, input your current ASP/ASP.NET URL at Authorized redirect URIs, 
        '       for example: http://localhost/gmailoauth/default.aspx. (Desktop Application doesn't require this step)
        '       Click "Create", you will get your client id and client secret.
        '
        '   - Finally you can also set detail information for your project at Credentials -> OAuth consent screen.
        '   - If you used https://mail.google.com scope, you should verify your application that is inroduced in cosent screen.
        '       If you don't verify your application, your application is limited by some conditions.
        '
        '   You must apply for your client id and client secret, don't use the client id in the sample project, because it is limited now.
        '   If you got "This app isn't verified" information, please click "advanced" -> Go to ... for test.
        ' 
        Private Function _initOauthWrapper() As OauthWebWrapper
            Dim OauthWrapper = TryCast(Session("OauthWrapper"), OauthWebWrapper)

            If OauthWrapper IsNot Nothing Then
                Return OauthWrapper
            End If

            Dim provider As OauthProviderInterface =
                GoogleOauthProvider.Create("1072602369179-prgq7tkc834li6ao3fd11r6f2mpc1hdq.apps.googleusercontent.com",
                                           "zRqEjYMLJwvfacYA_vUH_6M4",
                                           "email%20profile%20https://mail.google.com",
                                           "http://localhost:55659/gmailoauth/token") ' add this to Authorized redirect URIs

            OauthWrapper = New OauthWebWrapper(provider)
            Session("OauthWrapper") = OauthWrapper
            Return OauthWrapper
        End Function
    End Class
End Namespace