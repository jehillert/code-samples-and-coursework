Attribute VB_Name = "FindAndDo"
'   If Selection.Type = wdSelectionIP Then
'      Selection.WholeStory
'      Selection.Find.Wrap = wdFindContinue
'   Else
'      Selection.Find.Wrap = wdFindStop
'   End If
'
Sub DeleteTrailingMixedWhiteSpace()
      START_FS ("DeleteTrailingMixedWhiteSpace")
      Dim arr_f() As Variant   'Dim arr() As Variant
      Dim arr_r() As Variant
      Dim i As Byte
      '      ConvertAllNumbers
      Reset_FRS
      arr_f = Array("(^032)\1@(^11)", _
            "(^032)\1@(^13)", "(^032)\1@(^9)", _
            "(^032)\1@(^12)", "(^032)\1@(^14)", _
            "(^9)\1@(^11)", "(^9)\1@(^12)", _
            "(^9)\1@(^13)", "(^9)\1@(^14)")
      arr_r = Array("^11", _
            "\2", "\2", _
            "\2", "\2", _
            "\2", "\2", _
            "\2", "\2")
      For i = LBound(arr_f) To UBound(arr_f)
      With Selection.Find
            .MatchWildcards = True
            .Text = arr_f(i)
            .Replacement.Text = arr_r(i)
      End With
      Selection.Find.Execute Replace:=wdReplaceAll
      Next
      STOP_FS
      End Sub
Sub FindReplace(FindText As String, ReplaceText As String)
   InitialScreenUpdatingState = Application.ScreenUpdating
   InitialTrackChangesState = ActiveDocument.TrackRevisions
   Application.ScreenUpdating = False
   ActiveDocument.TrackRevisions = True
   Reset_FRS
   START_FS ("FindReplace")
   ActiveDocument.Bookmarks.Add Name:="FR_Mark", Range:=Selection.Range
   If Selection.Type = wdSelectionIP Then
   Selection.HomeKey Unit:=wdStory
   Selection.Find.Wrap = wdFindContinue
   End If
   With Selection.Find
   .Text = FindText
   .Replacement.Text = ReplaceText
   .Execute Replace:=wdReplaceAll
   End With
   Selection.GoTo what:=wdGoToBookmark, Name:="FR_Mark"
   ActiveDocument.Bookmarks("FR_Mark").Delete
   Reset_FRS
   Application.ScreenUpdating = InitialScreenUpdatingState
   ActiveDocument.TrackRevisions = InitialTrackChangesState
   objUndo.EndCustomRecord
    End Sub
Sub FindAndReplaceAsTxtFormFld(FindText As String, FormFieldFext)
   START_FC ("FindAndReplaceAsTxtFormFld")
   Dim pState As Boolean, Pwd As String, StrTmp As String, FFld As FormField
   pState = False
   If ActiveDocument.ProtectionType <> wdNoProtection Then
      Pwd = InputBox("Please enter the Password", "Password")
      pState = True
      ActiveDocument.Unprotect Pwd
   End If
   ActiveDocument.Range.Find.FORMAT = True
   ActiveDocument.Range.Find.MatchWildcards = True
   ActiveDocument.Range.Find.Execute
   Do While ActiveDocument.Range.Find.Found
      StrTmp = FormFieldFext
      Set FFld = ActiveDocument.FormFields.Add(Range:=ActiveDocument.Range.Duplicate.Words.Last, Type:=wdFieldFormTextInput)
      FFld.result = StrTmp
      ActiveDocument.Range.Start = FFld.Range.End
      ActiveDocument.Range.Find.Execute
   Loop
   If pState = True Then .Protect Type:=wdAllowOnlyFormFields, Noreset:=True, Password:=Pwd
   pState = False
   STOP_FS
   End Sub
Sub FindReplaceInSelection(FindText As String, ReplaceText As String)
   Call Reset_FRS
   Selection.Find.Text = FindText
   Selection.Find.Replacement.Text = ReplaceText
   Selection.Find.Execute Replace:=wdReplaceAll
   Selection.Find.Text = ""
   Selection.Find.Replacement.Text = ""
   End Sub
Sub FindReplaceInSelection_WildcardsOn(FindText As String, ReplaceText As String)
   Reset_FRS
   With Selection.Find
      .MatchWildcards = True
      .Text = FindText
      .Replacement.Text = ReplaceText
      .Execute Replace:=wdReplaceAll
      .Text = ""
      .Replacement.Text = ""
      .MatchWildcards = False
   End With
   Reset_FRS
   End Sub
