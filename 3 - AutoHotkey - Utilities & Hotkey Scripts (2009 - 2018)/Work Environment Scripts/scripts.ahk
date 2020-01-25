;************************************************************************
; ENVIRONMENT
;************************************************************************
#NoEnv
#Persistent
#SingleInstance force
#HotkeyInterval 4000  ; This is  the default value (milliseconds).
#MaxHotkeysPerInterval 600
#InstallKeybdHook

;************************************************************************
; SETTINGS
;************************************************************************
SendMode Input
SetNumlockState, AlwaysOn
SetScrollLockState, AlwaysOff
SetTitleMatchMode, 2
OnExit, ShowCursor
SetWorkingDir %A_ScriptDir%

;************************************************************************
; WINDOW & DISPLAY DIMENSIONS
;************************************************************************
Gosub getDisplayDim
Gosub getWorkArea
Gosub getTaskBarDim
Gosub getOtherGlobals

;************************************************************************
; TRAY MENU
;************************************************************************
Gosub, SetTrayTip
Gosub, InitializeTrayMenu
OnMessage(0x404, "AHK_NOTIFYICON")

;************************************************************************
; GROUPS
;************************************************************************
GroupAdd, SystemWindows, Start ahk_class Windows.UI.Core.CoreWindow
GroupAdd, SystemWindows, ahk_class Windows.UI.Core.CoreWindow
GroupAdd, SystemWindows, ahk_class ahk_exe SearchUI.exe
GroupAdd, SystemWindows, ahk_class #32770

;************************************************************************
#Include ms_word_highlighter_gui\gofer_pallet.ahk
return

;************************************************************************
; MAIN
;************************************************************************
#Include hotkey_configurations/_miscellaneous.ahk
#Include hotkey_configurations/art_&_media.ahk
#Include hotkey_configurations/browsers.ahk
#Include hotkey_configurations/chrome_devtools.ahk
#Include hotkey_configurations/file_explorer.ahk
#Include hotkey_configurations/foxit.ahk
#Include hotkey_configurations/potplayer64.ahk
#Include hotkey_configurations/sublime.ahk
#Include hotkey_configurations/word.ahk
#Include hotkey_configurations/zoom.ahk
#IfWinActive
#Include hotkey_configurations/_global.ahk

;************************************************************************
; FUNCTIONS & SUBROUTINES
;************************************************************************
#Include functions/general_functions.ahk
#Include functions/mouse_functions.ahk
#Include functions/moveit_window_resizing_function.ahk
#Include functions/functions_for_spots_utility.ahk
#Include functions/window_functions.ahk
#Include subroutines/subroutines.ahk

;************************************************************************
; AUTOTEXT
;************************************************************************
#Include autotext/autotext.ahk

;************************************************************************
; TRAY WIDGET
;************************************************************************
#Include tray_widget/tray_widget.ahk
