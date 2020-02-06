VERSION 5.00
Object = "{EAB22AC0-30C1-11CF-A7EB-0000C05BAE0B}#1.1#0"; "shdocvw.dll"
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   7980
   ClientLeft      =   165
   ClientTop       =   450
   ClientWidth     =   13560
   LinkTopic       =   "Form1"
   ScaleHeight     =   7980
   ScaleWidth      =   13560
   StartUpPosition =   3  'Windows Default
   Begin MSComDlg.CommonDialog FileDlg 
      Left            =   2400
      Top             =   6480
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
      DefaultExt      =   "*.eml"
      Filter          =   "Email file (*.EML)|*.EML"
   End
   Begin VB.CommandButton btnUpload 
      Caption         =   "Upload"
      Height          =   375
      Left            =   12480
      TabIndex        =   24
      Top             =   3000
      Width           =   975
   End
   Begin VB.CommandButton btnMove 
      Caption         =   "Move"
      Height          =   375
      Left            =   10440
      TabIndex        =   22
      Top             =   3000
      Width           =   975
   End
   Begin VB.CommandButton btnCopy 
      Caption         =   "Copy"
      Height          =   375
      Left            =   9360
      TabIndex        =   21
      Top             =   3000
      Width           =   975
   End
   Begin VB.Frame Frame1 
      Caption         =   "Account Information"
      Height          =   6255
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   3375
      Begin VB.ComboBox lstDateRange 
         Height          =   315
         Left            =   120
         Style           =   2  'Dropdown List
         TabIndex        =   12
         Top             =   3600
         Width           =   3135
      End
      Begin VB.CommandButton btnQuit 
         Caption         =   "Quit"
         Enabled         =   0   'False
         Height          =   495
         Left            =   120
         TabIndex        =   14
         Top             =   4800
         Width           =   3135
      End
      Begin VB.TextBox textServer 
         Height          =   285
         Left            =   1080
         TabIndex        =   2
         Top             =   315
         Width           =   2175
      End
      Begin VB.TextBox textUser 
         Height          =   285
         Left            =   1080
         TabIndex        =   4
         Top             =   795
         Width           =   2175
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
      Begin VB.CheckBox chkSSL 
         Caption         =   "SSL Connection"
         Height          =   375
         Left            =   120
         TabIndex        =   7
         Top             =   1800
         Value           =   1  'Checked
         Width           =   2895
      End
      Begin VB.ComboBox lstAuthType 
         Height          =   315
         Left            =   1080
         Style           =   2  'Dropdown List
         TabIndex        =   9
         Top             =   2460
         Width           =   2175
      End
      Begin VB.ComboBox lstProtocol 
         Height          =   315
         Left            =   1080
         Style           =   2  'Dropdown List
         TabIndex        =   11
         Top             =   3060
         Width           =   2175
      End
      Begin VB.CommandButton btnStart 
         Caption         =   "Start"
         Height          =   495
         Left            =   120
         TabIndex        =   13
         Top             =   4080
         Width           =   3135
      End
      Begin VB.CommandButton btnCancel 
         Caption         =   "Cancel"
         Enabled         =   0   'False
         Height          =   495
         Left            =   120
         TabIndex        =   15
         Top             =   5520
         Width           =   3135
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
      Begin VB.Label Label2 
         AutoSize        =   -1  'True
         Caption         =   "User"
         Height          =   195
         Left            =   120
         TabIndex        =   3
         Top             =   840
         Width           =   330
      End
      Begin VB.Label Label3 
         AutoSize        =   -1  'True
         Caption         =   "Password"
         Height          =   195
         Left            =   120
         TabIndex        =   5
         Top             =   1320
         Width           =   690
      End
      Begin VB.Label Label4 
         AutoSize        =   -1  'True
         Caption         =   "Auth Type"
         Height          =   195
         Left            =   120
         TabIndex        =   8
         Top             =   2520
         Width           =   735
      End
      Begin VB.Label Label5 
         AutoSize        =   -1  'True
         Caption         =   "Protocol"
         Height          =   195
         Left            =   120
         TabIndex        =   10
         Top             =   3120
         Width           =   585
      End
   End
   Begin MSComctlLib.ProgressBar pgBar 
      Height          =   255
      Left            =   6240
      TabIndex        =   26
      Top             =   7200
      Width           =   7215
      _ExtentX        =   12726
      _ExtentY        =   450
      _Version        =   393216
      Appearance      =   1
   End
   Begin VB.CommandButton btnExpunge 
      Caption         =   "Expunge"
      Enabled         =   0   'False
      Height          =   375
      Left            =   11520
      TabIndex        =   23
      Top             =   3000
      Width           =   855
   End
   Begin VB.CommandButton btnUnread 
      Caption         =   "Unread"
      Enabled         =   0   'False
      Height          =   375
      Left            =   8400
      TabIndex        =   20
      Top             =   3000
      Width           =   855
   End
   Begin VB.CommandButton btnUndelete 
      Caption         =   "Undelete"
      Enabled         =   0   'False
      Height          =   375
      Left            =   7320
      TabIndex        =   19
      Top             =   3000
      Width           =   975
   End
   Begin VB.CommandButton btnDelete 
      Caption         =   "Delete"
      Enabled         =   0   'False
      Height          =   375
      Left            =   6240
      TabIndex        =   18
      Top             =   3000
      Width           =   975
   End
   Begin MSComctlLib.StatusBar textStatus 
      Align           =   2  'Align Bottom
      Height          =   375
      Left            =   0
      TabIndex        =   27
      Top             =   7605
      Width           =   13560
      _ExtentX        =   23918
      _ExtentY        =   661
      Style           =   1
      _Version        =   393216
      BeginProperty Panels {8E3867A5-8586-11D1-B16A-00C0F0283628} 
         NumPanels       =   1
         BeginProperty Panel1 {8E3867AB-8586-11D1-B16A-00C0F0283628} 
         EndProperty
      EndProperty
   End
   Begin SHDocVwCtl.WebBrowser webMail 
      Height          =   3495
      Left            =   6240
      TabIndex        =   25
      Top             =   3600
      Width           =   7215
      ExtentX         =   12726
      ExtentY         =   6165
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
      Location        =   "http:///"
   End
   Begin MSComctlLib.ListView lstMail 
      Height          =   2655
      Left            =   6240
      TabIndex        =   17
      Top             =   120
      Width           =   7215
      _ExtentX        =   12726
      _ExtentY        =   4683
      SortKey         =   3
      View            =   3
      LabelEdit       =   1
      SortOrder       =   -1  'True
      Sorted          =   -1  'True
      MultiSelect     =   -1  'True
      LabelWrap       =   -1  'True
      HideSelection   =   0   'False
      FullRowSelect   =   -1  'True
      GridLines       =   -1  'True
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
   Begin MSComctlLib.TreeView lstFolder 
      Height          =   7335
      Left            =   3600
      TabIndex        =   16
      Top             =   120
      Width           =   2535
      _ExtentX        =   4471
      _ExtentY        =   12938
      _Version        =   393217
      HideSelection   =   0   'False
      LabelEdit       =   1
      Style           =   7
      Appearance      =   1
   End
   Begin VB.Menu mnuFolders 
      Caption         =   "Folders"
      Visible         =   0   'False
      Begin VB.Menu mnuRefreshFolder 
         Caption         =   "Refresh Folder"
      End
      Begin VB.Menu menuRefreshMails 
         Caption         =   "Refresh Mails"
      End
      Begin VB.Menu mnuAddFolder 
         Caption         =   "AddFolder"
      End
      Begin VB.Menu mnuDeleteFolder 
         Caption         =   "Delete Folder"
      End
      Begin VB.Menu mnuRenameFolder 
         Caption         =   "Rename Folder"
      End
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
' |    Copyright (c)2010-2019  ADMINSYSTEM SOFTWARE LIMITED                         |
' |
' |    Project: It demonstrates how to use EAGetMailObj to  access IMAP4/Exchange Server folders/emails.
' |
' |
' |    File: Form1 : implementation file
' |
' |    Author: Ivan Lui ( ivan@emailarchitect.net )
'  ==============================================================================='

