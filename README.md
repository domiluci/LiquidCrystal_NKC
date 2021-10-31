# LiquidCrystal NKC

#### **Developed By [Dominic Luciano](https://www.github.com/domiluci)**

Official repository of the **LiquidCrystal NKC** Arduino Library for [Longtech & NKC Electronics Serial LCD Modules](http://media.nkcelectronics.com/datasheet/LCM2004SD-NSA-FBW.pdf)

This Arduino Library is Arduino IDE 2.0+ Compatible

![Hello World Example](https://i.ibb.co/HYcRqPY/Hello-World-2.jpg)

## DESCRIPTION

While not very mainstream, the [Longtech & NKC Electronics Serial LCD display module](http://media.nkcelectronics.com/datasheet/LCM2004SD-NSA-FBW.pdf) boasts a myriad of features over and above the generic **PCF8574** and **MCP23017** I2C backpacks typically used to simplify 4-bit & 8-bit LCD connections, such as the capability to command the display not just via I2C but also over RS232 (with just a single wire), as well as over an everyday SPI bus. This NKC LCD also provides completely digital control over the brightness and contrast, doing away with trim pots for contrast adjustment, and providing backlight settings beyond just "ON" and "OFF".

But the bragging rights go beyond the mere NKC display itself. This **LiquidCrystal NKC** library is built to work with the same commands as the **LiquidCrystal** and **LiquidCrystal I2C** libraries, but it also retains alias commands to remain compatible with the original **SerialLCD** library. So little to no code will require rewriting or reworking.

However, many extensions to the basic commands were integrated into this **LiquidCrystal NKC** library. And there are many future additions and expansions planned, so make sure to keep your **LiquidCrystal NKC** library up-to-date to take advantage of all those features!

**NOTE:** This is currently a beta release. As such, some features are still being developed and perfected, and therefore may not work properly or as expected. Please make sure to post and report all bugs on the official GitHub repository, located at: https://www.github.com/domiluci/LiquidCrystal_NKC. Thanks!

## INSTALLATION

### ARDUINO

* **Arduino Library Manager**: 
	* The **LiquidCrystal NKC** library has been submitted to Arduino for approval, so this option will be available soon!
* **Arduino ZIP Installation**:
	* Download the **[Latest ZIP Release](https://github.com/domiluci/LiquidCrystal_NKC/releases)** of the **LiquidCrystal NKC** library (currently **[v0.21.302](https://github.com/domiluci/LiquidCrystal_NKC/archive/refs/tags/v0.21.302.zip)**).
	* Open your copy of the [Arduino IDE](https://www.arduino.cc/en/software). On the toolbar, click **Sketch > Include Library > Add .ZIP Library**
	* In the explorer window, navigate to the **LiquidCrystal NKC** ZIP file you just downloaded and select it.
	* You're all set! See the following information for instructions on how to include and use **LiquidCrystal NKC**.
	
### MANUAL

* **Manual Installation**:
	* Download the **[Latest ZIP Release](https://github.com/domiluci/LiquidCrystal_NKC/releases)** of the **LiquidCrystal NKC** library (currently **[v0.21.302](https://github.com/domiluci/LiquidCrystal_NKC/archive/refs/tags/v0.21.302.zip)**).
	* Extract the files of that ZIP archive somewhere that's easily accessible. You'll be moving them in a moment.
	* Open your Arduino **"libraries"** folder in **Windows Explorer**, OSX's **Finder**, or other file explorer
	* Once there, make a new folder in **"libraries"** specifically called **"LiquidCrystal_NKC"** and open it up.
	* Copy all of the files you extracted from the ZIP archive into that **"LiquidCrystal_NKC"** folder you just made.
	* The **LiquidCrystal NKC** library should automatically register with the Arduino IDE on next start or restart

## GENERAL USAGE

### INCLUDE

Including **LiquidCrystal NKC** in an Arduino sketch:
	
* Add `#include <Wire.h>` and `#include <LiquidCrystal_NKC.h>` to the top of your `.ino` or `.pde` file.
* Or go to **Sketch > Include Library > Wire** and **Sketch > Include Library > LiquidCrystal NKC**

### CONSTRUCTOR

**Format:** LC_NKC lcd(Interface, I2C Address/Baud Rate, LCD Columns, LCD Rows)

Ex: `LC_NKC lcd(I2C, 0x28, 20, 4);`

Ex: `LC_NKC lcd(RS232, 9600, 20, 4);`

### COMMANDS
* **LiquidCrystal Compatible Commands:**
	* Initialize the LCD module: `.init()` or `.begin()`
	* Turn the display ON/OFF: `.display()` or `.noDisplay`
	* Turn the backlight ON/OFF: `.backlight()` or `.noBacklight()`
	* Clear the entire display: `.clear()`
	* Reset the cursor to 0, 0: `.home()`
	* Set the cursor's position: `.setCursor(column, row)`
	* Write to the LCD display: `.write()`
	* Print a char or string:  `.print()`
	* Store a unique character: `.createChar()`
	* Set cursor visibility: `.cursor()` and `.noCursor()`
	* Blinking Cursor ON/OFF: `.blink()` and `.noBlink()`
	* Shift entire display LEFT: `.scrollDisplayLeft()`
	* Shift entire display RIGHT: `.scrollDisplayRight()`

* **Alias and Other Commands:**
	* Turn the display ON/OFF: `.on()` or `.off()`
	* Turn the backlight ON/OFF: `.setBacklight(HIGH or LOW)`
	* Set backlight brightness: `.setBacklightBrightness(1 to 8)`
	* Set the display's contrast: `.setContrast(1 to 50)`
	* Clear a single character: `.clear(column, row)`
	* Clear several characters: `.clear(start column, end column, row)`
	* Clear an entire line/row: `.clear(row)`
	* Deprecated print command: `.printstr()`
	* Set cursor visibility: `.cursorOn()` and `.cursorOff()`
	* Blinking cursor ON/OFF: `.blinkOn()` and `.blinkOff()`
	* Blinking cursor ON/OFF: `.blink(true)` and `.blink(false)`
	* Move cursor LEFT/RIGHT once: `.left()` or `.right()`
	* Move cursor L/R by "columns": `.left(columns)` or `.right(columns)`
	* Backspace the cursor: `.backspace()`
	* Shift the entire LCD once: `.shiftLeft()` and `.shiftRight()`
	* Shift entire LCD by "columns": `.shiftLeft(columns)` and `.shiftRight(columns)`
	* Shift entire LCD LEFT by "columns": `.scrollDisplayLeft(columns)`
	* Shift entire LCD RIGHT by "columns": `.scrollDisplayRight(columns)`

	
## EXAMPLES

### HELLO WORLD

The **Hello World** example sketch for Arduino provide a foundation of basic commands to build on with the **Full Demo** sketch.

* **[Hello World Arduino Example Sketch: I2C Version](https://github.com/domiluci/LiquidCrystal_NKC/blob/main/examples/HelloWorld_I2C/HelloWorld_I2C.ino)**
* **[Hello World Arduino Example Sketch: RS232 Version](https://github.com/domiluci/LiquidCrystal_NKC/blob/main/examples/HelloWorld_RS232/HelloWorld_RS232.ino)**

### FULL DEMO

The **Full Demo** sketch builds on the basics of the **Hello World** sketch while demonstrating advanced commands and alternate uses.

* **[Full Demo Arduino Example Sketch: I2C Version](https://github.com/domiluci/LiquidCrystal_NKC/blob/main/examples/FullDemo_I2C/FullDemo_I2C.ino)**
* **[Full Demo Arduino Example Sketch: RS232 Version](https://github.com/domiluci/LiquidCrystal_NKC/blob/main/examples/FullDemo_RS232/FullDemo_RS232.ino)**

## WHAT'S NEXT

Currently, an expanded **LiquidCrystal** library is in development that will combine support for all LCD displays, including this NKC Serial LCD display. A universal LCD library will not only make it easier to switch between different LCD displays while eliminating time wasted on reconfiguring and recoding projects, but it will also create a standardized set of commands for all LCD displays of all interface types. Not to mention expand on all current commands, providing easier, simpler functionality with more power and flexibility, all while requiring less code to implement and execute, especially for advanced commands.

As for this **LiquidCrystal NKC** library, it will continue to be updated and maintained, even after completion of the expanded **LiquidCrystal** library. More additions will be coming soon. So make sure you keep your copy of the **LiquidCrystal NKC** library up-to-date to score on all those fresh features ASAP. And stay tuned to the other repositories for the all new, all universal **LiquidCrystal** library coming soon!

## DONATIONS

The **LiquidCrystal NKC** library and associated support will *always* be free of charge and readily available to all. But finances are a crucial necessity for the maintenance and upkeep of this library, and those finances come 100% in the form of donations from the community. So, if it isn't too much to ask, please consider donating to support this work and help it grow and blossom into something great! It doesn't need to be much. Maybe enough for a cup of coffee, or even some leftover change from the living room couch cushions. Every little bit helps, and it will *always* be appreciated more than words can express!

* **BTC Donations Can Be Sent To: *1DCXaqhH595MKewoymTDHqpuCxkp7ZGQ4F***

##

#### A big **thank you** to you all for your support and use of the **LiquidCrystal NKC** library for the Arduino IDE!
