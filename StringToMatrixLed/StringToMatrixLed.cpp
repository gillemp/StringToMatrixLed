// include core Wiring API
#include "Arduino.h"

// include this library's description file
#include "StringToMatrixLed.h"

// Constructor /////////////////////////////////////////////////////////////////
// Handles the setup of the library
StringToMatrixLed::StringToMatrixLed() {
	//Set all the pins (columns and rows) to "outputm mode"
	for (int thisPin = 0; thisPin < 8; thisPin++) {
		pinMode(col[thisPin], OUTPUT);
		pinMode(row[thisPin], OUTPUT);
	}
	//Set all the leds of the display OFF
	for (int x = 0; x < 8; x++) { digitalWrite(col[x], HIGH); }
	for (int y = 0; y < 8; y++) { digitalWrite(row[y], LOW); }
}


///// Private Methods /////////////////////////////////////////////////////////////
///// Functions only available to other functions in this library

//Check if there is a bit (set to 1) in a determinate position of a determinate byte
bool StringToMatrixLed::ifThereIsABitInThisPosition(byte b, int pos) {
	return ((b >> 7 - pos) & B1);
}

//Draws in the matrix the given array
void StringToMatrixLed::drawScreen(byte printArray[]) {
	// Execute the code row by row
	for (byte forRow = 0; forRow < 8; forRow++) {
		//Turn on the leds that have the bit = 1 in their position
		for (byte forCol = 0; forCol < 8; forCol++) {
			digitalWrite(col[forCol], !ifThereIsABitInThisPosition(printArray[forRow], forCol));
		}

		digitalWrite(row[forRow], HIGH); //turn on the whole line to see which columns are on
		delay(1); // (Set this to 50 or 100 if you want to see the multiplexing effect)
		digitalWrite(row[forRow], LOW); //turn of the whole line to get ready for the next one
	}
}

//Determines whether in an array with 8 bytes there is none in the "column" position with its corresponding bit = 1 (if the full column in the array is 0)
bool StringToMatrixLed::isTheColumnFree(byte byteArray[], int column) {
	// Execute the code row by row
	for (byte forRow = 0; forRow < 8; forRow++) {
		//Check if there is a bit = 1 in the current row at the position number "column"
		if (ifThereIsABitInThisPosition(byteArray[forRow], column)) {
			return false;
		}
	}
	//If before the end of the array there is not a bit = 1, return that there is any bit = 1 in the given column
	return true;
}

//Moves the draw one pixel tot he left
void StringToMatrixLed::moveDrawOneToLeft() {
	//shifts one bit to the left all the bytes in the "printArray" array
	for (byte i = 0; i < 8; i++) {
		printArray[i] = printArray[i] << 1;
	}
}

