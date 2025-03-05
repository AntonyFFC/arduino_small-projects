    
#ifndef numbers_h
#define numbers_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


using namespace std;

class Numb{
  private:
  	int pinLatch;
  	int pinClock:
  	int pinData;	
  
  public: 
		Matrix(int pLatch, int pClock, int pData);

    		void pSetup();
    
    		void show(int Columns [7]={255,255,255,255,255,255,255,255});
    
   	 	int movex(int a=0, int xposition=0);
   	 	
   	 	int movey(int b=0, int yposition=0);
 };   
#endif
