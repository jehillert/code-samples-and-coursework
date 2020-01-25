/*
    Script for opening different email applications from win10
    tray icon.

    DESCRIPTION: Creates a persistent tray icon in Win10
    that provides a menu when clicked.  The menu provides
    links to gmail, yahoo mail, and Outlookmail accounts.
    Each email opens in a dedicated chrome window that
    shows only the email application.

    NOTE: Apps must first be created by chrome.  Using the
    'create shortcut' found in the 'More tools' submenu of
    Chrome's main menu.

    NOTE: "app-id" codes below will need to be recreated
    if user data for Chrome is deleted or if this executable
    is used on another computer.
*/

; AUTO-EXECUTE
#NoEnv
#Persistent
#SingleInstance force
GoSub, SetMenuTrayTip
Gosub, InitializeTrayMenu
SetWorkingDir %A_ScriptDir%
OnMessage(0x404, "AHK_NOTIFYICON")
Return

; MOUSE COMMANDS
LBUTTON() {
    Run "C:\Program Files (x86)\Google\Chrome\Application\chrome.exe"  --profile-directory=Default --app-id=kmhopmchchfpfdcdjodmpfaaphdclmlj
}
RBUTTON() {
    Menu, Tray, Show
}
MBUTTON() {
    ExitApp
}

; FUNCTIONS
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

; SUBROUTINES
InitializeTrayMenu:
    Menu, Tray, NoStandard
    Menu, Tray, Add, Gmail, GmailHandler
    Menu, Tray, Add, OutlookMail, OutlookMailHandler
    Menu, Tray, Add, Yahoo Mail, YahooMailHandler
    Menu, Tray, Icon, Gmail, %A_ScriptDir%\icons\gmail.ico,, 16
    Menu, Tray, Icon, OutlookMail, %A_ScriptDir%\icons\OutlookMail.ico,, 16
    Menu, Tray, Icon, Yahoo Mail, %A_ScriptDir%\icons\YahooMail.ico,, 16
    Return
SetMenuTrayTip:
    L1 =[L]Button      Open Gmail
    L2 =[R]Button      Email Menu
    L3 =[M]Button     Exit
    Menu, Tray, Tip, %L1%`n%L2%`n%L3%
    Return

; HANDLERS
GmailHandler:
    Run "C:\Program Files (x86)\Google\Chrome\Application\chrome.exe"  --profile-directory=Default --app-id=kmhopmchchfpfdcdjodmpfaaphdclmlj
    Return
YahooMailHandler:
    Run "C:\Program Files (x86)\Google\Chrome\Application\chrome.exe"  --profile-directory=Default --app-id=hdiplghhfmdffgajaocfolcilpobigmc
    Return
OutlookMailHandler:
    Run "C:\Program Files (x86)\Google\Chrome\Application\chrome.exe"  --profile-directory=Default --app-id=dnfhhlehgfipnnanmnahfkhmebmdpkef
    Return


