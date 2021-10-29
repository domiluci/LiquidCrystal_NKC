////////////////////////////////////////////////////////////////////////////////////////////////////
// LiquidCrystal NKC
// Version 0.21.302 (Oct 29th, 2021)
// Developed by Dominic Luciano
//
// An Arduino library for the NKC Electronics Serial LCD Display running in RS232, I2C, or SPI mode.
// Adapted from the original "SerialLCD" library by NKC Electronics and reworked for compatibility
// with the "LiquidCrystal" family to allow seamless transition between libraries and LCD displays.
// 
// DEFAULT CONNECTION GUIDE ////////////////////////////////////////////////////////////////////////
// RS232 (UART) INTERFACE:
// LCD PIN 1 [RX] -> ARDUINO UNO DIGITAL PIN 1 [TX] (or any SoftSerial library compatible pin)
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
////////////////////////////////////////////////////////////////////////////////////////////////////

// Include the Library's ".h" File
#include "LiquidCrystal_NKC.h"

// Default LCD Lines and Columns (Do NOT Change Here!) 
int g_num_lines = 2;				// Default: 2 Lines/Rows
int g_num_col = 16;					// Default: 16 Columns

// Default LCD Interface, I2C Address, I2C Clock, RS232 Baud Rate, and SPI Transfer Mode
int g_interface = 0; 				// 0 = Serial/RS232; 1 = I2C; 2 = SPI
int g_i2c_address = 0x28;			// Default for NKC I2C LCD = 0x28
int g_i2c_clock = I2C_STANDARD;		// I2C_SLOW = 10K; I2C_STANDARD = 100K; I2C_FAST = 400K
int g_baudrate = 9600;				// Default NKC RS232 Baud Rate is 9600bps
int g_txPin = 1;
int g_sspin = 10;
int g_sclk = 13;
int g_mosi = 11;
int g_miso = 12;

// Hexadecimal Index for Controlling the LCD's Cursor by Line & Column
// NKC Electronics Specific Index
int g_index[4] = { 0x00, 0x40, 0x14, 0x54 };

////////////////////////////////////////////////////////////////////////////////////////////////////
// CONSTRUCTOR /////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

