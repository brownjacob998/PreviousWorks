unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, OleCtrls, ComCtrls, StdCtrls, StrUtils, DateUtils, EAGetMailObjLib_TLB,
  SHDocVw, FormOauth, GoogleOauthWrapper;

type
  TForm1 = class(TForm)
    GroupBox1: TGroupBox;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    textServer: TEdit;
    textUser: TEdit;
    textPassword: TEdit;
    chkSSL: TCheckBox;
    Label4: TLabel;
    Label5: TLabel;

    lstAuthType: TComboBox;
    lstProtocol: TComboBox;
    chkLeaveCopy: TCheckBox;
    btnStart: TButton;
    btnCancel: TButton;
    pgBar: TProgressBar;
    lstMail: TListView;
    btnDel: TButton;
    lblTotal: TLabel;
    textStatus: TStatusBar;
    Label6: TLabel;
    chkNewOnly: TCheckBox;
    lstDateRange: TComboBox;
    textReport: TMemo;
    
    procedure FormCreate(Sender: TObject);
    procedure FormResize(Sender: TObject);

    procedure lstProtocolChange(Sender: TObject);
    procedure lstAuthTypeChange(Sender: TObject);

    procedure btnStartClick(Sender: TObject);
    procedure btnCancelClick(Sender: TObject);

    procedure lstMailSelectItem(Sender: TObject; Item: TListItem;
      Selected: Boolean);
    procedure lstMailCompare(Sender: TObject; Item1, Item2: TListItem;
      Data: Integer; var Compare: Integer);
    procedure btnDelClick(Sender: TObject);

    // EAGetMail event handler
    procedure OnIdle(ASender: TObject; const oSender: IDispatch; var Cancel: WordBool);
    procedure OnConnected(ASender: TObject; const oSender: IDispatch; var Cancel: WordBool);
    procedure OnQuit(ASender: TObject; const oSender: IDispatch; var Cancel: WordBool);
    procedure OnSecuring(ASender: TObject; const oSender: IDispatch; var Cancel: WordBool);
    procedure OnAuthorized(ASender: TObject; const oSender: IDispatch;
      var Cancel: WordBool);
    procedure OnSendingDataStream(ASender: TObject; const oSender: IDispatch;
      Sent: Integer; Total: Integer;
      var Cancel: WordBool);
    procedure OnReceivingDataStream(ASender: TObject; const oSender: IDispatch;
      const oInfo: IDispatch;
      Received: Integer; Total: Integer;
      var Cancel: WordBool);
    // End EAGetMail event handler
    
  private
    { Private declarations }
    procedure InitResize();
    procedure AutoResizeControl();

    function BuildServer(): TMailServer;
    function ValidateInput(): Boolean;
    function TryOauth(): Boolean;
    procedure SetMailRange();

    procedure EnableSettingControls(isEnabled: Boolean; isCancelEnabled: Boolean);
    function CreateLocalInbox(): WideString;
    function GenerateFileName(seed: integer): WideString;
    Function AddNewReportToListMail(oMail: IMail; filePath: WideString): TListItem;

    // Display report functions
    procedure LoadLocalReports();
    procedure ShowReport(fileName: WideString);

  public
    { Public declarations }
    // Oauth wrapper for Gmail XOAUTH2
    Oauth: TGoogleOauthWrapper;
  end;
  
const
  // Connection Type
  MailServerConnectType_ConnectSSLAuto = 0;
  MailServerConnectType_ConnectSSL = 1;
  MailServerConnectType_ConnectTLS = 2;

  // Proxy, EWS/WebDAV doesn't support proxy server
  ProxyType_Socks4 = 0;
  ProxyType_Socks5 = 1;
  ProxyType_Http = 2;

  // Auth type
  MailServerAuthLogin = 0;
  MailServerAuthCRAM5 = 1;
  MailServerAuthNTLM = 2;
  MailServerAuthXOAUTH2 = 3;

  MailServerPop3 = 0;
  MailServerImap4 = 1;
  MailServerEWS = 2;   // For Exchange Web Service - Exchange 2007/2010
  MailServerDAV = 3; // For Exchange Web DAV - Exchange 2000/2003

  // GetMailInfosParam Flags
  GetMailInfos_All = 1;
  GetMailInfos_NewOnly = 2;
  GetMailInfos_ReadOnly = 4;
  GetMailInfos_SeqRange = 8;
  GetMailInfos_UIDRange = 16;
  GetMailInfos_PR_ENTRYID = 32;
  GetMailInfos_DateRange = 64;
  GetMailInfos_OrderByDateTime = 128;

  // Report Type
  FailureReport = 0;
  DeliveryReceipt = 1;
  ReadReceipt = 2;
  Receipt_Deleted = 3;
  DelayedReport = 4;

