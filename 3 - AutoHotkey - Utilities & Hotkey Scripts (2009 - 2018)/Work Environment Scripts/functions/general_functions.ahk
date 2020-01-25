Captures() {
    iWidth = 384
    iHeight = 130
    CoordMode, Mouse, Window
    MouseGetPos, X, Y, thisWin
    WinGetPos, mX, mY, Width, Height, ahk_id %thisWin%
    iX := mX + Width/2 - iWidth/2
    iY := mY + Height/2 - iHeight/2
    InputBox, iter, Screen Captures, How many screen captures?, , iWidth, iHeight, iX, iY
    Loop, %iter%
    {
        MouseGetPos,,,,OutputVarControl
        if (GetKeyState("Escape", "P") || (OutputVarControl != "Intermediate D3D Window1")) {
            break
        }
        SendInput ^!+s
        Sleep 700
        SendInput {Click}
        sleep 700
    }
}

ClipboardText(){
    ClipSaved := ClipboardAll
    clipboard := ""
    SendInput ^c
    ClipWait, 1
    if (!ErrorLevel)
    {
        CopiedText = %clipboard%
    }
    Sleep, 100
    clipboard := ClipSaved       ; restore original clipboard
    ClipSaved := ""   ;  free the memory in case the clipboard was very large.
    return CopiedText
}

ExecuteInput(action) {
    ; Arguments may be void functions, labels and keystrokes.
    ; Syntax:
    ;     ExecuteInput("my_function")
    ;     ExecuteInput("my_label")
    ;     ExecuteInput("{Capslock}this in caps{Capslock}")
    ;     ExecuteInput(var_or_parameter_of_another_function)
    Try {
        if (action = "") {
            action := A_ThisHotkey
        } else {
      ; if (A_ThisHotkey = "RButton" || A_ThisHotkey = "~RButton Up" || A_PriorKey = "RButton") {
      ; ; msgbox hello
      ;     SuppressContextMenu(10)
      ; }
      }
        if IsLabel(action) {
            Gosub %action%
            Exit
        } else if IsFunc(action) {
            %action%()
            Exit
        } else {
            Send % action
            Exit
        }
    } catch {
        MsgBox Error - Invalid label or input
    }
}

Explorer_GetPath(hwnd="") {
    hwnd := hwnd ? hwnd : WinExist("A")
    WinGetClass class, ahk_id %hwnd%
    if (class="CabinetWClass" or class="ExploreWClass" or class="Progman")
        for window in ComObjCreate("Shell.Application").Windows
            if (window.hwnd==hwnd)
    sel := window.Document.SelectedItems
    for item in sel
    ToReturn .= item.path "`n"
    return Trim(ToReturn,"`n")
}

Explorer_RenameSelectedFile() {
    ibw := 250
    ibh := 100
    ControlGetFocus, thisControl, A
    if (thisControl != "DirectUIHWND3") {
        Goto, ErrorExitHandler
    }
    SendInput {F2}
    path1 := Explorer_GetPath()
    SplitPath, path1, NameExt1, FileDir, FileExt, name1
    Menu, Tray, Icon, imageres.dll, 204
    InputBox, name2, Rename File, , , %ibw%, %ibh%, %A_CaretX%,%A_CaretY%,,,%name1%
    if (ErrorLevel) {
        Goto, ErrorExitHandler
    } else {
        SendInput {F2}
        SendInput %name2%
        SendInput {Enter}
    }

    ErrorExitHandler:
        Menu, Tray, Icon, auxiliary_files/autotext.ico
    return
}

HideTrayTip() {
    TrayTip  ; Attempt to hide it the normal way.
    if SubStr(A_OSVersion,1,3) = "10." {
        Menu Tray, NoIcon
        Sleep 200  ; It may be necessary to adjust this sleep.
        Menu Tray, Icon
    }
}

OpenSublime(WinTitle, ProjectFileOrLink) {
    IfWinExist, %WinTitle%
        WinActivate, %WinTitle%
    else
        Run, %ProjectFileOrLink%
    WinWaitActive, %WinTitle%
    WinMaximize, %WinTitle%
    IfWinExist, untitled - Sublime Text
    WinClose, untitled - Sublime Text
    Click, 350, 149
    SendInput ^a
    Sleep 100
    SendInput {Control Down}k1{Control Up}
    Sleep 100
    SendInput {left}
}

RunMSWordMacro(MacroName) {
    oWord := ComObjActive("Word.Application")
    oWord.Run(MacroName)
}

RunMSExcelMacro(MacroName) {
    oExcel := ComObjActive("Excel.Application")
    oExcel.Run(MacroName)
}

