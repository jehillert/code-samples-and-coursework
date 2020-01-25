Attribute VB_Name = "ClaimFormat"
Private Const my_claim_zoom_percent = myZoomPref
Private Const my_claim_font = "Arial"
Private Const my_claim_font_size = 11

Sub FormatClaims()
   START_FS ("FormatClaims")
   On Error Resume Next
   delete_extra_white_space
   Selection.Range.ListFormat.ConvertNumbersToText
   Selection.Fields.Unlink
   Selection.Range.Font.Bold = False
   Selection.Range.Font.Name = my_claim_font
   Selection.Range.Font.Size = my_claim_font_size
   ActiveDocument.DefaultTabStop = InchesToPoints(0.5)
   ActiveWindow.ActivePane.View.Zoom.Percentage = my_claim_zoom_percent
   With Selection.ParagraphFormat
      .Alignment = wdAlignParagraphJustify
      .CharacterUnitLeftIndent = 0
      .CharacterUnitFirstLineIndent = 0
      .FirstLineIndent = InchesToPoints(0)
      .LeftIndent = InchesToPoints(0)
      .Space15 '.LineSpacing = LinesToPoints(1.15)
      .LineUnitBefore = 0
      .LineUnitAfter = 0
      .OutlineLevel = wdOutlineLevelBodyText
      .SpaceBeforeAuto = False
      .SpaceAfterAuto = False
      .SpaceBefore = 0
      .SpaceAfter = 0
      .TabStops.ClearAll
   End With
   Call find_replace_in_selection("^l", "^13")
   capitalize_claim_statuses
   
   format_claim_number_tab
   delete_empty_paragraphs
   With Selection.Find
      .ClearFormatting
      .Replacement.ClearFormatting
      .Text = ".^p"
      .Replacement.Text = ".^p^p"
      .Execute Replace:=wdReplaceAll
      .Text = "(Cancelled)"
      .Replacement.Text = "(Cancelled)^p"
      .Execute Replace:=wdReplaceAll
   End With
   assign_claims_OL (2)
   indent_after_preamble
   justify_claims
   Selection.collapse Direction:=wdCollapseStart
   STOP_FS
   End Sub
Private Function assign_claims_OL(my_OL As Integer)
   Dim SingleLine As Paragraph
   Dim lineText As String
   For Each SingleLine In Selection.PARAGRAPHS
      lineText = SingleLine.Range.Text
      If (InStr(lineText, "(Previously Presented)") _
         Or InStr(lineText, "(Allowed)") _
         Or InStr(lineText, "(Cancelled)") _
         Or InStr(lineText, "(Currently Amended)") _
         Or InStr(lineText, "(New)") _
         Or InStr(lineText, "(Original)") _
         Or InStr(lineText, "(Withdrawn)") _
         Or InStr(lineText, "(Withdrawn-Currently Amended)") _
         Or InStr(lineText, "(Withdrawn - Currently Amended)") _
         Or InStr(lineText, "." & Chr(9) & "The ") _
         Or InStr(lineText, "." & Chr(9) & "A ") _
         Or InStr(lineText, "." & Chr(9) & "An ")) > 0 Then
            SingleLine.OutlineLevel = OL_Value(my_OL)
      End If
   Next SingleLine
   End Function
Private Sub capitalize_claim_statuses()
   Call find_replace_in_selection("(new)", "(New)")
   Call find_replace_in_selection("(original)", "(Original)")
   Call find_replace_in_selection("(canceled)", "(Cancelled)")
   Call find_replace_in_selection("(withdrawn)", "(Withdrawn)")
   Call find_replace_in_selection("(cancelled)", "(Cancelled)")
   Call find_replace_in_selection("(currently amended)", "(Currently Amended)")
   Call find_replace_in_selection("(previously presented)", "(Previously Presented)")
   Call find_replace_in_selection("(withdrawn-currently amended)", "(Withdrawn - Currently Amended)")
   Call find_replace_in_selection("(withdrawn - currently amended)", "(Withdrawn - Currently Amended)")
   Call find_replace_in_selection("(original)", "(Original)")
   End Sub
