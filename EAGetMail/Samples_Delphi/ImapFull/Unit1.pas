unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, OleCtrls, ComCtrls, StdCtrls, StrUtils, DateUtils, EAGetMailObjLib_TLB,
  SHDocVw, Menus, FormOauth, FormFolder, FormSelectFolder, GoogleOauthWrapper;

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
    lstDateRange: TComboBox;
    
    btnStart: TButton;
    btnQuit: TButton;
    btnCancel: TButton;
    
    trFolder: TTreeView;
    PopupMenu1: TPopupMenu;
    RefreshFolders: TMenuItem;
    RefreshMails: TMenuItem;
    AddFolder: TMenuItem;
    DeleteFolder: TMenuItem;
    RenameFolder: TMenuItem;

    lstMail: TListView;
    webMail: TWebBrowser;
    pgBar: TProgressBar;
    textStatus: TStatusBar;
    
    btnDel: TButton;
    btnUndelete: TButton;
    btnUnread: TButton;
    btnExpunge: TButton;
    btnCopy: TButton;
    btnMove: TButton;
    btnUpload: TButton;

    procedure FormCreate(Sender: TObject);
    procedure FormResize(Sender: TObject);

    procedure lstAuthTypeChange(Sender: TObject);

    procedure btnStartClick(Sender: TObject);
    procedure btnQuitClick(Sender: TObject);
    procedure btnCancelClick(Sender: TObject);
    
    // Folder management
    procedure CreateFullFolder(folder: WideString);
    procedure trFolderChange(Sender: TObject; Node: TTreeNode);

    procedure RefreshFoldersClick(Sender: TObject);
    procedure RefreshMailsClick(Sender: TObject);
    procedure AddFolderClick(Sender: TObject);
    procedure DeleteFolderClick(Sender: TObject);
    procedure RenameFolderClick(Sender: TObject);
    procedure trFolderEdited(Sender: TObject; Node: TTreeNode;
      var S: String);

    // Display email functions
    procedure lstMailSelectItem(Sender: TObject; Item: TListItem;
      Selected: Boolean);
    procedure lstMailCompare(Sender: TObject; Item1, Item2: TListItem;
      Data: Integer; var Compare: Integer);
    procedure lstMailAdvancedCustomDrawItem(Sender: TCustomListView;
      Item: TListItem; State: TCustomDrawState; Stage: TCustomDrawStage;
      var DefaultDraw: Boolean);

    // Email management functions
    procedure btnDelClick(Sender: TObject);
    procedure btnUndeleteClick(Sender: TObject);
    procedure btnUnreadClick(Sender: TObject);
    procedure btnExpungeClick(Sender: TObject);
    procedure btnCopyClick(Sender: TObject);
    procedure btnMoveClick(Sender: TObject);
    procedure btnUploadClick(Sender: TObject);

    // EAGetMail event handler
    procedure OnIdle(ASender: TObject; const oSender: IDispatch; var Cancel: WordBool);
    procedure OnConnected(ASender: TObject; const oSender: IDispatch; var Cancel: WordBool);
    procedure OnQuit(ASender: TObject; const oSender: IDispatch; var Cancel: WordBool);
    procedure OnSecuring(ASender: TObject; const oSender: IDispatch; var Cancel: WordBool);
    procedure OnAuthorized(ASender: TObject; const oSender: IDispatch; var Cancel: WordBool);
    procedure OnSendingDataStream(ASender: TObject; const oSender: IDispatch; Sent: Integer; Total: Integer; var Cancel: WordBool);
    procedure OnReceivingDataStream(ASender: TObject; const oSender: IDispatch; const oInfo: IDispatch; Received: Integer; Total: Integer; var Cancel: WordBool);
    procedure PopupMenu1Popup(Sender: TObject);

  private
    { Private declarations }
    procedure InitResize();
    procedure AutoResizeControl();

    procedure SetMailRange();
    function ValidateInput(): Boolean;
    function TryOauth(): Boolean;
    function BuildServer(): TMailServer;
    procedure ConnectServerOnDemand();

    procedure PrepareLogin();
    procedure AfterLoginSucceeded();
    procedure AfterLoginError();
    procedure AfterQuit();
    procedure AfterError(ep: Exception);
    procedure PrepareWork();
    procedure EndWork();

    procedure EnableControlDynamic();

    procedure ShowAllFolders();
    procedure ExpandFolders(folders: IFolderCollection; parentNode: TTreeNode);
    function GetSelectedFolderNode(includeRoot: Boolean): TTreeNode;

    function GetDestFolder(): IImap4Folder;
    procedure CopyNodes(sourceNode: TTreeNode; destRoot:TTreeView; destNode: TTreeNode);

    // Display email functions
    function SelectedCounts(): integer;
    function EmlFileToHtmlRenderPath(filePath: WideString): WideString;
    function GetAttachmentTempFolder(filePath: WideString): WideString;
    function FormatAddresses(addresses: IAddressCollection; prefix: WideString): WideString;

    procedure LoadServerMails(folderNode: TTreeNode);
    function AddNewMailToListMail(oMail: TMail; oInfo: IMailInfo): TListItem;
    procedure ClearLocalMails(folder: WideString);
    procedure ShowMail(fileName: WideString);
    procedure GenerateHtmlForEmail(htmlFile: WideString; emlFile: WideString);

  public
    { Public declarations }
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

  ProtocolOffset = 1;

  // GetMailInfosParam Flags
  GetMailInfos_All = 1;
  GetMailInfos_NewOnly = 2;
  GetMailInfos_ReadOnly = 4;
  GetMailInfos_SeqRange = 8;
  GetMailInfos_UIDRange = 16;
  GetMailInfos_PR_ENTRYID = 32;
  GetMailInfos_DateRange = 64;
  GetMailInfos_OrderByDateTime = 128;

