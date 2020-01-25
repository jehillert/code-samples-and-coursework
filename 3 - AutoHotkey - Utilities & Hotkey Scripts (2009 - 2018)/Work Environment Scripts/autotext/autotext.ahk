;********************************************************************************************************************
; AUTOTEXT - %A_DD% %A_MM% %A_Hour% %A_Min%
;********************************************************************************************************************
; c = case-sensitive
; o = no trailing space (or other ending character)
; r = Send the replacement text raw; that is, without translating {Enter} to an ENTER keystroke, ^c to Control-C, etc.no trailing space
; x = Execute. Instead of replacement text
; * = ending character not required to trigger hotkey.

; JAVASCRIPT SHORTCUTS
:*c:fff::<project>
:cx*:st3::SendInput Sublime Text 3{Space}
:cx*:sbt::SendInput Sublime Text{Space}
:x*:bx::SendInput bx{Tab}
:x*:cnl::SendInput console.log();{left 2}
:x*:ppp::SendInput {ASC 37}{ASC 37}{Left}
:x*:jss::SendInput JavaScript{Space}

; ADDRESS
:roc:arb::MY_STREET_ADDRESS
:roc:arbb::MY_CITY_STATE_ZIP
:roc:arbc::MY_FULL_ADDRESS_WITH_LINE_BREAKS

; DATES
:*c:dte::
    SendInput [%A_YYYY%-%A_MM%-%A_DD%]
    return
:*c:dtm::
    SendInput %A_MM%/%A_DD%`t%A_Hour%:%A_Min%{Space}-{Space}
    return
:*c:ttt::
    SendInput %A_Hour%:%A_Min%
    return
:*c:dtt::
    FormatTime, Time,,M/d/yyyy
    SendInput, %Time%
    return
:*c:dt(::
    SendInput (%A_YYYY%-%A_MM%-%A_DD%)
    return

; PERSONAL INFO
:Roc:jh::FIRST_NAME_LAST_NAME
:roc:jml::MY_GMAIL_ADDRESS
:roc:jol::MY_OUTLOOK_EMAIL_ADDRESS
:*c:("")::
    Send {Raw}("")
    SendInput {Left 2}
    return

; OTHER
:r:ahkk::autohotkey
:r:ahhk::autohotkey
:*:rms::
    SendInput {Raw}RunMSWordMacro("")
    SendInput {Left 2}
    return

; ATTIC
; :x*:jqc::SendInput jqc{Tab}
; :x*:jqq::SendInput jqq{Tab}
; :x*:jfn::SendInput function __(__) {`{}{Enter}{Tab}__`;{Enter}{`}}{Up 2}{End}{Left 6}+{Left 2}
; :x*:jhof::SendInput (function __(__) {`{}{Enter}{Tab}__`;{Enter}{`}})`;{Up 2}{End}{Left 6}+{Left 2}
; :x*:frr::SendInput for (var i = __`; __`; i{`+}{`+}) {`{}{Enter}{Tab}__`;{Enter}{`}}{Up 2}{End}{Left 12}+{Left 2}
; :x*:jfr::SendInput for (var i = __`; __`; i{`+}{`+}) {`{}{Enter}{Tab}__`;{Enter}{`}}{Up 2}{End}{Left 12}+{Left 2}
; :x*:frn::SendInput for (__ in __) {`{}{Enter}{Tab}__`;{Enter}{`}}{Up 2}{End}{Left 9}+{Left 2}
; :x*:frf::SendInput for (__ of __) {`{}{Enter}{Tab}__`;{Enter}{`}}{Up 2}{End}{Left 9}+{Left 2}
; :x*:frch::SendInput for each (__ in __) {`{}{Enter}{Tab}__`;{Enter}{`}}{Up 2}{End}{Left 9}+{Left 2}
