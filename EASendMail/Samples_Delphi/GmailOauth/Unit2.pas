unit Unit2;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, OleCtrls, SHDocVw, MSHTML, GoogleOauthWrapper;

type
  TForm2 = class(TForm)
    webOAUTH: TWebBrowser;
    procedure webOAUTHDocumentComplete(Sender: TObject;
      const pDisp: IDispatch; var URL: OleVariant);
    procedure FormShow(Sender: TObject);
  private
         {private declare}

  public
    Oauth: TGoogleOauthWrapper;

  end;

var
  Form2: TForm2;

implementation

{$R *.dfm}

procedure TForm2.webOAUTHDocumentComplete(Sender: TObject;
  const pDisp: IDispatch; var URL: OleVariant);
var
  htmlDoc: HTMLDocument;
  htmlInput: IHtmlInputElement;
  code: string;
begin

  htmlDoc := webOAUTH.Document as HTMLDocument;
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

procedure TForm2.FormShow(Sender: TObject);
var
  authURI: string;
begin

  authURI := Oauth.GetFullAuthUri();
  webOAUTH.Navigate(authURI);
end;


end.
 