//Return the row number "line" of the sprite to draw the char number "chNum" in the string "str"
byte StringToMatrixLed::getArrayOfSprites(String str, int chNun, int line) {
	//Uppercase all the string (because there are not uppercased letters avaliable in this library)
	str.toUpperCase();
	//Get the char number "chNum" and saves it to the "currentChar" variable
	char currentChar = str.charAt(chNun);
	//switch to get the sprite that corresponds to the "currentChar" (and return the line number "line" of the corresponding sprite)
	switch (currentChar) {
		//All the characters that handles the library
	case 'A': { byte returnArray[] = {B01110000,B10001000,B10001000,B10001000,B11111000,B10001000,B10001000,B00000000}; return returnArray[line]; break; }
	case 'B': { byte returnArray[] = {B11110000,B10001000,B10001000,B11110000,B10001000,B10001000,B11110000,B00000000}; return returnArray[line]; break; }
	case 'C': { byte returnArray[] = {B01110000,B10001000,B10000000,B10000000,B10000000,B10001000,B01110000,B00000000}; return returnArray[line]; break; }
	case 'D': { byte returnArray[] = {B11110000,B10001000,B10001000,B10001000,B10001000,B10001000,B11110000,B00000000}; return returnArray[line]; break; }
	case 'E': { byte returnArray[] = {B11111000,B10000000,B10000000,B11110000,B10000000,B10000000,B11111000,B00000000}; return returnArray[line]; break; }
	case 'F': { byte returnArray[] = {B11111000,B10000000,B10000000,B11110000,B10000000,B10000000,B10000000,B00000000}; return returnArray[line]; break; }
	case 'G': { byte returnArray[] = {B01110000,B10001000,B10000000,B10111000,B10101000,B10001000,B01110000,B00000000}; return returnArray[line]; break; }
	case 'H': { byte returnArray[] = {B10001000,B10001000,B10001000,B11111000,B10001000,B10001000,B10001000,B00000000}; return returnArray[line]; break; }
	case 'I': { byte returnArray[] = {B10000000,B10000000,B10000000,B10000000,B10000000,B10000000,B10000000,B00000000}; return returnArray[line]; break; }
	case 'J': { byte returnArray[] = {B00010000,B00010000,B00010000,B00010000,B00010000,B10010000,B01100000,B00000000}; return returnArray[line]; break; }
	case 'K': { byte returnArray[] = {B10001000,B10001000,B10010000,B11100000,B10010000,B10001000,B10001000,B00000000}; return returnArray[line]; break; }
	case 'L': { byte returnArray[] = {B10000000,B10000000,B10000000,B10000000,B10000000,B10000000,B11111000,B00000000}; return returnArray[line]; break; }
	case 'M': { byte returnArray[] = {B10001000,B11011000,B10101000,B10101000,B10001000,B10001000,B10001000,B00000000}; return returnArray[line]; break; }
	case 'N': { byte returnArray[] = {B10001000,B10001000,B11001000,B10101000,B10011000,B10001000,B10001000,B00000000}; return returnArray[line]; break; }
	case 'O': { byte returnArray[] = {B01110000,B10001000,B10001000,B10001000,B10001000,B10001000,B01110000,B00000000}; return returnArray[line]; break; }
	case 'P': { byte returnArray[] = {B11110000,B10001000,B10001000,B11110000,B10000000,B10000000,B10000000,B00000000}; return returnArray[line]; break; }
	case 'Q': { byte returnArray[] = {B01110000,B10001000,B10001000,B10001000,B10101000,B10011000,B01111000,B00000000}; return returnArray[line]; break; }
	case 'R': { byte returnArray[] = {B11110000,B10001000,B10001000,B11110000,B10001000,B10001000,B10001000,B00000000}; return returnArray[line]; break; }
	case 'S': { byte returnArray[] = {B01110000,B10000000,B10000000,B01110000,B00001000,B00001000,B11110000,B00000000}; return returnArray[line]; break; }
	case 'T': { byte returnArray[] = {B11111000,B00100000,B00100000,B00100000,B00100000,B00100000,B00100000,B00000000}; return returnArray[line]; break; }
	case 'U': { byte returnArray[] = {B10001000,B10001000,B10001000,B10001000,B10001000,B10001000,B01110000,B00000000}; return returnArray[line]; break; }
	case 'V': { byte returnArray[] = {B10001000,B10001000,B10001000,B10001000,B10001000,B01010000,B00100000,B00000000}; return returnArray[line]; break; }
	case 'W': { byte returnArray[] = {B10001000,B10001000,B10001000,B10101000,B10101000,B11011000,B10001000,B00000000}; return returnArray[line]; break; }
	case 'X': { byte returnArray[] = {B10001000,B10001000,B01010000,B00100000,B01010000,B10001000,B10001000,B00000000}; return returnArray[line]; break; }
	case 'Y': { byte returnArray[] = {B10001000,B10001000,B01010000,B00100000,B00100000,B00100000,B00100000,B00000000}; return returnArray[line]; break; }
	case 'Z': { byte returnArray[] = {B11111000,B00001000,B00010000,B00100000,B01000000,B10000000,B11111000,B00000000}; return returnArray[line]; break; }
	case '¡': { byte returnArray[] = {B10000000,B00000000,B10000000,B10000000,B10000000,B10000000,B10000000,B00000000}; return returnArray[line]; break; }
	case '!': { byte returnArray[] = {B10000000,B10000000,B10000000,B10000000,B10000000,B00000000,B10000000,B00000000}; return returnArray[line]; break; }
	case '?': { byte returnArray[] = {B01110000,B10001000,B00001000,B00010000,B00100000,B00000000,B00100000,B00000000}; return returnArray[line]; break; }
	case '¿': { byte returnArray[] = {B00100000,B00000000,B00100000,B00010000,B00001000,B10001000,B01110000,B00000000}; return returnArray[line]; break; }
	case '+': { byte returnArray[] = {B00000000,B00100000,B00100000,B11111000,B00100000,B00100000,B00000000,B00000000}; return returnArray[line]; break; }
	case '-': { byte returnArray[] = {B00000000,B00000000,B00000000,B11110000,B00000000,B00000000,B00000000,B00000000}; return returnArray[line]; break; }
	case '#': { byte returnArray[] = {B01010000,B01010000,B11111000,B01010000,B11111000,B01010000,B01010000,B00000000}; return returnArray[line]; break; }
	case '.': { byte returnArray[] = {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B10000000,B00000000}; return returnArray[line]; break; }
	case ',': { byte returnArray[] = {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B10000000,B10000000}; return returnArray[line]; break; }
	case '1': { byte returnArray[] = {B00100000,B01100000,B10100000,B00100000,B00100000,B00100000,B11111000,B00000000}; return returnArray[line]; break; }
	case '2': { byte returnArray[] = {B01110000,B10001000,B00001000,B00110000,B01000000,B10000000,B11111000,B00000000}; return returnArray[line]; break; }
	case '3': { byte returnArray[] = {B01110000,B10001000,B00001000,B00110000,B00001000,B10001000,B01110000,B00000000}; return returnArray[line]; break; }
	case '4': { byte returnArray[] = {B00010000,B00110000,B01010000,B10010000,B11111000,B00010000,B00010000,B00000000}; return returnArray[line]; break; }
	case '5': { byte returnArray[] = {B11111000,B10000000,B11110000,B00001000,B00001000,B10001000,B01110000,B00000000}; return returnArray[line]; break; }
	case '6': { byte returnArray[] = {B01110000,B10001000,B10000000,B11110000,B10001000,B10001000,B01110000,B00000000}; return returnArray[line]; break; }
	case '7': { byte returnArray[] = {B11111000,B00001000,B00010000,B00100000,B00100000,B00100000,B00100000,B00000000}; return returnArray[line]; break; }
	case '8': { byte returnArray[] = {B01110000,B10001000,B10001000,B01110000,B10001000,B10001000,B01110000,B00000000}; return returnArray[line]; break; }
	case '9': { byte returnArray[] = {B01110000,B10001000,B10001000,B01111000,B00001000,B10001000,B01110000,B00000000}; return returnArray[line]; break; }
	case '0': { byte returnArray[] = {B01110000,B10001000,B10011000,B10101000,B11001000,B10001000,B01110000,B00000000}; return returnArray[line]; break; }
	case '/': { byte returnArray[] = {B00000000,B00001000,B00010000,B00100000,B01000000,B10000000,B00000000,B00000000}; return returnArray[line]; break; }
	case '*': { byte returnArray[] = {B10101000,B01110000,B11111000,B01110000,B10101000,B00000000,B00000000,B00000000}; return returnArray[line]; break; }
	case '@': { byte returnArray[] = {B01110000,B10001000,B10111000,B10101000,B10110000,B10000000,B01111000,B00000000}; return returnArray[line]; break; }
	case '$': { byte returnArray[] = {B00100000,B01111000,B10100000,B01110000,B00101000,B11110000,B00100000,B00000000}; return returnArray[line]; break; }
	case '€': { byte returnArray[] = {B00111000,B01000000,B11110000,B01000000,B11110000,B01000000,B00111000,B00000000}; return returnArray[line]; break; }
	case '&': { byte returnArray[] = {B01000000,B10100000,B10100000,B01000000,B10101000,B10010000,B01101000,B00000000}; return returnArray[line]; break; }
	case '(': { byte returnArray[] = {B01000000,B10000000,B10000000,B10000000,B10000000,B10000000,B01000000,B00000000}; return returnArray[line]; break; }
	case ')': { byte returnArray[] = {B10000000,B01000000,B01000000,B01000000,B01000000,B01000000,B10000000,B00000000}; return returnArray[line]; break; }
	case '=': { byte returnArray[] = {B00000000,B00000000,B11110000,B00000000,B11110000,B00000000,B00000000,B00000000}; return returnArray[line]; break; }
	case ':': { byte returnArray[] = {B00000000,B00000000,B10000000,B00000000,B10000000,B00000000,B00000000,B00000000}; return returnArray[line]; break; }
	case ';': { byte returnArray[] = {B00000000,B00000000,B01000000,B00000000,B01000000,B10000000,B00000000,B00000000}; return returnArray[line]; break; }
	case '<': { byte returnArray[] = {B00010000,B00100000,B01000000,B10000000,B01000000,B00100000,B00010000,B00000000}; return returnArray[line]; break; }
	case '>': { byte returnArray[] = {B10000000,B01000000,B00100000,B00010000,B00100000,B01000000,B10000000,B00000000}; return returnArray[line]; break; }
	//If there the char have not been defined to be drawed or the char is an space, return a white space
	default: { return B00000000; break; }
	}
}

