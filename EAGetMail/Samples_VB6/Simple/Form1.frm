VERSION 5.00
Object = "{EAB22AC0-30C1-11CF-A7EB-0000C05BAE0B}#1.1#0"; "shdocvw.dll"
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   7200
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   11700
   LinkTopic       =   "Form1"
   ScaleHeight     =   7200
   ScaleWidth      =   11700
   StartUpPosition =   3  'Windows Default
   Begin MSComctlLib.StatusBar textStatus 
      Align           =   2  'Align Bottom
      Height          =   375
      Left            =   0
      TabIndex        =   23
      Top             =   6825
      Width           =   11700
      _ExtentX        =   20638
      _ExtentY        =   661
      Style           =   1
      _Version        =   393216
      BeginProperty Panels {8E3867A5-8586-11D1-B16A-00C0F0283628} 
         NumPanels       =   1
         BeginProperty Panel1 {8E3867AB-8586-11D1-B16A-00C0F0283628} 
         EndProperty
      EndProperty
   End
   Begin VB.ComboBox lstDateRange 
      Height          =   315
      Left            =   240
      Style           =   2  'Dropdown List
      TabIndex        =   14
      Top             =   4920
      Width           =   3135
   End
   Begin VB.CheckBox chkNewOnly 
      Caption         =   "Retrieve new email only(IMAP,EWS,WebDAV)"
      Height          =   495
      Left            =   240
      TabIndex        =   13
      Top             =   4320
      Width           =   3015
   End
   Begin SHDocVwCtl.WebBrowser webMail 
      Height          =   3375
      Left            =   3840
      TabIndex        =   21
      Top             =   3360
      Width           =   7695
      ExtentX         =   13573
      ExtentY         =   5953
      ViewMode        =   0
      Offline         =   0
      Silent          =   0
      RegisterAsBrowser=   0
      RegisterAsDropTarget=   1
      AutoArrange     =   0   'False
      NoClientEdge    =   0   'False
      AlignLeft       =   0   'False
      NoWebView       =   0   'False
      HideFileNames   =   0   'False
      SingleClick     =   0   'False
      SingleSelection =   0   'False
      NoFolders       =   0   'False
      Transparent     =   0   'False
      ViewID          =   "{0057D0E0-3573-11CF-AE69-08002B2E1262}"
      Location        =   ""
   End
   Begin VB.CommandButton btnDel 
      Caption         =   "Delete"
      Height          =   375
      Left            =   10200
      TabIndex        =   20
      Top             =   2880
      Width           =   1335
   End
   Begin MSComctlLib.ListView lstMail 
      Height          =   2535
      Left            =   3840
      TabIndex        =   19
      Top             =   240
      Width           =   7695
      _ExtentX        =   13573
      _ExtentY        =   4471
      SortKey         =   3
      View            =   3
      LabelEdit       =   1
      SortOrder       =   -1  'True
      Sorted          =   -1  'True
      LabelWrap       =   -1  'True
      HideSelection   =   0   'False
      FullRowSelect   =   -1  'True
      _Version        =   393217
      ForeColor       =   -2147483640
      BackColor       =   -2147483643
      BorderStyle     =   1
      Appearance      =   1
      NumItems        =   4
      BeginProperty ColumnHeader(1) {BDD1F052-858B-11D1-B16A-00C0F0283628} 
         Text            =   "From"
         Object.Width           =   4410
      EndProperty
      BeginProperty ColumnHeader(2) {BDD1F052-858B-11D1-B16A-00C0F0283628} 
         SubItemIndex    =   1
         Text            =   "Subject"
         Object.Width           =   6174
      EndProperty
      BeginProperty ColumnHeader(3) {BDD1F052-858B-11D1-B16A-00C0F0283628} 
         SubItemIndex    =   2
         Text            =   "Date"
         Object.Width           =   3528
      EndProperty
      BeginProperty ColumnHeader(4) {BDD1F052-858B-11D1-B16A-00C0F0283628} 
         SubItemIndex    =   3
         Text            =   "SortValue"
         Object.Width           =   2
      EndProperty
   End
   Begin VB.Frame Frame1 
      Caption         =   "Account Information"
      Height          =   6255
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   3495
      Begin MSComctlLib.ProgressBar pgBar 
         Height          =   255
         Left            =   120
         TabIndex        =   17
         Top             =   5880
         Width           =   3135
         _ExtentX        =   5530
         _ExtentY        =   450
         _Version        =   393216
         Appearance      =   1
      End
      Begin VB.CommandButton btnCancel 
         Caption         =   "Cancel"
         Enabled         =   0   'False
         Height          =   375
         Left            =   1800
         TabIndex        =   16
         Top             =   5400
         Width           =   1455
      End
      Begin VB.CommandButton btnStart 
         Caption         =   "Start"
         Height          =   375
         Left            =   120
         TabIndex        =   15
         Top             =   5400
         Width           =   1455
      End
      Begin VB.CheckBox chkLeaveCopy 
         Caption         =   "Leave a copy of message on server"
         Height          =   375
         Left            =   120
         TabIndex        =   12
         Top             =   3000
         Value           =   1  'Checked
         Width           =   3015
      End
      Begin VB.ComboBox lstProtocol 
         Height          =   315
         Left            =   1080
         Style           =   2  'Dropdown List
         TabIndex        =   11
         Top             =   2580
         Width           =   2175
      End
      Begin VB.ComboBox lstAuthType 
         Height          =   315
         Left            =   1080
         Style           =   2  'Dropdown List
         TabIndex        =   9
         Top             =   2100
         Width           =   2175
      End
      Begin VB.CheckBox chkSSL 
         Caption         =   "SSL Connection"
         Height          =   375
         Left            =   120
         TabIndex        =   7
         Top             =   1680
         Value           =   1  'Checked
         Width           =   2895
      End
      Begin VB.TextBox textPassword 
         Height          =   285
         IMEMode         =   3  'DISABLE
         Left            =   1080
         PasswordChar    =   "*"
         TabIndex        =   6
         Top             =   1275
         Width           =   2175
      End
      Begin VB.TextBox textUser 
         Height          =   285
         Left            =   1080
         TabIndex        =   5
         Top             =   795
         Width           =   2175
      End
      Begin VB.TextBox textServer 
         Height          =   285
         Left            =   1080
         TabIndex        =   4
         Top             =   315
         Width           =   2175
      End
      Begin VB.Label Label5 
         AutoSize        =   -1  'True
         Caption         =   "Protocol"
         Height          =   195
         Left            =   120
         TabIndex        =   10
         Top             =   2640
         Width           =   585
      End
      Begin VB.Label Label4 
         AutoSize        =   -1  'True
         Caption         =   "Auth Type"
         Height          =   195
         Left            =   120
         TabIndex        =   8
         Top             =   2160
         Width           =   735
      End
      Begin VB.Label Label3 
         AutoSize        =   -1  'True
         Caption         =   "Password"
         Height          =   195
         Left            =   120
         TabIndex        =   3
         Top             =   1320
         Width           =   690
      End
      Begin VB.Label Label2 
         AutoSize        =   -1  'True
         Caption         =   "User"
         Height          =   195
         Left            =   120
         TabIndex        =   2
         Top             =   840
         Width           =   330
      End
      Begin VB.Label Label1 
         AutoSize        =   -1  'True
         Caption         =   "Server"
         Height          =   195
         Left            =   120
         TabIndex        =   1
         Top             =   360
         Width           =   465
      End
      Begin VB.Label Label6 
         Caption         =   "Warning: if ""leave a copy of message on server"" is not checked,  the emails on the server will be deleted !"
         ForeColor       =   &H8000000D&
         Height          =   735
         Left            =   120
         TabIndex        =   18
         Top             =   3480
         Width           =   3135
      End
   End
   Begin VB.Label lblTotal 
      AutoSize        =   -1  'True
      Caption         =   "Total"
      Height          =   195
      Left            =   3840
      TabIndex        =   22
      Top             =   2940
      Width           =   360
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'  ===============================================================================
' |    THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF      |
' |    ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO    |
' |    THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A         |
' |    PARTICULAR PURPOSE.                                                    |
' |    Copyright (c)2010 - 2019  ADMINSYSTEM SOFTWARE LIMITED                         |
' |
' |    Project: It demonstrates how to use EAGetMailObj to receive/parse email.
' |
' |
' |    File: Form1 : implementation file
' |
' |    Author: Ivan Lui ( ivan@emailarchitect.net )
'  ===============================================================================
Option Explicit

