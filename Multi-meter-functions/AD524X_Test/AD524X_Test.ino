//
//    FILE: AD524X_sawtooth.ino
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.01
// PURPOSE: AD524X demo program
//    DATE: 2013-10-12
//     URL:
//
// Released to the public domain
//

#include "AD524X.h"
#include "Wire.h"

AD524X AD01(0x2C);  // AD0 & AD1 == GND

int var = 0;
int R = 0;
int T = 0;
int Res =0;
int V = 0;

void setup()
{
    Serial.begin(115200);
    Serial.print("\nStart AD524X_sawtooth : ");
    Serial.println(AD524X_VERSION);
    Serial.println("resistor testing now");
    Wire.begin();
    TWBR = 72;  // 100KHz
    
    AD01.write(1, 0,HIGH,HIGH);
    AD01.write(0, 0,HIGH,HIGH);
    
    //  int tick = 0
}

void loop()
{
    while(T == 0)
    {  
        Serial.println(analogRead(A0));
      
        if(analogRead(A0) <= 512)
        {
            var ++;
            AD01.write(1, var,HIGH,HIGH);
            Serial.println(var);
        }
        else 
        {
            Serial.println("found resister");
            R =  map( var, 0, 255, 0, 100000);
        //    V = map(analogRead(A0), 0, 1024 , 0 ,5);
            R = (R - 400);
       //       Serial.println(R);
       //       Serial.println(V);
//            Res = ( analogRead(A0)+ (analogRead(A0) * var )  );
            
         //          Res = ( R ) / (-5 + V);
//   Res = ( R ) / (-(1024) + analogRead(A0))
         //   R =  map( var, 0, 255, 0, 100000);
            Serial.println(R);
            Serial.print(" stuffs hopefully ohms");
            T = 1;
        }


    }
      
    if(T == 1)
    {
        AD01.write(1, 255,LOW,LOW);
        AD01.write(0, 255,LOW,LOW);
        Serial.println(R);
        Serial.print(" ohms");
        Serial.println("done, shutting down");
        delay(10000);
        while (1);
    }

}

