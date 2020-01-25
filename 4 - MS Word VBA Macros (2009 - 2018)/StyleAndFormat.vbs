Attribute VB_Name = "StyleAndFormat"
'   If Selection.Type = wdSelectionIP Then
'      Selection.WholeStory
'      Selection.Find.Wrap = wdFindContinue
'   Else
'      Selection.Find.Wrap = wdFindStop
'   End If
'
'
'
'
'
'
'
'
'
Function style_exists(test_document As Word.Document, style_name As String) As Boolean
   style_exists = False
   On Error Resume Next
   style_exists = test_document.Styles(style_name).NameLocal = style_name
End Function
 Sub BoldNumbers()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("Bold Numbers")
   Call Reset_FRS_FC
   Selection.Find.FORMAT = True
   Selection.Find.Replacement.Font.Bold = True
   Selection.Find.Text = "^#"
   Selection.Find.Replacement.Text = ""
   Selection.Find.Execute Replace:=wdReplaceAll
   Call Reset_FRS_FC
   
   Selection.Find.Replacement.Font.Bold = False
   Selection.Find.Text = "[^#^#^#^#]"
   Selection.Find.Replacement.Text = ""
   Selection.Find.Execute Replace:=wdReplaceAll
    
   Selection.Find.Replacement.Font.Bold = False
   Selection.Find.Text = "[^#^#^#^#^#]"
   Selection.Find.Replacement.Text = ""
   Selection.Find.Execute Replace:=wdReplaceAll
   
   Call Reset_FRS_FC
   objUndo.EndCustomRecord
End Sub
Sub CleanUpPastedText()
   Application.ScreenUpdating = False
   With Selection.Range.Find
     .ClearFormatting
     .Replacement.ClearFormatting
     .Forward = True
     .Wrap = wdFindStop
     .FORMAT = False
     .MatchAllWordForms = False
     .MatchSoundsLike = False
     .MatchWildcards = True
     'Eliminate spaces & tabs before paragraph breaks.
     .Text = "[ ^s^t]{1,}^13"
     .Replacement.Text = "^p"
     .Execute Replace:=wdReplaceAll
     'Replace single paragraph breaks with a space
     .Text = "([!^13])([^13])([!^13])"
     .Replacement.Text = "\1 \3"
     'Replace all double spaces with single spaces
     .Execute Replace:=wdReplaceAll
     .Text = "[ ]{2,}"
     .Replacement.Text = " "
     'Delete hypens in hyphenated text formerly split across lines
     .Execute Replace:=wdReplaceAll
     .Text = "([a-z])-[ ]{1,}([a-z])"
     .Replacement.Text = "\1\2"
     .Execute Replace:=wdReplaceAll
     'Limit paragraph breaks to one per 'real' paragraph.
     .Text = "[^13]{1,}"
     .Replacement.Text = "^p"
     .Execute Replace:=wdReplaceAll
   End With
   'Restore Screen Updating
   Application.ScreenUpdating = True
End Sub
Sub ListIndentLeft()
   Selection.Range.ListFormat.ListOutdent
   End Sub
Sub ListIndentRight()
   Selection.Range.ListFormat.ListIndent
   End Sub
Sub InsertAutoCorrectEntries()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("InsertAutoCorrectEntries")
   ' "ACE" = variable for storing each entry "AutoCorrectEntry" is the data type
   Dim ACE As AutoCorrectEntry
   ' Create new document.
   Documents.Add
   ' Iterate through AutoCorrect entries.
   For Each ACE In Application.AutoCorrect.Entries
   ' Insert each entry name and its value on a new line.
      Selection.TypeText ACE.Name & vbTab & ACE.Value & " " & vbCr
   Next
   ' make list single spaced
   Selection.WholeStory
   Selection.ParagraphFormat.Space1
   objUndo.EndCustomRecord
   End Sub