' Connection Type
Const MailServerConnectType_ConnectSSLAuto = 0
Const MailServerConnectType_ConnectSSL = 1
Const MailServerConnectType_ConnectTLS = 2

' Proxy, EWS/WebDAV doesn't support proxy server
Const ProxyType_Socks4 = 0
Const ProxyType_Socks5 = 1
Const ProxyType_Http = 2

' Auth Type
Const MailServerAuthLogin = 0
Const MailServerAuthCRAM5 = 1
Const MailServerAuthNTLM = 2
Const MailServerAuthXOAUTH2 = 3

' Oauth wrapper for Gmail XOAUTH2
Public Oauth As New OauthWrapper

' Mail Server Protocols
Const MailServerPop3 = 0
Const MailServerImap4 = 1
Const MailServerEWS = 2 'Exchange Web Service, Exchange 2007/2010
Const MailServerDAV = 3 'Exchange WebDAV, Exchange 2000/2003

' GetMailInfosParam Flags
Const GetMailInfos_All = 1
Const GetMailInfos_NewOnly = 2
Const GetMailInfos_ReadOnly = 4
Const GetMailInfos_SeqRange = 8
Const GetMailInfos_UIDRange = 16
Const GetMailInfos_PR_ENTRYID = 32
Const GetMailInfos_DateRange = 64
Const GetMailInfos_OrderByDateTime = 128

