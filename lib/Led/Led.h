#ifndef LED_H
#define LED_H

#include <Arduino.h>

/**
 * Led library
 * Controls an Arduino led integrated in the board or an external one.
 * The external led should be properly connected on the positive side with a
 * resistor to the pin and with the ground.
 *
 * by Flavio Primo (2016)
 */

class Led {
  private:
    static const unsigned int DEFAULT_PIN = 13; // default pin at which the led is attached to
    unsigned int _pin; // pin where the led is attached to
    int _state; // state (on=HIGH or off=LOW) of the led
    unsigned int _counter; // counter

  public:
    Led(unsigned int pin = DEFAULT_PIN);
    int getState();
    void on();
    void off();
    void switchState();
    void resetCounter();
    void blinkState(unsigned int millisOn, unsigned int millisOff);
    void blinkStateCycles(unsigned int cyclesOn, unsigned int cyclesOff);
};

#endif //LED_H
