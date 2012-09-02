#include "lights.h"
#include "pins.h"

Lights lights;

unsigned long last_button_down = 0;
bool torch_on = false;
int attenuation;
int presses = 0;

void setup() {
  //led_cycle(&lights, PIN_LED_LEFT, 250);
  //led_cycle(&lights, PIN_LED_RIGHT, 250);
  lights.set(PIN_LED_BOTH, 0, 0, 0);

  pinMode(PIN_BUTTON, INPUT_PULLUP);
  attachInterrupt(INT_BUTTON, button_press, CHANGE);
}

void button_press() {
  if 
  presses++;
  if (presses > 3) {
    presses = 1;
  }
  
  

void loop() {
  int red;
  int green;
  int blue;
  // TiLDA can either have one LED lit, or both
  // the same colour.

      red = random(0,255);
      green = random(0,255);
      blue = random(0,255);
      lights.set(PIN_LED_BOTH, red, green, blue);


  delay(1000);

}

