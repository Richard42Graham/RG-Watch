#include <Wire.h>

void setup()
{
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(115200);  // start serial for output
    Serial.println("hello");
}

void loop()
{
    Wire.requestFrom(0x20, 1);   // request 6 bytes from slave device #2
//  Serial.println("1");
  while(Wire.available())    // slave may send less than requested
  { 
    byte c = Wire.read();    // receive a byte as character
    Serial.println(c, BIN);         // print the characteraracter
    //  Serial.println("2");
  }

  delay(500);
}


