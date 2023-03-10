#define F_CPU 3333333UL

#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <util/delay.h>

#include "adc.h"
#include "graphics.h"
#include "oled.h"
#include "spi.h"

#define KLAKK_CHANNEL 0x00
#define SW0_bm        0x40
#define SW0_PORT      PORTF

int main(void) {
    // Set button as input
    SW0_PORT.DIRCLR = SW0_bm;

    // Turn on interrupts
    sei();

    // Initialize SPI and wait a bit
    spi_init();
    _delay_ms(2000);

    // Initialize the OLED
    oled_init();

    // Initialize the ADC
    adc_init();

    // Printing startup bitmap, just the OV logo appearing on the OLED screen
    graphics_print_bitmap(OV);
    _delay_ms(2000);

    oled_clear_screen();
    graphics_loading_bar_init();

    while (1) {
        // We divide by 4 (which is the same as bit shifting two places to the
        // right) since we use 4 samples
        const uint16_t data = adc_read(KLAKK_CHANNEL) >> 2;

        oled_pos(0, 12);
        graphics_printf(5, "OV-POT read: ");
        graphics_printf(8, "%4u", data);

        // Update loading bar
        graphics_loading_bar_set(data);

        // Set position for voltage printout
        oled_pos(3, 12);

        // We have a 10-bit ADC measurement, so we have a value between 0 and
        // 1023. In order to go from the ADC value to voltage one thus has to do
        // (data / 1023) * 3.3V.
        //
        // But, as doing arithmetic with floats take a lot more space and time,
        // we do a trick in order to use integers.
        //    ((data * 1000) * (3.3 * 100) / 1023) = voltage * 1000 * 100
        // => (data * 330) / (1023 * 100) = voltage
        //
        // This is approximately:
        // (data * 323) / 100000 for the integer part (323 comes from
        // 330*1000/1023)
        const uint8_t voltage_integer = data * 323ul / 100000ul;
        const uint8_t voltage_fraction = (data * 323ul % 100000ul) / 1000;

        graphics_printf(5, "Voltage: ");
        graphics_printf(8, "%u.%02u V", voltage_integer, voltage_fraction);

        // Display OV logo when button is pressed
        if (!(SW0_PORT.IN & SW0_bm)) {
            oled_pos(0, 0);
            graphics_print_bitmap(OV);

            // Wait until button is released
            while (!(SW0_PORT.IN & (SW0_bm))) {}

            oled_clear_screen();
            graphics_loading_bar_init();
        }
    }
}
