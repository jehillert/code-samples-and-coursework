Attribute VB_Name = "PARAGRAPHS"
Sub Bold_Para_Numbers()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("Bold_Para_Numbers")
   Call Reset_FRS_FC
   Selection.Find.Replacement.Font.Bold = True
   Selection.Find.Text = "[^#^#^#^#^#]"
   Selection.Find.Replacement.Text = ""
   Selection.Find.Execute Replace:=wdReplaceAll
   Selection.Find.Text = "[^#^#^#^#]"
   Selection.Find.Replacement.Text = ""
   Selection.Find.Execute Replace:=wdReplaceAll
   Call Reset_FRS_FC
   objUndo.EndCustomRecord
   End Sub
Sub CutSelectedParagraphs()
   doStart ("CutSelectedParagraphs")
   Selection.Expand Unit:=wdParagraph
   Selection.Cut
   doStop
   End Sub
Sub CutSelectedSentences()
   doStart ("CutSelectedSentences")
   Selection.Expand Unit:=wdSentence
   Selection.Cut
   doStop
   End Sub
Sub DeleteEmptyParagraphs()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("DeleteEmptyParagraphs()")
   Reset_FRS
   If Selection.Type = wdSelectionIP Then
      Selection.HomeKey Unit:=wdStory
      Selection.Find.Wrap = wdFindContinue
   End If
   Selection.Find.Text = "^13^w^13"
   Selection.Find.Replacement.Text = "^p"
   Selection.Find.Execute Replace:=wdReplaceAll
   Selection.Find.MatchWildcards = True
   Selection.Find.Text = "(^13)\1@"
   Selection.Find.Replacement.Text = "^p"
   Selection.Find.Execute Replace:=wdReplaceAll
   Reset_FRS
   objUndo.EndCustomRecord
   End Sub
Sub DeleteParagraph()
   Dim pawj_option_was_on As Boolean
   If Options.PasteAdjustWordSpacing = True Then
      pawj_option_was_on = True
   End If
   On Error Resume Next
   Options.PasteAdjustWordSpacing = False
   Selection.PARAGRAPHS(1).Range.Delete
   If pawj_option_was_on = True Then
      Options.PasteAdjustWordSpacing = True
   End If
   End Sub
Sub DeleteToBeginningOfParagraph()
   Selection.collapse Direction:=wdCollapseStart
   Selection.MoveStart Unit:=wdParagraph, Count:=-1
   Selection.Delete
   End Sub
Sub DeleteToEndOfPara()
   Selection.collapse Direction:=wdCollapseEnd
   Selection.MoveEnd Unit:=wdParagraph, Count:=1
   Selection.Delete
   End Sub
Sub DeleteParagraphWF14()
   Application.ScreenUpdating = False
   If Selection.Type = wdSelectionIP Then
      Selection.PARAGRAPHS(1).Range.Delete
   Else
      Selection.Cut
   End If
   Application.ScreenUpdating = True
   End Sub
Sub duplicateParagraphBelow()
   Application.ScreenUpdating = False
   SelectParagraph
   Selection.Copy
   Selection.MoveDown Unit:=wdParagraph, Count:=-1
   Selection.Paste
   Selection.MoveDown Unit:=wdParagraph, Count:=-1
   Application.ScreenUpdating = True
   End Sub
Sub DeleteHeadingLevelsOfEmptyPara()
   iParCount = ActiveDocument.PARAGRAPHS.Count
   For j = 1 To iParCount
   sMyPar = ActiveDocument.PARAGRAPHS(j).Range.Text
   charCount = Len(sMyPar)
   If (charCount = 1) Then
      ActiveDocument.PARAGRAPHS(j).FORMAT.OutlineLevel = wdOutlineLevelBodyText
   End If
   Next j
   End Sub
Sub DeleteSentence()
   Selection.Sentences(1).Delete
   End Sub
Sub CutSelectedWords()
   doStart ("CutSelectedWords")
   Selection.Expand Unit:=wdWord
   Selection.Cut
   doStop
   End Sub
