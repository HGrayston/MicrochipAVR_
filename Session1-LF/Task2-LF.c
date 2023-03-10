#define F_CPU 3333333UL

#include <avr/io.h>
#include <util/delay.h>

// In the ATmega4809 Curiosity Nano Hardware User Guide (page 27), we see
// that LED is on PF5 and button is on PF6
// We only define the pins here, not the port

#define LED0 5
#define SW0  6

int main(void) {

    // We want to send signals to the LEDs, in order to turn it off and on.
    // We also want to be able to read the buttons.
    // This is done by setting bits in the PORTx.DIR register (in this case
    // PORTF.DIR)
    // PORTx.DIR: 1 is output, 0 is input
    //
    // LED: 1 LED is off, 0 LED is on
    // Button: 1 Button is open, 0 button is pressed
    //
    // Bit set logic:
    // Set to 1: REG |= ( 1 << BIT_POS )
    // Set to 0: REG &= ~( 1 << BIT_POS )

    // In order to read from the buttons, we need to give it a ground
    // reference, via a pull-up resistor. If we don't, the button pin will have
    // a floating ground, and hence its value will be undefined. On the
    // ATmega4809, we enable pull-up by setting the "PORT_PULLUPEN" bit in
    // "PORTx.PINnCTRL" high. See datasheet section 15 (I/O-ports).

    // Set the LED pins as output
    PORTF.DIR |= (1 << LED0);

    // Set the button as input
    PORTF.DIR &= ~(1 << SW0);

    // Set the pin as pull up
    PORTF.PIN6CTRL |= PORT_PULLUPEN_bm;

    while (1) {

        // If button is pressed (0 - LOW)
        if (!(PORTF.IN & (1 << SW0))) {
            // Sets output to 0, turns LED0 on (LED is active low)
            PORTF.OUT &= ~(1 << LED0);
        } else {
            // Sets output to 1, turns LED off (LED is active low)
            PORTF.OUT |= (1 << LED0);
        }
    }
}
