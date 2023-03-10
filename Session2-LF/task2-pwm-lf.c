#define F_CPU 3333333UL

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

// In the pin definitions below, we have defined the PORT as well.
// Everything works the same way as before, except you have to change PORTx with
// the PORT definition. Example: LED1_PORT.OUTSET = (1 << LED1);

#define LED1 4
#define LED2 5
#define LED3 5

#define LED1_PORT PORTD
#define LED2_PORT PORTD
#define LED3_PORT PORTC

#define TOP_PERIOD 0xFF

int main(void) {
    sei();

    LED1_PORT.DIRSET = (1 << LED1);
    LED2_PORT.DIRSET = (1 << LED2);

    // In dataheet:
    // Section 4.1, Multiplexed signals, we see that if we want to use TCA0 with
    // PD4 and PD5, we need to use portmux to change TCA to Port D. We find that
    // the led is at port D, pin 4 and 5 by looking at datasheets and silk text
    // for PCBs.
    PORTMUX.TCAROUTEA = PORTMUX_TCA0_PORTD_gc;

    // Set splitmode to get access to WO4 and WO5
    TCA0.SPLIT.CTRLD |= (1 << TCA_SPLIT_SPLITM_bp);

    // Enable the TCA and set prescaler to 1
    TCA0.SPLIT.CTRLA |= (1 << TCA_SPLIT_ENABLE_bp) | (TCA_SPLIT_CLKSEL_DIV1_gc);

    // Enable High Compare 1 and 2 to get output on WO4 and WO5. See Figure
    // 19-13 in functional description datasheet.
    TCA0.SPLIT.CTRLB |=
        (1 << TCA_SPLIT_HCMP1EN_bp) | (1 << TCA_SPLIT_HCMP2EN_bp);

    // Set period for High compare. See figure 20-13, page 194 in the ATmega4809
    // datasheet. This effectively sets the PWM Period.
    TCA0.SPLIT.HPER = TOP_PERIOD;

    // See figure 20-13, page 194 in the datasheet. This is the PWM duty cycle.
    TCA0.SPLIT.HCMP1 = 0x00; // Max brightness (Leds are inverted)
    TCA0.SPLIT.HCMP2 = 0xFF; // Min brightness (Leds are inverted)

    while (1) {

        // The following will make the LEDs fade in and out by modifying the
        // duty cycle

        for (uint8_t i = 0; i < TOP_PERIOD; i++) {
            TCA0.SPLIT.HCMP1 = i;
            TCA0.SPLIT.HCMP2 = TOP_PERIOD - i;
            _delay_ms(5);
        }

        for (uint8_t i = TOP_PERIOD; i > 0; i--) {
            TCA0.SPLIT.HCMP1 = i;
            TCA0.SPLIT.HCMP2 = TOP_PERIOD - i;
            _delay_ms(5);
        }
    }
}
