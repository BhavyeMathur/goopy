# Goopy

## Introduction
A simple-yet-powerful 2D graphics framework built on top of Tkinter capable of creating good-looking, modern GUIs, games, and simple animations.

This graphics library is built upon John Zelle's graphics.py package for use with his textbook "Python Programming: An Introduction to Computer Science". Over the past 2 years, I have worked on editing this library to add more featurs to use with making my GUIs and games. My entire aim while editing was to create a powerful medium to enable me to create good-looking graphics within Python and I have spent a lot of time making sure this is the case. Thus, this is a very intuitive and simple to use package with the potential of growing into one of the best Python Graphics Libraries. 

If you would want to contribute to this library by suggesting features, reporting bugs, or adding changes yourself, please do so. I would love it if you would use this library in your projects and do make sure to tell me about them! Right now, this is very much an alpha stage - there are many bugs, many features that aren't compatible with each other, and a ton of things to do differently, but hopefully this can all be fixed with future releases. 

If you want to contact me, you can drop me an email at: bhavyemathur@gmail.com

### Installation

This library is very simple to use, all you need is the file called 'goopy.py' and the requirements mentioned in the requirement.txt file. These include the Pillow (PIL) and the keyboard modules which you can download individually or clone this repository and in that directory execute:

```sh
python3 -m pip install -r requirements.txt
```

Now, wherever you need access to the library, simply import as so:

```python

from goopy import *
# or
import goopy as gp

```

### Documentation

There are plans to create a detailed documentation for this library both in the form of YouTube videos and a written document, however, there is not such documentation right now.

## Contributions

1. Spectral Doy - 3rd July 2020 - Helping me choose a name! we went through a lot of options... pyraphics, oreopy, pyllustrate, guipy... barnacle...
2. John Zelle - Creating the graphics.py package which formed the basis for my library.

## Version History

### v6.11-dev

#### 6.11.0 - 3rd July 2020

* Removed the Image_depr class which was used as a backup until the new class using the Pillow library was created
* Removed the ToDos, Version History, and Introduction from Goop.py and moved it to the README file

* Closed issue regarding adding new colour formats after adding Hex & CMYK support in v6.10
* Fixed the GraphWin's setBackground() function to work with colours referencing a style

* Warning added to warn the user if they are both calling the updateWin() function manually and the autoflush of the GraphWin is set to True
* While resizing a rectangle, you can set the min. width & height beyond which, the rectangle cannot be resized 
* A GraphicsError is now raised if the minWidth & minHeight arguments of the setResizable() function are < 1

* Added Errors to the setStyle() function & GraphWin class to make sure the user has entered the correct arguments


### v6.10-dev

* Points are no longer graphic objects
* Custom Support for Cursors on the GraphWin & _BBox classes
* Added support for colour palettes and added 3 style: default, pycharm darcula, and intellij
* Added Assertions to the graphics objects to give better error statements
* Added Config functions for all configurations for the Graphics Window class
* Added circular and ovular bounding boxes
* Added setObjectWidth & Height functions as well as _BBox object resizing functions
* Bounding boxes are now represented by graphics objects (_BBox objects)
* Fixed bugs with using the mouseEvent functions returning None value and added the refresh argument
* Fixed Bug with Graphics Objects resizing when resizing the window
* Fixed bug with background not filling colour of the entire region of window (not only the seen region)
* Tested the graphics window class
* Organized code in the GraphWin
* More colour definitions!
* ColourHex, ColourCMYK, and ColourRGB classes added

* Changed Version History dates from mm/dd/yyyy to dd/mm/yyyy

### v6.9-dev 31/5/2020
* Added argument assert statements to the Graphics Window class
* Added a colour class
* Changed all references of 'Color' to 'Colour'

### v6.8 17/5/2020
* Added a window parameter to every Graphics Class that allows the user to draw the window in the class declaration
* Added more functions to set the Arrow of a line
* You can now set the arrow of a line inside the __init__ function
* Removed all the sound functions
* Added TODOs

### v6.7-dev 25/4/2020
* The Image Object now uses the Pillow (PIL) library which gives the user far more ways to manipulate the object
* Added the ImageGrp class to Group Images together
* Added RadioButtons, & CycleButtons
* New & Improved functions to the GraphWin including the ability to resize the window!
* Added Glide & GlideTo functions with easing to animate objects!

### v6.6-dev 24/11/2019
* Added a few more colour definitions
* Image scaling functions (zoom & resize) now return the image class & don't require the image to have been drawn
* Added ButtonPressed attributes to the GraphWin class to have more variety in mouse events
* Added a moveTo function for BBox classes
* Made the CheckBox class much easier to work with
* Various bug fixes

### v6.5-dev 16/9/2019
* Added Right, Left and Middle click events to the GraphWin class
* Changed GraphWin getKey() and checkKey() functions to use the keyboard library instead of tkinter
* Added checkForKeys() function to GraphWin to check for Multiple keys at once
* Added attribute setting functions for SlideBar class
* Fixed bug of SlideBar class not functioning when p1.(x or y) > p2.(x or y) - x or y depending on orientation

* Added isClicked() function for points and lines
* Added isSelected() function for all GraphicObject children Classes
* Added enabled, disabled and read only states to Entry Class and added many more functions

* GraphicsObject objects now return themselves when the draw() function is called to allow the user to create and
draw an object with 1 line of code
* Added playSound function which plays music

### v6.2-dev 12/9/2019
* Fixed Bug of Line class not drawing due to error
* Fixed Bug of the Graphics Objects' undraw() function not undrawing
* Added SlideBar class
* Added a function to get the Mouse Scroll value to graphwin
* Removed restrictions on text fonts and size allowing user to use whatever values they want
* Added a very basic rectangular Button class

### v6.1-dev 29/8/2019
* Checkboxes added as a class
* Button class added
* Fixed bug with isClicked() function that didn't work when x1 > x2 or y1 > y2
* Added more Fonts

# v6-dev 15/7/2019
* added moveTo() function for all graphics objects to specify x & y variables rather than dx & dy
* added more parameters for classes to customize them during creation rather than using multiple functions
* Defined multiple variables containing colour information to use when colouring object
* added more fonts for text objects to use
* Implemented a new error for missing values
* Added isClicked() function for Image and BBox objects