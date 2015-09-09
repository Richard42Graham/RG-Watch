void Vmeter ()
{
      int con = 1;
     int X = 0;
     int duty = 0;
     int stat = 0;


while (con = 1);
{    // V meter stuff

if((DigitalRead(7)) == 1)
{
    con = 0;
// if escape button pressed. exit mode on next cycel.
}

// initate font
    // have all the setup before tge loop to save time and power.
// initate size
HCuOLED1.ClearBuffer;
HCuOLED1.Cursor(0,0);

HCuOLED1.Bitmap(128,8, // background // );

HCuOLED1.Cursor(40,1); // set position of V1 readout.
HCUOLED1.SetFont(LCDLarge_24pt); 
HCuOLED1.(1,5 (anologRead(A1)); 
  // posibly scale to read highter voltages? 

HCuOLED1.Cursor(40,5); // set position of V2 readout.
HCuOLED1(3,5 (anologRead(A2));

//time? 

HCuOLED1.Refresh;

// draw graph? 1
HCuOLED2.ClearBuffer;

// draw background for screen 2.

map A1 to 0-9.
HCuOLED2.Cursor(0,0);
//add possition offset.
HCuOLED2.Pixel (X,(AnologRead(A1) + 0)); // pixel Y = A1 + border offset.

 // draw graph? 1
//map A2 to 0-9.
HCuOLED2.Cursor(0,12);
//add possition offset.
HCuOLED2.Pixel (X  ,((AnologRead(A2) + 0)); // pixel Y = A1 + border offset.

HCuOLED2.Refresh;

if(X > 126) // increments the X axis of the graphs.
{ 
     X = 0;
}
       else
            {
                 X++;
             }

if((DigitalRead(A5)) == 1)
 // continueity tester.
{
       DigitalWrite(buzzer pin, HIGH);
       // Draw something to show continuity
}
else
         {
               DigitalWrite(buzzer pin, LOW);
          }

// // PWM? // // 

if(DigitalRead(button1) == 1)
// duty cycal up
{
     duty = duty + 5;

           if(duty >= 255)  // if equal or greater than max duty cycal
                    {
                           duty = 255;
                           // print "at max PWM" on screen.
                     }
}


if(DigitalRead(button3) == 1)
 // duty cycal down
{
     duty = duty - 5;

          if(duty <= 0)  // if equal or less than min duty cycal
                    {
                           duty = 0;
                           // print "at min PWM" on screen.
                     }
}



if( DigitalRead(button2) == 1)
{

       Delay(10);
            if(DigitalRead(button2) == 1)
                       {
                                if( stat == 1)
                                         {
                                                stat = 3; // long hold while on to go to PWM state
                                          }
                                                  else
                                                              {
                                                                    stat = 1; long hold while off to go to ON state.
                                                               }
                         }
                                 else
                                      {
                                            stat = 0; // tap to turn off
                                      }
                         
}

    // add state change detection to trigure this to save battery. maybe
switch(atat)
{
      
       case : 0
              {
                    AnologWrite(PWMpin, 0); // power off
                    DigitalWrite (PWMpin, LOW);
                    // screen indication.
               }

       case : 1
              {
                     DigitalWite(PWMpin,HIGH); power on
                     // screen indication.
               }

        case : 3
              {
                     AnologWrite(PWMpin,duty); PWM at duty cycal.
                     // screen indication.
               }

DEFULT:
          {
                 DigitalWrite(PWMpin,LOW);
                 // screen indication.
           }
}
// stat 0 === off
// stat 1 === on
// stat 3 === PWM


// alleleromitor / Gryonitor.
HCuOLED3.Clear;
// code magic stuff.
HCuOLED3.Refeesh;

}