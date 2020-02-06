namespace AppProject1
{
    partial class Form1
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
            this.GroupBoxServer = new System.Windows.Forms.GroupBox();
            this.ComboBoxDateRange = new System.Windows.Forms.ComboBox();
            this.chkNewOnly = new System.Windows.Forms.CheckBox();
            this.label6 = new System.Windows.Forms.Label();
            this.pgBar = new System.Windows.Forms.ProgressBar();
            this.btnCancel = new System.Windows.Forms.Button();
            this.btnStart = new System.Windows.Forms.Button();
            this.chkLeaveCopy = new System.Windows.Forms.CheckBox();
            this.ComboBoxProtocol = new System.Windows.Forms.ComboBox();
            this.label5 = new System.Windows.Forms.Label();
            this.ComboBoxAuthType = new System.Windows.Forms.ComboBox();
            this.label4 = new System.Windows.Forms.Label();
            this.chkSSL = new System.Windows.Forms.CheckBox();
            this.textPassword = new System.Windows.Forms.TextBox();
            this.textUser = new System.Windows.Forms.TextBox();
            this.textServer = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.ListViewMail = new System.Windows.Forms.ListView();
            this.colFrom = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colSubject = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colDate = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.ButtonDelete = new System.Windows.Forms.Button();
            this.LabelTotal = new System.Windows.Forms.Label();
            this.textStatus = new System.Windows.Forms.StatusBar();
            this.WebMail = new System.Windows.Forms.WebBrowser();
            this.GroupBoxServer.SuspendLayout();
            this.SuspendLayout();
            // 
            // GroupBoxServer
            // 
            this.GroupBoxServer.Controls.Add(this.ComboBoxDateRange);
            this.GroupBoxServer.Controls.Add(this.chkNewOnly);
            this.GroupBoxServer.Controls.Add(this.label6);
            this.GroupBoxServer.Controls.Add(this.pgBar);
            this.GroupBoxServer.Controls.Add(this.btnCancel);
            this.GroupBoxServer.Controls.Add(this.btnStart);
            this.GroupBoxServer.Controls.Add(this.chkLeaveCopy);
            this.GroupBoxServer.Controls.Add(this.ComboBoxProtocol);
            this.GroupBoxServer.Controls.Add(this.label5);
            this.GroupBoxServer.Controls.Add(this.ComboBoxAuthType);
            this.GroupBoxServer.Controls.Add(this.label4);
            this.GroupBoxServer.Controls.Add(this.chkSSL);
            this.GroupBoxServer.Controls.Add(this.textPassword);
            this.GroupBoxServer.Controls.Add(this.textUser);
            this.GroupBoxServer.Controls.Add(this.textServer);
            this.GroupBoxServer.Controls.Add(this.label3);
            this.GroupBoxServer.Controls.Add(this.label2);
            this.GroupBoxServer.Controls.Add(this.label1);
            this.GroupBoxServer.Location = new System.Drawing.Point(9, 10);
            this.GroupBoxServer.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.GroupBoxServer.Name = "GroupBoxServer";
            this.GroupBoxServer.Padding = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.GroupBoxServer.Size = new System.Drawing.Size(265, 487);
            this.GroupBoxServer.TabIndex = 0;
            this.GroupBoxServer.TabStop = false;
            this.GroupBoxServer.Text = "Account Information";
            // 
            // ComboBoxDateRange
            // 
            this.ComboBoxDateRange.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.ComboBoxDateRange.FormattingEnabled = true;
            this.ComboBoxDateRange.Location = new System.Drawing.Point(9, 395);
            this.ComboBoxDateRange.Name = "ComboBoxDateRange";
            this.ComboBoxDateRange.Size = new System.Drawing.Size(239, 23);
            this.ComboBoxDateRange.TabIndex = 14;
            // 
            // chkNewOnly
            // 
            this.chkNewOnly.Location = new System.Drawing.Point(9, 342);
            this.chkNewOnly.Name = "chkNewOnly";
            this.chkNewOnly.Size = new System.Drawing.Size(215, 38);
            this.chkNewOnly.TabIndex = 13;
            this.chkNewOnly.Text = "Retrieve new email only (IMAP, EWS, WebDAV)";
            this.chkNewOnly.UseVisualStyleBackColor = true;
            // 
            // label6
            // 
            this.label6.ForeColor = System.Drawing.SystemColors.HotTrack;
            this.label6.Location = new System.Drawing.Point(9, 285);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(239, 53);
            this.label6.TabIndex = 12;
            this.label6.Text = "Warning: if \"leave a copy of message on server\" is not checked,  the emails on th" +
    "e server will be deleted !";
            // 
            // pgBar
            // 
            this.pgBar.Location = new System.Drawing.Point(9, 468);
            this.pgBar.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.pgBar.Name = "pgBar";
            this.pgBar.Size = new System.Drawing.Size(243, 10);
            this.pgBar.TabIndex = 17;
            // 
            // btnCancel
            // 
            this.btnCancel.Enabled = false;
            this.btnCancel.Location = new System.Drawing.Point(133, 429);
            this.btnCancel.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(118, 30);
            this.btnCancel.TabIndex = 16;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
            // 
            // btnStart
            // 
            this.btnStart.Location = new System.Drawing.Point(9, 429);
            this.btnStart.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(118, 30);
            this.btnStart.TabIndex = 15;
            this.btnStart.Text = "Start";
            this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
            // 
            // chkLeaveCopy
            // 
            this.chkLeaveCopy.Checked = true;
            this.chkLeaveCopy.CheckState = System.Windows.Forms.CheckState.Checked;
            this.chkLeaveCopy.Location = new System.Drawing.Point(9, 257);
            this.chkLeaveCopy.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.chkLeaveCopy.Name = "chkLeaveCopy";
            this.chkLeaveCopy.Size = new System.Drawing.Size(243, 20);
            this.chkLeaveCopy.TabIndex = 11;
            this.chkLeaveCopy.Text = "Leave a copy of message on server";
            // 
            // ComboBoxProtocol
            // 
            this.ComboBoxProtocol.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.ComboBoxProtocol.Location = new System.Drawing.Point(93, 217);
            this.ComboBoxProtocol.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.ComboBoxProtocol.Name = "ComboBoxProtocol";
            this.ComboBoxProtocol.Size = new System.Drawing.Size(158, 23);
            this.ComboBoxProtocol.TabIndex = 10;
            this.ComboBoxProtocol.SelectedIndexChanged += new System.EventHandler(this.ComboBoxProtocol_SelectedIndexChanged);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(9, 219);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(52, 15);
            this.label5.TabIndex = 9;
            this.label5.Text = "Protocol";
            // 
            // ComboBoxAuthType
            // 
            this.ComboBoxAuthType.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.ComboBoxAuthType.Location = new System.Drawing.Point(93, 177);
            this.ComboBoxAuthType.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.ComboBoxAuthType.Name = "ComboBoxAuthType";
            this.ComboBoxAuthType.Size = new System.Drawing.Size(158, 23);
            this.ComboBoxAuthType.TabIndex = 8;
            this.ComboBoxAuthType.SelectedIndexChanged += new System.EventHandler(this.ComboBoxAuthType_SelectedIndexChanged);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(9, 179);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(61, 15);
            this.label4.TabIndex = 7;
            this.label4.Text = "Auth Type";
            // 
            // chkSSL
            // 
            this.chkSSL.Checked = true;
            this.chkSSL.CheckState = System.Windows.Forms.CheckState.Checked;
            this.chkSSL.Location = new System.Drawing.Point(9, 146);
            this.chkSSL.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.chkSSL.Name = "chkSSL";
            this.chkSSL.Size = new System.Drawing.Size(243, 20);
            this.chkSSL.TabIndex = 6;
            this.chkSSL.Text = "SSL connection";
            // 
            // textPassword
            // 
            this.textPassword.Location = new System.Drawing.Point(93, 108);
            this.textPassword.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.textPassword.Name = "textPassword";
            this.textPassword.PasswordChar = '*';
            this.textPassword.Size = new System.Drawing.Size(158, 23);
            this.textPassword.TabIndex = 5;
            // 
            // textUser
            // 
            this.textUser.Location = new System.Drawing.Point(93, 68);
            this.textUser.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.textUser.Name = "textUser";
            this.textUser.Size = new System.Drawing.Size(158, 23);
            this.textUser.TabIndex = 3;
            // 
            // textServer
            // 
            this.textServer.Location = new System.Drawing.Point(93, 28);
            this.textServer.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.textServer.Name = "textServer";
            this.textServer.Size = new System.Drawing.Size(158, 23);
            this.textServer.TabIndex = 1;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(9, 110);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(57, 15);
            this.label3.TabIndex = 4;
            this.label3.Text = "Password";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(9, 70);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(30, 15);
            this.label2.TabIndex = 2;
            this.label2.Text = "User";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(9, 30);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(39, 15);
            this.label1.TabIndex = 0;
            this.label1.Text = "Server";
            // 
            // ListViewMail
            // 
            this.ListViewMail.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.colFrom,
            this.colSubject,
            this.colDate});
            this.ListViewMail.FullRowSelect = true;
            this.ListViewMail.HideSelection = false;
            this.ListViewMail.Location = new System.Drawing.Point(289, 20);
            this.ListViewMail.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.ListViewMail.Name = "ListViewMail";
            this.ListViewMail.Size = new System.Drawing.Size(556, 209);
            this.ListViewMail.TabIndex = 1;
            this.ListViewMail.UseCompatibleStateImageBehavior = false;
            this.ListViewMail.View = System.Windows.Forms.View.Details;
            this.ListViewMail.Click += new System.EventHandler(this.ListViewMail_Click);
            // 
            // colFrom
            // 
            this.colFrom.Text = "From";
            this.colFrom.Width = 180;
            // 
            // colSubject
            // 
            this.colSubject.Text = "Subject";
            this.colSubject.Width = 200;
            // 
            // colDate
            // 
            this.colDate.Text = "Date";
            this.colDate.Width = 180;
            // 
            // ButtonDelete
            // 
            this.ButtonDelete.Location = new System.Drawing.Point(761, 233);
            this.ButtonDelete.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.ButtonDelete.Name = "ButtonDelete";
            this.ButtonDelete.Size = new System.Drawing.Size(84, 30);
            this.ButtonDelete.TabIndex = 3;
            this.ButtonDelete.Text = "Delete";
            this.ButtonDelete.Click += new System.EventHandler(this.btnDel_Click);
            // 
            // LabelTotal
            // 
            this.LabelTotal.AutoSize = true;
            this.LabelTotal.Location = new System.Drawing.Point(299, 240);
            this.LabelTotal.Name = "LabelTotal";
            this.LabelTotal.Size = new System.Drawing.Size(0, 15);
            this.LabelTotal.TabIndex = 2;
            // 
            // textStatus
            // 
            this.textStatus.Location = new System.Drawing.Point(0, 504);
            this.textStatus.Name = "textStatus";
            this.textStatus.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.textStatus.Size = new System.Drawing.Size(857, 26);
            this.textStatus.TabIndex = 5;
            // 
            // WebMail
            // 
            this.WebMail.Location = new System.Drawing.Point(289, 267);
            this.WebMail.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.WebMail.MinimumSize = new System.Drawing.Size(23, 25);
            this.WebMail.Name = "WebMail";
            this.WebMail.Size = new System.Drawing.Size(556, 230);
            this.WebMail.TabIndex = 4;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(857, 530);
            this.Controls.Add(this.WebMail);
            this.Controls.Add(this.textStatus);
            this.Controls.Add(this.LabelTotal);
            this.Controls.Add(this.ButtonDelete);
            this.Controls.Add(this.ListViewMail);
            this.Controls.Add(this.GroupBoxServer);
            this.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.Resize += new System.EventHandler(this.Form1_Resize);
            this.GroupBoxServer.ResumeLayout(false);
            this.GroupBoxServer.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox GroupBoxServer;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textServer;
        private System.Windows.Forms.TextBox textUser;
        private System.Windows.Forms.TextBox textPassword;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.ComboBox ComboBoxAuthType;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.ComboBox ComboBoxProtocol;
        private System.Windows.Forms.CheckBox chkLeaveCopy;
        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.ProgressBar pgBar;
        private System.Windows.Forms.CheckBox chkSSL;
        private System.Windows.Forms.ListView ListViewMail;
        private System.Windows.Forms.ColumnHeader colFrom;
        private System.Windows.Forms.ColumnHeader colSubject;
        private System.Windows.Forms.ColumnHeader colDate;
        private System.Windows.Forms.Button ButtonDelete;
        private System.Windows.Forms.Label LabelTotal;
        private System.Windows.Forms.StatusBar textStatus;
        private System.Windows.Forms.WebBrowser WebMail;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.CheckBox chkNewOnly;
        private System.Windows.Forms.ComboBox ComboBoxDateRange;

    }
}

