ActiveDisplayID(title := "A") {
    SysGet, DisplayCount, MonitorCount
    if (DisplayCount > 1) {
        gosub, getDisplayDim
    }
    WinGetPos, X, Y, W, H, %title%
    winMiddle := X + W/2
    if (DisplayCount = 2 && winMiddle > Mon2Left) {
        return 2
    }
    return 1
}

CenterInWindow(w, h, target := "") {
    ; Off-center for some reason...;
    CoordMode, Mouse, Window
    MouseGetPos,,, thisWin
    WinGetPos, mX, mY, Width, Height, ahk_id %thisWin%
    iX := mX + Width/2 - h/2
    iY := mY + Height/2 - w/2
    if (target = "") {
        InputBox, iter, Screen Captures, How many screen captures?, , w, h, iX, iY
    } else {
        WinMove, %target%,, iX, iY, w, h
    }
}

DisplayCount() {
    SysGet, DisplayCount, MonitorCount
    return DisplayCount
}

flashActivate(win := "A") {
    WinActivate, %win%
    WinHide, %win%
    WinShow, %win%
}

flash_window(win := "A") {
    WinActivate, %win%
    hWnd := WinActive( win )
    Loop 4
    {
        DllCall( "FlashWindow", UInt,hWnd, Int,True )
        Sleep 500
    }
    DllCall( "FlashWindow", UInt,hWnd, Int,False )
}

HideTitleBar(myWinTitle := "A") {
    WinGet Style, Style, A
    if(Style & 0xC40000) {
        WinSet, Style, -0xC40000 , %myWinTitle% ;0xC00000 0xC40000 0xC840000
    } else {
        WinSet, Style, +0xC40000, %myWinTitle% ;0xC40000 0xC840000
    }
}

MinMaxWindow() {
    WinGet, myWinState, MinMax
    if myWinState != 0
        WinRestore, A
    WinGetPos, , , Width, Height, A
    if (Width < 1024) {
        WinMove,A,,-1024,0,2048,1280
        WinSet, AlwaysOnTop, On, A
    } else {
        WinMove,A,,168,193,701,906
        WinSet, AlwaysOnTop, Off, A
    }
}

MaximizeToDisplay(WinTitle := "A") {
    WinMove, WinTitle, , -8, 0, A_ScreenWidth + 16, A_ScreenHeight + 8
    WinSet, AlwaysOnTop, On, WinTitle
}

MoveWinHor(Increment := 0, UpperLeftOrCentered := 0) {
    WinSet, Style, +0xC40000, A
    WinGetPos,wX,,,,A
    WinMove,A,,wX+Increment
}

MoveWinVert(Increment := 0, UpperLeftOrCentered := 0) {
    WinSet, Style, +0xC40000, A
    WinGetPos,,wY,,,A
    WinMove,A,,,wY-Increment
}

OpenWorkFolder_ControlClick() {
    SetControlDelay, -1
    IfWinNotActive, ahk_class CabinetWClass
    {
        SendInput #e
        WinWaitActive, ahk_class CabinetWClass, , 3
    }
    ControlClick, SysTreeView321, ahk_class CabinetWClass,,,, NA x80 y58
    SendInput {Space}
    Sleep, 100
    ControlFocus, DirectUIHWND3
    SendInput {Space}
}

OpenWorkFolder_Wintitle() {
    IniRead, path, "D:\AHK Tools\Scripts\_AuxFiles\data.ini", PATHS, WorkFolderPath, "C:\Windows\explorer.exe"
    Run, %path%
}

