Attribute VB_Name = "FormatDoc_OA"
Sub Format_Office_Action()
   
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("Format_Office_Action()")
   Application.ScreenUpdating = False
   Reset_FRS_FC
   
   ActiveDocument.ConvertNumbersToText
   Selection.WholeStory
   Selection.Font.Size = MY_FONT_SIZE
   Selection.Font.Name = my_font
   Selection.ParagraphFormat.LineSpacingRule = wdLineSpace1pt5
   Selection.ParagraphFormat.TabStops.ClearAll
   Selection.ParagraphFormat.SpaceBefore = 0
   Selection.ParagraphFormat.SpaceAfter = 0
   Selection.ParagraphFormat.LineUnitBefore = 0
   Selection.ParagraphFormat.LineUnitAfter = 0
   Selection.MoveLeft Unit:=wdCharacter, Count:=1
   ActiveWindow.View.Zoom.Percentage = myZoomPref
   ActiveWindow.View.Type = wdWebView
   
   BreaksToPara
   DeleteEmptyParagraphs
   JustifyFromLeft
   
   DeleteOAPageHeaders
   
   Reset_FRS_FC
   With Selection.Find
      
      .Replacement.Font.Bold = True
      .Replacement.ParagraphFormat.SpaceBefore = 12
      .Replacement.ParagraphFormat.SpaceBeforeAuto = False
      .Replacement.ParagraphFormat.SpaceAfter = 12
      .Replacement.ParagraphFormat.SpaceAfterAuto = False
      .Replacement.ParagraphFormat.Alignment = wdAlignParagraphCenter
      .Replacement.ParagraphFormat.LineUnitBefore = 0
      .Replacement.ParagraphFormat.LineUnitAfter = 0
      
      .FORMAT = True
      .MatchWildcards = True
      
      .Text = "Claim Rejections - 35*§*1[0-9][0-9]"
      .Replacement.Text = ""
      .Execute Replace:=wdReplaceAll
      
      .MatchWildcards = False
      .MatchCase = True
       
      .Text = "DETAILED ACTION^13"
      .Replacement.Text = ""
      .Execute Replace:=wdReplaceAll
      
      .Text = "EXAMINER'S AMENDMENT^13"
      .Replacement.Text = ""
      .Execute Replace:=wdReplaceAll
      
      .Replacement.Font.Italic = True
      
      .Text = "Allowable Subject Matter^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Amendments and Arguments^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Applicant-Initiated Interview Summary^13"
      .Execute Replace:=wdReplaceAll
          
      .Text = "Broadest Reasonable Interpretation^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Claim Objections^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Claim Status^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Communications^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Conclusion^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Continued Examination Under 37 CFR 1.114^13"
      .Execute Replace:=wdReplaceAll
          
      .Text = "Correspondence^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Double Patenting^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Drawings^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Election/Restrictions^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Election of Species Requirement^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Election of Species Requirements^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Information Disclosure Statement^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Minor Informalities^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Notice of Pre-AIA or AIA Status^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Notice of Allowability"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Objection to the Claims^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Objection to Drawings^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Objection to the Drawings^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Objection to Specification^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Objection to the Specification^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Preliminary Amendment^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Priority^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Reasons for Allowance^13"
      .Execute Replace:=wdReplaceAll
      
       .Text = "Relevant Prior Art^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Related Application Not Claimed As Priority^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Response to Amendment^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Response to Arguments^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Specification^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Status of the Claims^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Status of the Application^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Withdrawal of the Finality of Last Office Action^13"
      .Execute Replace:=wdReplaceAll
      
      .ClearFormatting
      .Replacement.ClearFormatting
      .MatchWildcards = True
      .Replacement.Font.Bold = True
      
      .Text = "Re Claim*> ([0-9]{1,2})"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Regarding claim*> ([0-9]{1,2})"
      .Execute Replace:=wdReplaceAll
   
      .Text = "Regarding claims ([0-9]{1,2}) and ([0-9]{1,2})"
      .Execute Replace:=wdReplaceAll

      .Text = "Regarding claims ([0-9]{1,2})-([0-9]{1,2})"
      .Execute Replace:=wdReplaceAll

      .Text = "Regarding claims ([0-9]{1,2}) - ([0-9]{1,2})"
      .Execute Replace:=wdReplaceAll
      
      
   
   End With
   
   Reset_FRS_FC
   Selection.Find.ClearFormatting
   Selection.Find.Replacement.ClearFormatting
   Options.DefaultHighlightColorIndex = wdYellow
   Selection.Find.Replacement.Highlight = True
   With Selection.Find
      .Text = "Rejected"
      .Replacement.Text = ""
      .FORMAT = True
      .MatchCase = False
      .Execute Replace:=wdReplaceAll
   End With
   BgRed
   office_action_TOC
   indent_oa_paragraphs
   Selection.collapse Direction:=wdCollapseStart
   Reset_FRS
   Application.ScreenUpdating = True
   objUndo.EndCustomRecord

End Sub


