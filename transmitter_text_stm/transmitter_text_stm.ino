#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int ledPin = 2;
boolean buttonState = 0;
RF24 radio(10,9);
const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.setDataRate(RF24_1MBPS);
  radio.stopListening();
}

void loop() {
  const char text[] = "Hello World";
  radio.write(&text, strlen(text));  // Send the string, not the full array
  Serial.println(text);
  delay(1000);
}
