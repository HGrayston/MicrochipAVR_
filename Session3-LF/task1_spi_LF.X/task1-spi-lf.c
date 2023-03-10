#define F_CPU 3333333UL

#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <util/delay.h>

#include "graphics.h"
#include "oled.h"
#include "spi.h"

#define FONTSIZE 5

int main(void) {
    spi_init();
    oled_init();

    graphics_printf(FONTSIZE, "Hello Screen\n");
    _delay_ms(2000);

    graphics_clear_screen();
    graphics_print_bitmap(OV);

    while (1) {}
}
