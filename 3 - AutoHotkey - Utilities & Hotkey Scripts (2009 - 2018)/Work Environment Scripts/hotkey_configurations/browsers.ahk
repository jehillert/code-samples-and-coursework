#if WinActive("- Google Chrome") || WinActive("Microsoft Edge ahk_exe ApplicationFrameHost.exe")
#F3::SendInput ^w
#d::SendInput ^+d
F21::SendInput ^{LButton}
RButton::SendInput {RButton Down}
RButton Up::SendInput {RButton Up}
PrintScreen::SendInput ^+{Tab}
Pause::SendInput ^{Tab}
ScrollLock::SendInput ^w
WheelLeft::OnTitleBarClick("{Control Down}{Shift Down}{Tab}{Control Up}{Shift Up}", "{WheelLeft}", "{WheelLeft}", "{WheelLeft}", 0)
WheelRight::OnTitleBarClick("{Control Down}{Tab}{Control Up}", "{WheelRight}", "{WheelRight}", "{WheelRight}", 0)
