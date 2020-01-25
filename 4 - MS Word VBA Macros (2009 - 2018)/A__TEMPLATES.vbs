Attribute VB_Name = "A__TEMPLATES"
Sub IteratateThroughParagraphsTemplate()
   Dim SingleP As Paragraph
   Selection.WholeStory
   For Each SingleP In Selection.PARAGRAPHS
   Next SingleP
   End Sub
