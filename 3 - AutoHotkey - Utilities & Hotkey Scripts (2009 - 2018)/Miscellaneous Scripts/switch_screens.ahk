#NoEnv
#Persistent
#SingleInstance force

SetWorkingDir %A_ScriptDir%
OnMessage(0x404, "AHK_NOTIFYICON")

Line1 = [L]Button/[R]Button Switch Screens
Line2 = [M]Button Exit

Menu, Tray, Tip, %Line1%`n%Line2%

return

AHK_NOTIFYICON(wParam, lParam) {
    if (lParam = 0x202) {
        SendInput !{Escape}

        SwitchDisplays()

        return 1
    } else if (lParam = 0x205) {
            Menu, Tray, Show
       } else if (lParam = 0x208) {
            ExitApp
        return 1
    }
}

RunMSExcelMacro(MacroName) {
    oExcel := ComObjActive("Excel.Application")
    oExcel.Run(MacroName)
}

RunMSWordMacro(MacroName) {
    oWord := ComObjActive("Word.Application")
    oWord.Run(MacroName)
}

SwitchDisplays() {
    WinSet, Transparent, 1, A
    WinGetPos, x1, , , , A
    SendInput #+{Left}
    Sleep 100
    WinGetPos, x2, , , , A
    If WinActive("ahk_class OpusApp") {
        SwitchDisplays_Word(x1, x2)
    }
    WinSet, Transparent, 255, A
}

SwitchDisplays_Word(x1, x2){
    If (x2 < x1) {
        RunMSWordMacro("NavPaneLeft")
    } Else {
        RunMSWordMacro("NavPaneRight")
    }
}
