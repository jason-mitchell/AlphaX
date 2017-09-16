//
//
//
//
//
//
//-----------------------------------------------------------------------------------------------------------------------------------------



// Includes
//--------------------------------------------------------
#include <msp430g2231.h>


// Definitions
//-------------------------------------------------------
#define ROW1	BIT3
#define ROW2	BIT4
#define COL1	BIT5
#define COL2	BIT6
#define COL3	BIT7


unsigned int IR_TIME = 0;
unsigned char TRANSMIT_REQ = 0;
unsigned char keycode;
unsigned char cnt;

unsigned char scancnt;

// Local Functions
//------------------

void Wait(unsigned int delay){
	unsigned int ttr = 0;
	for (ttr = 0; ttr < delay; ttr++){
		__delay_cycles(1000);
	}

}

// Name: ScanKeypad
// Function: Scan keypad to determine which key is pressed
//-----------------------------------------------------------
unsigned char ScanKeypad(void){

		// Lower all column drivers
		P1OUT &= ~COL1;
		P1OUT &= ~COL2;
		P1OUT &= ~COL3;

		// Column 1
		P1OUT |= COL1;
		switch(P1IN & 0x18){
		case 0x08:
			P1OUT &= ~COL1;
			return 0x01;

		case 0x10:
			P1OUT &= ~COL1;
			return 0x02;
		}

		P1OUT &= ~ COL1;

		// Column 2
		P1OUT |= COL2;
		switch(P1IN & 0x18){
		case 0x08:
			P1OUT &= ~COL2;
			return 0x03;

		case 0x10:
			P1OUT &= ~COL2;
			return 0x04;
		}

		P1OUT &= ~COL2;

		// Column 3
		P1OUT |= COL3;
		switch(P1IN & 0x18){
		case 0x08:
			P1OUT &= ~COL3;
			return 0x05;

		case 0x10:
			P1OUT &= ~COL3;
			return 0x06;
		}

		P1OUT &= ~COL3;

		return 0;
}

//----------------------------------------------------
// Name: PulseTimer
// Function: Generates accurate pulse times
// Parameters: Time period desired in uSeconds
// Returns: void
//-----------------------------------------------------
void PulseTimer(unsigned int time){
	unsigned int TCOMP;


	IR_TIME = 0;					// Reset timing register
	WDTCTL = WDT_MDLY_0_064; 		// Enable WDT with a period of 64uS

	TCOMP = (time / 64) - 2;
	for(;;){
		if(IR_TIME >= TCOMP){
			WDTCTL = WDTPW + WDTHOLD;					// Disable WDT
			break;
		}
	}
}



//----------------------------------------------------------------------------------------------------
// Name: PWMPinControl
// Function: Controls the drive of the PWM pin
//           This means when the CPU is halted we don't end up with the pin sitting at logic 1
//----------------------------------------------------------------------------------------------------
void PWMPinControl(unsigned char CTL){
	if(CTL == 0){
		P1DIR &= ~BIT2;		// PWM pin
	} else {
		P1DIR |= BIT2;		// PWM pin
	}

}

//----------------------------------------------------------------
// Name: TransmitBit
// Function: Generate the symbol pattern for a logic 0 or 1
//----------------------------------------------------------------
void TransmitBit(unsigned char bit){
	PWMPinControl(1);				// enable 38kHz IR modulation
	PulseTimer(562);				// 562uS pulse
	PWMPinControl(0);
	if(bit == 0){
		PulseTimer(562);
	} else {
		PulseTimer(1675);
	}
}


// Name: SetColumnDriversAll
// Function: Set all Column drivers = 1
// Parameters: void
// Returns: void
//----------------------------------------
void SetColumnDriversAll(void){
	   P1OUT |= COL1;
	   P1OUT |= COL2;
	   P1OUT |= COL3;

}

