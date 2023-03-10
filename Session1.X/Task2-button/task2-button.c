#define F_CPU 3333333UL

#include <avr/io.h>
#include <util/delay.h>

// LED0, PF5
#define LED0 5

// Check out the ATmega4809 Curiosity Nano Hardware User Guide to find
// the correct port and pin for the button
#define SW0 // -- Fill in the pin for the button here ---

int main(void) {
    // We want to send signals to the LEDs, in order to turn it off and on.
    // We also want to be able to read the button.
    // This is done by setting bits in the PORTx.DIR register (in this case
    // PORTF.DIR and PORTF.DIR)
    // PORTx.DIR: 1 is output, 0 is input
    //
    // LED: 1 LED is off, 0 LED is on
    // Button: 1 Button is open, 0 button is pressed
    //
    // Bit set logic:
    // Set to 1: REG |= ( 1 << BIT_POS )
    // Set to 0: REG &= ~( 1 << BIT_POS )

    // In order to read from the button, we need to give it a ground
    // reference, via a pull-up resistor. If we don't, the button pin will have
    // a floating ground, and hence its value will be undefined. On the
    // ATmega4809, we enable pull-up by setting the "PORT_PULLUPEN" bit in
    // "PORTx.PINnCTRL" high. See datasheet section 15 (I/O-ports).

    // It's your time to do some stuff! Do the following:
    // 1 - Find which pin and port the SW0 button is on. Check the ATMega4809
    // Curiosity Hardware User Guide to find the correct port and pin. Then
    // define the pin for the button at the line "#define SW0".
    // 2 - Set LED0 as output
    // 3 - Set SW0 as input
    // 4 - Enable pull-up on button SW0

    while (1) {
        // Here, you want to check if a button is pressed, and if yes, turn on
        // LED0. If no, then do the opposite. Similar to setting pins with
        // PORTx.OUT, we can read pins with PORTx.IN In order to check a pin
        // value, mask out that particular bit (use bitwise AND). Bit masking is
        // done like this: (REGISTER & (1 << BIT_POS)), which selects bit
        // BIT_POS from register. If that bit is 0, the result will be 0. If it
        // is 1, the result will be greater than 0 (depending on bit position).

        // Do the following:
        // 1 - check if button SW0 is pressed
        // 2 - if so, turn LED0 on
        // 3 - if not, turn LED0 off
    }
}
