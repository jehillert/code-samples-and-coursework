Attribute VB_Name = "Bookmarks"
Sub MarkSelection()
   If ActiveDocument.Bookmarks.Exists("mySelection") = True Then ActiveDocument.Bookmarks("mySelection").Delete
   ActiveDocument.Bookmarks.Add Name:="mySelection", Range:=Selection.Range
   End Sub
Sub Reselect()
   If ActiveDocument.Bookmarks.Exists("mySelection") = True Then Selection.GoTo what:=wdGoToBookmark, Name:="mySelection"
   ActiveDocument.Bookmarks("mySelection").Delete
   End Sub
Sub Mark()
   If ActiveDocument.Bookmarks.Exists("MARK") = True Then ActiveDocument.Bookmarks("MARK").Delete
   ActiveDocument.Bookmarks.Add Name:="MARK"
   End Sub
Sub goMark()
   Selection.GoTo what:=wdGoToBookmark, Name:="MARK"
   End Sub
Sub UnMark()
   ActiveDocument.Bookmarks("MARK").Delete
   End Sub
