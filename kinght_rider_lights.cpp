/*
 * File: kight_rider_lights.cpp
 * Author: Mazhar Ahmed
 * Board: Arduino Uno r3
 *
 * It will animate 6 LEDs for pin 8, 9, 10, 11, 12, 13
 */

int i = 0;
int incr = 1;
int leds[6] = {8, 9, 10, 11, 12, 13};

void setup() {
  // make all pins as output
  for(int j = 0; j < 6; j++)
  {
    pinMode(leds[j], OUTPUT);
  }
}

void loop() {
  // first turn the selected LED on
  digitalWrite(leds[i], HIGH);

  // turn others off
  for(int j = 0; j < 6; j++)
  {
    if (j == i)
    {
      // don't turn off selected LED
      continue;
    }
    digitalWrite(leds[j], LOW);
  }

  // next step
  i += incr;

  // make negative at the last moment
  if (i == 5 && incr == 1)
  {
    incr = -1;
  }

  // make positive at the first moment
  if (i == 0 && incr == -1)
  {
    incr = 1;
  }

  // now delay with motion tween
  delay(50 + (sin((3.1416 * abs(2.5 - i / 2)) / 5) * 40));
}
