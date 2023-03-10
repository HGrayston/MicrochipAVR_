#define F_CPU 3333333UL

#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>

#define LED0 5
#define SW0  6

int main(void) {
    // Set LED0 as output
    PORTF.DIR |= (1 << LED0);

    // Set LED0 off (remember, active-low)
    PORTF.OUT |= (1 << LED0);

    // Set button as input
    PORTF.DIR &= ~(1 << SW0);

    // Enable pull up on the button pin
    PORTF.PIN6CTRL |= PORT_PULLUPEN_bm;

    int button_state = 0;

    while (1) {
        // Check if the button is pressed
        if (!(PORTF.IN & (1 << SW0))) {

            // If the previous button state was 0 (it was not pressed in), then
            // toggle the LED
            if (button_state == 0) {
                PORTF.OUT ^= (1 << LED0);
                button_state = 1;
            }
        } else {
            button_state = 0;
        }

        _delay_ms(1);
    }
}
