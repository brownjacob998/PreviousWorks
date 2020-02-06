VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Begin VB.Form FormSelectFolder 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Select Folder"
   ClientHeight    =   6915
   ClientLeft      =   2760
   ClientTop       =   3750
   ClientWidth     =   5985
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   6915
   ScaleWidth      =   5985
   ShowInTaskbar   =   0   'False
   Begin MSComctlLib.TreeView lstFolder 
      Height          =   6015
      Left            =   240
      TabIndex        =   2
      Top             =   120
      Width           =   5535
      _ExtentX        =   9763
      _ExtentY        =   10610
      _Version        =   393217
      Style           =   7
      Appearance      =   1
   End
   Begin VB.CommandButton CancelButton 
      Caption         =   "Cancel"
      Height          =   375
      Left            =   4560
      TabIndex        =   1
      Top             =   6360
      Width           =   1215
   End
   Begin VB.CommandButton OKButton 
      Caption         =   "OK"
      Height          =   375
      Left            =   3240
      TabIndex        =   0
      Top             =   6360
      Width           =   1215
   End
End
Attribute VB_Name = "FormSelectFolder"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Option Explicit
Public OriginalFolder As String
Private Sub CancelButton_Click()
   lstFolder.SelectedItem = Nothing
   Me.Hide
End Sub

Private Sub OKButton_Click()
   Dim folderNode As Node
   Set folderNode = lstFolder.SelectedItem
   If folderNode Is Nothing Then
      MsgBox "Please select a folder!"
      Exit Sub
   End If
   
   If folderNode.Parent Is Nothing Then
      MsgBox "Please select a folder!"
      Exit Sub
   End If
   
   Dim oFolder As EAGetMailObjLib.Imap4Folder
   Set oFolder = folderNode.Tag
   
   If Not (oFolder Is Nothing) And (oFolder.ServerPath = OriginalFolder) Then
      MsgBox "Please select a folder different with original folder!"
      Exit Sub
   End If
   
   Me.Hide
End Sub