Option Explicit

Const MailServerConnectType_ConnectSSLAuto = 0
Const MailServerConnectType_ConnectSSL = 1
Const MailServerConnectType_ConnectTLS = 2

Const ProxyType_Socks4 = 0
Const ProxyType_Socks5 = 1
Const ProxyType_Http = 2

Const MailServerAuthLogin = 0
Const MailServerAuthCRAM5 = 1
Const MailServerAuthNTLM = 2
Const MailServerAuthXOAUTH2 = 3

' Oauth wrapper for Gmail XOAUTH2
Public Oauth As New OauthWrapper

Const ProtocolOffset = 1
Const MailServerPop3 = 0
Const MailServerImap4 = 1
Const MailServerEWS = 2 'Exchange Web Service - Exchange 2007/2010
Const MailServerDAV = 3 'Exchange WebDAV - Exchange 2000/2003

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

' Current server and uidl manager instance
Private oCurServer As EAGetMailObjLib.MailServer
Private oUIDLManager As EAGetMailObjLib.UIDLManager

' Cancel current operation flag
Private m_bCancel As Boolean
Private m_currentPath As String

Private m_isWorking As Boolean
Private m_isSelectedFolderChanged As Boolean
Private m_selectedFolderPath As String

'=========================================================
' Begin AutoResizeControl
'=========================================================
Private formWidth As Long
Private formHeight  As Long
Private lstMailWidthOffset As Long
Private webMailHeightOffset As Long
Private lstFolderHeightOffset As Long
Private pgBarTopOffset As Long

Private Sub InitResize()

    formWidth = Form1.Width
    formHeight = Form1.Height
    
    lstMailWidthOffset = Form1.Width - lstMail.Width
    webMailHeightOffset = Form1.Height - webMail.Height
    lstFolderHeightOffset = Form1.Height - lstFolder.Height
    pgBarTopOffset = Form1.Height - pgBar.Top

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
    
    webMail.Width = lstMail.Width
    webMail.Height = Form1.Height - webMailHeightOffset
    
    pgBar.Width = lstMail.Width
    pgBar.Top = Form1.Height - pgBarTopOffset
    lstFolder.Height = Form1.Height - lstFolderHeightOffset

End Sub

Private Sub Form_Resize()
   AutoResizeControl
End Sub
'=========================================================
' End AutoResizeControl
'=========================================================

Private Sub Form_Load()

    InitResize
    EnableControlDynamic

    webMail.Navigate "about:blank"

    Set oUIDLManager = New UIDLManager
    m_currentPath = App.Path

    lstAuthType.AddItem "USER/LOGIN"
    lstAuthType.AddItem "APOP(CRAM-MD5)"
    lstAuthType.AddItem "NTLM"
    lstAuthType.AddItem "Gmail XOAUTH2"
    lstAuthType.ListIndex = 0
    
    lstDateRange.AddItem "Sync last 7 days emails"
    lstDateRange.AddItem "Sync last 30 days emails"
    lstDateRange.AddItem "Sync last 60 days emails"
    lstDateRange.AddItem "Sync last 90 days emails"
    lstDateRange.AddItem "Sync all emails (slow)"
    
    lstDateRange.ListIndex = 0
    
    lstProtocol.AddItem "IMAP4"
    lstProtocol.AddItem "EWS - Exchange 2007-2019/Office365"
    lstProtocol.AddItem "Exchange WebDAV - 2000/2003"
    lstProtocol.ListIndex = 0
    
    m_bCancel = False

    textStatus.SimpleText = ""
    lstFolder.Nodes.Clear

    m_isWorking = False
    
End Sub

Private Sub Form_QueryUnload(Cancel As Integer, UnloadMode As Integer)
    'm_bCancel = True
    End
End Sub

Private Sub lstAuthType_Click()

    If lstAuthType.ListIndex = MailServerAuthXOAUTH2 Then
        lstProtocol.ListIndex = MailServerImap4 - ProtocolOffset
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

