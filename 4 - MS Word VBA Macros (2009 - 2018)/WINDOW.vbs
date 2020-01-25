Attribute VB_Name = "WINDOW"
Declare Function GetSystemMetrics32 Lib "USER32" Alias "GetSystemMetrics" (ByVal nIndex As Long) As Long
Private Const ABM_GETTASKBARPOS = &H5
Private Type RECT
   Left As Long
   Top As Long
   Right As Long
   Bottom As Long
   End Type
Private Type APPBARDATA
   cbSize As Long
   hwnd As Long
   uCallbackMessage As Long
   uEdge As Long
   rc As RECT
   lParam As Long
   End Type
Private Declare Function ShowCursor Lib "USER32" (ByVal fShow As Integer) As Integer
Private Declare Function SHAppBarMessage Lib "shell32.dll" (ByVal dwMessage As Long, pData As APPBARDATA) As Long

Sub AlignLeft()
   'README - Application.Left is in units of points.
   'Use Application.PixelsToPoints to convert.
   ActiveWindow.WindowState = xlNormal
   If TaskbarOrientation = "left" Then
      ActiveWindow.Left = TaskbarWidthInPoints
   Else
      ActiveWindow.Left = 0
   End If
   ActiveWindow.Top = 0
   End Sub
Sub AlignRight()
   'README - Application.Left is in units of points.
   'Use Application.PixelsToPoints to convert.
   ActiveWindow.WindowState = xlNormal
   If TaskbarOrientation = "right" Then
      ActiveWindow.Left = Display1WidthPoints - ActiveWindow.Width - TaskbarWidthInPoints
   Else
      ActiveWindow.Left = Display1WidthPoints - ActiveWindow.Width
   End If
   ActiveWindow.Top = 0
   End Sub
Sub AlignWindowAtStartup()
   ActiveWindow.WindowState = xlNormal
   If Display1Width() = 1024 Or Display1Width = 1280 Then
      ActiveWindow.WindowState = wdWindowStateMaximize
   ElseIf TaskbarOrientation = "left" Then
      ResizeAndAlignLeft
   ElseIf TaskbarOrientation = "right" Then
      ResizeAndAlignRight
   Else
      ResizeAndCenter
   End If
   End Sub
Sub CenterWindowInPrimaryDisplay()
   ActiveWindow.WindowState = xlNormal
   Dim DesktopWidth, WinWidth As Integer
   WinWidth = ActiveWindow.Width
   ActiveWindow.Left = (Display1WidthPoints) / 2 - WinWidth / 2
   ActiveWindow.Top = 0
   End Sub
Sub CursorHide()
   While ShowCursor(False) >= 0
   Wend
   End Sub
Sub CursorShow()
   While ShowCursor(True) < 0
   Wend
   End Sub
Function Display1HeightPoints() As Long
   Display1HeightPoints = PixelsToPoints(GetSystemMetrics32(1))
   End Function
Function Display1WidthPoints() As Long
   Display1WidthPoints = PixelsToPoints(GetSystemMetrics32(0))
   End Function
Function Display2WidthPoints() As Long
   Display2WidthPoints = PixelsToPoints(GetSystemMetrics32(78)) - PixelsToPoints(GetSystemMetrics32(0))
   End Function
Function Display2HeightPoints() As Long
   Dim m2w As Long
   m2w = PixelsToPoints(GetSystemMetrics32(78) - GetSystemMetrics32(0))
   If m2w = 1280 Then
      Display2HeightPoints = 1024
   Else
      Display2HeightPoints = 1280
   End If
   End Function
Function Display1Height() As Long
   Display1Height = GetSystemMetrics32(1)
   End Function
Function Display1Width() As Long
   Display1Width = GetSystemMetrics32(0)
   End Function
Function Display2Width() As Long
   Display2Width = GetSystemMetrics32(78) - GetSystemMetrics32(0)
   End Function
Function Display2Height() As Long
   Dim m2w As Long
   m2w = GetSystemMetrics32(78) - GetSystemMetrics32(0)
   If m2w = 1280 Then
      Display2Height = 1024
   Else
      Display2Height = 1280
   End If
   End Function
Sub MaximizeWindowInRightDisplay()
   If ActiveWindow.WindowState = wdWindowStateMaximize Then ActiveWindow.WindowState = xlWindowStateNormal
   ActiveWindow.Top = 1
   ActiveWindow.Left = Application.UsableWidth
   ActiveWindow.WindowState = wdWindowStateMaximize
   End Sub
Sub OutputDisplayMetricsInPixels()
   Dim ABD As APPBARDATA
   SHAppBarMessage ABM_GETTASKBARPOS, ABD
   MsgBox "WINDOW DIMENSIONS (PIXELS)" & vbNewLine & vbNewLine & _
   "Display1" & vbTab & "Height: " & Display1Height() & vbNewLine & _
   "Display1" & vbTab & "Width: " & Display1Width() & vbNewLine & vbNewLine & _
   "Display2" & vbTab & "Height: " & Display2Height() & vbNewLine & _
   "Display2" & vbTab & "Width: " & Display2Width() & vbNewLine & vbNewLine & _
   "Taskbar Orientation: " & TaskbarOrientation & vbNewLine & _
   "Taskbar Height: " & ABD.rc.Bottom - ABD.rc.Top & vbNewLine & _
   "TaskBar Width: " & ABD.rc.Right - ABD.rc.Left & vbNewLine & vbNewLine & _
   "Application.Top: " & vbTab & vbTab & Application.PointsToPixels(Application.Top) & vbNewLine & _
   "Application.Left: " & vbTab & vbTab & Application.PointsToPixels(Application.Left) & vbNewLine & vbNewLine & _
   "Application.UsableWidth: " & vbTab & Application.PointsToPixels(Application.UsableWidth) & vbNewLine & _
   "Application.UsableHeight: " & vbTab & Application.PointsToPixels(Application.UsableHeight)
   End Sub
