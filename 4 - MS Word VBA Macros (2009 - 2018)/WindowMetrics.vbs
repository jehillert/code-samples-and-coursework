Attribute VB_Name = "WindowMetrics"
'Attribute VB_Name = "MonitorInfo"
Option Explicit

Public Declare Function LoadLibraryEx Lib "kernel32.dll" Alias "LoadLibraryExA" (ByVal lpFileName As String, ByVal hFile As Long, ByVal dwFlags As Long) As Long
Public Declare Function GetProcAddress Lib "kernel32.dll" (ByVal hModule As Long, ByVal lpProcName As String) As Long
Public Declare Function GetModuleHandle Lib "kernel32.dll" Alias "GetModuleHandleA" (ByVal lpModuleName As String) As Long
Public Declare Function FreeLibrary Lib "kernel32.dll" (ByVal hLibModule As Long) As Boolean
Public Declare Function EnumDisplayMonitors Lib "user32.dll" (ByVal hdc As Long, ByRef lprcClip As Any, ByVal lpfnEnum As Long, ByVal dwData As Long) As Boolean
Public Declare Function GetMonitorInfo Lib "user32.dll" Alias "GetMonitorInfoA" (ByVal hMonitor As Long, ByRef lpmi As MONITORINFOEX) As Boolean

Public Const CCHDEVICENAME = 32
Public Const MONITORINFOF_PRIMARY = &H1

Public Type RECT
   Left As Long
   Top As Long
   Right As Long
   Bottom As Long
End Type

Public Type MONITORINFOEX
   cbSize As Long
   rcMonitor As RECT
   rcWork As RECT
   dwFlags As Long
   szDevice As String * CCHDEVICENAME
End Type

Dim MonitorId() As String
'Public Sub Test()
Public Sub Test()
Dim i As Integer
   MsgBox "Number of monitors in this system : " & GetMonitorId
   For i = 1 To UBound(MonitorId)
    MsgBox MonitorId(i)
   Next i
End Sub
'Public Sub GetMonitorID()
Public Function GetMonitorId()
   ReDim MonitorId(0)
   ' Of course dual screen systems are not available on all Win versions.
   If FunctionExist("user32.dll", "EnumDisplayMonitors") = True Then
    If EnumDisplayMonitors(&H0, ByVal &H0, AddressOf MonitorEnumProc, &H0) = False Then
       Failed "EnumDisplayMonitors"
    End If
   End If
   GetMonitorId = UBound(MonitorId)
End Function
'Public Sub PrintMonitorInfoDebug()
Private Sub PrintMonitorInfo(ForMonitorID As String)
Dim MONITORINFOEX As MONITORINFOEX
   MONITORINFOEX.cbSize = Len(MONITORINFOEX)
   If GetMonitorInfo(CLng(ForMonitorID), MONITORINFOEX) = False Then Failed "GetMonitorInfo"
   With MONITORINFOEX
    Debug.Print "Monitor info for device number : " & ForMonitorID
    Debug.Print "---------------------------------------------------"
    Debug.Print "Device Name : " & .szDevice
    If .dwFlags And MONITORINFOF_PRIMARY Then Debug.Print "Primary Display = True" Else Debug.Print "Primary Display = False"
    With .rcMonitor
       Debug.Print "Monitor Left : " & .Left
       Debug.Print "Monitor Top : " & .Top
       Debug.Print "Monitor Right : " & .Right
       Debug.Print "Monitor Bottom : " & .Bottom
    End With
    With .rcWork
       Debug.Print "Work area Left : " & .Left
       Debug.Print "Work area Top : " & .Top
       Debug.Print "Work area Right : " & .Right
       Debug.Print "Work area Bottom : " & .Bottom
    End With
   End With
   Debug.Print
   Debug.Print
End Sub
Sub SayMonitorInfo()
   Dim myID As Integer
   Dim isPrimary, myEOL As String
   myEOL = vbNewLine & vbTab
   myID = GetMonitorId
   Dim MONITORINFOEX As MONITORINFOEX
   MONITORINFOEX.cbSize = Len(MONITORINFOEX)
   If GetMonitorInfo(CLng(myID), MONITORINFOEX) = False Then Failed "GetMonitorInfo"
   With MONITORINFOEX
   If .dwFlags And MONITORINFOF_PRIMARY Then
    isPrimary = "True"
   Else
    isPrimary = "False"
   End If
    MsgBox "Monitor info for device number : " & myID & vbNewLine & _
    "---------------------------------------------------" & vbNewLine & _
    "Device Name : " & .szDevice & vbNewLine & _
    "Primary Display = " & isPrimary
    With .rcMonitor
       MsgBox "MONITOR DIMENSIONS: " & myEOL & _
       "Monitor Left : " & .Left & myEOL & _
       "Monitor Top : " & .Top & myEOL & _
       "Monitor Right : " & .Right & myEOL & _
       "Monitor Bottom : " & .Bottom
    End With
    With .rcWork
       MsgBox "WORK AREA: " & myEOL & _
       "Work area Left : " & .Left & myEOL & _
       "Work area Top : " & .Top & myEOL & _
       "Work area Right : " & .Right & myEOL & _
       "Work area Bottom : " & .Bottom
    End With
   End With
End Sub
'Public Function FunctionExist()
Public Function FunctionExist(ByVal strModule As String, ByVal strFunction As String) As Boolean
Dim hHandle As Long
   hHandle = GetModuleHandle(strModule)
   If hHandle = &H0 Then
    Failed "GetModuleHandle"
    hHandle = LoadLibraryEx(strModule, &H0, &H0): If hHandle = &H0 Then Failed "LoadLibrary"
    If GetProcAddress(hHandle, strFunction) = &H0 Then
       Failed "GetProcAddress"
    Else
       FunctionExist = True
    End If
    If FreeLibrary(hHandle) = False Then Failed "FreeLibrary"
   Else
    If GetProcAddress(hHandle, strFunction) = &H0 Then
       Failed "GetProcAddress"
    Else
       FunctionExist = True
    End If
   End If
End Function
'Public Sub Failed()
Public Sub Failed(ByVal strFunction As String)
   If errMsg = True Then
    If Err.LastDllError = 0 Then
       MessageBoxEx &H0, strFunction & Chr$(13) & Chr$(10) & Chr$(13) & Chr$(10) & "Failed", "Error", MB_OK Or MB_ICONWARNING Or MB_SETFOREGROUND, 0
    Else
       Errors Err.LastDllError, strFunction
    End If
   End If
End Sub
'Public Function MonitorEnumProc()
Public Function MonitorEnumProc(ByVal hMonitor As Long, ByVal hdcMonitor As Long, ByRef lprcMonitor As RECT, ByVal dwData As Long) As Boolean
Dim ub As Integer
   ub = 0
   On Error Resume Next
   ub = UBound(MonitorId)
   On Error GoTo 0
   ReDim Preserve MonitorId(ub + 1)
   MonitorId(UBound(MonitorId)) = CStr(hMonitor)
   MonitorEnumProc = 1
End Function
'SAY MONITOR ID
Sub say_monitor_id()
    MsgBox "Monitor ID:" & vbTab & GetMonitorId
End Sub
Sub Virtual_Desktop_Height()
   MsgBox GetSystemMetrics32(79)
   End Sub
Sub Virtual_Desktop_Width()
   MsgBox GetSystemMetrics32(78)
   End Sub
