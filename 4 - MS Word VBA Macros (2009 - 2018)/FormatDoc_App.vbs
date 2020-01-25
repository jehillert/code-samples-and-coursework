Attribute VB_Name = "FormatDoc_App"
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

Sub FormatAsRef()
   FormatDoc
   BgEvergreen
End Sub
Sub FormatAsApp()
   FormatDoc
   BgYellow
End Sub
Sub FormatDoc()

   START_FC ("FormatDoc")
   
   FormatWholeStory
   'FormatClaims
   format_claims
   
   Selection.Find.Text = "^p"
   Selection.Find.Replacement.Text = "^p^p"
   Selection.Find.Execute Replace:=wdReplaceAll
   
   Selection.Find.FORMAT = True
   Selection.Find.Replacement.ParagraphFormat.SpaceAfter = 8
   Selection.Find.Replacement.ParagraphFormat.LineUnitAfter = 0
   Selection.Find.Text = ""
   Selection.Find.Replacement.Text = ""
   Selection.Find.Execute Replace:=wdReplaceAll
   
   Selection.Find.Text = "]^w^t"
   Selection.Find.Replacement.Text = "]^t"
   Selection.Find.Execute Replace:=wdReplaceAll
   capitalize_app_headings
   Selection.Find.FORMAT = False
   
   Format_0001
   DeleteEmptyParagraphs
   ApplicationTOC
   AssignParasOL2
   
   Reset_FRS_FC
   
   Selection.Find.Text = "CLAIMS^13"
   Selection.Find.Replacement.Text = ""
   Selection.Find.MatchCase = True
   Selection.Find.Execute
   
   Selection.MoveRight Unit:=wdCharacter, Count:=1
   Selection.EndKey Unit:=wdStory, Extend:=wdExtend
   Selection.MoveUp Unit:=wdParagraph, Count:=2, Extend:=wdExtend
   Selection.HomeKey Unit:=wdStory
   Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
   
   MoveAbstractToEnd
   reset_indentation
   JustifyFromLeft
   ActiveWindow.View.Zoom.Percentage = myZoomPref
   ActiveWindow.View.Type = wdWebView
   STOP_FS
   End Sub
Private Sub ApplicationTOC()
   Dim SingleLine As Paragraph
   Dim lineText As String
   Selection.WholeStory
   For Each SingleLine In Selection.PARAGRAPHS
   lineText = SingleLine.Range.Text
   If (InStr(lineText, "CROSS-REFERENCES TO RELATED APPLICATIONS") Or _
      InStr(lineText, "RELATED APPLICATIONS") Or _
      InStr(lineText, "TECHNICAL FIELD OF THE INVENTION") Or _
      InStr(lineText, "FIELD OF THE INVENTION") Or _
      InStr(lineText, "BACKGROUND AND SUMMARY OF THE INVENTION") Or _
      InStr(lineText, "BACKGROUND OF THE INVENTION") Or _
      InStr(lineText, "SUMMARY OF THE INVENTION") Or _
      InStr(lineText, "BRIEF DESCRIPTION OF THE DRAWINGS") Or _
      InStr(lineText, "DETAILED DESCRIPTION OF PREFERRED EMBODIMENTS") Or _
      InStr(lineText, "DESCRIPTION OF THE PREFERRED EMBODIMENTS") Or _
      InStr(lineText, "DETAILED DESCRIPTION OF THE INVENTION") Or _
      InStr(lineText, "DETAILED DESCRIPTION") Or _
      InStr(lineText, "ABSTRACT") Or _
      InStr(lineText, "CLAIMS")) > 0 _
   Then
      SingleLine.OutlineLevel = wdOutlineLevel1
      SingleLine.FORMAT.SpaceAfter = 18
      SingleLine.FORMAT.SpaceBefore = 18
      SingleLine.FORMAT.Alignment = wdAlignParagraphCenter
   End If
   Next SingleLine
   End Sub
Private Sub AssignParasOL2()
   Dim MyInput As String
   Dim SingleLine As Paragraph
   Dim lineText As String
   Selection.Range.ListFormat.ConvertNumbersToText
   For Each SingleLine In Selection.PARAGRAPHS
      lineText = SingleLine.Range.Text
      If (InStr(lineText, Chr(91)) = 1 And (InStr(lineText, Chr(93)) = 6 Or InStr(lineText, Chr(93)) = 7)) Then
          SingleLine.OutlineLevel = wdOutlineLevel2
      End If
   Next SingleLine
   End Sub
