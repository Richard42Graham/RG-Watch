// inturpt handler

// when inturput triggured this will be called

switch( Wire.requestFrom(0x20, 1) )	// request 1 byte from I2C port expander 

// set adress bits right

{
	case 0: // MCU ? 
		{
			state = 1;
			// wake up watch from sleep
			// state 0 == sleep.
		} break;




	case 1: // button 1
		{

		} break;

	case 2:	// button 2
		{

		} break;

	case 3:	// button 3
		{

		} break;

	case 4:	// button escape;
		{

		} break;

	case 5:	// button Enter
		{

		} break;




	case 6:	// charge full (LED)
		{
			state = H; 	// ? a dedicated screen for fully charged.
		} break;

	case 7: // charing (LED)
		{
			state = L;	// ? a dedicated screen for chargeing and lil gif :P
		} break;



// posibly add cases for multi press such as put light on regardless of state.



