#if WinActive("Highlighter ahk_class AutoHotkeyGUI")
SC029::Gui, Highlighter:Cancel
~LButton Up::
    if (WinUnderMouse() != "Highlighter ahk_class AutoHotkeyGUI")
        Gui, Highlighter:Hide
    return
