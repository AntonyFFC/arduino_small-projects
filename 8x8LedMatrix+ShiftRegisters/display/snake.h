#ifndef snake_h
#define snake_h
#include "LED8x8.h"
#include "joystick.h"
#include <stdlib.h>  

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
        
        
        using namespace std;
        
        class Dott{
        friend class Snake;
          public:
          bool apple;
          void toggle(int (&pikt) [8]);//toggles this Dott
          
          private:
          int timer;
          bool on;
          int dx;
          int dy;

          Dott(int ctimer=0,bool con=false, bool capple = false, int cx = 0, int cy = 0);//constructor of Dott
        };

        
        class Snake{
          private:
          void longer(); //this makes the snake longer
          void faster(); //this makes the snake faster
          bool ate(); //this boolean checks if an apple is eaten
          bool death(); //this boolean checks if the snake hit its tail
          
          public:
          bool alive;
          int Length;
          int xVelocity;
          int yVelocity;
          int Level=1;
          int x;
          int y;
          Dott dotts [8] [8];
        
            Snake(int lev = 0,int xvel = 0,int yvel = 0,int i = 3, int j = 3);//constructor of Snake

            void show(int (&cpic)[8]); //this is used before the start of the game to set the snake initial positions
            
            //void turn(char dir); 

            void moved(int (&pik)[8]); //moves the snake

            void joystickMoved(Direction dr); //this function changes the direction of movement of the snake
        };
        
        
        
        
#endif