Private Sub SetMailRange()
    
    oClient.GetMailInfosParam.Reset

    If lstDateRange.ListIndex = 4 Then
        ' Retrieve all emails.
        Exit Sub
    End If

    oClient.GetMailInfosParam.GetMailInfosOptions = (oClient.GetMailInfosParam.GetMailInfosOptions Or GetMailInfos_DateRange)

    Dim dateSince As Date

    Select Case lstDateRange.ListIndex
    Case 0
        dateSince = DateAdd("d", -7, Now())
    Case 1
        dateSince = DateAdd("d", -30, Now())
    Case 2
        dateSince = DateAdd("d", -60, Now())
    Case Else
        dateSince = DateAdd("d", -90, Now())
    End Select
    
    oClient.GetMailInfosParam.DateRangeSINCE = dateSince
    oClient.GetMailInfosParam.DateRangeBEFORE = DateAdd("d", 1, Now())

End Sub

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

Private Function BuildServer()

    Dim oServer As New EAGetMailObjLib.MailServer
    
    oServer.Server = Trim(textServer.Text)
    oServer.User = Trim(textUser.Text)
    oServer.Password = Trim(textPassword.Text)

    oServer.SSLConnection = chkSSL.value
    oServer.AuthType = lstAuthType.ListIndex
    oServer.Protocol = lstProtocol.ListIndex + 1
    
    ' For EWS/WebDAV, don't need to set port
    If oServer.SSLConnection Then
         oServer.Port = 993 'SSL IMAP4
    Else
         oServer.Port = 143 'IMAP4 normal
    End If
    
    Set BuildServer = oServer

End Function

Private Sub ConnectServerOnDemand()

    m_isSelectedFolderChanged = False

    If Not oClient.Connected Then
        textStatus.SimpleText = "Connecting server ..."
        m_bCancel = False

        oClient.Connect oCurServer
        textStatus.SimpleText = "Connected"
    End If

    Dim folderNode As Node
    Set folderNode = GetSelectedFolderNode(False)

    If folderNode Is Nothing Then
        Exit Sub
    End If

    Dim oFolder As EAGetMailObjLib.Imap4Folder
    Set oFolder = folderNode.Tag

    If m_selectedFolderPath = oFolder.ServerPath Then
        Exit Sub
    End If
    
    ' Clear current mail list, because the selected folder will be changed
    lstMail.ListItems.Clear
    
    m_selectedFolderPath = oFolder.ServerPath
    m_isSelectedFolderChanged = True

    If oFolder.NoSelect Then
        Exit Sub
    End If

    oClient.SelectFolder oFolder
End Sub

'--------------------------------------------------
' Region: Login, Quit and Cancel
'--------------------------------------------------
Private Sub btnStart_Click()

    PrepareLogin

    If Not TryOauth() Then
        textStatus.SimpleText = "Failed to request/refresh access token."
        AfterLoginError
        Exit Sub
    End If

    If lstAuthType.ListIndex = MailServerAuthXOAUTH2 Then
        ' Use Gmail Oauth, now put user email and access token to user and password.
        textUser.Text = Oauth.UserEmail
        textPassword.Text = Oauth.AccessToken
    End If

    If Not ValidateInput() Then
        AfterLoginError
        Exit Sub
    End If
    
    btnStart.Enabled = False
    
On Error GoTo ErrorHandle:

    Set oClient = New EAGetMailObjLib.MailClient
    oClient.LicenseCode = "TryIt"

    Set oCurServer = BuildServer()

    PrepareWork

    textStatus.SimpleText = "Connecting ..."
    oClient.Connect oCurServer
    textStatus.SimpleText = "Connected"
    
    ShowAllFolders

    EndWork
    AfterLoginSucceeded
    Exit Sub

ErrorHandle:

    AfterError
    AfterLoginError

End Sub

Private Sub btnQuit_Click()

On Error Resume Next
    oClient.Logout
    oClient.Close

    AfterQuit
End Sub

Private Sub btnCancel_Click()
    m_bCancel = True
    btnCancel.Enabled = False
End Sub

Private Sub PrepareLogin()
    textServer.Enabled = False
    
    textUser.Enabled = False
    textPassword.Enabled = False
   
    lstAuthType.Enabled = False
    lstProtocol.Enabled = False
    lstDateRange.Enabled = False
    
    chkSSL.Enabled = False
    btnStart.Enabled = False

    m_selectedFolderPath = ""
    
End Sub

Private Sub AfterLoginSucceeded()
    textServer.Enabled = False
    
    textUser.Enabled = False
    textPassword.Enabled = False
   
    chkSSL.Enabled = False
    btnStart.Enabled = False
    btnQuit.Enabled = True

    m_selectedFolderPath = ""
End Sub

Private Sub AfterLoginError()

    textServer.Enabled = True
    
    If lstAuthType.ListIndex <> MailServerAuthXOAUTH2 Then
        textUser.Enabled = True
        textPassword.Enabled = True
    Else
        textUser.Enabled = False
        textPassword.Enabled = False
    End If
   
    lstAuthType.Enabled = True
    lstProtocol.Enabled = True
    lstDateRange.Enabled = True
    
    chkSSL.Enabled = True
    btnStart.Enabled = True
    btnQuit.Enabled = False
    
    webMail.Navigate ("about:blank")
    lstMail.ListItems.Clear
    lstFolder.Nodes.Clear

    m_selectedFolderPath = ""
End Sub

Private Sub AfterQuit()
    
    EndWork

    webMail.Navigate ("about:blank")
    lstMail.ListItems.Clear
    lstFolder.Nodes.Clear

    textServer.Enabled = True
    
    If lstAuthType.ListIndex <> MailServerAuthXOAUTH2 Then
        textUser.Enabled = True
        textPassword.Enabled = True
    End If
   
    lstAuthType.Enabled = True
    lstProtocol.Enabled = True
    lstDateRange.Enabled = True
    
    chkSSL.Enabled = True
    btnStart.Enabled = True

    btnQuit.Enabled = False
    
    m_selectedFolderPath = ""

    textStatus.SimpleText = "Disconnected"
End Sub

Private Sub AfterError()
    
    EndWork

    oClient.Close
    MsgBox Err.Description

    m_selectedFolderPath = ""

    textStatus.SimpleText = Err.Description