RunOrActivate(WinTitle, ExePath, FocusWhere := "") {
    DetectHiddenWindows, On  ; Might allow detection of menu sooner.
    IfWinExist, %WinTitle%
        WinActivate, %WinTitle%
    else
        Run, %ExePath%
    WinWaitActive, %WinTitle%
    if FocusWhere != ""
        ControlFocus, %FocusWhere%, %WinTitle%
}

RunNewInstance(WinTitle, ExePath, FocusWhere := "") {
    Run, %ExePath%
    WinWaitActive, %WinTitle%
    if FocusWhere != ""
        ControlFocus, %FocusWhere%, %WinTitle%
}

runLabel(LabelName){
    gosub %LabelName%
}

SetWorkFolder() {
    WinGetText, path, ahk_class CabinetWClass
    FirstCharPos := InStr(path,":") + 2
    LastCharPos := InStr(path,"`r`n",,FirstCharPos)
    PathLength := LastCharPos - FirstCharPos
    path := SubStr(path, FirstCharPos, PathLength)
    IniWrite, %path%, "D:\AHK Tools\Scripts\_AuxFiles\data.ini", PATHS, WorkFolderPath
}

SuppressContextMenu(Delay=0, menuTrigger := "RButton") {
  KeyWait %menuTrigger%
  SendInput {Esc}
  if (Delay > 0)
    Sleep %Delay%
}

textSelected() {
    ClipSaved := ClipboardAll       ;save clipboard
    clipboard := ""                 ; empty clipboard
    Send, ^c                        ; copy the selected file
    ClipWait, 1                     ; wait for the clipboard to contain data
    Sleep, 100
    clipboard := ClipSaved       ; restore original clipboard
    ClipSaved := ""   ;  free the memory in case the clipboard was very large.
    return text_selected
}

tmsg(msg_text, msg_title := "Scripts Notification", seconds := 2) {
    DetectHiddenText, On
    seconds := seconds * -1000
    TrayTip, %msg_title%, %msg_text%
    SetTimer, HideTrayTip, %seconds%
}

;*******************************************************************************************
; The following code is provided courtesy of contributors on the Autohotkey forum
;*******************************************************************************************

Morse(timeout = 400) {
    tout := timeout/1000
    key := RegExReplace(A_ThisHotKey,"[\*\~\$\#\+\!\^]")
    IfInString, key, %A_Space%
    StringTrimLeft, key, key,% InStr(key,A_Space,1,0)
    Loop
    {
        t := A_TickCount
        KeyWait %key%, T%tout%
        Pattern .= A_TickCount-t > timeout
        if(ErrorLevel)
            return Pattern
        KeyWait %key%,DT%tout%
        if (ErrorLevel) {
            return Pattern
        }
    }
}

