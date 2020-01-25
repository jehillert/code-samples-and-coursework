Attribute VB_Name = "Tables"

Function AdjustTableMargins(Optional margins As String = "A", Optional mInc As Single = 0.03)
'If cursor is in a table, or selects all or part of a table, then adjust only that table.
'Otherwise make the change for all tables.
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("AdjustTableMargins()")
   Application.ScreenUpdating = False
   Dim m As String
   Dim Index As Integer
   Dim oTbl As Word.Table
   For Index = 1 To Len(margins)
      m = Mid(margins, Index, 1)
      If Selection.Information(wdWithInTable) Then
         Call AdjustMarginsSelectedTable(Selection.Tables(1), m, mInc)
      Else
         For Each oTbl In ActiveDocument.Tables
            Call AdjustMarginsSelectedTable(oTbl, m, mInc)
         Next
      End If
   Next
   Application.ScreenUpdating = True
   objUndo.EndCustomRecord
End Function
Function AdjustMarginsSelectedTable(ByRef sTable As Table, m As String, mInc As Single)
   Dim mAR, mAL, mAT, mAB As String
   mAL = sTable.LeftPadding + InchesToPoints(mInc)
   mAR = sTable.RightPadding + InchesToPoints(mInc)
   mAT = sTable.TopPadding + InchesToPoints(mInc)
   mAB = sTable.BottomPadding + InchesToPoints(mInc)
   Select Case m
   Case "A", "a"

      If mAL > 0 Then
         sTable.LeftPadding = mAL
      Else
         sTable.LeftPadding = 0
      End If

      If mAR > 0 Then
         sTable.RightPadding = mAR
      Else
         sTable.RightPadding = 0
      End If

      If mAT > 0 Then
         sTable.TopPadding = mAT
      Else
         sTable.TopPadding = 0
      End If

      If mAB > 0 Then
         sTable.BottomPadding = mAB
      Else
         sTable.BottomPadding = 0
      End If
      
   Case "X"
      sTable.LeftPadding = 0
      sTable.RightPadding = 0
      sTable.TopPadding = 0
      sTable.BottomPadding = 0
   Case "L", "l"
      If mAL > 0 Then
         sTable.LeftPadding = mAL
      Else
         sTable.LeftPadding = 0
      End If
   Case "R", "r"
      If mAR > 0 Then
         sTable.RightPadding = mAR
      Else
         sTable.RightPadding = 0
      End If
   Case "T", "t"
      If mAT > 0 Then
         sTable.TopPadding = mAT
      Else
         sTable.TopPadding = 0
      End If
   Case "B", "b"
      If mAB > 0 Then
         sTable.BottomPadding = mAB
      Else
         sTable.BottomPadding = 0
      End If
   End Select
End Function

'RESET/INCREASE ALL MARGINS
Sub ResetTablePatting()
   Call AdjustTableMargins("X")
   End Sub
Sub IncreaseAllPadding()
   AdjustTableMargins
   End Sub
Sub IncreaseTopBottomPadding()
   Call AdjustTableMargins("TB")
   End Sub
   
'INCREASE TABLE MARGINS
Sub IncreaseTableMargin_TopPadding()
   Call AdjustTableMargins("T")
   End Sub
Sub IncreaseTableMargin_BottomPadding()
   Call AdjustTableMargins("B")
   End Sub
Sub IncreaseTableMargin_LeftPadding()
   Call AdjustTableMargins("L")
   End Sub
Sub IncreaseTableMargin_RightPadding()
   Call AdjustTableMargins("R")
   End Sub

'DECREASE TABLE MARGINS
Sub DecreaseTableMargin_TopPadding()
   Call AdjustTableMargins("T", -0.1)
   End Sub
Sub DecreaseTableMargin_BottomPadding()
   Call AdjustTableMargins("B", -0.1)
   End Sub
Sub DecreaseTableMargin_LeftPadding()
   Call AdjustTableMargins("L", -0.1)
   End Sub
Sub DecreaseTableMargin_RightPadding()
   Call AdjustTableMargins("R", -0.1)
   End Sub

'OTHER
Sub InsertTable()
   Set objUndo = Application.UndoRecord
   objUndo.StartCustomRecord ("InsertTable()")
   ActiveDocument.Tables.Add Range:=Selection.Range, NumRows:=1, NumColumns:= _
    2, DefaultTableBehavior:=wdWord9TableBehavior, AutoFitBehavior:= _
    wdAutoFitWindow
   With Selection.Tables(1)
    If .Style <> "Table Grid" Then
       .Style = "Table Grid"
    End If
    .ApplyStyleHeadingRows = True
    .ApplyStyleLastRow = False
    .ApplyStyleFirstColumn = True
    .ApplyStyleLastColumn = False
    .ApplyStyleRowBands = True
    .ApplyStyleColumnBands = False
   End With
   Selection.Tables(1).Select
   Selection.Borders(wdBorderTop).LineStyle = wdLineStyleNone
   Selection.Borders(wdBorderLeft).LineStyle = wdLineStyleNone
   Selection.Borders(wdBorderBottom).LineStyle = wdLineStyleNone
   Selection.Borders(wdBorderRight).LineStyle = wdLineStyleNone
   Selection.Borders(wdBorderVertical).LineStyle = wdLineStyleNone
   Selection.Borders(wdBorderDiagonalDown).LineStyle = wdLineStyleNone
   Selection.Borders(wdBorderDiagonalUp).LineStyle = wdLineStyleNone
   ActiveDocument.ActiveWindow.View.TableGridlines = True
   ActiveDocument.ActiveWindow.View.TableGridlines = True
   objUndo.EndCustomRecord
   End Sub

