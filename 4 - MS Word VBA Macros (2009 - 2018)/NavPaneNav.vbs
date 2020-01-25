Attribute VB_Name = "NavPaneNav"
Private Declare Function ShowCursor Lib "USER32" _
(ByVal fShow As Integer) As Integer

Function atStart() As Boolean
   If Selection.Type = wdSelectionNormal And Selection.Start = ActiveDocument.Content.Start Then
      atStart = True
   Else
      atStart = False
   End If
   End Function
Function atEnd() As Boolean
   If Selection.Type = wdSelectionNormal And Selection.End = ActiveDocument.Content.End Then
      atEnd = True
   Else
      atEnd = False
   End If
   End Function
Sub BWHeaderLvl1()
   doStart ("BWHeaderLvl1")
   Set myDoc = Application.ActiveDocument
   Dim oRng As Range
   Dim myCount As Integer
   SelectParagraph
   Selection.CopyFormat
   With Selection.ParagraphFormat
      .Alignment = wdAlignParagraphJustify
      .FirstLineIndent = InchesToPoints(-0.19)
      .LeftIndent = InchesToPoints(0)
      .OutlineLevel = wdOutlineLevel1
      .RightIndent = InchesToPoints(-0.25)
      .Space1
   End With
   With Selection.Font
      .Name = "Arial Nova Light"
      .Bold = False
      .Italic = False
      .Underline = wdUnderlineNone
      .color = wdColorWhite
   End With
   Selection.Shading.BackgroundPatternColor = wdColorBlack
   With Selection
      .HomeKey Unit:=wdLine
      .TypeText Text:=vbTab
      .TypeBackspace
      .HomeKey Unit:=wdLine
      .TypeText Text:=vbTab
      .EndKey Unit:=wdLine
   End With
   Set oRng = Selection.PARAGRAPHS(1).Range
   myCount = oRng.Characters.Count
   oRng.SetRange oRng.Start, oRng.End - 1
   oRng.collapse wdCollapseEnd
   oRng.Select
   Selection.TypeParagraph
   SelectParagraph
   Selection.PasteFormat
   If myCount < 3 Then
      oRng.Select
   Else
      Selection.collapse Direction:=wdCollapseStart
   End If
   doStop
End Sub
Sub BLHeaderLvl2()
   doStart ("BLHeaderLvl2")
   Set myDoc = Application.ActiveDocument
   Dim oRng As Range
   Dim myCount As Integer
   SelectParagraph
   Selection.CopyFormat
   With Selection.ParagraphFormat
      .Alignment = wdAlignParagraphJustify
      .FirstLineIndent = InchesToPoints(-0.19)
      .LeftIndent = InchesToPoints(0)
      .OutlineLevel = wdOutlineLevel2
      .RightIndent = InchesToPoints(-0.25)
      .Space1
   End With
   With Selection.Font
      .Name = "Arial Nova Light"
      .Bold = False
      .Italic = False
      .Underline = wdUnderlineNone
      .color = wdColorWhite
   With Selection.Shading.BackgroundPatternColor = -671039489
   With Selection
      .HomeKey Unit:=wdLine
      .TypeText Text:=vbTab
      .TypeBackspace
      .HomeKey Unit:=wdLine
      .TypeText Text:=vbTab
      .EndKey Unit:=wdLine
   End With
   Set oRng = Selection.PARAGRAPHS(1).Range
   myCount = oRng.Characters.Count
   oRng.SetRange oRng.Start, oRng.End - 1
   oRng.collapse wdCollapseEnd
   oRng.Select
   Selection.TypeParagraph
   SelectParagraph
   Selection.PasteFormat
   If myCount < 3 Then
      oRng.Select
   Else
      Selection.collapse Direction:=wdCollapseStart
   End If
   doStop