Sub ReverseClaimIndent()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("ReverseClaimIndent()")
   Selection.ParagraphFormat.LeftIndent = InchesToPoints(1.5)
   Selection.ParagraphFormat.SpaceBeforeAuto = False
   Selection.ParagraphFormat.SpaceAfterAuto = False
   Selection.ParagraphFormat.FirstLineIndent = InchesToPoints(-0.5)
   objUndo.EndCustomRecord
   End Sub
Sub IncreaseParagraphSpacingBefore()
   On Error Resume Next
   Selection.ParagraphFormat.SpaceBefore = Selection.ParagraphFormat.SpaceBefore + 3
   End Sub
Sub IncreaseParagraphSpacingAfter()
   On Error Resume Next
   Selection.ParagraphFormat.SpaceAfter = Selection.ParagraphFormat.SpaceAfter + 3
   End Sub
Sub IndentLeft()
   Selection.PARAGRAPHS.Outdent
   End Sub
Sub IndentRight()
   Selection.PARAGRAPHS.Indent
   End Sub
Sub JustifyFromLeft()
   START_FS ("Left to Justified")
   MarkSelection
   If Selection.Type = wdSelectionIP Then
      Selection.WholeStory
      Selection.Find.Wrap = wdFindContinue
   Else
      Selection.Find.Wrap = wdFindStop
   End If
   Selection.Find.FORMAT = True
   Selection.Find.ParagraphFormat.Alignment = wdAlignParagraphLeft
   Selection.Find.Replacement.ParagraphFormat.Alignment = wdAlignParagraphJustify
   Selection.Find.Text = ""
   Selection.Find.Replacement.Text = ""
   Selection.Find.Execute Replace:=wdReplaceAll
   Call Reset_FRS
   Reselect
   STOP_FS
   End Sub
Sub insert_blank_paragraphs()
   START_FS ("insert_blank_paragraphs")
   With Selection.Find
      .Text = "^p"
      .Replacement.Text = "^p<ABC>^p"
      .Execute Replace:=wdReplaceAll
      .Text = "<ABC>^p"
      .Replacement.Text = "^p"
      .Execute Replace:=wdReplaceAll
   End With
      DeleteHeadingLevelsOfEmptyPara
   STOP_FS
   End Sub
Sub ParaCleaner()
   START_FS ("ParaCleaner")
   With Selection.Find
   If Selection.Type = wdSelectionIP Then
      ActiveWindow.DocumentMap = Not ActiveWindow.DocumentMap
   Else
       .Text = "^l"
       .Replacement.Text = "^p"
       .Wrap = wdFindContinue
       .Execute Replace:=wdReplaceAll
       .Text = "^p"
       .Replacement.Text = " "
       .Wrap = wdFindStop
       .Execute Replace:=wdReplaceAll
       .Text = "  "
       .Replacement.Text = " "
       .Execute Replace:=wdReplaceAll
   Selection.MoveDown Unit:=wdParagraph, Count:=1
   End If
   End With
   STOP_FS
   End Sub

Sub RejoinParagraphFragments()
   START_FS ("RejoinParagraphFragments")
   If Selection.Type = wdSelectionIP Then
      Selection.WholeStory
      Selection.Find.Wrap = wdFindContinue
   Else
      Selection.Find.Wrap = wdFindStop
   End If
   With Selection.Find
      .MatchWildcards = True
      .Text = "(^11)([!^11])"
      .Replacement.Text = "\2"
      .Execute Replace:=wdReplaceAll
      .Text = "(^13)([!^13])"
      .Replacement.Text = "\2"
      .Execute Replace:=wdReplaceAll
      .Text = "(^13)\1@"
      .Replacement.Text = "^13^13"
      .Execute Replace:=wdReplaceAll
   End With
   STOP_FS
   End Sub
   
Sub PARA_0001_TAB()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("PARA_0001_TAB")
   Call Reset_FRS_FC
   Selection.Find.Text = "(\[[0-9][0-9][0-9][0-9]\])^13"
   Selection.Find.Replacement.Text = "\1^t"
   Selection.Find.MatchWildcards = True
   Selection.Find.Execute Replace:=wdReplaceAll
   Call Reset_FRS_FC
   objUndo.EndCustomRecord
   End Sub
