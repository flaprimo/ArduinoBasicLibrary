#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

/**
 * Button library
 * Controls an Arduino button directly connected to GND and a digital pin.
 *
 * by Flavio Primo (2016)
 */

class Button {
  private:
    static const unsigned int DEFAULT_PIN = 5; // default pin at which the button is attached to
    unsigned int _pin; // pin where the button is attached to
    int _state; // keep track of the precedent state of the button (pressed = 1 or not = 0)
    int _toggle; // keep track of the toggle of the button (active = 1 or not active = 0)
    unsigned long _time; // stores the time at which the button was pressed (default = 0)

  public:
    Button(unsigned int pin = DEFAULT_PIN);
    long getEvent();
    int getToggle();
    void printState();
};

#endif //BUTTON_H
