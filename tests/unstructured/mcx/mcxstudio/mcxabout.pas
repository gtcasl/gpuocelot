unit mcxabout;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, LResources, Forms, Controls, Graphics, Dialogs,
  StdCtrls, Buttons, ExtCtrls;

type

  { TfmAbout }

  TfmAbout = class(TForm)
    Button1: TButton;
    Image1: TImage;
    Label1: TLabel;
    procedure Image1Click(Sender: TObject);
  private
    { private declarations }
  public
    { public declarations }
  end; 

var
  fmAbout: TfmAbout;

implementation

{ TfmAbout }

procedure TfmAbout.Image1Click(Sender: TObject);
begin

end;

initialization
  {$I mcxabout.lrs}

end.

