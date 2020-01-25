Attribute VB_Name = "Quotes"
Sub BlockQuote()
   doStart ("Block Quote")
   With Selection.ParagraphFormat
      .Alignment = wdAlignParagraphJustify
      .FirstLineIndent = InchesToPoints(0#)
      .LeftIndent = InchesToPoints(1)
      .RightIndent = InchesToPoints(0.5)
      .SpaceBeforeAuto = False
      .SpaceAfterAuto = False
      .Space1
   End With
   Selection.MoveDown Unit:=wdParagraph, Count:=1
   Selection.MoveLeft Unit:=wdCharacter, Count:=1
   doStop
   End Sub
 Sub BlockClaimQuote()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("BlockClaimQuote()")
   With Selection.ParagraphFormat
      .Alignment = wdAlignParagraphJustify
      .FirstLineIndent = InchesToPoints(0.5)
      .LeftIndent = InchesToPoints(1)
      .RightIndent = InchesToPoints(0.5)
      .SpaceBeforeAuto = False
      .SpaceAfterAuto = False
      .Space1
   End With
   Selection.MoveDown Unit:=wdParagraph, Count:=1
   Selection.MoveLeft Unit:=wdCharacter, Count:=1
   objUndo.EndCustomRecord
   End Sub
Sub RedQuotes()
   Reset_FRS_FC
   Selection.Find.Replacement.Font.color = 192
   With Selection.Find
      .Text = "(" & ChrW(8220) & ")(*)(" & ChrW(8221) & ")"
      .Replacement.Text = ""
      .Forward = True
      .Wrap = wdFindContinue
      .FORMAT = True
      .MatchCase = False
      .MatchWholeWord = False
      .MatchAllWordForms = False
      .MatchSoundsLike = False
      .MatchWildcards = True
   End With
   Selection.Find.Execute Replace:=wdReplaceAll
   Reset_FRS
   End Sub
Sub BracketYQuote()
   doStart ("BracketYQuote")
   If Selection.Type = wdSelectionIP Then
      SelectSentence
   End If
   ChompSelection
   MarkSelection
   Selection.collapse Direction:=wdCollapseStart
   Selection.TypeText Text:="("""
   Reselect
   Selection.collapse Direction:=wdCollapseEnd
   Selection.TypeText Text:=""")"
   doStop
   End Sub
Sub PasteBracketQuote()
   doStart ("PasteBracketQuote")
   PasteYReselect
   ChompSelection
   MarkSelection
   Selection.collapse Direction:=wdCollapseStart
   Selection.TypeText Text:="("""
   Reselect
   Selection.collapse Direction:=wdCollapseEnd
   Selection.TypeText Text:=""")"
   doStop
   End Sub
Sub pasteAsBracketedQuote()
   Selection.TypeText Text:="("""
   Selection.Paste
   Selection.TypeText Text:=""");"
End Sub
 Sub QuotateSelection()
   doStart ("QuotateSelection")
   If Selection.Type = 0 Then
      Selection.TypeText Text:=""""
   Else
      'SelectSentence
      ChompSelection
      Selection.InsertBefore Chr(34)
      Selection.collapse Direction:=wdCollapseEnd
      Selection.InsertAfter Chr(34)
   End If
   doStop
   End Sub
 Sub ReplaceQuotes()
   START_FC ("ReplaceQuotes")
   Application.Options.AutoFormatAsYouTypeReplaceQuotes = False
   Selection.Find.Text = ChrW(8220)
   Selection.Find.Replacement.Text = """"
   Selection.Find.Execute Replace:=wdReplaceAll
   Selection.Find.Text = ChrW(8221)
   Selection.Find.Execute Replace:=wdReplaceAll
   Selection.Find.Text = "‘"
   Selection.Find.Replacement.Text = "'"
   Selection.Find.Execute Replace:=wdReplaceAll
   Selection.Find.Text = "’"
   Selection.Find.Replacement.Text = "'"
   Selection.Find.Execute Replace:=wdReplaceAll
   Application.Options.AutoFormatAsYouTypeReplaceQuotes = True
   Dim oShell As Object
   Dim iResponse As Integer
   Set oShell = CreateObject("Wscript.Shell")
   STOP_FS
   End Sub