//----------------------------------------------------------------
// Name: TransmitNEC
// Function: Generates a complete NEC IR protocol frame
// Parameters: Address field, Command field
// Returns: void
//----------------------------------------------------------------
void TransmitNEC(unsigned int address, unsigned int command){

	unsigned char bitcount;

	// First, generate the start-of-frame
	PWMPinControl(1);								// Start 38kHz modulation
	PulseTimer(8400);								// 9mS leading pulse
	PWMPinControl(0);								// Stop 38kHz modulation
	PulseTimer(4090);								// 4.5mS gap

	// Transmit address LSB first
	for(bitcount = 0; bitcount < 16; bitcount++){
		if ((address & 0x0001) == 0x01){
			TransmitBit(1);
		} else {
			TransmitBit(0);
		}
		address = address >> 1;
	}

	// Transmit command LSB first
	for(bitcount = 0; bitcount < 16; bitcount++){
		if ((command & 0x0001) == 0x01){
			TransmitBit(1);
		} else {
			TransmitBit(0);
		}
		command = command >> 1;
	}

	TransmitBit(0);			// This is required... not sure why but it doesn't work if deleted
}
//--------------------------------------------------------------------------------------
// 										Main Function
//--------------------------------------------------------------------------------------
void main(void) {

	   WDTCTL = WDTPW + WDTHOLD;					// Disable WDT
	   IE1 |= WDTIE; 								// Enable WDT interrupt
	   TRANSMIT_REQ = 0;							// Clear flag
	   DCOCTL = 0;                               	// Select lowest DCOx and MODx settings
	   BCSCTL1 = CALBC1_1MHZ;                    	// Set range
	   DCOCTL = CALDCO_1MHZ;                     	// Set DCO step + modulation */
	   BCSCTL2 = 0x00;								// SMCLK /4 (done here to reduce the clock jitter problem)

	   // Configure I/O pins
	   P1DIR |= BIT0;								// P1.0 to output (DEBUG purposes)
	   P1DIR |= BIT2;             					// P1.2 to output
	   P1DIR |= COL1;
	   P1DIR |= COL2;
	   P1DIR |= COL3;

	   P1SEL |= BIT2;             					// P1.2 to TA0.1
	   P1OUT &= ~BIT0;								// Set debug pin to low

	   SetColumnDriversAll();

	   // Configure Timer 1 (TA0.0)
	   //---------------------------------
	   TACTL = TACLR;								// Clear Timer

	   // Configure Capture/Compare to output a 38kHz clock
	   // Closest we can get is 39.07kHz

	   CCR0 = 25-1;             				// PWM Period       50 = 20kHz
	   CCTL1 = OUTMOD_7;          				// CCR1 reset/set
	   CCR1 = 12;                				// CCR1 PWM duty cycle 50% is given if this value = CCR0 / 2
	   TACTL = TASSEL_2 + MC_1;   				// SMCLK, up mode, timer running

	   // Port 1 Interrupts Enabled
	   P1IES = 0x00;							// This register MUST be set up
	   P1IE |= ROW1;
	   P1IE |= ROW2;


		__enable_interrupt();					// Enable System interrupts
		PWMPinControl(0);						// PWM pin disabled
		_BIS_SR(LPM3_bits + GIE); 				// Enter LPM3 w/interrupt // was LPM3


	//------------------------------------------------------
	// Main Handling Loop
	//-----------------------------------------------------
	for(;;) {

		// Execution begins here when exiting LPM
		Wait(3);						// Key Debounce
		do{
			keycode = ScanKeypad();			// Scan keypad
			SetColumnDriversAll();
			if (keycode > 0){
				P1OUT |= BIT0;
				switch(keycode){
					case 0x01:
					TransmitNEC(0xC7F8, 0x0738);
					break;

					case 0x02:
					TransmitNEC(0xC7F8, 0x0728);
					break;

				}

			} else {
				break;			// Keypress ceases to be valid, we exit!
			}

			// Code was transmitted, we wait a delay and then scan the keypad again
			// This means for keys held down, repeated packets are transmitted
			Wait(50);

		} while (1);

		// We are now finished with transmission, we prepare to shut down the system.

		Wait(50);								// Wait
		P1OUT &= ~BIT0;							// LED off as we're inactive
		P1IFG = 0x0;							// Clear pending IRQs
		_BIS_SR(LPM3_bits + GIE); 				// Enter LPM3 w/interrupt
		// End of active session

	}
}

// Watchdog Timer interrupt service routine
// Used here as a timer
//-----------------------------------------
#pragma vector=WDT_VECTOR
__interrupt void watchdog_timer(void){
	IR_TIME++;

}

// Port 1 interrupt service routine - executed when buttons are pressed
//-----------------------------------------------------------------------
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void){
		P1IFG = 0x0;					// Clear interrupt
		_BIC_SR(LPM3_EXIT); 			// Wake up
}

