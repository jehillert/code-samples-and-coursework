Attribute VB_Name = "HighlighterFunctions"
'HIGHLIGHT FIGS
Sub HighlightFIGS()

   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("HighlightFIGS")

   Reset_FRS_FC
 
   Selection.Range.HighlightColorIndex = wdYellow
   
   With Selection.Find
   
     .Replacement.Highlight = True
     .Replacement.Text = ""
     .FORMAT = True
     
     .Text = "FIG ^#^#^$"
     .Execute Replace:=wdReplaceAll
     
     .Text = "FIG ^#^#"
     .Execute Replace:=wdReplaceAll
     
     .Text = "FIG ^#^$"
     .Execute Replace:=wdReplaceAll
     
     .Text = "FIG ^#"
     .Execute Replace:=wdReplaceAll
     
     .Text = "FIGS ^#^#^$-^#^#^$"
     .Execute Replace:=wdReplaceAll
     
     .Text = "FIGS ^#^#-^#^#"
     .Execute Replace:=wdReplaceAll
     
     .Text = "FIGS ^#^$-^#^$"
     .Execute Replace:=wdReplaceAll
     
     .Text = "FIGS ^#-^#"
     .Execute Replace:=wdReplaceAll
     
     .Text = "FIG. ^#^#^$"
     .Execute Replace:=wdReplaceAll
     
     .Text = "FIG. ^#^#"
     .Execute Replace:=wdReplaceAll
     
     .Text = "FIG. ^#^$"
     .Execute Replace:=wdReplaceAll
     
     .Text = "FIG. ^#"
     .Execute Replace:=wdReplaceAll
     
     .Text = "FIGS. ^#^#^$-^#^#^$"
     .Execute Replace:=wdReplaceAll
     
     .Text = "FIGS. ^#^#-^#^#"
     .Execute Replace:=wdReplaceAll
     
     .Text = "FIGS. ^#^$-^#^$"
     .Execute Replace:=wdReplaceAll
     
     .Text = "FIGS. ^#-^#"
     .Execute Replace:=wdReplaceAll
     
     .Text = "FIG.^#^#^$"
     .Execute Replace:=wdReplaceAll
     
     .Text = "FIG.^#^#"
     .Execute Replace:=wdReplaceAll
     
     .Text = "FIG.^#^$"
     .Execute Replace:=wdReplaceAll
     
     .Text = "FIG.^#"
     .Execute Replace:=wdReplaceAll
     
     .Text = "FIGS.^#^#^$-^#^#^$"
     .Execute Replace:=wdReplaceAll
     
     .Text = "FIGS.^#^#-^#^#"
     .Execute Replace:=wdReplaceAll
     
     .Text = "FIGS.^#^$-^#^$"
     .Execute Replace:=wdReplaceAll
     
     .Text = "FIGS.^#-^#"
     .Execute Replace:=wdReplaceAll
   
     .Text = "Figure ^#^#^$"
     .Execute Replace:=wdReplaceAll
     
     .Text = "Figure ^#^#"
     .Execute Replace:=wdReplaceAll
     
     .Text = "Figure ^#^$"
     .Execute Replace:=wdReplaceAll
     
     .Text = "Figure ^#"
     .Execute Replace:=wdReplaceAll
     
     .Text = "Figures ^#^#^$-^#^#^$"
     .Execute Replace:=wdReplaceAll
     
     .Text = "Figures ^#^#-^#^#"
     .Execute Replace:=wdReplaceAll
     
     .Text = "Figures ^#^$-^#^$"
     .Execute Replace:=wdReplaceAll
     
     .Text = "Figures ^#-^#"
     .Execute Replace:=wdReplaceAll
   End With
   
   Reset_FRS_FC
   objUndo.EndCustomRecord
   
End Sub

Sub UnHighlightRefsToFigs()

   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("UnHighlightRefsToFigs")
   
   Reset_FRS_FC
   Selection.Find.Replacement.Highlight = False
   
   With Selection.Find
   
    .Text = "FIG. ^#^#^$"
    .Replacement.Text = ""
    .FORMAT = True
    .Execute Replace:=wdReplaceAll
   
    .Text = "FIG. ^#^#"
    .Execute Replace:=wdReplaceAll

    .Text = "FIG. ^#^$"
    .Execute Replace:=wdReplaceAll

    .Text = "FIG. ^#"
    .Execute Replace:=wdReplaceAll

    .Text = "FIGS. ^#^#^$-^#^#^$"
    .Execute Replace:=wdReplaceAll
   
    .Text = "FIGS. ^#^#-^#^#"
    .Execute Replace:=wdReplaceAll
   
    .Text = "FIGS. ^#^$-^#^$"
    .Execute Replace:=wdReplaceAll
   
    .Text = "FIGS. ^#-^#"
    .Execute Replace:=wdReplaceAll

    .Text = "Figure ^#^#^$"
    .Execute Replace:=wdReplaceAll
   
    .Text = "Figure ^#^#"
    .Execute Replace:=wdReplaceAll
   
    .Text = "Figure ^#^$"
    .Execute Replace:=wdReplaceAll
   
    .Text = "Figure ^#"
    .Execute Replace:=wdReplaceAll
   
    .Text = "Figures ^#^#^$-^#^#^$"
    .Execute Replace:=wdReplaceAll
   
    .Text = "Figures ^#^#-^#^#"
    .Execute Replace:=wdReplaceAll
   
    .Text = "Figures ^#^$-^#^$"
    .Execute Replace:=wdReplaceAll
   
    .Text = "Figures ^#-^#"
     .Execute Replace:=wdReplaceAll
     
   End With
   
   Call Reset_FRS
   
   objUndo.EndCustomRecord
   
