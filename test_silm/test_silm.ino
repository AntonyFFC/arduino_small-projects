#include <Servo.h>

Servo esc_1;  // create servo object to control the PWM signal

void setup() {
  esc_1.attach(9);  // make sure to use a PWM capable pin
}

void loop() {  
  set_esc_power(esc_1, 0);  
  delay(500) ;
  set_esc_power(esc_1, 20);
  delay(500) ;
  set_esc_power(esc_1, 40);
  delay(500) ;
  set_esc_power(esc_1, 60);
  delay(500) ;
  set_esc_power(esc_1, 80);
  delay(500) ;
  set_esc_power(esc_1, 100);
  delay(500) ;
  set_esc_power(esc_1, 80);
  delay(500) ;
  set_esc_power(esc_1, 60);
  delay(500) ;
  set_esc_power(esc_1, 40);
  delay(500) ;
  set_esc_power(esc_1, 20);
  delay(500) ;
  set_esc_power(esc_1, 0);
  delay(500) ;
  set_esc_power(esc_1, -20);
  delay(500) ;
  set_esc_power(esc_1, -40);
  delay(500) ;
  set_esc_power(esc_1, -60);
  delay(500) ;
  set_esc_power(esc_1, -80);
  delay(500) ;
  set_esc_power(esc_1, -100);
  delay(500) ;
  set_esc_power(esc_1, -80);
  delay(500) ;
  set_esc_power(esc_1, -60);
  delay(500) ;
  set_esc_power(esc_1, -40);
  delay(500) ;
  set_esc_power(esc_1, -20);
}

void set_esc_power (Servo esc, int power){
  power = constrain(power, -100, 100); //constrain between this range
  int signal_min = 850;
  int signal_max = 1950;
  int signal_output = map(power, -100, 100, signal_min, signal_max); //map(value, fromLow, fromHigh, toLow, toHigh)
  esc.writeMicroseconds(signal_output);
}
