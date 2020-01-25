#if WinActive("Zoom Group Chat ahk_exe Zoom.exe")
WheelRight::SendInput b{enter}
WheelLeft::SendInput p{enter}
XButton1::flashActivate("ahk_class ZPContentViewWndClass ahk_exe Zoom.exe")

#if WinActive("ahk_class ZPContentViewWndClass ahk_exe Zoom.exe")
XButton1::flashActivate("Zoom Group Chat")
WheelRight::
    flashActivate("Zoom Group Chat ahk_exe Zoom.exe")
    SendInput b{enter}
    return
WheelLeft::
    flashActivate("Zoom Group Chat ahk_exe Zoom.exe")
    SendInput p{enter}
    return