AutotextEntry() {
    ; Win+H hotkey
    ; Get the text currently selected. The clipboard is used instead of
    ; "ControlGet Selected" because it works in a greater variety of editors
    ; (namely word processors).  Save the current clipboard contents to be
    ; restored later. Although this handles only plain text, it seems better
    ; than nothing:
    AutoTrim Off  ; Retain any leading and trailing whitespace on the clipboard.
    ClipboardOld = %ClipboardAll%
    Clipboard =  ; Must start off blank for detection to work.
    Send ^c
    ClipWait 1
    if ErrorLevel  ; ClipWait timed out.
        return
    ; Replace CRLF and/or LF with `n for use in a "send-raw" hotstring:
    ; The same is done for any other characters that might otherwise
    ; be a problem in raw mode:
    StringReplace, Hotstring, Clipboard, ``, ````, All  ; Do this replacement first to avoid interfering with the others below.
    StringReplace, Hotstring, Hotstring, `r`n, ``r, All  ; Using `r works better than `n in MS Word, etc.
    StringReplace, Hotstring, Hotstring, `n, ``r, All
    StringReplace, Hotstring, Hotstring, %A_Tab%, ``t, All
    StringReplace, Hotstring, Hotstring, `;, ```;, All
    Clipboard = %ClipboardOld%  ; Restore previous contents of clipboard.
    ; This will move the InputBox's caret to a more friendly position:
    SetTimer, MoveCaret, 10
    ; Show the InputBox, providing the default hotstring:
    InputBox, Hotstring, New Hotstring, Type your abreviation at the indicated insertion point. You can also edit the replacement text if you wish.`n`nExample entry: :R:btw`::by the way,,,,,,,, :R:`::%Hotstring%
    if ErrorLevel  ; The user pressed Cancel.
        return
    IfInString, Hotstring, :R`:::
    {
        MsgBox You didn't provide an abbreviation. The hotstring has not been added.
        return
    }
    ; Otherwise, add the hotstring and reload the script:
    FileAppend, `n%Hotstring%, %A_ScriptFullPath%  ; Put a `n at the beginning in case file lacks a blank line at its end.
    Reload
    Sleep 200 ; if successful, the reload will close this instance during the Sleep, so the line below will never be reached.
    MsgBox, 4,, The hotstring just added appears to be improperly formatted.  Would you like to open the script for editing? Note that the bad hotstring is at the bottom of the script.
    IfMsgBox, Yes, Edit
}

RapidHotkey(keystroke, times="2", delay=0.2, IsLabel=0) {
/*
    Key::RapidHotkey("keystrokes" ;Enter keystrokes here. E.g.: "^o"
        , times             ;optional. The number of times the key must be pressed to execute.  E.g.: 3
        , delay             ;optional. How quick the key must be pressed to execute. E.g.: 0.2
        , IsLabel)          ;optional. specify 1 to indicate that parameter 1 is a label.
    ;E.g.
    ~o::RapidHotkey("^o") ;open file dialog if o pressed twice

    ;To specify several actions , use " as separator and leave times parameter empty.
    if press times parameter is omitted, first action would be triggered on 2 presses.
    ~e::RapidHotkey("#r""#e""#f") ; #r if pressed twice, #e 3 times and so on
    ;You can specify also one (can be also 1) or separated value for times
    ~s::RapidHotkey("^s""{F12}""^+s", 5) ;so pressing 5 times = ^s, 6 times = {F12} and so on
    ;You can also specify separated times value
    $x::RapidHotkey("x""#r""#e", "1""5""3")

    ;use same separator for delay and islabel parameter
*/
    Pattern := Morse(delay*1000)
    if (StrLen(Pattern) < 2 and Chr(Asc(times)) != "1")
        return
    if (times = "" and InStr(keystroke, """"))
    {
        Loop, Parse, keystroke,""
            if (StrLen(Pattern) = A_Index+1)
                continue := A_Index, times := StrLen(Pattern)
    }
    else if (RegExMatch(times, "^\d+$") and InStr(keystroke, """"))
    {
        Loop, Parse, keystroke,""
            if (StrLen(Pattern) = A_Index+times-1)
                times := StrLen(Pattern), continue := A_Index
    }
    else if InStr(times, """")
    {
        Loop, Parse, times,""
            if (StrLen(Pattern) = A_LoopField)
                continue := A_Index, times := A_LoopField
    }
    else if (times = "")
        continue = 1, times = 2
    else if (times = StrLen(Pattern))
        continue = 1
    if !continue
        return
    Loop, Parse, keystroke,""
        if (continue = A_Index)
            keystr := A_LoopField
    Loop, Parse, IsLabel,""
        if (continue = A_Index)
            IsLabel := A_LoopField
    hotkey := RegExReplace(A_ThisHotkey, "[\*\~\$\#\+\!\^]")
    IfInString, hotkey, %A_Space%
        StringTrimLeft, hotkey,hotkey,% InStr(hotkey,A_Space,1,0)
    Loop % times
        backspace .= "{Backspace}"
    keywait = Ctrl|Alt|Shift|LWin|RWin
    Loop, Parse, keywait, |
        KeyWait, %A_LoopField%
    if ((!IsLabel or (IsLabel and IsLabel(keystr))) and InStr(A_ThisHotkey, "~") and !RegExMatch(A_ThisHotkey
    , "i)\^[^\!\d]|![^\d]|#|Control|Ctrl|LCtrl|RCtrl|Shift|RShift|LShift|RWin|LWin|Escape|BackSpace|F\d\d?|"
    . "Insert|Esc|Escape|BS|Delete|Home|End|PgDn|PgUp|Up|Down|Left|Right|ScrollLock|CapsLock|NumLock|AppsKey|"
    . "PrintScreen|CtrlDown|Pause|Break|Help|Sleep|Browser_Back|Browser_Forward|Browser_Refresh|Browser_Stop|"
    . "Browser_Search|Browser_Favorites|Browser_Home|Volume_Mute|Volume_Down|Volume_Up|MButton|RButton|LButton|"
    . "Media_Next|Media_Prev|Media_Stop|Media_Play_Pause|Launch_Mail|Launch_Media|Launch_App1|Launch_App2"))
        Send % backspace
    if (WinExist("AHK_class #32768") and hotkey = "RButton")
        WinClose, AHK_class #32768
    if !IsLabel
        Send % keystr
    else if IsLabel(keystr)
        Gosub, %keystr%
    return
}
