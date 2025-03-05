#ifndef LED8x8_h
#define LED8x8_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
        
        
        using namespace std;
        
        class Led8x8{
          private:
          int latchPin;
          int clockPin;
          int dataPin;
          int i;
          int j;
          int k;
          
          public:
            Led8x8(int latchPn,int clockPn,int dataPn); //constructor of class Led8x8
            
            void pinSetup(); //the initial setup of the pins of the microcontroller
            
            void draw(int pic [8], int duration, int shortDur = 0); //draws the inputted array
            
            void dotchange(int x, int y, int (&pict) [8]); //lights up the LED with the given coordinates and changes the given array to contain the dot
            
            void dot(int x, int y, int pict [8]); //lights up the LED with the given coordinates
        };
        
#endif
