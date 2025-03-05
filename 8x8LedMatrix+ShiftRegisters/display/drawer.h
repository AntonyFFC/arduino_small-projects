#ifndef drawer_h
#define drawer_h
#include "LED8x8.h"
#include "LED4.h"

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
        
        
        using namespace std;
        
        class Drawer {
          private:
          int k;
    		  int h;
    		  int g;
        
          public:

            Drawer(int ing, int inh, int ink); //constructor of class Drawer
            
            void drawAll(Led8x8 (&L8), Led4 (&L4), int picture [8], int numbr, int lduration, int sduration); //sduration is the time this very instance of the function is done, while lduration is the whole length g
      			// of the displaying which could be done in several instances. lduration is nearly always equal to sduration unless you want to devide the display into several instances
      			void drawAll(Led8x8 (&L8), Led4 (&L4), int picture [8], String txt, int lduration, int sduration);
      			
      			void drawAllF(Led8x8 (&L8), Led4 (&L4), int picture [8], int speed, int type, int lduration, int sduration);
        };
        
#endif
