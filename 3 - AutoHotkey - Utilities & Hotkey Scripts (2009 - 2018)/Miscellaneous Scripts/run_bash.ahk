#NoEnv
#Persistent
#SingleInstance force

SetWorkingDir %scripts_folder%
process_ifldr := "C:\Users\jhillert\Dropbox\Programs\Scripts\icons\processes"

; MENU
OnMessage(0x404, "AHK_NOTIFYICON")
Menu, Tray, NoStandard
Menu, Tray, Icon, %process_ifldr%\gitbash.ico

; TEXT ON HOVER
Line1 =[L]Button Run Bash
Line2 =[R]Button Terminate Hosting
Line3 =[M]Button Exit
Menu, tray, Tip, %Line1%`n%Line2%`n%Line3%

return

AHK_NOTIFYICON(wParam, lParam) {
    if (lParam = 0x202){
        Run "C:\Program Files\Git\git-bash.exe" --cd="C:\Users\jhillert\Google Drive\JavaScript\HIGHLIGHTER"
        WinWaitActive, MINGW64 ahk_class mintty ahk_exe mintty.exe
        SendInput npm{Space}start{Enter}
        WinMinimize, A
        return 1
    } else if (lParam = 0x205) {
        WinActivate, MINGW64 ahk_class mintty ahk_exe mintty.exe
        SendInput ^c
        return 1
    } else if (lParam = 0x208) {
        ExitApp
        return 1
    }
}

Morse(timeout = 250)    {
    ; Morse function courtesy of AutoHotkey forum
    tout := timeout/1000
    key := RegExReplace(A_ThisHotKey,"[\*\~\$\#\+\!\^]")
    Loop
    {
        t := A_TickCount
        KeyWait %key%
        Pattern .= A_TickCount-t > timeout
        KeyWait %key%,DT%tout%
        if (ErrorLevel)
        return Pattern
    }
}

parent_folder(p_child_folder){
    SplitPath, p_child_folder, , parent_folder
    return parent_folder
}