var
  Form1: TForm1;
  
  // MailClient with Event Handler
  oClient: TMailClient;
  // EAGetMail Common Helper
  oTools: TTools;

  // Current server and uidl manager instance  
  oCurServer: TMailServer;
  oUIDLManager: TUIDLManager;

  // Cancel current operation flag
  m_bCancel: WordBool;

  m_currentPath: WideString;
  m_uidlfile: WideString;

  m_isWorking: WordBool;
  m_isSelectedFolderChanged: WordBool;
  m_selectedFolderPath: WideString;

  // Oauth wrapper for Gmail XOAUTH2
  Oauth: TGoogleOauthWrapper;

  // =========================================================
  // Variables for AutoResizeControl
  //=========================================================
  formWidth: integer;
  formHeight: integer;
  lstMailWidthOffset: integer;
  webMailHeightOffset: integer;
  trFolderHeightOffset: integer;
  pgBarTopOffset: integer;

implementation

{$R *.dfm}

//==============================================
// Region: AutoResizeControl
//===============================================
procedure TForm1.InitResize();
begin
  formWidth := Form1.Width;
  formHeight := Form1.Height;

  lstMailWidthOffset := Form1.Width - lstMail.Width;
  webMailHeightOffset := Form1.Height - webMail.Height;
  trFolderHeightOffset := Form1.Height - trFolder.Height;
  pgBarTopOffset := Form1.Height - pgBar.Top;
end;

procedure TForm1.AutoResizeControl();
begin
  if Form1.Width < formWidth then
    Form1.Width := formWidth;

  if Form1.Height < formHeight then
    Form1.Height := formHeight;

  lstMail.Width := Form1.Width - lstMailWidthOffset;
  webMail.Width := lstMail.Width;
  webMail.Height := Form1.Height - webMailHeightOffset;

  trFolder.Height := Form1.Height - trFolderHeightOffset;
  pgBar.Top := Form1.Height - pgBarTopOffset;
  pgBar.Width := webMail.Width;

end;

procedure TForm1.FormResize(Sender: TObject);
begin
  AutoResizeControl();
end;

//==============================================
// End Region: AutoResizeControl
//===============================================

procedure TForm1.FormCreate(Sender: TObject);
begin
  SetThreadLocale(GetSystemDefaultLCID());
  InitResize();
  EnableControlDynamic();

  oTools := TTools.Create(Application);
  oUIDLManager := TUIDLManager.Create(Application);
  Oauth := TGoogleOauthWrapper.Create;

  webMail.Navigate('about:blank');
  m_currentPath := GetCurrentDir();

  // Initialize authentication type
  lstAuthType.AddItem('USER/LOGIN', nil);
  lstAuthType.AddItem('APOP/AUTH CRAM-MD5', nil);
  lstAuthType.AddItem('NTLM', nil);
  lstAuthType.AddItem('Gmail XOAUTH2', nil);
  lstAuthType.ItemIndex := 0;

  // Initialize date range
  lstDateRange.AddItem('Sync last 7 days emails', nil);
  lstDateRange.AddItem('Sync last 30 days emails', nil);
  lstDateRange.AddItem('Sync last 60 days emails', nil);
  lstDateRange.AddItem('Sync last 90 days emails', nil);
  lstDateRange.AddItem('Sync all emails (slow)', nil);
  lstDateRange.ItemIndex := 0;

  // Initialize protocols
  lstProtocol.AddItem('IMAP4', nil);
  lstProtocol.AddItem('EWS- Exchange 2007-2019/Office365', nil);
  lstProtocol.AddItem('Exchange WebDAV - 2000/2003', nil);
  lstProtocol.ItemIndex := 0;

  m_bCancel := false;
  oCurServer := nil;

  textStatus.SimpleText := '';
  trFolder.Items.Clear();

  m_isWorking := false;
end;

//-----------------------------------------------------
// Region: User authentication and Server setting
//-----------------------------------------------------
procedure TForm1.lstAuthTypeChange(Sender: TObject);
begin
  if lstAuthType.ItemIndex = MailServerAuthXOAUTH2 then
    begin
      lstProtocol.ItemIndex := MailServerImap4 + ProtocolOffset;
      textServer.Text := 'imap.gmail.com';
      
      chkSSL.Checked := true;

      // Get user and access token from FormOauth
      textUser.Enabled := false;
      textPassword.Enabled := false;
      textUser.Color := clScrollbar;
      textPassword.Color := clScrollbar;

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

procedure TForm1.SetMailRange();
var
  dateSince: TDateTime;
begin
  oClient.GetMailInfosParam.Reset();

 
  if lstDateRange.ItemIndex = 4 Then
    exit; // Retrieve all emails.

  oClient.GetMailInfosParam.GetMailInfosOptions := (oClient.GetMailInfosParam.GetMailInfosOptions Or GetMailInfos_DateRange);

  case lstDateRange.ItemIndex of
    0: dateSince := IncDay(Now(), -7);
    1: dateSince := IncDay(Now(), -30);
    2: dateSince := IncDay(Now(), -60);
  else
    dateSince := IncDay(Now(), -90);
  end;
  
  oClient.GetMailInfosParam.DateRangeSINCE := dateSince;
  oClient.GetMailInfosParam.DateRangeBEFORE := IncDay(Now(), 1);
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
  oServer.Protocol := lstProtocol.ItemIndex + ProtocolOffset;
    
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

procedure TForm1.ConnectServerOnDemand();
var
  oFolder: IImap4Folder;
  folderNode: TTreeNode;
begin
    m_isSelectedFolderChanged := false;

    if not oClient.Connected then
      begin
        textStatus.SimpleText := 'Connecting server ...';
        m_bCancel := false;

        oClient.Connect1(oCurServer.DefaultInterface);
        textStatus.SimpleText := 'Connected';
      end;

    folderNode := GetSelectedFolderNode(false);
    if folderNode = nil then
      exit;

    oFolder := IImap4Folder(folderNode.Data);
    if m_selectedFolderPath = oFolder.ServerPath then
        exit;
    
    // Clear current mail list, because the selected folder will be changed
    lstMail.Items.Clear();
    
    m_selectedFolderPath := oFolder.ServerPath;
    m_isSelectedFolderChanged := true;

    if oFolder.NoSelect then
      exit;

    oClient.SelectFolder(oFolder);