Sub FindReplaceText(FindText As String, ReplaceText As String)
   Call Reset_FRS_FC
   Selection.Find.Text = FindText
   Selection.Find.Replacement.Text = ReplaceText
   Do While Selection.Find.Execute
      'Keep going until nothing found
      Selection.Find.Execute Replace:=wdReplaceAll
   Loop
   Selection.Find.Text = ""
   Selection.Find.Replacement.Text = ""
   End Sub
Sub RemoveHeadAndFoot()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("Remove Headers & Footers")
   
   Dim oSec As Section
   Dim oHead As HeaderFooter
   Dim oFoot As HeaderFooter

   For Each oSec In ActiveDocument.Sections
       For Each oHead In oSec.Headers
          If oHead.Exists Then oHead.Range.Delete
       Next oHead
   
       For Each oFoot In oSec.Footers
          If oFoot.Exists Then oFoot.Range.Delete
       Next oFoot
   Next oSec
   objUndo.EndCustomRecord
   End Sub
Sub ReplaceFirstOccurrence(ByVal strToFind As String, ByVal strReplacement As String)
   Selection.Find.ClearFormatting
   Selection.Find.Replacement.ClearFormatting
   Selection.Find.Text = strToFind
   Selection.Find.Replacement.Text = strReplacement
   Selection.Find.Forward = True
   Selection.Find.Wrap = wdFindContinue
   Selection.Find.FORMAT = False
   Selection.Find.MatchCase = False
   Selection.Find.MatchWholeWord = False
   Selection.Find.MatchWildcards = False
   Selection.Find.MatchSoundsLike = False
   Selection.Find.MatchAllWordForms = False
   Selection.Find.Execute Replace:=wdReplaceOne
   End Sub
Sub SearchAndReplaceCount(ByVal strSought As String, ByVal strReplacement As String)
   Dim rngReplace As Word.Range
   Dim lngCount As Long
   Set rngReplace = Selection.Range
   rngReplace.Find.ClearFormatting
   rngReplace.Find.Replacement.ClearFormatting
   rngReplace.Find.Text = strSought
   rngReplace.Find.Replacement.Text = strReplacement
   rngReplace.Find.Forward = True: .Wrap = wdFindContinue
   rngReplace.Find.FORMAT = False
   rngReplace.Find.MatchCase = False
   rngReplace.Find.MatchWholeWord = False
   rngReplace.Find.MatchAllWordForms = False
   rngReplace.Find.MatchSoundsLike = False
   rngReplace.Find.MatchWildcards = False
   Do While rngReplace.Find.Execute(Replace:=wdReplaceOne)
      lngCount = lngCount + 1
      rngReplace.collapse wdCollapseEnd
   Loop
   MsgBox lngCount & " Replacements were made"
   End Sub
Sub Reset_FRS_FC()
   Selection.Find.ClearFormatting
   Selection.Find.Replacement.ClearFormatting
   Selection.Find.Text = ""
   Selection.Find.Replacement.Text = ""
   Selection.Find.Forward = True
   Selection.Find.Wrap = wdFindContinue
   Selection.Find.FORMAT = False
   Selection.Find.MatchCase = False
   Selection.Find.MatchWholeWord = False
   Selection.Find.MatchWildcards = False
   Selection.Find.MatchSoundsLike = False
   Selection.Find.MatchAllWordForms = False
   End Sub
 Sub Reset_FRS()
   Selection.Find.ClearFormatting
   Selection.Find.Replacement.ClearFormatting
   Selection.Find.Text = ""
   Selection.Find.Replacement.Text = ""
   Selection.Find.Forward = True
   Selection.Find.Wrap = wdFindStop
   Selection.Find.FORMAT = False
   Selection.Find.MatchCase = False
   Selection.Find.MatchWholeWord = False
   Selection.Find.MatchWildcards = False
   Selection.Find.MatchSoundsLike = False
   Selection.Find.MatchAllWordForms = False
   End Sub
Sub WipeTabStops()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("Wipe Tab Stops")
   If Selection.Type = wdSelectionIP Then
      ActiveDocument.Bookmarks.Add Name:="MARK"
      Selection.WholeStory
      Selection.ParagraphFormat.TabStops.ClearAll
      Selection.GoTo what:=wdGoToBookmark, Name:="MARK"
      ActiveDocument.Bookmarks("MARK").Delete
   Else
      Selection.ParagraphFormat.TabStops.ClearAll
   End If
   ActiveDocument.DefaultTabStop = InchesToPoints(0.5)
   Selection.MoveLeft Unit:=wdCharacter, Count:=1
   objUndo.EndCustomRecord
   End Sub
















