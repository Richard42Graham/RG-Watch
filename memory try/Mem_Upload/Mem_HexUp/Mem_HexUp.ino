#include <SPI.h>

#define MEM_CS 5

#define WREN  6

#define LEDPIN 9

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void fmWriteEnable() {
  digitalWrite(MEM_CS, LOW);
  SPI.transfer(WREN);
  digitalWrite(MEM_CS, HIGH);
}

void setup() {

  delay(1000);

  pinMode(LEDPIN, OUTPUT);
  digitalWrite(LEDPIN, LOW);

  Serial.begin(9600);
  //Serial.println("Startup...");
  inputString.reserve(200);

  pinMode(MEM_CS, OUTPUT);
  digitalWrite(MEM_CS, HIGH);

  SPI.setDataMode(SPI_MODE0);
  SPI.setClockDivider(SPI_CLOCK_DIV4);
  SPI.begin();

  fmWriteEnable();

}

unsigned int hexToDec(String hexString) {

  unsigned int decValue = 0;
  int nextInt;

  for (int i = 0; i < hexString.length(); i++) {

    nextInt = int(hexString.charAt(i));
    if (nextInt >= 48 && nextInt <= 57) nextInt = map(nextInt, 48, 57, 0, 9);
    if (nextInt >= 65 && nextInt <= 70) nextInt = map(nextInt, 65, 70, 10, 15);
    if (nextInt >= 97 && nextInt <= 102) nextInt = map(nextInt, 97, 102, 10, 15);
    nextInt = constrain(nextInt, 0, 15);

    decValue = (decValue * 16) + nextInt;
  }

  return decValue;
}

void loop() {
  
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }

  if (stringComplete) {

    digitalWrite(LEDPIN, HIGH);

    int ad1 = hexToDec("0x00" + inputString.substring(2, 4));
    int ad2 = hexToDec("0x00" + inputString.substring(7, 9));
    int ad3 = hexToDec("0x00" + inputString.substring(12, 14));
    int ad4 = hexToDec("0x00" + inputString.substring(18, 19));

    int data = hexToDec("0x00" + inputString.substring(22, 24));

    digitalWrite(MEM_CS, LOW);
    SPI.transfer(0x12);//write;
    SPI.transfer((byte)ad4);
    SPI.transfer((byte)ad3);
    SPI.transfer((byte)ad2);
    SPI.transfer((byte)ad1);

    SPI.transfer((byte)data);

    digitalWrite(MEM_CS, HIGH);
    digitalWrite(LEDPIN, LOW);

    stringComplete = false;
    inputString = "";

  }

}
