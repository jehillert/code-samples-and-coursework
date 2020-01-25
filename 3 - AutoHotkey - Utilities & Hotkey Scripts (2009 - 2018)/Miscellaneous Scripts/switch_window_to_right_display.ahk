#NoEnv
#Persistent
#SingleInstance force

SetWorkingDir %A_ScriptDir%

OnMessage(0x404, "AHK_NOTIFYICON")
Menu, Tray, NoStandard

Line1 =[L]Button Desktop Right
Line2 =[R]Button Task Switcher
Line3 =[M]Button Exit
Menu, Tray, Tip, %Line1%`n%Line2%`n%Line3%

return

AHK_NOTIFYICON(wParam, lParam) {
if (lParam = 0x202){
    ; SendInput #{Tab}
    SendInput #^{right}
    return 1
} else if (lParam = 0x205) {
    ; SendInput !^{Tab}
    SendInput !{Escape}#!{right}
    return 1
} else if (lParam = 0x208) {
    ExitApp
    Return 1
}}
