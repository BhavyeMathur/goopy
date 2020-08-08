from goopylib.imports import *

window = GraphWin(title="Hello World!", width=500, height=500, bk_colour=DARKEST_GREY)  # Creating the window

Rectangle(Point(0, 220), Point(500, 280), fill=DARK_GREY, outline_width=0).draw()  # Drawing a rectangle in the back

# Creates the title text and makes it glide in from the side with an elastic ease for 2 seconds
title = Text(Point(0, 250), "Hello World!", font_colour=WHITE, font_size=30, font_face="Century Gothic", font_style="bold").draw()
title.glide_to_x(250, time=2, easing=ease_elastic_out())

# Creates the subtitle and makes it glide in from the bottom with a circle ease for 2 seconds
subtitle = Text(Point(250, 520), "Bhavye's 2nd program", font_colour=WHITE, font_size=12, font_face="Century Gothic").draw()
subtitle.glide(0, 0, time=1)
subtitle.glide_to_y(300, time=2, easing=ease_circle_out())

while True:  # The Mainloop
    window.update_win()  # Updating the Window