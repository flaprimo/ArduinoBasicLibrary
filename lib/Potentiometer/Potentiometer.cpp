#include "Potentiometer.h"

/**
 * Potentiometer constructor
 *
 * by Flavio Primo (2016)
 */
Potentiometer::Potentiometer(unsigned int pin, long minValue, long maxValue)
{
  _pin = pin;
  _minValue = minValue;
  _maxValue = maxValue;
}

/**
 * Directly read the potentiometer value
 * @return
 */
long Potentiometer::getValue()
{
  return analogRead(_pin);
}

/**
 * Map current potentiometer current value to given min/max values in long format.
 * @return
 */
long Potentiometer::getMappedValue(long toMinValue, long toMaxValue)
{
  return map(getValue(), _minValue, _maxValue, toMinValue, toMaxValue);
}

/**
 * Map current potentiometer current value to given min/max values in double format.
 * @return
 */
double Potentiometer::getDoubleMappedValue(double toMinValue, double toMaxValue)
{
  return (getValue() - _minValue) * (toMaxValue - toMinValue) /
    (_maxValue - _minValue) + toMinValue;
}
