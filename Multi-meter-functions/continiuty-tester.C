// continuity-tester.C

  Wire.beginTransmission(MPU);
// I2C write A , HIGHT;
Wire.write(0x01 );
// I2C write C , HIGHT;
Wire.write(0x04 );
// I2C write F , HIGHT;
Wire.write(0x20);
	// F for aobut 1K resistanse to ground, a pull down.
Wire.endTransmission(true);


while (state == conitiunity-tester)
{
if(AnologRead(A) <= XX)  1024/3.3 = ____ / 2.3 = _____ (2.3V or more.)
{	digitalWrite(buzzer,HIGH);
	HCuOLED3.bitMap ( closed); 
	draw/ refresh screen 3.
}

else 
{	digitalWrite(buzzer,LOW);
	HCuOLED3.bitmap (open);
	draw/ refresh screen 3.
}

// inturupt for button my change state.

}