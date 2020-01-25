Attribute VB_Name = "REVIEW"
'ACCEPT CHANGE
Sub AcceptChange()
   Selection.Range.Revisions.AcceptAll
End Sub

'CONVERT TRACK CHANGES
 Sub ConvertTrackChanges()
 
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("Convert Track Changes")
   
   Dim oRange As Range
   Dim rev As Revision
   Dim txt As String
   Dim r As Long
   Dim ran As Range
   Dim TrackChangesCount As Long
    
   If Documents.Count = 0 Then
    Exit Sub
   End If
    
   TrackChangesCount = ActiveDocument.Revisions.Count
    
    'If there are no track changes then notify user and exit sub
   If TrackChangesCount = 0 Then
    MsgBox "There are no track changes in the current document."
    Exit Sub
   End If
    
    'First switch off TrackChanges, else each of your reformattings will become a revision again
   ActiveDocument.TrackRevisions = False
   Application.ScreenUpdating = False
    '***Now cycle through revisions, identify type of change
   For Each rev In ActiveDocument.Revisions
    Select Case rev.Type
    Case wdRevisionDelete
        'secure "deleted" text as well as its position
       txt = rev.Range.Text
       r = rev.Range.Start
        'accept the revision to make the markup disappear
       rev.Accept
        'now type the text formatted as strikethrough at the position of the old text
       Set ran = ActiveDocument.Range(r, r)
       With ran
        .Text = txt
        .Font.StrikeThrough = 1
         '.Font.Color = wdColorRed
         '.Font.Bold = 1
       End With
    Case wdRevisionInsert
       Set ran = rev.Range
        'accept the revision to make the markup disappear
       rev.Accept
        'now type the text formatted as underlined at the position of the old text
       With ran
        .Font.Underline = wdUnderlineSingle
         '.Font.Color = wdColorBlue
         '.Font.Bold = 1
       End With
    End Select
   Next rev
    
   With ActiveDocument
    For Each oRange In .StoryRanges
       oRange.Revisions.AcceptAll
    Next
   End With
   Application.ScreenUpdating = True
   Application.ScreenRefresh
   MsgBox TrackChangesCount & " Track change(s) were converted to regular text."
   
   objUndo.EndCustomRecord
   
End Sub

'CUT/PASTE PARAGRAPH
Sub CutPasteParagraph()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("CutPasteParagraph")
   
   If ActiveDocument.TrackRevisions = False Then
    Call CutPastePara
    ActiveDocument.TrackRevisions = False
   Else
    Call CutPastePara
   End If
   Selection.MoveDown Unit:=wdParagraph, Count:=1
   
   objUndo.EndCustomRecord
End Sub

'CUT/PASTE PARAGRAPH
 Private Sub CutPastePara()
   
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("CutPastePara")
   
   Selection.MoveRight Unit:=wdCharacter, Count:=1
   Selection.MoveUp Unit:=wdParagraph, Count:=1
   Selection.MoveDown Unit:=wdParagraph, Count:=1, Extend:=wdExtend
   Selection.MoveLeft Unit:=wdWord, Count:=1, Extend:=wdExtend
   ActiveDocument.TrackRevisions = False
   Selection.Cut
   ActiveDocument.TrackRevisions = True
   Selection.Paste
   objUndo.EndCustomRecord
End Sub
'REJECT CHANGE
 Sub RejectChange()
   Selection.Range.Revisions.RejectAll
End Sub
'SHOW FINAL
Sub ShowFinal()
   ActiveWindow.View.ShowRevisionsAndComments = False
   ActiveWindow.View.RevisionsView = wdRevisionsViewFinal
End Sub
'SHOW MARKUP
Sub ShowMarkup()
   ActiveWindow.View.ShowRevisionsAndComments = True
   ActiveWindow.View.RevisionsView = wdRevisionsViewFinal
End Sub
'SHOW "ADVANCED TRACK CHANGES OPTIONS" DIALOGUE BOX
 Sub ShowTrackFormatOptions()
   Dialogs(wdDialogToolsOptionsTrackChanges).show
End Sub
'TOGGLE MARKUP
Sub ToggleMarkup()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("ToggleMarkup()")
   If ActiveWindow.View.ShowRevisionsAndComments = True And ActiveWindow.View.RevisionsView = wdRevisionsViewFinal Then
    ShowFinal
'   ElseIf ActiveWindow.View.ShowRevisionsAndComments = False And ActiveWindow.View.RevisionsView = wdRevisionsViewFinal Then
'    ShowNoTrackChanges
   Else
    ShowMarkup
   End If
    objUndo.EndCustomRecord
End Sub
'TOGGLE REVIEW VIEW
Sub ToggleReviewView()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("ToggleReviewView()")
   'ORIGINAL MARKUP --> ALL MARKUP
   If ActiveWindow.View.RevisionsFilter.Markup = wdRevisionsMarkupNone _
    And ActiveWindow.View.RevisionsFilter.View = wdRevisionsViewOriginal Then
    Call timed_message_box("All Markup", "Review View")
    With ActiveWindow.View.RevisionsFilter 'all markup
      .Markup = wdRevisionsMarkupAll
      .View = wdRevisionsViewFinal
    End With
   'ALL MARKUP--> NO MARKUP
   ElseIf ActiveWindow.View.RevisionsFilter.Markup = wdRevisionsMarkupAll _
    And ActiveWindow.View.RevisionsFilter.View = wdRevisionsViewFinal Then
   Call timed_message_box("No Markup", "Review View")
   With ActiveWindow.View.RevisionsFilter 'no markup
      .Markup = wdRevisionsMarkupNone
      .View = wdRevisionsViewFinal
   End With
   'NO MARKUP --> ORIGINAL MARKUP
   ElseIf ActiveWindow.View.RevisionsFilter.Markup = wdRevisionsMarkupNone _
    And ActiveWindow.View.RevisionsFilter.View = wdRevisionsViewFinal Then
    Call timed_message_box("Original Markup", "Review View")
    With ActiveWindow.View.RevisionsFilter 'original
      .Markup = wdRevisionsMarkupNone
      .View = wdRevisionsViewOriginal
    End With
   End If
   objUndo.EndCustomRecord
End Sub
'TOGGLE SHOW_ORIGINAL
Sub ToggleShowOriginal()
   If ActiveWindow.View.RevisionsFilter.Markup = wdRevisionsMarkupNone _
    And ActiveWindow.View.RevisionsFilter.View = wdRevisionsViewOriginal Then
    ActiveWindow.View.RevisionsFilter.Markup = wdRevisionsMarkupAll
    ActiveWindow.View.RevisionsFilter.View = wdRevisionsViewFinal
   Else
    ActiveWindow.View.RevisionsFilter.Markup = wdRevisionsMarkupNone
    ActiveWindow.View.RevisionsFilter.View = wdRevisionsViewOriginal
   End If
End Sub
'UPDATE DOCUMENT FIELDS
Sub update_document_fields()
   Dim myRange
   Set myRange = Selection.Range
   Selection.WholeStory
   Selection.Fields.Update
   myRange.Select
End Sub

