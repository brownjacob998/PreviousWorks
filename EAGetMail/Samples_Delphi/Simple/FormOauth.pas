unit FormOauth;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, OleCtrls, SHDocVw, MSHTML, GoogleOauthWrapper;

type
  TFormOauth = class(TForm)
    OauthBrowser: TWebBrowser;
    procedure OauthBrowserDocumentComplete(Sender: TObject;
      const pDisp: IDispatch; var URL: OleVariant);
    procedure FormShow(Sender: TObject);
  private
         {private declare}

  public
    Oauth: TGoogleOauthWrapper;

  end;

var
  FormOauth1: TFormOauth;

implementation

{$R *.dfm}

procedure TFormOauth.FormShow(Sender: TObject);
var
  authURI: string;
begin

  authURI := Oauth.GetFullAuthUri();
  OauthBrowser.Navigate(authURI);
end;

procedure TFormOauth.OauthBrowserDocumentComplete(Sender: TObject;
  const pDisp: IDispatch; var URL: OleVariant);
var
  htmlDoc: HTMLDocument;
  htmlInput: IHtmlInputElement;
  code: string;
begin

  htmlDoc := OauthBrowser.Document as HTMLDocument;
  htmlInput := htmlDoc.getElementById('code') as IHtmlInputElement;
  if htmlInput = nil then
    exit;

  code := htmlInput.value;
  if code <> '' then
  begin
    Oauth.AuthorizationCode := code;
    ModalResult := mrOK;
  end;

end;

end.
 