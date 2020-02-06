object Form1: TForm1
  Left = 100
  Top = 188
  AutoScroll = False
  Caption = 'Full Example for IMAP4 and Exchange Web Service/WebDAV'
  ClientHeight = 482
  ClientWidth = 941
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 255
    Height = 353
    Caption = 'Accout Information'
    TabOrder = 0
    object Label1: TLabel
      Left = 9
      Top = 26
      Width = 31
      Height = 13
      Caption = 'Server'
    end
    object Label2: TLabel
      Left = 9
      Top = 54
      Width = 22
      Height = 13
      Caption = 'User'
    end
    object Label3: TLabel
      Left = 9
      Top = 79
      Width = 46
      Height = 13
      Caption = 'Password'
    end
    object Label4: TLabel
      Left = 9
      Top = 147
      Width = 49
      Height = 13
      Caption = 'Auth Type'
    end
    object Label5: TLabel
      Left = 9
      Top = 173
      Width = 39
      Height = 13
      Caption = 'Protocol'
    end
    object textServer: TEdit
      Left = 74
      Top = 23
      Width = 167
      Height = 21
      TabOrder = 0
    end
    object textUser: TEdit
      Left = 74
      Top = 49
      Width = 167
      Height = 21
      TabOrder = 1
    end
    object textPassword: TEdit
      Left = 74
      Top = 76
      Width = 167
      Height = 21
      PasswordChar = '*'
      TabOrder = 2
    end
    object chkSSL: TCheckBox
      Left = 9
      Top = 106
      Width = 225
      Height = 25
      Caption = 'My server requires SSL connection'
      Checked = True
      State = cbChecked
      TabOrder = 3
    end
    object lstAuthType: TComboBox
      Left = 75
      Top = 142
      Width = 166
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      TabOrder = 4
    end
    object lstProtocol: TComboBox
      Left = 75
      Top = 169
      Width = 166
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      TabOrder = 5
    end
    object btnStart: TButton
      Left = 9
      Top = 248
      Width = 232
      Height = 25
      Caption = 'Start'
      TabOrder = 7
      OnClick = btnStartClick
    end
    object btnCancel: TButton
      Left = 9
      Top = 312
      Width = 232
      Height = 25
      Caption = 'Cancel'
      Enabled = False
      TabOrder = 9
      OnClick = btnCancelClick
    end
    object btnQuit: TButton
      Left = 9
      Top = 279
      Width = 232
      Height = 25
      Caption = 'Quit'
      Enabled = False
      TabOrder = 8
      OnClick = btnQuitClick
    end
    object lstDateRange: TComboBox
      Left = 9
      Top = 208
      Width = 232
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      TabOrder = 6
    end
  end
  object lstMail: TListView
    Left = 448
    Top = 13
    Width = 481
    Height = 153
    Columns = <
      item
        Caption = 'From'
        Width = 150
      end
      item
        Caption = 'Subject'
        Width = 190
      end
      item
        Caption = 'Date'
        Width = 150
      end
      item
        Width = 0
      end>
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    GridLines = True
    HideSelection = False
    MultiSelect = True
    RowSelect = True
    ParentFont = False
    SortType = stText
    TabOrder = 3
    ViewStyle = vsReport
    OnAdvancedCustomDrawItem = lstMailAdvancedCustomDrawItem
    OnCompare = lstMailCompare
    OnSelectItem = lstMailSelectItem
  end
  object btnDel: TButton
    Left = 448
    Top = 169
    Width = 64
    Height = 25
    Caption = 'Delete'
    Enabled = False
    TabOrder = 5
    OnClick = btnDelClick
  end
  object webMail: TWebBrowser
    Left = 449
    Top = 200
    Width = 480
    Height = 234
    TabOrder = 12
    ControlData = {
      4C0000009C3100002F1800000000000000000000000000000000000000000000
      000000004C000000000000000000000001000000E0D057007335CF11AE690800
      2B2E126208000000000000004C0000000114020000000000C000000000000046
      8000000000000000000000000000000000000000000000000000000000000000
      00000000000000000100000000000000000000000000000000000000}
  end
  object trFolder: TTreeView
    Left = 272
    Top = 14
    Width = 169
    Height = 435
    HideSelection = False
    Indent = 19
    PopupMenu = PopupMenu1
    TabOrder = 2
    OnChange = trFolderChange
    OnEdited = trFolderEdited
  end
  object pgBar: TProgressBar
    Left = 448
    Top = 438
    Width = 481
    Height = 11
    TabOrder = 1
  end
  object btnUndelete: TButton
    Left = 519
    Top = 169
    Width = 63
    Height = 25
    Caption = 'Undelete'
    Enabled = False
    TabOrder = 6
    OnClick = btnUndeleteClick
  end
  object btnUnread: TButton
    Left = 588
    Top = 169
    Width = 64
    Height = 25
    Caption = 'Unread'
    Enabled = False
    TabOrder = 7
    OnClick = btnUnreadClick
  end
  object btnExpunge: TButton
    Left = 793
    Top = 169
    Width = 64
    Height = 25
    Caption = 'Expunge'
    Enabled = False
    TabOrder = 10
    OnClick = btnExpungeClick
  end
  object btnCopy: TButton
    Left = 662
    Top = 169
    Width = 54
    Height = 25
    Caption = 'Copy'
    Enabled = False
    TabOrder = 8
    OnClick = btnCopyClick
  end
  object btnMove: TButton
    Left = 723
    Top = 169
    Width = 64
    Height = 25
    Caption = 'Move'
    Enabled = False
    TabOrder = 9
    OnClick = btnMoveClick
  end
  object btnUpload: TButton
    Left = 864
    Top = 169
    Width = 64
    Height = 25
    Caption = 'Upload'
    Enabled = False
    TabOrder = 11
    OnClick = btnUploadClick
  end
  object textStatus: TStatusBar
    Left = 0
    Top = 456
    Width = 941
    Height = 26
    Panels = <>
  end
  object PopupMenu1: TPopupMenu
    OnPopup = PopupMenu1Popup
    Left = 120
    Top = 400
    object RefreshFolders: TMenuItem
      Caption = 'Refresh Folders'
      OnClick = RefreshFoldersClick
    end
    object RefreshMails: TMenuItem
      Caption = 'Refresh Mails'
      OnClick = RefreshMailsClick
    end
    object AddFolder: TMenuItem
      Caption = 'Add Folder'
      OnClick = AddFolderClick
    end
    object DeleteFolder: TMenuItem
      Caption = 'Delete Folder'
      OnClick = DeleteFolderClick
    end
    object RenameFolder: TMenuItem
      Caption = 'Rename Folder'
      OnClick = RenameFolderClick
    end
  end
end
