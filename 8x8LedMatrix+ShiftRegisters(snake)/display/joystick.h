#ifndef joystick_h
#define joystick_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
        
        
        using namespace std;
        
        class Direction{
          public:
          int x;
          int y;
          Direction(int cx = 0, int cy = 0);//constructor of class Direction
        };
        
        class Joystick{
          private:
            int swPin;
            int xPin;
            int yPin;
            
          public:
            //Direction dir;

            
            Joystick(int cswPin,int cxPin,int cyPin);
            
            void pinSetup();

            bool change();

            Direction dir();

            bool swButton();

            
            
        };
        
#endif