Private Sub capitalize_app_headings()
   Selection.Find.Wrap = wdFindContinue
   Selection.Find.FORMAT = True
   Selection.Find.Replacement.ParagraphFormat.FirstLineIndent = InchesToPoints(0)
   Selection.Find.Replacement.ParagraphFormat.LineUnitBefore = 0
   Selection.Find.Replacement.ParagraphFormat.LineUnitAfter = 2
   Selection.Find.Replacement.Font.Underline = wdUnderlineNone
   Selection.Find.Replacement.Font.Bold = False
   Call find_and_capitalize("Cross-references to Related Applications^13")
   Call find_and_capitalize("Related Applications^13")
   Call find_and_capitalize("Technical Field of the Invention^13")
   Call find_and_capitalize("Field of the Invention^13")
   Call find_and_capitalize("Background and Summary of the Invention^13")
   Call find_and_capitalize("Background of the Invention^13")
   Call find_and_capitalize("Summary of the Invention^13")
   Call find_and_capitalize("Brief Description of the Drawings^13")
   Call find_and_capitalize("Detailed Description^13")
   Call find_and_capitalize("Detailed Description of the Invention^13")
   Call find_and_capitalize("Detailed Description of the Preferred Embodiments^13")
   Call find_and_capitalize("Detailed Description of Preferred Embodiments^13")
   Call find_and_capitalize("Abstract^13")
   Selection.Find.MatchWildcards = True
   Selection.Find.Text = "Claims \([0-9]{1,3}\)"
   Selection.Find.Replacement.Text = "Claims"
   Selection.Find.Execute Replace:=wdReplaceAll
   Selection.Find.MatchWildcards = False
   Call find_and_capitalize("Claims^13")
   Reset_FRS_FC
   End Sub
Sub Format_0001()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("Format_0001()")
   Reset_FRS_FC
   Selection.Find.MatchWildcards = True
   Selection.Find.Text = "(\[[0-9][0-9][0-9][0-9]@\])^13(<*>)"
   Selection.Find.Replacement.Text = "\1^t\2"
   Selection.Find.Execute Replace:=wdReplaceAll
   Selection.Find.FORMAT = True
   Selection.Find.Replacement.ParagraphFormat.TabStops.Add Position:= _
   InchesToPoints(0.75), Alignment:=wdAlignTabLeft, Leader:=wdTabLeaderSpaces
   Selection.Find.Text = "(\[[0-9][0-9][0-9][0-9]\])*(<*>)"
   Selection.Find.Replacement.Text = "\1^t\2"
   Selection.Find.Execute Replace:=wdReplaceAll
   Reset_FRS_FC
   objUndo.EndCustomRecord
   End Sub
Private Sub format_claims()
   Selection.Find.Wrap = wdFindStop
   Selection.ParagraphFormat.OutlineLevel = wdOutlineLevelBodyText
   ActiveDocument.DefaultTabStop = InchesToPoints(0.5)
   Selection.ParagraphFormat.TabStops.ClearAll
   Selection.Range.ListFormat.ConvertNumbersToText
   Selection.Fields.Unlink
   Selection.ParagraphFormat.SpaceAfter = 0
   Selection.ParagraphFormat.LeftIndent = InchesToPoints(0)
   Selection.ParagraphFormat.CharacterUnitLeftIndent = 0
   Selection.ParagraphFormat.LeftIndent = InchesToPoints(0)
   Selection.ParagraphFormat.FirstLineIndent = InchesToPoints(0)
   Selection.ParagraphFormat.CharacterUnitFirstLineIndent = 0
   format_claim_number_tab
   Call FindReplaceInSelection("^l", "^p")
   Call FindReplaceInSelection("^w^p", "^p")
   IndentClaimBodyParagraphs
   DeleteEmptyParagraphs
   Selection.Find.ClearFormatting
   Selection.Find.Replacement.ClearFormatting
   Selection.Find.FORMAT = True
   Selection.Find.Text = ".^p"
   Selection.Find.Replacement.Text = ".^p^p"
   Selection.Find.Execute Replace:=wdReplaceAll
   AssignClaimsOL2
   Call Reset_FRS_FC
   End Sub
