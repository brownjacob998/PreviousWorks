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
    <System.Diagnostics.DebuggerStepThrough()>
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Me.TreeViewFolder = New System.Windows.Forms.TreeView()
        Me.contextMenuFolder = New System.Windows.Forms.ContextMenuStrip(Me.components)
        Me.refreshFoldersToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.refreshMailsToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.addFolderToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.deleteFolderToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.renameFolderToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.ListViewMail = New System.Windows.Forms.ListView()
        Me.colFrom = CType(New System.Windows.Forms.ColumnHeader(), System.Windows.Forms.ColumnHeader)
        Me.colSubject = CType(New System.Windows.Forms.ColumnHeader(), System.Windows.Forms.ColumnHeader)
        Me.colDate = CType(New System.Windows.Forms.ColumnHeader(), System.Windows.Forms.ColumnHeader)
        Me.btnDelete = New System.Windows.Forms.Button()
        Me.btnUndelete = New System.Windows.Forms.Button()
        Me.btnUnread = New System.Windows.Forms.Button()
        Me.btnExpunge = New System.Windows.Forms.Button()
        Me.btnMove = New System.Windows.Forms.Button()
        Me.pgBar = New System.Windows.Forms.ProgressBar()
        Me.webMail = New System.Windows.Forms.WebBrowser()
        Me.textStatus = New System.Windows.Forms.StatusBar()
        Me.GroupBoxServer = New System.Windows.Forms.GroupBox()
        Me.ComboBoxDateRange = New System.Windows.Forms.ComboBox()
        Me.btnQuit = New System.Windows.Forms.Button()
        Me.label1 = New System.Windows.Forms.Label()
        Me.btnCancel = New System.Windows.Forms.Button()
        Me.btnStart = New System.Windows.Forms.Button()
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
        Me.label6 = New System.Windows.Forms.Label()
        Me.btnUpload = New System.Windows.Forms.Button()
        Me.btnCopy = New System.Windows.Forms.Button()
        Me.openFileDialog1 = New System.Windows.Forms.OpenFileDialog()
        Me.contextMenuFolder.SuspendLayout()
        Me.GroupBoxServer.SuspendLayout()
        Me.SuspendLayout()
        '
        'TreeViewFolder
        '
        Me.TreeViewFolder.ContextMenuStrip = Me.contextMenuFolder
        Me.TreeViewFolder.HideSelection = False
        Me.TreeViewFolder.Location = New System.Drawing.Point(296, 15)
        Me.TreeViewFolder.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.TreeViewFolder.Name = "TreeViewFolder"
        Me.TreeViewFolder.Size = New System.Drawing.Size(183, 453)
        Me.TreeViewFolder.TabIndex = 1
        '
        'contextMenuFolder
        '
        Me.contextMenuFolder.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.refreshFoldersToolStripMenuItem, Me.refreshMailsToolStripMenuItem, Me.addFolderToolStripMenuItem, Me.deleteFolderToolStripMenuItem, Me.renameFolderToolStripMenuItem})
        Me.contextMenuFolder.Name = "contextMenuFolder"
        Me.contextMenuFolder.Size = New System.Drawing.Size(155, 114)
        '
        'refreshFoldersToolStripMenuItem
        '
        Me.refreshFoldersToolStripMenuItem.Name = "refreshFoldersToolStripMenuItem"
        Me.refreshFoldersToolStripMenuItem.Size = New System.Drawing.Size(154, 22)
        Me.refreshFoldersToolStripMenuItem.Text = "Refresh Folders"
        '
        'refreshMailsToolStripMenuItem
        '
        Me.refreshMailsToolStripMenuItem.Name = "refreshMailsToolStripMenuItem"
        Me.refreshMailsToolStripMenuItem.Size = New System.Drawing.Size(154, 22)
        Me.refreshMailsToolStripMenuItem.Text = "Refresh Mails"
        '
        'addFolderToolStripMenuItem
        '
        Me.addFolderToolStripMenuItem.Name = "addFolderToolStripMenuItem"
        Me.addFolderToolStripMenuItem.Size = New System.Drawing.Size(154, 22)
        Me.addFolderToolStripMenuItem.Text = "Add Folder"
        '
        'deleteFolderToolStripMenuItem
        '
        Me.deleteFolderToolStripMenuItem.Name = "deleteFolderToolStripMenuItem"
        Me.deleteFolderToolStripMenuItem.Size = New System.Drawing.Size(154, 22)
        Me.deleteFolderToolStripMenuItem.Text = "Delete Folder"
        '
        'renameFolderToolStripMenuItem
        '
        Me.renameFolderToolStripMenuItem.Name = "renameFolderToolStripMenuItem"
        Me.renameFolderToolStripMenuItem.Size = New System.Drawing.Size(154, 22)
        Me.renameFolderToolStripMenuItem.Text = "Rename Folder"
        '
        'ListViewMail
        '
        Me.ListViewMail.Columns.AddRange(New System.Windows.Forms.ColumnHeader() {Me.colFrom, Me.colSubject, Me.colDate})
        Me.ListViewMail.FullRowSelect = True
        Me.ListViewMail.HideSelection = False
        Me.ListViewMail.Location = New System.Drawing.Point(498, 15)
        Me.ListViewMail.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.ListViewMail.Name = "ListViewMail"
        Me.ListViewMail.Size = New System.Drawing.Size(520, 185)
        Me.ListViewMail.TabIndex = 2
        Me.ListViewMail.UseCompatibleStateImageBehavior = False
        Me.ListViewMail.View = System.Windows.Forms.View.Details
        '
        'colFrom
        '
        Me.colFrom.Text = "From"
        Me.colFrom.Width = 150
        '
        'colSubject
        '
        Me.colSubject.Text = "Subject"
        Me.colSubject.Width = 200
        '
        'colDate
        '
        Me.colDate.Text = "Date"
        Me.colDate.Width = 100
        '
        'btnDelete
        '
        Me.btnDelete.Enabled = False
        Me.btnDelete.Location = New System.Drawing.Point(498, 210)
        Me.btnDelete.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.btnDelete.Name = "btnDelete"
        Me.btnDelete.Size = New System.Drawing.Size(65, 28)
        Me.btnDelete.TabIndex = 3
        Me.btnDelete.Text = "Delete Message"
        '
        'btnUndelete
        '
        Me.btnUndelete.Enabled = False
        Me.btnUndelete.Location = New System.Drawing.Point(570, 210)
        Me.btnUndelete.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.btnUndelete.Name = "btnUndelete"
        Me.btnUndelete.Size = New System.Drawing.Size(77, 28)
        Me.btnUndelete.TabIndex = 4
        Me.btnUndelete.Text = "Undelete"
        '
        'btnUnread
        '
        Me.btnUnread.Enabled = False
        Me.btnUnread.Location = New System.Drawing.Point(654, 210)
        Me.btnUnread.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.btnUnread.Name = "btnUnread"
        Me.btnUnread.Size = New System.Drawing.Size(65, 28)
        Me.btnUnread.TabIndex = 5
        Me.btnUnread.Text = "Unread"
        '
        'btnExpunge
        '
        Me.btnExpunge.Enabled = False
        Me.btnExpunge.Location = New System.Drawing.Point(870, 210)
        Me.btnExpunge.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.btnExpunge.Name = "btnExpunge"
        Me.btnExpunge.Size = New System.Drawing.Size(65, 28)
        Me.btnExpunge.TabIndex = 8
        Me.btnExpunge.Text = "Expunge"
        '
        'btnMove
        '
        Me.btnMove.Enabled = False
        Me.btnMove.Location = New System.Drawing.Point(798, 210)
        Me.btnMove.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.btnMove.Name = "btnMove"
        Me.btnMove.Size = New System.Drawing.Size(65, 28)
        Me.btnMove.TabIndex = 7
        Me.btnMove.Text = "Move"
        '
        'pgBar
        '
        Me.pgBar.Location = New System.Drawing.Point(497, 456)
        Me.pgBar.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.pgBar.Name = "pgBar"
        Me.pgBar.Size = New System.Drawing.Size(519, 12)
        Me.pgBar.TabIndex = 11
        '
        'webMail
        '
        Me.webMail.Location = New System.Drawing.Point(498, 246)
        Me.webMail.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.webMail.MinimumSize = New System.Drawing.Size(23, 25)
        Me.webMail.Name = "webMail"
        Me.webMail.Size = New System.Drawing.Size(520, 199)
        Me.webMail.TabIndex = 10
        '
        'textStatus
        '
        Me.textStatus.Location = New System.Drawing.Point(0, 473)
        Me.textStatus.Name = "textStatus"
        Me.textStatus.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.textStatus.Size = New System.Drawing.Size(1028, 26)
        Me.textStatus.TabIndex = 12
        '
        'GroupBoxServer
        '
        Me.GroupBoxServer.Controls.Add(Me.ComboBoxDateRange)
        Me.GroupBoxServer.Controls.Add(Me.btnQuit)
        Me.GroupBoxServer.Controls.Add(Me.label1)
        Me.GroupBoxServer.Controls.Add(Me.btnCancel)
        Me.GroupBoxServer.Controls.Add(Me.btnStart)
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
        Me.GroupBoxServer.Controls.Add(Me.label6)
        Me.GroupBoxServer.Location = New System.Drawing.Point(14, 11)
        Me.GroupBoxServer.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.GroupBoxServer.Name = "GroupBoxServer"
        Me.GroupBoxServer.Padding = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.GroupBoxServer.Size = New System.Drawing.Size(266, 434)
        Me.GroupBoxServer.TabIndex = 0
        Me.GroupBoxServer.TabStop = False
        Me.GroupBoxServer.Text = "Account Information"
        '
        'ComboBoxDateRange
        '
        Me.ComboBoxDateRange.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.ComboBoxDateRange.FormattingEnabled = True
        Me.ComboBoxDateRange.Location = New System.Drawing.Point(14, 275)
        Me.ComboBoxDateRange.Name = "ComboBoxDateRange"
        Me.ComboBoxDateRange.Size = New System.Drawing.Size(237, 23)
        Me.ComboBoxDateRange.TabIndex = 11
        '
        'btnQuit
        '
        Me.btnQuit.Enabled = False
        Me.btnQuit.Location = New System.Drawing.Point(14, 351)
        Me.btnQuit.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.btnQuit.Name = "btnQuit"
        Me.btnQuit.Size = New System.Drawing.Size(243, 30)
        Me.btnQuit.TabIndex = 14
        Me.btnQuit.Text = "Quit"
        Me.btnQuit.UseVisualStyleBackColor = True
        '
        'label1
        '
        Me.label1.AutoSize = True
        Me.label1.Location = New System.Drawing.Point(9, 340)
        Me.label1.Name = "label1"
        Me.label1.Size = New System.Drawing.Size(0, 15)
        Me.label1.TabIndex = 13
        '
        'btnCancel
        '
        Me.btnCancel.Enabled = False
        Me.btnCancel.Location = New System.Drawing.Point(14, 387)
        Me.btnCancel.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.btnCancel.Name = "btnCancel"
        Me.btnCancel.Size = New System.Drawing.Size(243, 30)
        Me.btnCancel.TabIndex = 15
        Me.btnCancel.Text = "Cancel Task"
        '
        'btnStart
        '
        Me.btnStart.Location = New System.Drawing.Point(13, 314)
        Me.btnStart.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.btnStart.Name = "btnStart"
        Me.btnStart.Size = New System.Drawing.Size(243, 30)
        Me.btnStart.TabIndex = 12
        Me.btnStart.Text = "Start"
        '
        'ComboBoxProtocol
        '
        Me.ComboBoxProtocol.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.ComboBoxProtocol.Location = New System.Drawing.Point(93, 226)
        Me.ComboBoxProtocol.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.ComboBoxProtocol.Name = "ComboBoxProtocol"
        Me.ComboBoxProtocol.Size = New System.Drawing.Size(158, 23)
        Me.ComboBoxProtocol.TabIndex = 10
        '
        'label5
        '
        Me.label5.AutoSize = True
        Me.label5.Location = New System.Drawing.Point(9, 229)
        Me.label5.Name = "label5"
        Me.label5.Size = New System.Drawing.Size(52, 15)
        Me.label5.TabIndex = 9
        Me.label5.Text = "Protocol"
        '
        'ComboBoxAuthType
        '
        Me.ComboBoxAuthType.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.ComboBoxAuthType.Location = New System.Drawing.Point(93, 186)
        Me.ComboBoxAuthType.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.ComboBoxAuthType.Name = "ComboBoxAuthType"
        Me.ComboBoxAuthType.Size = New System.Drawing.Size(158, 23)
        Me.ComboBoxAuthType.TabIndex = 8
        '
        'label4
        '
        Me.label4.AutoSize = True
        Me.label4.Location = New System.Drawing.Point(9, 189)
        Me.label4.Name = "label4"
        Me.label4.Size = New System.Drawing.Size(61, 15)
        Me.label4.TabIndex = 7
        Me.label4.Text = "Auth Type"
        '
        'chkSSL
        '
        Me.chkSSL.Checked = True
        Me.chkSSL.CheckState = System.Windows.Forms.CheckState.Checked
        Me.chkSSL.Location = New System.Drawing.Point(13, 152)
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
        'label6
        '
        Me.label6.AutoSize = True
        Me.label6.Location = New System.Drawing.Point(9, 30)
        Me.label6.Name = "label6"
        Me.label6.Size = New System.Drawing.Size(39, 15)
        Me.label6.TabIndex = 0
        Me.label6.Text = "Server"
        '
        'btnUpload
        '
        Me.btnUpload.Enabled = False
        Me.btnUpload.Location = New System.Drawing.Point(942, 210)
        Me.btnUpload.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.btnUpload.Name = "btnUpload"
        Me.btnUpload.Size = New System.Drawing.Size(65, 28)
        Me.btnUpload.TabIndex = 9
        Me.btnUpload.Text = "Upload"
        Me.btnUpload.UseVisualStyleBackColor = True
        '
        'btnCopy
        '
        Me.btnCopy.Enabled = False
        Me.btnCopy.Location = New System.Drawing.Point(726, 210)
        Me.btnCopy.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.btnCopy.Name = "btnCopy"
        Me.btnCopy.Size = New System.Drawing.Size(65, 28)
        Me.btnCopy.TabIndex = 6
        Me.btnCopy.Text = "Copy"
        Me.btnCopy.UseVisualStyleBackColor = True
        '
        'openFileDialog1
        '
        Me.openFileDialog1.FileName = "openFileDialog1"
        Me.openFileDialog1.Filter = "Email File | *.EML"
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(7.0!, 15.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(1028, 499)
        Me.Controls.Add(Me.btnCopy)
        Me.Controls.Add(Me.btnUpload)
        Me.Controls.Add(Me.GroupBoxServer)
        Me.Controls.Add(Me.textStatus)
        Me.Controls.Add(Me.webMail)
        Me.Controls.Add(Me.pgBar)
        Me.Controls.Add(Me.ListViewMail)
        Me.Controls.Add(Me.btnMove)
        Me.Controls.Add(Me.TreeViewFolder)
        Me.Controls.Add(Me.btnExpunge)
        Me.Controls.Add(Me.btnUnread)
        Me.Controls.Add(Me.btnDelete)
        Me.Controls.Add(Me.btnUndelete)
        Me.Font = New System.Drawing.Font("Segoe UI", 9.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.contextMenuFolder.ResumeLayout(False)
        Me.GroupBoxServer.ResumeLayout(False)
        Me.GroupBoxServer.PerformLayout()
        Me.ResumeLayout(False)

    End Sub

    Friend WithEvents TreeViewFolder As System.Windows.Forms.TreeView
    Friend WithEvents ListViewMail As System.Windows.Forms.ListView
    Friend WithEvents colFrom As System.Windows.Forms.ColumnHeader
    Friend WithEvents colSubject As System.Windows.Forms.ColumnHeader
    Friend WithEvents colDate As System.Windows.Forms.ColumnHeader
    Friend WithEvents btnDelete As System.Windows.Forms.Button
    Friend WithEvents btnUndelete As System.Windows.Forms.Button
    Friend WithEvents btnUnread As System.Windows.Forms.Button
    Friend WithEvents btnExpunge As System.Windows.Forms.Button
    Friend WithEvents btnMove As System.Windows.Forms.Button
    Friend WithEvents pgBar As System.Windows.Forms.ProgressBar
    Friend WithEvents textStatus As System.Windows.Forms.StatusBar
    Friend WithEvents webMail As System.Windows.Forms.WebBrowser
    Friend WithEvents GroupBoxServer As System.Windows.Forms.GroupBox
    Friend WithEvents label1 As System.Windows.Forms.Label
    Friend WithEvents btnCancel As System.Windows.Forms.Button
    Friend WithEvents btnStart As System.Windows.Forms.Button
    Friend WithEvents ComboBoxProtocol As System.Windows.Forms.ComboBox
    Friend WithEvents label5 As System.Windows.Forms.Label
    Friend WithEvents ComboBoxAuthType As System.Windows.Forms.ComboBox
    Friend WithEvents label4 As System.Windows.Forms.Label
    Friend WithEvents chkSSL As System.Windows.Forms.CheckBox
    Friend WithEvents textPassword As System.Windows.Forms.TextBox
    Friend WithEvents textUser As System.Windows.Forms.TextBox
    Friend WithEvents textServer As System.Windows.Forms.TextBox
    Friend WithEvents label3 As System.Windows.Forms.Label
    Friend WithEvents label2 As System.Windows.Forms.Label
    Friend WithEvents label6 As System.Windows.Forms.Label
    Friend WithEvents btnQuit As System.Windows.Forms.Button
    Friend WithEvents contextMenuFolder As System.Windows.Forms.ContextMenuStrip
    Friend WithEvents refreshFoldersToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents refreshMailsToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents addFolderToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents deleteFolderToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents renameFolderToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents btnUpload As System.Windows.Forms.Button
    Friend WithEvents btnCopy As System.Windows.Forms.Button
    Friend WithEvents openFileDialog1 As System.Windows.Forms.OpenFileDialog
    Friend WithEvents ComboBoxDateRange As System.Windows.Forms.ComboBox

End Class
