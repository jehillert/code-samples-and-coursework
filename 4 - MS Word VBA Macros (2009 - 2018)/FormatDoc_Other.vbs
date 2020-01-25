Attribute VB_Name = "FormatDoc_Other"
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
 Sub FormatIDF()
   
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("Format IDF")

   'UNLINK FIELDS
   ActiveDocument.Fields.Unlink
   ActiveDocument.ConvertNumbersToText
   
   'REMOVE BORDERS
   Selection.WholeStory
   Selection.Borders(wdBorderTop).LineStyle = wdLineStyleNone
   Selection.Borders(wdBorderLeft).LineStyle = wdLineStyleNone
   Selection.Borders(wdBorderBottom).LineStyle = wdLineStyleNone
   Selection.Borders(wdBorderRight).LineStyle = wdLineStyleNone
   Selection.Borders(wdBorderHorizontal).LineStyle = wdLineStyleNone
    
   'ADD FOUR P-MARKS AT END OF DOC
   Selection.EndKey Unit:=wdStory
   Selection.TypeParagraph
   Selection.TypeParagraph
   Selection.TypeParagraph
   Selection.TypeParagraph
   Selection.HomeKey Unit:=wdStory
   
   'PARAMETERS
   With Selection.Find
   .ClearFormatting
   .Replacement.ClearFormatting
   .Forward = True
   .Wrap = wdFindContinue
   .MatchCase = False
   .MatchWholeWord = False
   .MatchWildcards = False
   .MatchSoundsLike = False
   .MatchAllWordForms = False
   .MatchWildcards = True
   
   'JUSTIFY
   .ParagraphFormat.Alignment = wdAlignParagraphLeft
   .Replacement.ParagraphFormat.Alignment = wdAlignParagraphJustify
   .Text = ""
   .Replacement.Text = ""
   .FORMAT = True
   .Execute Replace:=wdReplaceAll

   'DELETE 'PURPOSE' BLOCK
   .FORMAT = False
   .Text = "PURPOSE*.com\).^13^13"
   .Replacement.Text = ""
   .Execute Replace:=wdReplaceAll
   
   'DELETE 'INSTRUCTIONS' BLOCK
   .Text = "INSTRUCTIONS*^13^13"
   .Replacement.Text = ""
   .Execute Replace:=wdReplaceAll
   
   '3. INVENTORS
   .FORMAT = True
   .Replacement.Font.Bold = True
   .Replacement.Font.Underline = wdUnderlineNone
   .Text = "(3.^tInventors)*(^13)"
   .Replacement.Text = "\1:\2"
   .Execute Replace:=wdReplaceAll
   
   .Text = "\(Please note: A patent can be invalidated*^13"
   .Replacement.Text = ""
   .FORMAT = False
   .Execute Replace:=wdReplaceAll
   
   '5. PROBLEMS ADDRESSED BY THE INVENTION
   .Text = "(5.^tProblems Addressed by Invention.)*(^13)"
   .Execute Replace:=wdReplaceAll
   
   '6. CONCISE DESCRIPTION OF THE INVENTION
   .Text = "(6.^tConcise Description of the Invention.)*(^13)"
   .Replacement.Text = "\1\2"
   .Execute Replace:=wdReplaceAll
   
   '7. PRIOR ART
   .Text = "(7.^tPrior Art.)*(^13)"
   .Execute Replace:=wdReplaceAll

   '8. POINTS OF NOVELTY
   .Text = "(8.^tPoints of Novelty.)*(^13)"
   .Execute Replace:=wdReplaceAll
   
   '9. COMMERCIAL ADVANTAGE
   .Text = "(9.^tCommercial Advantage.)*(^13)"
   .Execute Replace:=wdReplaceAll
   
   '10. PROTECTION STRATEGY
   .Text = "(Please provide reasons why you think a patent )*(^13)"
   .Replacement.Text = ""
   .Execute Replace:=wdReplaceAll
   .Text = "(Please also comment on whether you think it would )*^13^13"
   .Execute Replace:=wdReplaceAll
   .Text = "Are there likely to be viable workarounds or other means*^13^13"
   .Execute Replace:=wdReplaceAll
   
   '11. DATES OF DOCUMENTATION AND DISCLOSURES.
   .Text = "Has the invention been disclosed or demonstrated*^13"
   .Execute Replace:=wdReplaceAll
   .Text = "Has the invention or a product incorporating the *^13^13"
   .Execute Replace:=wdReplaceAll
   .Text = "Has the invention been constructed*^13^13"
   .Execute Replace:=wdReplaceAll
   .Text = "Is the invention described in internal documents*^13^13"
   .Execute Replace:=wdReplaceAll

   '12. VENDORS AND CUSTOMERS.
   .Text = "(12.^tVendors and Customers.)*(^13)"
   .Execute Replace:=wdReplaceAll
   
   'DELETE SIGNATURE BLOCK
   .Text = "SIGNATURES OF INVENTORS AND WITNESSES*^13^13^13^13"
   .Replacement.Text = ""
   .Execute Replace:=wdReplaceAll

   .MatchWildcards = False
   End With

   'SWITCH TO WEBVIEW
   ActiveWindow.View.Type = wdWebView
   
   BgViolet
   Call Reset_FRS_FC
   objUndo.EndCustomRecord
  
   End Sub

 Sub FormatMachineTransDoc()

   START_FC ("FormatMachineTransDoc")

   Call RemoveHeadAndFoot_JPatPlat
   With Selection.Find
   
      'delete unbracketed headings
      .Text = "^pclaims^p"
      .Replacement.Text = "^p"
      .Execute Replace:=wdReplaceAll
      .Text = "^pdetailed description^p"
      .Execute Replace:=wdReplaceAll
      .Text = "^pdescription of drawings^p"
      .Execute Replace:=wdReplaceAll
      
      'miscellaneous headings
      .Replacement.Font.Bold = True
      .FORMAT = True
      
      .Text = "Abstract"
      .Replacement.Text = "ABSTRACT"
      .Execute Replace:=wdReplaceAll
      
      .Text = "[Detailed Description of the Invention]"
      .Replacement.Text = "DETAILED DESCRIPTION OF THE INVENTION"
      .Execute Replace:=wdReplaceAll
   
      .Text = "[Brief Description of the Drawings]"
      .Replacement.Text = "BRIEF DESCRIPTION OF THE DRAWINGS"
      .Execute Replace:=wdReplaceAll
      
      .Text = "[Explanations of letters or numerals]"
      .Replacement.Text = "EXPLANATIONS OF LETTERS OR NUMERALS"
      .Execute Replace:=wdReplaceAll
      
      .FORMAT = False
   
      'eliminate space before paragraph breaks
      .Text = "^w^p"
      .Replacement.Text = "^p"
      .Execute Replace:=wdReplaceAll
      
      'remove spaces between paragraphs
      .Text = "(^13)\1@"
      .Replacement.Text = "^p"
      .MatchWildcards = True
   
      'swap headers with preceding paragraph numbers
      .Text = "(\[[0-9]{3,4}\])([!A-Z]@)\[(<*>)\]"
      .Replacement.Text = "\3^p\1"
      .Execute Replace:=wdReplaceAll
      
      'format [DRAWING #]
      .Replacement.ClearFormatting
      .Replacement.ParagraphFormat.TabStops.Add Position:= _
         InchesToPoints(1.5), Alignment:=wdAlignTabLeft, Leader:= _
         wdTabLeaderSpaces
      .Text = "(\[Drawing [0-9]@\])*(<*>)"
      .Replacement.Text = "\1   \2"
      .FORMAT = True
      .Execute Replace:=wdReplaceAll
      
      'format [CLAIM #]
      .Replacement.ClearFormatting
      .Replacement.ParagraphFormat.TabStops.Add Position:= _
         InchesToPoints(1), Alignment:=wdAlignTabLeft, Leader:= _
         wdTabLeaderSpaces
      .Text = "(\[Claim [0-9]@\])*(<*>)"
      .Replacement.Text = "\1^t\2"
      .Execute Replace:=wdReplaceAll
      
      'format [PATENT DOCUMENT #]
      .Replacement.ClearFormatting
      .Replacement.ParagraphFormat.TabStops.Add Position:= _
         InchesToPoints(1.75), Alignment:=wdAlignTabLeft, Leader:= _
         wdTabLeaderSpaces
      .Text = "(\[Patent Document [0-9]@\])*(<*>)"
      .Replacement.Text = "\1^t\2"
      .Execute Replace:=wdReplaceAll
          
      'format [WORKING EXAMPLE #]
      .Replacement.ClearFormatting
      .Text = "(\[Working Example [0-9]@\])*(<*>)"
      .Replacement.Text = "\1^t\2"
      .Execute Replace:=wdReplaceAll
      
      'format [0001]
      .Replacement.ClearFormatting
      .Replacement.ParagraphFormat.TabStops.Add Position:= _
         InchesToPoints(0.75), Alignment:=wdAlignTabLeft, Leader:= _
         wdTabLeaderSpaces
      .Text = "(\[[0-9][0-9][0-9][0-9]\])*(<*>)"
      .Replacement.Text = "\1^t\2"
      .Execute Replace:=wdReplaceAll
      
      .FORMAT = False
      .MatchWildcards = False
      
   End With
   FormatWholeStory_JPatPlat
   Selection.HomeKey Unit:=wdStory
   DeleteEmptyParagraphs
   insert_blank_paragraphs
   ActiveWindow.View.Zoom.Percentage = myZoomPref
   ActiveWindow.View.Type = wdWebView
   BgViolet
   STOP_FS
   End Sub
   
