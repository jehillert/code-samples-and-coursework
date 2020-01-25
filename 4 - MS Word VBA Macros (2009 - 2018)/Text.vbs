Attribute VB_Name = "Text"
Function ChangeTextColor(wdColor)
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("ChangeTextColor()")
   InitialScreenUpdatingState = Application.ScreenUpdating
   InitialTrackChangesState = ActiveDocument.TrackRevisions
   Application.ScreenUpdating = False
   ActiveDocument.TrackRevisions = True
   If ActiveDocument.TrackRevisions = True Then markup_state = True
   ActiveDocument.TrackRevisions = False
   If Selection.Type = wdSelectionIP Then
    SelectSentence
   End If
   Selection.Font.color = wdColor
   Selection.collapse Direction:=wdCollapseEnd
   If markup_state = True Then ActiveDocument.TrackRevisions = True
   Application.ScreenUpdating = InitialScreenUpdatingState
   ActiveDocument.TrackRevisions = InitialTrackChangesState
   objUndo.EndCustomRecord
   End Function
Function ChangeTextAndShadeColor(wdColor, TargetShade)
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("ChangeTextColor()")
   InitialScreenUpdatingState = Application.ScreenUpdating
   InitialTrackChangesState = ActiveDocument.TrackRevisions
   Application.ScreenUpdating = False
   ActiveDocument.TrackRevisions = True
   If Selection.Type = wdSelectionIP Then
      SelectSentence
   End If
   Selection.Font.color = wdColor
   Selection.Shading.BackgroundPatternColor = TargetShade
   Selection.collapse Direction:=wdCollapseEnd
   Application.ScreenUpdating = InitialScreenUpdatingState
   ActiveDocument.TrackRevisions = InitialTrackChangesState
   objUndo.EndCustomRecord
   End Function
Function IsLetter(strValue As String) As Boolean
   Dim intPos As Integer
   For intPos = 1 To Len(strValue)
    Select Case Asc(Mid(strValue, intPos, 1))
       Case 65 To 90, 97 To 122
        IsLetter = True
       Case Else
        IsLetter = False
        Exit For
    End Select
   Next
   End Function
Sub TextAuto()
   ChangeTextColor (wdColorAutomatic)
   End Sub
Sub BlackText()
   ChangeTextColor (wdColorBlack)
   End Sub
Sub GreenText()
   ChangeTextColor (3437568)
   End Sub
Sub BlueText()
   'ChangeTextColor (wdColorBlue)
   ChangeTextColor (16605699)
   'ChangeTextColor (15632384)
   End Sub
Sub OrangeText()
   ChangeTextColor (wdColorOrange)
   End Sub
Sub PurpleText()
   ChangeTextColor (10498160)
   End Sub
Sub RedText()
   'ChangeTextColor (192)
   ChangeTextColor (142)
   End Sub
Sub JEHComment()
   doStart ("JEHComment")
   If Selection.Type = wdSelectionIP Then
      SelectSentence
   End If
   ChompSelection
   Selection.Font.color = wdColorWhite
   Selection.Shading.BackgroundPatternColor = 15557041
   doStop
   End Sub
