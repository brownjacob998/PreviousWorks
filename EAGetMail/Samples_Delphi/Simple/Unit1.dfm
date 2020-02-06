object Form1: TForm1
  Left = 272
  Top = 244
  AutoScroll = False
  Caption = 'Form1'
  ClientHeight = 496
  ClientWidth = 781
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
  object lblTotal: TLabel
    Left = 280
    Top = 190
    Width = 24
    Height = 13
    Caption = 'Total'
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 265
    Height = 417
    Caption = 'Accout Information'
    TabOrder = 0
    object Label1: TLabel
      Left = 8
      Top = 26
      Width = 31
      Height = 13
      Caption = 'Server'
    end
    object Label2: TLabel
      Left = 8
      Top = 54
      Width = 22
      Height = 13
      Caption = 'User'
    end
    object Label3: TLabel
      Left = 8
      Top = 79
      Width = 46
      Height = 13
      Caption = 'Password'
    end
    object Label4: TLabel
      Left = 8
      Top = 138
      Width = 49
      Height = 13
      Caption = 'Auth Type'
    end
    object Label5: TLabel
      Left = 8
      Top = 164
      Width = 39
      Height = 13
      Caption = 'Protocol'
    end
    object Label6: TLabel
      Left = 8
      Top = 216
      Width = 239
      Height = 39
      Caption = 
        'Warning: if "leave a copy of message on server" is not checked, ' +
        ' the emails on the server will be deleted !'
      WordWrap = True
    end
    object textServer: TEdit
      Left = 74
      Top = 23
      Width = 177
      Height = 21
      TabOrder = 0
    end
    object textUser: TEdit
      Left = 74
      Top = 49
      Width = 177
      Height = 21
      TabOrder = 1
    end
    object textPassword: TEdit
      Left = 74
      Top = 76
      Width = 177
      Height = 21
      PasswordChar = '*'
      TabOrder = 2
    end
    object chkSSL: TCheckBox
      Left = 8
      Top = 104
      Width = 241
      Height = 25
      Caption = 'My server requires SSL connection'
      Checked = True
      State = cbChecked
      TabOrder = 3
    end
    object lstAuthType: TComboBox
      Left = 75
      Top = 133
      Width = 177
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      TabOrder = 4
      OnChange = lstAuthTypeChange
    end
    object lstProtocol: TComboBox
      Left = 75
      Top = 160
      Width = 177
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      TabOrder = 5
      OnChange = lstProtocolChange
    end
    object chkLeaveCopy: TCheckBox
      Left = 8
      Top = 192
      Width = 249
      Height = 17
      Caption = 'Leave a copy of message on server'
      Checked = True
      State = cbChecked
      TabOrder = 6
    end
    object btnStart: TButton
      Left = 9
      Top = 349
      Width = 113
      Height = 25
      Caption = 'Start'
      TabOrder = 9
      OnClick = btnStartClick
    end
    object btnCancel: TButton
      Left = 135
      Top = 349
      Width = 113
      Height = 25
      Caption = 'Cancel'
      Enabled = False
      TabOrder = 10
      OnClick = btnCancelClick
    end
    object pgBar: TProgressBar
      Left = 8
      Top = 385
      Width = 243
      Height = 17
      TabOrder = 11
    end
    object chkNewOnly: TCheckBox
      Left = 8
      Top = 264
      Width = 193
      Height = 33
      Caption = 'Retrieve new email only (IMAP, EWS, WebDAV)'
      Enabled = False
      TabOrder = 7
      WordWrap = True
    end
    object lstDateRange: TComboBox
      Left = 8
      Top = 312
      Width = 241
      Height = 21
      Style = csDropDownList
      Enabled = False
      ItemHeight = 13
      TabOrder = 8
    end
  end
  object lstMail: TListView
    Left = 280
    Top = 13
    Width = 489
    Height = 164
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
    RowSelect = True
    ParentFont = False
    SortType = stText
    TabOrder = 1
    ViewStyle = vsReport
    OnCompare = lstMailCompare
    OnSelectItem = lstMailSelectItem
  end
  object btnDel: TButton
    Left = 704
    Top = 186
    Width = 65
    Height = 22
    Caption = 'Delete'
    TabOrder = 2
    OnClick = btnDelClick
  end
  object webMail: TWebBrowser
    Left = 280
    Top = 216
    Width = 489
    Height = 249
    TabOrder = 3
    ControlData = {
      4C0000008A320000BC1900000000000000000000000000000000000000000000
      000000004C000000000000000000000001000000E0D057007335CF11AE690800
      2B2E126208000000000000004C0000000114020000000000C000000000000046
      8000000000000000000000000000000000000000000000000000000000000000
      00000000000000000100000000000000000000000000000000000000}
  end
  object textStatus: TStatusBar
    Left = 0
    Top = 472
    Width = 781
    Height = 24
    Panels = <>
  end
end
