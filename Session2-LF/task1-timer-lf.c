#define F_CPU 3333333UL

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

#define LED1 4 // port D
#define LED2 5 // port D

int main(void) {
    // Set both LEDs as output
    PORTD.DIRSET = (1 << LED1) | (1 << LED2);

    // Toggle the first LED. Just so that we get that the first LED will be off
    // when the second is on and vice versa
    PORTD.OUTTGL = (1 << LED1);

    // The period of the timer, the value the timer will count up to
    TCA0.SINGLE.PER = 0x4000;

    // We enable interrupt on overflow, that is when the timer counts up to the
    // TCA0.SINGLE.PER defined above (reaches the TOP value)
    TCA0.SINGLE.INTCTRL |= TCA_SINGLE_OVF_bm;

    // We set the timer frequency to main clock / 256 and enable it
    TCA0.SINGLE.CTRLA |= (TCA_SINGLE_CLKSEL_DIV256_gc) | (TCA_SINGLE_ENABLE_bm);

    // Enables interrupt. Without this, the ISR will not be called
    sei();

    while (1) {}
}

// Timer overflow interrupt
ISR(TCA0_OVF_vect) {
    // Toggle both LEDs when the timer has overflowed (reached the TOP value)
    PORTD.OUTTGL = (1 << LED1) | (1 << LED2);

    // We clear the interrupt overflow flag. We need to do this in order to
    // 'tell' the CPU that we have 'acknowledged' the interrupt and can move on
    TCA0.SINGLE.INTFLAGS = TCA_SINGLE_OVF_bm;
}
