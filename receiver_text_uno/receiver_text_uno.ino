#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int buttonPin = 2;
int buttonState = 0;
RF24 radio(10,9);
const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.setDataRate(RF24_1MBPS);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    char text[32];  // Buffer to hold the received text
    radio.read(&text, sizeof(text));
    Serial.println(text);  // Print the received message
  }
}
