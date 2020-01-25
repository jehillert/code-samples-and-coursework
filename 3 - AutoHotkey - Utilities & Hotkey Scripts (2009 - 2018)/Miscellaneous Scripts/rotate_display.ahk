; ************************************************************
; Persistent tray icon that provides a menu for rotating
; the screen of a given display. (Windows 10)
; ************************************************************

; VARIABLES
#NoEnv
#Persistent
#SingleInstance force
#KeyHistory 100

; SETTINGS
SendMode Input
SetTitleMatchMode, 2

; DIRECTORIES
scripts_folder := parent_folder(A_ScriptDir)
SetWorkingDir %scripts_folder%

; MENU DECLARATIONS
Menu, tray, Icon, icons/processes/RotateDisplay1.ico
Menu, tray, NoStandard
Menu, tray,Color, White, Single

Menu, tray, add

Menu, tray, add, Rotate 0, Rotate0
Menu, tray, add, Rotate 90, Rotate90
Menu, tray, add, Rotate 180, Rotate180
Menu, tray, add, Rotate 270, Rotate270

Menu, tray, Icon, Rotate 0, icons/processes/monIA.ico,,0
Menu, tray, Icon, Rotate 90, icons/processes/monIIA.ico,,0
Menu, tray, Icon, Rotate 180, icons/processes/monIIIA.ico,,0
Menu, tray, Icon, Rotate 270, icons/processes/monIIIIA.ico,,0

Menu, tray, add

Menu, tray, add, Exit Script, Exit_Handler
Menu, tray, Icon, Exit Script, icons/processes/door.ico,,0

Menu, tray, Default, Exit Script

; END OF AUTO-EXECUTE
return

; MENU HANDLERS
Rotate0: ;assumes right monitor is vertical
    MouseGetPos, xpos, ypos
    MouseMove, 1900,500
    SendInput ^+2
    MouseMove, xpos,ypos
    return
Rotate90:
    MouseGetPos, xpos, ypos
    MouseMove, 1900,500
    SendInput ^+1
    MouseMove, xpos,ypos
    return
Rotate180:
    MouseGetPos, xpos, ypos
    MouseMove, 1900,500
    SendInput ^+4
    MouseMove, xpos,ypos
    return
Rotate270:
    MouseGetPos, xpos, ypos
    MouseMove, 1900,500
    SendInput ^+3
    MouseMove, xpos,ypos
    return
Exit_Handler:
    ExitApp
    return

;INCLUDE (This was an old script.  Following files have since been deleted.)
#Include C:\Users\jhillert\Dropbox\Programs\Scripts\PROCESSES\[INCLUDE]\tray_folder_functions.ahk
#Include C:\Users\jhillert\Dropbox\Programs\Scripts\FUNCTIONS\explorer.ahk