'OFFICE ACTION TOC
 Sub office_action_TOC()
   
   Dim SingleLine As Paragraph
   Dim lineText As String

   Selection.WholeStory
   For Each SingleLine In Selection.PARAGRAPHS
    lineText = SingleLine.Range.Text
    If (InStr(lineText, "Allowable Subject Matter") Or InStr(lineText, "Amendments and Arguments") Or InStr(lineText, "Applicant-Initiated Interview Summary") Or _
       InStr(lineText, "Broadest Reasonable Interpretation") Or _
       InStr(lineText, "Claim Objections") Or _
       InStr(lineText, "Claim Rejections - 35 USC §101") Or InStr(lineText, "Claim Rejections - 35 USC § 101") Or InStr(lineText, "Claim Rejections - 35 USC §102") Or InStr(lineText, "Claim Rejections - 35 USC § 102") Or _
       InStr(lineText, "Claim Rejections - 35 USC §103") Or InStr(lineText, "Claim Rejections - 35 USC § 103") Or InStr(lineText, "Claim Rejections - 35 USC §112") Or InStr(lineText, "Claim Rejections - 35 USC § 112") Or _
       InStr(lineText, "Communications") Or InStr(lineText, "Conclusion") Or InStr(lineText, "Continued Examination Under 37 CFR 1.114") Or InStr(lineText, "Correspondence") Or _
       InStr(lineText, "Double Patenting") Or InStr(lineText, "Drawings") Or _
       InStr(lineText, "Election/Restrictions") Or InStr(lineText, "Election of Species Requirement") Or InStr(lineText, "Election of Species Requirements") Or _
       InStr(lineText, "Information Disclosure Statement") Or _
       InStr(lineText, "Minor Informalities") Or _
       InStr(lineText, "Notice of Allowability") Or _
       InStr(lineText, "Objection to the Claims") Or InStr(lineText, "Objection to Drawings") Or InStr(lineText, "Objection to the Drawings") Or _
       InStr(lineText, "Objection to Specification") Or InStr(lineText, "Objection to the Specification") Or _
       InStr(lineText, "Preliminary Amendment") Or InStr(lineText, "Priority") Or _
       InStr(lineText, "Reasons for Allowance") Or InStr(lineText, "Related Application Not Claimed As Priority") Or InStr(lineText, "Relevant Prior Art") Or _
       InStr(lineText, "Response to Amendment") Or InStr(lineText, "Response to Arguments") Or _
       InStr(lineText, "Specification") Or InStr(lineText, "Status of the Claims") Or InStr(lineText, "Status of the Application") Or _
       InStr(lineText, "Withdrawal of the Finality of Last Office Action")) > 0 _
   Then
       SingleLine.OutlineLevel = wdOutlineLevel1
   End If
   If ((InStr(lineText, "1") = 1 Or _
       InStr(lineText, "2") = 1 Or _
       InStr(lineText, "3") = 1 Or _
       InStr(lineText, "4") = 1 Or _
       InStr(lineText, "5") = 1 Or _
       InStr(lineText, "6") = 1 Or _
       InStr(lineText, "7") = 1 Or _
       InStr(lineText, "8") = 1 Or _
       InStr(lineText, "9") = 1) And _
       ((InStr(lineText, ".") = 2 Or InStr(lineText, ".") = 3))) _
   Then
       SingleLine.OutlineLevel = wdOutlineLevel2
   End If
    lineText = SingleLine.Range.Text
    If (InStr(lineText, "rejected") > 0) Then
       SingleLine.OutlineLevel = wdOutlineLevel2
       SingleLine.Shading.BackgroundPatternColor = -738132122
   End If
   Next SingleLine
   
'  NOT INCLUDED IN TOC
'  InStr(lineText, "Notice of Pre-AIA or AIA Status") Or _

End Sub
'DELETE PAGE HEADERS
Sub DeleteOAPageHeaders()

   Reset_FRS_FC
   
   With Selection.Find
   
      .MatchWildcards = True
      .Replacement.Text = ""
      
      .Text = "Application/Control Number*^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Art Unit: [0-9][0-9][0-9][0-9]^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Page [0-9][0-9]^13"
      .Execute Replace:=wdReplaceAll
      
      .Text = "Page [0-9]^13"
      .Execute Replace:=wdReplaceAll
      
   End With
End Sub
'INDENT OA PARAGRAPHS
Sub indent_oa_paragraphs()

   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("indent_oa_paragraphs()")
   
   Call Reset_FRS_FC
   
   With Selection.Find
    .ParagraphFormat.Alignment = wdAlignParagraphJustify
    .Replacement.ParagraphFormat.FirstLineIndent = InchesToPoints(0.5)
    .Replacement.ParagraphFormat.CharacterUnitFirstLineIndent = 0
    .Text = ""
    .Replacement.Text = ""
    .FORMAT = True
    .Execute Replace:=wdReplaceAll

    .Replacement.ParagraphFormat.FirstLineIndent = InchesToPoints(0)
    .Text = "^#.^t"
    .Replacement.Text = ""
    .Execute Replace:=wdReplaceAll
   End With
   
   Call Reset_FRS_FC
   objUndo.EndCustomRecord

End Sub
