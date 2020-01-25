Attribute VB_Name = "CONVERT"
Sub AllTablesToText()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("AllTablesToText()")
   Do While ActiveDocument.Tables.Count > 0
      ActiveDocument.Tables(1).ConvertToText Separator:=wdSeparateByTabs
   Loop
   objUndo.EndCustomRecord
   End Sub
Sub BreaksToPara()
   Call FindReplaceText("^11", "^13")
   Call FindReplaceText("^b", "^13")
   Call FindReplaceText("^l", "^13")
   Call FindReplaceText("^m", "^13")
   Call FindReplaceText("^n", "^13")
   End Sub
Sub convert_pdf_to_docx_via_Foxit()
   doStart ("convert_pdf_to_docx_via_Foxit")
   Call FindReplaceText("^l", " ")
   DeleteBreaksInSelection
   ConvertAllNumbers
   DeleteGraphics
   Reset
   Selection.WholeStory
   Selection.ClearFormatting
   Selection.Font.Name = my_font
   Selection.Font.Size = MY_FONT_SIZE
   ActiveWindow.DocumentMap = True
   Application.CommandBars("Navigation").Width = NavPane_R
'   Application.CommandBars("Navigation").Position = msoBarRight
   ActiveDocument.ActiveWindow.View.Type = wdWebView
   ActiveWindow.ActivePane.View.Zoom.PageFit = wdPageFitFullPage
   JustifyFromLeft
   insert_blank_paragraphs
   Selection.collapse Direction:=wdCollapseStart
   doStop
   End Sub
Sub convert_all_fields_to_text()
   doStart ("convert_all_fields_to_text")
   If Selection.Type = wdSelectionIP Then
      Selection.WholeStory
   End If
   'ActiveDocument.ConvertNumbersToText
   'Application.ActiveDocument.Fields.Unlink
   Selection.Range.ListFormat.ConvertNumbersToText
   Selection.Fields.Unlink
   doStop
   End Sub
Sub ConvertAllNumbers()
   ActiveDocument.ConvertNumbersToText
   Application.ActiveDocument.Fields.Unlink
   End Sub
Sub ConvertToEndnote()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("Convert to Endnote")
   Selection.Cut
   Selection.MoveLeft Unit:=wdCharacter, Count:=1
   With Selection
      With .EndnoteOptions
         .Location = wdEndOfDocument
         .NumberingRule = wdRestartContinuous
         .StartingNumber = 1
         .NumberStyle = wdNoteNumberStyleLowercaseRoman
      End With
   .Endnotes.Add Range:=Selection.Range, Reference:=""
   End With
   Selection.PasteAndFormat (wdFormatSurroundingFormattingWithEmphasis)
   Selection.TypeParagraph
   Selection.MoveUp Unit:=wdParagraph, Count:=1, Extend:=wdExtend
   objUndo.EndCustomRecord
   End Sub
Sub ConvertToFootnote()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("Convert to Footnote")
   Selection.Cut
   With Selection
      .FootnoteOptions.Location = wdBottomOfPage
      .FootnoteOptions.NumberingRule = wdRestartContinuous
      .FootnoteOptions.StartingNumber = 1
      .FootnoteOptions.NumberStyle = wdNoteNumberStyleArabic
      .FootnoteOptions.LayoutColumns = 0
      .Footnotes.Add Range:=Selection.Range, Reference:=""
   End With
   Selection.PasteAndFormat (wdFormatSurroundingFormattingWithEmphasis)
   Selection.TypeParagraph
   Selection.MoveUp Unit:=wdParagraph, Count:=1, Extend:=wdExtend
   objUndo.EndCustomRecord
   End Sub
Sub LineBreakToParaBreak()
   Call FindReplaceText("^l", "^p")
   End Sub
Sub RemoveAutoNumbering()
   START_FS ("RemoveAutoNumbering")
   MarkSelection
   If Selection.Type = wdSelectionIP Then
   Selection.WholeStory
   End If
   Selection.Range.ListFormat.RemoveNumbers NumberType:=wdNumberParagraph
   Reselect
   STOP_FS
   End Sub
Sub ReplaceSectionBreaks()
   Call FindReplaceText("^b", "^m")
   End Sub
Sub UnlinkFields()
   START_FS ("UnlinkFields")
   If Selection.Type = wdSelectionIP Then
      Selection.WholeStory
   End If
   Selection.Fields.Unlink
   Selection.collapse Direction:=wdCollapseStart
   STOP_FS
   End Sub
