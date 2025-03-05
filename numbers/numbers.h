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
	int pinA;
	int pinB;
	int pinC;
	int pinD;
	int pinE;
	int pinF;
	int pinG;
	int C1;
	int C2;
	int C3;
	int C4;

  public:
		Numb(int pnA,int pnB,int pnC,int pnD,int pnE,int pnF,int pnG,int D1,int D2,int D3,int D4);
		
		void pinSetup();
		
		void number(int i=0);

		void row(int a=0,int b=0, int c=0, int d=0);

		void intiger(int x=0);
};

#endif
