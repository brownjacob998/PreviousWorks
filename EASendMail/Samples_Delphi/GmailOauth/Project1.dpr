program Project1;

uses
  Forms,
  Unit1 in 'Unit1.pas' {Form1},
  EASendMailObjLib_TLB in 'EASendMailObjLib_TLB.pas',
  Unit2 in 'Unit2.pas' {Form2},
  MSXML2_TLB in 'MSXML2_TLB.pas',
  GoogleOauthWrapper in 'GoogleOauthWrapper.pas';

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.CreateForm(TForm2, Form2);
  Application.Run;
end.
