#include "LED8x8.h"
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
using namespace std;

      
      
      Led8x8::Led8x8(int latchPn,int clockPn,int dataPn){
          latchPin=latchPn;
          clockPin=clockPn;
          dataPin=dataPn;
      }

      void Led8x8::pinSetup() {
	      pinMode(latchPin, OUTPUT);     
	      pinMode(clockPin, OUTPUT); 
	      pinMode(dataPin, OUTPUT);       
      }


      void Led8x8::draw(int pic [8]) {
        for (int i=0; i<8; i++) {
        	if(pic[i]!=0){
			digitalWrite(latchPin, LOW);
	  		shiftOut(dataPin,clockPin,MSBFIRST,pic[i]);
	  		shiftOut(dataPin,clockPin,MSBFIRST,~(1 << i));
	  		digitalWrite(latchPin,HIGH);
	  		delay(2);
  		}
        }
	digitalWrite(latchPin, LOW);      
      }

      void Led8x8::dotchange(int x, int y, int (&pict) [8]) {
		pict[y] |= 1 << x;
		draw(pict);
      }
      void Led8x8::dot(int x, int y, int pict [8]) {
		bool set=false;
		if (pict[y] & (1<<x)){
			set = true;
		}
		pict[y] |= 1 << x;
		draw(pict);
		if(!set)pict[y] &= ~(1<<x);
      }

      
 
      
