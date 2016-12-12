#include "Button.h"

/**
 * Button constructor
 *
 * by Flavio Primo (2016)
 */
Button::Button(unsigned int pin)
{
  _pin = pin;
  pinMode(_pin, INPUT_PULLUP);
  _state = 0;
  _toggle = 0;
  _time = 0;
}

/**
 * Get a button event. It returns 0 if not pressed >0 if pressed (the pressed interval time).
 * Keeps also tracks of the toggle.
 * @return
 */
long Button::getEvent()
{
  int currentState = !digitalRead(_pin); // 1 for pressed and 0 for not pressed
  long interval = 0;

  // button pressed: start counting time
  if (currentState && !_state)
    _time = millis();

  // button released: get delta time and toggle
  else if (!currentState && _state) {
    // toggle
    _toggle = !_toggle;

    // time interval
    interval = millis() - _time;
    _time = 0;
  }

  _state = currentState;

  return interval;
}

/**
 * Get updated toggle status.
 * @return
 */
int Button::getToggle()
{
  getEvent();

  return _toggle;
}

/**
 * Print the state over the Serial interface (for debug purposes).
 * Remember to initialize the Serial interface.
 * @return return
 */
void Button::printState()
{
  Serial.println(_state);
}
