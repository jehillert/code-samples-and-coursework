Global LastFoundTitle
Global pRows := 4
Global pColumns := 5
Global iHeight := 20
Global iWidth := 20
Global pSpacing := 8
Global pxMargin := 10
Global pyMargin := 11
Global pHeight := pRows * iHeight + pSpacing * (pRows - 1) + pyMargin * 2
Global pWidth := pColumns * iWidth + pSpacing * (pColumns - 1) + pxMargin * 2
icons := "ms_word_highlighter_gui\icons"

Gui, Highlighter:Add, Picture, x10 y11 w20 h20 ghighlight_dark_yellow, %icons%\dark_yellow.png
Gui, Highlighter:Add, Picture, x38 y11 ghighlight_yellow, %icons%\yellow.png
Gui, Highlighter:Add, Picture, x66 y11 ghighlight_red_white, %icons%\red.png
Gui, Highlighter:Add, Picture, x94 y11 ghighlight_dark_red, %icons%\dark_red.png
Gui, Highlighter:Add, Picture, x122 y11 ghighlight_light_gray, %icons%\light_gray.png

Gui, Highlighter:Add, Picture, x10 y39 ghighlight_green, %icons%\green.png
Gui, Highlighter:Add, Picture, x38 y39 ghighlight_bright_green, %icons%\bright_green.png
Gui, Highlighter:Add, Picture, x66 y39 ghighlight_pink, %icons%\pink.png
Gui, Highlighter:Add, Picture, x94 y39 ghighlight_violet, %icons%\violet.png
Gui, Highlighter:Add, Picture, x122 y39 ghighlight_dark_gray, %icons%\dark_gray.png

Gui, Highlighter:Add, Picture, x10 y67 ghighlight_teal, %icons%\teal.png
Gui, Highlighter:Add, Picture, x38 y67 ghighlight_turquoise, %icons%\turquoise.png
Gui, Highlighter:Add, Picture, x66 y67 ghighlight_blue, %icons%\blue.png
Gui, Highlighter:Add, Picture, x94 y67 ghighlight_dark_blue, %icons%\dark_blue.png
Gui, Highlighter:Add, Picture, x122 y67 ghighlight_black, %icons%\black.png

Gui, Highlighter:Add, Picture, x10 y95 gtoggleGlobalViewState, %icons%\global.png
Gui, Highlighter:Add, Picture, x38 y95 ghighlight_unhighlight, %icons%\unhighlight.png
Gui, Highlighter:Add, Picture, x66 y95 gEraseMarkup, %icons%\EraseMarkup20.png

Gui, Highlighter:-Caption +alwaysontop
Gui, Highlighter:+Owner
Gui, Highlighter:Color, 363636