' MailClient with Event Handler
Private WithEvents oClient As EAGetMailObjLib.MailClient
Attribute oClient.VB_VarHelpID = -1
' Common Helper
Private oTools As New EAGetMailObjLib.Tools

' Cancel current operation flag
Private m_bCancel As Boolean
Private m_currentPath As String

'=========================================================
' Begin AutoResizeControl
'=========================================================
Private formWidth As Long
Private formHeight  As Long
Private lstMailWidthOffset As Long
Private btnDelLeftOffset As Long
Private webMailHeightOffset As Long

Private Sub InitResize()

    formWidth = Form1.Width
    formHeight = Form1.Height
    
    lstMailWidthOffset = Form1.Width - lstMail.Width
    webMailHeightOffset = Form1.Height - webMail.Height
    btnDelLeftOffset = Form1.Width - btnDel.Left

End Sub

Private Sub AutoResizeControl()

On Error Resume Next
    If Form1.Width < formWidth Then
        Form1.Width = formWidth
    End If
    
    If Form1.Height < formHeight Then
        Form1.Height = formHeight
    End If
    
    lstMail.Width = Form1.Width - lstMailWidthOffset
    btnDel.Left = Form1.Width - btnDelLeftOffset
    
    webMail.Width = lstMail.Width
    webMail.Height = Form1.Height - webMailHeightOffset
    
End Sub

Private Sub Form_Resize()
   AutoResizeControl
End Sub
'=========================================================
' End AutoResizeControl
'=========================================================

Private Sub Form_Load()

    InitResize
    
    webMail.Navigate "about:blank"
    
    m_currentPath = App.Path
    
    ' Initialize authentication type
    lstAuthType.AddItem "USER/AUTH LOGIN"
    lstAuthType.AddItem "APOP(CRAM-MD5)"
    lstAuthType.AddItem "NTLM"
    lstAuthType.AddItem "Gmail XOAUTH2"
    
    lstAuthType.ListIndex = 0
    
    ' Initialize date range
    lstDateRange.AddItem "All emails"
    lstDateRange.AddItem "Last 7 days"
    lstDateRange.AddItem "Last 30 days"
    lstDateRange.AddItem "Last 60 days"
    lstDateRange.AddItem "Last 90 days"
    
    lstDateRange.ListIndex = 0
    
    ' Initialize server protocols
    lstProtocol.AddItem "POP3"
    lstProtocol.AddItem "IMAP4"
    lstProtocol.AddItem "Exchange Web Service - Exchange 2007/2010"
    lstProtocol.AddItem "Exchange WebDAV - Exchange 2000/2003"
    lstProtocol.ListIndex = 0
    
    m_bCancel = False
    
    textStatus.SimpleText = ""
    
    pgBar.Min = 0
    pgBar.Max = 100
    pgBar.value = 0
    
    LoadLocalMails
    
    If lstMail.ListItems.Count > 0 Then
        lstMail.ListItems.Item(1).Selected = True
    End If

End Sub

Private Sub lstAuthType_Click()

    If lstAuthType.ListIndex = MailServerAuthXOAUTH2 Then
        lstProtocol.ListIndex = MailServerImap4
        textServer.Text = "imap.gmail.com"
        
        chkSSL.value = Checked
        ' Get user and access token from FormOauth
        textUser.Enabled = False
        textPassword.Enabled = False
        textUser.BackColor = &H8000000F
        textPassword.BackColor = &H8000000F
        
        textStatus.SimpleText = "Please click ""Start"" to login Gmail by Web OAUTH!"
    Else
        textUser.Enabled = True
        textPassword.Enabled = True
        
        textUser.BackColor = &H80000005
        textPassword.BackColor = &H80000005
        
        ' Clear existed access token
        Oauth.Clear
        textStatus.SimpleText = ""
    End If