var
  Form1: TForm1;

  // MailClient with Event Handler
  oClient: TMailClient;
  // EAGetMail Common Helper
  oTools: TTools;
  
  // Cancel current operation flag
  m_bCancel: WordBool;
  m_currentPath: WideString;

  // =========================================================
  // Variables for AutoResizeControl
  //=========================================================
  formWidth: integer;
  formHeight: integer;
  lstMailWidthOffset: integer;
  btnDelLeftOffset: integer;
  textReportHeightOffset: integer;

implementation

{$R *.dfm}
//==============================================
// Region AutoResizeControl
//===============================================
procedure TForm1.InitResize();
begin
  formWidth := Form1.Width;
  formHeight := Form1.Height;

  lstMailWidthOffset := Form1.Width - lstMail.Width;
  textReportHeightOffset := Form1.Height - textReport.Height;
  btnDelLeftOffset := Form1.Width - btnDel.Left;
end;

procedure TForm1.AutoResizeControl();
begin
  if Form1.Width < formWidth then
    Form1.Width := formWidth;

  if Form1.Height < formHeight then
    Form1.Height := formHeight;

  lstMail.Width := Form1.Width - lstMailWidthOffset;
  btnDel.Left := Form1.Width - btnDelLeftOffset;

  textReport.Width := lstMail.Width;
  textReport.Height := Form1.Height - textReportHeightOffset;

end;

procedure TForm1.FormResize(Sender: TObject);
begin
  AutoResizeControl();
end;

//==============================================
// End AutoResizeControl
//===============================================

procedure TForm1.FormCreate(Sender: TObject);
begin
  SetThreadLocale(GetSystemDefaultLCID());
  InitResize();

  oTools := TTools.Create(Application);
  Oauth := TGoogleOauthWrapper.Create;

  textReport.Text := '';
  m_currentPath := GetCurrentDir();

  // Initialize authentication type
  lstAuthType.AddItem('USER/LOGIN', nil);
  lstAuthType.AddItem('APOP/AUTH CRAM-MD5', nil);
  lstAuthType.AddItem('NTLM', nil);
  lstAuthType.AddItem('Gmail XOAUTH2', nil);

  lstAuthType.ItemIndex := 0;

  // Initialize date range
  lstDateRange.AddItem('All reports', nil);
  lstDateRange.AddItem('Last 7 days', nil);
  lstDateRange.AddItem('Last 30 days', nil);
  lstDateRange.AddItem('Last 60 days', nil);
  lstDateRange.AddItem('Last 90 days', nil);
  
  lstDateRange.ItemIndex := 0;

  // Initialize server protocols
  lstProtocol.AddItem('POP3', nil);
  lstProtocol.AddItem('IMAP4', nil);
  lstProtocol.AddItem('EWS Exchange 2007-2019/Office365', nil);
  lstProtocol.AddItem('Exchange WebDAV', nil);

  lstProtocol.ItemIndex := 0;

  m_bCancel := false;
    
  textStatus.SimpleText := '';
  
  LoadLocalReports();
end;

