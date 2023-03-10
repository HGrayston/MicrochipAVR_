#define F_CPU 3333333UL

#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>

#define LED1 4 // PWM2/PD4
#define LED2 5 // PWM3/PD5
#define LED3 5 // RST3/PC5

#define BTN1 2 // INT2/PC2
#define BTN2 1 // AN2/PD1
#define BTN3 2 // AN3/PD2

int main(void) {
    // Set the LED pins as output
    PORTD.DIR |= (1 << LED1) | (1 << LED2);
    PORTC.DIR |= (1 << LED3);

    // Set the button pins as input
    PORTD.DIR &= ~(1 << BTN2);
    PORTD.DIR &= ~(1 << BTN3);
    PORTC.DIR &= ~(1 << BTN1);

    // Enable pull-ups on the buttons
    PORTC.PIN2CTRL |= PORT_PULLUPEN_bm;
    PORTD.PIN1CTRL |= PORT_PULLUPEN_bm;
    PORTD.PIN2CTRL |= PORT_PULLUPEN_bm;

    bool button_state_1 = false;
    bool button_state_2 = false;
    bool button_state_3 = false;

    // Turn LEDs off (remember, active-low)
    PORTD.OUT |= (1 << LED1);
    PORTD.OUT |= (1 << LED2);
    PORTC.OUT |= (1 << LED3);

    while (1) {

        // This logic for every button is equal to task 3. We simply check if
        // the button is pressed (active-low), and if it wasn't previously
        // pressed (button_state_x is not true), then we toggle the LED

        if (!(PORTC.IN & (1 << BTN1))) {
            if (!button_state_1) {

                PORTD.OUT ^= (1 << LED1);
                button_state_1 = true;
            }
        } else {
            button_state_1 = false;
        }

        if (!(PORTD.IN & (1 << BTN2))) {
            if (!button_state_2) {

                PORTD.OUT ^= (1 << LED2);
                button_state_2 = true;
            }
        } else {
            button_state_2 = false;
        }

        if (!(PORTD.IN & (1 << BTN3))) {
            if (!button_state_3) {

                PORTC.OUT ^= (1 << LED3);
                button_state_3 = true;
            }
        } else {
            button_state_3 = false;
        }

        _delay_ms(1);
    }
}
