#include "drawer.h"
#include "LED8x8.h"
#include "LED4.h"
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
using namespace std;


  Drawer::Drawer(int ing, int inh, int ink){
  	g=ing;
  	h=inh;
  	k=ink;
  }

  void Drawer::drawAll(Led8x8 (&L8), Led4 (&L4), int picture [8], int numbr, int lduration, int sduration){
    for( k; k < (lduration/6); k++){
      L8.draw(picture, sduration, 4);
      L4.display(numbr, lduration, 2);
  	  sduration -= 6;
      if (sduration <= 0){
        k++;
        return;
      }
    }
	  k=0;
  }
  
  void Drawer::drawAll(Led8x8 (&L8), Led4 (&L4), int picture [8], String txt, int lduration, int sduration){
    for( h; h < (lduration/6); h++){ //h sie nie zeruje dlatego w kazdej nastepnej instancji jest tylko wieksze
      L8.draw(picture, sduration, 4);
      L4.display(txt, lduration, 2);
  	  sduration -= 6;
      if (sduration <= 0){
        h++;
        return;
      }
    }
	  h=0;
  }

  void Drawer::drawAllF(Led8x8 (&L8), Led4 (&L4), int picture [8], int speed, int type, int lduration, int sduration){
    for( g; g < (lduration/6); g++){
      L8.draw(picture, sduration, 4);
      L4.flashing(speed, lduration, type, 2);
  	  sduration -= 6;
      if (sduration <= 0){
        g++;
        return;
      }
    }
	  g=0;
  }
