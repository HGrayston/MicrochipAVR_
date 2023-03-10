#define F_CPU     3333333UL
#define BAUD_9600 ((4UL * F_CPU) / 9600)

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

#include "adc.h"
#include "graphics.h"
#include "spi.h"

// In this exercise you will use this to read the OV-POT KLAKK connected to the
// MicroBUS slot 1 on the Curiosity Nano Adapter board. We will display the
// results on the OLED screen from them previous task.
//
// In this task you don't need to do anything in the other files

int main(void) {

    // Initialize everything we need here

    // Turn on interrupt

    // Initialize SPI

    // Initialize OLED

    // Initialize ADC

    while (1) {
        // Continuously read the ADC each loop and output it to the screen

        // There is a loading bar in graphics.h. You can use that for extra
        // stylistic points. There are some other things in graphis.h you can
        // use as well.
    }
}