End Sub

' By default, Exchange Web Service requires SSL connection.
' For other protocol, please set SSL connection based on your server setting manually
' Pop3 doesn't support to get new email only, or retrieve email by date range.
Private Sub lstProtocol_Click()

    If lstProtocol.ListIndex = MailServerPop3 Then
        chkNewOnly.value = Unchecked
        chkNewOnly.Enabled = False
        
        lstDateRange.ListIndex = 0
        lstDateRange.Enabled = False
    Else
        chkNewOnly.Enabled = True
        lstDateRange.Enabled = True
    End If
    
    If lstProtocol.ListIndex = MailServerEWS Then
        chkSSL.value = Checked 'By default, Exchange Web Service requires SSL
    End If

End Sub

Private Function BuildServer()

    Dim oServer As New EAGetMailObjLib.MailServer
    
    oServer.Server = Trim(textServer.Text)
    oServer.User = Trim(textUser.Text)
    oServer.Password = Trim(textPassword.Text)

    oServer.SSLConnection = chkSSL.value
    oServer.AuthType = lstAuthType.ListIndex
    oServer.Protocol = lstProtocol.ListIndex
    
    If lstProtocol.ListIndex = MailServerImap4 Then
        If oServer.SSLConnection Then
            oServer.Port = 993 'SSL IMAP4
        Else
            oServer.Port = 143 'IMAP4 normal
        End If
    Else
        If oServer.SSLConnection Then
            oServer.Port = 995 'SSL POP3
        Else
            oServer.Port = 110 'POP3 normal
        End If
    End If

    Set BuildServer = oServer

End Function

Private Function ValidateInput()

    ValidateInput = False
    
    textServer.Text = Trim(textServer.Text)
    textUser.Text = Trim(textUser.Text)
    textPassword.Text = Trim(textPassword.Text)
    
    If textServer.Text = "" Then
        MsgBox "Please input server address!"
        textServer.Enabled = True
        textServer.SetFocus
        Exit Function
    End If

    If textUser.Text = "" Then
        MsgBox "Please input user name!"
        textUser.Enabled = True
        textUser.SetFocus
        Exit Function
    End If

    If textPassword.Text = "" Then
        MsgBox "Please input password!"
        textPassword.Enabled = True
        textPassword.SetFocus
        Exit Function
    End If

    ValidateInput = True

End Function

Private Function TryOauth()
    
    If lstAuthType.ListIndex <> MailServerAuthXOAUTH2 Then
        ' We don't need to login user by Gmail XOAUTH
        TryOauth = True
        Exit Function
    End If

    TryOauth = False
    
    If Oauth.AccessToken <> "" Then
        If Not Oauth.AccessTokenIsExpired() Then
           TryOauth = True
           Exit Function
        End If
        
        textStatus.SimpleText = "Refresh expired access token from server ..."
        If Oauth.RefreshAccessToken() Then
            TryOauth = True
            Exit Function
        End If
        
        Oauth.ClearError
        textStatus.SimpleText = "Failed to refresh expired access token, now request new token again ..."
    End If
    
    FormOauth.Show 1, Me
    If Oauth.AuthorizationCode = "" Then
        textStatus.SimpleText = "Failed to login user and get authorization code."
        Exit Function
    End If
    
    textStatus.SimpleText = "Request access token from server ..."
    If Not Oauth.RequestAccessTokenAndUserEmail() Then
        textStatus.SimpleText = Oauth.GetLastError()
        Exit Function
    End If
    
    TryOauth = True

End Function

Private Sub SetMailRange()
    
    oClient.GetMailInfosParam.Reset

    If lstProtocol.ListIndex = MailServerPop3 Then
        ' POP3 protocol doesn't support mail range.
        Exit Sub
    End If

    If chkNewOnly.value = Checked Then
        ' Retrieve new emails only.
        oClient.GetMailInfosParam.GetMailInfosOptions = (oClient.GetMailInfosParam.GetMailInfosOptions Or GetMailInfos_NewOnly)
    End If

    If lstDateRange.ListIndex = 0 Then
        ' Retrieve all emails.
        Exit Sub
    End If

    oClient.GetMailInfosParam.GetMailInfosOptions = (oClient.GetMailInfosParam.GetMailInfosOptions Or GetMailInfos_DateRange)

    Dim dateSince As Date

    Select Case lstDateRange.ListIndex
    Case 1
        dateSince = DateAdd("d", -7, Now())
    Case 2
        dateSince = DateAdd("d", -30, Now())
    Case 3
        dateSince = DateAdd("d", -60, Now())
    Case Else
        dateSince = DateAdd("d", -90, Now())
    End Select
    
    oClient.GetMailInfosParam.DateRangeSINCE = dateSince
    oClient.GetMailInfosParam.DateRangeBEFORE = DateAdd("d", 1, Now())

