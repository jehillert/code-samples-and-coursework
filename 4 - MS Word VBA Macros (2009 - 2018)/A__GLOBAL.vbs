Attribute VB_Name = "A__GLOBAL"
Dim objUndo As UndoRecord

Public Const NavPane_R = 270
Public Const NavPane_L = 220
Public Const my_font = "Segoe UI"
Public Const MY_FONT_SIZE = 12
Public Const zoomDecrement = 4
Public Const myZoomPref = 110
Public Const defWinWidth = 820

Public Declare PtrSafe Sub Sleep Lib "kernel32" (ByVal Milliseconds As LongPtr)
Public InitialScreenUpdatingState, InitialTrackChangesState As Boolean
Public StartTime, SecondsElapsed As Double
Public Bookmark_Iter As Integer
Public LastBM As String

 Sub CreateUndoRec()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("MACRONAME")
   objUndo.EndCustomRecord
   End Sub
Sub doStart(SubName As String)
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord (SubName & "()")
   InitialScreenUpdatingState = Application.ScreenUpdating
   InitialTrackChangesState = ActiveDocument.TrackRevisions
   Application.ScreenUpdating = False
   ActiveDocument.TrackRevisions = False
   End Sub
Sub doStop()
   ActiveDocument.TrackRevisions = InitialTrackChangesState
   Application.ScreenUpdating = InitialScreenUpdatingState
   objUndo.EndCustomRecord
   End Sub
Sub START_FS(SubName As String)
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord (SubName & "()")
   'InitialScreenUpdatingState = Application.ScreenUpdating
   InitialTrackChangesState = ActiveDocument.TrackRevisions
   'Application.ScreenUpdating = False
   ActiveDocument.TrackRevisions = False
   Reset_FRS
   End Sub
Sub STOP_FS()
   Reset_FRS
   ActiveDocument.TrackRevisions = InitialTrackChangesState
   'Application.ScreenUpdating = InitialScreenUpdatingState
   objUndo.EndCustomRecord
   End Sub
Sub START_FC(SubName As String)
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord (SubName & "()")
   'InitialScreenUpdatingState = Application.ScreenUpdating
   InitialTrackChangesState = ActiveDocument.TrackRevisions
   'Application.ScreenUpdating = False
   ActiveDocument.TrackRevisions = False
   Reset_FRS_FC
   End Sub
Sub STOP_FC()
   Reset_FRS_FC
   ActiveDocument.TrackRevisions = InitialTrackChangesState
   'Application.ScreenUpdating = InitialScreenUpdatingState
   objUndo.EndCustomRecord
   End Sub
Sub start_timer()
   StartTime = Timer
   End Sub
Sub stop_timer()
   SecondsElapsed = Round(Timer - StartTime, 2)
   Dim MyData As DataObject
   Dim strClip As String
   strClip = SecondsElapsed & " seconds"
   Set MyData = New DataObject
   MyData.SetText strClip
   MyData.PutInClipboard
   End Sub
Sub undoable(SubName As String)
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord (SubName & "()")
   End Sub