End Sub
'Sub highlight_as_text_form_field()
'   Set objUndo = Application.UndoRecord: objUndo.StartCustomRecord ("highlight_as_text_form_field(Color)")
'   If Selection.Type = wdSelectionIP Then
'    Selection.Expand Unit:=wdWord
'   End If
'   Selection.MoveEndWhile Chr(32), wdBackward
'   On Error GoTo ErrorHandler
'If Selection.Type = wdSelectionIP Then
'    Selection.Expand Unit:=wdWord
'   End If
'   Selection.MoveEndWhile Chr(32), wdBackward
'   Options.DefaultHighlightColorIndex = Color
'   Selection.Range.HighlightColorIndex = Color
'   On Error GoTo ErrorHandler
'Reset_FRS_FC
'HIGHLIGHT
'Function Highlight(Color)
'
'   InitialScreenUpdatingState = Application.ScreenUpdating
'   InitialTrackChangesState = ActiveDocument.TrackRevisions
''Application.ScreenUpdating = False
'   ActiveDocument.TrackRevisions = False
'
'   Set r = ActiveDocument.Content
'
'   r.Find.ClearFormatting
'   r.Find.Replacement.ClearFormatting
'
'   If Selection.Type = wdSelectionIP Then
'    Selection.Expand Unit:=wdWord
'   End If
'   Selection.MoveEndWhile Chr(32), wdBackward
'
'   Options.DefaultHighlightColorIndex = Color
'   r.Find.Replacement.Highlight = True
'   r.Find.Execute FindText:=Selection.Text, MatchWildcards:=False, Wrap:=wdFindContinue, FORMAT:=True, replacewith:="", Replace:=wdReplaceAll
'
'   ActiveDocument.TrackRevisions = initial_track_changes_state
''Application.ScreenUpdating = initial_screen_updating_state
'
'End Function



'Selection.Find.Replacement.Highlight = True
'    Selection.Find.Text = Selection: Selection.Find.Replacement.Text = ""
'    Selection.Find.format = True
'    Selection.Find.Execute Replace:=wdReplaceAll
'    Reset_FRS
'    objUndo.EndCustomRecord: Exit Sub
'ErrorHandler:
'
'
'   Reset_FRS
'   objUndo.EndCustomRecord
'   Exit Sub
'ErrorHandler:
'Reset_FRS_FC:        objUndo.EndCustomRecord
'End Sub
'Sub FindAndReplaceSelectionAsTxtFormField(FormFieldFext)
'   Set objUndo = Application.UndoRecord
'   objUndo.StartCustomRecord ("AddFormFields()")
'   Dim pState As Boolean, Pwd As String, StrTmp As String, FFld As FormField
'   With ActiveDocument
'     pState = False
'     If .ProtectionType <> wdNoProtection Then
'    Pwd = InputBox("Please enter the Password", "Password")
'    pState = True
'    .Unprotect Pwd
'     End If
'     With .Range
'    With .Find
'       .ClearFormatting
'       .Text = FindText
'       .Replacement.Text = ""
'       .Forward = True
'       .Wrap = wdFindContinue
'       .format = True
'       .MatchCase = False
'       .MatchWholeWord = False
'       .MatchWildcards = True
'       .MatchSoundsLike = False
'       .MatchAllWordForms = False
'       .Execute
'    End With
'    Do While .Find.Found
'    StrTmp = FormFieldFext
'      Set FFld = ActiveDocument.FormFields.Add(Range:=.Duplicate.Words.Last, _
'           Type:=wdFieldFormTextInput)
'      FFld.Result = StrTmp
'      .Start = FFld.Range.End
'      .Find.Execute
'    Loop
'     End With
'     If pState = True Then .Protect Type:=wdAllowOnlyFormFields, Noreset:=True, _
'         Password:=Pwd
'    pState = False
'   End With
'   Reset_FRS
'   objUndo.EndCustomRecord
'End Sub



