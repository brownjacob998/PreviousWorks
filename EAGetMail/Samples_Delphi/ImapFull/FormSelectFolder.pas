unit FormSelectFolder;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ComCtrls, EAGetMailObjLib_TLB;

type
  TFormSelectFolder = class(TForm)
    trFolder: TTreeView;
    btnOK: TButton;
    btnCancel: TButton;
    procedure btnOKClick(Sender: TObject);
    procedure btnCancelClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
    OriginalSelectedForlder: WideString;
  end;

var
  FormSelectFolder1: TFormSelectFolder;

implementation

{$R *.dfm}

procedure TFormSelectFolder.btnOKClick(Sender: TObject);
var
  oNode: TTreeNode;
  oFolder: IImap4Folder;
begin
  oNode := trFolder.Selected;
  if oNode = nil then
  begin
    ShowMessage( 'Please select a folder!');
    exit;
  end;

  if oNode.Parent = nil then
  begin
    ShowMessage( 'Please select a folder!');
    exit;
  end;

  oFolder := IImap4Folder(oNode.Data);
  if (oFolder <> nil) and (oFolder.ServerPath = OriginalSelectedForlder) then
    begin
      ShowMessage( 'Please select a folder different than original folder!');
      exit;
    end;


  ModalResult := mrOK;
end;

procedure TFormSelectFolder.btnCancelClick(Sender: TObject);
begin
  ModalResult := mrCancel;
end;

end.
