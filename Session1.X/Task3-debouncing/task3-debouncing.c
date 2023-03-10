// F_CPU

// Define F_CPU here

#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>

// LED
// Define the pin for the LED here

// Button
// Define the pin for the button here

int main(void) {
    // PORTx.DIR: set direction - 1 is output, 0 is input
    // PORTx.OUT: set value of pins
    // PORTx.IN: read value of pins
    // LED: 1 LED is off, 0 LED is on
    // SW: 1 Button is open, 0 button is pressed
    // Set to 1: REG |= ( 1 << BIT_POS )
    // Set to 0: REG &= ~( 1 << BIT_POS )
    // This is called "read-modify-write".

    // Do the following:
    // Set up the LED and button correctly, and add a pull-up to the button,
    // exactly the same as done in task 2

    while (1) {
        // Do the following:
        // Check if button is pressed, but this time you want to toggle the
        // light instead of turning it on/off (hint: OUTTGL or XOR) Add a
        // button-pressed-state so that you don't have to hold the button to
        // turn on the light, but so that you instead toggle between light
        // on/off when the button is pressed (like a light switch): When the
        // button is not pressed the light should hold its current state.
    }
}