Private Sub FormatWholeStory_JPatPlat()

   ActiveDocument.ConvertNumbersToText
   
   Selection.WholeStory
   Selection.Fields.Unlink
   Selection.Font.Size = MY_FONT_SIZE
   Selection.Font.Name = my_font
   Selection.Font.Bold = False
   Selection.ParagraphFormat.Space1
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
   ActiveDocument.DefaultTabStop = InchesToPoints(0.5)

   DeleteTrailingMixedWhiteSpace
   
   Call FindReplaceText("^11", "^13")
   Call FindReplaceText("^b", "^13")
   Call FindReplaceText("^l", "^13")
   Call FindReplaceText("^m", "^13")
   Call FindReplaceText("^n", "^13")

   JustifyFromLeft
   
   Call Reset_FRS
   
   End Sub
Private Sub RemoveHeadAndFoot_JPatPlat()
   Reset_FRS_FC
   Dim oSec As Section
   Dim oHead As HeaderFooter
   Dim oFoot As HeaderFooter
   For Each oSec In ActiveDocument.Sections
      For Each oHead In oSec.Headers
         If oHead.Exists Then oHead.Range.Delete
      Next oHead
      For Each oFoot In oSec.Footers
         If oFoot.Exists Then oFoot.Range.Delete
      Next oFoot
   Next oSec
   Reset_FRS_FC
   End Sub
   
