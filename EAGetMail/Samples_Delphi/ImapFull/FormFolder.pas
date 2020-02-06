unit FormFolder;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls;

type
  TFormFolder = class(TForm)
    Label1: TLabel;
    textFolder: TEdit;
    btnOK: TButton;
    btnCancel: TButton;
    procedure btnCancelClick(Sender: TObject);
    procedure btnOKClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  FormFolder1: TFormFolder;

implementation

{$R *.dfm}

procedure TFormFolder.btnCancelClick(Sender: TObject);
begin
  
  ModalResult := mrCancel;
end;

procedure TFormFolder.btnOKClick(Sender: TObject);
begin
  if textFolder.Text = '' then
  begin
    ShowMessage( 'Please input folder name!' );
    exit;
  end;

  ModalResult := mrOK;
end;

end.
