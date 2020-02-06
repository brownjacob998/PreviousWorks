VERSION 5.00
Object = "{EAB22AC0-30C1-11CF-A7EB-0000C05BAE0B}#1.1#0"; "shdocvw.dll"
Begin VB.Form DlgOAUTH 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Gmail Web Login"
   ClientHeight    =   8520
   ClientLeft      =   2760
   ClientTop       =   3750
   ClientWidth     =   7710
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   8520
   ScaleWidth      =   7710
   ShowInTaskbar   =   0   'False
   StartUpPosition =   1  'CenterOwner
   Begin SHDocVwCtl.WebBrowser OauthBrowser 
      Height          =   8055
      Left            =   120
      TabIndex        =   0
      Top             =   240
      Width           =   7455
      ExtentX         =   13150
      ExtentY         =   14208
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
End
Attribute VB_Name = "DlgOAUTH"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Option Explicit

Private Sub Form_Load()
    Dim authPath As String
    authPath = Form1.Oauth.GetFullAuthUri()
    OauthBrowser.Object.Navigate authPath
End Sub

Private Sub OauthBrowser_DocumentComplete(ByVal pDisp As Object, URL As Variant)
    
    Dim htmlDoc As HTMLDocument
    Set htmlDoc = OauthBrowser.Object.Document
    
    Dim htmlInput As HTMLInputElement
    Set htmlInput = htmlDoc.getElementById("code")
    
    If htmlInput Is Nothing Then
        Exit Sub
    End If
    
    Dim code As String
    code = htmlInput.Value
    
    ' MsgBox code
    If code <> "" Then
        Form1.Oauth.AuthorizationCode = code
        Unload Me
    End If

End Sub