End Sub
Sub CycleOutlineLevels()
   If (Selection.ParagraphFormat.OutlineLevel = wdOutlineLevelBodyText) Then
      Selection.ParagraphFormat.OutlineLevel = wdOutlineLevel1
   ElseIf (Selection.ParagraphFormat.OutlineLevel = wdOutlineLevel1) Then
      Selection.ParagraphFormat.OutlineLevel = wdOutlineLevel2
   ElseIf (Selection.ParagraphFormat.OutlineLevel = wdOutlineLevel2) Then
      Selection.ParagraphFormat.OutlineLevel = wdOutlineLevel3
   Else
      Selection.ParagraphFormat.OutlineLevel = wdOutlineLevel1
   End If
   End Sub
Sub DoFind(findDirection As Boolean)
   Dim initialFindDirection As Boolean
   initialFindDirection = Selection.Find.Forward
   Selection.Find.Forward = findDirection
   Selection.Find.Execute
   Selection.Find.Forward = initialFindDirection
   End Sub
Sub FindNext()
   DoFind True
   End Sub
Sub FindPrevious()
   DoFind False
   End Sub
Sub GoBack()
   Application.GoBack
   End Sub
Sub GoToBeginning()
   Selection.HomeKey Unit:=wdStory
   End Sub
Sub GoToEnd()
   Selection.EndKey Unit:=wdStory
   End Sub
Sub HideWin()
   ActiveWindow.Visible = False
   End Sub
Sub HideNav()
   ActiveWindow.DocumentMap = False
   End Sub
Sub NavPaneLeft()
   Application.CommandBars("Navigation").Width = NavPane_L
   Application.CommandBars("Navigation").Position = msoBarLeft
   End Sub
Sub NavPaneRight()
   Application.CommandBars("Navigation").Width = NavPane_R
   Application.CommandBars("Navigation").Position = msoBarRight
   End Sub
Sub NavPaneSwitch()
   If Application.CommandBars("Navigation").Position = msoBarRight Then
      Application.CommandBars("Navigation").Position = msoBarLeft
   Else
      Application.CommandBars("Navigation").Position = msoBarRight
   End If
   End Sub
Sub NextField()
   Selection.NextField
   End Sub
Sub nextOL1()
   Call OutlineLevelXMover(wdOutlineLevel1, True)
   End Sub
Sub nextOL2()
   Call OutlineLevelXMover(wdOutlineLevel1, True)
   End Sub
Sub nextOL3()
   Call OutlineLevelXMover(wdOutlineLevel1, True)
   End Sub
Sub nextOL4()
   Call OutlineLevelXMover(wdOutlineLevel1, True)
   End Sub
Sub nextOutlineLevel()
   Application.ScreenUpdating = False
   hide
   NextPara
   Do While (Selection.ParagraphFormat.OutlineLevel = wdOutlineLevelBodyText)
    NextPara
   Loop
   show
   Application.ScreenUpdating = True
   End Sub
Sub NextSentence()
   Selection.MoveRight Unit:=wdSentence, Count:=1
   End Sub

Sub NextWord()
   If Selection.Type <> wdNoSelection Then
    Selection.MoveRight Unit:=wdCharacter, Count:=1, Extend:=wdMove
   End If
   Selection.Words(1).Next(Unit:=wdWord, Count:=1).Select
   End Sub
Sub OutlineLevel1()
   Selection.ParagraphFormat.OutlineLevel = wdOutlineLevel1
   End Sub
Sub OutlineLevel2()
   Selection.ParagraphFormat.OutlineLevel = wdOutlineLevel2
   End Sub
Sub OutlineLevel3()
   Selection.ParagraphFormat.OutlineLevel = wdOutlineLevel3
   End Sub
Sub OutlineLevel4()
   Selection.ParagraphFormat.OutlineLevel = wdOutlineLevel4
   End Sub
Sub OutlineLevel5()
   Selection.ParagraphFormat.OutlineLevel = wdOutlineLevel5
   End Sub
Sub OutlineLevel6()
   Selection.ParagraphFormat.OutlineLevel = wdOutlineLevel6
   End Sub
Sub OutlineLevel7()
   Selection.ParagraphFormat.OutlineLevel = wdOutlineLevel7
   End Sub
Sub OutlineLevel8()
   Selection.ParagraphFormat.OutlineLevel = wdOutlineLevel8
   End Sub
Sub OutlineLevel9()
   Selection.ParagraphFormat.OutlineLevel = wdOutlineLevel9
   End Sub
