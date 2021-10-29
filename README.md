///////////////////////////////////////////////////////////////
// LiquidCrystal NKC v0.21.299 ////////////////////////////////
// Developer: Dominic Luciano /////////////////////////////////
///////////////////////////////////////////////////////////////

NKC Electronics Serial LCD Module Library for the Arduino IDE
This Library is Compatible with the Arduino IDE v1.0 to v2.0+

// DESCRIPTION ////////////////////////////////////////////////
While not very mainstream, the Longtech & NKC Electronics LCD
display boasts a myriad of features over and above the generic
I2C backpacks typically used to simplify 8-bit LCD connection,
such as the capability to command the display not just via I2C
but also over RS232 (with just a single wire), as well as over
an everyday SPI bus. This NKC LCD also provides fully digital
control over the brightness and contrast, doing away with trim
pots for contrast adjustment, and providing backlight settings
beyond just "ON" and "OFF".

But the bragging rights go beyond the mere NKC display itself.
This LiquidCrystal NKC library is built to work with the same
commands as the LiquidCrystal and LiquidCrystal I2C libraries,
but also retains alias commands to remain compatible with the
original SerialLCD library. So little to no code will require
rewriting or reworking.

However, many extensions to the basic commands were integrated
into this LiquidCrystal NKC library. And there are many future
additions and expansions planned, so make sure to keep your LC
NKC library updated to take advantage of all those features!

NOTE: Some features are still being developed and perfected &
may not work properly or as expected. Please make sure to post
and report all bugs on the official GitHub repository, located
at: https://www.guthub.com/domiluci/LiquidCrystal_NKC. Thanks!

// GENERAL USAGE //////////////////////////////////////////////

// CONSTRUCTOR //
// Interface, I2C Address/Baud Rate, Columns, Rows
Ex: LC_NKC lcd(I2C, 0x28, 20, 4)
Ex: LC_NKC lcd(RS232, 9600, 20, 4)

// COMMANDS //
- Initialize the LCD with .init() or .begin()
- Turn the display on/off with .on() or .off()
- Alternatively, you may use .display() or .noDisplay
- Toggle the backlight with .backlight() or .noBacklight()
- Or toggle the backlight with .setBacklight(HIGH or LOW)
- Set it to specific level with .setBacklightBrightness(1 to 8)
- Set the display's contrast with .setContrast(1 to 40)
- Clear the entire display with .clear()
- Clear a single position with .clear(column, row)
- Clear many spaces with .clear(start column, end column, row)
- Clear an entire line/row with .clear(row)
- Reset the cursor to 0, 0 with .home()
- Set the cursor's position with .setCursor(column, row)
- Write a single character to the display with .write()
- Print a char or string to the LCD with .print()
- The function .printstr() does the same thing
- Store up to 8 unique characters to LCD with .createChar()
- Use .cursorOn() or .cursorOff() to toggle the cursor
- Using .cursor() and .noCursor() alias does the same thing
- Turn the blinking cursor on/off with .blinkOn() & .blinkOff()
- Do the same with .blink(true) and .blink(false)
- Or use .blink() and .noBlink() to stay compatible
- To move cursor left/right a spot, use .left() or .right()
- To move it more, use .left(columns) or .right(columns)
- Backspace the cursor with .backspace()
- Shift the whole display with .shiftLeft() and .shiftRight()
- Shift more with .shiftLeft(columns) and .shiftRight(columns)
- Or use .scrollDisplayLeft() or .scrollDisplayRight() and...
- .scrollDisplayLeft(columns) or .scrollDisplayRight(columns)

// WHAT'S NEXT ////////////////////////////////////////////////

Currently, an expanded LiquidCrystal library is in development
that will combine support for all LCD displays, including this
NKC Serial LCD display. A universal LCD library will not only
make it easier to switch between different LCD displays while
eliminating time wasted on reconfiguring and recoding projects,
but it will also create a standardized set of commands for all
LCD displays of all interface types. Not to mention expand on
all current commands, providing easier, simpler functionality
with more power and flexibility, all while requiring less code
to implement and execute.

As for this LiquidCrystal NKC library, it will continue to be
updated and maintained, even after completion of the expanded
LiquidCrystal library. More additions will be coming soon. So
make sure you keep your copy of the LiquidCrystal NKC library
up-to-date to score on all those fresh features ASAP. And stay
tuned to the other repositories for the all new, all universal
LiquidCrystal library coming soon! 