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
        
          public:
            Led8x8(int latchPn,int clockPn,int dataPn);
            
            void pinSetup();
            
        
            void draw(int pic [8]);
            
            void dotchange(int x, int y, int (&pict) [8]);
            
            void dot(int x, int y, int pict [8]);
        };
        
#endif