End Sub

Private Sub PrepareWork()
    m_isWorking = True
    
    btnCancel.Enabled = True
    m_bCancel = False
    
    btnQuit.Enabled = False

    EnableControlDynamic
End Sub

Private Sub EndWork()
    
    m_isWorking = False
    btnCancel.Enabled = False
    
    btnQuit.Enabled = True

    EnableControlDynamic
End Sub

'--------------------------------------------------
' End Login, Quit and Cancel
'--------------------------------------------------

'----------------------------------------------------------------------
' Region: Show server folders and expand folders.
'----------------------------------------------------------------------
Private Sub ShowAllFolders()
    lstFolder.Nodes.Clear
    
    Dim rootNode As Node
    Set rootNode = lstFolder.Nodes.Add(, , "Root", "Root")
    rootNode.Text = oCurServer.Server & "\" & oCurServer.User
    
    lstFolder.SelectedItem = rootNode
     
    Dim folders As EAGetMailObjLib.FolderCollection
    Set folders = oClient.GetFolderList()
    
    ExpandFolders folders, rootNode.Key
    rootNode.Expanded = True
End Sub

Private Sub ExpandFolders(ByRef folders As EAGetMailObjLib.FolderCollection, ByVal ParentNodeKey As String)
    
    Dim i As Long
    For i = 0 To folders.Count - 1
        Dim oFolder As EAGetMailObjLib.Imap4Folder
        Set oFolder = folders.Item(i)

        Dim currentNode As Node
        Set currentNode = lstFolder.Nodes.Add(ParentNodeKey, tvwChild, ParentNodeKey & "_" & i, oFolder.ServerPath)

        currentNode.Text = oFolder.Name
        Set currentNode.Tag = oFolder
        
        Dim subFolders  As EAGetMailObjLib.FolderCollection
        Set subFolders = oFolder.SubFolderList

        ExpandFolders subFolders, currentNode.Key
        currentNode.Expanded = True
    Next

End Sub

'----------------------------------------------------------------------
' End: show server folders and expand folders.
'----------------------------------------------------------------------

'-------------------------------------------------------------------------------
' Region: Add, delete, rename folders
' ------------------------------------------------------------------------------
Private Function GetSelectedFolderNode(includeRoot As Boolean)

    Set GetSelectedFolderNode = Nothing

    Dim selectedNode As Node
    Set selectedNode = lstFolder.SelectedItem

    If selectedNode Is Nothing Then
        Exit Function
    End If

    If (Not includeRoot) And (selectedNode.Parent Is Nothing) Then
        Exit Function
    End If

    Set GetSelectedFolderNode = selectedNode
End Function

'-----------------------------------------------------------------------------------
' Show folder context menu
'-----------------------------------------------------------------------------------
Private Sub lstFolder_MouseDown(Button As Integer, Shift As Integer, x As Single, y As Single)
    If Button <> vbRightButton Then
        Exit Sub
    End If
    
    If GetSelectedFolderNode(True) Is Nothing Then
        Exit Sub
    End If
    
    mnuAddFolder.Enabled = (Not m_isWorking)
    mnuDeleteFolder.Enabled = (Not m_isWorking)
    mnuRefreshFolder.Enabled = (Not m_isWorking)
    mnuRenameFolder.Enabled = (Not m_isWorking)
    menuRefreshMails.Enabled = (Not m_isWorking)
    
    PopupMenu mnuFolders
End Sub

'----------------------------------------------------------------
' Add folder
'-----------------------------------------------------------------
Private Sub mnuAddFolder_Click()

    FormFolder.textFolder.Text = ""
    FormFolder.Show 1, Me

    Dim folderName As String
    folderName = FormFolder.textFolder

    If folderName = "" Then
        Exit Sub
    End If

    Dim folderNode As Node
    Set folderNode = lstFolder.SelectedItem

    If folderNode Is Nothing Then
        Set folderNode = lstFolder.Nodes.Item(1)
    End If
    
On Error GoTo ErrorHandle
    PrepareWork
    ConnectServerOnDemand

    Dim oFolder As EAGetMailObjLib.Imap4Folder
    
    If folderNode.Parent Is Nothing Then
        Set oFolder = oClient.CreateFolder(Nothing, folderName)
    Else
        Set oFolder = oClient.CreateFolder(folderNode.Tag, folderName)
    End If
    
    Dim oNewNode As Node
    Set oNewNode = lstFolder.Nodes.Add(folderNode.Key, tvwChild, oFolder.ServerPath, oFolder.Name)
    Set oNewNode.Tag = oFolder
    
    EndWork
    Exit Sub

ErrorHandle:
    AfterError
    
End Sub

'------------------------------------------------------------------------
' Rename folder
'-------------------------------------------------------------------------
Private Sub mnuRenameFolder_Click()

    If GetSelectedFolderNode(False) Is Nothing Then
        Exit Sub
    End If
    
    m_isWorking = True
    lstFolder.StartLabelEdit
End Sub

Private Sub lstFolder_AfterLabelEdit(Cancel As Integer, NewFolderName As String)
    Dim folderNode As Node
    Set folderNode = lstFolder.SelectedItem

    If folderNode.Text = NewFolderName Then
        Cancel = 1
        m_isWorking = False
        Exit Sub
    End If

On Error GoTo ErrorHandle
    PrepareWork
    ConnectServerOnDemand
    
    Dim folder As String
    folder = GetLocalFolderPath(folderNode.Tag)
    
    oClient.RenameFolder folderNode.Tag, NewFolderName
    folderNode.Text = NewFolderName

    Dim newFolder As String
    newFolder = GetLocalFolderPath(folderNode.Tag)
    
    oTools.RenameFile folder, newFolder
    Cancel = 0
    
    EndWork
    Exit Sub
    
ErrorHandle:
    Cancel = 1
    AfterError

End Sub

'----------------------------------------------------
' Delete folder
'----------------------------------------------------
Private Sub mnuDeleteFolder_Click()

    Dim folderNode As Node
    Set folderNode = GetSelectedFolderNode(False)
    If folderNode Is Nothing Then
        Exit Sub
    End If
    
