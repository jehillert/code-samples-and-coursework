/*
    PERSISTENT TRAY ICON

    Provides persistent Win10 tray icon.  Tray icon provides
    the following commands:

        - reload and exit scripts_main.ahk
        - access Autohotkey Windowspy utility
        - open Autohotkey help file
        - open scripts_main source code for editing
        - open and control 'spots' sub-script
*/

LBUTTON() {
    Suspend
}

MBUTTON() {
    Reload
}

RBUTTON() {
    Menu, Tray, Show
}

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
    }}

SetTrayTip:
    L1 =[L]Button1     Suspend
    L2 =[M]Button      Reload
    L3 =[R]Button       Menu
    Menu, Tray, Tip, %L1%`n%L2%`n%L3%
    return

InitializeTrayMenu:
    Menu, tray, Icon, auxiliary_files/autotext.ico
    Menu, tray, Color, FFFFFF
    Menu, tray, NoStandard
    Menu, tray, Add, Help, HelpHandler
    Menu, tray, Add
    Menu, tray, Add, Edit in Sublime, EditHandler
    Menu, tray, Add, Reload This Script (MB), ReloadHandler
    Menu, tray, Add, Window Spy, WindowSpyHandler
    Menu, tray, Add,
    Menu, tray, Add, Run Spots, SpotsHandler
    Menu, tray, Add, Toggle Spots, ToggleSpotsHandler

    Menu, tray, Add,
    Menu, tray, Add, Exit, ExitHandler
    return

HelpHandler:
    if WinExist("Autohotkey Help")
        RunOrActivate("AutoHotkey Help", "C:\Program Files\AutoHotkey\AutoHotkey.chm", "Internet Explorer_Server1")
    else
        RunOrActivate("AutoHotkey Help", "C:\Program Files\AutoHotkey\AutoHotkey.chm", "Edit1")
    return

EditHandler:
    OpenSublime("AHK Scripts", "AHK Scripts.sublime-workspace")
    return

ReloadHandler:
    Reload
    return

SpotsHandler:
    RunSpots()
    return

ToggleSpotsHandler:
    ToggleSpots()
    return

WindowSpyHandler:
    run, "C:\Program Files\AutoHotkey\WindowSpy.ahk"
    return

ExitHandler:
    ExitApp
    return
