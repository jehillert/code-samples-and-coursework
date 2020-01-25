RButton & MButton::SendInput ^/
MButton::OnTitleBarClick("{Enter}", "{MButton}", "{MButton}",  "{MButton}", 0)
F21 & F22::SendInput {AltDown}{Tab}{AltUp}
F21 & RButton:: ;space
    SuppressContextMenu()
    SendInput {Space}
    return
RButton & F21::SendInput {Space}
RButton & F22:: ;paste
    SuppressContextMenu()
    SendInput ^v
    return
RButton & WheelRight::
    SuppressContextMenu()
    SendInput #{Right}
    return
RButton & WheelLeft::SendInput #{Left}
RButton & WheelUp::SendInput {Volume_Up}
RButton & WheelDown::SendInput {Volume_Down}
RButton & XButton1::SendInput #e
XButton1 & XButton2::SendInput ^{Home}
XButton2 & XButton1::SendInput ^{End}
XButton1 & F21::SendInput ^{WheelDown}
XButton1 & F22::SendInput ^{WheelUp}
XButton1 & LButton::SendInput ^z
XButton1 & RButton:: ;redo
    SuppressContextMenu()
    SendInput ^y
    return
XButton1 & WheelLeft::SendInput ^{[}
XButton1 & WheelRight::SendInput ^{]}
F7::
    if (WinActive("- Sublime Text") || WinActive("- Google Chrome") || WinActive("- Opera")) {
        SendInput ^w
    } else {
        SendInput !{F4}
    }
    return
F21::SendInput {Backspace}
F22::SendInput ^x
WheelLeft::SendInput ^{PgUp}
WheelRight::SendInput ^{PgDn}
^SC029::MoveIt("tall")
^WheelRight::SendInput #\
!F1::Captures()
#+d::SendInput !^+d
Capslock & j::SendInput {Home}
Capslock & k::SendInput {End}
#j::SendInput {Right}
^AppsKey::
    SuppressContextMenu(10, AppsKey)
    SendInput {Alt Down}{Control Down}{Tab}{Alt Up}{Control Up}
    return
Capslock & p::SendInput `%
Capslock & a::SendInput {AltDown}{Control Down}{Tab}{AltUp}{Control Up}
Delete & End::SendInput, {Control Down}{AltDown}{Tab}{Control Up}{AltUp}
^+Delete::SendInput ^+{Delete}
^Delete::SendInput ^{Delete}
+Delete::SendInput +{Delete}
!Delete::SendInput  !{Delete}
End & Delete::SendInput, {Control Down}{AltDown}{Tab}{Control Up}{AltUp}
^+End::SendInput ^+{End}
^End::SendInput ^{End}
+End::SendInput +{End}
!End::SendInput  !{End}
End::SendInput {End}
Delete::SendInput {Delete}
#h::OpenSublime("hack_reactor", "W:\Dropbox (Personal)\Hack Reactor\_hack_reactor.sublime-project")
#k::OpenSublime("SCRIPTS", "SCRIPTS.sublime-project")
#+k::RunOrActivate("AutoHotkey Help", ahk_help_path, "Internet Explorer_Server1")
#+m::SendInput #m
#n::RunOrActivate("Notepad", notepad.exe)
#!n::run, notepad.exe
#o::Run %chrome_exe_path%
#w::SendInput #e;
+Insert::SendInput +{Insert}
!Insert::SendInput !{Insert}
!+Insert::SendInput !+{Insert}
^Insert::SendInput ^{Insert}
^!Insert::SendInput ^!{Insert}
^+Insert::SendInput ^+{Insert}
Insert::SendInput {Alt Down}{Tab}{Alt Up}
!~LButton::SendInput {Enter}
LShift & WheelLeft::SendInput ^z
LShift & WheelRight::SendInput ^y
#Numpad1::MoveIt(1)
#Numpad2::MoveIt(2)
#Numpad3::MoveIt(3)
#Numpad4::MoveIt(4)
#Numpad5::MoveIt(5)
#Numpad6::MoveIt(6)
#Numpad7::MoveIt(7)
#Numpad8::MoveIt(8)
#Numpad9::MoveIt(9)
NumpadSub & NumpadMult::SendInput `,
NumpadMult & NumpadDiv::SendInput :
NumpadMult & NumpadSub::SendInput :
Numlock::SendInput ]{Left}^{Left}[^{Right}{Right}
NumpadDiv::NumpadDiv
NumpadMult::SendInput {NumpadMult}
NumpadSub::SendInput {NumpadSub}
RWin & '::msgbox it worked
RWin::
    if WinActive("- Google Chrome") {
            SendInput ^w
    } else if WinActive("- Sublime Text") {
        SendInput ^!+w
        SendInput !{F4}
        Sleep 400
    } else {
        SendInput !{F4}
    } return
ScrollLock::MoveIt("default")
XButton1::SendInput {XButton1}
XButton2::SendInput {XButton2}
RButton::
    Keywait RButton
    if (A_ThisHotkey != "RButton") {
        SendInput {Escape}
    } else {
        SendInput {RButton}
    }
    return
    ; WheelLeft::OnTitleBarClick("{%A_ThisHotkey%}", "#^{Left}", "!#{Left}",  "WheelLeft", 0)
    ; WheelRight::OnTitleBarClick("{%A_ThisHotkey%}", "#^{Right}", "!#{Right}", "WheelRight", 0)
    /*
    WinGet, active_id, ID, A
    active_win := "ahk_id " active_id
    WinGetClass, active_win_class, A
    if (MouseIsOver("ahk_class NotifyIconOverflowWindow") || ControlUnderMouse("ToolbarWindow323")) {
        SendInput {%A_ThisHotkey%}
    } else if MouseIsOver("ahk_class CabinetWClass") {
        tmsg("use rbutton & lbutton")
    } else {
        SendInput {Enter}
    } return
    */