End Sub

Private Sub EnableSettingControls(ByVal isEnabled As Boolean, ByVal isCancelEnabled As Boolean)
    
    btnStart.Enabled = isEnabled
    btnCancel.Enabled = isCancelEnabled

    textServer.Enabled = isEnabled
    chkSSL.Enabled = isEnabled
    chkLeaveCopy.Enabled = isEnabled

    lstAuthType.Enabled = isEnabled
    lstProtocol.Enabled = isEnabled

    If lstAuthType.ListIndex <> MailServerAuthXOAUTH2 Then
        textUser.Enabled = isEnabled
        textPassword.Enabled = isEnabled
    End If

    If lstProtocol.ListIndex <> MailServerPop3 Then
        chkNewOnly.Enabled = isEnabled
        lstDateRange.Enabled = isEnabled
    End If

End Sub

Private Function CreateLocalInbox()
    Dim mailFolder As String
    mailFolder = m_currentPath & "\inbox"
    oTools.CreateFolder mailFolder

    CreateLocalInbox = mailFolder
End Function

Private Function GenerateFileName(ByVal index As Long)
    ' Generate a random file name by current local datetime,
    ' You can use your method to generate the filename if you do not like it
    Dim fileName As String
    fileName = oTools.GenFileName(index) & ".eml"
    GenerateFileName = fileName
End Function

Private Function AddNewMailToListMail(ByRef oMail As EAGetMailObjLib.Mail, ByVal filePath As String)

    Dim oItem As ListItem
    Set oItem = lstMail.ListItems.Add()

    oItem.Bold = True
    
    If oMail.From.Name <> "" Then
        oItem.Text = oMail.From.Name & " <" & oMail.From.Address & ">"
    Else
        oItem.Text = oMail.From.Address
    End If

    oItem.Tag = filePath
    oItem.ListSubItems.Add , , oMail.Subject
    oItem.ListSubItems.Add , , oMail.ReceivedDate
    oItem.ListSubItems.Add , , CDbl(oMail.ReceivedDate) ' For sort

    Set AddNewMailToListMail = oItem
End Function

Private Sub btnStart_Click()
    
    EnableSettingControls False, False

    If Not TryOauth() Then
        ' textStatus.SimpleText = "Failed to request/refresh access token."
        EnableSettingControls True, False
        Exit Sub
    End If

    If lstAuthType.ListIndex = MailServerAuthXOAUTH2 Then
        ' Use Gmail Oauth, now put user email and access token to user and password.
        textUser.Text = Oauth.UserEmail
        textPassword.Text = Oauth.AccessToken
    End If

    If Not ValidateInput() Then
        EnableSettingControls True, False
        Exit Sub
    End If
            
    EnableSettingControls False, True

    Dim isUidlLoaded As Boolean
    isUidlLoaded = False