Sub format_document_breaks()
   Call FindReplaceText("^11", "^13")
   Call FindReplaceText("^b", "^m")
   Call FindReplaceText("^l", "^13")
   Call FindReplaceText("^n", "^13")
   End Sub
 Sub FormFieldShading()
   ActiveDocument.FormFields.Shaded = Not ActiveDocument.FormFields.Shaded
   End Sub
 Sub InchesToPoint()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("InchesToPoint()")
   Selection.Find.ClearFormatting
   Selection.Find.ParagraphFormat.LeftIndent = InchesToPoints(1)
   Selection.Find.Replacement.ClearFormatting
   Selection.Find.Replacement.ParagraphFormat.RightIndent = InchesToPoints(1)
   Selection.Find.FORMAT = True
   Selection.Find.Execute Replace:=wdReplaceAll
   Call Reset_FRS_FC
   objUndo.EndCustomRecord
   End Sub
Sub NormalMargins()
   With Selection.PageSetup
      .LineNumbering.Active = False
      .Orientation = wdOrientPortrait
      .TopMargin = InchesToPoints(1)
      .BottomMargin = InchesToPoints(1)
      .LeftMargin = InchesToPoints(1)
      .RightMargin = InchesToPoints(1)
      .Gutter = InchesToPoints(0)
      .HeaderDistance = InchesToPoints(0)
      .FooterDistance = InchesToPoints(0)
      .PageWidth = InchesToPoints(8.26)
      .PageHeight = InchesToPoints(11.69)
      .FirstPageTray = wdPrinterDefaultBin
      .OtherPagesTray = wdPrinterDefaultBin
      .SectionStart = wdSectionNewPage
      .OddAndEvenPagesHeaderFooter = True
      .DifferentFirstPageHeaderFooter = False
      .VerticalAlignment = wdAlignVerticalTop
      .SuppressEndnotes = True
      .MirrorMargins = False
      .TwoPagesOnOne = False
      .BookFoldPrinting = False
      .BookFoldRevPrinting = False
      .BookFoldPrintingSheets = 1
      .GutterPos = wdGutterPosLeft
   End With
   End Sub
Sub NumberEveryLine()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("Number Every Line")
   Selection.WholeStory
   With ActiveDocument.Styles(wdStyleNormal).Font
      If .NameFarEast = .NameAscii Then .NameAscii = ""
      .NameFarEast = ""
   End With
   ActiveDocument.PageSetup.LineNumbering.Active = True
   ActiveDocument.PageSetup.LineNumbering.StartingNumber = 1
   ActiveDocument.PageSetup.LineNumbering.CountBy = 1
   ActiveDocument.PageSetup.LineNumbering.RestartMode = wdRestartPage
   ActiveDocument.PageSetup.LineNumbering.DistanceFromText = wdAutoPosition
   ActiveDocument.PageSetup.Orientation = wdOrientPortrait
   ActiveDocument.PageSetup.TopMargin = InchesToPoints(1)
   ActiveDocument.PageSetup.BottomMargin = InchesToPoints(1)
   ActiveDocument.PageSetup.LeftMargin = InchesToPoints(1)
   ActiveDocument.PageSetup.RightMargin = InchesToPoints(1)
   ActiveDocument.PageSetup.Gutter = InchesToPoints(0)
   ActiveDocument.PageSetup.HeaderDistance = InchesToPoints(0.5)
   ActiveDocument.PageSetup.FooterDistance = InchesToPoints(0.5)
   ActiveDocument.PageSetup.PageWidth = InchesToPoints(8.27)
   ActiveDocument.PageSetup.PageHeight = InchesToPoints(11.69)
   ActiveDocument.PageSetup.FirstPageTray = wdPrinterDefaultBin
   ActiveDocument.PageSetup.OtherPagesTray = wdPrinterDefaultBin
   ActiveDocument.PageSetup.SectionStart = wdSectionNewPage
   ActiveDocument.PageSetup.OddAndEvenPagesHeaderFooter = False
   ActiveDocument.PageSetup.DifferentFirstPageHeaderFooter = False
   ActiveDocument.PageSetup.VerticalAlignment = wdAlignVerticalTop
   ActiveDocument.PageSetup.SuppressEndnotes = False
   ActiveDocument.PageSetup.MirrorMargins = False
   ActiveDocument.PageSetup.TwoPagesOnOne = False
   ActiveDocument.PageSetup.BookFoldPrinting = False
   ActiveDocument.PageSetup.BookFoldRevPrinting = False
   ActiveDocument.PageSetup.BookFoldPrintingSheets = 1
   ActiveDocument.PageSetup.GutterPos = wdGutterPosLeft
   objUndo.EndCustomRecord
