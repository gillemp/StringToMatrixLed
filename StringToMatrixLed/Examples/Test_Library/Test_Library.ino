#include <StringToMatrixLed.h>
StringToMatrixLed stringToMatrixLed;

void setup() {}

//General variables
int positionI = 0;
float positionF = 0;


void loop() {
  //Generate the position where the sprite will be printed
  positionF += 0.05; if (positionF >= 1) { positionI ++; positionF = 0; }
  
  
  //PRINT THE STRING IN A DETERMINATE POSITION
    stringToMatrixLed.printDisplay("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!¡¿?+-#.,/*@$€&()=:;<>", positionI);
    
  //PRINT THE STRING IN A DETERMINATE POSITION
    //stringToMatrixLed.printDisplay("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!¡¿?+-#.,/*@$€&()=:;<>", 6); 
    
  //TEST THE STRING WITH UPPER CASE AND LOWERCASE LETTERS
    //stringToMatrixLed.printDisplay("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!¡¿?+-#.,/*@$€&()=:;<>", positionI);
  
}



