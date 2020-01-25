#if WinActive("DevTools ahk_class Chrome_WidgetWin_1 ahk_exe chrome.exe")
!SC029::AddToWatches()
LButton & WheelLeft::SendInput ^{F10}
XButton1::SendInput {F8}
RButton & Left::SendInput ^r
^WheelUp::
WheelRight::AddToWatches()
AddToWatches() {
    SendInput {RButton}
    Sleep 100
    SendInput {Down 9}{Enter}
}