On Error GoTo ErrorHandle
    
    Set oClient = New EAGetMailObjLib.MailClient
    
    ' For evaluation usage, please use "TryIt" as the license code, otherwise the
    ' "Invalid license code" exception will be thrown. However, the object will expire in 1-2 months, then
    ' "Trial version expired" exception will be thrown.
    oClient.LicenseCode = "TryIt"
    
    textStatus.SimpleText = "Connecting server ..."
    
    Dim oServer As EAGetMailObjLib.MailServer
    Set oServer = BuildServer()

    'oClient.LogFileName = "d:\pop3.txt" 'generate a log file
    m_bCancel = False

    oClient.Connect oServer
    
    Dim localInbox As String
    localInbox = CreateLocalInbox()
    
    Dim uidlFile As String
    uidlFile = localInbox & "\uidl.txt"
    
    ' uidl is the identifier of every email on POP3/IMAP4 server, to avoid retrieve
    ' the same email from server more than once, we record the email uidl retrieved every time
    ' if you delete the email from server every time and not to leave a copy of email on
    ' the server, then please remove all the function about uidl.
    ' If you want to re-download all emails, please delete uidl.txt from local inbox.
    Dim oUIDLManager As New EAGetMailObjLib.UIDLManager
    oUIDLManager.Load uidlFile
    isUidlLoaded = True
    
    SetMailRange

    textStatus.SimpleText = "Retrieving mail list ..."
    Dim mailInfos As EAGetMailObjLib.MailInfoCollection
    Set mailInfos = oClient.GetMailInfoList()
    
    
    
    If lstDateRange.ListIndex = 0 Then
        ' Remove the local uidl that is not existed on the server,
        ' we only synchronize it with uidl of all emails in current mail folder
        oUIDLManager.SyncUIDLEX oServer, mailInfos
        ' Update result back to uidl file
        oUIDLManager.Update

    End If
    
    Dim i As Long
    For i = 0 To mailInfos.Count - 1

        Dim oInfo As EAGetMailObjLib.MailInfo
        Set oInfo = mailInfos.Item(i)

        textStatus.SimpleText = "Retrieving " & i + 1 & "/" & mailInfos.Count & "..."
        
        Dim oUIDLItem As UIDLItem
        Set oUIDLItem = oUIDLManager.FindUIDL(oServer, oInfo.UIDL)
        
        ' If this email has not been retrieved before, then get it
        If oUIDLItem Is Nothing Then

            Dim oMail As EAGetMailObjLib.Mail
            Set oMail = oClient.GetMail(oInfo)
            
            Dim fileName As String
            fileName = GenerateFileName(i)
            Dim fullFileName As String
            fullFileName = localInbox & "\" & fileName
            
            oMail.SaveAs fullFileName, True
            AddNewMailToListMail oMail, fullFileName

            lblTotal.Caption = "Total " & lstMail.ListItems.Count & " email(s)"

            ' If retrieve only new emails, after we retrieved it, mark it as read,
            ' With this feature, you don't have to UIDLManager to prevent duplicated emails.
            If chkNewOnly.value = Checked And lstProtocol.ListIndex <> MailServerPop3 Then
                oClient.MarkAsRead oInfo, True
            End If
            
            If chkLeaveCopy.value = Checked Then
                ' Add the email uidl to uidl file to avoid we retrieve it next time.
                oUIDLManager.AddUIDL oServer, oInfo.UIDL, fileName
            Else
                textStatus.SimpleText = "Deleting " & i + 1 & " ..."
                oClient.Delete oInfo

                ' Remove UIDL from local uidl file.
                oUIDLManager.RemoveUIDL oServer, oInfo.UIDL
            End If
        End If

    Next
    
    ' Delete method just mark the email as deleted,
    ' Quit method expunge the emails from server exactly.
    oClient.Quit
    Set oClient = Nothing
    
    textStatus.SimpleText = "Completed"

    GoTo FinalHandle

ErrorHandle:
   
    MsgBox Err.Description
    textStatus.SimpleText = Err.Description
 
FinalHandle:
    
    Set oClient = Nothing
    If isUidlLoaded Then
        ' Update the uidl list to a text file and then we can load it next time.
        oUIDLManager.Update
    End If

    EnableSettingControls True, False

End Sub

' Cancel email retrieving
Private Sub btnCancel_Click()
    m_bCancel = True
    btnCancel.Enabled = False
End Sub

' -----------------------------------------------
' Delete selected email from local disk
' -----------------------------------------------
Private Sub btnDel_Click()
    Dim oItem As ListItem
    Set oItem = lstMail.SelectedItem
    If oItem Is Nothing Then
        Exit Sub
    End If
    
    If MsgBox("Are you sure to delete selected emails?", vbYesNo, "Delete Email") <> vbYes Then
        Exit Sub
    End If
    
    Dim fileName As String
    fileName = oItem.Tag
   
    Dim htmlFile As String
    htmlFile = EmlFileToHtmlRenderPath(fileName)
    
    Dim tempFolder As String
    tempFolder = GetAttachmentTempFolder(fileName)

    Dim nIndex
    nIndex = oItem.index
    
    lstMail.ListItems.Remove (oItem.index)
    
    On Error GoTo ErrorDel
    
    oTools.RemoveFile fileName
    oTools.RemoveFile htmlFile
    oTools.RemoveFolder tempFolder, True
 
    lblTotal.Caption = "Total " & lstMail.ListItems.Count & " email(s)"
    
    If lstMail.ListItems.Count > 0 Then
        If nIndex > lstMail.ListItems.Count Then
            nIndex = lstMail.ListItems.Count
        End If
        
        lstMail.ListItems.Item(nIndex).Selected = True
        ShowMail lstMail.ListItems.Item(nIndex).Tag
    Else
        webMail.Navigate "about:blank"
    End If

    Exit Sub

ErrorDel:
    MsgBox Err.Description
    
