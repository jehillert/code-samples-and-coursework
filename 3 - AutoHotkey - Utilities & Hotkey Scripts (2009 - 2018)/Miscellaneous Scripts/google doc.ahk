; ************************************************************
; This script always opens the same google doc.
; The doc is opened from a persistent tray icon.
; (Windows 10)
; ************************************************************

#NoEnv
#Persistent
#SingleInstance force
GoSub, SetMenuTrayTip
Gosub, InitializeTrayMenu
SetWorkingDir %A_ScriptDir%
OnMessage(0x404, "AHK_NOTIFYICON")
Return

LBUTTON() {
    Run "C:\Program Files (x86)\Google\Chrome\Application\chrome.exe"  --profile-directory=Default --app-id=bojccfnmcnekjgjhcaklmcgofnngpjcl
}

RBUTTON() {
    Menu, Tray, Show
}

MBUTTON() {
    ExitApp
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
    }
}

InitializeTrayMenu:
    Menu, Tray, NoStandard
    Menu, Tray, Add, Open Google Docs, google_docs_handler
    Menu, Tray, Add, Exit, exit_handler
    ; Menu, Tray, Icon, Open Google Docs, %A_AhkPath%, 1
    Return

SetMenuTrayTip:
    L1 =[L]Button Open Gmail
    L2 =[R]Button Email Menu
    L3 =[M]Button Exit
    Menu, Tray, Tip, %L1%`n%L2%`n%L3%
    Return

; HANDLERS
google_docs_handler:
    Run "C:\Program Files (x86)\Google\Chrome\Application\chrome.exe"  --profile-directory=Default --app-id=bojccfnmcnekjgjhcaklmcgofnngpjcl
    Return

exit_handler:
    Exit App
    Return