Private Sub format_claim_number_tab()
   Call FindReplaceInSelection_WildcardsOn("(^13)([0-9]{1,2}).([ ^t]{1,5})(<[AT][ nh])", "\1\2.^t\4")
   End Sub
Private Sub FormatWholeStory()
   ActiveDocument.ConvertNumbersToText
   Selection.WholeStory
   Selection.Fields.Unlink
   Selection.Font.Size = MY_FONT_SIZE
   Selection.Font.Name = my_font
   Selection.Font.Bold = False
   Selection.ParagraphFormat.Space1
   'Selection.ParagraphFormat.LineSpacing = LinesToPoints(1.5)
   Selection.ParagraphFormat.LeftIndent = InchesToPoints(0)
   Selection.ParagraphFormat.RightIndent = InchesToPoints(0)
   Selection.ParagraphFormat.FirstLineIndent = InchesToPoints(0)
   Selection.ParagraphFormat.CharacterUnitLeftIndent = 0
   Selection.ParagraphFormat.CharacterUnitRightIndent = 0
   Selection.ParagraphFormat.CharacterUnitFirstLineIndent = 0
   Selection.ParagraphFormat.SpaceAfter = 0
   Selection.ParagraphFormat.LineUnitAfter = 0
   Selection.ParagraphFormat.SpaceBefore = 0
   Selection.ParagraphFormat.LineUnitBefore = 0
   Selection.ParagraphFormat.SpaceBeforeAuto = False
   Selection.ParagraphFormat.SpaceAfterAuto = False
   Selection.ParagraphFormat.OutlineLevel = wdOutlineLevelBodyText
   Selection.ParagraphFormat.TabStops.ClearAll
   ActiveDocument.DefaultTabStop = InchesToPoints(0.25)
   DeleteTrailingMixedWhiteSpace
   Call FindReplaceText("^11", "^13")
   Call FindReplaceText("^b", "^13")
   Call FindReplaceText("^l", "^13")
   Call FindReplaceText("^m", "^13")
   Call FindReplaceText("^n", "^13")
   End Sub

Private Sub reset_indent()

   Selection.ParagraphFormat.RightIndent = InchesToPoints(0)
   Selection.ParagraphFormat.SpaceBeforeAuto = False
   Selection.ParagraphFormat.SpaceAfterAuto = False
   Selection.ParagraphFormat.LeftIndent = InchesToPoints(0)
   Selection.ParagraphFormat.SpaceBeforeAuto = False
   Selection.ParagraphFormat.SpaceAfterAuto = False
   Selection.ParagraphFormat.FirstLineIndent = InchesToPoints(0)
   End Sub
   

Private Sub find_and_capitalize(FindText As String)
   Dim FormatWasOn As Boolean
   If Selection.Find.FORMAT = False Then FormatWasOn = False
   Selection.Find.FORMAT = True
   Selection.Find.Text = FindText
   Selection.Find.Replacement.Text = UCase(FindText)
   Selection.Find.Execute Replace:=wdReplaceAll
   If FormatWasOn = False Then Selection.Find.FORMAT = False
   End Sub
Private Sub MoveAbstractToEnd()
   Selection.HomeKey Unit:=wdStory
   With Selection.Find
   .Wrap = wdFindContinue
   .Text = "^13ABSTRACT^13"
   .Execute
   If .Found = True Then
      Selection.MoveStart Unit:=wdCharacter, Count:=1
      Selection.MoveDown Unit:=wdParagraph, Count:=1, Extend:=wdExtend
      Selection.Cut
      Selection.EndKey Unit:=wdStory
      Selection.InsertBreak Type:=wdPageBreak
      Selection.Find.ClearFormatting
      Selection.Find.Replacement.ClearFormatting
      Selection.Paste
      Selection.HomeKey Unit:=wdStory
      .Execute
      .FORMAT = True
      Selection.MoveStart Unit:=wdCharacter, Count:=1
      Selection.collapse Direction:=wdCollapseStart
      Selection.ParagraphFormat.Alignment = wdAlignParagraphCenter
      Selection.HomeKey Unit:=wdStory
      .Wrap = wdFindContinue
      .FORMAT = False
   End If
   End With
   End Sub





