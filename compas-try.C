// compas-try.C

Wire.beginTransmission(MPU);
Wire.Write(0x38); // acsess register ? 
// look for compass one in datasheet.

Wire.Write(0x0AH,B0010);// Set CNTL1 regester to continus mesasuremtnt mode 1

wire.read(0x03H,2?/1?);	// read X-axis Lowest 8-bit data
wire.read(0x04H,1);	// read X-axis Hightest 8-bit data

wire.read(0x05H,1?/2?);	// read Y-axis Lowest 8-bit data
wire.read(0x06H,1);	// read Y-axis Highest 8-bit data

wire.read(0x07H,1?/2?);	// read Z-axis Lowest 8-bit data
wire.read(0x08H,1);	// read Z-axis Highest 8-bit data

Measured data is stored in two's compliment andLittle Endian format. axis range from -32760 - 32760 in decimal in 16-bit output

// so bascialy 
// 2 ,8-bit numbers.	given y axis on display = 32, 1 to 1 bit matching, for  size

wire.write(0x0AH,B000);	// power down mode.
// turn device off while not useing ? or at least this bit.
