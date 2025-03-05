#ifndef LED4_h
#define LED4_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
        
        
        using namespace std;
        
        class Led4 {
          private:
          int latchPin;
          int clockPin;
          int dataPin;
          int i;
          int j;
          int k;
          int h;
        
          public:

            Led4(int latchPn,int clockPn,int dataPn); //constructor of class Led4
            
            void pinSetup(); //the initial setup of the pins of the microcontroller

            void clear(); //clears the screen
            
            void character(char a = ' ', bool dp = false); // this contains all of the sequences for each letter and number

            void display(String text, int duration, int shortDur = 0); //displays the given text
            void display(int numb, int duration, int shortDur = 0); // or number

            void flashing(int speed = 200, int duration = 1000, int type = 2, int shortDur = 0);
        };
        
#endif
