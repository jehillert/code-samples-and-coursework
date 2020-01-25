#if WinActive("ahk_class PotPlayer64")
F6::SendInput ^{F6}
F7::SendInput !{F4}
F21::SendInput {RButton}
F1::SendInput {F1}
Home & PgUp::SendInput !#{Right}
SC035::SendInput {Alt Down}{Control Down}{Tab}{Control Up}{Alt Up}
Home & Insert::SendInput !#{Left}
PgDn::SendInput {F1}
SC033 & SC034::SendInput {, 6}
SC034 & SC033::SendInput {. 6}
Space & SC033::SendInput {, 12}
Space & SC034::SendInput {. 12}
SC033::SendInput {,}
SC034::SendInput {.}
MButton::SendInput {Enter}
NumpadAdd::SendInput ^{Up 50}
NumpadSub::SendInput ^{Down 50}
Numpad8::SendInput {Numpad8 20}
Numpad2::SendInput {Numpad2 20}
Numpad3::SendInput {Numpad6 1}
Numpad6::SendInput {Numpad6 20}
Numpad4::SendInput {Numpad4 20}
Numpad1::SendInput {Numpad4 1}
#F3::SendInput !{F4}
WheelUp::
    MouseGetPos,,Y
    if Y < 60
        SendInput {Volume_Up 3}
    else
        SendInput {WheelUp 3}
    return
WheelDown::
    MouseGetPos,,Y
    if Y < 60
        SendInput {Volume_Down}
    else
        SendInput {WheelDown}
    return
WheelRight::SendInput {RButton}
WheelLeft::SendInput !{F4}
RButton::SendInput p
Space::SendInput {Space}

#if WinActive("Task View ahk_class Windows.UI.Core.CoreWindow")
SC033::SendInput {Left}
SC034::SendInput {Right}
