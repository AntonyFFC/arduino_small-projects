#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int buttonPin = 2;
int buttonState = 0;
RF24 radio(10,9);
const byte address[6] = "00001";

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.setDataRate(RF24_1MBPS);
  radio.stopListening();
}

void loop() {
  delay(50);
  buttonState = digitalRead(buttonPin);
  radio.write(&buttonState, sizeof(buttonState));

}
