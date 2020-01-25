#if WinActive("- Sublime")
^r::
    WinActivate, ahk_class Chrome_WidgetWin_1 ahk_exe chrome.exe
    SendInput ^r
    return
^SC34::SendInput !{Numpad7}
^Numpad2::SendInput {Control Down}{k}{Control Up}{Down}
^Numpad8::SendInput {Control Down}{k}{Control Up}{Up}
^Numpad4::SendInput {Control Down}{k}{Control Up}{Left}
^Numpad6::SendInput {Control Down}{k}{Control Up}{Right}
^SC029::SendInput {Control Down}{SC029}{Control Up}
^Tab::SendInput ^{PgDn}
^+Tab::SendInput ^{PgUp}
^b::SendInput ^s^b
+SC029::SendInput +{SC029}
#F3::SendInput ^/
#s::
    SendInput !fl
    reload
    return
Alt & WheelUp::SendInput !{Up}
Alt & WheelDown::SendInput !{Down}
Capslock & Up::SendInput !+{Up}
Capslock & Down::SendInput !+{Down}
SC029 & Right::SendInput {Control Down}{k}{Control Up}{Right}
SC029 & Down::SendInput {Control Down}{k}{Control Up}{Down}
SC029 & Up::SendInput {Control Down}{k}{Control Up}{Up}
SC029 & Left::SendInput {Control Down}{k}{Control Up}{Left}
SC029::SendInput {SC029}
RButton & WheelUp::SendInput ^+{Up}
RButton & WheelDown::SendInput ^+{Down}
XButton2 & WheelLeft::OnTitleBarClick("^{[}", "{WheelLeft}", "{WheelLeft}", "{WheelLeft}", 0)
XButton2 & WheelRight::OnTitleBarClick("^{]}", "{WheelRight}", "{WheelRight}", "{WheelRight}", 0)
XButton1::SendInput ^x;
LButton & RButton::SendInput ^/
~RButton Up::OnTitleBarClick("{RButton}", "^{home}^k^1", "^k^j", "{RButton}", 50)
RButton::
    Keywait RButton
    if (A_ThisHotkey = "XButton1 & RButton") {
        return
    } else if (A_ThisHotkey != "RButton" && A_PriorKey != "RButton") {
        SendInput {Escape}
    } else {
        return
    }
    return