//-----------------------------------------------------
// Region: User authentication and Server setting
//-----------------------------------------------------
procedure TForm1.lstAuthTypeChange(Sender: TObject);
begin
  if lstAuthType.ItemIndex = MailServerAuthXOAUTH2 then
    begin
      lstProtocol.ItemIndex := MailServerImap4;
      textServer.Text := 'imap.gmail.com';
      
      chkSSL.Checked := true;

      // Get user and access token from FormOauth
      textUser.Enabled := false;
      textPassword.Enabled := false;

      textUser.Color := clScrollbar;
      textPassword.Color := clScrollbar;

      chkNewOnly.Enabled := true;
      lstDateRange.Enabled := true;
      
      textStatus.SimpleText := 'Please click \"Start\" to login Gmail by Web OAUTH!';
    end
  else
    begin
        textUser.Enabled := true;
        textPassword.Enabled := true;
        
        textUser.Color := clWindow;
        textPassword.Color := clWindow;
        
        // Clear existed access token
        Oauth.Clear();
        textStatus.SimpleText := '';
    end;

end;

// By default, Exchange Web Service requires SSL connection.
// For other protocol, please set SSL connection based on your server setting manually
// Pop3 doesn't support to get new email only, or retrieve email by date range.
procedure TForm1.lstProtocolChange(Sender: TObject);
begin
  if lstProtocol.ItemIndex = MailServerPop3 then
    begin
      chkNewOnly.Checked := false;
      chkNewOnly.Enabled := false;
      
      lstDateRange.ItemIndex := 0;
      lstDateRange.Enabled := false;
    end
  else
    begin
      chkNewOnly.Enabled := true;
      lstDateRange.Enabled := true;
    end;
  
  if lstProtocol.ItemIndex = MailServerEWS then
    chkSSL.Checked := true; //By default, Exchange Web Service requires SSL

end;

function TForm1.BuildServer(): TMailServer;
var
  oServer: TMailServer;
begin
  oServer := TMailServer.Create(Application);
    
  oServer.Server := trim(textServer.Text);
  oServer.User := trim(textUser.Text);
  oServer.Password := trim(textPassword.Text);

  oServer.SSLConnection := chkSSL.Checked;
  oServer.AuthType := lstAuthType.ItemIndex;
  oServer.Protocol := lstProtocol.ItemIndex;
    
  if oServer.Protocol = MailServerPop3 then
    if oServer.SSLConnection then
      oServer.Port := 995
    else
      oServer.Port := 110
  else
    if oServer.SSLConnection then
      oServer.Port :=993
    else
      oServer.Port := 143;

  result := oServer;
end;

function TForm1.ValidateInput(): Boolean;
begin
  result := false;

  textServer.Text := trim(textServer.Text);
  textUser.Text := trim(textUser.Text);
  textPassword.Text := trim(textPassword.Text);
  
  if textServer.Text = '' then
    begin
      ShowMessage('Please input server address!');
      textServer.Enabled := true;
      textServer.SetFocus();
      exit;
    end;

  if textUser.Text = '' then
    begin
      ShowMessage('Please input user name!');
      textUser.Enabled := true;
      textUser.SetFocus();
      exit;
    end;

  if textPassword.Text = '' then
    begin
      ShowMessage('Please input password!');
      textPassword.Enabled := true;
      textPassword.SetFocus();
      exit;
    end;

  result := true;
end;

function TForm1.TryOauth(): Boolean;
var
  formOauth: TFormOauth;
begin

  result := true;
  if lstAuthType.ItemIndex <> MailServerAuthXOAUTH2 then
    exit; // We don't need to login user by Gmail XOAUTH


  if Oauth.AccessToken <> '' then
    begin
      if not Oauth.AccessTokenIsExpired() then
          exit;
        
      textStatus.SimpleText := 'Refresh expired access token from server ...';
      if Oauth.RefreshAccessToken() then
        exit;
        
      Oauth.ClearError();
      textStatus.SimpleText := 'Failed to refresh expired access token, now request new token again ...';
    end;
    
    result := false;

    formOauth := TFormOauth.Create(Application);
    formOauth.Oauth := Oauth;
    formOauth.ShowModal();

    if Oauth.AuthorizationCode = '' then
      begin
        textStatus.SimpleText := 'Failed to login user and get authorization code.';
        exit;
      end;
    
    textStatus.SimpleText := 'Request access token from server ...';
    if not Oauth.RequestAccessTokenAndUserEmail() then
      begin
        textStatus.SimpleText := Oauth.GetLastError();
        exit;
      end;
    
    result := true
