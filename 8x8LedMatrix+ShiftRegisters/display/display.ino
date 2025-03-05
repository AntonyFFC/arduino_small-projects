#include "LED8x8.h"
#include "LED4.h"
#include "snake.h"
#include "joystick.h"
#include "drawer.h"

Led8x8 l1(2,3,4);
Led4 l2H(6,7,8);
Led4 l2E(6,7,8);
Led4 l2G(6,7,8);
Joystick j1(5,0,1);
Drawer drawrHome(0,0,0);
Drawer drawrGame(0,0,0);
Drawer drawrEnd(0,0,0);


int blank [8] = {0,0,0,0,0,0,0,0};

 
  void setup() {
    l1.pinSetup();
    l2H.pinSetup();
    l2E.pinSetup();
    l2G.pinSetup();
    j1.pinSetup();
  }

  void loop(){
    drawrHome.drawAll(l1, l2H, blank, "CHOOSE GAME", 3000, 1000);
    if(j1.swButton()){
      Snk();
    };
    drawrHome.drawAll(l1, l2H, blank, "CHOOSE GAME", 3000, 1000);
    if(j1.swButton()){
      Snk();
    }
    drawrHome.drawAll(l1, l2H, blank, "CHOOSE GAME", 3000, 1000);
    if(j1.swButton()){
      Snk();
    }
  }

  void Snk(){
      int picture [8] = {0,0,0,0,0,0,0,0};
      Snake waz(1,-1,0,0,5);
      Direction dir(waz.xVelocity,waz.yVelocity);
      l1.draw(blank,16);
      int i=rand() % 8;
      int j=rand() % 8;
      waz.dotts[j][i].apple=true;
      waz.dotts[j][i].toggle(picture);
      String endText = "You died your final score is= ";
      
      waz.show(picture);
      
      while(waz.alive) {
        // tu owinien sie zerowac drawall i l1 i l2
        drawrGame.drawAll(l1, l2G, picture, waz.Level, (4800/(waz.Level+4)), (2400/(waz.Level+4)));
        if(j1.change()){ //checks first time in the middle of the lighting of leds if joystick moved
          dir = j1.dir();
        }

        drawrGame.drawAll(l1, l2G, picture, waz.Level, (4800/(waz.Level+4)), (2400/(waz.Level+4)));

        if(j1.change()){ //checks second time right before the movement if joystick moved
          dir = j1.dir();
        }
        waz.joystickMoved(dir);
        
        waz.moved(picture);
      
      }
      endText += String(waz.Level);
      drawrEnd.drawAll(l1, l2E, blank, endText, 8000, 9000);
  }