Private Sub delete_empty_paragraphs()
   With Selection.Find
      .ClearFormatting
      .Replacement.ClearFormatting
      .Text = "^13^w^13"
      .Replacement.Text = "^p"
      .Execute Replace:=wdReplaceAll
      .MatchWildcards = True
      .Text = "(^13)\1@"
      .Replacement.Text = "^p"
      .Execute Replace:=wdReplaceAll
      .MatchWildcards = False
   End With
   End Sub
  Sub delete_extra_white_space()
   Dim arr_f() As Variant
   Dim arr_r() As Variant
   Dim i As Byte
   arr_f = Array("(^032)\1@(^11)", _
      "(^032)\1@(^13)", "(^032)\1@(^9)", _
      "(^032)\1@(^12)", "(^032)\1@(^14)", _
      "(^9)\1@(^11)", "(^9)\1@(^12)", _
      "(^9)\1@(^13)", "(^9)\1@(^14)")
   arr_r = Array("\2", _
      "\2", "\2", _
      "\2", "\2", _
      "\2", "\2", _
      "\2", "\2")
   For i = LBound(arr_f) To UBound(arr_f)
      With Selection.Find
         .MatchWildcards = True
         .Text = arr_f(i)
         .Replacement.Text = arr_r(i)
         .Execute Replace:=wdReplaceAll
      End With
   Next
   Selection.Find.MatchWildcards = False
   End Sub
Private Sub find_replace_in_selection(FindText As String, ReplaceText As String)
   Selection.Find.ClearFormatting
   Selection.Find.Replacement.ClearFormatting
   Selection.Find.Text = FindText
   Selection.Find.Replacement.Text = ReplaceText
   Selection.Find.Execute Replace:=wdReplaceAll
   Selection.Find.Text = ""
   Selection.Find.Replacement.Text = ""
   End Sub
Private Sub find_replace_in_selection_WildcardsOn(FindText As String, ReplaceText As String)
   With Selection.Find
      .ClearFormatting
      .Replacement.ClearFormatting
      .MatchWildcards = True
      .Text = FindText
      .Replacement.Text = ReplaceText
      .Execute Replace:=wdReplaceAll
      .Text = ""
      .Replacement.Text = ""
      .MatchWildcards = False
   End With
   End Sub
Private Sub format_claim_number_tab()
   Call FindReplaceInSelection_WildcardsOn("([0-9]{1,3}).([^t ])\1@", "\1.^t")
   Call find_replace_in_selection_WildcardsOn("(^13)([0-9]{1,3}).([!0-9A-z(]{1,15})", "^13\2.^t")
   Call FindReplaceInSelection_WildcardsOn("([0-9]{1,3}).([AT ][hn ][e])", "\1.^t\2")
'   Call FindReplaceInSelection_WildcardsOn("(^13)([0-9]{1,3}).(<*>)", "^p\2.^t\3")
   End Sub

Private Sub indent_after_preamble()
   Call find_replace_in_selection_WildcardsOn("(^13)([ ^t]{1,15})(?)", "\1\3")
   With Selection.Find
      .ClearFormatting
      .Replacement.ClearFormatting
      .FORMAT = True
      .MatchWildcards = True
      .Replacement.Text = ""
      .Replacement.ParagraphFormat.RightIndent = InchesToPoints(0)
      .Replacement.ParagraphFormat.LeftIndent = InchesToPoints(0)
      .Replacement.ParagraphFormat.FirstLineIndent = InchesToPoints(0.5)
      .Text = "(^13)[!0-9^13]"
      .Execute Replace:=wdReplaceAll
      .Replacement.ParagraphFormat.RightIndent = InchesToPoints(0)
      .Replacement.ParagraphFormat.LeftIndent = InchesToPoints(0)
      .Replacement.ParagraphFormat.FirstLineIndent = InchesToPoints(0)
      .Text = "(^13)([0-9]{1,2})."
      .Execute Replace:=wdReplaceAll
      .MatchWildcards = False
      .FORMAT = False
      .Text = ""
      .Replacement.Text = ""
   End With
   End Sub
Private Sub justify_claims()
   With Selection.Find
      .ClearFormatting
      .Replacement.ClearFormatting
      .FORMAT = True
      .ParagraphFormat.Alignment = wdAlignParagraphLeft
      .Replacement.ParagraphFormat.Alignment = wdAlignParagraphJustify
      .Text = ""
      .Replacement.Text = ""
      .Execute Replace:=wdReplaceAll
      .FORMAT = False
   End With
   End Sub

