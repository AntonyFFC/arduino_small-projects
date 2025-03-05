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
          i=0;
          j=0;
          k=0;
      }

      void Led8x8::pinSetup() {
	      pinMode(latchPin, OUTPUT);     
	      pinMode(clockPin, OUTPUT); 
	      pinMode(dataPin, OUTPUT);       
      }


      void Led8x8::draw(int pic [8], int duration, int shortDur) {
        for (j; j<(duration/8); j++){
          for (i; i<8; i++) {
  			      digitalWrite(latchPin, LOW);
  	  		    shiftOut(dataPin,clockPin,MSBFIRST,pic[i]);
  	  		    shiftOut(dataPin,clockPin,MSBFIRST,~(1 << i));
  	  		    digitalWrite(latchPin,HIGH);
              delay(1);
              shortDur -= 1;
              if (shortDur <= 0){
                i++;
                return;
              }
          }
          i=0;
        }
        j=0;
	      digitalWrite(latchPin, LOW);
      }

      void Led8x8::dotchange(int x, int y, int (&pict) [8]) {
		    pict[y] |= 1 << x;
		    draw(pict,16);
      }
      void Led8x8::dot(int x, int y, int pict [8]) {
		    bool set=false;
		    if (pict[y] & (1<<x)){
			    set = true;
		    }
		    pict[y] |= 1 << x;
		    draw(pict,16);
		    if(!set)pict[y] &= ~(1<<x);
      }

      
 
      
