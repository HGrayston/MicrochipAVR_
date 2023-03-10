#define F_CPU 3333333UL

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

#define LED1 4 // Port D
#define LED2 5 // Port D

// In this exercise, you will use PWM to control the brightness of LEDs.
// Once we have PWM set up, controling the brightness is super easy!
//
// NB: These LEDs are on the OLED1 Xplained board!

int main(void) {
    // Set up the LEDs. You might want to copy this from previous
    // exercises.

    // In dataheet:
    // Section 4.1, Multiplexed signals, we see that if we want to use TCA0 with
    // PD4 and PD5, we need to use portmux to change TCA to Port D. Look at the
    // PORTMUX.TCAROUTEA register for this and set it to the appropriate value.

    // We will be using timer TCA0 in Split (not Single) mode. We use Split mode
    // to output waveforms on WO4 and WO5, see Figure 4-1 in the Curiosity Nano
    // Hardware User Guide. It is highly recommended that you read
    // chapter 20.3.3.4 and 20.3.3.6 in the megaAVR® 0-series. There you will
    // find a sub-chapter on the single-slope PWM we will be using.
    //
    // First, set the split mode. Look in section 20.7.4 in the data sheet.

    // Then, enable the TCA and set the prescaler. See section 20.7.1. Set the
    // prescaler to for example 1.

    // Enable high compare 1 and 2 to get output on WO4 and WO5. See
    // section 20.7.2.

    // Set period for high compare. See section 20.7.13. Set it to for example
    // 0xFF

    // See figure 20-13, page 194 in the datasheet. This is the PWM duty cycle.
    TCA0.SPLIT.HCMP1 = 0x00; // Max brightness (Leds are inverted)
    TCA0.SPLIT.HCMP2 = 0xFF; // Min brightness (Leds are inverted)

    while (1) {
        // To now adjust the brightness of the LEDs, we can modify
        // TCA.SPLIT.HCMPx. Try for example incrementing the HCMPx values in a
        // loop with a delay
    }
}
