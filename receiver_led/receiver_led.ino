#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int ledPin = 2;
boolean buttonState = 0;
RF24 radio(10,9);
const byte address[6] = "00001";

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.setDataRate(RF24_1MBPS);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    radio.read(&buttonState, sizeof(buttonState));
    Serial.println(buttonState);

    if ( buttonState == 1)
    {
        digitalWrite(ledPin, HIGH);
    }
    else
    {
        digitalWrite(ledPin, LOW);
    }
  }
}
