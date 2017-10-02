 #include <SPI.h> // Only needed for Arduino 1.6.5 and earlier
 #include "SSD1306Spi.h"

#include <DS1307RTC.h>
#include <Wire.h>
#include <Time.h>
 

 #include "A.h"
 
 #include "B.h"
 
 #include "C.h"

  #include "numbers.h"

//adc6

SSD1306Spi display(22, 17, 21);
SSD1306Spi display2(22, 32, 33);
SSD1306Spi display3(22,25 ,26 );
  int rev = 0;
    int Batty = 0;

//char  Nums[10]={ a0_bits, a1_bits, a2_bits, a3_bits, a4_bits, a5_bits, a6_bits, a7_bits, a8_bits, a9_bits};

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println();

Wire.begin(4,0);

  // Initialising the UI will init the display too.
  SPI.begin ();
  SPI.setClockDivider (SPI_CLOCK_DIV2); // this makes it faster ??!!!!  

  pinMode(22, OUTPUT);  // reset pin



  // Pulse Reset low for 10ms
      digitalWrite(22, HIGH);
      delay(1);
      digitalWrite(22, LOW);
      delay(10);
      digitalWrite(22, HIGH);

     delay(10);

Wire.beginTransmission(0x20);
Wire.write(0x00); // IODIRA register
Wire.write(0x00); // set all of port A to outputs
Wire.endTransmission();
      
  display.init();
  Serial.println("i did this bit");
  display2.init();
  Serial.println("i did that bit too");
  display3.init();

  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);

  display2.flipScreenVertically();
  display2.setFont(ArialMT_Plain_10);

  display3.flipScreenVertically();
  display3.setFont(ArialMT_Plain_10);

}




