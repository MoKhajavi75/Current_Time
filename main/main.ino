// Current Time, Arduino by MohamadKh75
// 2017-07-01
// ********************


#include <Wire.h>   //used for I2C
#include "RTClib.h"   //Download and paste it in ~\Arduino\libraries


RTC_DS1307 RTC;

void setup ()
{
  Serial.begin(9600);   //Set the serial conncetion to check the result in Serial Monitor
  Wire.begin();
  RTC.begin();
  
  if (! RTC.isrunning())
    {
    Serial.println("RTC is NOT running!");
    RTC.adjust(DateTime(__DATE__, __TIME__));   //Sets the RTC to the date & time this sketch was compiled
    }
}


void loop ()
{
  DateTime now = RTC.now();
    
  Serial.print(now.year(), DEC);
  Serial.print('/');
    
  Serial.print(now.month(), DEC);
  Serial.print('/');
    
  Serial.print(now.day(), DEC);
    
  Serial.print(' ');
    
  Serial.print(now.hour(), DEC);
  Serial.print(':');
    
  Serial.print(now.minute(), DEC);
  Serial.print(':');
    
  Serial.print(now.second(), DEC);
  Serial.println(); 
    
  delay(1000);    //wait for 1 second!
}
