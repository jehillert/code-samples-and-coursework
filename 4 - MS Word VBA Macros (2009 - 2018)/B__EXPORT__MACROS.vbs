Attribute VB_Name = "B__EXPORT__MACROS"
Sub ExportMacros()
   Dim strPath As String
   Dim vbc As Object
   With Application.FileDialog(msoFileDialogFolderPicker)
      If .show Then
         strPath = .SelectedItems(1)
         If Right(strPath, 1) <> "\" Then
            strPath = strPath & "\"
         End If
         For Each vbc In ActiveDocument.AttachedTemplate.VBProject.VBComponents
            vbc.Export strPath & vbc.Name & ".vbs"
         Next vbc
      Else
         MsgBox "No folder specified...", vbExclamation
      End If
   End With
End Sub

