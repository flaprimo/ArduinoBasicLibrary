#include "Led.h"

/**
* Led constructor
*
* by Flavio Primo (2016)
*/
Led::Led(unsigned int pin)
{
  _pin = pin;
  pinMode(pin, OUTPUT);
  _state = LOW;
  _counter = 0;
}

/**
 * Get led state (on=HIGH or off=LOW).
 */
int Led::getState()
{
  return _state;
}

/**
 * Switch the led on.
 */
void Led::on()
{
  if (_state == LOW) {
    _state = HIGH;
    digitalWrite(_pin, HIGH);
  }
}

/**
 * Switch the led off.
 */
void Led::off()
{
  if (_state == HIGH) {
    _state = LOW;
    digitalWrite(_pin, LOW);
  }
}

/**
 * Switch led state.
 */
void Led::switchState()
{
  if (_state == LOW) on();
  else off();
}

/**
 * Reset counter for cycles.
 */
void Led::resetCounter()
{
  _counter = 0;
}

/**
 * Alternate on and off state with milliseconds.
 * Disable delay or it will work erratically.
 */
void Led::blinkState(unsigned int millisOn, unsigned int millisOff)
{
  if (millis() % (millisOn+millisOff) < millisOn) on();
  else off();
}

/**
 * Alternate on and off state with a counter (ok for delay also).
 */
void Led::blinkStateCycles(unsigned int cyclesOn, unsigned int cyclesOff)
{
  if (_counter % (cyclesOn+cyclesOff) < cyclesOn) on();
  else off();

  _counter++;
}
