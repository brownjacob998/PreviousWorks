program Project1;

uses
  Forms,
  Unit1 in 'Unit1.pas' {Form1},
  EAGetMailObjLib_TLB in 'EAGetMailObjLib_TLB.pas',
  FormOauth in 'FormOauth.pas' {FormOauth},
  MSXML2_TLB in 'MSXML2_TLB.pas',
  GoogleOauthWrapper in 'GoogleOauthWrapper.pas';
  
{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.
