# LiquidCrystal NKC for Arduino IDE

[![GitHub release (latest by date including pre-releases)](https://img.shields.io/github/v/release/domiluci/LiquidCrystal_NKC?label=Release&display_name=tag&include_prereleases)](https://github.com/domiluci/LiquidCrystal_NKC/releases)
[![GitHub](https://img.shields.io/github/license/domiluci/LiquidCrystal_NKC?label=License)](https://github.com/domiluci/LiquidCrystal_NKC/blob/main/LICENSE)
[![Arduino 2.0](https://img.shields.io/badge/Arduino%202.0-Ready-brightgreen)](https://www.arduino.cc/en/software#experimental-software)
[![Donate](https://img.shields.io/badge/Donate-BTC-f7931a?logo=bitcoin)](https://i.ibb.co/QQ4hSnN/CA-BTC-DL.png)
[![Donate](https://img.shields.io/badge/Donate-BCH-0ac18e?logo=bitcoincash)](https://i.ibb.co/DW9gXPN/BP-BCH-DL.png)
[![Donate](https://img.shields.io/badge/Donate-LTC-a6a9aa?logo=litecoin)](https://i.ibb.co/G2y9GXh/BP-LTC-DL.png)
[![Donate](https://img.shields.io/badge/Donate-ETH-434976?logo=ethereum)](https://i.ibb.co/wrbMGZN/BP-ETH-DL.png)

![Hello World Example](https://i.ibb.co/HYcRqPY/Hello-World-2.jpg)

## DESCRIPTION

While not very mainstream, the **[Longtech & NKC Electronics Serial LCD display module](http://media.nkcelectronics.com/datasheet/LCM2004SD-NSA-FBW.pdf)** boasts a myriad of features over and above the generic **PCF8574** and **MCP23017** I2C backpacks typically used to simplify 4-bit & 8-bit LCD connections, such as the capability to command the display not just via I2C but also over RS232 (with just a single wire), as well as over an everyday SPI bus. This NKC LCD also provides completely digital control over the brightness and contrast, doing away with trim pots for contrast adjustment, and providing backlight settings beyond just "ON" and "OFF".

But the bragging rights go beyond the mere NKC display itself. This **LiquidCrystal NKC** library, designed by professional engineering scientist and developer of the groundbreaking Neo Leaf load control system, **[Dominic Luciano](https://www.github.com/domiluci)**, is built to work with the same commands as the **LiquidCrystal** and **LiquidCrystal I2C** libraries, but it also retains alias commands to remain compatible with the original **SerialLCD** library. So little to no code will require rewriting or reworking.

However, many extensions to the basic commands were integrated into this **LiquidCrystal NKC** library. And there are many future additions and expansions planned, so make sure to keep your **LiquidCrystal NKC** library up-to-date to take advantage of all those features!

**NOTE:** This is currently a *"Version 0"* beta release. As such, some features are still being developed and perfected, and therefore may not work properly or as expected. Please make sure to post and report all bugs on the [official GitHub repository](https://www.github.com/domiluci/LiquidCrystal_NKC). Thanks!

### LICENSE

The **LiquidCrystal NKC** library, copyright (C) 2021-2022 Dominic M. Luciano & Nox Labs, is licensed under the **[GNU Lesser General Public License v3.0 (GNU LGPLv3)](https://www.gnu.org/licenses/lgpl-3.0)**, and as such is free for all to use for any purpose, inluding commercial and for profit use. However, it is humbly asked that the original source code, copyright information, and license be disclosed and included in all derivative works, and that all changes made over and above the original source code be documented and disclosed in those derivative works. In short, it would just mean a lot if credit was given when using the **LiquidCrystal NKC** library for Arduino IDE as word-of-mouth is the only way people will ever know this library exists for their use. Thank you all so very much!

## INSTALLATION

### ARDUINO

* **Arduino Library Manager**: 
	* Open your copy of the [Arduino IDE](https://www.arduino.cc/en/software). Go to **Sketch > Include Library > Manage Libraries**
	* Search for **LiquidCrystal NKC** and click **Install**
	* It's that easy! See the following information for instructions on how to include and use **LiquidCrystal NKC**.
* **Arduino ZIP Installation**:
	* Download the **[Latest ZIP Release](https://github.com/domiluci/LiquidCrystal_NKC/releases)** of the **LiquidCrystal NKC** library.
	* Open your copy of the [Arduino IDE](https://www.arduino.cc/en/software). On the toolbar, click **Sketch > Include Library > Add .ZIP Library**
	* In the explorer window, navigate to the **LiquidCrystal NKC** ZIP file you just downloaded and select it.
	* You're all set! See the following information for instructions on how to include and use **LiquidCrystal NKC**.
	
### MANUAL

* **Manual Installation**:
	* Download the **[Latest ZIP Release](https://github.com/domiluci/LiquidCrystal_NKC/releases)** of the **LiquidCrystal NKC** library.
	* Extract the files of that ZIP archive somewhere that's easily accessible. You'll be moving them in a moment.
	* Open your Arduino **"libraries"** folder in **Windows Explorer**, OSX's **Finder**, or other file explorer
	* Once there, make a new folder in **"libraries"** specifically called **"LiquidCrystal_NKC"** and open it up.
	* Copy all of the files you extracted from the ZIP archive into that **"LiquidCrystal_NKC"** folder you just made.
	* The **LiquidCrystal NKC** library should automatically register with the Arduino IDE on next start or restart

## GENERAL USE

### CONNECTIONS

* **I2C LCD Connection to Arduino Uno/Nano**
	* LCD Pin 2 [VSS] -> Arduino GND
	* LCD Pin 3 [VDD] -> Arduino +5V
	* LCD Pin 7 [SCL] -> Arduino A5 [SCL]
	* LCD Pin 8 [SDA] -> Arduino A4 [SDA]
	
* **RS232 LCD Connection to Arduino Uno/Nano**
	* LCD Pin 1 [RXD] -> Arduino D1 [TXD]
	* LCD Pin 2 [VSS] -> Arduino GND
	* LCD Pin 3 [VDD] -> Arduino +5V
* **SPI LCD Connection to Arduino Uno/Nano**
	* LCD Pin 2 [VSS] -> Arduino GND
	* LCD Pin 3 [VDD] -> Arduino +5V
	* LCD Pin 5 [SPISS] -> Arduino D10 [SS or CS]
	* LCD Pin 6 [SDO] -> Arduino D11 [MOSI]
	* LCD Pin 7 [SCK] -> Arduino D13 [SCK]
	* LCD Pin 8 [SDI] -> Arduino D12 [MISO]
	
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
	* Send a direct HD47780 command: `.command(value)`
	* Initialize the LCD module: `.begin()` or `.init()`
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
	
* **LCD API 1.0 Compatible Commands**
	* Send a direct HD47780 command: `.command(value)`
	* Turn the pixels/backlight ON/OFF: `.on()` or `.off()`
	* Initialize the LCD module: `.init()`
	* Set backlight brightness: `.setBacklight(0 to 255)`
	* Set the display's contrast: `.setContrast(0 to 255)` *(Default = 200)*
	* Clear the entire display: `.clear()`
	* Write to the LCD display: `.write()`
	* Print a char or string:  `.print()`
	* Deprecated print command: `.printstr()`

* **Alias and Other Commands:**
	* Turn display's pixels ON/OFF: `.displayOn()` and `.displayOff()`
	* Set backlight brightness: `.setBacklightBrightness(0 to 255)`
	* Clear a single character: `.clear(column, row)`
	* Clear several characters: `.clear(start column, end column, row)`
	* Clear an entire line/row: `.clear(row)`
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

### SHORT TERM

One of the biggest goals of the **LiquidCrystal NKC** library for the Arduino IDE is to be as compatible as possible with existing libraries, such as with the **LiquidCrystal** and **SerialLCD** parent libraries that **LiquidCrystal NKC** was born from. So to expand on that compatibility even more so that users migrating from other libraries can simply "plug-n-play", **LiquidCrystal NKC** is in the process of being made as [**LCD API 1.0**](https://playground.arduino.cc/Code/LCDAPI/) compliant as possible. This means less hassle when switching from one display and library to the **LiquidCrystal NKC** and **NKC Electronics** serial LCD display module, and less rewriting and redesigning to switch back, not that you'll want to, *of course*! So make sure to keep your copy of **LiquidCrystal NKC** up-to-date to capitalize on all the features being added each Friday these coming weeks, especially while all the kinks are getting ironed out in this "Version 0" release.

### LONG TERM

Currently, an expanded **LiquidCrystal** library is in development that will combine support for all LCD displays, including this NKC Serial LCD display. A universal LCD library will not only make it easier to switch between different LCD displays while eliminating time wasted on reconfiguring and recoding projects, but it will also create a standardized set of commands for all LCD displays of all interface types. Not to mention expand on all current commands, providing easier, simpler functionality with more power and flexibility, all while requiring less code to implement and execute, especially for advanced commands.

As for this **LiquidCrystal NKC** library, it will continue to be updated and maintained, even after completion of the expanded **LiquidCrystal** library. More additions will be coming soon. So make sure you keep your copy of the **LiquidCrystal NKC** library up-to-date to score on all those fresh features. And stay tuned to the other [repositories](https://github.com/domiluci?tab=repositories) for the all new, all universal **LiquidCrystal** library coming soon!

## DONATIONS

The **LiquidCrystal NKC** library and associated support will *always* be free of charge and readily available to all, no matter what may come. But finances are a crucial necessity for the maintenance and upkeep of this library, and those finances come 100% in the form of donations from the community. So, if it isn't too much to ask, please consider donating to support this work and help it grow and blossom into something great! It doesn't need to be much. Maybe enough for a cup of coffee, or even some leftover change from the living room couch cushions. Every little bit helps, and it will *always* be appreciated more than words can express!

* **Bitcoin (BTC) Donations Can Be Sent To: *35BY9KNc1TASpqduMuqcgfGo6YCm5co27y*** **([QR](https://i.ibb.co/QQ4hSnN/CA-BTC-DL.png))**
* **Bitcoin Cash (BCH) Donations Can Be Sent To: *qq0t955cudgk4w0fuykys3008wfms5xkwyurkfqwtn*** **([QR](https://i.ibb.co/DW9gXPN/BP-BCH-DL.png))**
* **Litecoin (LTC) Donations Can Be Sent To: *ltc1qzk32fz5020yd36n72kz5vqckup0pka6x8s8fsf*** **([QR](https://i.ibb.co/G2y9GXh/BP-LTC-DL.png))**
* **Ethereum (ETH) Donations Can Be Sent To: *0x6F798f6EdAC45fEC1c3B3195EFBC741B210b4CCb*** **([QR](https://i.ibb.co/wrbMGZN/BP-ETH-DL.png))**

##

#### A big **thank you** to you all for your support and use of the **LiquidCrystal NKC** library for the Arduino IDE!
