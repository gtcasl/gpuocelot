unit mcxgui;
{==============================================================================
    Monte Carlo eXtreme (MCX) Studio
-------------------------------------------------------------------------------
    Author: Qianqian Fang
    Email : fangq at nmr.mgh.harvard.edu
    Web   : http://mcx.sourceforge.net
    License: GNU General Public License version 3 (GPLv3)
===============================================================================}
{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, process, FileUtil, LResources, Forms, Controls,
  Graphics, Dialogs, StdCtrls, Menus, ComCtrls, ExtCtrls, Spin,
  EditBtn, Buttons, ActnList, lcltype, AsyncProcess,
  inifiles, mcxabout;

type

  { TfmMCX }

  TfmMCX = class(TForm)
    mcxdoHelpOptions: TAction;
    Bevel1: TBevel;
    Bevel2: TBevel;
    ckSaveDetector: TCheckBox;
    ckAutopilot: TCheckBox;
    edGPUID: TComboBox;
    edDetectedNum: TEdit;
    edUnitInMM: TEdit;
    grVariant: TRadioGroup;
    Label12: TLabel;
    Label8: TLabel;
    Label9: TLabel;
    MenuItem19: TMenuItem;
    mmOutput: TMemo;
    OpenProject: TOpenDialog;
    plOutput: TPanel;
    pMCX: TAsyncProcess;
    edBlockSize: TComboBox;
    Label11: TLabel;
    mcxSetCurrent: TAction;
    acInteract: TActionList;
    mcxdoDefault: TAction;
    mcxdoClearLog: TAction;
    mcxdoSave: TAction;
    mcxdoExit: TAction;
    mcxdoListGPU: TAction;
    mcxdoQuery: TAction;
    mcxdoWeb: TAction;
    mcxdoAbout: TAction;
    mcxdoHelp: TAction;
    mcxdoRunAll: TAction;
    mcxdoStop: TAction;
    mcxdoRun: TAction;
    mcxdoVerify: TAction;
    mcxdoDeleteItem: TAction;
    mcxdoAddItem: TAction;
    mcxdoOpen: TAction;
    mcxdoInitEnv: TAction;
    acMCX: TActionList;
    ckReflect: TCheckBox;
    ckSaveData: TCheckBox;
    ckNormalize: TCheckBox;
    edThread: TComboBox;
    edPhoton: TEdit;
    edSession: TEdit;
    edBubble: TEdit;
    edConfigFile: TFileNameEdit;
    ImageList1: TImageList;
    Label1: TLabel;
    Label10: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    Label6: TLabel;
    Label7: TLabel;
    lvJobs: TListView;
    MainMenu1: TMainMenu;
    MenuItem17: TMenuItem;
    MenuItem18: TMenuItem;
    MenuItem1: TMenuItem;
    MenuItem10: TMenuItem;
    MenuItem11: TMenuItem;
    MenuItem12: TMenuItem;
    MenuItem13: TMenuItem;
    MenuItem14: TMenuItem;
    MenuItem15: TMenuItem;
    MenuItem16: TMenuItem;
    MenuItem2: TMenuItem;
    MenuItem3: TMenuItem;
    MenuItem4: TMenuItem;
    MenuItem5: TMenuItem;
    MenuItem6: TMenuItem;
    MenuItem7: TMenuItem;
    MenuItem8: TMenuItem;
    MenuItem9: TMenuItem;
    plSetting: TPanel;
    grArray: TRadioGroup;
    edRespin: TSpinEdit;
    edGate: TSpinEdit;
    pExternal: TProcess;
    PopupMenu1: TPopupMenu;
    SaveProject: TSaveDialog;
    Splitter1: TSplitter;
    Splitter2: TSplitter;
    sbInfo: TStatusBar;
    tbtRun: TToolButton;
    tbtRunAll: TToolButton;
    tbtStop: TToolButton;
    tbtVerify: TToolButton;
    ToolBar1: TToolBar;
    ToolButton1: TToolButton;
    ToolButton10: TToolButton;
    ToolButton11: TToolButton;
    ToolButton12: TToolButton;
    ToolButton13: TToolButton;
    ToolButton14: TToolButton;
    ToolButton15: TToolButton;
    ToolButton16: TToolButton;
    ToolButton17: TToolButton;
    ToolButton18: TToolButton;
    ToolButton19: TToolButton;
    ToolButton2: TToolButton;
    ToolButton3: TToolButton;
    ToolButton4: TToolButton;
    ToolButton5: TToolButton;
    ToolButton6: TToolButton;
    ToolButton7: TToolButton;
    ToolButton8: TToolButton;
    ToolButton9: TToolButton;
    procedure ckAtomicClick(Sender: TObject);
    procedure FormDockOver(Sender: TObject; Source: TDragDockObject; X,
      Y: Integer; State: TDragState; var Accept: Boolean);
    procedure lvJobsChange(Sender: TObject; Item: TListItem; Change: TItemChange
      );
    procedure lvJobsDeletion(Sender: TObject; Item: TListItem);
    procedure mcxdoAboutExecute(Sender: TObject);
    procedure mcxdoAddItemExecute(Sender: TObject);
    procedure mcxdoDefaultExecute(Sender: TObject);
    procedure mcxdoDeleteItemExecute(Sender: TObject);
    procedure mcxdoExitExecute(Sender: TObject);
    procedure mcxdoHelpExecute(Sender: TObject);
    procedure mcxdoHelpOptionsExecute(Sender: TObject);
    procedure mcxdoOpenExecute(Sender: TObject);
    procedure mcxdoQueryExecute(Sender: TObject);
    procedure mcxdoRunExecute(Sender: TObject);
    procedure mcxdoSaveExecute(Sender: TObject);
    procedure mcxdoStopExecute(Sender: TObject);
    procedure mcxdoVerifyExecute(Sender: TObject);
    procedure edConfigFileChange(Sender: TObject);
    procedure edRespinChange(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure lvJobsSelectItem(Sender: TObject; Item: TListItem;
      Selected: Boolean);
    procedure mcxdoWebExecute(Sender: TObject);
    procedure mcxSetCurrentExecute(Sender: TObject);
    procedure MenuItem19Click(Sender: TObject);
    procedure mmOutputDragDrop(Sender, Source: TObject; X, Y: Integer);
    procedure mmOutputDragOver(Sender, Source: TObject; X, Y: Integer;
      State: TDragState; var Accept: Boolean);
    procedure mmOutputMouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure plOutputDockOver(Sender: TObject; Source: TDragDockObject; X,
      Y: Integer; State: TDragState; var Accept: Boolean);
    procedure plSettingDockOver(Sender: TObject; Source: TDragDockObject; X,
      Y: Integer; State: TDragState; var Accept: Boolean);
    procedure pMCXReadData(Sender: TObject);
    procedure pMCXTerminate(Sender: TObject);
    procedure ToolButton14Click(Sender: TObject);
  private
    { private declarations }
  public
    { public declarations }
    MapList: TStringList;
    function CreateCmd:string;
    function CreateCmdOnly:string;
    procedure VerifyInput;
    procedure AddLog(str:string);
    procedure ListToPanel2(node:TListItem);
    procedure PanelToList2(node:TListItem);
    procedure UpdateMCXActions(actlst: TActionList; ontag,offtag: string);
    function  GetMCXOutput (outputstr: string) : string;
    procedure SaveTasksToIni(fname: string);
    procedure LoadTasksFromIni(fname: string);
    procedure RunExternalCmd(cmd: string);
    function  GetBrowserPath : string;
    function  SearchForExe(fname : string) : string;
  end;

var
  fmMCX: TfmMCX;
  ProfileChanged: Boolean;
  MaxWait: integer;
  TaskFile: string;

implementation

{ TfmMCX }
procedure TfmMCX.AddLog(str:string);
begin
    mmOutput.Lines.Add(str);
end;

procedure TfmMCX.edConfigFileChange(Sender: TObject);
begin
  if(Length(edSession.Text)=0) then
       edSession.Text:=ExtractFileName(edConfigFile.FileName);
end;

procedure TfmMCX.edRespinChange(Sender: TObject);
var
    ed: TEdit;
    cb: TComboBox;
    ck: TCheckBox;
    se: TSpinEdit;
    gr: TRadioGroup;
    fed:TFileNameEdit;
    idx: integer;
    node: TListItem;
begin
    if(Sender=nil) or (lvJobs.Selected=nil) then exit;
    try
    node:=lvJobs.Selected;
    if(Sender is TSpinEdit) then begin
       se:=Sender as TSpinEdit;
       idx:=MapList.IndexOf(se.Hint);
       if(idx>=0) then
                  node.SubItems.Strings[idx]:=IntToStr(se.Value);
    end else if(Sender is TEdit) then begin
       ed:=Sender as TEdit;
       idx:=MapList.IndexOf(ed.Hint);
       if(ed.Hint = 'Session') then  node.Caption:=ed.Text;
       if(idx>=0) then
                  node.SubItems.Strings[idx]:=ed.Text;
       if(ed.Hint = 'BubbleSize') then begin
            if StrToFloat(ed.Text)>0 then begin
              if(ckSaveDetector.Checked) then begin
                grVariant.ItemIndex:=3;
              end else begin
                grVariant.ItemIndex:=2;
              end;
            end;
       end;
    end else if(Sender is TRadioGroup) then begin
       gr:=Sender as TRadioGroup;
       idx:=MapList.IndexOf(gr.Hint);
       if(idx>=0) then
                  node.SubItems.Strings[idx]:=IntToStr(gr.ItemIndex);
       if(gr.Hint = 'VariantName') then begin
           ckSaveDetector.Enabled:=(gr.ItemIndex=1) or (gr.ItemIndex=3);
           edDetectedNum.Enabled:=ckSaveDetector.Enabled;
       end;
    end else if(Sender is TComboBox) then begin
       cb:=Sender as TComboBox;
       idx:=MapList.IndexOf(cb.Hint);
       if(idx>=0) then
                  node.SubItems.Strings[idx]:=cb.Text;
    end else if(Sender is TCheckBox) then begin
       ck:=Sender as TCheckBox;
       idx:=MapList.IndexOf(ck.Hint);
       if(idx>=0) then
                  node.SubItems.Strings[idx]:=IntToStr(Integer(ck.Checked));
       if(ck.Hint='Autopilot') then begin
           edThread.Enabled:=not ck.Checked;
           edBlockSize.Enabled:=not ck.Checked;
       end;
       if(ck.Hint='SaveDetector') then begin
           if(ck.Checked) then begin
             if(grVariant.ItemIndex=2) then begin
                grVariant.ItemIndex:=3;
             end else begin
                grVariant.ItemIndex:=1;
             end;
           end else begin
             if(grVariant.ItemIndex=3) then begin
                grVariant.ItemIndex:=2;
             end else begin
                grVariant.ItemIndex:=0;
             end;
           end;
           edDetectedNum.Enabled:=ck.Checked;
       end;
    end else if(Sender is TFileNameEdit) then begin
       fed:=Sender as TFileNameEdit;
       idx:=MapList.IndexOf(fed.Hint);
       if(idx>=0) then
                  node.SubItems.Strings[idx]:=fed.Text;
    end;
    UpdateMCXActions(acMCX,'','Work');
    UpdateMCXActions(acMCX,'','Run');
    mcxdoSave.Enabled:=true;
    except
    end;
end;

procedure TfmMCX.mcxdoExitExecute(Sender: TObject);
var
   ret:integer;
begin
    if(mcxdoSave.Enabled) then begin
       ret:=Application.MessageBox('The current session has not been saved, do you want to save before exit?',
         'Confirm', MB_YESNOCANCEL);
       if (ret=IDYES) then
            mcxdoSaveExecute(Sender);
       if (ret=IDCANCEL) then
            exit;
    end;
    Close;
end;

procedure TfmMCX.mcxdoHelpExecute(Sender: TObject);
begin
   RunExternalCmd(GetBrowserPath + ' http://mcx.sourceforge.net/cgi-bin/index.cgi?Doc');
end;

procedure TfmMCX.mcxdoHelpOptionsExecute(Sender: TObject);
begin
    if(not pMCX.Running) then begin
          pMCX.CommandLine:=CreateCmdOnly;
          pMCX.Options := [poUsePipes];
          AddLog('-- Executing MCX --');
          pMCX.Execute;
    end;
end;

procedure TfmMCX.mcxdoAddItemExecute(Sender: TObject);
var
   node: TListItem;
   i:integer;
   sessionid: string;
begin
   sessionid:=InputBox('Set Session Name','Please type in a unique session name','');
   if(length(sessionid)=0) then exit;
   for i:=0 to lvJobs.Items.Count-1 do begin
        if(lvJobs.Items.Item[i].Caption = sessionid) then
           raise Exception.Create('Session name already used!');
   end;
   node:=lvJobs.Items.Add;
   for i:=0 to lvJobs.Columns.Count-1 do node.SubItems.Add('');
   node.Caption:=sessionid;
   plSetting.Enabled:=true;
   lvJobs.Selected:=node;
   mcxdoDefaultExecute(nil);
   edSession.Text:=sessionid;
   UpdateMCXActions(acMCX,'','Work');
   UpdateMCXActions(acMCX,'','Run');
   UpdateMCXActions(acMCX,'Preproc','');
   UpdateMCXActions(acMCX,'SelectedJob','');
end;

procedure TfmMCX.mcxdoDefaultExecute(Sender: TObject);
begin
      //edSession.Text:='';
      edConfigFile.FileName:='';
      edThread.Text:='1796';
      edPhoton.Text:='1e7';
      edBlockSize.Text:='64';
      edBubble.Text:='0';
      edGate.Value:=1;
      edRespin.Value:=1;
      grArray.ItemIndex:=0;
      ckReflect.Checked:=true;
      ckSaveData.Checked:=true;
      ckNormalize.Checked:=true;
      ckAutopilot.Checked:=false;
      ckSaveDetector.Checked:=false;
      grVariant.ItemIndex:=0;
      edUnitInMM.Text:='1';
      edGPUID.ItemIndex:=0;
      edDetectedNum.Text:='1000000';
      if not (lvJobs.Selected = nil) then
         PanelToList2(lvJobs.Selected);
end;

procedure TfmMCX.UpdateMCXActions(actlst: TActionList; ontag,offtag: string);
var
   i: integer;
begin
   for i:=0 to actlst.ActionCount-1 do begin
       if (Length(ontag)>0) and (actlst.Actions[i].Category=ontag) then begin
             (actlst.Actions[i] as TAction).Enabled:=true;
       end else if (Length(offtag)>0) and (actlst.Actions[i].Category=offtag) then
             (actlst.Actions[i] as TAction).Enabled:=false;
   end;
end;


procedure TfmMCX.mcxdoAboutExecute(Sender: TObject);
var
    fmAbout:TfmAbout;
begin
     fmAbout:=TfmAbout.Create(Application);
     fmAbout.ShowModal;
     fmAbout.Free;
end;

procedure TfmMCX.lvJobsChange(Sender: TObject; Item: TListItem;
  Change: TItemChange);
begin
  mcxdoSave.Enabled:=true;
end;

procedure TfmMCX.lvJobsDeletion(Sender: TObject; Item: TListItem);
begin

end;

procedure TfmMCX.ckAtomicClick(Sender: TObject);
begin
end;

procedure TfmMCX.FormDockOver(Sender: TObject; Source: TDragDockObject; X,
  Y: Integer; State: TDragState; var Accept: Boolean);
begin
end;

procedure TfmMCX.mcxdoDeleteItemExecute(Sender: TObject);
begin
  if not (lvJobs.Selected = nil) then
  begin
        if not (Application.MessageBox('The selected configuration will be deleted, are you sure?',
          'Confirm', MB_YESNOCANCEL)=IDYES) then
            exit;
        lvJobs.Items.Delete(lvJobs.Selected.Index);
        if not (lvJobs.Selected = nil) then
            ListToPanel2(lvJobs.Selected)
        else
            mcxdoDeleteItem.Enabled:=false;
  end;
end;

procedure TfmMCX.mcxdoOpenExecute(Sender: TObject);
begin
  if(OpenProject.Execute) then begin
    TaskFile:=OpenProject.FileName;
    if(mcxdoSave.Enabled) then begin
       if(Application.MessageBox('The current session has not been saved, do you want to discard?',
         'Confirm', MB_YESNOCANCEL)=IDYES) then
            LoadTasksFromIni(TaskFile);
    end else begin
            LoadTasksFromIni(TaskFile);
    end;
  end
end;

procedure TfmMCX.mcxdoQueryExecute(Sender: TObject);
begin
    if(not pMCX.Running) then begin
          pMCX.CommandLine:=CreateCmdOnly+' -L';
          pMCX.Options := [poUsePipes];
          AddLog('-- Executing MCX --');
          pMCX.Execute;

          UpdateMCXActions(acMCX,'Run','');
    end;
end;

procedure TfmMCX.mcxdoRunExecute(Sender: TObject);
begin
    if(not pMCX.Running) then begin
          pMCX.CommandLine:=CreateCmd;
          //pMCX.CommandLine:='du /usr/ --max-depth=1';
          pMCX.Options := pMCX.Options+[poUsePipes];
          AddLog('-- Executing MCX --');
          pMCX.Execute;
          mcxdoStop.Enabled:=true;
          mcxdoRun.Enabled:=false;
          sbInfo.Panels[0].Text := 'Status: busy';
          sbInfo.Color := clRed;
          UpdateMCXActions(acMCX,'Run','');
          Application.ProcessMessages;
    end;
end;

procedure TfmMCX.mcxdoSaveExecute(Sender: TObject);
begin
  if(SaveProject.Execute) then begin
    TaskFile:=SaveProject.FileName;
    if(length(TaskFile) >0) then begin
        SaveTasksToIni(TaskFile);
        mcxdoSave.Enabled:=false;
    end;
  end;
end;

procedure TfmMCX.mcxdoStopExecute(Sender: TObject);
begin
     if(pMCX.Running) then pMCX.Terminate(0);
     Sleep(1000);
     if(not pMCX.Running) then begin
          mcxdoStop.Enabled:=false;
          if(mcxdoVerify.Enabled) then
             mcxdoRun.Enabled:=true;
          AddLog('-- Stopped MCX --');
     end
end;

procedure TfmMCX.mcxdoVerifyExecute(Sender: TObject);
begin
    VerifyInput;
end;

procedure TfmMCX.FormCreate(Sender: TObject);
var
   i: integer;
begin
    MapList:=TStringList.Create();
    MapList.Clear;
    for i:=1 to lvJobs.Columns.Count-1 do begin
        MapList.Add(lvJobs.Columns.Items[i].Caption);
    end;
    ProfileChanged:=false;
    if not (SearchForExe(CreateCmdOnly) = '') then begin
        mcxdoQuery.Enabled:=true;
        mcxdoHelpOptions.Enabled:=true;
    end;
end;

procedure TfmMCX.FormDestroy(Sender: TObject);
begin
    MapList.Free;
end;

procedure TfmMCX.lvJobsSelectItem(Sender: TObject; Item: TListItem;
  Selected: Boolean);
begin
     if(Selected) then begin
          if (lvJobs.Selected=nil) then begin
          end else begin
              mcxdoDeleteItem.Enabled:=true;
          end;
     end
end;

procedure TfmMCX.RunExternalCmd(cmd: string);
var
  Proc : TProcess;
begin
  Proc := TProcess.Create(nil);
  try
    Proc.CommandLine := cmd;
    //PRoc.Options := Proc.Options + [poWaitOnExit];
    PRoc.Execute;
  finally
    Proc.free;
  end;
end;

function TfmMCX.SearchForExe(fname : string) : string;
begin
   {$IFDEF WINDOWS}
   if (Pos('.exe',Trim(LowerCase(fname)))<=0) or (Pos('.exe',Trim(LowerCase(fname))) <> Length(Trim(fname))-3) then
           fname:=fname+'.exe';
   {$ENDIF}
   Result :=
    SearchFileInPath(fname, '', ExtractFilePath(Application.ExeName)+PathSeparator+GetEnvironmentVariable('PATH'),
                     PathSeparator, [sffDontSearchInBasePath]);
end;

function TfmMCX.GetBrowserPath : string;
  {Return path to first browser found.}
begin
   Result := SearchForExe('firefox');
   if Result = '' then
     Result := SearchForExe('konqueror');  {KDE browser}
   if Result = '' then
     Result := SearchForExe('epiphany');  {GNOME browser}
   if Result = '' then
     Result := SearchForExe('mozilla');
   if Result = '' then
     Result := SearchForExe('opera');
   if Result = '' then
     Result := SearchForExe('open'); // mac os
   if Result = '' then
     Result :='cmd /c start'; // windows
end;

procedure TfmMCX.mcxdoWebExecute(Sender: TObject);
begin
  RunExternalCmd(GetBrowserPath + ' http://mcx.sourceforge.net');
end;

procedure TfmMCX.mcxSetCurrentExecute(Sender: TObject);
begin
     if not (lvJobs.Selected = nil) then begin
         ListToPanel2(lvJobs.Selected);
         plSetting.Enabled:=true;
         mcxdoVerify.Enabled:=true;
         mcxdoDefault.Enabled:=true;
     end;
end;

procedure TfmMCX.MenuItem19Click(Sender: TObject);
begin
    mmOutput.Lines.Clear;
end;

procedure TfmMCX.mmOutputDragDrop(Sender, Source: TObject; X, Y: Integer);
begin

end;

procedure TfmMCX.mmOutputDragOver(Sender, Source: TObject; X, Y: Integer;
  State: TDragState; var Accept: Boolean);
begin
         mmOutput.DragMode:=dmManual;
end;

procedure TfmMCX.mmOutputMouseDown(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
    if(ssCtrl in Shift) then begin
         mmOutput.DragMode:=dmAutomatic;
    end;
end;

procedure TfmMCX.plOutputDockOver(Sender: TObject; Source: TDragDockObject; X,
  Y: Integer; State: TDragState; var Accept: Boolean);
var
   pos:TRect;
   mm: TMemo;
begin
     Accept:=false;
     if (Sender is TMemo) then
        Accept:=true;
     if(Accept) then begin
          mm:=(Sender as TMemo);
          pos:=Rect(0,Height-mm.Height, Width, Height);
          mm.Dock(Self,pos);
     end;
end;

procedure TfmMCX.plSettingDockOver(Sender: TObject; Source: TDragDockObject; X,
  Y: Integer; State: TDragState; var Accept: Boolean);
begin
end;

procedure TfmMCX.pMCXReadData(Sender: TObject);
begin
     mmOutput.Lines.Text:=GetMCXOutput(mmOutput.Lines.Text);
     if not (pMCX.Running) then
         pMCXTerminate(Sender);
end;

procedure TfmMCX.pMCXTerminate(Sender: TObject);
begin
     mcxdoStop.Enabled:=false;
     if(mcxdoVerify.Enabled) then
         mcxdoRun.Enabled:=true;
     sbInfo.Panels[0].Text := 'Status: idle';
     sbInfo.Color := clBtnFace;
     AddLog('Task complete');
     UpdateMCXActions(acMCX,'','Run');
end;

procedure TfmMCX.ToolButton14Click(Sender: TObject);
begin

end;

function TfmMCX.GetMCXOutput (outputstr: string) : string;
var
    Buffer: string;
    BytesAvailable: DWord;
    BytesRead:LongInt;
begin
   Result:= outputstr;

   //if(pMCX.Running) then
   if true then
    begin
      BytesAvailable := pMCX.Output.NumBytesAvailable;
      BytesRead := 0;
      while BytesAvailable>0 do
      begin
        SetLength(Buffer, BytesAvailable);
        BytesRead := pMCX.OutPut.Read(Buffer[1], BytesAvailable);
        Result := Result + copy(Buffer,1, BytesRead);
        BytesAvailable := pMCX.Output.NumBytesAvailable;
      end;
    end;
end;

procedure TfmMCX.SaveTasksToIni(fname: string);
var
   inifile: TIniFile;
   i,j: integer;
begin
     DeleteFile(fname);
     inifile:=TIniFile.Create(fname);
     for i:=0 to lvJobs.Items.Count-1 do begin
          for j:=0 to lvJobs.Columns.Count-1 do begin
              inifile.WriteString(lvJobs.Items.Item[i].Caption,
                                  lvJobs.Columns.Items[j].Caption,
                                  lvJobs.Items.Item[i].SubItems.Strings[j]);
          end;
     end;
     inifile.UpdateFile;
     inifile.Free;
end;

procedure TfmMCX.LoadTasksFromIni(fname: string);
var
   sessions,vals:TStringList;
   inifile: TIniFile;
   i,j: integer;
   node: TListItem;
begin
     sessions:=TStringList.Create;
     vals:=TStringList.Create;
     inifile:=TIniFile.Create(fname);
     inifile.ReadSections(sessions);
     for i:=0 to sessions.Count-1 do begin
         node:=lvJobs.Items.Add;
         node.Caption:=sessions.Strings[i];
         inifile.ReadSectionValues(node.Caption,vals);
         for j:=0 to lvJobs.Columns.Count-1 do
             node.SubItems.Add('');
         for j:=0 to lvJobs.Columns.Count-1 do begin
             node.SubItems.Strings[j]:=vals.Values[lvJobs.Columns.Items[j].Caption];
         end
     end;
     inifile.Free;
     vals.Free;
     sessions.Free;
     AddLog(Format('Successfully loaded project %s. Please double click on session list to edit.',[fname]));
end;


procedure TfmMCX.VerifyInput;
var
    nthread, nblock: integer;
    radius,nphoton: extended;
    exepath: string;
begin
  try
    if(Length(edConfigFile.FileName)=0) then
        raise Exception.Create('Config file must be specified');
    if(not FileExists(edConfigFile.FileName)) then
        raise Exception.Create('Config file does not exist, please check the path');
    try
        nthread:=StrToInt(edThread.Text);
        nphoton:=StrToFloat(edPhoton.Text);
        radius:=StrToFloat(edBubble.Text);
        nblock:=StrToInt(edBlockSize.Text);
    except
        raise Exception.Create('Invalid numbers: check the values for thread (-t), block (-T), photon (-n) and cache radius (-R)');
    end;
    if(nthread<512) then
       AddLog('Warning: using over 20000 threads (-t) can usually give you the best speed');
    if(nthread>10000) then
       AddLog('Warning: you can try Cached MCX to improve accuracy near the source');
    if(nphoton>1e9) then
       AddLog('Warning: you can increase respin number (-r) to get more photons');
    if(nblock<0) then
       raise Exception.Create('Thread block number (-T) can not be negative');
    if(radius<0) then
       raise Exception.Create('Cache radius (-R) can not be negative');
    if (grVariant.ItemIndex =2) or (grVariant.ItemIndex =3) and (radius<3) or (radius>7) then
       AddLog('Warning: a cache radius (-R) between 3mm to 5mm is recommended');

    exepath:=SearchForExe(CreateCmdOnly);
    if(exepath='') then
       raise Exception.Create('Can not find mcx executable in the search path');

    UpdateMCXActions(acMCX,'Work','');
  except
    On E : Exception do
      ShowMessage(E.Message);
  end;
end;

function TfmMCX.CreateCmdOnly:string;
var
    cmd: string;
begin
    cmd:='mcx';
    if(grVariant.ItemIndex=0) then begin
       cmd:='mcx';
    end else if(grVariant.ItemIndex=1) then begin
       cmd:='mcx_det';
    end else if(grVariant.ItemIndex=2) then begin
       cmd:='mcx_cached';
    end else if(grVariant.ItemIndex=3) then begin
       cmd:='mcx_det_cached';
    end else if(grVariant.ItemIndex=4) then begin
       cmd:='mcx_atomic';
    end;
    Result:=cmd;
end;

function TfmMCX.CreateCmd:string;
var
    nthread, nblock,gpuid,hitmax: integer;
    bubbleradius,unitinmm,nphoton: extended;
    cmd: string;
begin
//    cmd:='"'+Config.MCXExe+'" ';
    cmd:=CreateCmdOnly;
    if(Length(edSession.Text)>0) then
       cmd:=cmd+' --session "'+Trim(edSession.Text)+'" ';
    if(Length(edConfigFile.FileName)>0) then
       cmd:=cmd+' --input "'+Trim(edConfigFile.FileName)
         +'" --root "'+ExcludeTrailingPathDelimiter(ExtractFilePath(edConfigFile.FileName))+'" ';
    try
        nthread:=StrToInt(edThread.Text);
        nphoton:=StrToFloat(edPhoton.Text);
        nblock:=StrToInt(edBlockSize.Text);
        bubbleradius:=StrToFloat(edBubble.Text);
        gpuid:=StrToInt(edGPUID.Text);
        unitinmm:=StrToFloat(edUnitInMM.Text);
        hitmax:=StrToInt(edDetectedNum.Text);
    except
        raise Exception.Create('Invalid numbers: check the values for thread, block, photon and time gate settings');
    end;

    if(ckAutopilot.Checked) then begin
      cmd:=cmd+Format(' --gpu %d --autopilot 1 --photon %.0f --repeat %d --array %d --skipradius %f ',
        [gpuid,nphoton,edRespin.Value,grArray.ItemIndex,bubbleradius]);
    end else begin
      cmd:=cmd+Format(' --thread %d --blocksize %d --photon %.0f --repeat %d --array %d --skipradius %f ',
        [nthread,nblock,nphoton,edRespin.Value,grArray.ItemIndex,bubbleradius]);
    end;
    cmd:=cmd+Format(' --normalize %d --save2pt %d --reflect %d --savedet %d --maxdetphoton %d --unitinmm %f',
      [Integer(ckNormalize.Checked),Integer(ckSaveData.Checked),Integer(ckReflect.Checked),
      Integer(ckSaveDetector.Checked),hitmax,unitinmm]);

    Result:=cmd;
    AddLog('Command:');
    AddLog(cmd);
end;

procedure TfmMCX.PanelToList2(node:TListItem);
var
    ed: TEdit;
    cb: TComboBox;
    ck: TCheckBox;
    se: TSpinEdit;
    gr: TRadioGroup;
    i,idx: integer;
begin
    if(node=nil) then exit;
    for i:=0 to plSetting.ControlCount-1 do
    begin
        try
        if(plSetting.Controls[i] is TSpinEdit) then begin
           se:=plSetting.Controls[i] as TSpinEdit;
           idx:=MapList.IndexOf(se.Hint);
           if(idx>=0) then node.SubItems.Strings[idx]:=IntToStr(se.Value);
           continue;
        end;
        if(plSetting.Controls[i] is TEdit) then begin
           ed:=plSetting.Controls[i] as TEdit;
           idx:=MapList.IndexOf(ed.Hint);
           if(idx>=0) then node.SubItems.Strings[idx]:=ed.Text;
           continue;
        end;
        if(plSetting.Controls[i] is TRadioGroup) then begin
           gr:=plSetting.Controls[i] as TRadioGroup;
           idx:=MapList.IndexOf(gr.Hint);
           if(idx>=0) then node.SubItems.Strings[idx]:=IntToStr(gr.ItemIndex);
           continue;
        end;
        if(plSetting.Controls[i] is TComboBox) then begin
           cb:=plSetting.Controls[i] as TComboBox;
           idx:=MapList.IndexOf(cb.Hint);
           if(idx>=0) then node.SubItems.Strings[idx]:=cb.Text;
           continue;
        end;
        if(plSetting.Controls[i] is TCheckBox) then begin
           ck:=plSetting.Controls[i] as TCheckBox;
           idx:=MapList.IndexOf(ck.Hint);
           if(idx>=0) then node.SubItems.Strings[idx]:=IntToStr(Integer(ck.Checked));
           continue;
        end;

        except
        end;
    end;
end;

procedure TfmMCX.ListToPanel2(node:TListItem);
var
    ed: TEdit;
    cb: TComboBox;
    ck: TCheckBox;
    se: TSpinEdit;
    gr: TRadioGroup;
    fed:TFileNameEdit;
    i,idx: integer;
begin
    if(node=nil) then exit;
    edSession.Text:=node.Caption;

    for i:=0 to plSetting.ControlCount-1 do
    begin
        if(plSetting.Controls[i] is TSpinEdit) then begin
           se:=plSetting.Controls[i] as TSpinEdit;
           idx:=MapList.IndexOf(se.Hint);
           if(idx>=0) then begin
                try
                      se.Value:=StrToInt(node.SubItems.Strings[idx]);
                except
                end;
           end;
           continue;
        end;
        if(plSetting.Controls[i] is TEdit) then begin
           ed:=plSetting.Controls[i] as TEdit;
           idx:=MapList.IndexOf(ed.Hint);
           if(idx>=0) then ed.Text:=node.SubItems.Strings[idx];
           continue;
        end;
        if(plSetting.Controls[i] is TFileNameEdit) then begin
           fed:=plSetting.Controls[i] as TFileNameEdit;
           idx:=MapList.IndexOf(fed.Hint);
           if(idx>=0) then fed.Text:=node.SubItems.Strings[idx];
           continue;
        end;
        if(plSetting.Controls[i] is TRadioGroup) then begin
           gr:=plSetting.Controls[i] as TRadioGroup;
           idx:=MapList.IndexOf(gr.Hint);
           if(idx>=0) then begin
                try
                      gr.ItemIndex:=StrToInt(node.SubItems.Strings[idx]);
                except
                end;
           end;
           continue;
        end;
        if(plSetting.Controls[i] is TComboBox) then begin
           cb:=plSetting.Controls[i] as TComboBox;
           idx:=MapList.IndexOf(cb.Hint);
           if(idx>=0) then cb.Text:=node.SubItems.Strings[idx];
           continue;
        end;
        if(plSetting.Controls[i] is TCheckBox) then begin
           ck:=plSetting.Controls[i] as TCheckBox;
           idx:=MapList.IndexOf(ck.Hint);
           if(idx>=0) then ck.Checked:=(node.SubItems.Strings[idx]='1');
           continue;
        end;
    end;
end;
initialization
  {$I mcxgui.lrs}

end.