end;
//-----------------------------------------------------
// End Of User authentication and Server setting
//-----------------------------------------------------


//-----------------------------------------------------
// Region: Retrieve emails from server
//-----------------------------------------------------
procedure TForm1.SetMailRange();
var
  dateSince: TDateTime;
begin
  oClient.GetMailInfosParam.Reset();

  if lstProtocol.ItemIndex = MailServerPop3 then
    exit; // POP3 protocol doesn't support mail range.

  // Retrieve new emails only.
  if chkNewOnly.Checked then
    oClient.GetMailInfosParam.GetMailInfosOptions := (oClient.GetMailInfosParam.GetMailInfosOptions Or GetMailInfos_NewOnly);


  if lstDateRange.ItemIndex = 0 Then
    exit; // Retrieve all emails.

  oClient.GetMailInfosParam.GetMailInfosOptions := (oClient.GetMailInfosParam.GetMailInfosOptions Or GetMailInfos_DateRange);

  case lstDateRange.ItemIndex of
    1: dateSince := IncDay(Now(), -7);
    2: dateSince := IncDay(Now(), -30);
    3: dateSince := IncDay(Now(), -60);
  else
    dateSince := IncDay(Now(), -90);
  end;
  
  oClient.GetMailInfosParam.DateRangeSINCE := dateSince;
  oClient.GetMailInfosParam.DateRangeBEFORE := IncDay(Now(), 1);
end;

procedure TForm1.EnableSettingControls(isEnabled: Boolean; isCancelEnabled: Boolean);
begin

   btnStart.Enabled := isEnabled;
   btnCancel.Enabled := isCancelEnabled;

   textServer.Enabled := isEnabled;
   chkSSL.Enabled := isEnabled;
   chkLeaveCopy.Enabled := isEnabled;

   lstAuthType.Enabled := isEnabled;
   lstProtocol.Enabled := isEnabled;

  if lstAuthType.ItemIndex <> MailServerAuthXOAUTH2 then
    begin
       textUser.Enabled := isEnabled;
       textPassword.Enabled := isEnabled;
    end;

  if lstProtocol.ItemIndex <> MailServerPop3 then
    begin
       chkNewOnly.Enabled := isEnabled;
       lstDateRange.Enabled := isEnabled;
    end;

end;

function TForm1.CreateLocalInbox(): WideString;
var
  mailFolder: WideString;
begin
 // create a folder named "inbox" under
  // current directory to store the email files
  mailFolder := m_currentPath + '\inbox';
  oTools.CreateFolder(mailFolder);

  result := mailFolder;
end;

function TForm1.GenerateFileName(seed: integer): WideString;
var
  fileName: WideString;
begin
  fileName :=  oTools.GenFileName(seed) + '.eml';
  result := fileName;
end;

Function TForm1.AddNewReportToListMail(oMail: IMail; filePath: WideString): TListItem;
var
  item: TListItem;
begin

  item := TListItem.Create(lstMail.Items);

  item.SubItems.Add(oMail.Subject);
  item.SubItems.Add(FormatDateTime('yyyy-MM-dd hh:mm:ss', oMail.ReceivedDate));
  item.SubItems.Add(filePath);

  lstMail.Items.AddItem(item);
  item.Caption := oMail.From.Address;

  result := item;
end;

procedure TForm1.btnStartClick(Sender: TObject);
var
  oServer: TMailServer;
  oUIDLManager: TUIDLManager;
  mailInfos: IMailInfoCollection;
  oInfo: IMailInfo;
  oMail: IMail;
  i: integer;
  localInbox, fileName, fullFileName: WideString;
  isUidlLoaded: Boolean;
