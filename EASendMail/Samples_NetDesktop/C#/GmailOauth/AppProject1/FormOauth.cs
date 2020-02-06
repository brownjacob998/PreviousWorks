using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using EASendMail.Oauth;

namespace AppProject1
{
    public partial class FormOauth : Form
    {
        public OauthDesktopWrapper OauthWrapper = null;
        public FormOauth()
        {
            InitializeComponent();
            this.DialogResult = DialogResult.Cancel;
        }

        private void FormOauth_Load(object sender, EventArgs e)
        {
            //start to open Gmail OAUTH login web page.
            OauthBrowser.Navigate(OauthWrapper.OauthProvider.GenerateFullAuthUri()); 
        }

        private void OauthBrowser_DocumentCompleted(object sender, WebBrowserDocumentCompletedEventArgs e)
        {
            HtmlElement elment = OauthBrowser.Document.GetElementById("code");
            if (elment == null)
            {
                return;
            }

            string code = elment.GetAttribute("value");
            OauthWrapper.AuthorizationCode = code;
            this.DialogResult = DialogResult.OK;
            this.Close();
        }
    }
}
