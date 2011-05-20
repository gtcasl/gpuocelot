program mcxstudio;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Interfaces, // this includes the LCL widgetset
  Forms
  { you can add units after this }, mcxgui, LResources, mcxabout;

{$IFDEF WINDOWS}{$R mcxstudio.rc}{$ENDIF}

begin
  Application.Title:='MCX Studio';
  {$I mcxstudio.lrs}
  Application.Initialize;
  Application.CreateForm(TfmMCX, fmMCX);
  Application.Run;
end.

