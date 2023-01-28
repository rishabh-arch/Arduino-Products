#include <Arduino.h>

#include <SevenSegmentTM1637.h>
long int a=0, x = 0, z = 300;

const int e18_sensor = 7;
int sen =1;
int totalCounts = 1000;
String num;
#define CLK 2
#define DIO 3

//#define TEST_DELAY 2000

SevenSegmentTM1637 display(CLK, DIO);

void setup()
{
  display.begin();    
  display.setBacklight(100);
  Serial.begin(9600);
  pinMode (e18_sensor, INPUT);
  display.print(0);
}

void loop()
{
  int state = digitalRead(e18_sensor);
 
   while(state==HIGH && sen==1){
    
    Serial.println(a);
     sen=2;
   }

   
while(state== LOW && sen ==2){
 
    a=a+1;
     sen=1;
  
    if(a==10000){
    display.clear();
    a=1;
   
    }
     display.print(a);
      } 
   
}
