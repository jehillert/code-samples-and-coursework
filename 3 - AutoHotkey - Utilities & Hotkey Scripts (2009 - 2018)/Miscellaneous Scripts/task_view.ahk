#NoEnv
#Persistent
#SingleInstance force
SendMode Input

OnMessage(0x404, "AHK_NOTIFYICON")

Line1 =[L]Button Task View
Line2 =[R]Button Menu
Line3 =[M]Button Exit
Menu, tray, Tip, %Line1%`n%Line2%`n%Line3%

AHK_NOTIFYICON(wParam, lParam) {
    Global path_to_planner
    if (lParam = 0x202){            ;LB
        SendInput #{Tab}
        return 1
    } else if (lParam = 0x204) {    ;RB
        Menu, Tray, Show
        return 1
    } else if (lParam = 0x208) {    ;MB
        ExitApp
        return 1
    }
}

