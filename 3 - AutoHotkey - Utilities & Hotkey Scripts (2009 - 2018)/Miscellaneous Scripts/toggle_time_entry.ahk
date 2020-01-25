#NoEnv
#Persistent
#SingleInstance force

SendMode Input
SetTitleMatchMode, 2

SetWorkingDir %A_ScriptDir%
pWinTitle := "TIME ENTRY ahk_class XLMAIN"
OnMessage(0x404, "AHK_NOTIFYICON")

Line1 =[L]Button Toggle Time Entry
Line2 =[R]Button Save to SharePoint
Line3 =[M]Button Exit

Menu, tray, Tip, %Line1%`n%Line2%`n%Line3%
menu, tray, NoStandard

AHK_NOTIFYICON(wParam, lParam) {
    if (lParam = 0x202){            ;LB
        RunOrActivate("TIME ENTRY", "C:\Users\JohnH\Documents\Dropbox (SAPC)\Admin\TIME ENTRY.xlsm")
        return 1
    } else if (lParam = 0x204) {    ;RB
        ; Menu, Tray, Show
        SaveToSharePoint()
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

SaveToSharePoint() {
    Try {
        FileDelete, Y:\SAPC Administrative\JHillert\Matter Narratives\Hillert, John - Time Entries*
    } Catch e {
        ShowTrayTip("ERROR - Older version of time entries failed to delete")
        HideTrayTip()
    }
    FormatTime, LastSaved,,dd-MMM-yyyy
    SourceFile := "C:\Users\JohnH\Documents\Dropbox (SAPC)\Admin\TIME ENTRY.xlsm"
    DestinationFile := "Y:\SAPC Administrative\JHillert\Matter Narratives\Hillert, John - Time Entries (" . LastSaved . ").xlsm"
    Try {
        FileCopy %SourceFile%, %DestinationFile%, 1
        ShowTrayTip("Saved to SharePoint on " . LastSaved)
        HideTrayTip()
    } Catch e {
        ShowTrayTip("ERROR - File failed to save.")
        HideTrayTip()
    }
}

ShowTrayTip(msg) {
    TrayTip, , %msg%
    Sleep 2500
}

HideTrayTip() {
    TrayTip  ; Attempt to hide it the normal way.
    if SubStr(A_OSVersion,1,3) = "10." {
        Menu Tray, NoIcon
        Sleep 200  ; It may be necessary to adjust this sleep.
        Menu Tray, Icon
    }
}