On Error GoTo ErrorHandle
    PrepareWork
    ConnectServerOnDemand
    
    Dim folder As String
    folder = GetLocalFolderPath(folderNode.Tag)
    
    oClient.DeleteFolder folderNode.Tag
    
    lstFolder.Nodes.Remove folderNode.Index
    oTools.RemoveFolder folder, True
    
    EndWork
    Exit Sub

ErrorHandle:
    AfterError

End Sub

'-------------------------------------
' Refresh folder
'--------------------------------------
Private Sub mnuRefreshFolder_Click()

    lstMail.ListItems.Clear

On Error GoTo ErrorHandle
    PrepareWork
    ConnectServerOnDemand

    oClient.RefreshFolders
    ShowAllFolders
    
    EndWork
    Exit Sub

ErrorHandle:
    AfterError

End Sub

'-------------------------------------------------------------------------------
' End Of Add, delete, rename folders
' ------------------------------------------------------------------------------

'---------------------------------------------
' List emails of selected folder
'----------------------------------------------
Private Sub lstFolder_NodeClick(ByVal folderNode As MSComctlLib.Node)
    If folderNode.Parent Is Nothing Then
        lstMail.ListItems.Clear
        textStatus.SimpleText = "Root"
        Exit Sub
    End If

 On Error GoTo ErrorHandle
    PrepareWork
    ConnectServerOnDemand

    If m_isSelectedFolderChanged Then
        LoadServerMails folderNode
    End If
    
    EndWork
    Exit Sub

ErrorHandle:
   AfterError

End Sub

'---------------------------------------------------------------------------
' Load emails on server
'---------------------------------------------------------------------------
Private Sub LoadServerMails(folderNode As MSComctlLib.Node)
    
    lstMail.ListItems.Clear
    
    Dim oFolder As EAGetMailObjLib.Imap4Folder
    Set oFolder = folderNode.Tag

    ' Current server folder is unselectable
    If oFolder.NoSelect Then
        folderNode.Expanded = True
        Exit Sub
    End If
    
    Dim isUidlLoaded As Boolean
    isUidlLoaded = False

On Error GoTo ErrorHandle
    
    Dim folder As String
    folder = GetLocalFolderPath(oFolder)
    
    ' Create a full local folder to store downloaded email/header
    CreateFullLocalFolder folder
    oUIDLManager.Load folder & "\uidl.txt"
    isUidlLoaded = True

    SetMailRange

    textStatus.SimpleText = "Refreshing email(s) ..."

    Dim mailInfos
    Set mailInfos = oClient.GetMailInfoList()
  
    If lstDateRange.ListIndex = 4 Then
        ' Remove the local uidl which is not existed on the server.
        ' we only synchronize it with uidl of all emails in current mail folder
        oUIDLManager.SyncUIDLEX oCurServer, mailInfos
        oUIDLManager.Update
    End If
    
    Dim i As Long
    For i = 0 To mailInfos.Count - 1

        Dim oInfo As EAGetMailObjLib.MailInfo
        Set oInfo = mailInfos.Item(i)
        
        Dim oUIDLItem As EAGetMailObjLib.UIDLItem
        Set oUIDLItem = oUIDLManager.FindUIDL(oCurServer, oInfo.UIDL)

        ' Retrieve email headers only to display the summary, if the email headers file is existed, load it directly.
        Dim emailHeaderFile As String
        Dim fullEmailHeaderFile As String

        If oUIDLItem Is Nothing Then
            ' Current email headers has not been downloaded, generate a new file to store email headers
            emailHeaderFile = oTools.GenFileName(i) & ".eml"
            fullEmailHeaderFile = folder & "\" & emailHeaderFile
        Else
            ' Get existed email headers file from existed email headers file.
            fullEmailHeaderFile = folder & "\" & oUIDLItem.fileName
        End If

        textStatus.SimpleText = "Retrieve summary " & (i + 1) & "/" & mailInfos.Count & "..."
           
        Dim oMail As New EAGetMailObjLib.Mail
        oMail.LicenseCode = "TryIt"
        
        If oTools.ExistFile(fullEmailHeaderFile) Then
            oMail.LoadFile fullEmailHeaderFile, True
        Else
            ' Download email headers and save it to local disk
            oMail.Load oClient.GetMailHeader(oInfo)
            oMail.SaveAs fullEmailHeaderFile, True
        End If
        
        pgBar.value = 100
        
        Dim oItem As ListItem
        Set oItem = AddNewMailToListMail(oMail, oInfo)
      
        If oInfo.Deleted Then
            oItem.ForeColor = &H80000010
        ElseIf Not oInfo.Read Then
            oItem.Bold = True
        End If
        
        If oUIDLItem Is Nothing Then
            ' Add UIDL to prevent to download it at next time again.
            oUIDLManager.AddUIDL oCurServer, oInfo.UIDL, emailHeaderFile
        End If
    Next
    
    ' Remove the mail on local disk which is not existed on server
    ClearLocalMails folder
    
    oUIDLManager.Update
    Unselectall
    textStatus.SimpleText = "Total " & lstMail.ListItems.Count & " email(s)"
    
    Exit Sub

ErrorHandle:
    Unselectall
    
    If isUidlLoaded Then
        oUIDLManager.Update
    End If

    textStatus.SimpleText = "Total " & lstMail.ListItems.Count & " email(s)"

    Err.Raise Err.Number, Err.Source, Err.Description
End Sub

Private Function AddNewMailToListMail(ByRef oMail As EAGetMailObjLib.Mail, ByRef oInfo As EAGetMailObjLib.MailInfo)

    Dim oItem As ListItem
    Set oItem = lstMail.ListItems.Add()

    oItem.Text = oMail.From.Name & " <" & oMail.From.Address & ">"
    Set oItem.Tag = oInfo
    oItem.ListSubItems.Add , , oMail.Subject
    oItem.ListSubItems.Add , , oMail.ReceivedDate
    oItem.ListSubItems.Add , , CDbl(oMail.ReceivedDate)

    Set AddNewMailToListMail = oItem
End Function

