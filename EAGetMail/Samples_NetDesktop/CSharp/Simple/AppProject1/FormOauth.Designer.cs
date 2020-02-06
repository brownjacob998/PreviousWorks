namespace AppProject1
{
    partial class FormOauth
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.OauthBrowser = new System.Windows.Forms.WebBrowser();
            this.SuspendLayout();
            // 
            // OauthBrowser
            // 
            this.OauthBrowser.Dock = System.Windows.Forms.DockStyle.Fill;
            this.OauthBrowser.Location = new System.Drawing.Point(0, 0);
            this.OauthBrowser.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.OauthBrowser.MinimumSize = new System.Drawing.Size(27, 22);
            this.OauthBrowser.Name = "OauthBrowser";
            this.OauthBrowser.ScriptErrorsSuppressed = true;
            this.OauthBrowser.Size = new System.Drawing.Size(799, 606);
            this.OauthBrowser.TabIndex = 0;
            this.OauthBrowser.DocumentCompleted += new System.Windows.Forms.WebBrowserDocumentCompletedEventHandler(this.OauthBrowser_DocumentCompleted);
            // 
            // FormOauth
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(799, 606);
            this.Controls.Add(this.OauthBrowser);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "FormOauth";
            this.Text = "Google Login";
            this.Load += new System.EventHandler(this.FormOauth_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.WebBrowser OauthBrowser;
    }
}