using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AppProject1
{
    public partial class FormAddFolder : Form
    {
        public FormAddFolder()
        {
            InitializeComponent();
        }

        private void ButtonOK_Click(object sender, EventArgs e)
        {
            textFolderName.Text = textFolderName.Text.Trim();
            if (textFolderName.Text.Length == 0)
            {
                MessageBox.Show("Please input folder name!");
                this.DialogResult = DialogResult.None;
            }
            else
            {
                this.DialogResult = DialogResult.OK;
            }
        }
    }
}