'---------------------------------------------
' Referesh emails
'----------------------------------------------
Private Sub menuRefreshMails_Click()
    Dim folderNode As Node
    Set folderNode = GetSelectedFolderNode(False)

    If folderNode Is Nothing Then
        Exit Sub
    End If
    
On Error GoTo ErrorHandle
    PrepareWork
    ConnectServerOnDemand

    oClient.RefreshMailInfos
    LoadServerMails folderNode
   
    EndWork
    Exit Sub

ErrorHandle:
    AfterError

End Sub

'----------------------------------------------------
' Copy email to another folder
'----------------------------------------------------
Private Function GetDestFolder()
    FormSelectFolder.lstFolder.Nodes.Clear
    FormSelectFolder.OriginalFolder = m_selectedFolderPath
    
    Dim destNode As Node
    Set destNode = FormSelectFolder.lstFolder.Nodes.Add(, , "Root")
    destNode.Text = "Root Folder"

    CopyNodes lstFolder.Nodes.Item(1), destNode
    destNode.Expanded = True
    FormSelectFolder.Show 1, Me

    Set GetDestFolder = FormSelectFolder.lstFolder.SelectedItem
End Function

Private Sub CopyNodes(sourceNode As Node, destNode As Node)
    If sourceNode Is Nothing Then
        Exit Sub
    End If
    
    Dim childNode As Node
    Set childNode = sourceNode.Child
    
    Do While Not (childNode Is Nothing)
        Dim newChildNode As Node
        Set newChildNode = FormSelectFolder.lstFolder.Nodes.Add(destNode.Key, tvwChild, childNode.Key, childNode.Text)
        Set newChildNode.Tag = childNode.Tag
        
        newChildNode.Expanded = True
        
        If Not (childNode.Child Is Nothing) Then
            CopyNodes childNode, newChildNode
        End If
        
        Set childNode = childNode.Next
    Loop
    
End Sub

'------------------------------------------
' Copy selected email to another folder
'------------------------------------------
Private Sub btnCopy_Click()

    Dim folderNode As Node
    Set folderNode = GetSelectedFolderNode(False)
    If folderNode Is Nothing Then
        Exit Sub
    End If

    If SelectedCounts() < 1 Then
        Exit Sub
    End If
    
    Dim oDest As Node
    Set oDest = GetDestFolder()
    If oDest Is Nothing Then
        Exit Sub
    End If

On Error GoTo ErrorHandle
    PrepareWork
    ConnectServerOnDemand

    Dim i As Integer
    i = 1
    Do While (i <= lstMail.ListItems.Count)
        Dim Item As ListItem
        Set Item = lstMail.ListItems(i)
        
        If Item.Selected Then
            Dim oInfo As EAGetMailObjLib.MailInfo
            Set oInfo = Item.Tag
            oClient.Copy oInfo, oDest.Tag
        End If
        i = i + 1
    Loop
        
    EndWork
    Exit Sub

ErrorHandle:
    AfterError

End Sub

'------------------------------------------
' Move selected email to another folder
'------------------------------------------
Private Sub btnMove_Click()

    If SelectedCounts() < 1 Then
        Exit Sub
    End If
    
    Dim oDest As Node
    Set oDest = GetDestFolder()
    If oDest Is Nothing Then
        Exit Sub
    End If

On Error GoTo ErrorHandle
    PrepareWork
    ConnectServerOnDemand
    
    Dim i As Integer
    i = 1
    Do While (i <= lstMail.ListItems.Count)
        Dim Item As ListItem
        Set Item = lstMail.ListItems(i)
        If Item.Selected Then
            
            Dim oInfo As EAGetMailObjLib.MailInfo
            Set oInfo = Item.Tag
            oClient.Move oInfo, oDest.Tag
            
            Item.Bold = False
            Item.ForeColor = &H80000010
            
            lstMail.ListItems.Remove i
        Else
            i = i + 1
        End If
    Loop

    If oCurServer.Protocol = MailServerImap4 Then
        oClient.Expunge
    End If

    EndWork
    Exit Sub

ErrorHandle:
    AfterError

End Sub

'--------------------------------------------------------------
' Expunge deleted emails from server, only IMAP4 support it.
'--------------------------------------------------------------
Private Sub btnExpunge_Click()
    Dim folderNode As Node
    Set folderNode = GetSelectedFolderNode(False)

    If folderNode Is Nothing Then
        Exit Sub
    End If
    
    If (oCurServer.Protocol = MailServerEWS) Or (oCurServer.Protocol = MailServerDAV) Then
        Exit Sub
    End If

On Error GoTo ErrorHandle
    PrepareWork
    ConnectServerOnDemand
    
    oClient.Expunge
    LoadServerMails folderNode

    EndWork
    Exit Sub

ErrorHandle:
    AfterError

End Sub

'----------------------------------------
' Mark email as unread
'-----------------------------------------
Private Sub btnUnread_Click()

    If SelectedCounts() < 1 Then
        Exit Sub
    End If
    
On Error GoTo ErrorHandle
    PrepareWork
    ConnectServerOnDemand
     
    Dim i As Integer
    i = 1
    Do While (i <= lstMail.ListItems.Count)
        Dim Item As ListItem
        Set Item = lstMail.ListItems(i)
        If Item.Selected Then

            Dim oInfo As EAGetMailObjLib.MailInfo
            Set oInfo = Item.Tag
        
            If oInfo.Read Then
                oClient.MarkAsRead Item.Tag, False
        
                Item.Bold = True
                Item.ForeColor = &H80000008
            End If
        End If
        i = i + 1
    Loop
        
    EndWork
    Exit Sub

ErrorHandle:
    AfterError

End Sub

'---------------------------------------------------------
' Mark deleted email as undeleted, only IMAP4 support this
'---------------------------------------------------------
Private Sub btnUndelete_Click()
    
    If SelectedCounts() < 1 Then
        Exit Sub
    End If
    
