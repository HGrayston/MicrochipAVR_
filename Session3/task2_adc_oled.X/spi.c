#include <avr/io.h>

#include "spi.h"

#define MOSI_bm  (1 << 4)
#define SCK_bm   (1 << 6)
#define SPI_PORT PORTA
#define CS_bm    (1 << 6)
#define CS_PORT  PORTC

#define SPI_IF_ENABLE_bp 0

void spi_init() {
    // Set MOSI and SCK as outputs
    SPI_PORT.DIRSET = (MOSI_bm) | (SCK_bm);

    // Set CS as output
    CS_PORT.DIRSET = (CS_bm);

    // Set CS high to deselect (CS is active low)
    CS_PORT.OUTSET = (CS_bm);

    // Enable SPI and set master mode
    SPI0.CTRLA |= (SPI_ENABLE_bm) | (SPI_MASTER_bm);

    // Make sure CS does not disable master mode
    SPI0.CTRLB |= (SPI_SSD_bm);
}

void spi_transmit(char cData) {
    // Set CS low to select (active low)
    CS_PORT.OUTCLR = (CS_bm);

    // Fill the data
    SPI0.DATA = cData;

    // Wait until the the data is sent
    while (!(SPI0.INTFLAGS & (SPI_IF_bm))) {}

    // Dummy read to clear the flag
    SPI0.DATA;

    // Deselect the CS
    CS_PORT.OUTSET = (CS_bm);
}
