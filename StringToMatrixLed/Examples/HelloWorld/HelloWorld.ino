#include <StringToMatrixLed.h>
StringToMatrixLed nameLibrary;

void setup() {}

//General variables
int positionI = 0;
float positionF = 0;


void loop() {
  //Generate the position where the sprite will be printed
    positionF += 0.05; if (positionF >= 1) { 
      positionI ++; 
      positionF = 0; 
    }
  
  //PRINT THE STRING IN A DETERMINATE POSITION
    nameLibrary.printDisplay("Hello world!", positionI);
}



