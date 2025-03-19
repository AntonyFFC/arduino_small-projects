#include "LED8x8.h"
#include "snake.h"
#include "joystick.h"

Led8x8 l1(2,3,4);
Joystick j1(5,0,1);


int blank [8] = {0,0,0,0,0,0,0,0};

 
  void setup() {
    l1.pinSetup();
    j1.pinSetup();
  }

  void loop(){
    int picture [8] = {0,0,0,0,0,0,0,0};
    Snake waz(3,1,0,0,5);
    Direction dir(waz.xVelocity,waz.yVelocity);
    l1.draw(blank,16);
    int i=rand() % 8;
    int j=rand() % 8;
    waz.dotts[j][i].apple=true;
    waz.dotts[j][i].toggle(picture);

    
    if(j1.swButton()){
      waz.show(picture);
      
      while(waz.alive) {
        
        l1.draw(picture,(2400/(waz.Level+2)));
        if(j1.change()){ //checks first time in the middle of the lighting of leds if joystick moved
          dir = j1.dir();
        }
        l1.draw(picture,(2400/(waz.Level+2)));

        if(j1.change()){ //checks second time right before the movement if joystick moved
          dir = j1.dir();
        }
        waz.joystickMoved(dir);
        
        waz.moved(picture);
      
      } 
    }
  }
