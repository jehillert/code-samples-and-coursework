Attribute VB_Name = "ClaimStatuses"
Sub AllowedClaims()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("NOAClaimStatuses()")
   For Each myRev In Selection.Range.Revisions
    myRev.Accept
   Next myRev
   Call Reset_FRS
   Selection.Range.Revisions.AcceptAll
   Call DeleteDoubleBrackets
   Call CapitalizeClaimStatuses
   Selection.Find.MatchCase = False
   Call FindReplaceInSelection(".^wA ", ".^t(Allowed) A ")
   Call FindReplaceInSelection(".^wThe", ".^t(Allowed) The")
   Call FindReplaceInSelection(".^w(New)", ".^t(Allowed)")
   Call FindReplaceInSelection(".^w(Currently Amended)", ".^t(Allowed)")
   Call FindReplaceInSelection(".^w(Previously Presented)", ".^t(Allowed)")
   Call FindReplaceInSelection(".^w(Original)", ".^t(Allowed)")
   Call FindReplaceInSelection(".^w(Withdrawn)", ".^t(Cancelled)")
   Call AssignClaimsOL1
   Call Reset_FRS
   objUndo.EndCustomRecord
End Sub
Sub AddClaimStatuses()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("Add Claim Statuses")
   ActiveDocument.TrackRevisions = "False"
   Selection.Find.ClearFormatting
   Selection.Find.Replacement.ClearFormatting
   With Selection.Find
    .Text = ".^t"
    .Replacement.Text = ".^t(Original) "
    .Forward = True
    .Wrap = wdFindStop
   End With
   Selection.Find.Execute Replace:=wdReplaceAll
   Selection.Find.ClearFormatting
   Selection.Find.Replacement.ClearFormatting
   With Selection.Find
    .Text = "No Change"
    .Replacement.Text = "Original"
    .Forward = True
    .Wrap = wdFindStop
    .FORMAT = True
   End With
   Selection.Find.Execute Replace:=wdReplaceAll
   Call Reset_FRS
   objUndo.EndCustomRecord
End Sub
Sub CapitalizeClaimStatuses()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("CapitalizeClaimStatuses()")
   If ActiveDocument.TrackRevisions = True Then markup_state = True
   ActiveDocument.TrackRevisions = False
   Call Reset_FRS
   Selection.Find.Wrap = wdFindStop
   Call FindReplaceInSelection("(currently amended)", "(Currently Amended)")
   Call FindReplaceInSelection("(new)", "(New)")
   Call FindReplaceInSelection("(canceled)", "(Cancelled)")
   Call FindReplaceInSelection("(cancelled)", "(Cancelled)")
   Call FindReplaceInSelection("(original)", "(Original)")
   Call FindReplaceInSelection("(previously presented)", "(Previously Presented)")
   Call FindReplaceInSelection("(withdrawn)", "(Withdrawn)")
   Call FindReplaceInSelection("(withdrawn - currently amended)", "(Withdrawn - Currently Amended)")
   Call FindReplaceInSelection("(withdrawn-currently amended)", "(Withdrawn - Currently Amended)")
   Call FindReplaceInSelection("(original)", "(Original)")
   Call Reset_FRS
   If markup_state = True Then ActiveDocument.TrackRevisions = True
   objUndo.EndCustomRecord
End Sub
Sub DeleteClaimStatuses()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("Delete Claim Statuses")
   ActiveDocument.TrackRevisions = "False"
   Call Reset_FRS
   Selection.Find.Wrap = wdFindStop
   Call FindReplaceInSelection("(amend)^w", "")
   Call FindReplaceInSelection("(add)^w", "")
   Call FindReplaceInSelection("(added)^w", "")
   Call FindReplaceInSelection("(allowed)^w", "")
   Call FindReplaceInSelection("(amended)^w", "")
   Call FindReplaceInSelection("(cancel)^w", "")
   'Call FindReplaceInSelection("(canceled)^w", "")
   'Call FindReplaceInSelection("(cancelled)^w", "")
   Call FindReplaceInSelection("(currently amended)^w", "")
   Call FindReplaceInSelection("(delete)^w", "")
   Call FindReplaceInSelection("(deleted)^w", "")
   Call FindReplaceInSelection("(new)^w", "")
   Call FindReplaceInSelection("(no change)^w", "")
   Call FindReplaceInSelection("(original)^w", "")
   Call FindReplaceInSelection("(previously presented)^w", "")
   Call FindReplaceInSelection("(withdrawn)^w", "")
   Call FindReplaceInSelection("\(withdrawn*\)", "")
   Call FindReplaceInSelection("\(withdrawn*\)", "")
   Call FindReplaceInSelection("\(withdrawn*\)", "")
   Call FindReplaceInSelection("\(withdrawn*\)^t", "")
   Call Reset_FRS
   objUndo.EndCustomRecord
End Sub
Sub Update_Claim_Statuses()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("Update_Statuses()")
   ActiveDocument.TrackRevisions = "False"
   Selection.Range.Revisions.AcceptAll
   Call DeleteDoubleBrackets
   Call Reset_FRS
   Selection.Find.Wrap = wdFindStop
   Call FindReplaceInSelection("(currently amended)", "(Previously Presented)")
   Call FindReplaceInSelection("(previously presented)", "(Previously Presented)")
   Call FindReplaceInSelection("(new)", "(Previously Presented)")
   Call FindReplaceInSelection("(withdrawn-currently amended)", "(Withdrawn)")
   Call FindReplaceInSelection("(withdrawn - currently amended)", "(Withdrawn)")
   Call FindReplaceInSelection("(canceled)", "(Cancelled)")
   Call FindReplaceInSelection("(cancelled)", "(Cancelled)")
   Call FindReplaceInSelection("(original)", "(Original)")
   Call FindReplaceInSelection("(withdrawn)", "(Withdrawn)")
   Call Reset_FRS
   objUndo.EndCustomRecord
End Sub
