# Arduino basic components library

This is an ensemble of independent Arduino libraries to manage basic components such as buttons, potentiometers and leds.

Code and functionalities are intentionally trivial and independent to favor fast prototyping, modifications and customization.

Pros:

* **modular** -  completely written in C++ with OOP programming principles and it doesn't interfere with other libraries
* **non-blocking** - delay() function is not used
* **easy to customize**

## Installation
Simply copy the folder of the library you are interested in and import it with `#include <NAME_OF_THE_LIBRARY.h>`.

## Usage

### Button library
Example usage of the button component with this library.

#### Hardware
![Arduino Button Library](http://www.flavioprimo.xyz/wp-content/uploads/2016/12/button_library.png)

#### Software
```C
#include "Arduino.h"
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
}
```

### Potentiometer library
Example usage of the potentiometer component with this library.

#### Hardware
![Arduino Potentiometer Library](http://www.flavioprimo.xyz/wp-content/uploads/2016/12/potentiometer_library.png)

#### Software
```C
#include "Arduino.h"
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
}
```

### Led library
Example usage of the led component with this library.

#### Hardware
![Arduino Led Library](http://www.flavioprimo.xyz/wp-content/uploads/2016/12/led_library.png)

#### Software
```C
#include "Arduino.h"
#include <Led.h>

Led led(2);

void setup() {
}

void loop() {
  led.blinkState(1000, 500);
}
```

## Credits

by [Flavio Primo](https://flavioprimo.xyz/about/)
