#define F_CPU 3333333UL

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

// NB: These LEDs are on the OLED1 Xplained board!
#define LED1 4 // Port D
#define LED2 5 // Port D

int main(void) {
    // In this exercise we will get LEDs to blink at even intervals using
    // interrupts. First set up the LEDs like in the previous exercise. You can
    // either copy paste from the previous exercise or start fresh.
    // These LEDs are on the OLED1 Xplained board (the blue board), not the
    // previous LED you have used

    // We will be using timer A (TCA0) that will trigger an overflow interrupt.
    // This is a 16 bit timer that can run in 2 modes
    // - single mode as one 16-bit timer
    // - dual/split mode as two 8-bit timers
    //
    // We will be using single mode in this exercise.
    // Hint: because the register names can be hard to understand:
    // TCA0.SINGLE.CTRLA addresses the control A register for timer A

    // We have to set the top value the timer will count to. This defines the
    // period of the interrupt (which hints at the register's name)
    //
    // Find the register to set and set the value to a value here:

    // Next we have to enable timer interrupt for overflow on TCA0. This
    // triggers an interrupt when the timer reaches the top value.
    //
    // Enable timer overflow interrupt here:

    // Then we set the prescaler to clk=clk/256 and enable the timer. This makes
    // the timer count at frequency which is the CPU frequncy divded by 256.
    // This is done by setting the correct bits in the control A register.
    //
    // Set prescaler and enable timer here:

    // To be able to react to the interrupts from the module we have to
    // enable interrupts globally. This is done in the function sei(), which
    // is located in the already included header file <avr/interrupt.h>
    sei();

    while (1) {
        // Do other things?

        // Remember to fill in the ISR at the bottom of the file, else nothing
        // will happen!
    }
}

ISR(TCA0_OVF_vect) {

    // Do something with the led(s), like toggle.

    // Clear the interrupt flag.
    // If we do not clear the flag, we will instantly jump back into the ISR
    // again. Be careful and read the datasheet properly when clearing the flag.
    // Clearing the flag is done by setting a value in the INTFLAGS register for
    // the timer.
}
