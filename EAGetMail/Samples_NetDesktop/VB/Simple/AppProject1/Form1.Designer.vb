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
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.GroupBoxServer = New System.Windows.Forms.GroupBox()
        Me.ComboBoxDateRange = New System.Windows.Forms.ComboBox()
        Me.chkNewOnly = New System.Windows.Forms.CheckBox()
        Me.label6 = New System.Windows.Forms.Label()
        Me.pgBar = New System.Windows.Forms.ProgressBar()
        Me.btnCancel = New System.Windows.Forms.Button()
        Me.btnStart = New System.Windows.Forms.Button()
        Me.chkLeaveCopy = New System.Windows.Forms.CheckBox()
        Me.ComboBoxProtocol = New System.Windows.Forms.ComboBox()
        Me.label5 = New System.Windows.Forms.Label()
        Me.ComboBoxAuthType = New System.Windows.Forms.ComboBox()
        Me.label4 = New System.Windows.Forms.Label()
        Me.chkSSL = New System.Windows.Forms.CheckBox()
        Me.textPassword = New System.Windows.Forms.TextBox()
        Me.textUser = New System.Windows.Forms.TextBox()
        Me.textServer = New System.Windows.Forms.TextBox()
        Me.label3 = New System.Windows.Forms.Label()
        Me.label2 = New System.Windows.Forms.Label()
        Me.label1 = New System.Windows.Forms.Label()
        Me.ListViewMail = New System.Windows.Forms.ListView()
        Me.colFrom = CType(New System.Windows.Forms.ColumnHeader(), System.Windows.Forms.ColumnHeader)
        Me.colSubject = CType(New System.Windows.Forms.ColumnHeader(), System.Windows.Forms.ColumnHeader)
        Me.colDate = CType(New System.Windows.Forms.ColumnHeader(), System.Windows.Forms.ColumnHeader)
        Me.ButtonDelete = New System.Windows.Forms.Button()
        Me.LabelTotal = New System.Windows.Forms.Label()
        Me.textStatus = New System.Windows.Forms.StatusBar()
        Me.WebMail = New System.Windows.Forms.WebBrowser()
        Me.GroupBoxServer.SuspendLayout()
        Me.SuspendLayout()
        '
        'GroupBoxServer
        '
        Me.GroupBoxServer.Controls.Add(Me.ComboBoxDateRange)
        Me.GroupBoxServer.Controls.Add(Me.chkNewOnly)
        Me.GroupBoxServer.Controls.Add(Me.label6)
        Me.GroupBoxServer.Controls.Add(Me.pgBar)
        Me.GroupBoxServer.Controls.Add(Me.btnCancel)
        Me.GroupBoxServer.Controls.Add(Me.btnStart)
        Me.GroupBoxServer.Controls.Add(Me.chkLeaveCopy)
        Me.GroupBoxServer.Controls.Add(Me.ComboBoxProtocol)
        Me.GroupBoxServer.Controls.Add(Me.label5)
        Me.GroupBoxServer.Controls.Add(Me.ComboBoxAuthType)
        Me.GroupBoxServer.Controls.Add(Me.label4)
        Me.GroupBoxServer.Controls.Add(Me.chkSSL)
        Me.GroupBoxServer.Controls.Add(Me.textPassword)
        Me.GroupBoxServer.Controls.Add(Me.textUser)
        Me.GroupBoxServer.Controls.Add(Me.textServer)
        Me.GroupBoxServer.Controls.Add(Me.label3)
        Me.GroupBoxServer.Controls.Add(Me.label2)
        Me.GroupBoxServer.Controls.Add(Me.label1)
        Me.GroupBoxServer.Location = New System.Drawing.Point(9, 10)
        Me.GroupBoxServer.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.GroupBoxServer.Name = "GroupBoxServer"
        Me.GroupBoxServer.Padding = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.GroupBoxServer.Size = New System.Drawing.Size(265, 487)
        Me.GroupBoxServer.TabIndex = 0
        Me.GroupBoxServer.TabStop = False
        Me.GroupBoxServer.Text = "Account Information"
        '
        'ComboBoxDateRange
        '
        Me.ComboBoxDateRange.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.ComboBoxDateRange.FormattingEnabled = True
        Me.ComboBoxDateRange.Location = New System.Drawing.Point(9, 395)
        Me.ComboBoxDateRange.Name = "ComboBoxDateRange"
        Me.ComboBoxDateRange.Size = New System.Drawing.Size(239, 23)
        Me.ComboBoxDateRange.TabIndex = 14
        '
        'chkNewOnly
        '
        Me.chkNewOnly.Location = New System.Drawing.Point(9, 342)
        Me.chkNewOnly.Name = "chkNewOnly"
        Me.chkNewOnly.Size = New System.Drawing.Size(215, 38)
        Me.chkNewOnly.TabIndex = 13
        Me.chkNewOnly.Text = "Retrieve new email only (IMAP, EWS, WebDAV)"
        Me.chkNewOnly.UseVisualStyleBackColor = True
        '
        'label6
        '
        Me.label6.ForeColor = System.Drawing.SystemColors.HotTrack
        Me.label6.Location = New System.Drawing.Point(9, 285)
        Me.label6.Name = "label6"
        Me.label6.Size = New System.Drawing.Size(239, 53)
        Me.label6.TabIndex = 12
        Me.label6.Text = "Warning: if ""leave a copy of message on server"" is not checked,  the emails on th" & _
    "e server will be deleted !"
        '
        'pgBar
        '
        Me.pgBar.Location = New System.Drawing.Point(9, 468)
        Me.pgBar.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.pgBar.Name = "pgBar"
        Me.pgBar.Size = New System.Drawing.Size(243, 10)
        Me.pgBar.TabIndex = 17
        '
        'btnCancel
        '
        Me.btnCancel.Enabled = False
        Me.btnCancel.Location = New System.Drawing.Point(133, 429)
        Me.btnCancel.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.btnCancel.Name = "btnCancel"
        Me.btnCancel.Size = New System.Drawing.Size(118, 30)
        Me.btnCancel.TabIndex = 16
        Me.btnCancel.Text = "Cancel"
        '
        'btnStart
        '
        Me.btnStart.Location = New System.Drawing.Point(9, 429)
        Me.btnStart.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.btnStart.Name = "btnStart"
        Me.btnStart.Size = New System.Drawing.Size(118, 30)
        Me.btnStart.TabIndex = 15
        Me.btnStart.Text = "Start"
        '
        'chkLeaveCopy
        '
        Me.chkLeaveCopy.Checked = True
        Me.chkLeaveCopy.CheckState = System.Windows.Forms.CheckState.Checked
        Me.chkLeaveCopy.Location = New System.Drawing.Point(9, 257)
        Me.chkLeaveCopy.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.chkLeaveCopy.Name = "chkLeaveCopy"
        Me.chkLeaveCopy.Size = New System.Drawing.Size(243, 20)
        Me.chkLeaveCopy.TabIndex = 11
        Me.chkLeaveCopy.Text = "Leave a copy of message on server"
        '
        'ComboBoxProtocol
        '
        Me.ComboBoxProtocol.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.ComboBoxProtocol.Location = New System.Drawing.Point(93, 217)
        Me.ComboBoxProtocol.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.ComboBoxProtocol.Name = "ComboBoxProtocol"
        Me.ComboBoxProtocol.Size = New System.Drawing.Size(158, 23)
        Me.ComboBoxProtocol.TabIndex = 10
        '
        'label5
        '
        Me.label5.AutoSize = True
        Me.label5.Location = New System.Drawing.Point(9, 219)
        Me.label5.Name = "label5"
        Me.label5.Size = New System.Drawing.Size(52, 15)
        Me.label5.TabIndex = 9
        Me.label5.Text = "Protocol"
        '
        'ComboBoxAuthType
        '
        Me.ComboBoxAuthType.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.ComboBoxAuthType.Location = New System.Drawing.Point(93, 177)
        Me.ComboBoxAuthType.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.ComboBoxAuthType.Name = "ComboBoxAuthType"
        Me.ComboBoxAuthType.Size = New System.Drawing.Size(158, 23)
        Me.ComboBoxAuthType.TabIndex = 8
        '
        'label4
        '
        Me.label4.AutoSize = True
        Me.label4.Location = New System.Drawing.Point(9, 179)
        Me.label4.Name = "label4"
        Me.label4.Size = New System.Drawing.Size(61, 15)
        Me.label4.TabIndex = 7
        Me.label4.Text = "Auth Type"
        '
        'chkSSL
        '
        Me.chkSSL.Checked = True
        Me.chkSSL.CheckState = System.Windows.Forms.CheckState.Checked
        Me.chkSSL.Location = New System.Drawing.Point(9, 146)
        Me.chkSSL.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.chkSSL.Name = "chkSSL"
        Me.chkSSL.Size = New System.Drawing.Size(243, 20)
        Me.chkSSL.TabIndex = 6
        Me.chkSSL.Text = "SSL connection"
        '
        'textPassword
        '
        Me.textPassword.Location = New System.Drawing.Point(93, 108)
        Me.textPassword.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.textPassword.Name = "textPassword"
        Me.textPassword.PasswordChar = Global.Microsoft.VisualBasic.ChrW(42)
        Me.textPassword.Size = New System.Drawing.Size(158, 23)
        Me.textPassword.TabIndex = 5
        '
        'textUser
        '
        Me.textUser.Location = New System.Drawing.Point(93, 68)
        Me.textUser.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.textUser.Name = "textUser"
        Me.textUser.Size = New System.Drawing.Size(158, 23)
        Me.textUser.TabIndex = 3
        '
        'textServer
        '
        Me.textServer.Location = New System.Drawing.Point(93, 28)
        Me.textServer.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.textServer.Name = "textServer"
        Me.textServer.Size = New System.Drawing.Size(158, 23)
        Me.textServer.TabIndex = 1
        '
        'label3
        '
        Me.label3.AutoSize = True
        Me.label3.Location = New System.Drawing.Point(9, 110)
        Me.label3.Name = "label3"
        Me.label3.Size = New System.Drawing.Size(57, 15)
        Me.label3.TabIndex = 4
        Me.label3.Text = "Password"
        '
        'label2
        '
        Me.label2.AutoSize = True
        Me.label2.Location = New System.Drawing.Point(9, 70)
        Me.label2.Name = "label2"
        Me.label2.Size = New System.Drawing.Size(30, 15)
        Me.label2.TabIndex = 2
        Me.label2.Text = "User"
        '
        'label1
        '
        Me.label1.AutoSize = True
        Me.label1.Location = New System.Drawing.Point(9, 30)
        Me.label1.Name = "label1"
        Me.label1.Size = New System.Drawing.Size(39, 15)
        Me.label1.TabIndex = 0
        Me.label1.Text = "Server"
        '
        'ListViewMail
        '
        Me.ListViewMail.Columns.AddRange(New System.Windows.Forms.ColumnHeader() {Me.colFrom, Me.colSubject, Me.colDate})
        Me.ListViewMail.FullRowSelect = True
        Me.ListViewMail.HideSelection = False
        Me.ListViewMail.Location = New System.Drawing.Point(289, 20)
        Me.ListViewMail.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.ListViewMail.Name = "ListViewMail"
        Me.ListViewMail.Size = New System.Drawing.Size(556, 209)
        Me.ListViewMail.TabIndex = 1
        Me.ListViewMail.UseCompatibleStateImageBehavior = False
        Me.ListViewMail.View = System.Windows.Forms.View.Details
        '
        'colFrom
        '
        Me.colFrom.Text = "From"
        Me.colFrom.Width = 180
        '
        'colSubject
        '
        Me.colSubject.Text = "Subject"
        Me.colSubject.Width = 200
        '
        'colDate
        '
        Me.colDate.Text = "Date"
        Me.colDate.Width = 180
        '
        'ButtonDelete
        '
        Me.ButtonDelete.Location = New System.Drawing.Point(761, 233)
        Me.ButtonDelete.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.ButtonDelete.Name = "ButtonDelete"
        Me.ButtonDelete.Size = New System.Drawing.Size(84, 30)
        Me.ButtonDelete.TabIndex = 3
        Me.ButtonDelete.Text = "Delete"
        '
        'LabelTotal
        '
        Me.LabelTotal.AutoSize = True
        Me.LabelTotal.Location = New System.Drawing.Point(299, 240)
        Me.LabelTotal.Name = "LabelTotal"
        Me.LabelTotal.Size = New System.Drawing.Size(0, 15)
        Me.LabelTotal.TabIndex = 2
        '
        'textStatus
        '
        Me.textStatus.Location = New System.Drawing.Point(0, 504)
        Me.textStatus.Name = "textStatus"
        Me.textStatus.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.textStatus.Size = New System.Drawing.Size(857, 26)
        Me.textStatus.TabIndex = 5
        '
        'WebMail
        '
        Me.WebMail.Location = New System.Drawing.Point(289, 267)
        Me.WebMail.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.WebMail.MinimumSize = New System.Drawing.Size(23, 25)
        Me.WebMail.Name = "WebMail"
        Me.WebMail.Size = New System.Drawing.Size(556, 230)
        Me.WebMail.TabIndex = 4
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(7.0!, 15.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(857, 530)
        Me.Controls.Add(Me.WebMail)
        Me.Controls.Add(Me.textStatus)
        Me.Controls.Add(Me.LabelTotal)
        Me.Controls.Add(Me.ButtonDelete)
        Me.Controls.Add(Me.ListViewMail)
        Me.Controls.Add(Me.GroupBoxServer)
        Me.Font = New System.Drawing.Font("Segoe UI", 9.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.GroupBoxServer.ResumeLayout(False)
        Me.GroupBoxServer.PerformLayout()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents GroupBoxServer As  System.Windows.Forms.GroupBox
    Friend WithEvents label1 As  System.Windows.Forms.Label
    Friend WithEvents label2 As  System.Windows.Forms.Label
    Friend WithEvents label3 As  System.Windows.Forms.Label
    Friend WithEvents textServer As  System.Windows.Forms.TextBox
    Friend WithEvents textUser As  System.Windows.Forms.TextBox
    Friend WithEvents textPassword As  System.Windows.Forms.TextBox
    Friend WithEvents label4 As  System.Windows.Forms.Label
    Friend WithEvents ComboBoxAuthType As  System.Windows.Forms.ComboBox
    Friend WithEvents label5 As  System.Windows.Forms.Label
    Friend WithEvents ComboBoxProtocol As  System.Windows.Forms.ComboBox
    Friend WithEvents chkLeaveCopy As  System.Windows.Forms.CheckBox
    Friend WithEvents btnStart As  System.Windows.Forms.Button
    Friend WithEvents btnCancel As  System.Windows.Forms.Button
    Friend WithEvents pgBar As  System.Windows.Forms.ProgressBar
    Friend WithEvents chkSSL As  System.Windows.Forms.CheckBox
    Friend WithEvents ListViewMail As  System.Windows.Forms.ListView
    Friend WithEvents colFrom As  System.Windows.Forms.ColumnHeader
    Friend WithEvents colSubject As  System.Windows.Forms.ColumnHeader
    Friend WithEvents colDate As  System.Windows.Forms.ColumnHeader
    Friend WithEvents ButtonDelete As  System.Windows.Forms.Button
    Friend WithEvents LabelTotal As  System.Windows.Forms.Label
    Friend WithEvents textStatus As  System.Windows.Forms.StatusBar
    Friend WithEvents WebMail As  System.Windows.Forms.WebBrowser
    Friend WithEvents label6 As  System.Windows.Forms.Label
    Friend WithEvents chkNewOnly As  System.Windows.Forms.CheckBox
    Friend WithEvents ComboBoxDateRange As  System.Windows.Forms.ComboBox

End Class
