;*******************************************************************************************
; The following code is provided courtesy of contributors on the Autohotkey forum
;*******************************************************************************************

MoveIt(Q)
{
    ; Get the windows pos
    Global SM_XVIRTUALSCREEN, SM_YVIRTUALSCREEN
    WinGetPos,X,Y,W,H,A,,,
    WinGet,M,MinMax,A

    ; Calculate the top center edge
    CX := X + W/2
    CY := Y + 20

    ; MsgBox, X: %X% Y: %Y% W: %W% H: %H% CX: %CX% CY: %CY%
    SysGet, Count, MonitorCount

    num = 1
    Loop, %Count%
    {
        SysGet, Mon, MonitorWorkArea, %num%

        if( CX >= MonLeft && CX <= MonRight && CY >= MonTop && CY <= MonBottom ) {
            MW := (MonRight - MonLeft)
            MH := (MonBottom - MonTop)
            MHW := (MW / 2)
            MHH := (MH / 2)
            MMX := MonLeft + MHW
            MMY := MonTop + MHH

            if( M != 0 )
                WinRestore,A

            if( Q == 1 )
                WinMove,A,,MonLeft,MMY,MHW,MHH
            if( Q == 2 )
                WinMove,A,,MonLeft,MMY,MW,MHH
            if( Q == 3 )
                WinMove,A,,MMX,MMY,MHW,MHH
            if( Q == 4 )
                WinMove,A,,MonLeft,MonTop,MHW,MH
            if( Q == 5 ) {
                if( M == 0 )
                    WinMaximize,A
                else
                    WinRestore,A
            }
            if( Q == 6 )
                WinMove,A,,MMX,MonTop,MHW,MH
            if( Q == 7 )
                WinMove,A,,MonLeft,MonTop,MHW,MHH
            if( Q == 8 )
                WinMove,A,,MonLeft,MonTop,MW,MHH
            if( Q == 9 )
                WinMove,A,,MMX,MonTop,MHW,MHH
            if( Q == "default" )
                WinMove, A, , MMX - 550, 0, 1100, 1210
            if( Q == "tall" )
                WinMove, A, , SM_XVIRTUALSCREEN - 8, SM_YVIRTUALSCREEN, 1278 + 16, 2047 + 8
            return
        }

        num += 1
    }

    return
}
