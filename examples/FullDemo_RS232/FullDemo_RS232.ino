// OVERVIEW //////////////////////////////////////
// LiquidCrystal NKC: Library for Arduino
// Full Arduino IDE Demonstration Sketch
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

// General Variables //
// Strings We'll Use Shortly
String ChangingToday = "Changing Today";
String EvolvingTomorrow = "Evolving Tomorrow";

// Custom Character Arrays //
byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

void setup() {
  
  // Initialize LCD Module
  lcd.init();
  
  // Turn On LCD Backlight
  lcd.backlight();
  // Or Use: lcd.setBacklight(HIGH);  
  
  // Create New Character From Earlier Byte Array
  // We'll Use This Later On
  lcd.createChar(0, heart);

}

void loop() {
  
  // Set Cursor to "Col 0, Row 0" (1st Col, 1st Row)
  lcd.home(); // Or Use: lcd.setCursor(0, 0);

  // Clear The Entire LCD
  lcd.clear();

  // Set Cursor to "Col 4, Row 1" (5th Col, 2nd Row)
  lcd.setCursor(4, 1);

  // Print "Hello, World" to the LCD
  lcd.print("Hello, World");
  delay(2000);

  // Clear LCD From Cols 4 to 16 on Row 1 (5th-17th Column, 2nd Row)
  lcd.clear(4, 16, 1);
  delay(250);

  // Display the LCD Firmware's Version
  lcd.displayVersion();
  delay(2000);

  // Clear The Entire LCD
  lcd.clear();
  delay(250);

  // Display the LCD's Current I2C Address
  lcd.displayI2CAddress();
  delay(2000);

  // Clear Entire LCD
  lcd.clear();
  delay(250);  
  
  // Set Cursor Back to "0, 0"
  lcd.home();  

  // Print Some Text...
  lcd.print("LiquidCrystal NKC");
  
  // Set Cursor To "Col 0, Row 1" (1st Col, 2nd Row)
  lcd.setCursor(0, 1);
  lcd.print("By Dominic Luciano");
  delay(2000);
  
  // Set Cursor To "Col 0, Row 2" (1st Col, 3rd Row)
  lcd.setCursor(0, 2);
  lcd.print("GitHub.com/DomiLuci");
  delay(2000);  
    
  // Set Cursor To "0, 2"
  lcd.setCursor(0, 3);

  //Turn LCD Blinking Cursor On
  lcd.blink();
  // or use: lcd.blinkOn();
  // or use: lcd.blink(true);
  
  // And For My Next Trick...
  // Making Text Appear Behind A Blinking Cursor
  for (byte i = 0; i <= 18; i++) {
    // Print Each Letter of the String At Index "i"      
    lcd.print(String(ChangingToday.charAt(i)));
    // Cursor Must Be Reset After Each Letter to Col "i"
    lcd.setCursor(i, 3);
    // Move the Blinking Cursor One Spot Right Every 100ms   
    lcd.right();
    delay(100);
  }  
  delay(1000);
  
  // Making Text Appear Behind A Blinking Cursor  
  // ...In Reverse
  for (byte i = 19; i <= 19; i--) {
    // Print Each Letter of the String At Index "i"      
    lcd.print(String(EvolvingTomorrow.charAt(i)));
    // Cursor Must Be Reset After Each Letter to Col "i"
    lcd.setCursor(i, 3);
    // Move the Blinking Cursor One Spot Left Every 100ms   
    lcd.left();
    delay(100);
  }
    
  //Turn LCD Blinking Cursor Off
  lcd.noBlink();
  // Or Use: lcd.blinkOff();
  // Or Use: lcd.blink(false);
  delay(2000);

  // Drop the Contrast to "0"
  lcd.setContrast(0);
  
  // Clear Rows 0, 1, 2, and 3 (1st, 2nd, 3rd, and 4th Row)
  lcd.clear(0);
  lcd.clear(1);
  lcd.clear(2);
  lcd.clear(3);
  // Reset Cursor to "0, 3"  
  lcd.setCursor(2, 1);
  // Print "Now Let's Scroll"
  lcd.print("Now Let's Scroll");

  // Fade The Contrast In...
  for (byte i = 0; i <= 40; i++) {
    // Set Contrast to "i"
    lcd.setContrast(i);
    delay(100);
  }
  delay(2000);
  
  // Set Cursor to "20, 1" (21st Column of 2nd Row, Sort Of)
  lcd.setCursor(20, 1);
  // Shift ALL Text Left 2 Positions, Once Every 100ms...
  // The Easy Way This Time
  lcd.scrollDisplayLeft(1, 100);
  // Or Use: lcd.shiftLeft(14, 100);
  delay(250);
  
  byte col = 21; // Variable For Next Loop
  // Now Shift ALL Text Right 20 Positions, Once Every 100ms...
  // The Harder Way
  for (byte i = 0; i <= 20; i++) {
    delay(100);
    lcd.scrollDisplayRight();
    // Or Use: shiftRight();
    // Clear Each Character Before It Re-enters Frame
    lcd.clear(col, 1);  col--;
  }
  delay(2000);
  
  // Clear The Entire LCD... 
  // Also Resetting The LCD Shift
  lcd.clear();

  // Set Cursor to "3, 1" (4th Column, 2nd Row)
  lcd.setCursor(3, 1);
  // Print Some Thank You Text
  lcd.print("Thanks 4 The ");
  // Show That Heart We Made Earlier  
  lcd.write((byte)0);
  delay(2000);
  
  //Clean Up The Entire LCD Before Loop Reset
  lcd.clear();
  delay(1500);  
}