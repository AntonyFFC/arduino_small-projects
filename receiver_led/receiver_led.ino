#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
Servo Servo1;
Servo Esc1;

int ledPin = 2;
boolean buttonState = 0;
int signals[2] = {0,0};
RF24 radio(10,9);
const byte address[6] = "00001";
int servoPin = 6;
int escPin = 5;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.setDataRate(RF24_1MBPS);
  radio.startListening();
  Servo1.attach(servoPin);
  Esc1.attach(escPin);
}

void loop() {
  if (radio.available()) {
    radio.read(&signals, sizeof(signals));
    Serial.print("servo: ");
    Serial.println(signals[0]);
    Serial.print("silnik: ");
    Serial.println(signals[1]);
    analogWrite(ledPin, signals[0]);
    Servo1.write(signals[0]);
    Esc1.writeMicroseconds(signals[1]);
    delay(5);
//    if ( buttonState == 1)
//    {
//        digitalWrite(ledPin, HIGH);
//    }
//    else
//    {
//        digitalWrite(ledPin, LOW);
//    }
  }
}
