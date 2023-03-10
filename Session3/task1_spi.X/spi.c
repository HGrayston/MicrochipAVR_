#include <avr/io.h>

#include "spi.h"

void spi_init() {
    // First you will need to set MOSI, SCK, CS (slave select) as outputs
    // Look in the ATmega4809, Base4Click and in the OLED datasheet in order
    // to find where these pins are. It is easy to get this wrong, so double
    // check them

    // Set CS to high to disable the slave (the CS is active low) for now

    // Then you will have to enable SPI MASTER and enable SPI. Look in
    // section 24.5.1.

    // Make sure the CS does not disable master mode, look at the SSD bit in the
    // CTRLB register, section 24.5.2.
}

void spi_transmit(char cData) {
    // First select the correct slave by setting the slave select (SS) bit LOW.
    // This can be done with the CS

    // Then start the transmission by assigning the data to the SPI data
    // register

    // Now wait for the data transmission to complete by periodically checking
    // the SPI INTFLAGS register.
    // The IF bit is the one we're interested in.

    // Make a dummy read to clear the interrupt flags

    // Finally set the slave select bit HIGH before leaving the function
}