ResizeWindow(i := 0, FrameOfRef := 0) {
    Global Mon1Left, Mon1Right, Mon1MiddleX, Mon1MiddleY, Mon2MiddleX, Mon2MiddleY
    DetectHiddenWindows, On
    SetTitleMatchMode, 2
    WinSet, Transparent, 1, A
    WinGet, id, ID, A
    WinGetPos, X, Y, W, H, ahk_id %id%
    H := H + i
    W := W + i
    if (FrameOfRef = 0) {
        WinMove, ahk_id %id%,,X,Y,W,H
        WinSet, Transparent, 255, A
        Exit
    } else if (FrameOfRef = 1) {
        X := X - i/2
        Y := Y - i/2
    } else if (FrameOfRef = 2) {
        if (X < 0) {
            X := Mon1MiddleX-W/2
            Y := Mon1MiddleY-H/2
        } else {
            X := Mon2MiddleX-W/2
            Y := Mon2MiddleY-H/2
        }
    }
    WinMove, ahk_id %id%,,X,Y,W,H
    WinSet, Transparent, 255, A
}

ResizeToWorkArea(WinTitle := "A") {
    SysGet, d, MonitorWorkArea
    WinMove, A, , %dLeft% - 8, %dTop%, %dWidth%, %dHeight%
}

RelocateUpperLeftCorner(WinTitle := "A") {
    WinMove, WinTitle, , , , [Width, Height, ExcludeTitle, ExcludeText]
}

SwitchDisplays(winTitle := "A") {
    Global Mon1Right, DefWin_D1_W, DefWin_D1_H, DefWin_D1_X, DefWin_D1_Y, DefWin_D2_X
    ; DISPLAYS
    WinGet, isMaxed, MinMax, %winTitle%
    WinSet, Transparent, 1, %winTitle%
    WinRestore, %winTitle%
    WinGetPos, x1, , , , %winTitle%
    ; DISPLAY 2 --> DISPLAY 1
    if (x1 >= Mon1Right) {
        SendInput #+{Left}
        Sleep, 100
        WinMove, %winTitle%, , DefWin_D1_X, DefWin_D1_Y, DefWin_D1_W, DefWin_D1_H
        if WinActive("ahk_class OpusApp")
            RunMSWordMacro("NavPaneLeft")
    } else {
    ; RESIZE IF MAXED IN DISPLAY 1
        if (isMaxed = 1) {
            WinRestore, A
            WinMove, %winTitle%, , DefWin_D1_X, DefWin_D1_Y, DefWin_D1_W, DefWin_D1_H
            if WinActive("ahk_class OpusApp")
                RunMSWordMacro("NavPaneLeft")
        } else {
    ; DISPLAY 1 --> DISPLAY 2
        WinMove, %winTitle%, , DefWin_D2_X
        Sleep, 100
        WinMaximize, %winTitle%
        if WinActive("ahk_class OpusApp")
            RunMSWordMacro("NavPaneRight")
    }}
    WinSet, Transparent, 255, %winTitle%
}

SwitchDisplays_Word(x1, x2){
    try {
        if (x2 < x1) {
            RunMSWordMacro("NavPaneLeft")
        } else {
            RunMSWordMacro("NavPaneRight")
        }
    } catch {
        throw Exception("Fail", -1)
    }
}

TaskbarDisplayNum(taskbarID := 1) {
    if (taskbarID = 1) {
        return ActiveDisplayID("ahk_class Shell_TrayWnd")
    } else if (taskbarID = 2) {
        return ActiveDisplayID("ahk_class Shell_SecondaryTrayWnd")
    }
}

TaskbarOrientation() {
   gosub, getDisplayDim
    gosub, getTaskBarDim
    i := TaskbarDisplayNum()
    ; MsgBox i:  %i%
    ;   MsgBox % Mon%i%Left
    ;   MsgBox tbh:  %tbh%
    ;   MsgBox tbx:  %tbx%
    ;   MsgBox tby:  %tby%
    ;   MsgBox tbw:  %tbw%
    if (tbx = Mon%i%Left & tbh > tbw) {
        ; MsgBox L
        return "L"
    } else if (tbx = Mon%i%Left & tby = Mon%i%Top) {
        ; MsgBox T
        return "T"
    } else if (tbh > tbw) {
        ; MsgBox R
        return "R"
    } else {
        ; MsgBox B
        return "B"
    }
}