Sub ParaNo1234()
   With ListGalleries(wdOutlineNumberGallery).ListTemplates(1).ListLevels(1)
      .NumberFormat = "[%1]"
      .TrailingCharacter = wdTrailingTab
      .NumberStyle = wdListNumberStyleArabicLZ3
      .NumberPosition = InchesToPoints(0)
      .Alignment = wdListLevelAlignLeft
      .TextPosition = InchesToPoints(0)
      .TabPosition = InchesToPoints(0.75)
      .ResetOnHigher = 0
      .StartAt = 1
      With .Font
         .Bold = False
         .Italic = False
         .StrikeThrough = wdUndefined
         .Subscript = wdUndefined
         .Superscript = wdUndefined
         .Shadow = wdUndefined
         .Outline = wdUndefined
         .Emboss = wdUndefined
         .Engrave = wdUndefined
         .AllCaps = wdUndefined
         .Hidden = wdUndefined
         .Underline = wdUndefined
         .color = wdUndefined
         .Size = 11
         .Animation = wdUndefined
         .DoubleStrikeThrough = wdUndefined
         .Name = ""
      End With
      .LinkedStyle = ""
   End With
   With ListGalleries(wdOutlineNumberGallery).ListTemplates(1).ListLevels(2)
      .NumberFormat = "%2"
      .TrailingCharacter = wdTrailingTab
      .NumberStyle = wdListNumberStyleNone
      .NumberPosition = InchesToPoints(0)
      .Alignment = wdListLevelAlignLeft
      .TextPosition = InchesToPoints(0)
      .TabPosition = wdUndefined
      .ResetOnHigher = 1
      .StartAt = 1
      With .Font
         .Bold = wdUndefined
         .Italic = wdUndefined
         .StrikeThrough = wdUndefined
         .Subscript = wdUndefined
         .Superscript = wdUndefined
         .Shadow = wdUndefined
         .Outline = wdUndefined
         .Emboss = wdUndefined
         .Engrave = wdUndefined
         .AllCaps = wdUndefined
         .Hidden = wdUndefined
         .Underline = wdUndefined
         .color = wdUndefined
         .Size = 11
         .Animation = wdUndefined
         .DoubleStrikeThrough = wdUndefined
         .Name = ""
      End With
      .LinkedStyle = ""
   End With
   With ListGalleries(wdOutlineNumberGallery).ListTemplates(1).ListLevels(3)
      .NumberFormat = "%3"
      .TrailingCharacter = wdTrailingTab
      .NumberStyle = wdListNumberStyleNone
      .NumberPosition = InchesToPoints(0)
      .Alignment = wdListLevelAlignRight
      .TextPosition = InchesToPoints(0)
      .TabPosition = wdUndefined
      .ResetOnHigher = 2
      .StartAt = 1
      With .Font
         .Bold = wdUndefined
         .Italic = wdUndefined
         .StrikeThrough = wdUndefined
         .Subscript = wdUndefined
         .Superscript = wdUndefined
         .Shadow = wdUndefined
         .Outline = wdUndefined
         .Emboss = wdUndefined
         .Engrave = wdUndefined
         .AllCaps = wdUndefined
         .Hidden = wdUndefined
         .Underline = wdUndefined
         .color = wdUndefined
         .Size = 11
         .Animation = wdUndefined
         .DoubleStrikeThrough = wdUndefined
         .Name = ""
      End With
      .LinkedStyle = ""
   End With
   With ListGalleries(wdOutlineNumberGallery).ListTemplates(1).ListLevels(4)
      .NumberFormat = "%4"
      .TrailingCharacter = wdTrailingTab
      .NumberStyle = wdListNumberStyleNone
      .NumberPosition = InchesToPoints(0)
      .Alignment = wdListLevelAlignLeft
      .TextPosition = InchesToPoints(0)
      .TabPosition = wdUndefined
      .ResetOnHigher = 3
      .StartAt = 1
      With .Font
         .Bold = wdUndefined
         .Italic = wdUndefined
         .StrikeThrough = wdUndefined
         .Subscript = wdUndefined
         .Superscript = wdUndefined
         .Shadow = wdUndefined
         .Outline = wdUndefined
         .Emboss = wdUndefined
         .Engrave = wdUndefined
         .AllCaps = wdUndefined
         .Hidden = wdUndefined
         .Underline = wdUndefined
         .color = wdUndefined
         .Size = 11
         .Animation = wdUndefined
         .DoubleStrikeThrough = wdUndefined
         .Name = ""
      End With
      .LinkedStyle = ""
   End With
   With ListGalleries(wdOutlineNumberGallery).ListTemplates(1).ListLevels(5)
      .NumberFormat = "%5"
      .TrailingCharacter = wdTrailingTab
      .NumberStyle = wdListNumberStyleNone
      .NumberPosition = InchesToPoints(0)
      .Alignment = wdListLevelAlignLeft
      .TextPosition = InchesToPoints(0)
      .TabPosition = wdUndefined
      .ResetOnHigher = 1
      .StartAt = 1
      With .Font
         .Bold = wdUndefined
         .Italic = wdUndefined
         .StrikeThrough = wdUndefined
         .Subscript = wdUndefined
         .Superscript = wdUndefined
         .Shadow = wdUndefined
         .Outline = wdUndefined
         .Emboss = wdUndefined
         .Engrave = wdUndefined
         .AllCaps = wdUndefined
         .Hidden = wdUndefined
         .Underline = wdUndefined
         .color = wdUndefined
         .Size = 11
         .Animation = wdUndefined
         .DoubleStrikeThrough = wdUndefined
         .Name = ""
      End With
      .LinkedStyle = ""
   End With
   With ListGalleries(wdOutlineNumberGallery).ListTemplates(1).ListLevels(6)
      .NumberFormat = "%6"
      .TrailingCharacter = wdTrailingTab
      .NumberStyle = wdListNumberStyleNone
      .NumberPosition = InchesToPoints(0)
      .Alignment = wdListLevelAlignRight
      .TextPosition = InchesToPoints(0)
      .TabPosition = InchesToPoints(0)
      .ResetOnHigher = 5
      .StartAt = 1
      With .Font
         .Bold = wdUndefined
         .Italic = wdUndefined
         .StrikeThrough = wdUndefined
         .Subscript = wdUndefined
         .Superscript = wdUndefined
         .Shadow = wdUndefined
         .Outline = wdUndefined
         .Emboss = wdUndefined
         .Engrave = wdUndefined
         .AllCaps = wdUndefined
         .Hidden = wdUndefined
         .Underline = wdUndefined
         .color = wdUndefined
         .Size = 11
         .Animation = wdUndefined
         .DoubleStrikeThrough = wdUndefined
         .Name = ""
      End With
      .LinkedStyle = ""
   End With
   With ListGalleries(wdOutlineNumberGallery).ListTemplates(1).ListLevels(7)
      .NumberFormat = "%7"
      .TrailingCharacter = wdTrailingTab
      .NumberStyle = wdListNumberStyleNone
      .NumberPosition = InchesToPoints(0)
      .Alignment = wdListLevelAlignLeft
      .TextPosition = InchesToPoints(0)
      .TabPosition = wdUndefined
      .ResetOnHigher = 6
      .StartAt = 1
      With .Font
         .Bold = wdUndefined
         .Italic = wdUndefined
         .StrikeThrough = wdUndefined
         .Subscript = wdUndefined
         .Superscript = wdUndefined
         .Shadow = wdUndefined
         .Outline = wdUndefined
         .Emboss = wdUndefined
         .Engrave = wdUndefined
         .AllCaps = wdUndefined
         .Hidden = wdUndefined
         .Underline = wdUndefined
         .color = wdUndefined
         .Size = 11
         .Animation = wdUndefined
         .DoubleStrikeThrough = wdUndefined
         .Name = ""
      End With
      .LinkedStyle = ""
   End With
   With ListGalleries(wdOutlineNumberGallery).ListTemplates(1).ListLevels(8)
      .NumberFormat = "%8"
      .TrailingCharacter = wdTrailingTab
      .NumberStyle = wdListNumberStyleNone
      .NumberPosition = InchesToPoints(0)
      .Alignment = wdListLevelAlignLeft
      .TextPosition = InchesToPoints(0)
      .TabPosition = wdUndefined
      .ResetOnHigher = 1
      .StartAt = 1
      With .Font
         .Bold = wdUndefined
         .Italic = wdUndefined
         .StrikeThrough = wdUndefined
         .Subscript = wdUndefined
         .Superscript = wdUndefined
         .Shadow = wdUndefined
         .Outline = wdUndefined
         .Emboss = wdUndefined
         .Engrave = wdUndefined
         .AllCaps = wdUndefined
         .Hidden = wdUndefined
         .Underline = wdUndefined
         .color = wdUndefined
         .Size = 11
         .Animation = wdUndefined
         .DoubleStrikeThrough = wdUndefined
         .Name = ""
      End With
      .LinkedStyle = ""
   End With
   With ListGalleries(wdOutlineNumberGallery).ListTemplates(1).ListLevels(9)
      .NumberFormat = "%9"
      .TrailingCharacter = wdTrailingTab
      .NumberStyle = wdListNumberStyleNone
      .NumberPosition = InchesToPoints(0)
      .Alignment = wdListLevelAlignRight
      .TextPosition = InchesToPoints(0)
      .TabPosition = wdUndefined
      .ResetOnHigher = 8
      .StartAt = 1
      With .Font
         .Bold = wdUndefined
         .Italic = wdUndefined
         .StrikeThrough = wdUndefined
         .Subscript = wdUndefined
         .Superscript = wdUndefined
         .Shadow = wdUndefined
         .Outline = wdUndefined
         .Emboss = wdUndefined
         .Engrave = wdUndefined
         .AllCaps = wdUndefined
         .Hidden = wdUndefined
         .Underline = wdUndefined
         .color = wdUndefined
         .Size = 11
         .Animation = wdUndefined
         .DoubleStrikeThrough = wdUndefined
         .Name = ""
      End With
      .LinkedStyle = ""
   End With
   ListGalleries(wdOutlineNumberGallery).ListTemplates(1).Name = ""
   Selection.Range.ListFormat.ApplyListTemplateWithLevel ListTemplate:= _
      ListGalleries(wdOutlineNumberGallery).ListTemplates(1), _
      ContinuePreviousList:=False, ApplyTo:=wdListApplyToWholeList, _
      DefaultListBehavior:=wdWord10ListBehavior
   End Sub
