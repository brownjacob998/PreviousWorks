<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class FormOauth
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
        Me.OauthBrowser = New System.Windows.Forms.WebBrowser()
        Me.SuspendLayout()
        '
        'OauthBrowser
        '
        Me.OauthBrowser.Dock = System.Windows.Forms.DockStyle.Fill
        Me.OauthBrowser.Location = New System.Drawing.Point(0, 0)
        Me.OauthBrowser.Margin = New System.Windows.Forms.Padding(4)
        Me.OauthBrowser.MinimumSize = New System.Drawing.Size(27, 22)
        Me.OauthBrowser.Name = "OauthBrowser"
        Me.OauthBrowser.ScriptErrorsSuppressed = True
        Me.OauthBrowser.Size = New System.Drawing.Size(799, 606)
        Me.OauthBrowser.TabIndex = 0
        '
        'FormOauth
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(8.0!, 15.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(799, 606)
        Me.Controls.Add(Me.OauthBrowser)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog
        Me.Margin = New System.Windows.Forms.Padding(4)
        Me.MaximizeBox = False
        Me.MinimizeBox = False
        Me.Name = "FormOauth"
        Me.Text = "Google Login"
        Me.ResumeLayout(False)

    End Sub

    Friend WithEvents OauthBrowser As System.Windows.Forms.WebBrowser
End Class
