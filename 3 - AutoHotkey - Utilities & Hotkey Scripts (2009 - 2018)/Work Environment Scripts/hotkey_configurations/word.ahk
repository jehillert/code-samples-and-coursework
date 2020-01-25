#if WinActive("ahk_class OpusApp ahk_exe WINWORD.EXE")
^+m::SendInput ^!+{F1} ; RunMSWordMacro("SelectTextBetweenParenthesesAtCursor")
Capslock & q::SendInput ^!+{F2} ; RunMSWordMacro("SelectTextBetweenQuotesAtCursor")
Capslock & r::SendInput ^!+{F3} ; RunMSWordMacro("SelectRevisionAtIP")
Capslock & s::SendInput ^!+{F4} ; RunMSWordMacro("SelectSentence")
XButton1 & LButton::SendInput {Backspace}
XButton1 & XButton2::
    SendInput #+{Left}
    RunMSWordMacro("NavPaneLeft")
    return
XButton2 & XButton1::
    SendInput #+{Right}
    RunMSWordMacro("NavPaneRight")
    return
#+Left::
    SendInput #+{Left}
    RunMSWordMacro("NavPaneLeft")
    return
#+Right::
    SendInput #+{Right}
    RunMSWordMacro("NavPaneRight")
    return
RAlt & SC033::SendInput {Shift Down}{F11}{Shift Up}
RAlt & SC034::SendInput {F11} ; RunMSWordMacro("SelectParagraph")
^+d::SendInput ^!+d ; RunMSWordMacro("duplicateParagraphBelow")
!+q::SendInput ^!+a ; RunMSWordMacro("BlockClaimQuote")
Volume_Mute::SendInput +{F11}
Volume_Down::SendInput {F11}
Volume_Up::SendInput ^c^f
#z::SendInput ^!+z ; RunMSWordMacro("InsertEditTextField")
!1::RunMSWordMacro("OutlineLevel1")
!2::RunMSWordMacro("OutlineLevel2")
!3::RunMSWordMacro("OutlineLevel3")
!4::RunMSWordMacro("OutlineLevel4")
!5::RunMSWordMacro("OutlineLevel5")
!6::RunMSWordMacro("OutlineLevel6")
!7::RunMSWordMacro("OutlineLevel7")
!8::RunMSWordMacro("OutlineLevel8")
!9::RunMSWordMacro("OutlineLevel9")
ScrollLock::SendInput ^!+{F5} ; RunMSWordMacro("ResizeAndCenter")
XButton1::SendInput {Enter}
Numlock::SendInput {`]}^{Left 2}{`[}^{Right}{Right}
XButton2::SendInput ^x ; RunMSWordMacro("deleteParagraphOrSelection")

#Include ms_word_highlighter_gui\gofer_handlers.ahk
#Include ms_word_highlighter_gui\gofer_hotkeys.ahk