Sub OutlineLevelNone()
   Selection.ParagraphFormat.OutlineLevel = wdOutlineLevelBodyText
   End Sub
Function OutlineLevelXMover(myOutlineLevel, isForward)
   Selection.Find.ClearFormatting
   If isForward = False Then
    Selection.Find.Forward = False
   Else
    Selection.Find.Forward = True
   End If
   Selection.Find.FORMAT = True
   Selection.Find.Wrap = wdFindContinue
   Selection.Find.ParagraphFormat.OutlineLevel = myOutlineLevel
   Selection.Find.Text = ""
   Selection.Find.Execute
   End Function
Sub PageDown()
   Application.Browser.Next
   End Sub
Sub PageUp()
   Application.Browser.Previous
   End Sub
Sub PreviousField()
   Selection.PreviousField
   End Sub
Sub prevOL1()
   Call OutlineLevelXMover(wdOutlineLevel1, False)
   End Sub
Sub prevOL2()
   Call OutlineLevelXMover(wdOutlineLevel1, False)
   End Sub
Sub prevOL3()
   Call OutlineLevelXMover(wdOutlineLevel1, False)
   End Sub
Sub prevOL4()
   Call OutlineLevelXMover(wdOutlineLevel1, False)
   End Sub
Sub prevOutlineLevel()
   Application.ScreenUpdating = False
   PrevPara
   Do While (Selection.ParagraphFormat.OutlineLevel = wdOutlineLevelBodyText)
    PrevPara
   Loop
   Application.ScreenUpdating = True
   End Sub
Sub PrevPara()
   Dim c As Boolean
   c = Selection.MoveUp(wdParagraph, 1)
   If c = 0 Then
    Selection.EndKey Unit:=wdStory, Extend:=wdMove
   End If
   End Sub
Sub PreviousSentence()
   Selection.MoveLeft Unit:=wdSentence, Count:=1
   End Sub
Sub PreviousWord()
   If Selection.Type <> wdNoSelection Then
    Selection.MoveLeft Unit:=wdCharacter, Count:=1, Extend:=wdMove
   End If
   Selection.Words(1).Previous(Unit:=wdWord, Count:=1).Select
   End Sub
Sub sayOL()
   Do While (Selection.ParagraphFormat.OutlineLevel = 10)
    MsgBox Selection.ParagraphFormat.OutlineLevel
   Exit Do
   Loop
   End Sub
Sub ScrollToUpperLeftCorner()
   Application.ScreenUpdating = False
   ActiveWindow.ScrollIntoView Selection.Range, True
   ActiveDocument.ActiveWindow.SmallScroll down:=14
   Application.ScreenUpdating = True
   End Sub
Sub WindowSwitcherWord()
   Application.ScreenUpdating = False
   If ActiveWindow.View.Zoom.Percentage <> myZoomPref _
      Then ActiveWindow.View.Zoom.Percentage = myZoomPref
   If ActiveWindow.View.Zoom.PageFit <> wdPageFitTextFit _
      Then ActiveWindow.View.Zoom.PageFit = wdPageFitTextFit
   With ActiveWindow
      .WindowState = xlNormal
      .Height = 0.75 * Application.UsableHeight
      .Width = 0.75 * Application.UsableWidth
   End With
   On Error Resume Next
   If Application.Left < -20 Then
      Application.CommandBars("Navigation").Width = NavPane_R
      Application.CommandBars("Navigation").Position = msoBarRight
      If DisplayHeight() < Display1Width() Then
         resize_and_AlignLeft
      Else
         ActiveWindow.Left = Application.UsableWidth
         ActiveWindow.WindowState = wdWindowStateMaximize
      End If
   Else
      Application.CommandBars("Navigation").Width = NavPane_L
      Application.CommandBars("Navigation").Position = msoBarLeft
      ActiveWindow.Left = -Application.UsableWidth
      ActiveWindow.Top = 1
      ActiveWindow.Height = Application.UsableHeight
      ActiveWindow.WindowState = wdWindowStateMaximize
   End If
   ActiveWindow.DocumentMap = True
   Application.ScreenUpdating = True
   End Sub
