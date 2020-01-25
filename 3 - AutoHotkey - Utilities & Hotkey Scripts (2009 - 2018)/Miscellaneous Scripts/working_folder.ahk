#NoEnv
#Persistent
#SingleInstance force

SendMode Input
SetTitleMatchMode, 2

scripts_folder := parent_folder(A_ScriptDir)
SetWorkingDir %scripts_folder%

; MENU
OnMessage(0x404, "AHK_NOTIFYICON")
Menu, tray, Icon, icons/processes/work_folder.ico

; TRAY TIP
Menu, tray, Tip,[L]Button   Open Work Folder
Line1 =[L]Button Open Work Folder
Line2 =[M]Button Assign Work Folder
Line3 =[R]Button Menu
Menu, tray, Tip, %Line1%`n%Line2%`n%Line3%

return

AHK_NOTIFYICON(wParam, lParam) {
    if (lParam = 0x202){
        OpenWFFromTray()
        return 1
    } else if (lParam = 0x204) {
        Menu, tray, show
        return 1
    } else if (lParam = 0x208) {
        suppress_context_menu(20)
        SendInput !{Tab}
        sleep 500
        If (WinActive("ahk_class CabinetWClass") || WinActive("ahk_group DialoguesGroup"))
            AssignWFFromTray()
        return 1
    }
}

; Old script, and the following files deleted.
#Include C:\Users\jhillert\Dropbox\Programs\Scripts\PROCESSES\[INCLUDE]\tray_folder_functions.ahk
#Include C:\Users\jhillert\Dropbox\Programs\Scripts\FUNCTIONS\explorer.ahk
