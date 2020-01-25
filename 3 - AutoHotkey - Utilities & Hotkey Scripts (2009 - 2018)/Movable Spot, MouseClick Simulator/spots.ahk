;-------------------------------------------------------------------------------------------------
;
; Movable spot that simulate mouse clicks where placed when hotkey pressed
;
; PURPOSE: This script lets a user access UI controls form the keyboard in applications
; where hotkeys cannot be assigned or tabbed to, and where the UI control ID cannot
; be extracted. Additional hotkeys are provided for the mouse, for cases where a spot
; on the desktop far away from the cursor must be clicked immediately.
;
; DESCRIPTION: 1 or 2 colored dots appear on the desktop, which can be repositioned with
; the mouse.  Hotkeys 'Numpad0' and 'NumpadDot' simulate a mouse click when pressed.
; Other hotkeys are provided, which are indicated by the code below.
;-------------------------------------------------------------------------------------------------

;-------------------------------------------------------------------------------------------------
; GLOBAL & ENVIRONMENT
;-------------------------------------------------------------------------------------------------
#NoEnv
#Persistent
#SingleInstance force
#InstallKeybdHook

SendMode Input
SetTitleMatchMode, 2
SetWorkingDir %A_ScriptDir%
CoordMode, Mouse, Screen
Menu, Tray, Icon, icons\spots_icon.ico
OnExit, ShowCursor

Global Mon1, Mon1Height, Mon1Width, Mon1MiddleX, Mon1MiddleY
Global Mon1Left, Mon1Right, Mon1Top, Mon1Bottom
Global tbW, mx, my, nx, ny
Global ix, iy
Global titles := Object()
Global asx := Object()
Global asy := Object()
Global SpotIndex := 0
Global spH := 13
Global spW := 13

WinGetPos,x,,tbW,, ahk_class Shell_TrayWnd
SysGet, Mon1, Monitor, 1
Mon1MiddleX := Mon1Right - (Mon1Right - Mon1Left)/2
Mon1MiddleY := Mon1Bottom - (Mon1Bottom - Mon1Top)/2
Mon1Width := Mon1Right - Mon1Left
Mon1Height := Mon1Bottom - Mon1Top

if (x = 0)
	nx := tbW
Else
	nx := Mon1Right - tbW - spW
ny := Mon1Height/2 - spH
; my := Mon1Top

IniRead, my, spots_data.ini, LastCoords, y, %ny%
IniRead, mx, spots_data.ini, LastCoords, x, %nx%
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
Return

;-------------------------------------------------------------------------------------------------
; HOTKEYS
;-------------------------------------------------------------------------------------------------

; comment out this line to make hotkeys global
#If WinActive("MY_WINDOW_AHK_CLASS")
MButton::SetSpot(1)
m::TriggerSpot(1,32)
l::TriggerSpot(1)
Numpad0::TriggerSpot(1)
NumpadDot::TriggerSpot(1, 32)
NumpadEnter::TriggerSpot(1, 32, 0, 0)

RButton & WheelUp::
  	SendInput {Right 7}
  	Sleep 200
  	Return

RButton & WheelDown::
  	SendInput {Left 7}
  	Sleep 200
  	Return

RButton & LButton::TriggerSpot(1,32)

LButton::
  	CoordMode, Mouse, Window
  	MouseGetPos, x, y, win
  	WinGetTitle, title, ahk_id %id%
  	If (title != MY_WINDOW_AHK_CLASS && title != MY_WINDOW_AHK_CLASS) {
  		SendInput {LButton}
  		Exit
  	}
  	WinGetPos,,,Width,Height, A
  	y1 := 40
  	y2 := Height - 70
  	if (y > y1 && y < y2 && x > 0 && x < Width) {
  		SendInput {Left}
  		exit
  	}
  	SendInput {LButton}
  	Return

RButton::
    CoordMode, Mouse, Window
    MouseGetPos, x, y, win
    WinGetTitle, title, ahk_id %id%
    IfWinActive, %title%
    {
      WinGetPos,,,Width,Height, A
      y1 := 40
      y2 := Height - 70
      if (y > y1 && y < y2 && x > 0 && x < Width) {
        SendInput {Right}
        exit
      }
    }
    Return

  XButton1::TriggerSpot(1)

  XButton2::TriggerSpot(1, 32)

; global hotkeys.  comment out if commenting out line above
#If
    Capslock & Tab::ToggleSpots()
    SC029::TriggerSpot(1)
    CapsLock & SC029::TriggerSpot(1, 32)
    !SC029::SendInput ``

;-------------------------------------------------------------------------------------------------
; SUBROUTINES
;-------------------------------------------------------------------------------------------------

ShowCursor:
	SystemCursor("On")
	ExitApp

MoveSpot:
	Global MoveSpot
	Keywait LButton
	num := SubStr(A_Gui, 5, 1)
	SetSpot(num)
	Return

;-------------------------------------------------------------------------------------------------
; FUNCTIONS
;-------------------------------------------------------------------------------------------------
AHK_NOTIFYICON(wParam, lParam) {
    Global SpotIndex
    if (lParam = 0x202){
        reload
        Return 1
    } else if (lParam = 0x204) {
    	ToggleSpots()
        Return 1
    } else if (lParam = 0x208) {
        ExitApp
        Return 1
    }
}

