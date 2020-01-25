getDisplayDim:
    Global Mon1, Mon2
    Global Mon1Left, Mon2Left, Mon1Right, Mon2Right
    Global Mon1Top, Mon2Top, Mon1Bottom, Mon2Bottom
    SysGet, Mon1, Monitor, 1
    if (DisplayCount() > 1) {
        SysGet, Mon2, Monitor, 2
        if (Mon1Right > Mon2Right) {
            SysGet, Mon2, Monitor, 1
            SysGet, Mon1, Monitor, 2
        }
        Global Mon2MiddleX := Mon2Right - (Mon2Right - Mon2Left)/2
        Global Mon2MiddleY := Mon2Bottom - (Mon2Bottom - Mon2Top)/2
        Global Mon2Width := Mon2Right - Mon2Left
        Global Mon2Height := Mon2Bottom - Mon2Top
    }
    Global Mon1MiddleX := Mon1Right - (Mon1Right - Mon1Left)/2
    Global Mon1MiddleY := Mon1Bottom - (Mon1Bottom - Mon1Top)/2
    Global Mon1Width := Mon1Right - Mon1Left
    Global Mon1Height := Mon1Bottom - Mon1Top

getTaskBarDim:
    Global tbx, tby, tbw, tbh, tb2x, tb2y, tb2w, tb2h
    WinGetPos, tbx, tby, tbw, tbh, ahk_class Shell_TrayWnd
    if WinExist("ahk_class Shell_SecondaryTrayWnd")
    WinGetPos, tb2x, tb2y, tb2w, tb2h, ahk_class Shell_SecondaryTrayWnd
    return

getWorkArea:
    Global WorkAreaLeft, WorkAreaRight, WorkAreaTop, WorkAreaBottom,
    SysGet, WorkArea, MonitorWorkArea, %A_Index%
    SysGet, SM_XVIRTUALSCREEN, 76
    SysGet, SM_YVIRTUALSCREEN, 77
    Global WorkAreaMiddleX := WorkAreaRight - (WorkAreaRight - WorkAreaLeft)/2
    Global WorkAreaMiddleY := WorkAreaBottom - (WorkAreaBottom - WorkAreaTop)/2
    Global WorkAreaWidth := WorkAreaRight - WorkAreaLeft
    Global WorkAreaHeight := WorkAreaBottom - WorkAreaTop
    return

getOtherGlobals:
    Global text_selected
    Global ahk_help_path := "C:\Program Files\AutoHotkey\AutoHotkey.chm"
    Global chrome_exe_path := "C:\Program Files (x86)\Google\Chrome\Application\chrome.exe"
    return

OnClipboardChange:
    global text_selected
    if(A_EventInfo=1)
    {
        text_selected := true
    }
    else
        text_selected := false
    return

MoveCaret:
    IfWinNotActive, New Hotstring
        return
    Send {Home}{Right 3}
    SetTimer, MoveCaret, Off
    return

MigrateWinLeft:
    SendInput #!{Left}
    Sleep, 200
    SendInput #^{Left}
    return

MigrateWinRight:
    SendInput #!{Right}
    Sleep, 200
    SendInput #^{Right}
    return

showSelected:
    ClipSaved := ClipboardAll         ;save clipboard
    clipboard := ""                ; empty clipboard
    Send, ^c                         ; copy the selected file
    ClipWait, 1                     ; wait for the clipboard to contain data
    if (!ErrorLevel)              ; if NOT ErrorLevel clipwait found data on the clipboard
    {
        if text_selected
        MsgBox, %clipboard%
    }
    Sleep, 100
    clipboard := ClipSaved         ; restore original clipboard
    ClipSaved := ""    ;  free the memory in case the clipboard was very large.
    return
