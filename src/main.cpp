#include "Arduino.h"

/*
 * Potentiometer Library example
 */
/*
#include <Potentiometer.h>

Potentiometer potentiometer;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println(potentiometer.getValue());
  Serial.println(potentiometer.getMappedValue(0, 5));
  Serial.println(potentiometer.getDoubleMappedValue(0, 5));

  delay(200);
}*/

/*
 * Button Library example
 */
/*
#include <Button.h>

Button button;

void setup()
{
 // initialize LED digital pin as an output.
 pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  button.getEvent();

  if (button.getToggle())
    digitalWrite(LED_BUILTIN, HIGH);
  else
    digitalWrite(LED_BUILTIN, LOW);

  delay(100);
}*/

/*
 * Led Library example
 */

#include <Led.h>

Led led;

void setup() {
}

void loop() {
  led.blinkState(1000, 500);
}