End Sub

Private Sub Form_QueryUnload(Cancel As Integer, UnloadMode As Integer)
    m_bCancel = True
    End
End Sub

'=========================================================================================================
'Region "Parse and Display Mails"
'=========================================================================================================

Private Sub lstMail_ItemClick(ByVal Item As MSComctlLib.ListItem)
    ShowMail Item.Tag
    Item.Bold = False
End Sub


Private Function EmlFileToHtmlRenderPath(ByVal filePath)

    Dim pos As Integer
    pos = InStrRev(filePath, ".")

    Dim htmlFile As String
    htmlFile = Mid(filePath, 1, pos - 1) & ".html"

    EmlFileToHtmlRenderPath = htmlFile

End Function

Private Function GetAttachmentTempFolder(ByVal filePath)

    Dim pos As Integer
    pos = InStrRev(filePath, ".")

    Dim tempFolder As String
    tempFolder = Mid(filePath, 1, pos - 1)

    GetAttachmentTempFolder = tempFolder

End Function

Private Sub LoadLocalMails()
        
    lstMail.ListItems.Clear

    Dim localInbox As String
    localInbox = CreateLocalInbox()
    
    Dim files
    files = oTools.GetFiles(localInbox & "\*.eml")
    
    Dim i As Long
    For i = LBound(files) To UBound(files)
        Dim fullFileName As String
        fullFileName = files(i)
        
        Dim oMail As New EAGetMailObjLib.Mail
        
        ' For evaluation usage, please use "TryIt" as the license code, otherwise the
        ' "Invalid license code" exception will be thrown. However, the object will expire in 1-2 months, then
        ' "Trial version expired" exception will be thrown.
        oMail.LicenseCode = "TryIt"
        oMail.LoadFile fullFileName, True
        
        Dim oItem As ListItem
        Set oItem = AddNewMailToListMail(oMail, fullFileName)
    
        Dim htmlFile As String
        htmlFile = EmlFileToHtmlRenderPath(fullFileName)
        
        If Not oTools.ExistFile(htmlFile) Then
            ' This email is unread, we set the font style to bold.
            oItem.Bold = True
        Else
            oItem.Bold = False
        End If

        oMail.Clear
    Next
    
    lblTotal.Caption = "Total " & UBound(files) - LBound(files) & " email(s)"
End Sub

Private Sub ShowMail(ByVal fileName As String)

    Dim htmlFile As String
    htmlFile = EmlFileToHtmlRenderPath(fileName)
    
    If Not (oTools.ExistFile(htmlFile)) Then
        'we haven't generate the html for this email, generate it now.
        GenerateHtmlForEmail htmlFile, fileName
    End If
    
    webMail.Navigate htmlFile

End Sub

' Generate a html + temporal attachment folder for every email, once the html is created,
' next time we don't need to parse the email again.
Private Sub GenerateHtmlForEmail(ByVal htmlFile As String, ByVal emlFile As String)
    
On Error GoTo ErrorGenHtml

    Dim tempFolder As String
    tempFolder = GetAttachmentTempFolder(emlFile)

    Dim oMail As New EAGetMailObjLib.Mail
    ' For evaluation usage, please use "TryIt" as the license code, otherwise the
    ' "Invalid license code" exception will be thrown. However, the object will expire in 1-2 months, then
    ' "Trial version expired" exception will be thrown.
    oMail.LicenseCode = "TryIt"
        
    oMail.LoadFile emlFile, False
    If Err.Number <> 0 Then
        MsgBox Err.Description
        Exit Sub
    End If
    
On Error GoTo ErrorDecryptionOrVerification
    If oMail.IsEncrypted Then
        Set oMail = oMail.Decrypt(Nothing)
    End If
    
    If oMail.IsSigned Then
        oMail.VerifySignature
    End If

ErrorDecryptionOrVerification:
    If Err.Number <> 0 Then
        MsgBox Err.Description
        Err.Clear
    End If
    
