EraseMarkup:
    RunMSWordMacro("EraseMarkup")
    return

toggleGlobalViewState:
    RunMSWordMacro(A_ThisLabel)
    return

highlight_unhighlight:
    RunMSWordMacro("UnHighlight")
    return

highlight_blue:
    RunMSWordMacro(A_ThisLabel)
    return

highlight_bright_green:
    RunMSWordMacro(A_ThisLabel)
    return

highlight_dark_gray:
    RunMSWordMacro(A_ThisLabel)
    return

highlight_light_gray:
    RunMSWordMacro(A_ThisLabel)
    return

highlight_pink:
    RunMSWordMacro(A_ThisLabel)
    return

highlight_turquoise:
    RunMSWordMacro(A_ThisLabel)
    return

highlight_yellow:
    RunMSWordMacro(A_ThisLabel)
    return

highlight_black:
    RunMSWordMacro(A_ThisLabel)
    return

highlight_dark_blue:
    RunMSWordMacro(A_ThisLabel)
    return

highlight_dark_red:
    RunMSWordMacro(A_ThisLabel)
    return

highlight_dark_yellow:
    RunMSWordMacro(A_ThisLabel)
    return

highlight_green:
    RunMSWordMacro(A_ThisLabel)
    return

highlight_red_white:
    RunMSWordMacro(A_ThisLabel)
    return

highlight_teal:
    RunMSWordMacro(A_ThisLabel)
    return

highlight_violet:
    RunMSWordMacro(A_ThisLabel)
    return


CallHLP() {
    Global LastFoundTitle
    if (LastFoundTitle != "Highlighter") {
        if (A_PriorHotkey <> "~LButton Up" or A_TimeSincePriorHotkey > 400) {
            if (textSelected() && !WinActive("Highlighter ahk_class AutoHotkeyGUI")) {
                ShowHLP()
            }
        } else {
            RunMSWordMacro("SelectWord")
            ShowHLP()
        } return
    } else {
        LastFoundTitle := ""
    }
}

ShowHLP() {
    Global pHeight, pWidth
    WinGetTitle, winParent, A
    hX := 0
    hy := 0
    MouseGetPos, hX, hY
    Sleep 50
    X := hX + 500
    Y := hY - 8
    Gui, Highlighter:Show, x%X% y%Y% h%pHeight% w%pWidth%, Highlighter
    WinActivate, %winParent%
    KeyWait, LButton, D T2
    HideHLP()
    Exit
}

HideHLP() {
    Global LastFoundTitle
    Gui, Highlighter:+LastFound
    WinGetTitle, LastFoundTitle
    Gui, Highlighter:Hide
}

HighlighterGuiEscape:
    Global LastFoundTitle
    Gui Highlighter:+LastFound
    WinGetTitle, LastFoundTitle
    Gui, Highlighter:Hide
    return
