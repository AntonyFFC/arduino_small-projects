#include "joystick.h"
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
using namespace std;
      
      Direction::Direction(int cx, int cy){
        x=cx;
        y=cy;
      }
      
      Joystick::Joystick(int cswPin,int cxPin,int cyPin){
          swPin=cswPin;
          xPin=cxPin;
          yPin=cyPin;
          //dir = Direction();
      }

      void Joystick::pinSetup() {
            pinMode(swPin, INPUT);
            digitalWrite(swPin, HIGH);       
      }

      bool Joystick::change(){
        if (analogRead(xPin) < 300 || analogRead(xPin) > 750 || analogRead(yPin) < 300 || analogRead(yPin) > 750) return true;
        return false;
      }

      Direction Joystick::dir(){
        int x=0;
        int y=0;
        if (analogRead(xPin) < 300){
          x = -1;
        }else if (analogRead(xPin) > 750){
          x = 1;
        }else if (analogRead(xPin) > 300 && analogRead(xPin) < 750){
          x = 0;
        }
        if (analogRead(yPin) < 300){
          y = -1;
        }else if (analogRead(yPin) > 750){
          y = 1;
        }else if (analogRead(yPin) > 300 && analogRead(yPin) < 750){
          y = 0;
        }
        return Direction(x,y);
      }

      bool Joystick::swButton(){
        if (digitalRead(swPin)==1) return false;
        else if (digitalRead(swPin)==0) return true;
      }

      
 
      
