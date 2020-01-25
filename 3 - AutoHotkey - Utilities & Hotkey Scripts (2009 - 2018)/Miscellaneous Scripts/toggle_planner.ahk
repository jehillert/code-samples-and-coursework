#NoEnv
#Persistent
#SingleInstance force

SendMode Input
SetTitleMatchMode, 2

SetWorkingDir %A_ScriptDir%
OnMessage(0x404, "AHK_NOTIFYICON")

Line1 =[L]Button Toggle Planner
Line2 =[R]Button Menu
Line3 =[M]Button Exit
Menu, tray, Tip, %Line1%`n%Line2%`n%Line3%

AHK_NOTIFYICON(wParam, lParam) {
    if (lParam = 0x202){            ;LB
        IniRead, planner_path, ahk_tray_exe.ini, PATHS, planner_path
        RunOrActivate("PLANNER", planner_path)
        return 1
    } else if (lParam = 0x204) {    ;RB
        Menu, Tray, Show
        return 1
    } else if (lParam = 0x208) {    ;MB
        ExitApp
        return 1
    }
}

RunOrActivate(WinTitle, Target) {
    IfWinExist, %WinTitle%
        WinActivate, %WinTitle%
    else
        Run, %Target%
}

RunMSExcelMacro(MacroName) {
  oExcel := ComObjActive("Excel.Application")
  oExcel.Run(MacroName)
}
