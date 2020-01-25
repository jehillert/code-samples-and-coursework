Attribute VB_Name = "NewMacros"

Sub Macro5()
         Application.ScreenUpdating = True
End Sub
Sub SelectRevisionAtIP()
   Call SetSearchSettings("SelectContiguouslyHighlightedText")
   With Selection
      If (.Type <> wdSelectionIP) Then
            Exit Sub
      Else
         .NextRevision (True)
         .Find.Execute
      End If
   End With
End Sub
Sub Macro2()
Attribute Macro2.VB_ProcData.VB_Invoke_Func = "Normal.NewMacros.Macro2"
'
' Macro2 Macro
'
'
   
End Sub

