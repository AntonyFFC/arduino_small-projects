   
#include "numbers.h"
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
using namespace std;  
   
   
   
    Matrix::Matrix(int pLatch, int pClock, int pData) {
        pinLatch=pLatch;
        pinClock=pClock;
        pinData=pData;
    
    }

    void Matrix::pSetup() {
      pinMode(pinLatch, OUTPUT);     
      pinMode(pinClock, OUTPUT);     
      pinMode(pinData, OUTPUT);      
  }
    
    void Matrix::show(int Columns [7]) {
        for(int i=0; i<8;i++){
        	if(Columns[i]!=0){
        	        digitalWrite(pinLatch, LOW);
        		shiftOut(pinData,pinClock,MSBFIRST,~(1<<i));
        		shiftOut(pinData,pinClock,MSBFIRST,Columns[i]);
        		digitalWrite(pinLatch,HIGH);  
        	}
        	delay(10);
	}
	digitalWrite(pinLatch, LOW);          
    }
    
    int Matrix::movex(int a, int xposition){
        xposition = xposition<<a;  
        return xposition;  
    }
    
    int Matrix::movey(int b, int yposition){
        yposition = yposition<<b; 
        return yposition;    
    }