Sub FormatComments()
   START_FC ("FormatComments")
   Dim SingleLine As Paragraph
   Dim lineText As String
   ActiveDocument.ConvertNumbersToText
   Selection.WholeStory
   Selection.Font.Size = MY_FONT_SIZE
   Selection.Font.Name = my_font
   Selection.Font.Bold = False
   Selection.ParagraphFormat.LineSpacingRule = wdLineSpaceSingle
   Selection.ParagraphFormat.TabStops.ClearAll
   ActiveDocument.DefaultTabStop = InchesToPoints(0)
   ActiveWindow.View.Zoom.Percentage = myZoomPref
   ActiveWindow.View.Type = wdWebView
   DeleteTrailingMixedWhiteSpace
   BreaksToPara
   JustifyFromLeft
   DeleteEmptyParagraphs
   For Each SingleLine In Selection.PARAGRAPHS
      lineText = SingleLine.Range.Text
      SingleLine.OutlineLevel = wdOutlineLevel2
   Next SingleLine
   insert_blank_paragraphs
   Selection.Find.ParagraphFormat.Alignment = wdAlignParagraphJustify
   Selection.Find.Replacement.ParagraphFormat.SpaceAfter = 0
   Selection.Find.Replacement.ParagraphFormat.LineUnitAfter = 0
   Selection.Find.Text = ""
   Selection.Find.Replacement.Text = ""
   Selection.Find.Execute Replace:=wdReplaceAll
   Selection.Range.ListFormat.ConvertNumbersToText
   Selection.HomeKey Unit:=wdStory
   BgViolet
   STOP_FS
   End Sub
