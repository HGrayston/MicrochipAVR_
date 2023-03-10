#define F_CPU 3333333

#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>
#include <string.h>
#include <util/delay.h>

#define BAUD_9600         4 * F_CPU / 9600
#define TX_PORT           PORTB
#define TX_PIN            0
#define KLAKK_ADC_CHANNEL 0x0

char uart_str[64];

void usart_init(unsigned long baud) {
    TX_PORT.DIRSET = (1 << TX_PIN);

    // Set baud rate we've specified. Note that since the baud rate is usually
    // greater than a value fitting in a 8-bit number, we need to use two
    // registers here
    USART3.BAUDL = (uint8_t)baud;
    USART3.BAUDH = (uint8_t)(baud >> 8);

    // Enable RX and TX
    USART3.CTRLB = (1 << USART_RXEN_bp) | (1 << USART_TXEN_bp);
}

void usart_transmit(char data) {
    // Sends a character over UART

    // First we should check that there isn't already data being sent.
    // If there is, we should wait for it to finish first
    while (!(USART3.STATUS & (1 << USART_DREIF_bp))) {}

    // Put our new data into TX data register
    USART3.TXDATAL = data;
}

void usart_transmit_string(char *data) {
    // Loop until the end of the string
    while (*data != '\0') {
        usart_transmit(*data);
        data++;
    }
}

void usart_print_voltage(uint16_t data) {
    // We have 4 samples, so we want to divide by 4
    // Right shifting by 2 is equivalent to dividing an integer by 4
    data = data >> 2;

    // We have a 10-bit ADC measurement, so we have a value between 0 and 1023.
    // In order to go from the ADC value to voltage one thus has to do
    // (data / 1023) * 3.3V.
    //
    // But, as doing arithmetic with floats take a lot more space and time, we
    // do a trick in order to use integers.
    //    ((data * 1000) * (3.3 * 100) / 1023) = voltage * 1000 * 100
    // => (data * 330) / (1023 * 100) = voltage
    //
    // This is approximately:
    // (data * 323) / 100000 for the integer part (323 comes from 330*1000/1023)

    uint8_t voltage_integer = data * 323ul / 100000ul;
    uint8_t voltage_fraction = (data * 323ul % 100000ul) / 1000;

    // Format string and put voltage
    sprintf(
        uart_str, "Voltage: %u.%02u V\r\n", voltage_integer, voltage_fraction);

    usart_transmit_string(uart_str);
}

void adc_init() {
    // Set resolution, we choose 10 bits
    ADC0.CTRLA |= (ADC_RESSEL_10BIT_gc);

    // 4 samples
    ADC0.CTRLB |= (ADC_SAMPNUM_ACC4_gc);

    // Select to use the supply voltage (VDD) as voltage reference
    ADC0.CTRLC |= (ADC_REFSEL_VDDREF_gc);

    // ADC clock prescaler, best accuracy when run below 2MHz. (Here div2 ~1.46
    // MHz)
    ADC0.CTRLC |= (ADC_PRESC_DIV2_gc);

    // Enable the ADC
    ADC0.CTRLA |= (ADC_ENABLE_bm);
}

uint16_t adc_read(uint8_t channel) {
    // Select the channel to read from
    ADC0.MUXPOS = channel;

    // Clear the results ready flag
    ADC0.INTFLAGS = ADC_RESRDY_bm;

    // Start a conversion
    ADC0.COMMAND |= (ADC_STCONV_bm);

    // Wait for the results ready flag to be set
    while (!(ADC0.INTFLAGS & ADC_RESRDY_bm)) {}

    return ADC0.RES;
}

int main(void) {
    usart_init(BAUD_9600);
    adc_init();

    while (1) {
        uint16_t data = adc_read(KLAKK_ADC_CHANNEL);

        usart_print_voltage(data);

        _delay_ms(1000);
    }
}
