#include "LED4.h"
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
using namespace std;

Led4::Led4(int latchPn, int clockPn, int dataPn) {
    latchPin = latchPn;
    clockPin = clockPn;
    dataPin = dataPn;
    i=0;
    j=0;
    k=0;
    h=0;
}

void Led4::pinSetup() {
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
}

void Led4::clear() {
    for (int f = 0; f < 4; f++) {
        digitalWrite(latchPin, LOW);
        character(' ', false);
        shiftOut(dataPin, clockPin, MSBFIRST, ~(1 << i));
        digitalWrite(latchPin, HIGH);
        delay(2);
    }
    digitalWrite(latchPin, LOW);
}

void Led4::character(char a, bool dp) {
    short int numb = 0;

    if (a == '0') {
        numb = 63;
    }
    else if (a == '1') {
        numb = 6;
    }
    else if (a == '2') {
        numb = 91;
    }
    else if (a == '3') {
        numb = 79;
    }
    else if (a == '4') {
        numb = 102;
    }
    else if (a == '5') {
        numb = 109;
    }
    else if (a == '6') {
        numb = 125;
    }
    else if (a == '7') {
        numb = 7;
    }
    else if (a == '8') {
        numb = 127;
    }
    else if (a == '9') {
        numb = 111;
    }
    else if (a == 'A') {
        numb = 119;
    }
    else if (a == 'a') {
        numb = 95;
    }
    else if (a == 'B') {
        numb = 127;
    }
    else if (a == 'b') {
        numb = 124;
    }
    else if (a == 'C') {
        numb = 57;
    }
    else if (a == 'c') {
        numb = 88;
    }
    else if (a == 'd' || a == 'D') {
        numb = 94;
    }
    else if (a == 'e' || a == 'E') {
        numb = 121;
    }
    else if (a == 'f' || a == 'F') {
        numb = 113;
    }
    else if (a == 'G') {
        numb = 61;
    }
    else if (a == 'g') {
        numb = 111;
    }
    else if (a == 'H') {
        numb = 118;
    }
    else if (a == 'h') {
        numb = 116;
    }
    else if (a == 'I') {
        numb = 6;
    }
    else if (a == 'i') {
        numb = 4;
    }
    else if (a == 'j' || a == 'J') {
        numb = 30;
    }
    else if (a == 'k' || a == 'K') {
        numb = 112;
    }
    else if (a == 'l' || a == 'L') {
        numb = 56;
    }
    else if (a == 'm' || a == 'M') {
        numb = 21;
    }
    else if (a == 'n' || a == 'N') {
        numb = 84;
    }
    else if (a == 'O') {
        numb = 63;
    }
    else if (a == 'o') {
        numb = 92;
    }
    else if (a == 'p' || a == 'P') {
        numb = 115;
    }
    else if (a == 'q' || a == 'Q') {
        numb = 103;
    }
    else if (a == 'r' || a == 'R') {
        numb = 80;
    }
    else if (a == 's' || a == 'S') {
        numb = 109;
    }
    else if (a == 't' || a == 'T') {
        numb = 120;
    }
    else if (a == 'u' || a == 'U') {
        numb = 62;
    }
    else if (a == 'v' || a == 'V') {
        numb = 28;
    }
    else if (a == 'w' || a == 'W') {
        numb = 42;
    }
    else if (a == 'x' || a == 'X') {
        numb = 73;
    }
    else if (a == 'y' || a == 'Y') {
        numb = 110;
    }
    else if (a == 'z' || a == 'Z') {
        numb = 91;
    }
    else if (a == '_') {
        numb = 8;
    }
    else if (a == '=') {
        numb = 72;
    }
    else if (a == '-') {
        numb = 64;
    }
    else if (a == ' ') {
        numb = 0;
    }

    if (dp) {
        numb += 128;
    }

    shiftOut(dataPin, clockPin, MSBFIRST, numb);
}

void Led4::display(String text, int duration, int shortDur) {
    int siz = text.length();
    int d = 0;

    for (int f = 0; f < siz; f++) {
        if (text[f] == '.') {
            siz--;
        }
    }
    
    if (siz > 4) {
        for (j; j < (3+ siz); j++) {
            for (k; k < (duration / (siz * 4)); k++) {
                d = 0;
                for (i; i < 4; i++) {
                    digitalWrite(latchPin, LOW);
                    if ((i + j - 3) <= siz && (i + j - 3) >= 0) {
                        if (text[i + j - 2 + d] == '.') {
                            character(text[i + j - 3], true);
                            d++;
                        }
                        else {
                            character(text[i + j - 3 + d], false);
                        }
                        
                    }
                    else {
                        character(' ', false);
                    }
                    shiftOut(dataPin, clockPin, MSBFIRST, ~(1 << i));
                    digitalWrite(latchPin, HIGH);
                    delay(1);
                    shortDur -= 1;
                    if (shortDur <= 0){
                      i++;
                      return;
                    }
                }
                i=0;
            }
            k=0;
        }
        j=0;
    }
    else {
        for (j; j < (duration / 4); j++) {
            d = 0;
            for (i; i < 4; i++) {
                digitalWrite(latchPin, LOW);
                if (text[i + 1 + d] == '.') {
                    character(text[i], true);
                    d++;
                }
                else {
                    character(text[i + d], false);
                }
                shiftOut(dataPin, clockPin, MSBFIRST, ~(1 << i));
                digitalWrite(latchPin, HIGH);
                delay(1);
                shortDur -= 1;
                if (shortDur <= 0){
                    i++;
                    return;
                }
            }
            i=0;
        }
        j=0;

    }
}

void Led4::display(int numb, int duration, int shortDur) {
    String txt = String(numb);
    display(txt, duration, shortDur);
}

void Led4::flashing(int speed, int duration, int type, int shortDur) {
    int arrangements[6][4][3] = 
        { 
            { {9,32,16},{0,8,1},{0,1,8},{9,4,2} }, 
            { {41,48,25},{8,9,1},{1,9,8},{13,6,11} },
            { {36,18,36},{18,36,18},{36,18,36},{18,36,18} },
            { {127,0,0},{0,127,0},{0,0,127},{127,0,0} },
            { {57,0,0},{0,57,6},{0,15,48},{15,0,0} },
            { {1,8,64},{64,1,8},{8,64,1},{1,8,64} }
        };

    for (h; h < (duration / (12000 / speed)); h++) {
        for (k; k < 3; k++) {
            for (j; j < (2000 / speed); j++) {
                for (i; i < 4; i++) {
                    digitalWrite(latchPin, LOW);
                    shiftOut(dataPin, clockPin, MSBFIRST, arrangements[type][i][k]);
                    shiftOut(dataPin, clockPin, MSBFIRST, ~(1 << i));
                    digitalWrite(latchPin, HIGH);
                    delay(1);
                    shortDur -= 1;
                    if (shortDur <= 0){
                      i++;
                      return;
                    }
                }
                i=0;
            }
            j=0;
        }
        k=0;
    }
    h=0;
}
