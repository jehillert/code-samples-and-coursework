#NoEnv
#Persistent
#SingleInstance force

GoSub, SetTrayTip
Gosub, InitializeTrayMenu
SetWorkingDir %A_ScriptDir%
OnMessage(0x404, "AHK_NOTIFYICON")
Return

LBUTTON()
{    SendInput #n
    }
RBUTTON() {
    Menu, Tray, Show
    }
MBUTTON() {
    SendInput #+s
    }

AHK_NOTIFYICON(wParam, lParam) {
    If (lParam = 0x202) {
        LBUTTON()
        Return 1
    } Else If (lParam = 0x205) {
        RBUTTON()
        Return 1
    } Else If (lParam = 0x208) {
        MBUTTON()
        Return 1
    }}

SetTrayTip:
    L1 =[L]Button New Quick Note
    L3 =[M]Button Take Screen Clipping
    L2 =[R]Button Menu
    Menu, Tray, Tip, %L1%`n%L2%`n%L3%
    Return

InitializeTrayMenu:
    Menu, Tray, NoStandard
    Menu, Tray, Add, OPTION_1, OPTION_1Handler
    Menu, Tray, Add, OPTION_2, OPTION_2Handler
    Menu, Tray, Add, Exit, exitHandler
    Menu, Tray, Icon, OPTION_1, %A_ScriptDir%${4:ICON_1}.ico,, 16
    Menu, Tray, Icon, OPTION_2, %A_ScriptDir%${5:ICON_2}.ico,, 16
    Menu, Tray, Icon, Exit, %A_ScriptDir%${6:ICON_3}.ico,, 16
    Return

; HANDLERS
    ; OPTION_1Handler:
    ;     CODE_1
    ;     Return
    ; OPTION_2Handler:
    ;     CODE_2
    ;     Return
    exitHandler:
        CODE_3
        Return

/*  WM_MOUSEFIRST = 0x200 | WM_MOUSEMOVE = 0x200
    WM_LBUTTONDOWN = 0x201 | WM_LBUTTONUP = 0x202 | WM_LBUTTONDBLCLK = 0x203
    WM_RBUTTONDOWN = 0x204 | WM_RBUTTONUP = 0x205 | WM_RBUTTONDBLCLK = 0x206
    WM_MBUTTONDOWN = 0x207 | WM_MBUTTONUP = 0x208 | WM_MBUTTONDBLCLK = 0x209
    WM_MOUSEWHEEL = 0x20A | WM_MOUSEHWHEEL = 0x20E */
