
#include "numbers.h"
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
using namespace std;


	

	Numb::Numb(int pnA,int pnB,int pnC,int pnD,int pnE,int pnF,int pnG,int D1,int D2,int D3,int D4){
		pinA=pnA;
		pinB=pnB;
		pinC=pnC;
		pinD=pnD;
		pinE=pnE;
		pinF=pnF;
		pinG=pnG;
		C1=D1;
		C2=D2;
		C3=D3;
		C4=D4;	
	}
	
	void Numb::pinSetup() {
	  pinMode(pinA, OUTPUT);     
	  pinMode(pinB, OUTPUT);     
	  pinMode(pinC, OUTPUT);     
	  pinMode(pinD, OUTPUT);     
	  pinMode(pinE, OUTPUT);     
	  pinMode(pinF, OUTPUT);     
	  pinMode(pinG, OUTPUT);   
	  pinMode(C1, OUTPUT);  
	  pinMode(C2, OUTPUT);  
	  pinMode(C3, OUTPUT);  
	  pinMode(C4, OUTPUT);  	
	}
	
	void Numb::number(int i){

	  if( i==0){
	    digitalWrite(pinA, HIGH);   
	    digitalWrite(pinB, HIGH);   
	    digitalWrite(pinC, HIGH);   
	    digitalWrite(pinD, HIGH);   
	    digitalWrite(pinE, HIGH);   
	    digitalWrite(pinF, HIGH);   
	    digitalWrite(pinG, LOW); 
	  }else if( i==1){
	    digitalWrite(pinA, LOW);   
	    digitalWrite(pinB, HIGH);   
	    digitalWrite(pinC, HIGH);   
	    digitalWrite(pinD, LOW);   
	    digitalWrite(pinE, LOW);   
	    digitalWrite(pinF, LOW);   
	    digitalWrite(pinG, LOW); 
	  }else if( i==2){
	    digitalWrite(pinA, HIGH);   
	    digitalWrite(pinB, HIGH);   
	    digitalWrite(pinC, LOW);   
	    digitalWrite(pinD, HIGH);   
	    digitalWrite(pinE, HIGH);   
	    digitalWrite(pinF, LOW);   
	    digitalWrite(pinG, HIGH); 
	  }else if( i==3){
	    digitalWrite(pinA, HIGH);   
	    digitalWrite(pinB, HIGH);   
	    digitalWrite(pinC, HIGH);   
	    digitalWrite(pinD, HIGH);   
	    digitalWrite(pinE, LOW);   
	    digitalWrite(pinF, LOW);   
	    digitalWrite(pinG, HIGH); 
	  }else if( i==4){
	    digitalWrite(pinA, LOW);   
	    digitalWrite(pinB, HIGH);   
	    digitalWrite(pinC, HIGH);   
	    digitalWrite(pinD, LOW);   
	    digitalWrite(pinE, LOW);   
	    digitalWrite(pinF, HIGH);   
	    digitalWrite(pinG, HIGH); 
	  }else if( i==5){
	    digitalWrite(pinA, HIGH);   
	    digitalWrite(pinB, LOW);   
	    digitalWrite(pinC, HIGH);   
	    digitalWrite(pinD, HIGH);   
	    digitalWrite(pinE, LOW);   
	    digitalWrite(pinF, HIGH);   
	    digitalWrite(pinG, HIGH); 
	  }else if( i==6){
	    digitalWrite(pinA, HIGH);   
	    digitalWrite(pinB, LOW);   
	    digitalWrite(pinC, HIGH);   
	    digitalWrite(pinD, HIGH);   
	    digitalWrite(pinE, HIGH);   
	    digitalWrite(pinF, HIGH);   
	    digitalWrite(pinG, HIGH); 
	  }else if( i==7){
	    digitalWrite(pinA, HIGH);   
	    digitalWrite(pinB, HIGH);   
	    digitalWrite(pinC, HIGH);   
	    digitalWrite(pinD, LOW);   
	    digitalWrite(pinE, LOW);   
	    digitalWrite(pinF, LOW);   
	    digitalWrite(pinG, LOW); 
	  }else if( i==8){
	    digitalWrite(pinA, HIGH);   
	    digitalWrite(pinB, HIGH);   
	    digitalWrite(pinC, HIGH);   
	    digitalWrite(pinD, HIGH);   
	    digitalWrite(pinE, HIGH);   
	    digitalWrite(pinF, HIGH);   
	    digitalWrite(pinG, HIGH); 
	  }else if( i==9){
	    digitalWrite(pinA, HIGH);   
	    digitalWrite(pinB, HIGH);   
	    digitalWrite(pinC, HIGH);   
	    digitalWrite(pinD, HIGH);   
	    digitalWrite(pinE, LOW);   
	    digitalWrite(pinF, HIGH);   
	    digitalWrite(pinG, HIGH); 
	  };

	  
	}

	void Numb::row(int a,int b, int c, int d){
	  if(a==1){
	    digitalWrite(C1, LOW);
	  }else{
	    digitalWrite(C1, HIGH);
	  };

	    if(b==1){
	    digitalWrite(C2, LOW);
	  }else{
	    digitalWrite(C2, HIGH);
	  };

	    if(c==1){
	    digitalWrite(C3, LOW);
	  }else{
	    digitalWrite(C3, HIGH);
	  };

	    if(d==1){
	    digitalWrite(C4, LOW);
	  }else{
	    digitalWrite(C4, HIGH);
	  };


	  
	}

	void Numb::intiger(int x){
	  int ones;
	  int tens;
	  int hundreds;
	  int thousands;
	  ones=(x%10);
	  tens=(((x-ones)/10)%10);
	  hundreds=(((x-ones-tens)/100)%10);
	  thousands=(((x-ones-tens-hundreds)/1000)%10);
	  
	  
	    if(thousands==0)row();
	    else row(1);
	    number(thousands);
	    delay(2);
	    if(thousands==0 && hundreds==0)row();
	    else row(0,1);
	    number(hundreds);
	    delay(2);
	    if(thousands==0 && hundreds==0 && tens==0)row();
	    else row(0,0,1);
	    number(tens);
	    delay(2);
	    if(thousands==0 && hundreds==0 && tens==0 && ones==0)row();
	    else row(0,0,0,1);
	    number(ones);
	    delay(2);
 } 


