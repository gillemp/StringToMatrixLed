// ensure this library description is only included once
#ifndef StringToMatrixLed_h
#define StringToMatrixLed_h

// include types & constants of Wiring core API (and Arduino)
#include "Arduino.h"

// library interface description
class StringToMatrixLed
{
// user-accessible "public" interface
public:
	StringToMatrixLed(); //constructor of the library, handles the setup of the library
	void printDisplay(String str, int pos); //method to print a string in the matrix giving a determinate position (the one that have to use the user)

// library-accessible "private" interface
private:
	//Global variables and arrays
	int row[8] = { 2, 7, 19, 5, 13, 18, 12, 16 }; //default rows pins
	int col[8] = { 6, 11, 10, 3, 17, 4, 8, 9 }; //default columns pins
	byte printArray[8] = { B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000 }; //Aray that will be printed in the matrix (initially in blank)
	byte nextDraw[8] = { B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000 }; //Aray that will hold the next letter to print in the matrix (initially in blank)

	int lastPosition = 0; //variable that saves the last position that have been printed with this library (it is used to improve the performance)
	String lastString = String(""); //variable that saves the last string that was printed

	int charIndex = 0; //character that is being printed (Starts with 0 and is incremented evey time that the draw changes the character)
	bool startedPrinting = false; //bool variable to determinate if the print have been started
	int copyIndex = 0; //Copy Position (Starts with 0 and is incremented evey time that the draw is moved to the left)
	bool enablePrinting = true; //bool variable that allows you to draw the sprites in the array "nextDraw" (the next sprite that follow the one that is drawn at that moment)

	//Methods
	bool ifThereIsABitInThisPosition(byte b, int pos); //Check if there is a bit (set to 1) in a determinate position of a determinate byte
	void drawScreen(byte printArray[]); //Draws in the matrix the given array
	bool isTheColumnFree(byte byteArray[], int column); //Determines whether in an array with 8 bytes there is none in the "column" position with its corresponding bit = 1 (if the full column in the array is 0)
	void moveDrawOneToLeft(); //Moves the draw one pixel tot he left (shifts one bit to the left all the bytes in the "printArray" array)
	byte getArrayOfSprites(String str, int chNun, int line); //Return the row number "line" of the sprite to draw the char number "chNum" in the string "str"
};

#endif