# CHANGE LOG

The official and complete change log of the **LiquidCrystal NKC** library for the Arduino IDE.

## VERSION 0

* **v0.21.316** (November 12th, 2021)
	* Changed value of `I2C_SLOW` from `10000` (10kHz) to `50000` (50kHz) as it broke I2C functionality of the LCD when used
	* `on()` and `off()` now turn the pixels *and* backlight **ON** or **OFF**, and are LCD API 1.0 compliant
	* The `setBacklight()` function now accepts a value from 0-255, and therefore is LCD API 1.0 compliant.
	* The `setContrast()` function now accepts a value from 0-255, and therefore is LCD API 1.0 compliant.
	* The **new** `displayOn()` and `displayOff()` commands turn *just the pixels* **ON** or **OFF**
	* Combined all `delayMicroseconds(I2CDELAY)` calls to just one after `Wire.endTransmission()` in `LiquidCrystal_NKC.cpp`
	* Removed unneeded inclusions of `delayMicroseconds(RS232DELAY)` in `LiquidCrystal_NKC.cpp`as they *may* break functionality
	* Further increased the command responsiveness of I2C and RS232 command functions in `LiquidCrystal_NKC.cpp`
	* Resolved the formatting issues of `LiquidCrystal_NKC.h` and `LiquidCrystal_NKC.cpp`
	* Updated the content of **keywords.txt**
	* Updated the content of **library.json**, and **library.properties**
	* Updated the **Commands** and **What's Next** portion of the **[README.md](https://github.com/domiluci/LiquidCrystal_NKC/blob/main/README.md)** file
	* Temporarily removed the **compiled** examples folders to add an auto-compiler to the repository

* **v0.21.309** (November 5th, 2021)
	* Modified variable types to optimize and reduce memory consumption
	* Fixed the overflow warnings for the I2C clock speed constants
	* Increased I2C command response speed by 200%
	* Revised the format and content of **keywords.txt**
	* Revised the content of **library.json**, and **library.properties**
	* Added **[CHANGELOG.md](https://github.com/domiluci/LiquidCrystal_NKC/blob/main/CHANGELOG.md)** to the repository; the official change log
	* Added **Connections** information for Uno/Nano to the **[README.md](https://github.com/domiluci/LiquidCrystal_NKC/blob/main/README.md)** file
	* Added **[LICENSE](https://github.com/domiluci/LiquidCrystal_NKC/blob/main/LICENSE)** file, licensing **LiquidCrystal NKC** under **[GNU LGPLv3](https://www.gnu.org/licenses/lgpl-3.0)**
	
* **v0.21.302** (October 29th, 2021)
	* Official library release and initial GitHub commit
