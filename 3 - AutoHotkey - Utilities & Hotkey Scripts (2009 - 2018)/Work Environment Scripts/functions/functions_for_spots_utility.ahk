ShowCursor:
    SystemCursor("On")
    ExitApp

MoveSpot:
    CoordMode, Mouse, Screen
    Global MoveSpot
    Keywait LButton
    num := SubStr(A_Gui, 5, 1)
    SetSpot(num)
    return

ActivateTitle(num) {
    global titles
    title := titles[num]
    WinActivate, %title%
}

AssignCoordinates(num) {
    Global asx, asy, sx, sy, titles
    MouseGetPos, , , id, control
    WinGetTitle, title, ahk_id %id%
    titles[num] := title
    CoordMode, Mouse, Screen
    MouseGetPos, sx, sy
    CoordMode, Mouse, Window
    MouseGetPos
    asx[num] := sx
    asy[num] := sy
}

HideSpot(num) {
    Gui, SPOT%num%:Cancel
}

InitializeSpotGui(num) {
    CoordMode, Mouse, Screen
    Global SpotIndex, spH, spW
    SpotIndex := SpotIndex + 1
    Gui, SPOT%num%:New,, SPOT%num%
    Gui, SPOT%num%:Color, EEAA99
    Gui SPOT%num%:+LastFound  ; Make the GUI window the last found window for use by the line below.
    Gui, SPOT%num%:-Caption +alwaysontop
    Gui, SPOT%num%:+Owner
    WinSet, TransColor, EEAA99
    Gui, SPOT%num%:Add, Picture, x0 y0 gMoveSpot w%spW% h%spH%, auxiliary_files/spot%num%.ico
    return SPOT%num%
}

InitializeSpots() {
    CoordMode, Mouse, Screen
    Global SpotIndex, mx, my, asx, asy
    Loop, %SpotIndex%
    {
        sname := "SPOT"a_index
        if WinExist(sname) {
            Gui SPOT%a_index%:Cancel
        } else {
            InitializeSpot(a_index)
        }
    }
}

InitializeSpot(num) {
    CoordMode, Mouse, Screen
    Global SpotIndex, mx, my, asx, asy, spW
    ; mx := mx - SpotIndex/2*spW
    my := my + spW*(num - 1)
    asx[num] := mx
    asy[num] := my
}

RunSpots() {
    Global mx, my, nx, ny
    Global ix, iy
    Global titles := Object()
    Global asx := Object()
    Global asy := Object()
    Global SpotIndex := 0
    Global spH := 13
    Global spW := 13

    WinGetPos,x,,,, ahk_class Shell_TrayWnd

    if (x = 0)
    nx := tbw
    else
    nx := Mon1Right - tbw - spW
    ny := Mon1Height/2 - spH

    IniRead, my, _AuxFiles/spot.ini, LastCoords, y, %ny%
    IniRead, mx, _AuxFiles/spot.ini, LastCoords, x, %nx%
    InitializeSpotGui(1)
    ; InitializeSpotGui(2)
    InitializeSpots()

    L1 =[L]Button       Reload
    L2 =[R]Button      Toggle
    L3 =[M]Button     Exit

    Menu, Tray, Tip, %L1%`n%L2%`n%L3%
    Menu, tray, NoStandard
    OnMessage(0x404, "AHK_NOTIFYICON")

    ToggleSpots()
}

SetSpot(num) {
    CoordMode, Mouse, Screen
    Global asx, asy, sx, sy, spH, spW, titles
    Gui, SPOT%num%: Cancel
    AssignCoordinates(num)
    UpdateCoordinates(num)
    Gui, SPOT%num%:Show, x%sx% y%sy% h%spH% w%spW%, SPOT%num%
    ActivateTitle(num)
    IniWrite, %sx%, _AuxFiles/spot.ini, LastCoords, x
    IniWrite, %sy%, _AuxFiles/spot.ini, LastCoords, y
}

ToggleSpots(){
    CoordMode, Mouse, Screen
    Global SpotIndex, mx, my, spH, spW, asx, asy
    mx := mx - SpotIndex/2*spW
    Loop, %SpotIndex%
    {
        sname := "SPOT"a_index
        if WinExist(sname) {
            Gui SPOT%a_index%:Cancel
        } else {
            ; mx := mx + spW*(a_index -1)
            my := my + spW*(a_index - 1)
            asx[a_index] := mx
            asy[a_index] := my
            Gui, SPOT%a_index%:Show, x%mx% y%my% h%spH% w%spW%, SPOT%a_index%
        }
    }
}

TriggerSpot(num, dx := 0, dy := 0, clickcount := 1) {
    CoordMode, Mouse, Screen
    Global asx, asy, sx, sy, spH, spW, titles
    Gui, SPOT%num%: Cancel
    MouseGetPos, ix, iy
    SystemCursor("Off")
    ActivateTitle(num)
    UpdateCoordinates(num)
    tx := sx + dx
    ty := sy + dy
    Sleep 100
    if (clickcount = 0) {
        InputBox, clickcount, __spots_functions.ahk, , , 100, 100
        if ErrorLevel {
            exit
        }
    }
    Click, %tx%, %ty%, %clickcount%
    Sleep 100
    Gui, SPOT%num%:Show, x%sx% y%sy% h%spH% w%spW%, SPOT%num%
    ActivateTitle(num)
    MouseMove, %ix%, %iy%
    SystemCursor("On")
    tx := 0
    ty := 0
}

UpdateCoordinates(num) {
    CoordMode, Mouse, Screen
    Global asx, asy, sx, sy
    sx := asx[num]
    sy := asy[num]
}