On Error GoTo ErrorGenHtml
    
    ' Decode winmail.dat (Outlook TNEF Stream) automatically.
    ' also convert RTF body to HTML body automatically.
    oMail.DecodeTNEF

    Dim html As String
    html = oMail.HtmlBody

    Dim header As String
    header = header & "<div style=""font-family: consolas, 'Courier New', Arial; font-size: 14px; background-color: #fff;"">"
    header = header & "<b>From:</b> " + FormatHtmlTag(oMail.From.Name & "<" & oMail.From.Address & ">") + "<br>"
    
    Dim addresses As EAGetMailObjLib.AddressCollection
    Set addresses = oMail.ToList
    header = header & FormatAddresses(addresses, "To")
    
    Set addresses = oMail.CcList
    header = header & FormatAddresses(addresses, "Cc")
    
    header = header & "<b>Subject:</b>" & FormatHtmlTag(oMail.Subject) & "<br>" & vbCrLf
    
    Dim attachments As AttachmentCollection
    Set attachments = oMail.AttachmentList
    

    If attachments.Count > 0 Then
        ' Create temporal folder for attachment
        If Not oTools.ExistFile(tempFolder) Then
            oTools.CreateFolder (tempFolder)
        End If
        
        header = header & "<b>Attachments:</b>"

        Dim i As Long
        For i = 0 To attachments.Count - 1
            Dim oAttachment As EAGetMailObjLib.Attachment
            Set oAttachment = attachments.Item(i)

            Dim attachmentName As String
            attachmentName = tempFolder & "\" & oAttachment.Name
            oAttachment.SaveAs attachmentName, True

            header = header & "<a href=""" & attachmentName & """ target=""_blank"">" & oAttachment.Name & "</a> "
            If Len(oAttachment.ContentID) > 0 And InStr(html, oAttachment.ContentID) > 0 Then
                ' Show embedded image, replace <img src="cid:cid-value"> to <img src="attachment-full-path">
                html = Replace(html, "cid:" + oAttachment.ContentID, attachmentName)
            End If

        Next
    End If
    
    header = header & "</div>"
    
    Dim reg
    Set reg = CreateObject("VBScript.RegExp")
    
    reg.Global = True
    reg.IgnoreCase = True
    reg.Pattern = "(<meta[^>]*charset[ \t]*=[ \t""]*)([^<> \r\n""]*)"
    html = reg.Replace(html, "$1utf-8")
    
    header = "<meta HTTP-EQUIV=""Content-Type"" Content=""text/html; charset=utf-8"">" & header
    html = header & "<hr>" & html

    oTools.WriteTextFile htmlFile, html, 65001
    oMail.Clear

    Exit Sub
    
ErrorGenHtml:
    MsgBox "Failed to generate html file for the email; " & Err.Description
    
End Sub

Private Function FormatAddresses(ByRef addresses As EAGetMailObjLib.AddressCollection, ByVal prefix As String) As String

    If addresses.Count = 0 Then
        FormatAddresses = ""
        Exit Function
    End If

    Dim value As String
    value = "<b>" & prefix & ":</b> " ' To or Cc
    
    Dim i As Long
    For i = 0 To addresses.Count - 1
        value = value & FormatHtmlTag(addresses.Item(i).Name & " <" & addresses.Item(i).Address & ">")
        If (i < addresses.Count - 1) Then
            value = value & "; "
        End If
    Next
    
    FormatAddresses = value & "<br>"
End Function

Private Function FormatHtmlTag(ByVal src As String) As String

    src = Replace(src, ">", "&gt;")
    src = Replace(src, "<", "&lt;")

    FormatHtmlTag = src

End Function
'=============================================================================================
' End of Parse and Display Mails
'=============================================================================================


'================================================================================================
'"EAGetMail Event Handler"
' you don't have to use EAGetMail Event, but using Event make your application more user friendly
'================================================================================================
Private Sub oClient_OnAuthorized(ByVal oSender As Object, Cancel As Boolean)
        textStatus.SimpleText = "Authorized"
        Cancel = m_bCancel
End Sub

Private Sub oClient_OnConnected(ByVal oSender As Object, Cancel As Boolean)
        textStatus.SimpleText = "Connected"
        Cancel = m_bCancel
End Sub

Private Sub oClient_OnIdle(ByVal oSender As Object, Cancel As Boolean)
        DoEvents
        Cancel = m_bCancel
End Sub

Private Sub oClient_OnQuit(ByVal oSender As Object, Cancel As Boolean)
        textStatus.SimpleText = "Quiting ... "
End Sub

Private Sub oClient_OnReceivingDataStream(ByVal oSender As Object, _
ByVal oInfo As Object, ByVal Received As Long, ByVal Total As Long, Cancel As Boolean)
        pgBar.Min = 0
        pgBar.Max = 100
        pgBar.value = (Received / Total) * 100
        
        DoEvents
        Cancel = m_bCancel
End Sub

Private Sub oClient_OnSecuring(ByVal oSender As Object, Cancel As Boolean)
        textStatus.SimpleText = "Securing ..."
End Sub
'================================================================================================
'"EAGetMail Event Handler" end
'================================================================================================