end;
    
//-----------------------------------------------------
// End Region: User authentication and Server setting
//-----------------------------------------------------

// --------------------------------------------------
// Region: Login, Quit and Cancel
// --------------------------------------------------
procedure TForm1.btnStartClick(Sender: TObject);
begin
  PrepareLogin();

  if not TryOauth() then
    begin
      textStatus.SimpleText := 'Failed to request/refresh access token.';
      AfterLoginError();
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
      AfterLoginError();
      exit;
    end;
    
  btnStart.Enabled := false;

  try
    oClient := TMailClient.Create(Application);
    oClient.LicenseCode := 'TryIt';

    // Add eagetmail event handler
    oClient.OnIdle := OnIdle;
    oClient.OnConnected := OnConnected;
    oClient.OnQuit := OnQuit;
    oClient.OnSecuring := OnSecuring;
    oClient.OnAuthorized := OnAuthorized;
    oClient.OnSendingDataStream := OnSendingDataStream;
    oClient.OnReceivingDataStream := OnReceivingDataStream;

    oCurServer := BuildServer();

    PrepareWork();

    oClient.Connect1(oCurServer.DefaultInterface);
    textStatus.SimpleText := 'Connected';
    
    ShowAllFolders();

    EndWork();
    AfterLoginSucceeded();

  except
    on ep:Exception do
      begin
        AfterError(ep);
        AfterLoginError();
      end;
  end;
  
end;

procedure TForm1.btnQuitClick(Sender: TObject);
begin
  try
    oClient.Logout
  except
    on ep:Exception do
    begin

    end;
  end;
  
  oClient.Close();
  AfterQuit();
end;

procedure TForm1.btnCancelClick(Sender: TObject);
begin
  m_bCancel := true;
  btnCancel.Enabled := false;
end;

procedure TForm1.PrepareLogin();
begin
    textServer.Enabled := false;
    
    textUser.Enabled := false;
    textPassword.Enabled := false;
   
    lstAuthType.Enabled := false;
    lstProtocol.Enabled := false;
    lstDateRange.Enabled := false;
    
    chkSSL.Enabled := false;
    btnStart.Enabled := false;

    m_selectedFolderPath := '';
end;

procedure TForm1.AfterLoginSucceeded();
begin
    textServer.Enabled :=  false;
    
    textUser.Enabled :=  false;
    textPassword.Enabled :=  false;
   
    chkSSL.Enabled :=  false;
    btnStart.Enabled :=  false;
    btnQuit.Enabled := true;

    m_selectedFolderPath := '';
end;

procedure TForm1.AfterLoginError();
begin
    textServer.Enabled := true;
    
    if lstAuthType.ItemIndex <> MailServerAuthXOAUTH2 then
      begin
        textUser.Enabled := true;
        textPassword.Enabled := true;
      end
    else
      begin
        textUser.Enabled :=  false;
        textPassword.Enabled :=  false;
      end;
   
    lstAuthType.Enabled := true;
    lstProtocol.Enabled := true;
    lstDateRange.Enabled := true;
    
    chkSSL.Enabled := true;
    btnStart.Enabled := true;
    btnQuit.Enabled :=  false;
    
    webMail.Navigate('about:blank');
    lstMail.Items.Clear();
    trFolder.Items.Clear();

    m_selectedFolderPath := '';
end;

procedure TForm1.AfterQuit();
begin;
    
    EndWork();

    webMail.Navigate ('about:blank');
    lstMail.Items.Clear();
    trFolder.Items.Clear();

    textServer.Enabled := true;

    if lstAuthType.ItemIndex <> MailServerAuthXOAUTH2 then
      begin
        textUser.Enabled := true;
        textPassword.Enabled := true;
      end;
   
    lstAuthType.Enabled := true;
    lstProtocol.Enabled := true;
    lstDateRange.Enabled := true;
    
    chkSSL.Enabled := true;
    btnStart.Enabled := true;

    btnQuit.Enabled :=  false;
    
    m_selectedFolderPath  := '';
    textStatus.SimpleText := 'Disconnected';
end;

procedure TForm1.AfterError(ep: Exception);
begin
    EndWork();

    oClient.Close();
    ShowMessage(ep.Message);

    m_selectedFolderPath := '';
    textStatus.SimpleText := ep.Message;
end;

procedure TForm1.PrepareWork();
begin
    m_isWorking := true;
    
    btnCancel.Enabled := true;
    m_bCancel :=  false;
    
    btnQuit.Enabled :=  false;

    EnableControlDynamic();
end;

procedure TForm1.EndWork();
begin
    m_isWorking :=  false;
    btnCancel.Enabled :=  false;
    
    btnQuit.Enabled := true;

    EnableControlDynamic();
end;

// --------------------------------------------------
// End Region: Login, Quit and Cancel
// --------------------------------------------------

//----------------------------------------------------------------------
// Region: Show server folders and expand folders.
//----------------------------------------------------------------------
procedure TForm1.ShowAllFolders();
var
  rootNode: TTreeNode;