Sub OutputDisplayMetricsInPoints()
   Dim ABD As APPBARDATA
   SHAppBarMessage ABM_GETTASKBARPOS, ABD
   MsgBox "WINDOW DIMENSIONS (POINTS)" & vbNewLine & vbNewLine & _
   "Display1" & vbTab & "Height: " & Application.PixelsToPoints(Display1Height()) & vbNewLine & _
   "Display1" & vbTab & "Width: " & Application.PixelsToPoints(Display1Width()) & vbNewLine & vbNewLine & _
   "Display2" & vbTab & "Height: " & Application.PixelsToPoints(Display2Height()) & vbNewLine & _
   "Display2" & vbTab & "Width: " & Application.PixelsToPoints(Display2Width()) & vbNewLine & vbNewLine & _
   "Taskbar Orientation: " & TaskbarOrientation & vbNewLine & _
   "Taskbar Height: " & Application.PixelsToPoints(ABD.rc.Bottom - ABD.rc.Top) & vbNewLine & _
   "TaskBar Width: " & Application.PixelsToPoints(ABD.rc.Right - ABD.rc.Left) & vbNewLine & vbNewLine & _
   "Application.Top: " & vbTab & vbTab & Application.Top & vbNewLine & _
   "Application.Left: " & vbTab & vbTab & Application.Left & vbNewLine & vbNewLine & _
   "Application.UsableWidth: " & vbTab & Application.UsableWidth & vbNewLine & _
   "Application.UsableHeight: " & vbTab & Application.UsableHeight
   End Sub
Sub RemoveAppNameFromWindowCaption()
   On Error GoTo ErrorHandler
   Dim FileName As String
   FileName = Left(ActiveDocument.Name, InStr(ActiveDocument.Name, ".") - 1)
   ActiveWindow.Caption = ""
   ActiveWindow.Application.Caption = " "
   ActiveWindow.Caption = FileName
ErrorHandler:
   End Sub
Sub RemoveWindowCaption()
   ActiveWindow.Caption = ""
   ActiveWindow.Application.Caption = " "
   End Sub
Sub ResizeAndCenter()
   ResizeWindow
   CenterWindowInPrimaryDisplay
   NavPaneRight
   End Sub
Sub ResizeAndAlignLeft()
   ResizeWindow
   AlignLeft
   NavPaneLeft
   ActiveWindow.DocumentMap = True
   End Sub
Sub ResizeAndAlignRight()
   ResizeWindow
   AlignRight
   NavPaneRight
   ActiveWindow.DocumentMap = True
   End Sub
Sub ResizeToMaxUsableDim()
   With ActiveWindow
   .WindowState = xlNormal
   .Height = Application.UsableHeight
   .Width = Application.UsableWidth
   End With
   End Sub
Sub ResizeWindow()
   ActiveWindow.WindowState = xlNormal
   ActiveWindow.Height = Application.UsableHeight
   ActiveWindow.Width = defWinWidth
   End Sub
Function TaskbarHeightInPixels() As Long
   Dim ABD As APPBARDATA
   SHAppBarMessage ABM_GETTASKBARPOS, ABD
   TaskbarHeightInPixels = ABD.rc.Bottom - ABD.rc.Top
   End Function
Function TaskbarWidthInPixels() As Long
   Dim ABD As APPBARDATA
   SHAppBarMessage ABM_GETTASKBARPOS, ABD
   TaskbarWidthInPixels = ABD.rc.Right - ABD.rc.Left
   End Function
Function TaskbarHeightInPoints() As Long
   Dim ABD As APPBARDATA
   SHAppBarMessage ABM_GETTASKBARPOS, ABD
   TaskbarHeightInPoints = Application.PixelsToPoints(ABD.rc.Bottom - ABD.rc.Top)
   End Function
Function TaskbarOrientation() As String
   Dim ABD As APPBARDATA
   SHAppBarMessage ABM_GETTASKBARPOS, ABD
   With ABD.rc
      If .Left = 0 And .Top = 0 Then
         TaskbarOrientation = "left"
      ElseIf .Left > 0 And .Top = 0 Then
         TaskbarOrientation = "right"
      ElseIf .Left = 0 And .Top = 0 Then
         TaskbarOrientation = "top"
      Else
         TaskbarOrientation = "bottom"
      End If
   End With
   End Function
Function TaskbarWidthInPoints() As Long
   Dim ABD As APPBARDATA
   SHAppBarMessage ABM_GETTASKBARPOS, ABD
   TaskbarWidthInPoints = Application.PixelsToPoints(ABD.rc.Right - ABD.rc.Left)
   End Function
Sub ZoomIn()
   On Error Resume Next
   'Application.ScreenUpdating = False
   'CursorHide
   With ActiveDocument.ActiveWindow.View
      .Zoom.Percentage = .Zoom.Percentage + zoomDecrement
   End With
   'CursorShow
   'Application.ScreenUpdating = True
   End Sub
Sub ZoomOut()
   On Error Resume Next
   'Application.ScreenUpdating = False
   'CursorHide
   With ActiveDocument.ActiveWindow.View
      .Zoom.Percentage = .Zoom.Percentage - zoomDecrement
   End With
   'CursorShow
   'Application.ScreenUpdating = True
   End Sub

