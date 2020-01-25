Attribute VB_Name = "ClaimMacros"
Sub Brackets()
   doStart ("Brackets")
   SelectWord
   Selection.InsertBefore "["
   Selection.MoveRight Unit:=wdCharacter, Count:=1
   Selection.TypeText Text:="]"
   doStop
   End Sub
Sub BracketsToLeft()
   doStart ("BracketsToLeft")
   Selection.TypeText Text:="]"
   Selection.MoveLeft Unit:=wdWord, Count:=1
   Selection.MoveLeft Unit:=wdCharacter, Count:=4
   Selection.TypeText Text:="["
   Selection.MoveRight Unit:=wdWord, Count:=1
   Selection.MoveRight Unit:=wdCharacter, Count:=1
   doStop
   End Sub
Sub BracketsCutPaste()
   doStart ("Brackets")
   Options.PasteAdjustWordSpacing = False
   Selection.MoveLeft Unit:=wdWord, Count:=1, Extend:=wdExtend
   Selection.Cut
   Selection.TypeText Text:="["
   Selection.Paste
   Selection.TypeText Text:="]"
   Options.PasteAdjustWordSpacing = True
   doStop
   End Sub
Sub BracketsDouble()
   doStart ("Brackets")
   Selection.MoveLeft Unit:=wdWord, Count:=1
   Selection.TypeText Text:="[["
   Selection.Expand Unit:=wdWord
   Selection.MoveEndWhile Cset:=(Chr$(32) & Chr$(13)), Count:=-Selection.Characters.Count
   Selection.collapse Direction:=wdCollapseEnd
   Selection.TypeText Text:="]]"
   doStop
   End Sub
Sub DeleteDoubleBrackets()
   Set objUndo = Application.UndoRecord: objUndo.StartCustomRecord ("DeleteDoubleBrackets()"): ActiveDocument.TrackRevisions = "False": Call Reset_FRS
   With Selection.Find
      .MatchWildcards = True: .Text = " \[\[*\]\]": .Replacement.Text = "": .Execute Replace:=wdReplaceAll: .Text = "\[\[*\]\]": .Replacement.Text = "": .Execute Replace:=wdReplaceAll
   End With
   Call Reset_FRS: objUndo.EndCustomRecord
   End Sub
Sub FormatClaimNumberTab()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("FormatClaimNumberTab()")
   Call FindReplaceInSelection_WildcardsOn("(^13)([0-9]{1,2}).([ ^t]{1,5})([(])", "\1\2.^t\4")
   Call FindReplaceInSelection_WildcardsOn("(^13)([0-9]{1,2}).([ ^t]{1,5})(<[(AT][ ATnh])", "\1\2.^t\4")
   Call FindReplaceInSelection_WildcardsOn("([)])([ ^t]{1,5})(<[AT][ nh])", "\1 \3")
   objUndo.EndCustomRecord
   End Sub
Sub IndentClaimBodyParagraphs()
   Call Reset_FRS
   Call FindReplaceInSelection_WildcardsOn("(^13)([ ^t]{1,15})(?)", "\1\3")
   With Selection.Find
      .ClearFormatting
      .Replacement.ClearFormatting
      .FORMAT = True
      .MatchWildcards = True
      .Replacement.ParagraphFormat.RightIndent = InchesToPoints(0)
      .Replacement.ParagraphFormat.LeftIndent = InchesToPoints(0)
      .Replacement.ParagraphFormat.FirstLineIndent = InchesToPoints(0.5)
      .Text = "(^13)[!0-9^13]"
      .Replacement.Text = ""
      .Execute Replace:=wdReplaceAll
      .Text = "(^13)([0-9]{1,2})."
      .Replacement.ParagraphFormat.RightIndent = InchesToPoints(0)
      .Replacement.ParagraphFormat.LeftIndent = InchesToPoints(0)
      .Replacement.ParagraphFormat.FirstLineIndent = InchesToPoints(0)
      .Execute Replace:=wdReplaceAll
      .MatchWildcards = False
      .FORMAT = False
   End With
   Call Reset_FRS
   End Sub
Sub next_claim()
   doStart ("next_claim")
   Reset_FRS
   With Selection.Find
      .Execute FindText:="(^13)([0-9]{1,3})(.)", Forward:=True, MatchWildcards:=True
   End With
   Selection.MoveStart Unit:=wdCharacter, Count:=1
   Selection.collapse Direction:=wdCollapseStart
   Reset_FRS
   doStop
   End Sub
Sub previous_claim()
   doStart ("previous_claim")
   Reset_FRS
   With Selection.Find
      .Execute FindText:="(^13)([0-9]{1,3})(.)", Forward:=False, MatchWildcards:=True
   End With
   Selection.MoveStart Unit:=wdCharacter, Count:=1
   Selection.collapse Direction:=wdCollapseStart
   Reset_FRS
   doStop
   End Sub
Sub userIncrementToFile()
   doStart ("userIncrementToFile")
   Dim FileName As String, fileNo As Integer, MyInput As String

   Title = "Select Increment"
   msg = "Enter +/- increment:"
   MyInput = InputBox(msg, Title, "1")
   
   FileName = "C:\Users\jhillert\Dropbox\Templates\Custom Office Templates\MacroData\fixed_increment.txt"
   fileNo = FreeFile 'Get first free file number
   Open FileName For Output As #fileNo

   Print #fileNo, MyInput
   Close #fileNo
   doStop
   End Sub
Sub ZTerm()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("ZTerm")
   Dim sMyRefNum As String
   Dim sZTerm As String
   Selection.MoveLeft Unit:=wdWord, Count:=1, Extend:=wdExtend
   sMyRefNum = Selection: Selection.Delete
   sZTerm = "z" & sMyRefNum
   Selection.TypeText (sZTerm)
   objUndo.EndCustomRecord
   End Sub