On Error GoTo ErrorHandle
    PrepareWork
    ConnectServerOnDemand
    
    Dim i As Integer
    i = 1
    Do While (i <= lstMail.ListItems.Count)
        Dim Item As ListItem
        Set Item = lstMail.ListItems(i)
        If Item.Selected Then
            
            Dim oInfo As EAGetMailObjLib.MailInfo
            Set oInfo = Item.Tag
            
            If oInfo.Deleted Then
                oClient.Undelete Item.Tag
                
                Item.Bold = False
                Item.ForeColor = &H80000008

                If Not oInfo.Read Then
                    Item.Bold = True
                End If
            End If

        End If
        i = i + 1
    Loop

    EndWork
    Exit Sub

ErrorHandle:
    AfterError

End Sub

'-----------------------------------------------------------------------------------------------
' Delete email, it only marks email as deleted in IMAP, use Expunge to expunge email from server
'------------------------------------------------------------------------------------------------
Private Sub btnDelete_Click()

    If SelectedCounts() < 1 Then
        Exit Sub
    End If
    
On Error GoTo ErrorHandle
    PrepareWork
    ConnectServerOnDemand
    
    Dim i As Integer
    i = 1
    Do While (i <= lstMail.ListItems.Count)
        Dim Item As ListItem
        Set Item = lstMail.ListItems(i)
        If Item.Selected Then

            oClient.Delete Item.Tag
            Item.Bold = False
            Item.ForeColor = &H80000010
        
            lstMail.ListItems.Remove i
        Else
             i = i + 1
        End If
    Loop

    If oCurServer.Protocol = MailServerImap4 Then
        oClient.Expunge
    End If

    EndWork
    Exit Sub

ErrorHandle:
    AfterError

End Sub

'-----------------------------------------------------------------------------------------------
' Upload email file to server
'------------------------------------------------------------------------------------------------
Private Sub btnUpload_Click()
    
    Dim folderNode As Node
    Set folderNode = GetSelectedFolderNode(False)
    If folderNode Is Nothing Then
        Exit Sub
    End If
    
    Dim oFolder As EAGetMailObjLib.Imap4Folder
    Set oFolder = folderNode.Tag

    FileDlg.ShowOpen
    If FileDlg.fileName = vbNullString Or FileDlg.fileName = "" Then
        Exit Sub
    End If
    
    Dim fileName As String
    fileName = FileDlg.fileName
    
On Error GoTo ErrorHandle
    PrepareWork
    ConnectServerOnDemand
    
    Dim oMail As New EAGetMailObjLib.Mail
    oMail.LicenseCode = "TryIt"
    oMail.LoadFile fileName, False

    oClient.Append oFolder, oMail.Content
    
    oClient.RefreshMailInfos
    LoadServerMails folderNode
    
    EndWork
    Exit Sub

ErrorHandle:
    AfterError

End Sub

'-----------------------------------------------------------------------------------------------
' Unselect seleted emails.
'------------------------------------------------------------------------------------------------
Private Sub Unselectall()
    Dim i As Integer
    For i = 1 To lstMail.ListItems.Count
        lstMail.ListItems(i).Selected = False
    Next
End Sub

'-----------------------------------------------------------------------------------------------
' Get count of selected emails
'------------------------------------------------------------------------------------------------
Private Function SelectedCounts()
    Dim i, nSelected As Integer
    
    nSelected = 0
    For i = 1 To lstMail.ListItems.Count
        If lstMail.ListItems(i).Selected = True Then
            nSelected = nSelected + 1
        End If
    Next
    
    SelectedCounts = nSelected
End Function

