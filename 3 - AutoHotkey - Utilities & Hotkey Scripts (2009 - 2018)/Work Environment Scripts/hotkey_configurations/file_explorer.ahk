#if WinActive("ahk_class CabinetWClass")
F7::SendInput !{F4}
!1::
    SetWorkFolder()
    SendInput !1
    return
!a::Gosub FileFocus
!q::
    ControlFocus, SysTreeView321
    SendInput {Home}{Down}
    return
RButton & LButton::FileExplorerActions()
XButton2::SendInput !{Right}
XButton1::SendInput !{Left}
FileFocus:
    ControlFocus, DirectUIHWND3
    Sleep, 50
    SendInput {Space}
    return
FileFocusCapslock: ; FIGURE OUT HOW TO DETECT F2 RENAME
    ControlGetFocus, fC, A
    SetStoreCapsLockMode, Off
    if ((fC = "DirectUIHWND1") || (fC = "Edit1")) {
        Send {Capslock}
    } else if (fC != "DirectUIHWND3") {
        ControlFocus, DirectUIHWND3
        Sleep, 50
        SendInput {Space}
    } else {
        Send {Capslock}
    }
    return
NavigateToWorkFolder:
    ControlFocus, SysTreeView321
    Sleep, 50
    SendInput {Home}{Down}{Enter}
    Sleep, 50
    SendInput {Tab}
    Sleep, 50
    SendInput {End}
    return
FileExplorerActions() {
    MouseGetPos, , , , control
    if (control = "SysTreeView321") {
        SendInput {RButton}
        Sleep, 100
        SendInput u
        SendInput, {Escape}
    } else if (control = "DirectUIHWND3") {
        SendInput !hpi
    }}