ActivateTitle(num) {
	global titles
	title := titles[num]
	; msgbox % titles[num]
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
	Global SpotIndex, spH, spW
	SpotIndex := SpotIndex + 1
	Gui, SPOT%num%:New,, SPOT%num%
	Gui, SPOT%num%:Color, EEAA99
	Gui SPOT%num%:+LastFound  ; Make the GUI window the last found window for use by the line below.
	Gui, SPOT%num%:-Caption +alwaysontop
	Gui, SPOT%num%:+Owner
	WinSet, TransColor, EEAA99
	Gui, SPOT%num%:Add, Picture, x0 y0 gMoveSpot w%spW% h%spH%, icons\spots_icon%num%.ico
	Return SPOT%num%
}

InitializeSpots() {
	Global SpotIndex, mx, my, asx, asy
    Loop, %SpotIndex%
	{
		sname := "SPOT"a_index
		If WinExist(sname) {
			Gui SPOT%a_index%:Cancel
		} Else {
			InitializeSpot(a_index)
		}
    }
}

InitializeSpot(num) {
	Global SpotIndex, mx, my, asx, asy, spW
	; mx := mx - SpotIndex/2*spW
	my := my + spW*(num - 1)
	asx[num] := mx
	asy[num] := my
}

SetSpot(num) {
	Global asx, asy, sx, sy, spH, spW, titles
	Gui, SPOT%num%: Cancel
	AssignCoordinates(num)
	UpdateCoordinates(num)
	Gui, SPOT%num%:Show, x%sx% y%sy% h%spH% w%spW%, SPOT%num%
	ActivateTitle(num)
	IniWrite, %sx%, spots_data.ini, LastCoords, x
	IniWrite, %sy%, spots_data.ini, LastCoords, y
}

ToggleSpots(){
	Global SpotIndex, mx, my, spH, spW, asx, asy
	mx := mx - SpotIndex/2*spW
    Loop, %SpotIndex%
	{
		sname := "SPOT"a_index
		If WinExist(sname) {
			Gui SPOT%a_index%:Cancel
		} Else {
			; mx := mx + spW*(a_index -1)
			my := my + spW*(a_index - 1)
			asx[a_index] := mx
			asy[a_index] := my
			Gui, SPOT%a_index%:Show, x%mx% y%my% h%spH% w%spW%, SPOT%a_index%
		}
	}
}

TriggerSpot(num, dx := 0, dy := 0, clickcount := 1) {
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
      InputBox, clickcount, spots.ahk, , , 100, 100
         if ErrorLevel {
            exit
         }
   }
	Click, %tx%, %ty%, %clickcount%
	Sleep 100
	; CoordMode, Mouse, Window
	; CoordMode, Mouse, Screen
	Gui, SPOT%num%:Show, x%sx% y%sy% h%spH% w%spW%, SPOT%num%
	ActivateTitle(num)
	MouseMove, %ix%, %iy%
	SystemCursor("On")
	tx := 0
	ty := 0
}

UpdateCoordinates(num) {
    Global asx, asy, sx, sy
    sx := asx[num]
    sy := asy[num]
}

WinUnderMouse() {
	MouseGetPos, , , win
	WinGetTitle, title, ahk_id %win%
	Return title
}

;***********************************************************************8
; The following code provided courtesy of the AutoHotkey Forum
;***********************************************************************8

SystemCursor(OnOff=1)   ; INIT = "I","Init"; OFF = 0,"Off"; TOGGLE = -1,"T","Toggle"; ON = others
{
    static AndMask, XorMask, $, h_cursor
        ,c0,c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13 ; system cursors
        , b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13   ; blank cursors
        , h1,h2,h3,h4,h5,h6,h7,h8,h9,h10,h11,h12,h13   ; handles of default cursors
    if (OnOff = "Init" or OnOff = "I" or $ = "")       ; init when requested or at first call
    {
        $ = h                                          ; active default cursors
        VarSetCapacity( h_cursor,4444, 1 )
        VarSetCapacity( AndMask, 32*4, 0xFF )
        VarSetCapacity( XorMask, 32*4, 0 )
        system_cursors = 32512,32513,32514,32515,32516,32642,32643,32644,32645,32646,32648,32649,32650
        StringSplit c, system_cursors, `,
        Loop %c0%
        {
            h_cursor   := DllCall( "LoadCursor", "Ptr",0, "Ptr",c%A_Index% )
            h%A_Index% := DllCall( "CopyImage", "Ptr",h_cursor, "UInt",2, "Int",0, "Int",0, "UInt",0 )
            b%A_Index% := DllCall( "CreateCursor", "Ptr",0, "Int",0, "Int",0
                , "Int",32, "Int",32, "Ptr",&AndMask, "Ptr",&XorMask )
        }
    }
    if (OnOff = 0 or OnOff = "Off" or $ = "h" and (OnOff < 0 or OnOff = "Toggle" or OnOff = "T"))
        $ = b  ; use blank cursors
    else
        $ = h  ; use the saved cursors

    Loop %c0%
    {
        h_cursor := DllCall( "CopyImage", "Ptr",%$%%A_Index%, "UInt",2, "Int",0, "Int",0, "UInt",0 )
        DllCall( "SetSystemCursor", "Ptr",h_cursor, "UInt",c%A_Index% )
    }
}