'-----------------------------------------------------------------------------------------------
' Remove local email file that is not existed on server.
'------------------------------------------------------------------------------------------------
Private Sub ClearLocalMails(folder As String)

    Dim files
    files = oTools.GetFiles(folder & "\*.eml")

    Dim i As Long
    For i = LBound(files) To UBound(files)
        Dim fileName
        fileName = files(i)

        Dim shortName
        shortName = fileName
        
        Dim pos
        pos = InStrRev(shortName, "\")
        If pos > 0 Then
            shortName = Mid(shortName, pos + 1)
        End If

        If oUIDLManager.FindLocalFile(shortName) Is Nothing Then
            ' This email has not existed on server, so delete the local file
            oTools.RemoveFile fileName

            Dim htmlFile As String
            Dim tempFolder As String

            htmlFile = EmlFileToHtmlRenderPath(fileName)
            tempFolder = GetAttachmentTempFolder(fileName)
            
            oTools.RemoveFile htmlFile
            oTools.RemoveFolder tempFolder, True

            DoEvents
        End If
    Next
End Sub

'-----------------------------------------------------------------------------------------------
' Create local folder recursively
'------------------------------------------------------------------------------------------------
Private Function GetLocalFolderPath(ByRef oFolder As EAGetMailObjLib.Imap4Folder) As String
    GetLocalFolderPath = m_currentPath & "\" & oCurServer.Server & "\" & oCurServer.User & "\" & oFolder.LocalPath
End Function

Private Sub CreateFullLocalFolder(folder As String)

    If oTools.ExistFile(folder) Then
        Exit Sub
    End If
    
    Dim pos As Integer
    pos = InStr(1, folder, App.Path, vbTextCompare)
    If pos > 0 Then
        pos = pos + Len(App.Path) + 1
    End If
            
    Dim s As String
    Do While True
        pos = InStr(pos, folder, "\")
        If pos > 0 Then
    
            s = Mid(folder, 1, pos - 1)
            If Not oTools.ExistFile(s) Then
                oTools.CreateFolder s
            End If
            
        ElseIf pos < 1 Then
            Exit Do
        End If
        pos = pos + 1
    Loop
    
    If Not oTools.ExistFile(folder) Then
        oTools.CreateFolder folder
    End If
End Sub

'-----------------------------------------------------------------
'  Region: Parse and display emails
'------------------------------------------------------------------
Private Sub lstMail_ItemClick(ByVal Item As MSComctlLib.ListItem)
    
    Dim folderNode As Node
    Set folderNode = GetSelectedFolderNode(False)
    If folderNode Is Nothing Then
        Exit Sub
    End If

    If SelectedCounts() <> 1 Or m_isWorking Then
        Exit Sub
    End If
    
    Dim OriginalStatus As String
    OriginalStatus = textStatus.SimpleText

On Error GoTo ErrorHandle
    PrepareWork
    ConnectServerOnDemand
    
    Dim oFolder As EAGetMailObjLib.Imap4Folder
    Set oFolder = folderNode.Tag
    
    Dim oInfo As EAGetMailObjLib.MailInfo
    Set oInfo = Item.Tag
          
    Dim folder As String
    folder = GetLocalFolderPath(oFolder)
    
    ' Find current email record in UIDL file.
    Dim oUIDLItem As UIDLItem
    Set oUIDLItem = oUIDLManager.FindUIDL(oCurServer, oInfo.UIDL)
    If (oUIDLItem Is Nothing) Then
        ' Should never happen except you delete the file from the folder manually.
        MsgBox ("No email file found!")
        EndWork
        Exit Sub
    End If

    Dim fileName As String
    ' Get the  local file name for this email UIDL
    fileName = folder & "\" & oUIDLItem.fileName
    
    Dim htmlFile As String
    htmlFile = EmlFileToHtmlRenderPath(fileName)
    
    Dim tempFolder As String
    tempFolder = GetAttachmentTempFolder(fileName)
    
    ' Only mail header is retrieved, now retrieve full content of mail.
    If Not oTools.ExistFile(htmlFile) Then
        Dim oMail As EAGetMailObjLib.Mail

        pgBar.Min = 0
        pgBar.Max = 100
        pgBar.value = 0
        textStatus.SimpleText = "Downloading Email " & oInfo.Index & "..."
        
        Set oMail = oClient.GetMail(oInfo)
        pgBar.value = 100
        oMail.SaveAs fileName, True
    End If
    
    If Not oInfo.Read Then
        oClient.MarkAsRead oInfo, True
        Item.Bold = False
    End If
        
    If oInfo.Deleted Then
        Item.ForeColor = &H80000010
    End If
    
    textStatus.SimpleText = OriginalStatus

    ShowMail fileName
    
    EndWork
    Exit Sub

ErrorHandle:
    AfterError

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

'----------------------------------------------------------------------------------------
' Generate a html + temporal attachment folder for every email, once the html is created,
' next time we don't need to parse the email again.
'----------------------------------------------------------------------------------------
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
        If addresses.Item(i).Name = "" Then
            value = value & FormatHtmlTag(addresses.Item(i).Address)
        Else
            value = value & FormatHtmlTag(addresses.Item(i).Name & " <" & addresses.Item(i).Address & ">")
        End If
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

'=============================================================================================
' End of Parse and display emails
'=============================================================================================

'-----------------------------------------------------------------------------------------------
' Enable button based on current status
'------------------------------------------------------------------------------------------------
Private Sub EnableControlDynamic()

    Dim selectMailCount As Long
    selectMailCount = SelectedCounts()
    
    Dim isFolderSelected As Boolean
    isFolderSelected = Not (GetSelectedFolderNode(False) Is Nothing)

    lstFolder.Enabled = (Not m_isWorking)
    lstMail.Enabled = (Not m_isWorking)
    btnDelete.Enabled = (Not m_isWorking) And isFolderSelected And selectMailCount > 0
    
    If lstProtocol.ListIndex + ProtocolOffset = MailServerImap4 Then
        btnUndelete.Enabled = (Not m_isWorking) And isFolderSelected And selectMailCount > 0
        btnExpunge.Enabled = (Not m_isWorking) And isFolderSelected
    Else
        btnUndelete.Enabled = False
        btnExpunge.Enabled = False
    End If

    btnUnread.Enabled = (Not m_isWorking) And isFolderSelected And selectMailCount > 0
    
    btnMove.Enabled = (Not m_isWorking) And isFolderSelected And selectMailCount > 0
    btnCopy.Enabled = (Not m_isWorking) And isFolderSelected And selectMailCount > 0

    btnUpload.Enabled = (Not m_isWorking) And isFolderSelected
    

End Sub

'================================================================================================
' "EAGetMail Event Handler"
'  You don't have to use EAGetMail Event, but using Event make your application more user friendly
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

Private Sub oClient_OnSendingDataStream(ByVal oSender As Object, ByVal Sent As Long, ByVal Total As Long, Cancel As Boolean)
        pgBar.Min = 0
        pgBar.Max = 100
        pgBar.value = (Sent / Total) * 100
        DoEvents
        Cancel = m_bCancel
End Sub

Private Sub oClient_OnSecuring(ByVal oSender As Object, Cancel As Boolean)
        textStatus.SimpleText = "Securing ..."
        Cancel = m_bCancel
End Sub
'================================================================================================
'"EAGetMail Event Handler" end
'================================================================================================

Private Sub EnableButton(IsEnabled As Boolean)

    btnDelete.Enabled = IsEnabled
    btnUndelete.Enabled = IsEnabled
    btnUnread.Enabled = IsEnabled
    btnExpunge.Enabled = IsEnabled
    btnMove.Enabled = IsEnabled
    btnCopy.Enabled = IsEnabled
    btnUpload.Enabled = IsEnabled
    
    If SelectedCounts() = 0 Then
        btnDelete.Enabled = False
        btnUndelete.Enabled = False
        btnUnread.Enabled = False
        btnCopy.Enabled = False
        btnMove.Enabled = False
    End If

    Dim folderNode
    Set folderNode = lstFolder.SelectedItem
    If folderNode Is Nothing Then
        btnUpload.Enabled = False
    Else
        If folderNode.Parent Is Nothing Then
            btnUpload.Enabled = False
        End If
    End If
    
    btnCancel.Enabled = (Not IsEnabled)

    If btnStart.Enabled Then
        btnCancel.Enabled = False
    End If

    btnQuit.Enabled = IsEnabled
    lstFolder.Enabled = IsEnabled
    lstMail.Enabled = IsEnabled

    If Not (oCurServer Is Nothing) Then
    
        If (oCurServer.Protocol = MailServerEWS Or _
            oCurServer.Protocol = MailServerDAV) Then
        ' Exchange WebDAV and EWS doesn't support this operating
            btnUndelete.Enabled = False
            btnExpunge.Enabled = False
        End If
    End If
End Sub