///// Public Methods //////////////////////////////////////////////////////////////
///// Functions available in Wiring sketches, this library, and other libraries

//"General" method to print a string in the matrix giving a determinate position
void StringToMatrixLed::printDisplay(String str, int pos) {
	//If the position that the player wants is different to the last printed or the string have changed since the last print, restart the whole printing, If not, take advantage of previous printing to improve performance 
	if ((lastPosition > pos) || (lastPosition == 0) || (lastString != str))  {
		//Clean the array from the previous executions setting all the positions = B00000000
		for (int b = 0; b < 8; b++) { printArray[b] = B00000000; }

		lastPosition = 0; //reset the lastPosition

		charIndex = 0; //character that is being printed (Starts with 0 and is incremented evey time that the draw changes the character)
		startedPrinting = false; //bool variable to determinate if the print have been started
		copyIndex = 0; //Copy Position (Starts with 0 and is incremented evey time that the draw is moved to the left)
		enablePrinting = true; //bool variable that allows you to draw the sprites in the array "nextDraw" (the next sprite that follow the one that is drawn at that moment)

		//Save the next sprite to draw in the array "nextDraw" (the first sprite in this case)
		for (int n = 0; n < 8; n++) { nextDraw[n] = getArrayOfSprites(str, charIndex, n); }

		Serial.println("New print");
	}

	//---- POSITIONING THE STRING'S DRAW ----
	//"For" that will be executed "pos" times ("pos" is choosed by the user) --> To increase performance (...)
	for (int p = pos; p > lastPosition; p--) {
		//Move the draw one to left (thats essentially what determinates the position ["pos"] of the draw)
		moveDrawOneToLeft();

		//If the copy of the next sprite have ended (it happens when the variable "copyIndex" set to a value higher than 7)
		if (copyIndex > 7) {
			//If there are still things to copy
			if (charIndex < str.length()) {
				//Swap to the next character to print
				charIndex++;
				//If the previous sprite to print hadn't had 8 bits length, a white space is not necessary, then, set the variable "copyIndex" = 0, to start the print inmediatly
				if (copyIndex == 10) { copyIndex = 0; }
				//If the previous sprite to print had 8 bits length, a white space is necessary, then, set the variable "copyIndex" = -1, to avoid starting inmediatly the next print
				else { copyIndex = -1; }
				//Save the variable next sprite to draw in the array of bytes "nextDraw"
				for (int n = 0; n < 8; n++) { nextDraw[n] = getArrayOfSprites(str, charIndex, n); }
			}
			//If there are not more things to copy, disable the printing
			else { enablePrinting = false; }
		}

		//Copy the contents of the column "copyIndex" from the array "nextDraw" to the last column of "printArray"
		if ((copyIndex >= 0) && (copyIndex < 8)) { //Avoid bugs
			//execute the copy row by row
			for (int forRow = 0; forRow < 8; forRow++) {
				//If in the following drawing there is a pixel in the position "copyIndex"...
				if (ifThereIsABitInThisPosition(nextDraw[forRow], copyIndex)) { 
					//...put that pixel in the drawing array at the left
					if (enablePrinting) printArray[forRow] |= 1; 
				}
			}
		}

		//Increase the "copyIndex" because the drawing have advanced
		copyIndex++;

		//If the last column doesn't have any pixel on
		if (isTheColumnFree(printArray, 7)) {
			//if we have started to print and we are not 'in the space between two copys', set "copyIndex" = 10 to indicate that the copy have ended and we have to copy the next char 
			if ((startedPrinting) && (copyIndex>0)) copyIndex = 10;
		}
		//If the last column have a pixel on
		else {
			//Save that the string have been started to be printed
			startedPrinting = true;
		}


	}

	lastPosition = pos; //Save in the variable "lastPosition" the current position
	lastString = str; //Save in the variable "lastString" the current string

	//Once everything have been done, print the array "printArray"
	drawScreen(printArray);
}