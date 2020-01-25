Attribute VB_Name = "A__AUTO"
Sub AutoNew()
   InitializeGlobalVariables
   SetViewAndZoom
   InitializeCustomSettings
   RemoveAppNameFromWindowCaption
   End Sub
Sub AutoOpen()
   InitializeGlobalVariables
   SetViewAndZoom
   InitializeCustomSettings
   RemoveAppNameFromWindowCaption
   ActiveDocument.Save
   End Sub
Sub AutoClose()
   Options.CheckGrammarAsYouType = False
   Options.CheckSpellingAsYouType = True
   ActiveDocument.TrackFormatting = False
   If ActiveDocument.Bookmarks.Exists("mySelection") = True Then ActiveDocument.Bookmarks("mySelection").Delete
   'If InStr(ActiveDocument.Name, "Response") Or InStr(ActiveDocument.Name, "Instructions") Then BgNone
   End Sub
Sub ColorizePatentDocuments()
   If InStr(ActiveDocument.Name, "Office Action") Then
      BgOrange
   ElseIf InStr(ActiveDocument.Name, "Application") Then
      BgYellow
   ElseIf InStr(ActiveDocument.Name, "Claims") Then
      BgBlue
   ElseIf InStr(ActiveDocument.Name, "OUTLINE") Then
      BgMint
   ElseIf InStr(ActiveDocument.Name, "COMMENTS") Then
      BgViolet
'   ElseIf InStr(ActiveDocument.Name, "Response") Then
'      BgDRAFT
'   ElseIf InStr(ActiveDocument.Name, "Instructions") Then
'      BgDRAFT
   End If
   End Sub
Sub InitializeGlobalVariables()
   Bookmark_Iter = 1
   End Sub
Sub InitializeCustomSettings()
   Options.CheckGrammarAsYouType = False
   Options.CheckSpellingAsYouType = True
   End Sub
Private Sub initialViewState()
   If wasNormal Then
    ActiveWindow.WindowState = wdWindowStateNormal
   End If
   If ActiveDocument.ActiveWindow.View.Type = wdPrintView Then
    ActiveDocument.ActiveWindow.View.Zoom.PageColumns = 1
   End If
   ActiveWindow.DocumentMap = True
   ActiveDocument.ActiveWindow.View.Type = wdWebView
   ActiveDocument.ActiveWindow.View.Zoom.Percentage = myZoomPref
   Application.CommandBars("Navigation").Width = NavPane_R
   Application.CommandBars("Navigation").Position = msoBarRight
   viewStateWasCaptured = True
   End Sub
Sub RemoveAppCaption()
   Application.Caption = " "
   End Sub
Sub SetViewAndZoom()
   On Error Resume Next
   initialViewState
   ActiveDocument.Selection.MoveUp Unit:=wdScreen, Count:=1
   ActiveDocument.TrackFormatting = False
   AlignWindowAtStartup
   'ColorizePatentDocuments
   On Error GoTo 0
   End Sub