End Sub
Sub PasteFormat()
   Selection.PasteFormat
   End Sub
 Sub TEXT_Bold()
   START_FC ("TEXT_Bold")
   If Selection.Type = wdSelectionIP Then
      Selection.Expand Unit:=wdWord
   End If
   Call Reset_FRS_FC
   If Selection.Font.Bold = False Then
      Selection.Find.Replacement.Font.Bold = True
   Else
      Selection.Find.Replacement.Font.Bold = False
   End If
   Selection.Find.FORMAT = True
   Selection.Find.Text = Selection
   Selection.Find.Replacement.Text = ""
   Selection.Find.Execute Replace:=wdReplaceAll
   STOP_FS
   End Sub
 Sub TEXT_Underline()
   'Attribute TEXT_Underline.VB_ProcData.VB_Invoke_Func = "Normal.BoldTextUnderline.Macro2"
   START_FC ("TEXT_Underline")
   If Selection.Type = wdSelectionIP Then
      Selection.Expand Unit:=wdWord
   End If
   If Selection.Font.Underline = wdUnderlineNone Then
      Selection.Find.Replacement.Font.Underline = wdUnderlineSingle
   ElseIf Selection.Font.Underline = wdUnderlineSingle Then
      Selection.Find.Replacement.Font.Underline = wdUnderlineDouble
   Else
      Selection.Find.Replacement.Font.Underline = wdUnderlineNone
   End If
   Selection.Find.FORMAT = True
   Selection.Find.Text = Selection
   Selection.Find.Replacement.Text = ""
   Selection.Find.Execute Replace:=wdReplaceAll
   STOP_FS
   End Sub
Sub TEXT_Italicize()
   START_FC ("TEXT_Italicize")
   If Selection.Type = wdSelectionIP Then
      Selection.Expand Unit:=wdWord
   End If
   If Selection.Font.Italic = False Then
      Selection.Find.Replacement.Font.Italic = True
   Else
      Selection.Find.Replacement.Font.Italic = False
   End If
   Selection.Find.FORMAT = True
   Selection.Find.Text = Selection
   Selection.Find.Replacement.Text = ""
   Selection.Find.Execute Replace:=wdReplaceAll
   STOP_FS
   End Sub




' Sub TEXT_Bold()
'   START_FC ("TEXT_Bold")
'   If Selection.Type = wdSelectionIP Then
'      Selection.Expand Unit:=wdWord
'   End If
'   If Selection.Font.Bold = False Then
'      Selection.Find.Replacement.Font.Bold = True
'   Else
'      Selection.Find.Replacement.Font.Bold = False
'   End If
'   Selection.Find.FORMAT = True
'   Selection.Find.TEXT = Selection
'   Selection.Find.Replacement.TEXT = ""
'   Selection.Find.Execute Replace:=wdReplaceAll
'   STOP_FS
'   End Sub
' Sub TEXT_Underline()
'   START_FC ("TEXT_Bold")
'   If Selection.Type = wdSelectionIP Then Selection.Expand Unit:=wdWord
'   If Selection.Font.Underline = wdUnderlineNone Then
'      Selection.Find.Replacement.Font.Underline = wdUnderlineDouble
'   Else
'      Selection.Find.Replacement.Font.Underline = wdUnderlineNone
'   End If
'   Selection.Find.FORMAT = True
'   Selection.Find.TEXT = Selection
'   Selection.Find.Replacement.TEXT = ""
'   STOP_FS
'   End Sub
'Sub TEXT_Italicize()
'   START_FC ("TEXT_Italicize")
'   If Selection.Type = wdSelectionIP Then Selection.Expand Unit:=wdWord
'   Call Reset_FRS_FC
'   If Selection.Font.Italic = False Then
'      Selection.Find.Replacement.Font.Italic = True
'   Else
'      Selection.Find.Replacement.Font.Italic = False
'   End If
'   Selection.Find.FORMAT = True
'   Selection.Find.TEXT = Selection
'   Selection.Find.Replacement.TEXT = ""
'   Selection.Find.Execute Replace:=wdReplaceAll
'   STOP_FS
'   End Sub
'
