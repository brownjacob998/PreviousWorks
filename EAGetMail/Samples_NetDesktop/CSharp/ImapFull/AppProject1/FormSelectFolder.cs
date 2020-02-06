using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using EAGetMail;

namespace AppProject1
{
    public partial class FormSelectFolder : Form
    {
        public string OriginalFolderPath = "";
        public FormSelectFolder()
        {
            InitializeComponent();
        }

        private void ButtonOK_Click(object sender, EventArgs e)
        {
            TreeNode node = TreeViewFolder.SelectedNode;
            if (node == null || node.Parent == null)
            {
                MessageBox.Show("please select a folder.");
                this.DialogResult = DialogResult.None;
                return;
            }

            Imap4Folder folder = node.Tag as Imap4Folder;
            if (string.Compare(folder.ServerPath, OriginalFolderPath, true) == 0)
            {
                MessageBox.Show("please select a folder different with original folder.");
                this.DialogResult = DialogResult.None;
                return;
            }

            this.DialogResult = DialogResult.OK;
        }
    }
}
