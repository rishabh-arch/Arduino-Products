#include <Arduino.h>
#include <TM1637Display.h>
#include <EEPROM.h>

long int a, x = 0, z = 300;
uint8_t EEPROMaddress0 = 0;
uint8_t EEPROMaddress1 = 1;
uint8_t EEPROMaddress2 = 2;
const int e18_sensor = 7;

int numArray[3];
int totalCounts = 1000;
String num;
#define CLK 2
#define DIO 3

#define TEST_DELAY 2000

TM1637Display display(CLK, DIO);

int Int_of_numArray=0;
int ArrayToInt(int numArray[], int size)
{
  int value = 0;
  for (int i = 0; i < size; i++)
  {
    value *= 10;
    value += numArray[i];
  }
  return value;
}
void setup()
{
  numArray[0] = EEPROM.read(EEPROMaddress0);
  numArray[1] = EEPROM.read(EEPROMaddress1);
  numArray[2] = EEPROM.read(EEPROMaddress2);
  Int_of_numArray = ArrayToInt(numArray, 3);
  Serial.begin(9600);
  pinMode (e18_sensor, INPUT);
}

void loop()
{
  int state = digitalRead(e18_sensor);
  display.setBrightness(0x0f);
  
  // int k;
  // uint8_t data[] = {0xff, 0xff, 0xff, 0xff};
  // uint8_t blank[] = {0x00, 0x00, 0x00, 0x00};
  // num = String(EEPROM.read(EEPROMaddress0)) + String(EEPROM.read(EEPROMaddress1)) + String(EEPROM.read(EEPROMaddress2));
  // display.showNumberDec(num.toInt(), false);

  //
  for (int i = ArrayToInt(numArray, 3); i < totalCounts; i++)
  {
   

    int temp = Int_of_numArray;
    for (int j = 2; j >= 0; j--)
    {
      numArray[j] = temp % 10;
      temp /= 10;
    }
    EEPROM.write(EEPROMaddress0, numArray[0]);
    EEPROM.write(EEPROMaddress1, numArray[1]);
    EEPROM.write(EEPROMaddress2, numArray[2]);

    display.showNumberDec(Int_of_numArray, false);

    if (Int_of_numArray ==totalCounts-1)
    {
      EEPROM.write(EEPROMaddress0, 0);
      EEPROM.write(EEPROMaddress1, 0);
      EEPROM.write(EEPROMaddress2, 0);
      Int_of_numArray = 0;
      display.showNumberDec(0, true);
    }
    Int_of_numArray++;
    delay(500);
  }
}