begin

  EnableSettingControls(false, false);

  if not TryOauth() then
    begin
      // textStatus.SimpleText = "Failed to request/refresh access token."
      EnableSettingControls(true, false);
      exit;
    end;

  if lstAuthType.ItemIndex = MailServerAuthXOAUTH2 then
    begin
        // Use Gmail Oauth, now put user email and access token to user and password.
      textUser.Text := Oauth.UserEmail;
      textPassword.Text := Oauth.AccessToken;
    end;

  if not ValidateInput() then
    begin
      EnableSettingControls(true, false);
      exit;
    end;

  EnableSettingControls(false, true);
  isUidlLoaded := false;

  try
    oClient := TMailClient.Create(Application);
    // For evaluation usage, please use "TryIt" as the license code, otherwise the
    // "Invalid license code" exception will be thrown. However, the object will expire in 1-2 months, then
    // "Trial version expired" exception will be thrown.
    oClient.LicenseCode := 'TryIt';

    // Add EAGetMail event handler
    // You don't have to use EAGetMail Event,
    // but using Event make your application more user friendly
    oClient.OnIdle := OnIdle;
    oClient.OnConnected := OnConnected;
    oClient.OnQuit := OnQuit;
    oClient.OnSecuring := OnSecuring;
    oClient.OnAuthorized := OnAuthorized;
    oClient.OnSendingDataStream := OnSendingDataStream;
    oClient.OnReceivingDataStream := OnReceivingDataStream;
    
    oServer := BuildServer();
 
    pgBar.Position := 0;
    m_bCancel := false; 

    textStatus.SimpleText := 'Connecting server ...';

    // oClient.LogFileName = 'd:\\pop3.txt'; // Generate a log file
    oClient.Connect1(oServer.DefaultInterface);
    localInbox := CreateLocalInbox();

    // uidl is the identifier of every email on POP3/IMAP4 server, to avoid retrieve
    // the same email from server more than once, we record the email uidl retrieved every time
    // if you delete the email from server every time and not to leave a copy of email on
    // the server, then please remove all the function about uidl.
    oUIDLManager := TUIDLManager.Create(Application);
    oUIDLManager.Load(localInbox + '\uidl.txt');
    isUidlLoaded := true;

    SetMailRange();

    textStatus.SimpleText := 'Retrieving mail list ...';
    mailInfos := oClient.GetMailInfoList();
    

    if lstDateRange.ItemIndex = 0 then
      begin
          // Remove the local uidl that is not existed on the server,
          // We only synchronize it with uidl of all emails in current mail folder
        oUIDLManager.SyncUIDLEX(oServer.DefaultInterface, mailInfos);
        oUIDLManager.Update(); 
      end;

   
    for i := 0 to mailInfos.Count - 1 do
      begin
        textStatus.SimpleText := Format('Checking %d/%d ...', [i+1, mailInfos.Count]);
        oInfo := mailInfos.Item[i];

        // This email has not been retrieved before, then get it
        if oUIDLManager.FindUIDL(oServer.DefaultInterface, oInfo.UIDL) = nil then
          begin

             textStatus.SimpleText := Format('Retrieve headers %d/%d ...', [i+1, mailInfos.Count]);
            // Retrieve email from server
            oMail := TMail.Create(Application).DefaultInterface;
            oMail.LicenseCode := 'TryIt';
            oMail.Load(oClient.GetMailHeader(oInfo));
            

            fileName := GenerateFileName(i);
            fullFileName := localInbox + '\' + fileName;
            
            if not oMail.IsReport then
              begin
                // This is not a report
                // add the email uidl to uidl file to avoid we check it next time.
                oUIDLManager.AddUIDL(oServer.DefaultInterface, oInfo.UIDL, fileName);

                // If retrieve only new emails, after we retrieved it, mark it as read,
                // With this feature, you don't have to UIDLManager to prevent duplicated emails.
                if chkNewOnly.Checked and (lstProtocol.ItemIndex <> MailServerPop3) then
                    oClient.MarkAsRead(oInfo, true);

              end
            else
              begin
                // This is a delivery report, get entire message
                textStatus.SimpleText := Format('Report found, retrieve full data %d/%d ...', [i+1, mailInfos.Count]);
                oMail := oClient.GetMail(oInfo);
                oMail.SaveAs(fullFileName, true);
                
                AddNewReportToListMail(oMail, fullFileName);

                // If retrieve only new emails, after we retrieved it, mark it as read,
                // With this feature, you don't have to UIDLManager to prevent duplicated emails.
                if chkNewOnly.Checked and (lstProtocol.ItemIndex <> MailServerPop3) then
                    oClient.MarkAsRead(oInfo, true);

                 if chkLeaveCopy.Checked Then
                  begin
                    // Add the email uidl to uidl file to avoid we retrieve it next time.
                    oUIDLManager.AddUIDL(oServer.DefaultInterface, oInfo.UIDL, fileName);
                  end
                else
                  begin
                    // We only delete the report email and ignore other normal emails.
                    textStatus.SimpleText := Format('Deleting report %d ... ', [i+1]);
                    oClient.Delete(oInfo);

                    // Remove UIDL from local uidl file.
                    oUIDLManager.RemoveUIDL(oServer.DefaultInterface, oInfo.UIDL);
                  end;

              end;
               
          end;

        pgBar.Position := 0;
        
      end;

    // Delete method just mark the email as deleted,
    // Quit method pure the emails from server exactly.
    oClient.Quit;

    // Update the uidl list to a text file and then we can load it next time.
    oUIDLManager.Update();
    textStatus.SimpleText := 'Completed';

  except
    on ep:Exception do
      begin
       // Update the uidl list to a text file and then we can load it next time.
       if isUidlLoaded then
          oUIDLManager.Update();

        ShowMessage(ep.Message);
        textStatus.SimpleText := ep.Message;
      end;
  end;

  if oClient <> nil then
    oClient := nil;

  EnableSettingControls(true, false);

