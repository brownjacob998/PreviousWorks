<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Friend WithEvents components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()>
    Private Sub InitializeComponent()
        Me.label1 = New System.Windows.Forms.Label()
        Me.label2 = New System.Windows.Forms.Label()
        Me.label3 = New System.Windows.Forms.Label()
        Me.label4 = New System.Windows.Forms.Label()
        Me.TextBoxFrom = New System.Windows.Forms.TextBox()
        Me.TextBoxTo = New System.Windows.Forms.TextBox()
        Me.TextBoxCc = New System.Windows.Forms.TextBox()
        Me.TextBoxSubject = New System.Windows.Forms.TextBox()
        Me.GroupBoxServer = New System.Windows.Forms.GroupBox()
        Me.ComboBoxPorts = New System.Windows.Forms.ComboBox()
        Me.Server = New System.Windows.Forms.Label()
        Me.TextBoxServer = New System.Windows.Forms.TextBox()
        Me.label8 = New System.Windows.Forms.Label()
        Me.TextBoxAttachments = New System.Windows.Forms.TextBox()
        Me.ButtonSend = New System.Windows.Forms.Button()
        Me.ProgressBarSend = New System.Windows.Forms.ProgressBar()
        Me.StatusBarSend = New System.Windows.Forms.StatusBar()
        Me.label9 = New System.Windows.Forms.Label()
        Me.ComboBoxEncoding = New System.Windows.Forms.ComboBox()
        Me.ButtonAddAttachment = New System.Windows.Forms.Button()
        Me.ButtonClearAttachments = New System.Windows.Forms.Button()
        Me.OpenFileDialogAttachment = New System.Windows.Forms.OpenFileDialog()
        Me.CheckBoxSignature = New System.Windows.Forms.CheckBox()
        Me.CheckBoxEncrypt = New System.Windows.Forms.CheckBox()
        Me.ColorDialogForeColor = New System.Windows.Forms.ColorDialog()
        Me.ComboBoxFont = New System.Windows.Forms.ComboBox()
        Me.ComboBoxSize = New System.Windows.Forms.ComboBox()
        Me.ButtonBold = New System.Windows.Forms.Button()
        Me.ButtonItalic = New System.Windows.Forms.Button()
        Me.ButtonUnderline = New System.Windows.Forms.Button()
        Me.ButtonColor = New System.Windows.Forms.Button()
        Me.ButtonInsertImage = New System.Windows.Forms.Button()
        Me.ButtonCancel = New System.Windows.Forms.Button()
        Me.HtmlEditor = New System.Windows.Forms.WebBrowser()
        Me.ButtonClearToken = New System.Windows.Forms.Button()
        Me.GroupBoxServer.SuspendLayout()
        Me.SuspendLayout()
        '
        'label1
        '
        Me.label1.AutoSize = True
        Me.label1.Location = New System.Drawing.Point(18, 23)
        Me.label1.Name = "label1"
        Me.label1.Size = New System.Drawing.Size(44, 18)
        Me.label1.TabIndex = 0
        Me.label1.Text = "From"
        '
        'label2
        '
        Me.label2.AutoSize = True
        Me.label2.Location = New System.Drawing.Point(18, 57)
        Me.label2.Name = "label2"
        Me.label2.Size = New System.Drawing.Size(26, 18)
        Me.label2.TabIndex = 1
        Me.label2.Text = "To"
        '
        'label3
        '
        Me.label3.AutoSize = True
        Me.label3.Location = New System.Drawing.Point(18, 90)
        Me.label3.Name = "label3"
        Me.label3.Size = New System.Drawing.Size(27, 18)
        Me.label3.TabIndex = 2
        Me.label3.Text = "Cc"
        '
        'label4
        '
        Me.label4.AutoSize = True
        Me.label4.Location = New System.Drawing.Point(18, 123)
        Me.label4.Name = "label4"
        Me.label4.Size = New System.Drawing.Size(57, 18)
        Me.label4.TabIndex = 3
        Me.label4.Text = "Subject"
        '
        'TextBoxFrom
        '
        Me.TextBoxFrom.Location = New System.Drawing.Point(84, 23)
        Me.TextBoxFrom.Name = "TextBoxFrom"
        Me.TextBoxFrom.Size = New System.Drawing.Size(344, 24)
        Me.TextBoxFrom.TabIndex = 1
        '
        'TextBoxTo
        '
        Me.TextBoxTo.Location = New System.Drawing.Point(84, 55)
        Me.TextBoxTo.Name = "TextBoxTo"
        Me.TextBoxTo.Size = New System.Drawing.Size(344, 24)
        Me.TextBoxTo.TabIndex = 2
        '
        'TextBoxCc
        '
        Me.TextBoxCc.Location = New System.Drawing.Point(84, 87)
        Me.TextBoxCc.Name = "TextBoxCc"
        Me.TextBoxCc.Size = New System.Drawing.Size(344, 24)
        Me.TextBoxCc.TabIndex = 3
        '
        'TextBoxSubject
        '
        Me.TextBoxSubject.Location = New System.Drawing.Point(84, 121)
        Me.TextBoxSubject.Name = "TextBoxSubject"
        Me.TextBoxSubject.Size = New System.Drawing.Size(344, 24)
        Me.TextBoxSubject.TabIndex = 4
        Me.TextBoxSubject.Text = "Test email from GmailOauth sample"
        '
        'GroupBoxServer
        '
        Me.GroupBoxServer.Controls.Add(Me.ComboBoxPorts)
        Me.GroupBoxServer.Controls.Add(Me.Server)
        Me.GroupBoxServer.Controls.Add(Me.TextBoxServer)
        Me.GroupBoxServer.Location = New System.Drawing.Point(457, 10)
        Me.GroupBoxServer.Name = "GroupBoxServer"
        Me.GroupBoxServer.Size = New System.Drawing.Size(326, 223)
        Me.GroupBoxServer.TabIndex = 8
        Me.GroupBoxServer.TabStop = False
        '
        'ComboBoxPorts
        '
        Me.ComboBoxPorts.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.ComboBoxPorts.FormattingEnabled = True
        Me.ComboBoxPorts.Location = New System.Drawing.Point(254, 19)
        Me.ComboBoxPorts.Name = "ComboBoxPorts"
        Me.ComboBoxPorts.Size = New System.Drawing.Size(55, 26)
        Me.ComboBoxPorts.TabIndex = 16
        '
        'Server
        '
        Me.Server.AutoSize = True
        Me.Server.Location = New System.Drawing.Point(13, 23)
        Me.Server.Name = "Server"
        Me.Server.Size = New System.Drawing.Size(51, 18)
        Me.Server.TabIndex = 0
        Me.Server.Text = "Server"
        '
        'TextBoxServer
        '
        Me.TextBoxServer.Location = New System.Drawing.Point(87, 20)
        Me.TextBoxServer.Name = "TextBoxServer"
        Me.TextBoxServer.Size = New System.Drawing.Size(163, 24)
        Me.TextBoxServer.TabIndex = 10
        Me.TextBoxServer.Text = "smtp.gmail.com"
        '
        'label8
        '
        Me.label8.AutoSize = True
        Me.label8.Location = New System.Drawing.Point(18, 246)
        Me.label8.Name = "label8"
        Me.label8.Size = New System.Drawing.Size(90, 18)
        Me.label8.TabIndex = 9
        Me.label8.Text = "Attachments"
        '
        'TextBoxAttachments
        '
        Me.TextBoxAttachments.BackColor = System.Drawing.SystemColors.Info
        Me.TextBoxAttachments.ForeColor = System.Drawing.SystemColors.HotTrack
        Me.TextBoxAttachments.Location = New System.Drawing.Point(114, 243)
        Me.TextBoxAttachments.Name = "TextBoxAttachments"
        Me.TextBoxAttachments.ReadOnly = True
        Me.TextBoxAttachments.Size = New System.Drawing.Size(546, 24)
        Me.TextBoxAttachments.TabIndex = 6
        '
        'ButtonSend
        '
        Me.ButtonSend.Location = New System.Drawing.Point(479, 509)
        Me.ButtonSend.Name = "ButtonSend"
        Me.ButtonSend.Size = New System.Drawing.Size(93, 28)
        Me.ButtonSend.TabIndex = 15
        Me.ButtonSend.TabStop = False
        Me.ButtonSend.Text = "Send"
        '
        'ProgressBarSend
        '
        Me.ProgressBarSend.Location = New System.Drawing.Point(12, 518)
        Me.ProgressBarSend.Name = "ProgressBarSend"
        Me.ProgressBarSend.Size = New System.Drawing.Size(427, 10)
        Me.ProgressBarSend.TabIndex = 13
        '
        'StatusBarSend
        '
        Me.StatusBarSend.Location = New System.Drawing.Point(0, 555)
        Me.StatusBarSend.Name = "StatusBarSend"
        Me.StatusBarSend.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.StatusBarSend.Size = New System.Drawing.Size(800, 27)
        Me.StatusBarSend.TabIndex = 14
        '
        'label9
        '
        Me.label9.AutoSize = True
        Me.label9.Location = New System.Drawing.Point(19, 162)
        Me.label9.Name = "label9"
        Me.label9.Size = New System.Drawing.Size(70, 18)
        Me.label9.TabIndex = 15
        Me.label9.Text = "Encoding"
        '
        'ComboBoxEncoding
        '
        Me.ComboBoxEncoding.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.ComboBoxEncoding.Location = New System.Drawing.Point(97, 158)
        Me.ComboBoxEncoding.Name = "ComboBoxEncoding"
        Me.ComboBoxEncoding.Size = New System.Drawing.Size(229, 26)
        Me.ComboBoxEncoding.TabIndex = 5
        '
        'ButtonAddAttachment
        '
        Me.ButtonAddAttachment.Location = New System.Drawing.Point(675, 241)
        Me.ButtonAddAttachment.Name = "ButtonAddAttachment"
        Me.ButtonAddAttachment.Size = New System.Drawing.Size(46, 28)
        Me.ButtonAddAttachment.TabIndex = 7
        Me.ButtonAddAttachment.Text = "Add"
        '
        'ButtonClearAttachments
        '
        Me.ButtonClearAttachments.Location = New System.Drawing.Point(728, 241)
        Me.ButtonClearAttachments.Name = "ButtonClearAttachments"
        Me.ButtonClearAttachments.Size = New System.Drawing.Size(54, 28)
        Me.ButtonClearAttachments.TabIndex = 8
        Me.ButtonClearAttachments.Text = "Clear"
        '
        'CheckBoxSignature
        '
        Me.CheckBoxSignature.AutoSize = True
        Me.CheckBoxSignature.Location = New System.Drawing.Point(21, 200)
        Me.CheckBoxSignature.Name = "CheckBoxSignature"
        Me.CheckBoxSignature.Size = New System.Drawing.Size(139, 22)
        Me.CheckBoxSignature.TabIndex = 17
        Me.CheckBoxSignature.Text = "Digitial Signature"
        '
        'CheckBoxEncrypt
        '
        Me.CheckBoxEncrypt.AutoSize = True
        Me.CheckBoxEncrypt.Location = New System.Drawing.Point(184, 200)
        Me.CheckBoxEncrypt.Name = "CheckBoxEncrypt"
        Me.CheckBoxEncrypt.Size = New System.Drawing.Size(80, 22)
        Me.CheckBoxEncrypt.TabIndex = 18
        Me.CheckBoxEncrypt.Text = "Encrypt"
        '
        'ComboBoxFont
        '
        Me.ComboBoxFont.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.ComboBoxFont.Location = New System.Drawing.Point(17, 273)
        Me.ComboBoxFont.Name = "ComboBoxFont"
        Me.ComboBoxFont.Size = New System.Drawing.Size(159, 26)
        Me.ComboBoxFont.TabIndex = 20
        '
        'ComboBoxSize
        '
        Me.ComboBoxSize.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.ComboBoxSize.Location = New System.Drawing.Point(185, 273)
        Me.ComboBoxSize.Name = "ComboBoxSize"
        Me.ComboBoxSize.Size = New System.Drawing.Size(94, 26)
        Me.ComboBoxSize.TabIndex = 21
        '
        'ButtonBold
        '
        Me.ButtonBold.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.ButtonBold.Location = New System.Drawing.Point(288, 272)
        Me.ButtonBold.Name = "ButtonBold"
        Me.ButtonBold.Size = New System.Drawing.Size(28, 28)
        Me.ButtonBold.TabIndex = 22
        Me.ButtonBold.Text = "B"
        '
        'ButtonItalic
        '
        Me.ButtonItalic.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, CType((System.Drawing.FontStyle.Bold Or System.Drawing.FontStyle.Italic), System.Drawing.FontStyle), System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.ButtonItalic.Location = New System.Drawing.Point(316, 272)
        Me.ButtonItalic.Name = "ButtonItalic"
        Me.ButtonItalic.Size = New System.Drawing.Size(28, 28)
        Me.ButtonItalic.TabIndex = 23
        Me.ButtonItalic.Text = "I"
        '
        'ButtonUnderline
        '
        Me.ButtonUnderline.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, CType((System.Drawing.FontStyle.Bold Or System.Drawing.FontStyle.Underline), System.Drawing.FontStyle), System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.ButtonUnderline.Location = New System.Drawing.Point(344, 272)
        Me.ButtonUnderline.Name = "ButtonUnderline"
        Me.ButtonUnderline.Size = New System.Drawing.Size(28, 28)
        Me.ButtonUnderline.TabIndex = 24
        Me.ButtonUnderline.Text = "U"
        '
        'ButtonColor
        '
        Me.ButtonColor.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.ButtonColor.ForeColor = System.Drawing.Color.Red
        Me.ButtonColor.Location = New System.Drawing.Point(372, 272)
        Me.ButtonColor.Name = "ButtonColor"
        Me.ButtonColor.Size = New System.Drawing.Size(28, 28)
        Me.ButtonColor.TabIndex = 25
        Me.ButtonColor.Text = "C"
        '
        'ButtonInsertImage
        '
        Me.ButtonInsertImage.Location = New System.Drawing.Point(419, 272)
        Me.ButtonInsertImage.Name = "ButtonInsertImage"
        Me.ButtonInsertImage.Size = New System.Drawing.Size(102, 28)
        Me.ButtonInsertImage.TabIndex = 26
        Me.ButtonInsertImage.Text = "Insert Picture"
        '
        'ButtonCancel
        '
        Me.ButtonCancel.Enabled = False
        Me.ButtonCancel.Location = New System.Drawing.Point(577, 509)
        Me.ButtonCancel.Name = "ButtonCancel"
        Me.ButtonCancel.Size = New System.Drawing.Size(93, 28)
        Me.ButtonCancel.TabIndex = 27
        Me.ButtonCancel.TabStop = False
        Me.ButtonCancel.Text = "Cancel"
        '
        'HtmlEditor
        '
        Me.HtmlEditor.Location = New System.Drawing.Point(15, 304)
        Me.HtmlEditor.MinimumSize = New System.Drawing.Size(20, 20)
        Me.HtmlEditor.Name = "HtmlEditor"
        Me.HtmlEditor.Size = New System.Drawing.Size(769, 188)
        Me.HtmlEditor.TabIndex = 28
        '
        'ButtonClearToken
        '
        Me.ButtonClearToken.Enabled = False
        Me.ButtonClearToken.Location = New System.Drawing.Point(675, 509)
        Me.ButtonClearToken.Name = "ButtonClearToken"
        Me.ButtonClearToken.Size = New System.Drawing.Size(111, 28)
        Me.ButtonClearToken.TabIndex = 29
        Me.ButtonClearToken.Text = "Clear Token"
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(9.0!, 18.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(800, 582)
        Me.Controls.Add(Me.ButtonClearToken)
        Me.Controls.Add(Me.HtmlEditor)
        Me.Controls.Add(Me.ButtonCancel)
        Me.Controls.Add(Me.ButtonInsertImage)
        Me.Controls.Add(Me.ButtonColor)
        Me.Controls.Add(Me.ButtonUnderline)
        Me.Controls.Add(Me.ButtonItalic)
        Me.Controls.Add(Me.ButtonBold)
        Me.Controls.Add(Me.ComboBoxSize)
        Me.Controls.Add(Me.ComboBoxFont)
        Me.Controls.Add(Me.CheckBoxEncrypt)
        Me.Controls.Add(Me.CheckBoxSignature)
        Me.Controls.Add(Me.ButtonClearAttachments)
        Me.Controls.Add(Me.ButtonAddAttachment)
        Me.Controls.Add(Me.ComboBoxEncoding)
        Me.Controls.Add(Me.label9)
        Me.Controls.Add(Me.TextBoxAttachments)
        Me.Controls.Add(Me.label8)
        Me.Controls.Add(Me.TextBoxSubject)
        Me.Controls.Add(Me.TextBoxCc)
        Me.Controls.Add(Me.TextBoxTo)
        Me.Controls.Add(Me.TextBoxFrom)
        Me.Controls.Add(Me.label4)
        Me.Controls.Add(Me.label3)
        Me.Controls.Add(Me.label2)
        Me.Controls.Add(Me.label1)
        Me.Controls.Add(Me.StatusBarSend)
        Me.Controls.Add(Me.ProgressBarSend)
        Me.Controls.Add(Me.ButtonSend)
        Me.Controls.Add(Me.GroupBoxServer)
        Me.Font = New System.Drawing.Font("Microsoft Sans Serif", 9.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.GroupBoxServer.ResumeLayout(False)
        Me.GroupBoxServer.PerformLayout()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents label1 As System.Windows.Forms.Label
    Friend WithEvents label2 As System.Windows.Forms.Label
    Friend WithEvents label3 As System.Windows.Forms.Label
    Friend WithEvents label4 As System.Windows.Forms.Label
    Friend WithEvents GroupBoxServer As System.Windows.Forms.GroupBox
    Friend WithEvents label8 As System.Windows.Forms.Label
    Friend WithEvents label9 As System.Windows.Forms.Label
    Friend WithEvents TextBoxFrom As System.Windows.Forms.TextBox
    Friend WithEvents TextBoxTo As System.Windows.Forms.TextBox
    Friend WithEvents TextBoxCc As System.Windows.Forms.TextBox
    Friend WithEvents TextBoxSubject As System.Windows.Forms.TextBox
    Friend WithEvents Server As System.Windows.Forms.Label
    Friend WithEvents TextBoxServer As System.Windows.Forms.TextBox
    Friend WithEvents TextBoxAttachments As System.Windows.Forms.TextBox
    Friend WithEvents ButtonSend As System.Windows.Forms.Button
    Friend WithEvents ProgressBarSend As System.Windows.Forms.ProgressBar
    Friend WithEvents StatusBarSend As System.Windows.Forms.StatusBar
    Friend WithEvents ButtonAddAttachment As System.Windows.Forms.Button
    Friend WithEvents ButtonClearAttachments As System.Windows.Forms.Button
    Friend WithEvents ComboBoxEncoding As System.Windows.Forms.ComboBox
    Friend WithEvents CheckBoxSignature As System.Windows.Forms.CheckBox
    Friend WithEvents CheckBoxEncrypt As System.Windows.Forms.CheckBox
    Friend WithEvents ComboBoxFont As System.Windows.Forms.ComboBox
    Friend WithEvents ComboBoxSize As System.Windows.Forms.ComboBox
    Friend WithEvents ButtonBold As System.Windows.Forms.Button
    Friend WithEvents ButtonItalic As System.Windows.Forms.Button
    Friend WithEvents ButtonUnderline As System.Windows.Forms.Button
    Friend WithEvents ButtonColor As System.Windows.Forms.Button
    Friend WithEvents ButtonInsertImage As System.Windows.Forms.Button
    Friend WithEvents ButtonCancel As System.Windows.Forms.Button
    Friend WithEvents HtmlEditor As System.Windows.Forms.WebBrowser
    Friend WithEvents ComboBoxPorts As System.Windows.Forms.ComboBox
    Friend WithEvents ButtonClearToken As System.Windows.Forms.Button

    Private OpenFileDialogAttachment As System.Windows.Forms.OpenFileDialog
    Private ColorDialogForeColor As System.Windows.Forms.ColorDialog

End Class
