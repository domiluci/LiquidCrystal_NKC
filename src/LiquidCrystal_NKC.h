////////////////////////////////////////////////////////////////////////////////////////////////////
// LiquidCrystal NKC
// Version 0.21.316 (Nov. 12th, 2021)
// Developed by Dominic Luciano
//
// An Arduino library for the NKC Electronics Serial LCD Display running in RS232, I2C, or SPI mode.
// Adapted from the original "SerialLCD" library by NKC Electronics and reworked for compatibility
// with the "LiquidCrystal" family to allow seamless transition between libraries and LCD displays.
//
// Date Codes Generated By: https://www.epochconverter.com/daynumbers
//
// DEFAULT CONNECTION GUIDE ////////////////////////////////////////////////////////////////////////
//
// RS232 (UART) INTERFACE:
// LCD PIN 1 -> ARDUINO UNO DIGITAL PIN 1 [TXD] (or any SoftSerial library compatible pin)
//
// I2C INTERFACE:
// LCD PIN 7 -> ARDUINO UNO ANALOG PIN 5 [SCL]
// LCD PIN 8 -> ARDUINO UNO ANALOG PIN 4 [SDA]
//
// SPI INTERFACE:
// LCD PIN 5 -> ARDUINO UNO DIGITAL PIN 10 [SS or CS]
// LCD PIN 6 -> ARDUINO UNO DIGITAL PIN 11 [MOSI]
// LCD PIN 7 -> ARDUINO UNO DIGITAL PIN 13 [SCK]
// LCD PIN 8 -> ARDUINO UNO DIGITAL PIN 12 [MISO] (Not Necessary)
//
// USAGE:
// Please see the examples in the "examples" folder of this library distibution, or through the
// library examples section of the Arduino IDE. The README file also contains instructions for
// general usage of this library. Enjoy!
//
// Feel free to browse the GitHub repository for this library, or start a discussion at:
// https://www.github.com/domiluci/LiquidCrystal_NKC
//
// CHANGE LOG //////////////////////////////////////////////////////////////////////////////////////
//
// 21.302: Initial Release and GitHub Commit of Entire LiquidCrystal NKC library v0.21.302
// 21.309: Improved I2C Responsiveness and Variable Memory Use. Fixed Overflow Warnings.
// 21.316: Fixed bug when changing clock speed to 10kHz. I2C_SLOW is now 50000. Removed extra delays
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef LiquidCrystal_NKC_h
#define LiquidCrystal_NKC_h

// Include files
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <Wire.h>

// #include "Print.h"

// VALUES: Minimums & Maximums
#define MIN_BRIGHTNESS			0
#define MAX_BRIGHTNESS			8
#define SCALE_BRIGHTNESS    28
#define VALUE_OUT_OF_RANGE	1
#define MIN_CONTRAST				0
#define DEF_CONTRAST        40
#define MAX_CONTRAST				50
#define SC_DEF_CONTRAST     200
#define SCALE_CONTRAST      5
#define MAX_STRLEN					40

// INTERFACE: Interface Values
#define RS232								1
#define I2C									2
#define SPI									3

// RS232: Baud Rate Parameters
#define BAUD_300						1
#define BAUD_1200						2	
#define BAUD_2400						3	
#define BAUD_9600						4	
#define BAUD_14400					5	
#define BAUD_19200					6	
#define BAUD_57600					7	
#define BAUD_115200					8

// I2C: Supported Clock Rates
#define I2C_SLOW						50000		// 50kHz
#define I2C_STANDARD				100000	// 100kHz
#define I2C_FAST						400000	// 400kHz

// CHARACTERS: Custom Constants
#define NUM_CUSTOM_CHARS		8
#define CUSTOM_CHAR_SIZE		8

