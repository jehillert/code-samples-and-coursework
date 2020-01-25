#NoEnv
#Persistent
#SingleInstance force

SetWorkingDir %A_ScriptDir%
#Include desktop_switcher_fcn.ahk

OnMessage(0x404, "AHK_NOTIFYICON")
Menu, Tray, NoStandard

; TRAY TIP
Line1 =D4      [L]Button
Line2 =D8      [R]Button
Line3 = EXIT   [M]Button
Menu, Tray, Tip, %Line1%`n%Line2%`n%Line3%

return

AHK_NOTIFYICON(wParam, lParam) {
    if (lParam = 0x202){
        switchDesktopByNumber(4)
        return 1
    } else if (lParam = 0x205) {
        switchDesktopByNumber(8)
        return 1
    } else if (lParam = 0x208) {
        ExitApp
        Return 1
    }
}
