<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Main
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
        Me.lstEmail = New System.Windows.Forms.ListBox()
        Me.btnRetrieve = New System.Windows.Forms.Button()
        Me.btnDelete = New System.Windows.Forms.Button()
        Me.btnSend = New System.Windows.Forms.Button()
        Me.btndebug = New System.Windows.Forms.Button()
        Me.btnClose = New System.Windows.Forms.Button()
        Me.btnRefresh = New System.Windows.Forms.Button()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.SuspendLayout()
        '
        'lstEmail
        '
        Me.lstEmail.FormattingEnabled = True
        Me.lstEmail.ItemHeight = 16
        Me.lstEmail.Location = New System.Drawing.Point(261, 161)
        Me.lstEmail.Margin = New System.Windows.Forms.Padding(4)
        Me.lstEmail.Name = "lstEmail"
        Me.lstEmail.Size = New System.Drawing.Size(709, 196)
        Me.lstEmail.TabIndex = 0
        '
        'btnRetrieve
        '
        Me.btnRetrieve.Location = New System.Drawing.Point(273, 366)
        Me.btnRetrieve.Margin = New System.Windows.Forms.Padding(4)
        Me.btnRetrieve.Name = "btnRetrieve"
        Me.btnRetrieve.Size = New System.Drawing.Size(100, 28)
        Me.btnRetrieve.TabIndex = 1
        Me.btnRetrieve.Text = "View"
        Me.btnRetrieve.UseVisualStyleBackColor = True
        '
        'btnDelete
        '
        Me.btnDelete.Location = New System.Drawing.Point(397, 366)
        Me.btnDelete.Margin = New System.Windows.Forms.Padding(4)
        Me.btnDelete.Name = "btnDelete"
        Me.btnDelete.Size = New System.Drawing.Size(100, 28)
        Me.btnDelete.TabIndex = 2
        Me.btnDelete.Text = "Delete"
        Me.btnDelete.UseVisualStyleBackColor = True
        '
        'btnSend
        '
        Me.btnSend.Location = New System.Drawing.Point(872, 366)
        Me.btnSend.Margin = New System.Windows.Forms.Padding(4)
        Me.btnSend.Name = "btnSend"
        Me.btnSend.Size = New System.Drawing.Size(100, 28)
        Me.btnSend.TabIndex = 3
        Me.btnSend.Text = "Compose"
        Me.btnSend.UseVisualStyleBackColor = True
        '
        'btndebug
        '
        Me.btndebug.Location = New System.Drawing.Point(273, 425)
        Me.btndebug.Margin = New System.Windows.Forms.Padding(4)
        Me.btndebug.Name = "btndebug"
        Me.btndebug.Size = New System.Drawing.Size(100, 28)
        Me.btndebug.TabIndex = 4
        Me.btndebug.Text = "Debug"
        Me.btndebug.UseVisualStyleBackColor = True
        '
        'btnClose
        '
        Me.btnClose.Location = New System.Drawing.Point(872, 425)
        Me.btnClose.Margin = New System.Windows.Forms.Padding(4)
        Me.btnClose.Name = "btnClose"
        Me.btnClose.Size = New System.Drawing.Size(100, 28)
        Me.btnClose.TabIndex = 5
        Me.btnClose.Text = "Close"
        Me.btnClose.UseVisualStyleBackColor = True
        '
        'btnRefresh
        '
        Me.btnRefresh.Location = New System.Drawing.Point(519, 366)
        Me.btnRefresh.Margin = New System.Windows.Forms.Padding(4)
        Me.btnRefresh.Name = "btnRefresh"
        Me.btnRefresh.Size = New System.Drawing.Size(100, 28)
        Me.btnRefresh.TabIndex = 6
        Me.btnRefresh.Text = "Refresh"
        Me.btnRefresh.UseVisualStyleBackColor = True
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(258, 140)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(41, 17)
        Me.Label1.TabIndex = 7
        Me.Label1.Text = "Inbox"
        '
        'Main
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(8.0!, 16.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(1067, 554)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.btnRefresh)
        Me.Controls.Add(Me.btnClose)
        Me.Controls.Add(Me.btndebug)
        Me.Controls.Add(Me.btnSend)
        Me.Controls.Add(Me.btnDelete)
        Me.Controls.Add(Me.btnRetrieve)
        Me.Controls.Add(Me.lstEmail)
        Me.Margin = New System.Windows.Forms.Padding(4)
        Me.Name = "Main"
        Me.Text = "Main"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents lstEmail As ListBox
    Friend WithEvents btnRetrieve As Button
    Friend WithEvents btnDelete As Button
    Friend WithEvents btnSend As Button
    Friend WithEvents btndebug As Button
    Friend WithEvents btnClose As Button
    Friend WithEvents btnRefresh As Button
    Friend WithEvents Label1 As Label
End Class
