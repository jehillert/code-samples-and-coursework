/*
  ^d - unselect
  b - pencil
  g - fill
  h - hand
  i - color picker
  m - select
  w - wand
  v - move selection
*/
#if WinActive("ahk_class TfrmMain ahk_exe icofx3.exe")
RButton & LButton::SendInput {LButton}g
RButton & XButton1::SendInput w
F21::
    SendInput i
    sleep 100
    Click
    sleep 100
    SendInput i
    return
WheelRight::SendInput b
WheelLeft::SendInput h
XButton1 & XButton2::SendInput ^d
XButton1::SendInput m
XButton2::SendInput v

#if WinActive("ahk_class MSPaintApp")
^=::SendInput ^{PgUp}
^WheelUp::SendInput ^{PgUp}
^-::SendInput ^{PgDn}
^WheelDown::SendInput ^{PgDn}
RButton & WheelDown::SendInput ^{PgDn}
RButton & WheelUp::SendInput ^{PgUp}