Sub reset_indentation()
   START_FS ("reset_indentation")
   If Selection.Type = wdSelectionIP Then SelectParagraph
   Selection.ParagraphFormat.RightIndent = InchesToPoints(0)
   Selection.ParagraphFormat.LeftIndent = InchesToPoints(0)
   Selection.ParagraphFormat.SpaceBeforeAuto = False
   Selection.ParagraphFormat.SpaceAfterAuto = False
   Selection.ParagraphFormat.FirstLineIndent = InchesToPoints(0)
   Selection.ParagraphFormat.TabStops.ClearAll
   STOP_FS
   End Sub
Sub ResetParagraphSpacing()
   On Error Resume Next
   Selection.ParagraphFormat.SpaceBefore = 0
   Selection.ParagraphFormat.SpaceAfter = 0
   End Sub
Sub BasicIndent()
   START_FS ("BasicIndent")
   MarkSelection
   If Selection.Type = wdSelectionIP Then Selection.WholeStory
   Selection.ParagraphFormat.RightIndent = InchesToPoints(0)
   Selection.ParagraphFormat.LeftIndent = InchesToPoints(0)
   Selection.ParagraphFormat.FirstLineIndent = InchesToPoints(0.5)
   Reselect
   STOP_FS
   End Sub
Sub SelectParagraph()
   Selection.Expand Unit:=wdParagraph
   End Sub
