<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class ViewEmail
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
        Me.txtFrom = New System.Windows.Forms.TextBox()
        Me.txtSubject = New System.Windows.Forms.TextBox()
        Me.txtContent = New System.Windows.Forms.TextBox()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.btnBack = New System.Windows.Forms.Button()
        Me.btnReply = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'txtFrom
        '
        Me.txtFrom.Location = New System.Drawing.Point(128, 43)
        Me.txtFrom.Name = "txtFrom"
        Me.txtFrom.ReadOnly = True
        Me.txtFrom.Size = New System.Drawing.Size(470, 20)
        Me.txtFrom.TabIndex = 0
        '
        'txtSubject
        '
        Me.txtSubject.Location = New System.Drawing.Point(128, 69)
        Me.txtSubject.Name = "txtSubject"
        Me.txtSubject.ReadOnly = True
        Me.txtSubject.Size = New System.Drawing.Size(470, 20)
        Me.txtSubject.TabIndex = 1
        '
        'txtContent
        '
        Me.txtContent.Location = New System.Drawing.Point(128, 95)
        Me.txtContent.Multiline = True
        Me.txtContent.Name = "txtContent"
        Me.txtContent.ReadOnly = True
        Me.txtContent.Size = New System.Drawing.Size(470, 220)
        Me.txtContent.TabIndex = 2
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(92, 46)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(30, 13)
        Me.Label1.TabIndex = 3
        Me.Label1.Text = "From"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(83, 72)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(43, 13)
        Me.Label2.TabIndex = 4
        Me.Label2.Text = "Subject"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(78, 98)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(44, 13)
        Me.Label3.TabIndex = 5
        Me.Label3.Text = "Content"
        '
        'btnBack
        '
        Me.btnBack.Location = New System.Drawing.Point(523, 321)
        Me.btnBack.Name = "btnBack"
        Me.btnBack.Size = New System.Drawing.Size(75, 23)
        Me.btnBack.TabIndex = 6
        Me.btnBack.Text = "Back"
        Me.btnBack.UseVisualStyleBackColor = True
        '
        'btnReply
        '
        Me.btnReply.Location = New System.Drawing.Point(128, 322)
        Me.btnReply.Name = "btnReply"
        Me.btnReply.Size = New System.Drawing.Size(75, 23)
        Me.btnReply.TabIndex = 7
        Me.btnReply.Text = "Reply"
        Me.btnReply.UseVisualStyleBackColor = True
        '
        'ViewEmail
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(832, 450)
        Me.Controls.Add(Me.btnReply)
        Me.Controls.Add(Me.btnBack)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.txtContent)
        Me.Controls.Add(Me.txtSubject)
        Me.Controls.Add(Me.txtFrom)
        Me.Name = "ViewEmail"
        Me.Text = "ViewEmail"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents txtFrom As TextBox
    Friend WithEvents txtSubject As TextBox
    Friend WithEvents txtContent As TextBox
    Friend WithEvents Label1 As Label
    Friend WithEvents Label2 As Label
    Friend WithEvents Label3 As Label
    Friend WithEvents btnBack As Button
    Friend WithEvents btnReply As Button
End Class