begin
  trFolder.Items.Clear();
  
  rootNode := trFolder.Items.AddChild(nil,
        oCurServer.Server + '\' + oCurServer.User);

  trFolder.Selected := rootNode;
  ExpandFolders(oClient.GetFolderList(), rootNode);
  rootNode.Expand(true);

end;
    
procedure TForm1.ExpandFolders(folders: IFolderCollection; parentNode: TTreeNode);
var
  i: integer;
  currentNode: TTreeNode;
  oFolder: IImap4Folder;
begin
  parentNode.DeleteChildren();
  for i:= 0 to folders.Count - 1 do
  begin
       oFolder := folders.Item[i];
  
       currentNode := trFolder.Items.AddChild(parentNode, oFolder.Name);
       currentNode.Data := Pointer(oFolder);
       ExpandFolders(oFolder.SubFolderList, currentNode);
       currentNode.Expand(true);
  end;
end;
   
//----------------------------------------------------------------------
// End Region: Show server folders and expand folders.
//----------------------------------------------------------------------

//-------------------------------------------------------------------------------
// Region: Add, delete, rename folders
// ------------------------------------------------------------------------------
function TForm1.GetSelectedFolderNode(includeRoot: Boolean): TTreeNode;
var
  selectedNode: TTreeNode;
begin
  result := nil;
  selectedNode := trFolder.Selected;
  if selectedNode = nil then
    exit;

   if (not includeRoot) and (selectedNode.Parent = nil) then
    exit; 

    result := selectedNode;
end;

procedure TForm1.PopupMenu1Popup(Sender: TObject);
begin
    if GetSelectedFolderNode(true) = nil Then
      exit;

    
    AddFolder.Enabled := (not m_isWorking);
    DeleteFolder.Enabled := (not m_isWorking);
    RefreshFolders.Enabled := (not m_isWorking);
    RenameFolder.Enabled := (not m_isWorking);
    RefreshMails.Enabled := (not m_isWorking);
    
end;

procedure TForm1.AddFolderClick(Sender: TObject);
var
  formAddFolder: TFormFolder;
  selectedNode, newNode: TTreeNode;
  folderName: WideString;
  oParentFolder, oFolder: IImap4Folder;
begin
  formAddFolder := TFormFolder.Create(Application);
  if formAddFolder.ShowModal() <> mrOK then
    exit;

  folderName := formAddFolder.textFolder.Text;
  selectedNode := trFolder.Selected;
  oParentFolder := nil;

  if selectedNode <> nil then
    if selectedNode.Parent <> nil then
      oParentFolder := IImap4Folder(selectedNode.Data);

  try
    
    PrepareWork();
    ConnectServerOnDemand();

    oFolder := oClient.CreateFolder(oParentFolder, folderName);

    newNode := trFolder.Items.AddChild(selectedNode, folderName);
    newNode.Data := Pointer(oFolder);

    if selectedNode <> nil then
      selectedNode.Expand(true);

    EndWork();
  except
    on ep:Exception do
    begin
      AfterError(ep);
    end;
  end;

end;

procedure TForm1.RenameFolderClick(Sender: TObject);
var
  selectedNode: TTreeNode;
begin
  selectedNode := GetSelectedFolderNode(false);
  if selectedNode <> nil then
    selectedNode.EditText();

  m_isWorking := true;  
end;

procedure TForm1.trFolderEdited(Sender: TObject; Node: TTreeNode; var S: String);
var
  oFolder: IImap4Folder;
  folder, newFolder: WideString;
begin

  try
    PrepareWork();
    ConnectServerOnDemand();

    oFolder := IImap4Folder(Node.Data);
    folder := m_currentPath + '\' + oCurServer.Server + '\' + oCurServer.User +
    '\' + oFolder.LocalPath;
    
    oClient.RenameFolder(oFolder, S);
    Node.Text := S;

    newFolder := m_currentPath + '\' + oCurServer.Server + '\' + oCurServer.User +
    '\' + oFolder.LocalPath;

    oTools.RenameFile(folder, newFolder);
    EndWork();
  except
    on ep:Exception do
      begin
        Node.EndEdit(true);
        S := Node.Text;

        AfterError(ep);
      end;
  end;

end;

procedure TForm1.DeleteFolderClick(Sender: TObject);
var
  selectedNode: TTreeNode;
  oFolder: IImap4Folder;
  folder: WideString;
begin
  selectedNode := GetSelectedFolderNode(false);
  if selectedNode = nil then
    exit;

 try
    PrepareWork();
    ConnectServerOnDemand();

    oFolder := IImap4Folder(selectedNode.Data);
    folder := m_currentPath + '\' + oCurServer.Server + '\' + oCurServer.User +
    '\' + oFolder.LocalPath;
    
    oClient.DeleteFolder(oFolder);

    lstMail.Items.Clear();
    trFolder.Items.Delete(selectedNode);
    
    // remove local folder
    oTools.RemoveFolder(folder, true);

    EndWork();
  except
    on ep:Exception do
      begin
        AfterError(ep);
      end;
  end;

end;

// refresh folders
procedure TForm1.RefreshFoldersClick(Sender: TObject);
begin

  try
    PrepareWork();
    ConnectServerOnDemand();
    
    lstMail.Items.Clear();
    oClient.RefreshFolders();
    ShowAllFolders();
    
    EndWork();
  except
    on ep:Exception do
      begin
        AfterError(ep);
      end;
  end;

end;

//-------------------------------------------------------------------------------
// End Region: Add, delete, rename folders
// ------------------------------------------------------------------------------

//---------------------------------------------
// List emails of selected folder
//----------------------------------------------

function TForm1.SelectedCounts(): integer;
begin
  result := lstMail.SelCount;
end;

procedure TForm1.trFolderChange(Sender: TObject; Node: TTreeNode);
begin
  if Node.Parent = nil then
  begin
    lstMail.Items.Clear();
    textStatus.SimpleText := 'Root';
    exit;
  end;

  try
    PrepareWork();
    ConnectServerOnDemand();

    LoadServerMails(Node);

    EndWork();
  except
    on ep:Exception do
      begin
        AfterError(ep);
      end;
  end;
end;

procedure TForm1.LoadServerMails(folderNode: TTreeNode);
var
  oFolder: IImap4Folder;
  folder: WideString;
  
  mailInfos: IMailInfoCollection;
  oInfo: IMailInfo;

  i: integer;
  oUIDLItem: IUIDLItem;

  emailHeaderFile, fullEmailHeaderFile: WideString;
  oMail: TMail;
  
  isUidlLoaded: Boolean;
begin

  lstMail.Items.Clear();
  oFolder := IImap4Folder(folderNode.Data);

  if oFolder.NoSelect then
  begin
    folderNode.Expand(true);
    exit;
  end;

  isUidlLoaded := false;

  try
    folder := m_currentPath + '\' + oCurServer.Server + '\' + oCurServer.User +
    '\' + oFolder.LocalPath;

    CreateFullFolder(folder);
    oUIDLManager.Load(folder + '\uidl.txt');
    isUidlLoaded := true;

    textStatus.SimpleText := 'Refreshing email(s) ...';
    SetMailRange();
    mailInfos := oClient.GetMailInfoList();

    If lstDateRange.ItemIndex = 4 Then
    begin
      // Remove the local uidl which is not existed on the server.
      // we only synchronize it with uidl of all emails in current mail folder
      // Remove the local uidl which is not existed on the server.
      oUIDLManager.SyncUIDLEX(oCurServer.DefaultInterface, mailInfos);
      oUIDLManager.Update();
    end;

    for i:= 0 to mailInfos.Count - 1 do
    begin

      oInfo := mailInfos.Item[i];
      // Retrieve email headers only to display the summary, if the email headers file is existed, load it directly.
      oUIDLItem := oUIDLManager.FindUIDL(oCurServer.DefaultInterface, oInfo.UIDL);
      if oUIDLItem = nil then
        begin
          // Current email headers has not been downloaded, generate a new file to store email headers
          emailHeaderFile := oTools.GenFileName(i) + '.eml';
          fullEmailHeaderFile := folder + '\' + emailHeaderFile;
        end
      else
        begin
          // Get existed email headers file from existed email headers file.
          fullEmailHeaderFile := folder + '\' + oUIDLItem.FileName;
        end;

      textStatus.SimpleText := Format('Retrieve headers of %d/%d ...', [i + 1, mailInfos.Count]);
      
      oMail := TMail.Create(Application);
      oMail.LicenseCode := 'TryIt';

      pgBar.Position := 0;

      if oTools.ExistFile(fullEmailHeaderFile) then
        oMail.LoadFile(fullEmailHeaderFile, false)
      else
        begin
          // Download email headers and save it to local disk
          oMail.Load(oClient.GetMailHeader(oInfo));
          oMail.SaveAs(fullEmailHeaderFile, true);
        end;

      pgBar.Position := pgBar.Max;
      AddNewMailToListMail(oMail, oInfo);
      
      if oUIDLItem = nil then
      begin
        // Add UIDL to prevent to download it at next time again.
        oUIDLManager.AddUIDL(oCurServer.DefaultInterface, oInfo.UIDL, emailHeaderFile);
      end;
      

      // Remove the email on local disk which is not existed on server
      ClearLocalMails(folder);
      oUIDLManager.Update();

    end;
    
    textStatus.SimpleText := Format('Total %d email(s)', [lstMail.Items.Count]);

  except
    on ep:Exception do
    begin
      if isUidlLoaded then
        oUIDLManager.Update();
        
      textStatus.SimpleText := Format('Total %d email(s)', [lstMail.Items.Count]);
      Raise;
    end;
  end;
  
end;

function TForm1.AddNewMailToListMail(oMail: TMail; oInfo: IMailInfo): TListItem;
var
  item: TListItem;
begin
  item := TListItem.Create(lstMail.Items);

  item.SubItems.Add(oMail.Subject);
  item.SubItems.Add(FormatDateTime('yyyy-MM-dd hh:mm:ss', oMail.ReceivedDate));
  // item.SubItems.Add(fileName);
  item.Data := Pointer(oInfo);

  lstMail.Items.AddItem(item);
  item.Caption := oMail.From.Address;
  item.Update();

  result := item;
end;

procedure TForm1.RefreshMailsClick(Sender: TObject);
var
  folderNode: TTreeNode;
begin
  
  folderNode := GetSelectedFolderNode(false);
  if folderNode = nil then
    exit;

  try
    PrepareWork();
    ConnectServerOnDemand();

    oClient.RefreshMailInfos();
    LoadServerMails(folderNode);
   
    EndWork();

  except
    on ep:Exception do
      begin
        AfterError(ep);
      end;
  end;

end;

//----------------------------------------------------
// Copy email to another folder
//----------------------------------------------------
function TForm1.GetDestFolder(): IImap4Folder;
var
  formSelectFolder: TFormSelectFolder;
  destNode: TTreeNode;
begin
  formSelectFolder := TFormSelectFolder.Create(Application);
  formSelectFolder.OriginalSelectedForlder := m_selectedFolderPath;

  destNode := formSelectFolder.trFolder.Items.Add(nil, 'Root');
  CopyNodes(trFolder.Items.GetFirstNode(), formSelectFolder.trFolder, destNode);
  destNode.Expand(true);

  if formSelectFolder.ShowModal() <> mrOK then
    exit;
  
  result := IImap4Folder(formSelectFolder.trFolder.Selected.Data);
end;

procedure TForm1.CopyNodes(sourceNode: TTreeNode; destRoot:TTreeView; destNode: TTreeNode);
var
  child: TTreeNode;
  newNode: TTreeNode;
begin
  child := sourceNode.GetFirstChild();
  if child = nil then
    exit;

  repeat
    newNode := destRoot.Items.AddChild(destNode, child.Text);
    newNode.Data := child.Data;
    newNode.Expand(true);

    CopyNodes(child, destRoot, newNode);

    child := child.GetNextSibling();
  until (child = nil);
end;

//------------------------------------------
// Copy selected email to another folder
//------------------------------------------
procedure TForm1.btnCopyClick(Sender: TObject);
var
  oInfo: IMailInfo;
  oDest: IImap4Folder;
  item: TListItem;
  i: integer;
begin
  oDest := GetDestFolder();
  if oDest = nil then
    exit;

  if SelectedCounts() < 1 then
    exit;

  try
    PrepareWork();
    ConnectServerOnDemand();

    i := 0;
    while i < lstMail.Items.Count do
      begin
        item := lstMail.Items[i];
        if not item.Selected then
          begin
            i := i + 1;
            continue;
          end;

        oInfo := IMailInfo(item.Data);
        oClient.Copy(oInfo, oDest);
        i := i + 1;
      end;

    EndWork();
  except
    on ep:Exception do
    begin
      AfterError(ep);
    end;
  end;

end;

//------------------------------------------
// Move selected email to another folder
//------------------------------------------
procedure TForm1.btnMoveClick(Sender: TObject);
var
  oInfo: IMailInfo;
  oDest: IImap4Folder;
  item: TListItem;
  i: integer;
begin
  oDest := GetDestFolder();
  if oDest = nil then
    exit;

  if SelectedCounts() < 1 then
    exit;

  try
    PrepareWork();
    ConnectServerOnDemand();

    i := 0;
    while i < lstMail.Items.Count do
      begin
        item := lstMail.Items[i];
        if not item.Selected then
          begin
            i := i + 1;
            continue;
          end;

        oInfo := IMailInfo(item.Data);
        oClient.Move(oInfo, oDest);
        lstMail.Items.Delete(i);
      end;

    if oCurServer.Protocol = MailServerImap4 then
      oClient.Expunge();

    EndWork();    
  except
    on ep:Exception do
      begin
        AfterError(ep);
      end;
  end;

end;

//--------------------------------------------------------------
// Expunge deleted emails from server, only IMAP4 support it.
//--------------------------------------------------------------
procedure TForm1.btnExpungeClick(Sender: TObject);
var
  folderNode: TTreeNode;
begin
  if (oCurServer.Protocol = MailServerEWS) Or
    (oCurServer.Protocol = MailServerDAV) then
    exit;
        
  folderNode := GetSelectedFolderNode(false);
  if folderNode = nil then 
    exit;
  
  try
    PrepareWork();
    ConnectServerOnDemand();

    oClient.Expunge();
    LoadServerMails(folderNode);

    EndWork();
  except
    on ep:Exception do
      begin
        AfterError(ep);
      end;
  end;

end;

//----------------------------------------
// Mark email as unread
//-----------------------------------------
procedure TForm1.btnUnreadClick(Sender: TObject);
var
  oInfo: IMailInfo;
  item: TListItem;
  i: integer;
begin
  
  if SelectedCounts() < 1 then
    exit;

  try
    PrepareWork();
    ConnectServerOnDemand();

    i := 0;
    while i < lstMail.Items.Count do
    begin
      item := lstMail.Items[i];
      if not item.Selected then
      begin
        i := i+1;
        continue;
      end;

      oInfo := IMailInfo(item.Data);
      if oInfo.Read  then
        oClient.MarkAsRead(oInfo,  false);

      i := i+1;
      item.Update();
    end;

    Endwork();
  except
    on ep:Exception do
      begin
        AfterError(ep);
      end;
  end;
  
end;

//---------------------------------------------------------
// Mark deleted email as undeleted, only IMAP4 support this
//---------------------------------------------------------
procedure TForm1.btnUndeleteClick(Sender: TObject);
var
  oInfo: IMailInfo;
  item: TListItem;
  i: integer;
begin
 
  if SelectedCounts() < 1 then
    exit;

  if (oCurServer.Protocol = MailServerEWS) Or
    (oCurServer.Protocol = MailServerDAV) then
    exit;

  try
    PrepareWork();
    ConnectServerOnDemand();

    i := 0;
    while i < lstMail.Items.Count do
      begin
        item := lstMail.Items[i];
        if not item.Selected then
        begin
          i := i+1;
          continue;
        end;

        oInfo := IMailInfo(item.Data);
        if oInfo.Deleted then
          oClient.Undelete(oInfo);

        i := i + 1;
        item.Update();
      end;

    EndWork();
  except
    on ep:Exception do
      begin
        AfterError(ep);
      end;
  end;

end;

//-----------------------------------------------------------------------------------------------
// Delete email, it only marks email as deleted in IMAP, use Expunge to expunge email from server
//------------------------------------------------------------------------------------------------
procedure TForm1.btnDelClick(Sender: TObject);
var
  oInfo: IMailInfo;
  item: TListItem;
  i: integer;
begin
  
  if SelectedCounts() < 1 then
    exit;

  try
    PrepareWork();
    ConnectServerOnDemand();
    
    i := 0;
    while i < lstMail.Items.Count do
      begin
        item := lstMail.Items[i];
        if not item.Selected then
          begin
            i := i+1;
            continue;
          end;

        oInfo := IMailInfo(item.Data);
        oClient.Delete(oInfo);
        lstMail.Items.Delete(i)

      end;

    if oCurServer.Protocol = MailServerImap4 then
      oClient.Expunge();

    EndWork();
  except
    on ep:Exception do
      begin
        AfterError(ep);
      end;
  end;

end;

//-----------------------------------------------------------------------------------------------
// Upload email file to server
//------------------------------------------------------------------------------------------------
procedure TForm1.btnUploadClick(Sender: TObject);
var
  pFileDlg: TOpenDialog;
  fileName: WideString;
  oNode: TTreeNode;
  oMail: TMail;
  oFolder: IImap4Folder;
begin
  oNode := GetSelectedFolderNode(false);
  if(oNode = nil) then
    exit;

  pFileDlg := TOpenDialog.Create(Form1);
  pFileDlg.Filter := 'Email File (*.eml)|*.EML';
  if not pFileDlg.Execute() then
  begin
    pFileDlg.Destroy();
    Exit;
  end;

  fileName := pFileDlg.FileName;
  pFileDlg.Destroy();

  try
    PrepareWork();
    ConnectServerOnDemand();

    oMail := TMail.Create(Application);
    oMail.LicenseCode := 'TryIt';
    oMail.LoadFile(fileName,  false);

    oFolder := IImap4Folder(oNode.Data);
    
    oClient.Append(oFolder, oMail.Content);
    oClient.RefreshMailInfos();
    LoadServerMails(oNode);
    
    Endwork();
   except
    on ep:Exception do
      begin
        AfterError(ep);
      end;
  end;

end;

//-----------------------------------------------------------------------------------------------
// Create local folder recursively
//------------------------------------------------------------------------------------------------
procedure TForm1.CreateFullFolder(folder: WideString);
var
  s: WideString;
  npos: integer;
begin
    if oTools.ExistFile(folder) then
        Exit;

    npos := 1;
    while true do
    begin
      npos := PosEx('\', folder, npos);
      if npos > 3 then
      begin
        s := MidStr(folder, 1, npos - 1);
        if not oTools.ExistFile(s) then
          oTools.CreateFolder(s);

      end
      else if npos < 1 then
        Break;

      npos := npos + 1;
    end;

    if Not oTools.ExistFile(folder) then
      oTools.CreateFolder(folder);  
end;

//-----------------------------------------------------------------
//  Region: Parse and display emails
//------------------------------------------------------------------

function TForm1.EmlFileToHtmlRenderPath(filePath: WideString): WideString;
begin
  result := LeftStr(filePath, length(filePath) - 4) + '.html';
end;
  
function TForm1.GetAttachmentTempFolder(filePath: WideString): WideString;
begin
  result := LeftStr(filePath, length(filePath) - 4);
end;

procedure TForm1.lstMailSelectItem(Sender: TObject; Item: TListItem; Selected: Boolean);
var
  fileName, folder, tempFolder, htmlFile: WideString;
  folderNode: TTreeNode;
  oFolder: IImap4Folder;
  oInfo: IMailInfo;
  oUIDLItem: IUIDLItem;
  oMail: IMail;
  OriginalStatus: WideString;
begin
    
  folderNode := GetSelectedFolderNode(false);
  if folderNode = nil then
    exit;

  if (SelectedCounts() <> 1) or (m_isWorking) then
    exit;

  OriginalStatus := textStatus.SimpleText;
  
  try
    PrepareWork();
    oFolder := IImap4Folder(folderNode.Data);
    oInfo := IMailInfo(Item.Data);

    folder := m_currentPath + '\' + oCurServer.Server + '\' + oCurServer.User +
    '\' + oFolder.LocalPath;

    oUIDLItem := oUIDLManager.FindUIDL(oCurServer.DefaultInterface, oInfo.UIDL);
    if oUIDLItem = nil then
    begin
      // should never happen except you delete the file from the folder manually.
      ShowMessage('No email file found');
      EndWork();
      exit;
    end;

    // Get the local file name for this email UIDL
    fileName := folder + '\' + oUIDLItem.fileName;
    htmlFile := EmlFileToHtmlRenderPath(fileName);
    tempFolder := GetAttachmentTempFolder(fileName);

    // only mail header is retrieved, now retrieve full content of mail.
    if not oTools.ExistFile(htmlFile) then
    begin
      textStatus.SimpleText := 'Downloading email ...';
      pgBar.Position := 0;

      oMail := oClient.GetMail(oInfo);
      oMail.SaveAs(fileName, true);

      pgBar.Position := pgBar.Max;
    end;

    if not oInfo.Read then
      oClient.MarkAsRead(oInfo, true);

    textStatus.SimpleText := OriginalStatus;
    ShowMail(fileName);

    Endwork();
  except
    on ep:Exception do
      begin
        AfterError(ep);
      end;
  end;

end;

procedure TForm1.ShowMail(fileName: WideString);
var
  htmlFile: WideString;
begin
  htmlFile := EmlFileToHtmlRenderPath(fileName);
  if not oTools.ExistFile(htmlFile) then
    begin
      // We haven't generated the html for this email, generate it now.
      GenerateHtmlForEmail(htmlFile, fileName);
    end;

  webMail.Navigate(htmlFile);
end;

function TForm1.FormatAddresses(addresses: IAddressCollection; prefix: WideString): WideString;
var
  value: WideString;
  i: integer;
begin
    if addresses.Count = 0 then
      begin
        result := '';
        exit;
      end;

    
    value := '<b>' + prefix + ':</b> '; // To or Cc
    
    for i := 0 to addresses.Count - 1 do
      begin
        if(addresses.Item[i].Name = '') then
          value := value + '&lt;' + addresses.Item[i].Address + '&gt;'
        else
          value := value + addresses.Item[i].Name + ' &lt;' + addresses.Item[i].Address + '&gt;';
          
        if (i < addresses.Count - 1) then
            value := value + '; ';
      end;
    
    result := value + '<br>';
end;

//----------------------------------------------------------------------------------------
// Generate a html + temporal attachment folder for every email, once the html is created,
// next time we don't need to parse the email again.
//----------------------------------------------------------------------------------------
procedure TForm1.GenerateHtmlForEmail(htmlFile: WideString; emlFile: WideString);
var
  oMail: TMail;
  attachments: IAttachmentCollection;
  oAttachment: IAttachment;
  i: integer;
  html, header, attachmentName, tempFolder: WideString;
begin
  
  oMail := TMail.Create(Application);
  oMail.LicenseCode := 'TryIt';

  oMail.LoadFile(emlFile, false);

  try
    if oMail.IsEncrypted then
      oMail.Load(oMail.Decrypt(nil).Content);
  except
    on ep:Exception do
      ShowMessage('Decrypt Error: ' + ep.Message);
  end;

  try
    if oMail.IsSigned then
      oMail.VerifySignature();
  except
    on ep:Exception do
      ShowMessage('Verify Digital Signature Error: ' + ep.Message);
  end;

  // Decode winmail.dat (TNEF stream) automatically.
  // also convert RTF body to HTML automatically.
  oMail.DecodeTNEF(); 

  html := oMail.HtmlBody;
  header := header + '<font face="Courier New,Arial" size="2">';
  header := header + '<b>From:</b> ' + oMail.From.Name + ' &lt;' + oMail.From.Address + '&gt;' + '<br>';

  header := header + FormatAddresses(oMail.ToList, 'To');
  header := header + FormatAddresses(oMail.CcList, 'Cc');
  header := header + '<b>Subject:</b>' + oMail.Subject + '<br>' + #13#10;

  // Parse attachment
  attachments := oMail.AttachmentList;
  if(attachments.Count > 0) then
    begin
    
      // Create a temporal folder to store attachments.
      tempFolder := GetAttachmentTempFolder(emlFile);
      if not oTools.ExistFile(tempFolder) then
        oTools.CreateFolder(tempFolder);

      header := header + '<b>Attachments:</b> ';
      for i:= 0 to attachments.Count - 1 do
        begin
          oAttachment := attachments.Item[i];

          attachmentName := tempFolder + '\' + oAttachment.Name;
          oAttachment.SaveAs(attachmentName, true);
          header := header + '<a href="' + attachmentName + '" target="_blank">' + oAttachment.Name + '</a> ';

            // Show embedded images
          if oAttachment.ContentID <> '' then
            begin
              // StringReplace doesn't support some non-ascii characters very well.
              html := StringReplace(html, 'cid:' + oAttachment.ContentID, attachmentName, [rfReplaceAll, rfIgnoreCase]);
            end
          
        end;
    end;

  header := '<meta http-equiv="Content-Type" content="text-html; charset=utf-8">' + header;
  html := header + '<hr>' + html;
  oTools.WriteTextFile(htmlFile, html, 65001);

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

procedure TForm1.lstMailAdvancedCustomDrawItem(Sender: TCustomListView;
  Item: TListItem; State: TCustomDrawState; Stage: TCustomDrawStage;
  var DefaultDraw: Boolean);
var
  oInfo: IMailInfo;
begin
  if item.Data = nil then
    exit;

  oInfo := IMailInfo(item.Data);
  if not oInfo.Read then
    Sender.Canvas.Font.Style := Sender.Canvas.Font.Style + [fsBold]
  else
    Sender.Canvas.Font.Style := Sender.Canvas.Font.Style - [fsBold];

  if oInfo.Deleted then
    Sender.Canvas.Font.Style := Sender.Canvas.Font.Style +  [fsStrikeOut]
  else
    Sender.Canvas.Font.Style := Sender.Canvas.Font.Style -  [fsStrikeOut];

end;

procedure TForm1.ClearLocalMails(folder: WideString);
var
  files: OleVariant;
  i, UBound: integer;
  fileName, shortName: WideString;
  nPos: integer;
  bFind: bool;
  htmlFile, tempFolder: WideString;
begin
  files := oTools.GetFiles(folder + '\*.eml');
  UBound := VarArrayHighBound(files, 1);
  for i:= 0 to UBound do
    begin
      fileName := WideString(VarArrayGet(files, i));
      shortName := fileName;
      while true do
        begin
          nPos := Pos( '\', shortName);
          if nPos < 1 then
            break;

          shortName := MidStr(shortName, nPos+1, length(shortName) - nPos);
        end;

      bFind :=  false;
      if oUIDLManager.FindLocalFile(shortName) <> nil then
        bFind := true;

      if Not bFind then
        begin
          oTools.RemoveFile(fileName);

          htmlFile := EmlFileToHtmlRenderPath(fileName);
          tempFolder := GetAttachmentTempFolder(fileName);

          if oTools.ExistFile(htmlFile) then
            oTools.RemoveFile(htmlFile);

          if oTools.ExistFile(tempFolder) then
            oTools.RemoveFolder(tempFolder, true);

        end;
        
    end;
end;
//=============================================================================================
// End Region: Parse and display emails
//=============================================================================================

//-----------------------------------------------------------------------------------------------
// Enable button based on current status
//------------------------------------------------------------------------------------------------
procedure TForm1.EnableControlDynamic();
var
  isFolderSelected: Boolean;
  selectMailCount: integer;
begin

  selectMailCount := SelectedCounts();
  isFolderSelected := (GetSelectedFolderNode(false) <> nil);

  trFolder.Enabled := (not m_isWorking);
  lstMail.Enabled := (not m_isWorking);
  btnDel.Enabled := ((not m_isWorking) and (isFolderSelected) and (selectMailCount > 0));

  if lstProtocol.ItemIndex + ProtocolOffset = MailServerImap4 then
    begin
      btnUndelete.Enabled := ((not m_isWorking) and (isFolderSelected) and (selectMailCount > 0));
      btnExpunge.Enabled := ((not m_isWorking) and (isFolderSelected));
    end
  else
    begin
      btnUndelete.Enabled := false;
      btnExpunge.Enabled := false;
    end;

  btnMove.Enabled := ((not m_isWorking) and (isFolderSelected) and (selectMailCount > 0));
  btnCopy.Enabled := ((not m_isWorking) and (isFolderSelected) and (selectMailCount > 0));

  btnUpload.Enabled := ((not m_isWorking) and (isFolderSelected));
  btnUnread.Enabled := ((not m_isWorking) and (isFolderSelected) and (selectMailCount > 0));

end;

// --------------------------------------------------------------------------------------
// Region: EAGetMail event handler
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

procedure TForm1.OnAuthorized(ASender: TObject; const oSender: IDispatch; var Cancel: WordBool);
begin
  textStatus.SimpleText := 'Authorized';
  Cancel := m_bCancel;
end;

procedure TForm1.OnSendingDataStream(ASender: TObject; const oSender: IDispatch; Sent: Integer; Total: Integer; var Cancel: WordBool);
begin
  pgBar.Max := Total;
  pgBar.Min := 0;
  pgBar.Position := Sent;
  Cancel := m_bCancel;
end;

procedure TForm1.OnReceivingDataStream(ASender: TObject; const oSender: IDispatch; const oInfo: IDispatch; Received: Integer; Total: Integer; var Cancel: WordBool);
begin
  pgBar.Max := Total;
  pgBar.Min := 0;
  pgBar.Position := Received;
  Cancel := m_bCancel;
end;
// --------------------------------------------------------------------------------------
// End Region: EAGetMail event handler
// ---------------------------------------------------------------------------------------


end.
