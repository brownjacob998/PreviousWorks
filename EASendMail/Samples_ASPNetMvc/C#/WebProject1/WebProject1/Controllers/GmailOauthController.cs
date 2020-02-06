using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using WebProject1.Models;
using EASendMail;
using EASendMail.Oauth;

namespace WebProject1.Controllers
{
    public class GmailOauthController : Controller
    {
        // GET: GmailOauth
        public ActionResult Index()
        {
            var mailTask = _buildDefaultTask();
            return _mailView(mailTask);
        }

        ActionResult _mailView(MailTask mailTask)
        {
            ViewBag.Port = DropDownListData.PortList(mailTask.Port);
            return View("Index", mailTask);
        }

        void _setDefaultViewBagValue()
        {
            ViewBag.IsSyncSendSucceeded = false;
            ViewBag.SyncSendStatus = string.Empty;

            ViewBag.AutoAsyncSend = false;
            ViewBag.TokenIsExisted = false;
        }

        MailTask _buildDefaultTask()
        {
            var oauthWrapper = _initOauthWrapper();

            var mailTask = new MailTask();
            mailTask.Subject = "Test email from ASP.NET MVC with XOAUTH2";
            mailTask.IsAuthenticationRequired = true;
            mailTask.AuthType = SmtpAuthType.XOAUTH2;
            mailTask.Server = "smtp.gmail.com";
            mailTask.Port = 587;
            mailTask.IsSslConnection = true;
            mailTask.Sender = "unspecified"; // will be replaced after oauth is completed.

            var body = new StringBuilder();
            body.Append("This sample demonstrates how to send email from ASP.NET MVC with XOAUTH2.\r\n\r\n");
            body.Append("Please apply for your google client_id and client_secret as introduced in GoolgeOauthProvider.cs.\r\n");
            body.Append("If you got \"This app isn't verified\" information, please click \"advanced\" -> Go to ... for test.\r\n");

            mailTask.TextBody = body.ToString();

            _setDefaultViewBagValue();
            ViewBag.TokenIsExisted = !string.IsNullOrEmpty(oauthWrapper.OauthProvider.AccessToken);

            return mailTask;
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Index(MailTask mailTask)
        {
            _setDefaultViewBagValue();

            if (ModelState.IsValid)
            {
                try
                {
                    return _doOauth(mailTask);
                }
                catch (Exception ep)
                {
                    ViewBag.SyncSendStatus = ep.Message;
                }

                return _mailView(mailTask);
            }

            var OauthWrapper = _initOauthWrapper();
            ViewBag.TokenIsExisted = !string.IsNullOrEmpty(OauthWrapper.OauthProvider.AccessToken);

            return _mailView(mailTask);
        }

        // Please add http://localhost:54098/gmailoauth/token to Authorized redirect URIs in your Google project.
        // to learn more detail, please refer to GoogleOauthProvider.cs
        public ActionResult Token(string code, string state)
        {
            _setDefaultViewBagValue();

            MailTask mailTask = Services.TempMailTaskStore.GetTask(state);
            if (mailTask == null)
            {
                mailTask = _buildDefaultTask();

                ViewBag.SyncSendStatus = "Specified mail task is not found in temporal storage, please try it again.";
                return _mailView(mailTask);
            }

            var oauthWrapper = _initOauthWrapper();

            try
            {
                oauthWrapper.AuthorizationCode = code;
                oauthWrapper.RequestAccessTokenAndUserEmail();
            }
            catch (Exception ep)
            {
                ViewBag.SyncSendStatus = ep.Message;
                return _mailView(mailTask);
            }

            if (mailTask.IsAsyncTask)
            {
                ViewBag.IsSyncSendSucceeded = true;
                ViewBag.SyncSendStatus = "Oauth is completed, ready to send email.";

                // oauth is completed. back to view and invoke AutoAsyncSend.
                ViewBag.AutoAsyncSend = true;
                ViewBag.TokenIsExisted = !string.IsNullOrEmpty(oauthWrapper.OauthProvider.AccessToken);
                return _mailView(mailTask);
            }

            return _syncSendMail(mailTask);
        }

        private ActionResult _doOauth(MailTask mailTask)
        {
            _setDefaultViewBagValue();

            var oauthWrapper = _initOauthWrapper();
            if (!string.IsNullOrEmpty(oauthWrapper.OauthProvider.AccessToken))
            {
                if (!oauthWrapper.IsAccessTokenExpired)
                {
                    return _syncSendMail(mailTask);
                }

                try
                {
                    oauthWrapper.RefreshAccessToken();
                    return _syncSendMail(mailTask);
                }
                catch
                {
                    // "Failed to refresh access token, try to get a new access token ...";
                }
            }

            Services.TempMailTaskStore.PutTask(mailTask);
            return Redirect(oauthWrapper.OauthProvider.GenerateFullAuthUri() + "&state=" + mailTask.TaskId);
        }

        private ActionResult _syncSendMail(MailTask mailTask)
        {
            var oauthWrapper = _initOauthWrapper();
            ViewBag.TokenIsExisted = !string.IsNullOrEmpty(oauthWrapper.OauthProvider.AccessToken);

            try
            {
                mailTask.AuthType = SmtpAuthType.XOAUTH2;
                mailTask.User = oauthWrapper.OauthProvider.UserEmail;
                mailTask.Password = oauthWrapper.OauthProvider.AccessToken;
                mailTask.IsAuthenticationRequired = true;
          
                // always set From to authenticated user.
                mailTask.Sender = oauthWrapper.OauthProvider.UserEmail;      

                var smtp = new SmtpClient();
                var server = mailTask.BuildServer();
                var mail = mailTask.BuildMail();

                smtp.SendMail(server, mail);

                ViewBag.IsSyncSendSucceeded = true;
                ViewBag.SyncSendStatus = "Message has been submitted to server successfully.";
            }
            catch (Exception ep)
            {
                ViewBag.IsSyncSendSucceeded = false;
                ViewBag.SyncSendStatus = ep.Message;
            }

            mailTask.TaskId = Guid.NewGuid().ToString();
            return _mailView(mailTask);
        }

        // access token is existed, submit email directly from ajax send.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult AsyncSend(MailTask mailTask)
        {
            var oauthWrapper = _initOauthWrapper();
            if (oauthWrapper.IsAccessTokenExpired)
            {

                try
                {
                    oauthWrapper.RefreshAccessToken();
                }
                catch
                {
                    Services.AsyncSendMailService.PutErrorStatus(mailTask.TaskId, "Failed to refresh access token.");
                    return Content(mailTask.TaskId);
                }
            }

            mailTask.AuthType = SmtpAuthType.XOAUTH2;
            mailTask.User = oauthWrapper.OauthProvider.UserEmail;
            mailTask.Password = oauthWrapper.OauthProvider.AccessToken;
            mailTask.IsAuthenticationRequired = true;

            // always set From to authenticated user.
            mailTask.Sender = oauthWrapper.OauthProvider.UserEmail;

            Services.AsyncSendMailService.CreateAsyncTask(mailTask);
            return Content(mailTask.TaskId);
        }

        public ActionResult QueryAsyncTask(string id)
        {
            Services.AsyncSendMailStatus status = Services.AsyncSendMailService.QueryStatus(id);
            if (status == null)
            {
                status = new Services.AsyncSendMailStatus();
                status.TaskId = id;
                status.Completed = true;
                status.HasError = true;
                status.Status = "Invalid Task ID";
            }
            return Json(status, JsonRequestBehavior.AllowGet);
        }

        public ActionResult ClearToken()
        {
            var oauthWrapper = _initOauthWrapper();
            oauthWrapper.OauthProvider.ClearToken();
            oauthWrapper.AuthorizationCode = "";
            return Content("OK");
        }

        private OauthWebWrapper _initOauthWrapper()
        {
            var OauthWrapper = Session["OauthWrapper"] as OauthWebWrapper;
            if (OauthWrapper != null)
            {
                return OauthWrapper;
            }

            /*
            To use Google OAUTH in your application, you must create a project in Google Developers Console.

         - Create your project at https://console.developers.google.com/project.
         - Select your project -> APIs & Services -> Dashboard -> Credentials;
         - Credentials -> Create Credentials -> OAuth client ID -> Web application or Other (Desktop Application). 
             It depends on your application type.

         - Input a name for your application, input your current ASP/ASP.NET URL at Authorized redirect URIs, 
             for example: http://localhost/gmailoauth/default.aspx. (Desktop Application doesn't require this step)
             Click "Create", you will get your client id and client secret.

         - Finally you can also set detail information for your project at Credentials -> OAuth consent screen.
         - If you used https://mail.google.com scope, you should verify your application that is inroduced in cosent screen.
             If you don't verify your application, your application is limited by some conditions.

         You must apply for your client id and client secret, don't use the client id in the sample project, because it is limited now.
         If you got \"This app isn't verified\" information, please click \"advanced\" -> Go to ... for test.
             */
            OauthProviderInterface provider = GoogleOauthProvider.Create("1072602369179-prgq7tkc834li6ao3fd11r6f2mpc1hdq.apps.googleusercontent.com",
                            "zRqEjYMLJwvfacYA_vUH_6M4",
                            "email%20profile%20https://mail.google.com",
                            "http://localhost:54098/gmailoauth/token"); // add this to Authorized redirect URIs

            OauthWrapper = new OauthWebWrapper(provider);
            Session["OauthWrapper"] = OauthWrapper;
            return OauthWrapper;
        }
    }
}