// COMMANDS: 
// NKC LCD Hex Commands
#define ON									0x41
#define OFF									0x42
#define SETCURSOR						0x45
#define HOME								0x46
#define CURSOR_ON						0x47
#define CURSOR_OFF					0x48
#define LEFT								0x49
#define RIGHT								0x4A
#define BLINK_ON						0x4B
#define BLINK_OFF						0x4C
#define BACKSPACE						0x4E
#define CLEAR								0x51
#define SETCONTRAST					0x52
#define SETBLBRIGHTNESS			0x53
#define LOADCUSTOMCHAR			0x54
#define SHIFTLEFT						0x55
#define SHIFTRIGHT					0x56
#define CHANGEBAUDRATE			0x61
#define CHANGEI2CADDRESS		0x62
#define DISPLAYVERSION			0x70
#define DISPLAYBAUDRATE			0x71
#define DISPLAYI2CADDRESS		0x72
#define COMMAND							0xFE

// DELAYS: In Microseconds
#define RS232DELAY					50		// 50us (0.05ms)
#define I2CDELAY						100		// 100us (0.1ms)
#define SPIDELAY						5			// 5us (0.005ms)
#define CLEARDELAY					200		// 200us (0.2ms)

class LC_NKC : public Print {

public: 

  LC_NKC(uint8_t interface, uint16_t parameter, uint8_t num_col, uint8_t num_lines);
	  
  void command(uint8_t value);	// LiquidCrystal Compatible
  void begin();									// LiquidCrystal Compatible
  void init();									// LiquidCrystal Compatible
  virtual size_t write(uint8_t);
  void clear();									// LiquidCrystal Compatible
  void clear(uint8_t col, uint8_t row);
  void clear(uint8_t start_col, uint8_t end_col, uint8_t row);
  void clear(uint8_t row);
  void home();									// LiquidCrystal Compatible
  void on();
  void off();
  void display();								// LiquidCrystal Compatible
  void noDisplay();							// LiquidCrystal Compatible
  void displayOn();
  void displayOff();
  void cursorOn();
  void cursorOff();
  void cursor();								// LiquidCrystal Compatible
  void noCursor();							// LiquidCrystal Compatible
  void blinkOn();
  void blinkOff();
  void blink(bool isOn);
  void blink();									// LiquidCrystal Compatible
  void noBlink();								// LiquidCrystal Compatible
  void left();
  void right();
  void left(uint8_t positions, uint8_t delay_ms);
  void right(uint8_t positions, uint8_t delay_ms);
  void backspace();
  void shiftLeft();
  void shiftRight();
  void shiftLeft(uint8_t positions, uint8_t delay_ms);
  void shiftRight(uint8_t positions, uint8_t delay_ms);
  void scrollDisplayLeft();			// LiquidCrystal Compatible
  void scrollDisplayRight();		// LiquidCrystal Compatible
  void scrollDisplayLeft(uint8_t positions, uint8_t delay_ms);
  void scrollDisplayRight(uint8_t positions, uint8_t delay_ms);
  void displayVersion();
  void displayBaudRate();
  void displayI2CAddress();
  void changeBaudRate(unsigned char baud);
  void changeI2CAddress(unsigned char addr);
  void changeI2CClock(uint32_t clock_rate);
 
  // Print & LCD Visual Controls
  void print(const String inputStr);						// Created to "print" and handle "String" inputs to retain LC lib compatibility
  void print(const char inputChar[]);						// Included to "print" and handle "char" inputs to retain lib compatibility
  void printstr(const String inputStr);					// Alias to "print()". Included for compatibility when switching from other libraries
  void printstr(const char inputChar[]);				// Alias to "print()". Included for compatibility when switching from other libraries
  void setCursor(uint8_t col_num, uint8_t row_num);
  void createChar(unsigned char char_num, unsigned char *rows);
	void setBacklight(uint8_t new_val);						// Included to activate/deactivate LCD backlight and maintain LC library compatibility
  void setBacklightBrightness(uint8_t new_val);	// Alias to "setBacklight()". Included to maintain SerialLCD library compatibility
  void backlight();															// Included to activate LCD backlight and maintain LC library compatibility
  void noBacklight();														// Included to deactivate LCD backlight and maintain LC library compatibility
  void setContrast(uint8_t new_val);
	
private:	

};
#endif