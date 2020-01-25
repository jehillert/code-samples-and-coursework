Attribute VB_Name = "VIEWS"
Function ApplyFont(myFont, Optional myFontSize As Integer = 12, Optional myZoomPercent As Integer = 115)
   doStart ("ApplyFont: " & myFont)
   ActiveDocument.Range.Font.Name = myFont
   ActiveDocument.Range.Font.Size = myFontSize
   ActiveWindow.ActivePane.View.Zoom.Percentage = myZoomPercent
   doStop
End Function
Sub ArialNovaLight()
   Call ApplyFont("Arial Nova Light", 12.5, 110)
   End Sub
Sub Arial()
   Call ApplyFont("Arial", 11, 111)
   End Sub
Sub ArialUnicode()
   Call ApplyFont("Arial Unicode MS", 12, 100)
   End Sub
Sub Calibri()
   Call ApplyFont("Calibri", 12, 118)
   End Sub
Sub CalibriLight()
   Call ApplyFont("Calibri Light", 12, 125)
   End Sub
Sub SegoeUI()
   Call ApplyFont("Segoe UI")
   End Sub
Sub Verdana()
   Call ApplyFont("Verdana, 10, 120")
'   Selection.WholeStory
'   Selection.ParagraphFormat.LineSpacingRule = wdLineSpaceSingle
'   Selection.collapse Direction:=wdCollapseStart
   End Sub
