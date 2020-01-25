#NoEnv
#Persistent
#SingleInstance force

SetWorkingDir %A_ScriptDir%

OnMessage(0x404, "AHK_NOTIFYICON")
Menu, Tray, NoStandard

; TRAY TIP
Line1 =[L]Button Desktop Left
Line2 =[R]Button Task Switcher
Line3 =[M]Button Exit
Menu, Tray, Tip, %Line1%`n%Line2%`n%Line3%

return

; TRAY WIDGET HOTKEYS
AHK_NOTIFYICON(wParam, lParam) {
    if (lParam = 0x202){
        SendInput #^{left}
        return 1
    } else if (lParam = 0x205) {
        SendInput !{Escape}#!{left}
        return 1
    } else if (lParam = 0x208) {
        ExitApp
        Return 1
    }
}




