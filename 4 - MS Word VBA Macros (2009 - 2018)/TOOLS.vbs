Attribute VB_Name = "TOOLS"
Private GlobalExpandCollapseState As Boolean

Sub CopyTextAndFormatting()
   Selection.Copy
   Selection.CopyFormat
   End Sub
Sub InsertBlankTextField()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("InsertBlankTextField()")
   Selection.FormFields.Add Range:=Selection.Range, Type:= _
    wdFieldFormTextInput
   objUndo.EndCustomRecord
   End Sub
 Sub InsertEditTextField()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("InsertEditTextField()")
   sPrompt = "Please enter text for Legacy Text Field."
   sTitle = "DATA ENTRY - LEGACY TEXT FIELD"
   sDefault = ""
   sMyString = InputBox(sPrompt, sTitle, sDefault)
   Selection.FormFields.Add Range:=Selection.Range, Type:=wdFieldFormTextInput
   Selection.TypeBackspace
   With Selection.FormFields(1)
    .Name = "LegTxtFld"
    .EntryMacro = ""
    .ExitMacro = ""
    .Enabled = True
    .OwnHelp = False
    .HelpText = ""
    .OwnStatus = False
    .StatusText = ""
    With .TextInput
      .EditType Type:=wdRegularText, Default:=sMyString, FORMAT:=""
      .Width = 10
    End With
   End With
   Selection.MoveRight Unit:=wdCharacter, Count:=Len(sMyString)
   objUndo.EndCustomRecord
   End Sub
Sub RemoveSectionBreaks()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("RemoveSectionBreaks()")
   Dim rg As Range
   Set rg = ActiveDocument.Range
   With rg.Find
    .Text = "^b" ' section break
    .Wrap = wdFindStop
    While .Execute
       rg.Delete
    Wend
   End With
   objUndo.EndCustomRecord
   End Sub
Sub timed_message_box(input_box_msg As String, title_bar_msg As String)
   Dim AckTime As Integer, InfoBox As Object
   Set InfoBox = CreateObject("WScript.Shell")
   AckTime = 1
   Select Case InfoBox.Popup(input_box_msg, _
   AckTime, title_bar_msg, 0)
   Case 1, -1
   Exit Sub
   End Select
   End Sub
Sub ToggleCollapseByDefaultToggle()
   Selection.PARAGRAPHS(1).Range.ParagraphFormat.CollapsedByDefault = Not Selection.PARAGRAPHS(1).Range.ParagraphFormat.CollapsedByDefault
   End Sub
Sub ToggleExpandCollapse()
   Selection.PARAGRAPHS(1).CollapsedState = Not Selection.PARAGRAPHS(1).CollapsedState
   End Sub
Sub ToggleNavPane()
   ActiveWindow.DocumentMap = Not ActiveWindow.DocumentMap
   End Sub
Sub ToggleExpandCollapseAllHeadings()
   If GlobalExpandCollapseState = True Then
      ActiveDocument.ActiveWindow.View.ExpandAllHeadings
   Else
      ActiveDocument.ActiveWindow.View.CollapseAllHeadings
   End If
   GlobalExpandCollapseState = Not GlobalExpandCollapseState
End Sub