end;

procedure TForm1.btnCancelClick(Sender: TObject);
begin
  m_bCancel := true;
  btnCancel.Enabled := false;
end;
//-----------------------------------------------------
// End of Retrieve emails from server
//-----------------------------------------------------

// ----------------------------------------------------
// Region: Display and parse emails
// ----------------------------------------------------
procedure TForm1.LoadLocalReports();
var
  oMail: TMail;
  i, UBound: integer;
  localInbox: WideString;
  files: OleVariant;
  fullFileName: WideString;
begin
  localInbox := CreateLocalInbox();
  files := oTools.GetFiles(localInbox + '\*.eml');

  UBound := VarArrayHighBound(files, 1);
  for i := 0 to UBound do
  begin
    fullFileName := VarArrayGet(files, i);
    oMail := TMail.Create(Application);
    oMail.LicenseCode := 'TryIt';

    // Only load the email header temporially
    oMail.LoadFile(fullFileName, true);
    AddNewReportToListMail(oMail.DefaultInterface, fullFileName);

  end;
  lblTotal.Caption := Format('Total %d report(s)', [lstMail.Items.Count]);

end;

procedure TForm1.lstMailSelectItem(Sender: TObject; Item: TListItem;
  Selected: Boolean);
var
  fileName: WideString;
