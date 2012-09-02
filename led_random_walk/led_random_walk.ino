#include "lights.h"
#include "pins.h"

Lights lights;
int Red = 128, Green = 128, Blue = 128;
unsigned long last_button_down = 0;
bool torch_on = false;
int presses = 0;

void setup() {
  //led_cycle(&lights, PIN_LED_LEFT, 250);
  //led_cycle(&lights, PIN_LED_RIGHT, 250);
  lights.set(PIN_LED_BOTH, 0, 0, 0);

  pinMode(PIN_BUTTON, INPUT_PULLUP);
  attachInterrupt(INT_BUTTON, button_press, CHANGE);
  last_button_down = millis();
}

void button_press() {
  
  if (last_button_down > 1000) {
  presses++;
  if (presses > 3) {
    presses = 1;
  }
  }
  last_button_down = millis();
}

void loop()
{  
  byte randRed;
  byte randGreen;
  byte randBlue;
  randRed = random(0,2);
  randGreen = random(0,2);
  randBlue = random(0,2);
  
  int i = 0;
  for (i=0; i<5; i++) {
      delay(5);
      if ( randRed == 1 ) {
        if ( Red < 255 ) {
          Red++;
        }
      } else {
        if ( Red > 0 ) {
          Red--;
        }
      }
      if (randGreen == 1) {
        if ( Green < 255 ) {
          Green++;
        }
      } else {
        if ( Green > 0 ) {
          Green--;
        }
      }
      if (randBlue == 1) {
        if ( Blue < 255 ) { 
          Blue++;
        }
      } else {
        if ( Blue > 1 ) {
          Blue--;
        }
      }
  
      lights.set(PIN_LED_BOTH, Red/presses, Green/presses, Blue/presses);
  }
}





