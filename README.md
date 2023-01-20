# EEPROM With 999 Numbers 

This is a simple program that allows you to store 999 numbers in the EEPROM of your Arduino. Even in UNO boards, which have only 1Kb of EEPROM memory.

## How to use it
just upload the code to your Arduino and open the Serial Monitor. You will see a menu with the following options:


## E18-D80NK IR Obstacle Avoidance Proximity Sensor

![https://circuitdigest.com/microcontroller-projects/interfacing-e18d80nk-ir-proximity-sensor-with-arduino](https://circuitdigest.com/sites/default/files/inlineimages/u3/E18-D80NK-Sensor-Pinout.png)


## EEPROM BASIC COMMANDS


```c
#include <EEPROM.h>

uint8_t EEPROMaddress = 0;
uint8_t EEPROM_value;
void setup()
{
 EEPROM_value  = EEPROM.read(EEPROMaddress);
}
  void loop()
{
  EEPROM.write(EEPROMaddress, 1234);

}
```

## TM1637Display

```c
#include <TM1637Display.h>
#define CLK 2
#define DIO 3
TM1637Display display(CLK, DIO);

void loop()
{
  display.setBrightness(0x0f);
   display.showNumberDec(1234, false);
}
```