'GPATPATCLEANER
'https://patents.google.com
Sub GPatCleaner()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("DeleteFromGP()")
   
   Selection.HomeKey Unit:=wdStory
   Selection.WholeStory
   Selection.Font.Size = MY_FONT_SIZE
   Selection.Font.Name = my_font
   ActiveDocument.DefaultTabStop = InchesToPoints(0.25)
   Selection.MoveLeft Unit:=wdCharacter, Count:=1
   ActiveWindow.View.Zoom.Percentage = myZoomPref
   ActiveWindow.View.Type = wdWebView
   
   DeleteTrailingMixedWhiteSpace
   BreaksToPara
   JustifyFromLeft
   Reset_FRS_FC

   'DELETE END CITATIONS FIRST
   With Selection.Find
    .Wrap = wdFindContinue
    .MatchWildcards = True
    .Text = "^13Patent Citations \([0-9]{1,3}\)^13"
    .Replacement.Text = ""
    .Execute
   End With
   Selection.EndKey Unit:=wdStory, Extend:=wdExtend
   Selection.Delete Unit:=wdCharacter, Count:=1
   Selection.TypeParagraph
   
   Selection.HomeKey Unit:=wdStory
   
   'THEN MOVE ABSTRACT TO THE BOTTOM
   Selection.Find.ClearFormatting
   With Selection.Find
    .Text = "^13Abstract^13*Images \([0-9]{1,3}\)^13"
    .Replacement.Text = ""
    .Execute
   End With
   Selection.MoveLeft Unit:=wdWord, Count:=3, Extend:=wdExtend
   Selection.Cut
   Selection.EndKey Unit:=wdStory
   Selection.InsertBreak Type:=wdPageBreak
   Selection.PasteAndFormat (wdFormatOriginalFormatting)

   Selection.HomeKey Unit:=wdStory
   
   With Selection.Find
    .Text = "^13Images*AssignmentEspacenetDiscuss^13Description"
    .Replacement.Text = ""
    .Execute Replace:=wdReplaceOne
   End With
   Selection.HomeKey Unit:=wdStory
   With Selection.Find
    .MatchWildcards = False
    .Text = "^13^wPatents^13"
    .Replacement.Text = ""
    .Execute Replace:=wdReplaceOne
   End With
   Selection.HomeKey Unit:=wdStory
   
   'FORMAT [0001]
   With Selection.Find
    Reset_FRS_FC
    .Replacement.ParagraphFormat.TabStops.Add Position:= _
    InchesToPoints(0.75), Alignment:=wdAlignTabLeft, Leader:= _
       wdTabLeaderSpaces
    .Text = "(\[[0-9][0-9][0-9][0-9]\])*(<*>)"
    .Replacement.Text = "\1^t\2"
    .MatchWildcards = True
    .FORMAT = True
    .Execute Replace:=wdReplaceAll
   End With
   
   Reset_FRS_FC
   objUndo.EndCustomRecord
End Sub
