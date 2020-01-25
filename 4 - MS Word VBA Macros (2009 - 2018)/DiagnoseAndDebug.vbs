Attribute VB_Name = "DiagnoseAndDebug"
'   MsgBox "This code ran successfully in " & SecondsElapsed & " seconds", vbInformation

Sub sayMyName()
   Dim pathName As String
   Dim o As Document
   Set o = ActiveDocument
   If InStrRev(o.Name, ".") <> 0 Then
      MsgBox Left(o.Name, InStrRev(o.Name, ".") - 1)
   Else
      MsgBox o.Name
   End If
End Sub

Sub SaySelectionType()
   If Selection.Type = 0 Then
    MsgBox "Selection Type:   wdNoSelection"
   ElseIf Selection.Type = 6 Then
    MsgBox "Selection Type:   wdSelectionBlock"
   ElseIf Selection.Type = 4 Then
    MsgBox "Selection Type:   wdSelectionColumn"
   ElseIf Selection.Type = 3 Then
    MsgBox "Selection Type:   wdSelectionFrame"
   ElseIf Selection.Type = 7 Then
    MsgBox "Selection Type:   wdSelectionInlineShape"
   ElseIf Selection.Type = 1 Then
    MsgBox "Selection Type:   wdSelectionIP"
   ElseIf Selection.Type = 2 Then
    MsgBox "Selection Type:   wdSelectionNormal"
   ElseIf Selection.Type = 5 Then
    MsgBox "Selection Type:   wdSelectionRow"
   ElseIf Selection.Type = 8 Then
    MsgBox "Selection Type:   wdSelectionShape"
   End If
End Sub

Sub SaySelectionAndStoryType()

   SaySelectionType
   
   If Selection.StoryType = wdCommentsStory Then
    MsgBox "Selection.StoryType = 'wdCommentsStory'"
   ElseIf Selection.StoryType = wdEndnoteContinuationNoticeStory Then
    MsgBox "Selection.StoryType = 'wdEndnoteContinuationNoticeStory'"
   ElseIf Selection.StoryType = wdEndnoteContinuationSeparatorStory Then
    MsgBox "Selection.StoryType = 'wdEndnoteContinuationSeparatorStory'"
   ElseIf Selection.StoryType = wdEndnoteSeparatorStory Then
    MsgBox "Selection.StoryType = 'wdEndnoteSeparatorStory'"
   ElseIf Selection.StoryType = wdEndnotesStory Then
    MsgBox "Selection.StoryType = 'wdEndnotesStory'"
   ElseIf Selection.StoryType = wdEvenPagesFooterStory Then
    MsgBox "Selection.StoryType = 'wdEvenPagesFooterStory'"
   ElseIf Selection.StoryType = wdEvenPagesHeaderStory Then
    MsgBox "Selection.StoryType = 'wdEvenPagesHeaderStory'"
   ElseIf Selection.StoryType = wdFirstPageFooterStory Then
    MsgBox "Selection.StoryType = 'wdFirstPageFooterStory'"
   ElseIf Selection.StoryType = wdFirstPageHeaderStory Then
    MsgBox "Selection.StoryType = 'wdFirstPageHeaderStory'"
   ElseIf Selection.StoryType = wdFootnoteContinuationNoticeStory Then
    MsgBox "Selection.StoryType = 'wdFootnoteContinuationNoticeStory'"
   ElseIf Selection.StoryType = wdFootnoteContinuationSeparatorStory Then
    MsgBox "Selection.StoryType = 'wdFootnoteContinuationSeparatorStory'"
   ElseIf Selection.StoryType = wdFootnoteSeparatorStory Then
    MsgBox "Selection.StoryType = 'wdFootnoteSeparatorStory'"
   ElseIf Selection.StoryType = wdFootnotesStory Then
    MsgBox "Selection.StoryType = 'wdFootnotesStory'"
   ElseIf Selection.StoryType = wdMainTextStory Then
    MsgBox "Selection.StoryType = 'wdMainTextStory'"
   ElseIf Selection.StoryType = wdPrimaryFooterStory Then
    MsgBox "Selection.StoryType = 'wdPrimaryFooterStory'"
   ElseIf Selection.StoryType = wdPrimaryHeaderStory Then
    MsgBox "Selection.StoryType = 'wdPrimaryHeaderStory'"
   ElseIf Selection.StoryType = wdTextFrameStory Then
    MsgBox "Selection.StoryType = 'wdTextFrameStory'"
   End If
   
   If Selection.Information(wdWithInTable) Then
    MsgBox "Selection is in a table."
   Else
    MsgBox "Selection is not in a table."
   End If
   
End Sub
'VIEW STATE DIAGNOSTICS
Sub testCaptureResetViewStateMacros()

   captureViewState
   sayViewStateParameters
   
   ActiveDocument.Windows(1).View = wdNormalView
   ActiveDocument.ActiveWindow.View.Zoom.Percentage = 300
   Application.CommandBars("Navigation").Position = msoBarLeft
   Application.CommandBars("Navigation").Width = 500
   ActiveWindow.DocumentMap = True
    
   sayViewStateParameters
'   resetViewState
   sayViewStateParameters
    
End Sub
Sub sayViewStateParameters()
   MsgBox "OLD VIEW STATE" & vbNewLine & vbTab & _
    "Document View: " & oldViewType & vbNewLine & vbTab & _
    "NavPane Position: " & oldNavPanePosition & vbNewLine & vbTab & _
    "NavPaneWidth: " & oldNavPaneWidth & vbNewLine & vbTab & _
    "Zoom Percentage: " & oldZoomPercentage & "%" & vbNewLine & vbTab & _
    "DocumentMap State: " & oldNavPaneState
    
   MsgBox "CURRENT VIEW STATE" & vbNewLine & vbTab & _
    "Document View: " & ActiveDocument.Windows(1).View.Type & vbNewLine & vbTab & _
    "NavPane Position: " & Application.CommandBars("Navigation").Position & vbNewLine & vbTab & _
    "NavPaneWidth: " & Application.CommandBars("Navigation").Width & vbNewLine & vbTab & _
    "Zoom Percentage: " & ActiveDocument.ActiveWindow.View.Zoom.Percentage & "%" & vbNewLine & vbTab & _
    "DocumentMap State: " & ActiveWindow.DocumentMap
End Sub
'MACRO PERFORMANCE
Sub CalculateRunTime_Minutes()
'PURPOSE: Determine how many minutes it took for code to completely run
'SOURCE: www.TheSpreadsheetGuru.com/the-code-vault

Dim StartTime As Double
Dim MinutesElapsed As String

'Remember time when macro starts
  StartTime = Timer

'*****************************
'Insert Your Code Here...
'*****************************

'Determine how many seconds code took to run
  MinutesElapsed = FORMAT((Timer - StartTime) / 86400, "hh:mm:ss")

'Notify user in seconds
  MsgBox "This code ran successfully in " & MinutesElapsed & " minutes", vbInformation

End Sub

Sub CalculateRunTime_Seconds()
'PURPOSE: Determine how many seconds it took for code to completely run
'SOURCE: www.TheSpreadsheetGuru.com/the-code-vault

Dim StartTime As Double
Dim SecondsElapsed As Double

'Remember time when macro starts
  StartTime = Timer

'*****************************
'Insert Your Code Here...
'*****************************

'Determine how many seconds code took to run
  SecondsElapsed = Round(Timer - StartTime, 2)

'Notify user in seconds
  MsgBox "This code ran successfully in " & SecondsElapsed & " seconds", vbInformation

End Sub
