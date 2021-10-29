// OVERVIEW //////////////////////////////////////
// LiquidCrystal NKC: Library for Arduino
// "Hello, World!" Arduino IDE Demo Sketch
// Sketch v21.302 by Dominic M. Luciano
//
// This sketch is intended to highlight & display
// the major functions of the LiquidCrystal NKC
// library and their potential uses and usages in
// conjunction with an NKC Electronics Serial LCD
// display module running in RS232 mode
////////////////////////////////////////////////// 
// CONNECTIONS ///////////////////////////////////
// LCD PIN 1 [RXD] -> ARDUINO UNO PIN D1 [TXD]
// LCD PIN 2 [VSS] -> ARDUINO UNO GND
// LCD PIN 3 [VDD] -> ARDUINO UNO +5V
//////////////////////////////////////////////////

#include <Wire.h>
#include <LiquidCrystal_NKC.h>

// DECLARATIONS //////////////////////////////////
// Constructor & Parameters //
// Interface, Baud Rate, Columns, Rowa
LC_NKC lcd(RS232, 9600, 20, 4);

void setup() {
  
  // Initialize LCD Module
  lcd.init();
  
  // Turn On LCD Backlight
  lcd.backlight();
  // Or Use: lcd.setBacklight(HIGH);  
  
  // Set Cursor to "Col 0, Row 0" (1st Col, 1st Row)
  lcd.home(); // Or Use: lcd.setCursor(0, 0);

  // Clear The Entire LCD
  lcd.clear();

  // Print Some Text to the LCD
  lcd.print("HELLO, WORLD!");
  // Set Cursor to "Col 0, Row 1" (1st Col, 2nd Row)
  lcd.setCursor(0, 1);
  // Print Some Text to the LCD
  lcd.print("LiquidCrystal NKC");
  // Set Cursor to "Col 0, Row 2" (1st Col, 3rd Row)
  lcd.setCursor(0, 2);
  // Print Some Text to the LCD
  lcd.print("By Dominic Luciano");
  // Set Cursor to "Col 0, Row 3" (1st Col, 4th Row)
  lcd.setCursor(0, 3);
  // Print Some Text to the LCD
  lcd.print("GitHub.com/DomiLuci");

}

void loop() {
  // Program's Main Loop Code Goes Here //
}