void loop() {
    tmElements_t tm;  // remind RTC of the MCUs existance.
  // clear the display
  display.clear();
  display2.clear();
  display3.clear();

    display.drawXbm(0, 0, 128, 64, A_bits);   // show LCARS "back" "ground"
    display2.drawXbm(0, 0, 128, 64, B_bits);
    display3.drawXbm(0, 0, 128, 64, C_bits);




 // battery ? 
// max adc = 4095, min adc = 0;
 Batty = map(analogRead(34), 1630, 2366, 0, 100); // calibrated for 3.7V lipo
  // draw the POWER bar
  display3.drawProgressBar(15, 1, 70, 8, Batty);
  display3.setFont(ArialMT_Plain_10);             // set small font
  display3.drawString(96, 0, String(Batty) + "%");  // show percentage as number




// read buttons

 Wire.beginTransmission(0x20);
 Wire.write(0x13); // set MCP23017 memory pointer to GPIOB address
 Wire.endTransmission();
 Wire.requestFrom(0x20, 1); // request one byte of data from MCP20317
int inputs=Wire.read(); // store the incoming byte into "inputs"
 if (inputs>0) // if a button was pressed
 {
 // Serial.println(inputs); // display the contents of the GPIOB register in binary
// delay(200); // for debounce
display3.drawProgressBar(15, 30, 89, 8, inputs);  // for debugging so i can see this move when buttons pushed
 }




// do a thing with buttons
{
  switch(inputs)
        {
          case 47:  // back button // all off 
            {
                  Wire.beginTransmission(0x20);
                  Wire.write(0x12); // address port A
                  Wire.write(0x00);  // value to send
                  Wire.endTransmission();
                  Serial.println("back");
            } break;

       case 62:  // back button // laser on
            {
                  Wire.beginTransmission(0x20);
                  Wire.write(0x12); // address port A
                  Wire.write(0xA0);  // value to send
                  Wire.endTransmission();
                  Serial.println("62");
            } break;

       case 61:  // back button // light on
            {
                  Wire.beginTransmission(0x20);
                  Wire.write(0x12); // address port A
                  Wire.write(0x40);  // value to send
                  Wire.endTransmission();
                  Serial.println("61");
            } break;

       case 59:  // back button // all on! 
            {
                  Wire.beginTransmission(0x20);
                  Wire.write(0x12); // address port A
                  Wire.write(0xF0);  // value to send
                  Wire.endTransmission();
                  Serial.println("59");
            } break;
        }

}






  // fun scrolling numbers

    // 18 x 28 pixes for numbers
    switch(rev)
      {
        case 0:
          {
            display.drawXbm((67-42), 25, 18, 28, a0_bits);    // Hour (10)         
            display.drawXbm((67-20), 25, 18, 28, a0_bits);    // Hour ( 1)

            display.drawXbm(67, 25, 10, 28, col_bits);        // colon
            
            display.drawXbm((67+11), 25, 18, 28, a0_bits);    // Minit (10)
            display.drawXbm((67+28+4), 25, 18, 28, a0_bits);  // Minit ( 1)

          }  break;

          case 1:
          {
            display.drawXbm((67-42), 25, 18, 28, a1_bits);         
            display.drawXbm((67-20), 25, 18, 28, a1_bits);;

            display.drawXbm(67, 25, 10, 28, col_bits);
            
            display.drawXbm((67+11), 25, 18, 28, a1_bits);
            display.drawXbm((67+28+4), 25, 18, 28, a1_bits);
          }  break;

          case 2:
          {
            display.drawXbm((67-42), 25, 18, 28, a2_bits);         
            display.drawXbm((67-20), 25, 18, 28, a2_bits);;

            display.drawXbm(67, 25, 10, 28, col_bits);
            
            display.drawXbm((67+11), 25, 18, 28, a2_bits);
            display.drawXbm((67+28+4), 25, 18, 28, a2_bits);
          }  break;

          case 3:
          {
            display.drawXbm((67-42), 25, 18, 28, a3_bits);         
            display.drawXbm((67-20), 25, 18, 28, a3_bits);;

            display.drawXbm(67, 25, 10, 28, col_bits);
            
            display.drawXbm((67+11), 25, 18, 28, a3_bits);
            display.drawXbm((67+28+4), 25, 18, 28, a3_bits);           
          }  break;

          case 4:
          {
            display.drawXbm((67-42), 25, 18, 28, a4_bits);         
            display.drawXbm((67-20), 25, 18, 28, a4_bits);;

            display.drawXbm(67, 25, 10, 28, col_bits);
            
            display.drawXbm((67+11), 25, 18, 28, a4_bits);
            display.drawXbm((67+28+4), 25, 18, 28, a4_bits);
          }  break;

          case 5:
          {
            display.drawXbm((67-42), 25, 18, 28, a5_bits);         
            display.drawXbm((67-20), 25, 18, 28, a5_bits);;

            display.drawXbm(67, 25, 10, 28, col_bits);
            
            display.drawXbm((67+11), 25, 18, 28, a5_bits);
            display.drawXbm((67+28+4), 25, 18, 28, a5_bits);
          }  break;

          case 6:
          {
            display.drawXbm((67-42), 25, 18, 28, a6_bits);         
            display.drawXbm((67-20), 25, 18, 28, a6_bits);;

            display.drawXbm(67, 25, 10, 28, col_bits);
            
            display.drawXbm((67+11), 25, 18, 28, a6_bits);
            display.drawXbm((67+28+4), 25, 18, 28, a6_bits);
          }  break;

          case 7:
          {
            display.drawXbm((67-42), 25, 18, 28, a7_bits);         
            display.drawXbm((67-20), 25, 18, 28, a7_bits);;

            display.drawXbm(67, 25, 10, 28, col_bits);
            
            display.drawXbm((67+11), 25, 18, 28, a7_bits);
            display.drawXbm((67+28+4), 25, 18, 28, a7_bits);
          }  break;

          case 8:
          {
            display.drawXbm((67-42), 25, 18, 28, a8_bits);         
            display.drawXbm((67-20), 25, 18, 28, a8_bits);;

            display.drawXbm(67, 25, 10, 28, col_bits);
            
            display.drawXbm((67+11), 25, 18, 28, a8_bits);
            display.drawXbm((67+28+4), 25, 18, 28, a8_bits);         
          }  break;

          case 9:
          {
            display.drawXbm((67-42), 25, 18, 28, a9_bits);         
            display.drawXbm((67-20), 25, 18, 28, a9_bits);;

            display.drawXbm(67, 25, 10, 28, col_bits);
            
            display.drawXbm((67+11), 25, 18, 28, a9_bits);
            display.drawXbm((67+28+4), 25, 18, 28, a9_bits);          
          }  break;

          case 10:
          {
            display.drawXbm((67-42), 25, 18, 28, a0_bits);         
            display.drawXbm((67-20), 25, 18, 28, a4_bits);;

            display.drawXbm(67, 25, 10, 28, col_bits);
            
            display.drawXbm((67+11), 25, 18, 28, a2_bits);
            display.drawXbm((67+28+4), 25, 18, 28, a0_bits);            
          }  break;
      }

 






// RTC things
    if (RTC.read(tm)) {
                          print2digits(tm.Hour);
                          print2digits(tm.Minute);
                          print2digits(tm.Second);
                      }
  
int sec = print2digits(tm.Second);    // convert recovered values to int
int Min = print2digits(tm.Minute);
int hor = print2digits(tm.Hour);

    display3.setTextAlignment(TEXT_ALIGN_LEFT);   // all of this just displays the time normaly with defult font
    display3.setFont(ArialMT_Plain_10);
     
    display2.drawString(48, 30, String(sec));
    display2.setFont(ArialMT_Plain_16);
    display2.drawString(26, 30, String(Min)+ ":");
    display2.drawString(4, 30,String(hor)+ ":");

// date,
// 1st | 2nd | 3rd | 4th 5th ... ect 
// switch ? (to get the right letters after the day)

      display2.setFont(ArialMT_Plain_10);
      display2.drawString(20, 0, String(tm.Day) + "th");  // th is most comon after a day number
      display2.drawString(42, 0, String(tm.Month));
      display2.drawString(84, 0, String(tmYearToCalendar(tm.Year)));

      
  // write the buffer to the display
  display.display();
  display2.display();
  display3.display();

delay(200);





   { rev = rev + 1; }   // increase the counter! 
 if(rev == 11)
  { rev = 0; }
   
  
}


int print2digits(int number) {    // needed for playing with RTC vales recived
  if (number >= 0 && number < 10) {
 //   Serial.write('0');
  }
//  Serial.print(number);
return number;
}