// This is the Default Constructor //
// RS232 Example: "LC_NKC lcd(RS232, 9600, 20, 4);"
// I2C Example: "LC_NKC lcd(I2C, 0x28, 20, 4);"
// SPI Example: This functionality is still under development
LC_NKC::LC_NKC (int interface, int parameter, int num_col, int num_lines)	{
	
	g_num_lines = num_lines;
	g_num_col = num_col;
	g_interface = interface;

	switch (g_interface) {
		case RS232:
			g_baudrate = parameter;
			break;
		case I2C:
			g_i2c_address = parameter;
			break;
		case SPI:
			g_sspin = parameter;
			break;
	}
	
	// Default to 2 lines/rows if less than 1 or greater than 4
	if (g_num_lines < 1 || g_num_lines > 4) {
		g_num_lines = 2;
	}
	
	// Default to 16 columns if less than 1 or greater than 40
	if (g_num_col < 1 || g_num_col > 40) {
		g_num_col = 16;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// HARDWARE LEVEL FUNCTIONS ////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

// INTERFACE TRANSFER FUNCTIONS ////////////////////////////////////////////////////////////////////

// SPI Transfer That Uses Bitbanging to Send Data 
void spitransfer(unsigned char var) {
	int i;

	digitalWrite(g_sspin, LOW);
	digitalWrite(g_sclk, HIGH);

	for (i=1; i<=8; i++) {
		digitalWrite(g_sclk, LOW);
		delayMicroseconds(SPIDELAY);
		if (var & 0x80)
			digitalWrite(g_mosi, HIGH);
		else
			digitalWrite(g_mosi, LOW);
		var <<= 1;
		digitalWrite(g_sclk, HIGH);
		delayMicroseconds(SPIDELAY);
		}
	digitalWrite(g_sspin, HIGH);
}

// COMMAND FUNCTIONS ///////////////////////////////////////////////////////////////////////////////

// Sends a Specific Hex Command to the LCD for Execution
void sendcommand(unsigned char command) {
	switch (g_interface) {
		case RS232: 
			Serial.write(0xFE);
			delayMicroseconds(RS232DELAY);
			Serial.write(command);
			delayMicroseconds(RS232DELAY);
			break;
		case I2C:
			Wire.beginTransmission(g_i2c_address);
			Wire.write(0xFE);
			delayMicroseconds(I2CDELAY);
			Wire.write(command);
			delayMicroseconds(I2CDELAY);
			Wire.endTransmission();
			delayMicroseconds(I2CDELAY);
			break;
		case SPI:
			spitransfer(0xFE);
			delayMicroseconds(SPIDELAY);
			spitransfer(command);
			delayMicroseconds(SPIDELAY);
			break;
	}
}

// Sends a Specific Command & Associated Value to LCD for Execution
void sendcommand2(unsigned char command, unsigned char value) {
	switch (g_interface) {
		case RS232: 
			Serial.write(0xFE);
			delayMicroseconds(RS232DELAY);
			Serial.write(command);
			delayMicroseconds(RS232DELAY);
			Serial.write(value);
			delayMicroseconds(RS232DELAY);
			break;
		case I2C:
			Wire.beginTransmission(g_i2c_address);
			Wire.write(0xFE);
			delayMicroseconds(I2CDELAY);
			Wire.write(command);
			delayMicroseconds(I2CDELAY);
			Wire.write(value);
			delayMicroseconds(I2CDELAY);
			Wire.endTransmission();
			delayMicroseconds(I2CDELAY);
			break;
		case SPI:
			spitransfer(0xFE);
			delayMicroseconds(SPIDELAY);
			spitransfer(command);
			delayMicroseconds(SPIDELAY);
			spitransfer(value);
			delayMicroseconds(SPIDELAY);
			break;
	}
}

// Allows the User to Send a Direct HD44780 Hex Command to the LCD Display for Execution
void LC_NKC::command(int value) {
	sendcommand2(COMMAND, value);
}

// RS232 SERIAL FUNCTIONS //////////////////////////////////////////////////////////////////////////

// Displays the Set Baud Rate for the Display
void LC_NKC::displayBaudRate(){
    sendcommand(DISPLAYBAUDRATE);
}

// Changes the RS232 Serial Baud Rate of the LCD
void LC_NKC::changeBaudRate(unsigned char baud){
    sendcommand2(CHANGEBAUDRATE, baud);
}

// I2C RELATED FUNCTIONS ///////////////////////////////////////////////////////////////////////////

// Displays the Current I2C Address of the LCD
void LC_NKC::displayI2CAddress(){
    sendcommand(DISPLAYI2CADDRESS);
}

// Changes the LCD Display's Default or Current I2C Address
void LC_NKC::changeI2CAddress(unsigned char addr){
    sendcommand2(CHANGEI2CADDRESS, addr);
}

// Allows the User to Modify the I2C Clock Speed
void changeI2CClock(int clock_rate)	{
	switch (clock_rate)	{
		case I2C_SLOW:
			Wire.setClock(I2C_SLOW);
			g_i2c_clock = I2C_SLOW;
		break;
		case I2C_STANDARD:
			Wire.setClock(I2C_STANDARD);
			g_i2c_clock = I2C_STANDARD;
		break;
		case I2C_FAST:
			Wire.setClock(I2C_FAST);
			g_i2c_clock = I2C_FAST;
		break;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// SOFTWARE LEVEL FUNCTIONS ////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

// FIRMWARE FUNCTIONS //////////////////////////////////////////////////////////////////////////////

// Displays the Firmware Version of the LCD
void LC_NKC::displayVersion(){
    sendcommand(DISPLAYVERSION);
}

// LCD INITIALIZATION FUNCTIONS ////////////////////////////////////////////////////////////////////

// Turn the NKC LCD Display "ON" or "OFF"
void LC_NKC::on()	{
    sendcommand(ON);	
}
void LC_NKC::off()	{
    sendcommand(OFF);	
}
// LiquidCrystal Compatible Versions
void LC_NKC::display()	{
    sendcommand(ON);	
}
void LC_NKC::noDisplay()	{
    sendcommand(OFF);	
}

// LiquidCrystal Compatible Functions
// Initializes the LCD Display and Defaults All Basic Values
void LC_NKC::begin() {
	init();
}
void LC_NKC::init() {
	delay(500);
	switch (g_interface) {
		case RS232:
			Serial.begin(g_baudrate);
			break;
		case I2C:
			Wire.begin();
			break;
		case SPI:
			pinMode(g_sspin, OUTPUT);
			pinMode(g_sclk, OUTPUT);
			pinMode(g_mosi, OUTPUT);
			pinMode(g_miso, INPUT);
			digitalWrite(g_sspin, HIGH);
			break;
	}
	on();
	setContrast(40);
	clear();
	blinkOff();
	cursorOff(); 
	home();
}

// BACKLIGHT & CONTRAST FUNCTIONS //////////////////////////////////////////////////////////////////

// LiquidCrystal Compatible Functions
// Turns LCD Backlight "ON" or "OFF"
void LC_NKC::backlight() {
	sendcommand2(SETBACKLIGHTBRIGHTNESS, MAX_BRIGHTNESS);
}
void LC_NKC::noBacklight() {
	sendcommand2(SETBACKLIGHTBRIGHTNESS, MIN_BRIGHTNESS);
}
void LC_NKC::setBacklight(uint8_t new_val) {
	switch (new_val) {
		
		case 0:
		noBacklight();
		break;
		
		case 1:
		backlight();
		break;
	}
}


// Set Backlight Brightness to a Specific Value
void LC_NKC::setBacklightBrightness(unsigned char new_val)
{
	if ((new_val < MIN_BRIGHTNESS)
		|| (new_val > MAX_BRIGHTNESS))
		new_val = MAX_BRIGHTNESS >> 1; // mid point value
	
	sendcommand2(SETBACKLIGHTBRIGHTNESS, new_val);
}

// Sets the Contrast of the LCD to a Specific Value
void LC_NKC::setContrast(unsigned char new_val)
{
	if ((new_val < MIN_CONTRAST)
		|| (new_val > MAX_CONTRAST))
		new_val = MAX_CONTRAST >> 1; // mid point value

	sendcommand2(SETCONTRAST, new_val);
}

// WRITE, CREATE & PRINT FUNCTIONS /////////////////////////////////////////////////////////////////

// "Writes" Data Over The Specified Interface
size_t LC_NKC::write(uint8_t value) {
	switch (g_interface) {
		case RS232: 
			Serial.write(value);
			break;
		case I2C:
			Wire.beginTransmission(g_i2c_address);
			Wire.write(value);
			Wire.endTransmission();
			break;
		case SPI:
			spitransfer(value);
			break;
	}
}


// Creates a New Character & Stores It In LCD Memory
void LC_NKC::createChar(unsigned char char_num, unsigned char *rows)
{	
	uint8_t i;
	
	switch (g_interface) {
		case RS232:
			Serial.write(0xFE);
			delayMicroseconds(RS232DELAY);
			Serial.write(LOADCUSTOMCHARACTER);
			delayMicroseconds(RS232DELAY);
			Serial.write(char_num);
			delayMicroseconds(RS232DELAY);
			Serial.write(rows, CUSTOM_CHAR_SIZE);
			delayMicroseconds(RS232DELAY);
			break;
		case I2C:
			Wire.beginTransmission(g_i2c_address);
			delayMicroseconds(I2CDELAY);
			Wire.write(0xFE);
			delayMicroseconds(I2CDELAY);
			Wire.write(LOADCUSTOMCHARACTER);
			delayMicroseconds(I2CDELAY);
			Wire.write(char_num);
			delayMicroseconds(I2CDELAY);
			Wire.write(rows, CUSTOM_CHAR_SIZE);
			delayMicroseconds(I2CDELAY);
			Wire.endTransmission();
			delayMicroseconds(I2CDELAY);
			break;
		case SPI:
			spitransfer(0xFE);
			delayMicroseconds(SPIDELAY);
			spitransfer(LOADCUSTOMCHARACTER);
			delayMicroseconds(SPIDELAY);
			spitransfer(char_num);
			delayMicroseconds(SPIDELAY);
			for (i=0; i<CUSTOM_CHAR_SIZE; i++)	{
				spitransfer(rows[i]);
				delayMicroseconds(SPIDELAY);
			}
			break;
	}
}

// LiquidCrystal Compatible Functions
// These Functions "print()" Characters to the LCD
void  LC_NKC::print(const String inputStr)	{

	int len = inputStr.length();
	
	switch (g_interface) {
		case RS232:
			for (int i = 0; i < len; i++)	{
				Serial.write(inputStr.charAt(i));
			}
			break;
		case I2C:
			Wire.beginTransmission(g_i2c_address);
			for (int i = 0; i < len; i++)	{
				Wire.write(inputStr.charAt(i));
			}
			Wire.endTransmission();
			break;
		case SPI:
		/*
			for (int i = 0; i < len; i++)	{
				spitransfer(inputStr.charAt(i));
			}
		*/
			break;
		}
}
void  LC_NKC::print(const char inputChar[])
{
	byte len;

	len = min(strlen(inputChar), MAX_STRLEN);
	switch (g_interface) {
		case RS232:
			while (len--)
				Serial.write(*inputChar++);
			break;
		case I2C:
			Wire.beginTransmission(g_i2c_address);
			while (len--)
				Wire.write(*inputChar++);
			Wire.endTransmission();
			break;
		case SPI:
			while (len--)
				spitransfer(*inputChar++);
			break;
		}
}


// These Aliases are Included for Compatibility
void  LC_NKC::printstr(const String inputStr)	{
	print(inputStr);
}
void  LC_NKC::printstr(const char inputChar[])	{
	print(inputChar);
}

// LCD CLEAR FUNCTIONS /////////////////////////////////////////////////////////////////////////////

// LiquidCrystal Compatible Function
// Clears The Entire LCD Display
void LC_NKC::clear()	{
	sendcommand(CLEAR);
	delayMicroseconds(CLEARDELAY);
}
// Clears a Single Character by "Column, Row"
void LC_NKC::clear(int col, int row)	{
	setCursor(col, row);
	print(" ");
	delayMicroseconds(CLEARDELAY);
}
// Clears Specified Columns/Characters of a Row
void LC_NKC::clear(int start_col, int end_col, int row)	{
	for (int i = 0; i <= (end_col - start_col); i++)	{
		setCursor((start_col + i), row);
		print(" ");
		delayMicroseconds(CLEARDELAY);
	}
}
// Clears the Contents of the Specified Row
void LC_NKC::clear(int row)	{
	for (int i = 0; i <= g_num_col; i++)	{
		setCursor(i, row);
		print(" ");
		delayMicroseconds(CLEARDELAY);
	}
}

// LCD CURSOR CONTROL FUNCTIONS ////////////////////////////////////////////////////////////////////

// LiquidCrystal Compatible Function
// Quick and Easy Way to Reset Cursor to "0, 0"
void LC_NKC::home(){
    sendcommand(HOME);	
}


// LiquidCrystal Compatible Function
// Uses the Hex Index To Set Cursor Position to "Column, Row"
void LC_NKC::setCursor(int col_num, int row_num){
	sendcommand2(SETCURSOR, g_index[row_num] + col_num);
}


//Turn the Underline Cursor "ON" or "OFF"
void LC_NKC::cursorOn(){
    sendcommand(CURSOR_ON);	
}
void LC_NKC::cursorOff(){
    sendcommand(CURSOR_OFF);	
}
// LiquidCrystal Compatible Versions
void LC_NKC::cursor(){
    sendcommand(CURSOR_ON);	
}
void LC_NKC::noCursor(){
    sendcommand(CURSOR_OFF);	
}


//Turn the Blinking Cursor "ON" or "OFF"
void LC_NKC::blinkOn() {
    sendcommand(BLINK_ON);	
}
void LC_NKC::blinkOff() {
    sendcommand(BLINK_OFF);	
}
void LC_NKC::blink(bool isOn) {
	if (isOn == true) {
		sendcommand(BLINK_ON);
	}
	else if (isOn == false) {
    	sendcommand(BLINK_OFF);
	}
}
// LiquidCrystal Compatible Versions
void LC_NKC::blink(){
    sendcommand(BLINK_ON);	
}
void LC_NKC::noBlink(){
    sendcommand(BLINK_OFF);	
}


//Move the Cursor Right/Left 1 Position (Or More...)
void LC_NKC::left() {
    sendcommand(LEFT);	
}
void LC_NKC::right() {
	sendcommand(RIGHT);
}
void LC_NKC::left(uint8_t positions, uint8_t delay_ms) {
    for (uint8_t i = 0; i <= positions; i++) {
		delay(delay_ms);
    	sendcommand(LEFT);
	}
}
void LC_NKC::right(uint8_t positions, uint8_t delay_ms) {
    for (uint8_t i = 0; i <= positions; i++) {
		delay(delay_ms);
    	sendcommand(RIGHT);
	}
}

//Backspace
void LC_NKC::backspace(){
    sendcommand(BACKSPACE);
}

// OTHER LCD FUNCTIONS /////////////////////////////////////////////////////////////////////////////

//Shift Display Right/Left 1 Position (Or More...)
void LC_NKC::shiftLeft() {
    sendcommand(SHIFTLEFT);
}
void LC_NKC::shiftRight() {
    sendcommand(SHIFTRIGHT);
}
void LC_NKC::shiftLeft(uint8_t positions, uint8_t delay_ms) {
    for (uint8_t i = 0; i <= positions; i++) {
		delay(delay_ms);
    	sendcommand(SHIFTLEFT);
	}
}
void LC_NKC::shiftRight(uint8_t positions, uint8_t delay_ms) {
    for (uint8_t i = 0; i <= positions; i++) {
		delay(delay_ms);
    	sendcommand(SHIFTRIGHT);
	}
}
void LC_NKC::scrollDisplayLeft(uint8_t positions, uint8_t delay_ms) {
    for (uint8_t i = 0; i <= positions; i++) {
		delay(delay_ms);
    	sendcommand(SHIFTLEFT);
	}
}
void LC_NKC::scrollDisplayRight(uint8_t positions, uint8_t delay_ms) {
    for (uint8_t i = 0; i <= positions; i++) {
		delay(delay_ms);
    	sendcommand(SHIFTRIGHT);
	}
}

// LiquidCrystal Compatible Versions
void LC_NKC::scrollDisplayLeft() {
    sendcommand(SHIFTLEFT);
}
void LC_NKC::scrollDisplayRight() {
    sendcommand(SHIFTRIGHT);
}