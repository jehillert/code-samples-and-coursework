Attribute VB_Name = "MoveSelectGo"
Sub SelectCopyCut_Sentence()
   Selection.Expand Unit:=wdSentence
   If Selection.Information(wdCapsLock) = False Then
      Selection.Cut
   Else
      ChompSelection
      Selection.Copy
   End If
   End Sub
Sub SelectOrCutSentence()
   Selection.Expand Unit:=wdSentence
   If Selection.Information(wdCapsLock) = False Then
      Selection.Cut
   Else
      ChompSelection
   End If
   End Sub
Sub SelectTableCell()
   Selection.SelectCell
   Selection.Copy
   End Sub
Sub SelectTextBetweenQuotesAtCursor()
   'Chr(39) is a single quote
   'Chr(34) is a double quote
   With Selection
      .collapse
      .StartIsActive = True
      .MoveStartUntil Cset:=Chr(34), Count:=wdBackward
      .StartIsActive = False
      .MoveEndUntil Cset:=Chr(34), Count:=wdForward
   End With
   End Sub
Sub SelectTextBetweenParenthesesAtCursor()
   'Chr(39) is a single quote
   'Chr(34) is a double quote
   With Selection
      .collapse
      .StartIsActive = True
      .MoveStartUntil Cset:=Chr(40), Count:=wdBackward
      .StartIsActive = False
      .MoveEndUntil Cset:=Chr(41), Count:=wdForward
   End With
   End Sub

'SELECT STUFF
Sub PasteYReselect()
  Dim oRng As Word.Range
  Set oRng = Selection.Range
  oRng.Paste
  oRng.Select
End Sub
Sub SelectLine()
   Selection.Expand Unit:=wdLine
   End Sub
Sub SelectSentence()
   Selection.Expand Unit:=wdSentence
   ChompSelection
End Sub
Sub SelectWord()
   If Selection.Type = wdSelectionIP Or (Selection.Words.Count = 1 And Selection.Type <> wdSelectionNormal) Then
      Selection.Words(1).Select
      If Selection.Range.Characters.Count = 1 Then
           Selection.MoveStart Unit:=wdWord, Count:=-1
      End If
      ChompWord
      If Selection.Range.Characters.Count = 1 Then
           Selection.MoveStart Unit:=wdWord, Count:=-1
           ChompWord
      End If
   End If
   End Sub
Sub ChompWord()
   Selection.MoveEndWhile Cset:=(Chr$(10) & Chr$(32) & Chr$(13) & ".,?!"), Count:=-Selection.Characters.Count
End Sub
Sub SelectLeftWord()
   Selection.MoveLeft Unit:=wdWord, Count:=1, Extend:=wdExtend
   Selection.Expand Unit:=wdWord
End Sub
Sub ChompStart()
   If Selection.Range.Characters.Count = 1 Then Exit Sub
   Selection.MoveEndWhile Cset:=(Chr$(32) & Chr$(13)), Count:=-Selection.Characters.Count
End Sub
Sub ChompEnd()
   If Selection.Range.Characters.Count = 1 Then Exit Sub
   Selection.MoveEndWhile Cset:=(Chr$(32) & Chr$(13)), Count:=-Selection.Characters.Count
End Sub
Sub ChompSelection()
   If Selection.Range.Characters.Count = 1 Then Exit Sub
   Selection.MoveStartWhile Cset:=(Chr$(32) & Chr$(13)), Count:=Selection.Characters.Count
   Selection.MoveEndWhile Cset:=(Chr$(32) & Chr$(13)), Count:=-Selection.Characters.Count
End Sub
Function Chomp_Selection(ByRef sel As Selection)
   If sel.Range.Characters.Count = 1 Then Exit Function
   sel.MoveStartWhile Cset:=(Chr$(32) & Chr$(13)), Count:=sel.Characters.Count
   sel.MoveEndWhile Cset:=(Chr$(32) & Chr$(13)), Count:=-sel.Characters.Count
End Function
'MOVE STUFF
Sub MoveToBeginningOfWord()
   Selection.MoveRight Unit:=wdCharacter, Count:=1, Extend:=wdExtend
   If (IsLetter(Selection.Characters(1)) = True _
    Or IsNumeric(Selection.Characters(1)) = True) Then
    Selection.Expand Unit:=wdWord
    ChompSelection
    Selection.MoveLeft Unit:=wdCharacter, Count:=1
   Else
    Selection.MoveLeft Unit:=wdCharacter, Count:=2
    Selection.Expand Unit:=wdWord
    ChompSelection
    Selection.MoveLeft Unit:=wdCharacter, Count:=1
   End If
End Sub
Sub MoveToEndOfWord()
   Selection.MoveRight Unit:=wdCharacter, Count:=1, Extend:=wdExtend
   If (IsLetter(Selection.Characters(1)) = True _
    Or IsNumeric(Selection.Characters(1)) = True) Then
    Selection.Expand Unit:=wdWord
    ChompSelection
    Selection.collapse Direction:=wdCollapseEnd
   Else
    Selection.MoveLeft Unit:=wdCharacter, Count:=1
   End If
End Sub
Sub CopyToEnd()

   doStart ("CopyToEnd")
   
   If Selection.Type = wdSelectionIP Then
      Selection.Expand Unit:=wdParagraph
   End If
   ChompSelection
   MarkSelection
   Selection.Copy
   Selection.MOVE Unit:=wdStory, Count:=1
   
   Selection.TypeParagraph
   Selection.TypeParagraph
   Selection.Paste
   Reselect
   
   doStop
   
End Sub
Sub CopyToTop()

   doStart ("MoveToStart")
   
   If Selection.Type = wdSelectionIP Then
      Selection.Expand Unit:=wdParagraph
   End If
   ChompSelection
   MarkSelection
   Selection.Copy
   Selection.MOVE Unit:=wdStory, Count:=-1
   
   Selection.TypeParagraph
   Selection.TypeParagraph
   Selection.Paste
   Reselect
   
   doStop
   
End Sub
Sub MoveSelectionToStart()

   doStart ("MoveToStart")
   
   MarkSelection
   If Selection.Type = wdSelectionIP Then
      Selection.Expand Unit:=wdParagraph
   End If
   ChompSelection
   Selection.Cut
   Selection.MOVE Unit:=wdStory, Count:=-1
   
   Selection.Paste
   Selection.TypeParagraph
   Selection.TypeParagraph
   Reselect
   
   doStop
   
End Sub
Sub MoveSelectionToEnd()

   doStart ("MoveToEnd")
   
   MarkSelection
   If Selection.Type = wdSelectionIP Then
      Selection.Expand Unit:=wdParagraph
   End If
   ChompSelection
   Selection.Cut
   Selection.MOVE Unit:=wdStory, Count:=1
   
   Selection.TypeParagraph
   Selection.TypeParagraph
   Selection.Paste
   Reselect
   
   doStop
End Sub
