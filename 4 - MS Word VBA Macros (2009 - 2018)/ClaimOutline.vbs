Attribute VB_Name = "ClaimOutline"
Function assign_outline_levels_to_claims(my_OL As Integer)
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("assign_outline_level()")
   FormatClaimNumberTab
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
   objUndo.EndCustomRecord
   End Function
Property Get OL_Value(my_OL As Integer) As WdOutlineLevel
   Select Case my_OL
   Case 0
    OL_Value = wdOutlineLevelBodyText
   Case 1
    OL_Value = wdOutlineLevel1
   Case 2
    OL_Value = wdOutlineLevel2
   Case 3
    OL_Value = wdOutlineLevel3
   Case 4
    OL_Value = wdOutlineLevel4
   Case 5
    OL_Value = wdOutlineLevel5
   Case 6
    OL_Value = wdOutlineLevel6
   Case 7
    OL_Value = wdOutlineLevel7
   Case 8
    OL_Value = wdOutlineLevel8
   Case 8
    OL_Value = wdOutlineLevel9
   End Select
   End Property
Sub OutlineClaims(I_Level As Integer, D_Level As Integer)
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("OutlineClaims()")
   Dim SingleLine As Paragraph
   Dim lineText As String
   Selection.Range.ListFormat.ConvertNumbersToText
   assign_outline_levels_to_claims (I_Level)
   For Each SingleLine In Selection.PARAGRAPHS
      lineText = SingleLine.Range.Text
      Call AssignDepClaimOutlineLevel(lineText, SingleLine, D_Level)
   Next SingleLine
   objUndo.EndCustomRecord
   End Sub
Sub AssignClaimsOL1()
   Call assign_outline_levels_to_claims(1)
   End Sub
Sub AssignClaimsOL2()
   Call assign_outline_levels_to_claims(2)
   End Sub
Sub AssignClaimsOL3()
   Call assign_outline_levels_to_claims(3)
   End Sub
Sub outline_claims10()
   Call OutlineClaims(3, 0)
   End Sub
Sub outline_claims20()
   Call OutlineClaims(3, 0)
   End Sub
Sub outline_claims12()
   Call OutlineClaims(1, 2)
   End Sub
Sub outline_claims23()
   Call OutlineClaims(2, 3)
   End Sub
Sub outline_claims34()
   Call OutlineClaims(3, 4)
   End Sub
Sub AssignDepClaimOutlineLevel(CL_String As String, CL_Paragraph As Paragraph, LevelOption As Integer) 'must call FormatClaimNumberTab() first
    If (InStr(CL_String, "(Previously Presented)") _
    Or InStr(CL_String, "." & Chr(9) & "The ") _
    Or InStr(CL_String, "(Allowed) The ") _
    Or InStr(CL_String, "(Cancelled) The ") _
    Or InStr(CL_String, "(Currently Amended) The ") _
    Or InStr(CL_String, "(New) The ") _
    Or InStr(CL_String, "(Original) The ") _
    Or InStr(CL_String, "(Withdrawn) The ") _
    Or InStr(CL_String, "(Withdrawn-Currently Amended) The ") _
    Or InStr(CL_String, "(Withdrawn - Currently Amended) The ")) > 0 Then
       If LevelOption = 0 Then
        CL_Paragraph.OutlineLevel = wdOutlineLevelBodyText
       ElseIf LevelOption = "1" Then
        CL_Paragraph.OutlineLevel = wdOutlineLevel1
       ElseIf LevelOption = 2 Then
        CL_Paragraph.OutlineLevel = wdOutlineLevel2
       ElseIf LevelOption = 3 Then
        CL_Paragraph.OutlineLevel = wdOutlineLevel3
       End If
    End If
   End Sub



