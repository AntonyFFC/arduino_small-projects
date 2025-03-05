#include "LED8x8.h"
#include "snake.h"
#include "joystick.h"
#include <stdlib.h>  
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
using namespace std;

      
      Dott::Dott(int ctimer,bool con,bool capple, int cx, int cy){
          timer = ctimer;
          on = con;
          apple=capple;
          dx = cx;
          dy = cy;
      }
      
      void Dott::toggle(int (&pikt) [8]) {
          if (on){
            on = false;
          }else{
            on = true;
          }
          pikt[dy] ^= 1 << dx;
      }
      
      Snake::Snake(int lev,int xvel,int yvel,int i, int j){
          alive=true;
          Level=lev;
          xVelocity=xvel;
          yVelocity=yvel;
          x=i;
          y=j;

          for (int r=0; r<8; r++){
            for (int c=0; c<8; c++){
              dotts [r] [c] = Dott(0,false,false,c,r);
            }
          }
      }

      void Snake::show(int (&cpic)[8]){
          y-=yVelocity;
          x-=xVelocity;
        for (int i=0; i++; i<(Level+2)){
          y+=yVelocity;
          x+=xVelocity;
          dotts[y][x].toggle(cpic);
          dotts[y][x].timer = i+1;  
        }
      }

      /*void Snake::turn(char dir){
      		if (dir=='d' || dir=='D'){
      			if (yVelocity > 0){
      				return;
			      }
			    yVelocity = -yVelocity;
      		}else if (dir=='u' || dir=='U'){
      			if (yVelocity < 0){
      				return;
			      }
			      yVelocity = -yVelocity;      		     		
      		}else if (dir=='r' || dir=='R'){
      			if (xVelocity > 0){
      				return;
			      }
			      xVelocity = -xVelocity;      		
      		}else if (dir=='l' || dir=='L'){
			      if (xVelocity < 0){
      				return;
			      }
			      xVelocity = -xVelocity;     		
      		}
      }*/

      void Snake::longer() {
		      Length++;
      }
      
      void Snake::faster() { 
      		if (yVelocity == 0 && xVelocity != 0){
      			xVelocity++;
      		}else if (xVelocity == 0 && yVelocity != 0){
      			yVelocity++;
      		}
      }
      
      bool Snake::ate() {
      		if (dotts[y][x].apple==false)return false;
          return true; 
      }

      bool Snake::death() {
          if (dotts[y][x].apple==false && dotts[y][x].on)return true;
          return false;
      }

      void Snake::moved(int (&pik) [8]) {
          int i;
          int j;
          
          y+=yVelocity;
          x+=xVelocity;

          if (!death()){
            //this decreases the timers of each dot and turns off the ones with no timer left
            if (!ate()){
              for (int i=0; i<8; i++){
                for (int j=0; j<8; j++){
                  if (dotts[i][j].timer == 0)continue;
                  dotts[i][j].timer--;
                  if (dotts[i][j].timer <= 0){
                    dotts[i][j].toggle(pik);
                  }
                }
              }
            }else{ //if the snake has just ate the above step is skipped
              Level++;
              longer();
              dotts[y][x].toggle(pik);
              dotts[y][x].apple = false;
              do{
                i=rand() % 8;
                j=rand() % 8;
              }while (dotts[j][i].on);
              dotts[j][i].apple=true;
              dotts[j][i].toggle(pik);
            }

            // this ensures that the snake moves to the other side of the screen when reached the end
            if (y>7)y-=8;
            if (y<0)y+=8;
            if (x>7)x-=8;
            if (x<0)x+=8;
            
            dotts[y][x].timer = Level+2;         
            dotts[y][x].toggle(pik);
          
          }else{
            alive=false;
          }
          
      }

      void Snake::joystickMoved(Direction dr){
          if (abs(dr.x) > abs(dr.y)){
            if (abs(xVelocity)>0)return;
            xVelocity = dr.x;
            yVelocity=0;
          }else{
            if (abs(yVelocity)>0)return;
            yVelocity = dr.y;
            xVelocity=0;
          }
      }

      
