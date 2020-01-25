#if WinActive("ahk_class Qt5QWindowToolTipSaveBits")
    c::SendInput ^!+c   ; copy
    d::SendInput ^!+d   ; draw
    q::
    escape::SendInput ^!+q ; cancel
    p::SendInput ^!+q ; panel
#if WinActive("ahk_class XLMAIN")
    NumLock::SendInput {Tab}
    WheelRight::
    ^Tab::SendInput ^{PgDn}
    WheelLeft::
    ^+Tab::SendInput ^{PgUp}
#if WinActive("- Notepad")
    Numlock::SendInput ]{Left}^{Left}[^{Right}
