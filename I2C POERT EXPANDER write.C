#include <Wire.h>

void setup()
{
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(115200);  // start serial for output
    Serial.println("hello");
}

void loop()
{
  Wire.beginTransmission(0x20);
  
  //  Wire.requestFrom(0x20, 1);   // request 6 bytes from slave device #2
//  Serial.println("1");

  //while(Wire.available())    // slave may send less than requested
//  { 
    
    
  //   Wire.beginTransmission(0x21); // transmit to device #4
  // use hex. convert from bianry, hex 0x , 01
  //                                  0000 , 0001
  //                                   Msb    Lsb
  Wire.write(B00000000);        // sends five bytes
//  Wire.write(x);              // sends one byte
 Serial.println(Wire.endTransmission());    // stop transmitting
    //  Serial.println("2");
 // }

  delay(500);
  
  while(1)
  {
  }
}