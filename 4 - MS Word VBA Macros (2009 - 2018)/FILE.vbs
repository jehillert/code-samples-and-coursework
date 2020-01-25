Attribute VB_Name = "FILE"
Option Explicit
Sub InsertTextFromFile()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("InsertTextFromFile()")
   strFolderpath = SelectedFile()
   Selection.InsertFile FileName:=strFolderpath, Range:="", _
      ConfirmConversions:=False, Link:=False, Attachment:=False
   objUndo.EndCustomRecord
   End Sub
' RETURN SelectedFile()
Function SelectedFile() As String
   Dim fDialog As FileDialog, result As Integer
   Set fDialog = Application.FileDialog(msoFileDialogFilePicker)
   'Optional: FileDialog properties
   fDialog.AllowMultiSelect = False
   fDialog.Title = "Select a file"
   fDialog.InitialFileName = "C:\"
   'Optional: Add filters
   fDialog.Filters.Clear
   '   fDialog.Filters.Add "Excel files", "*.xlsx"
   '   fDialog.Filters.Add "All files", "*.*"
   'Show the dialog. -1 means success!
   If fDialog.show = -1 Then
      Debug.Print fDialog.SelectedItems(1)
   End If
   SelectedFile = fDialog.SelectedItems(1)
   End Function
Function SaveAs_OpensToNewDefaultDir(ByVal new_default_save_as_dir As String, my_save_type)
   With Dialogs(wdDialogFileSaveAs)
      .FORMAT = my_save_type
      .Name = new_default_save_as_dir
      .show
   End With
   End Function
Sub PrintStuff()
   Application.PrintOut FileName:="", Range:=wdPrintAllDocument, Item:= _
      wdPrintDocumentWithMarkup, Copies:=1, pages:="", PageType:= _
      wdPrintAllPages, Collate:=True, Background:=True, PrintToFile:=False, _
      PrintZoomColumn:=0, PrintZoomRow:=0, PrintZoomPaperWidth:=0, _
      PrintZoomPaperHeight:=0
   End Sub
Sub SaveAllCloseAll()
   Application.Quit SaveChanges:=wdSaveChanges, OriginalFormat:=wdWordDocument
   End Sub
Sub SaveAsDOCX()
   ActiveDocument.SaveAs2 FileName:=Replace(ActiveDocument.FullName, ".doc", ".docx"), _
      FileFormat:=wdFormatXMLDocument, LockComments:=False, Password:="", AddToRecentFiles:= _
      True, WritePassword:="", ReadOnlyRecommended:=False, EmbedTrueTypeFonts:= _
      False, SaveNativePictureFormat:=False, SaveFormsData:=False, _
      SaveAsAOCELetter:=False, CompatibilityMode:=15
   End Sub
Function thisFileName() As String
   Dim pathName As String
   Dim o As Document
   Set o = ActiveDocument
   If InStrRev(o.Name, ".") <> 0 Then
      thisFileName = Left(o.Name, InStrRev(o.Name, ".") - 1)
   Else
      thisFileName = o.Name
   End If
   End Function

