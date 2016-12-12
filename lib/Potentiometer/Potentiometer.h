#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include <Arduino.h>

/**
 * Potentiometer library
 * Controls an Arduino potentiometer directly connected to 5V, GND and an analog pin.
 */
class Potentiometer {
  private:
    static const unsigned int DEFAULT_PIN = A0; // default pin at which the potentiometer is attached to
    static const int DEFAULT_MIN_VALUE = 0; // default min value read from the potentiometer
    static const int DEFAULT_MAX_VALUE = 1023; // default max value read from the potentiometer
    unsigned int _pin; // pin where the potentiometer is attached to
    long _minValue; // min value to map to the potentiometer
    long _maxValue; // max value to map to the potentiometer

  public:
    Potentiometer(unsigned int pin = DEFAULT_PIN, long minValue = DEFAULT_MIN_VALUE,
      long maxValue = DEFAULT_MAX_VALUE);
    long getValue();
    long getMappedValue(long toMinValue, long toMaxValue);
    double getDoubleMappedValue(double toMinValue, double toMaxValue);
};

#endif //POTENTIOMETER_H
