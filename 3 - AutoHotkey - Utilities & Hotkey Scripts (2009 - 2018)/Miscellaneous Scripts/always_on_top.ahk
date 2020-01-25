; ******************************************************
;
;  This script provides a persistent Win10 tray widget
;  that sets the active window to AlwaysOnTop
;
; ******************************************************

#NoEnv
#Persistent
#SingleInstance force

L1 =[L]Button Toggle 'AlwaysOnTop' on and off.
L2 =[R]Button Set 'AlwaysOnTop' to off.
L3 =[M]Button Exit Script.
SetWorkingDir %A_ScriptDir%
OnMessage(0x404, "AHK_NOTIFYICON")
Menu, Tray, Tip, %L1%`n%L2%`n%L3%
Menu, Tray, NoStandard
return

; HOTKEYS
LBUTTON() {
    SendInput !{Tab}
    sleep 500
    WinSet, AlwaysOnTop, toggle, A
    ShowTrayTip()
    HideTrayTip()
}

RBUTTON() {
    SendInput !{Tab}
    sleep 500
    WinSet, AlwaysOnTop, Off, A
    ShowTrayTip()
        HideTrayTip()
}

MBUTTON() {
    ExitApp
}

; FUNCTIONS
AHK_NOTIFYICON(wParam, lParam) {
    if (lParam = 0x202) {
        LBUTTON()
        return 1
    } else if (lParam = 0x205) {
        RBUTTON()
        return 1
    } else if (lParam = 0x208) {
        MBUTTON()
        return 1
    }
}

ShowTrayTip() {
    WinGet, ExStyle, ExStyle, A
    {
        if (ExStyle & 0x8)
            ExStyle = AlwaysOnTop is on.
        else
            ExStyle = AlwaysOnTop is off.
    }
    TrayTip, , %exstyle%
    Sleep 2500
}

HideTrayTip() {
    TrayTip    ; Attempt to hide it the normal way.
    if SubStr(A_OSVersion,1,3) = "10." {
            Menu Tray, NoIcon
            Sleep 200    ; It may be necessary to adjust this sleep.
            Menu Tray, Icon
    }
}

RunAsAdmin(){
    if(! A_IsAdmin) {
        ;dll calls window movers will not work without admin
        Run *RunAs "%A_ScriptFullPath%"    ; Requires v1.0.92.01+
        ExitApp
    }
}
