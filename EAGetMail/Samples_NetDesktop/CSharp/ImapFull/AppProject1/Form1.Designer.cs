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
            this.components = new System.ComponentModel.Container();
            this.TreeViewFolder = new System.Windows.Forms.TreeView();
            this.contextMenuFolder = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.refreshFoldersToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.refreshMailsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.addFolderToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.deleteFolderToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.renameFolderToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.ListViewMail = new System.Windows.Forms.ListView();
            this.colFrom = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colSubject = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colDate = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.btnDelete = new System.Windows.Forms.Button();
            this.btnUndelete = new System.Windows.Forms.Button();
            this.btnUnread = new System.Windows.Forms.Button();
            this.btnExpunge = new System.Windows.Forms.Button();
            this.btnMove = new System.Windows.Forms.Button();
            this.pgBar = new System.Windows.Forms.ProgressBar();
            this.webMail = new System.Windows.Forms.WebBrowser();
            this.textStatus = new System.Windows.Forms.StatusBar();
            this.GroupBoxServer = new System.Windows.Forms.GroupBox();
            this.ComboBoxDateRange = new System.Windows.Forms.ComboBox();
            this.btnQuit = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.btnCancel = new System.Windows.Forms.Button();
            this.btnStart = new System.Windows.Forms.Button();
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
            this.label6 = new System.Windows.Forms.Label();
            this.btnUpload = new System.Windows.Forms.Button();
            this.btnCopy = new System.Windows.Forms.Button();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.contextMenuFolder.SuspendLayout();
            this.GroupBoxServer.SuspendLayout();
            this.SuspendLayout();
            // 
            // TreeViewFolder
            // 
            this.TreeViewFolder.ContextMenuStrip = this.contextMenuFolder;
            this.TreeViewFolder.HideSelection = false;
            this.TreeViewFolder.Location = new System.Drawing.Point(296, 15);
            this.TreeViewFolder.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.TreeViewFolder.Name = "TreeViewFolder";
            this.TreeViewFolder.Size = new System.Drawing.Size(183, 453);
            this.TreeViewFolder.TabIndex = 1;
            this.TreeViewFolder.AfterLabelEdit += new System.Windows.Forms.NodeLabelEditEventHandler(this.TreeViewFolder_AfterLabelEdit);
            this.TreeViewFolder.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.TreeViewFolder_AfterSelect);
            // 
            // contextMenuFolder
            // 
            this.contextMenuFolder.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.refreshFoldersToolStripMenuItem,
            this.refreshMailsToolStripMenuItem,
            this.addFolderToolStripMenuItem,
            this.deleteFolderToolStripMenuItem,
            this.renameFolderToolStripMenuItem});
            this.contextMenuFolder.Name = "contextMenuFolder";
            this.contextMenuFolder.Size = new System.Drawing.Size(155, 114);
            this.contextMenuFolder.Opening += new System.ComponentModel.CancelEventHandler(this.contextMenuFolder_Opening);
            // 
            // refreshFoldersToolStripMenuItem
            // 
            this.refreshFoldersToolStripMenuItem.Name = "refreshFoldersToolStripMenuItem";
            this.refreshFoldersToolStripMenuItem.Size = new System.Drawing.Size(154, 22);
            this.refreshFoldersToolStripMenuItem.Text = "Refresh Folders";
            this.refreshFoldersToolStripMenuItem.Click += new System.EventHandler(this.refreshFoldersToolStripMenuItem_Click);
            // 
            // refreshMailsToolStripMenuItem
            // 
            this.refreshMailsToolStripMenuItem.Name = "refreshMailsToolStripMenuItem";
            this.refreshMailsToolStripMenuItem.Size = new System.Drawing.Size(154, 22);
            this.refreshMailsToolStripMenuItem.Text = "Refresh Mails";
            this.refreshMailsToolStripMenuItem.Click += new System.EventHandler(this.refreshMailsToolStripMenuItem_Click);
            // 
            // addFolderToolStripMenuItem
            // 
            this.addFolderToolStripMenuItem.Name = "addFolderToolStripMenuItem";
            this.addFolderToolStripMenuItem.Size = new System.Drawing.Size(154, 22);
            this.addFolderToolStripMenuItem.Text = "Add Folder";
            this.addFolderToolStripMenuItem.Click += new System.EventHandler(this.addFolderToolStripMenuItem_Click);
            // 
            // deleteFolderToolStripMenuItem
            // 
            this.deleteFolderToolStripMenuItem.Name = "deleteFolderToolStripMenuItem";
            this.deleteFolderToolStripMenuItem.Size = new System.Drawing.Size(154, 22);
            this.deleteFolderToolStripMenuItem.Text = "Delete Folder";
            this.deleteFolderToolStripMenuItem.Click += new System.EventHandler(this.deleteFolderToolStripMenuItem_Click);
            // 
            // renameFolderToolStripMenuItem
            // 
            this.renameFolderToolStripMenuItem.Name = "renameFolderToolStripMenuItem";
            this.renameFolderToolStripMenuItem.Size = new System.Drawing.Size(154, 22);
            this.renameFolderToolStripMenuItem.Text = "Rename Folder";
            this.renameFolderToolStripMenuItem.Click += new System.EventHandler(this.renameFolderToolStripMenuItem_Click);
            // 
            // ListViewMail
            // 
            this.ListViewMail.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.colFrom,
            this.colSubject,
            this.colDate});
            this.ListViewMail.FullRowSelect = true;
            this.ListViewMail.HideSelection = false;
            this.ListViewMail.Location = new System.Drawing.Point(498, 15);
            this.ListViewMail.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.ListViewMail.Name = "ListViewMail";
            this.ListViewMail.Size = new System.Drawing.Size(520, 185);
            this.ListViewMail.TabIndex = 2;
            this.ListViewMail.UseCompatibleStateImageBehavior = false;
            this.ListViewMail.View = System.Windows.Forms.View.Details;
            this.ListViewMail.ItemSelectionChanged += new System.Windows.Forms.ListViewItemSelectionChangedEventHandler(this.ListViewMail_ItemSelectionChanged);
            // 
            // colFrom
            // 
            this.colFrom.Text = "From";
            this.colFrom.Width = 150;
            // 
            // colSubject
            // 
            this.colSubject.Text = "Subject";
            this.colSubject.Width = 200;
            // 
            // colDate
            // 
            this.colDate.Text = "Date";
            this.colDate.Width = 100;
            // 
            // btnDelete
            // 
            this.btnDelete.Enabled = false;
            this.btnDelete.Location = new System.Drawing.Point(498, 210);
            this.btnDelete.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btnDelete.Name = "btnDelete";
            this.btnDelete.Size = new System.Drawing.Size(65, 28);
            this.btnDelete.TabIndex = 3;
            this.btnDelete.Text = "Delete Message";
            this.btnDelete.Click += new System.EventHandler(this.btnDelete_Click);
            // 
            // btnUndelete
            // 
            this.btnUndelete.Enabled = false;
            this.btnUndelete.Location = new System.Drawing.Point(570, 210);
            this.btnUndelete.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btnUndelete.Name = "btnUndelete";
            this.btnUndelete.Size = new System.Drawing.Size(77, 28);
            this.btnUndelete.TabIndex = 4;
            this.btnUndelete.Text = "Undelete";
            this.btnUndelete.Click += new System.EventHandler(this.btnUndelete_Click);
            // 
            // btnUnread
            // 
            this.btnUnread.Enabled = false;
            this.btnUnread.Location = new System.Drawing.Point(654, 210);
            this.btnUnread.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btnUnread.Name = "btnUnread";
            this.btnUnread.Size = new System.Drawing.Size(65, 28);
            this.btnUnread.TabIndex = 5;
            this.btnUnread.Text = "Unread";
            this.btnUnread.Click += new System.EventHandler(this.btnUnread_Click);
            // 
            // btnExpunge
            // 
            this.btnExpunge.Enabled = false;
            this.btnExpunge.Location = new System.Drawing.Point(952, 210);
            this.btnExpunge.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btnExpunge.Name = "btnExpunge";
            this.btnExpunge.Size = new System.Drawing.Size(65, 28);
            this.btnExpunge.TabIndex = 9;
            this.btnExpunge.Text = "Expunge";
            this.btnExpunge.Click += new System.EventHandler(this.btnExpunge_Click);
            // 
            // btnMove
            // 
            this.btnMove.Enabled = false;
            this.btnMove.Location = new System.Drawing.Point(807, 210);
            this.btnMove.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btnMove.Name = "btnMove";
            this.btnMove.Size = new System.Drawing.Size(65, 28);
            this.btnMove.TabIndex = 7;
            this.btnMove.Text = "Move";
            this.btnMove.Click += new System.EventHandler(this.btnMove_Click);
            // 
            // pgBar
            // 
            this.pgBar.Location = new System.Drawing.Point(497, 456);
            this.pgBar.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.pgBar.Name = "pgBar";
            this.pgBar.Size = new System.Drawing.Size(519, 12);
            this.pgBar.TabIndex = 11;
            // 
            // webMail
            // 
            this.webMail.Location = new System.Drawing.Point(498, 246);
            this.webMail.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.webMail.MinimumSize = new System.Drawing.Size(23, 25);
            this.webMail.Name = "webMail";
            this.webMail.Size = new System.Drawing.Size(520, 199);
            this.webMail.TabIndex = 10;
            // 
            // textStatus
            // 
            this.textStatus.Location = new System.Drawing.Point(0, 473);
            this.textStatus.Name = "textStatus";
            this.textStatus.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.textStatus.Size = new System.Drawing.Size(1028, 26);
            this.textStatus.TabIndex = 12;
            // 
            // GroupBoxServer
            // 
            this.GroupBoxServer.Controls.Add(this.ComboBoxDateRange);
            this.GroupBoxServer.Controls.Add(this.btnQuit);
            this.GroupBoxServer.Controls.Add(this.label1);
            this.GroupBoxServer.Controls.Add(this.btnCancel);
            this.GroupBoxServer.Controls.Add(this.btnStart);
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
            this.GroupBoxServer.Controls.Add(this.label6);
            this.GroupBoxServer.Location = new System.Drawing.Point(14, 11);
            this.GroupBoxServer.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.GroupBoxServer.Name = "GroupBoxServer";
            this.GroupBoxServer.Padding = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.GroupBoxServer.Size = new System.Drawing.Size(266, 434);
            this.GroupBoxServer.TabIndex = 0;
            this.GroupBoxServer.TabStop = false;
            this.GroupBoxServer.Text = "Account Information";
            // 
            // ComboBoxDateRange
            // 
            this.ComboBoxDateRange.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.ComboBoxDateRange.FormattingEnabled = true;
            this.ComboBoxDateRange.Location = new System.Drawing.Point(14, 275);
            this.ComboBoxDateRange.Name = "ComboBoxDateRange";
            this.ComboBoxDateRange.Size = new System.Drawing.Size(237, 23);
            this.ComboBoxDateRange.TabIndex = 11;
            // 
            // btnQuit
            // 
            this.btnQuit.Enabled = false;
            this.btnQuit.Location = new System.Drawing.Point(14, 351);
            this.btnQuit.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btnQuit.Name = "btnQuit";
            this.btnQuit.Size = new System.Drawing.Size(243, 30);
            this.btnQuit.TabIndex = 14;
            this.btnQuit.Text = "Quit";
            this.btnQuit.UseVisualStyleBackColor = true;
            this.btnQuit.Click += new System.EventHandler(this.btnQuit_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(9, 340);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(0, 15);
            this.label1.TabIndex = 13;
            // 
            // btnCancel
            // 
            this.btnCancel.Enabled = false;
            this.btnCancel.Location = new System.Drawing.Point(14, 387);
            this.btnCancel.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(243, 30);
            this.btnCancel.TabIndex = 15;
            this.btnCancel.Text = "Cancel Task";
            this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
            // 
            // btnStart
            // 
            this.btnStart.Location = new System.Drawing.Point(13, 314);
            this.btnStart.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(243, 30);
            this.btnStart.TabIndex = 12;
            this.btnStart.Text = "Start";
            this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
            // 
            // ComboBoxProtocol
            // 
            this.ComboBoxProtocol.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.ComboBoxProtocol.Location = new System.Drawing.Point(93, 226);
            this.ComboBoxProtocol.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.ComboBoxProtocol.Name = "ComboBoxProtocol";
            this.ComboBoxProtocol.Size = new System.Drawing.Size(158, 23);
            this.ComboBoxProtocol.TabIndex = 10;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(9, 229);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(52, 15);
            this.label5.TabIndex = 9;
            this.label5.Text = "Protocol";
            // 
            // ComboBoxAuthType
            // 
            this.ComboBoxAuthType.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.ComboBoxAuthType.Location = new System.Drawing.Point(93, 186);
            this.ComboBoxAuthType.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.ComboBoxAuthType.Name = "ComboBoxAuthType";
            this.ComboBoxAuthType.Size = new System.Drawing.Size(158, 23);
            this.ComboBoxAuthType.TabIndex = 8;
            this.ComboBoxAuthType.SelectedIndexChanged += new System.EventHandler(this.ComboBoxAuthType_SelectedIndexChanged);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(9, 189);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(61, 15);
            this.label4.TabIndex = 7;
            this.label4.Text = "Auth Type";
            // 
            // chkSSL
            // 
            this.chkSSL.Checked = true;
            this.chkSSL.CheckState = System.Windows.Forms.CheckState.Checked;
            this.chkSSL.Location = new System.Drawing.Point(13, 152);
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
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(9, 30);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(39, 15);
            this.label6.TabIndex = 0;
            this.label6.Text = "Server";
            // 
            // btnUpload
            // 
            this.btnUpload.Enabled = false;
            this.btnUpload.Location = new System.Drawing.Point(878, 210);
            this.btnUpload.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btnUpload.Name = "btnUpload";
            this.btnUpload.Size = new System.Drawing.Size(65, 28);
            this.btnUpload.TabIndex = 8;
            this.btnUpload.Text = "Upload";
            this.btnUpload.UseVisualStyleBackColor = true;
            this.btnUpload.Click += new System.EventHandler(this.btnUpload_Click);
            // 
            // btnCopy
            // 
            this.btnCopy.Enabled = false;
            this.btnCopy.Location = new System.Drawing.Point(731, 210);
            this.btnCopy.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btnCopy.Name = "btnCopy";
            this.btnCopy.Size = new System.Drawing.Size(65, 28);
            this.btnCopy.TabIndex = 6;
            this.btnCopy.Text = "Copy";
            this.btnCopy.UseVisualStyleBackColor = true;
            this.btnCopy.Click += new System.EventHandler(this.btnCopy_Click);
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            this.openFileDialog1.Filter = "Email File | *.EML";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1028, 499);
            this.Controls.Add(this.btnCopy);
            this.Controls.Add(this.btnUpload);
            this.Controls.Add(this.GroupBoxServer);
            this.Controls.Add(this.textStatus);
            this.Controls.Add(this.webMail);
            this.Controls.Add(this.pgBar);
            this.Controls.Add(this.ListViewMail);
            this.Controls.Add(this.btnMove);
            this.Controls.Add(this.TreeViewFolder);
            this.Controls.Add(this.btnExpunge);
            this.Controls.Add(this.btnUnread);
            this.Controls.Add(this.btnDelete);
            this.Controls.Add(this.btnUndelete);
            this.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.Resize += new System.EventHandler(this.Form1_Resize);
            this.contextMenuFolder.ResumeLayout(false);
            this.GroupBoxServer.ResumeLayout(false);
            this.GroupBoxServer.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TreeView TreeViewFolder;
        private System.Windows.Forms.ListView ListViewMail;
        private System.Windows.Forms.ColumnHeader colFrom;
        private System.Windows.Forms.ColumnHeader colSubject;
        private System.Windows.Forms.ColumnHeader colDate;
        private System.Windows.Forms.Button btnDelete;
        private System.Windows.Forms.Button btnUndelete;
        private System.Windows.Forms.Button btnUnread;
        private System.Windows.Forms.Button btnExpunge;
        private System.Windows.Forms.Button btnMove;
        private System.Windows.Forms.ProgressBar pgBar;
        private System.Windows.Forms.StatusBar textStatus;
        private System.Windows.Forms.WebBrowser webMail;
        private System.Windows.Forms.GroupBox GroupBoxServer;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.ComboBox ComboBoxProtocol;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.ComboBox ComboBoxAuthType;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.CheckBox chkSSL;
        private System.Windows.Forms.TextBox textPassword;
        private System.Windows.Forms.TextBox textUser;
        private System.Windows.Forms.TextBox textServer;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Button btnQuit;
        private System.Windows.Forms.ContextMenuStrip contextMenuFolder;
        private System.Windows.Forms.ToolStripMenuItem refreshFoldersToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem refreshMailsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem addFolderToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem deleteFolderToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem renameFolderToolStripMenuItem;
        private System.Windows.Forms.Button btnUpload;
        private System.Windows.Forms.Button btnCopy;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.ComboBox ComboBoxDateRange;
    }
}