begin
  if not Selected then
    exit;

  fileName := item.SubItems[2];

  try
    ShowReport(fileName);
  except
    on ep:Exception do
      ShowMessage('Error: ' + ep.Message + #13#10 + 'file: ' + fileName);
  end;
end;

procedure TForm1.ShowReport(fileName: WideString);
var
  oMail: TMail;
  oReport: IMailReport;
  s : WideString;
  oHeaders: IHeaderCollection;
  count, i: integer;
begin

  oMail := TMail.Create(Application);
  oMail.LicenseCode := 'TryIt';

  oMail.LoadFile(fileName, false);
  if not oMail.IsReport then
  begin
      textReport.Text := 'This is not a report';
      exit;
  end;

  oReport := oMail.GetReport();
  if oReport.ReportType = DeliveryReceipt then
  s := 'This is a deliver receipt!' + #13#10#13#10
  else if oReport.ReportType = ReadReceipt then
  s := 'This is a read receipt!' + #13#10#13#10
  else if oReport.ReportType = Receipt_Deleted then
  s := 'This is a unread receipt, this email was deleted without read.' + #13#10#13#10
  else if oReport.ReportType = DelayedReport then
  s := 'This is a delayed report, this email will be tried later' + #13#10#13#10
  else
  s := 'This is a failure report!' + #13#10#13#10;

  // Get original message information
  s := s + 'Original Sender: ' + oReport.OriginalSender + #13#10;
  s := s + 'Original Recipient: ' + oReport.OriginalRecipient + #13#10;
  s := s + 'Original Message-ID: ' + oReport.OriginalMessageID + #13#10#13#10;

  if (oReport.ReportType = FailureReport) or (oReport.ReportType = DelayedReport) then
    begin

      s := s + 'Error Code: ' + oReport.ErrCode + #13#10;
      s := s + 'Error Description: ' + oReport.ErrDescription + #13#10;
      s := s + 'Report MTA: ' + oReport.ReportMTA + #13#10;
      s := s + 'Original Subject: ' + oReport.OriginalSubject + #13#10#13#10;
      s := s + '---- Original Message Header ----' + #13#10#13#10;

      oHeaders := oReport.OriginalHeaders;
      // Parse original email headers.
      count := oHeaders.Count;
      for i := 0 to count - 1 do
        begin
          s := s + oHeaders.Item(i).HeaderKey + ': ' +
            oHeaders.Item(i).HeaderValue + #13#10;
        end;

    end;

  textReport.Text := s;

end;

procedure TForm1.btnDelClick(Sender: TObject);
var
  index: integer;
  fileName: WideString;
begin
  if lstMail.ItemIndex = -1 then
  begin
    ShowMessage('Please select an email in the list!');
    exit;
  end;

  index := lstMail.ItemIndex;
  fileName := lstMail.Items[index].SubItems[2];
  lstMail.Items.Delete(index);

  try

    oTools.RemoveFile(fileName);
  
    lblTotal.Caption := Format('Total %d report(s)', [lstMail.Items.Count]);
    
    if lstMail.Items.Count > 0 then
      begin
        if index > (lstMail.Items.Count-1) then
            index := lstMail.Items.Count-1;

        lstMail.Items[index].Selected := true;
        ShowReport(lstMail.Items[index].SubItems[2]);
      end
    else
      textReport.Text := '';

  except
    on ep:Exception do
      begin
        ShowMessage('Delete Error: ' + ep.Message);
      end;

  end;
end;

procedure TForm1.lstMailCompare(Sender: TObject; Item1, Item2: TListItem;
  Data: Integer; var Compare: Integer);
var
  s1, s2: string;
begin
    s1:= Item1.SubItems[1];;
    s2 := Item2.SubItems[1];
    Compare := -CompareText(s1,s2);
end;
// ----------------------------------------------------
// End Of Display and parse emails
// ----------------------------------------------------


// ---------------------------------------------------------------------------------------
// EAGetMail event handler
// ---------------------------------------------------------------------------------------
procedure TForm1.OnIdle(ASender: TObject; const oSender: IDispatch; var Cancel: WordBool);
begin
  Application.ProcessMessages();
  Cancel := m_bCancel;
end;

procedure TForm1.OnConnected(ASender: TObject; const oSender: IDispatch; var Cancel: WordBool);
begin
  textStatus.SimpleText := 'Connected';
  Cancel := m_bCancel;
end;

procedure TForm1.OnQuit(ASender: TObject; const oSender: IDispatch; var Cancel: WordBool);
begin
  textStatus.SimpleText := 'Disconnecting ...';
end;

procedure TForm1.OnSecuring(ASender: TObject; const oSender: IDispatch; var Cancel: WordBool);
begin
  textStatus.SimpleText := 'Securing ...';
  Cancel := m_bCancel;
end;

procedure TForm1.OnAuthorized(ASender: TObject; const oSender: IDispatch;
      var Cancel: WordBool);
begin
  textStatus.SimpleText := 'Authorized';
  Cancel := m_bCancel;
end;

procedure TForm1.OnSendingDataStream(ASender: TObject; const oSender: IDispatch;
      Sent: Integer; Total: Integer;
      var Cancel: WordBool);
begin
  // Implementation code for IMAP4 appending event
end;

procedure TForm1.OnReceivingDataStream(ASender: TObject; const oSender: IDispatch;
      const oInfo: IDispatch;
      Received: Integer; Total: Integer;
      var Cancel: WordBool);
begin
  pgBar.Max := Total;
  pgBar.Min := 0;
  pgBar.Position := Received;
  Cancel := m_bCancel;
end;
// End of EAGetMail event handler

end.
