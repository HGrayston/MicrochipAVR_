#ifndef OLED_GRAPHIC_H_
#define OLED_GRAPHIC_H_

#include <avr/io.h>
#include <avr/pgmspace.h>

/* Custom printf function. Text 4, 5 or 8*/
void graphics_printf(uint8_t size, const char *__fmt, ...);

/* Clear the screen */
void graphics_clear_screen();

/* Draw the outline of the loading bar */
void graphics_loading_bar_init();

/* Set length of loading bar. Between 0 and 1023 */
void graphics_loading_bar_set(uint16_t data);

/* Print a bitmap to the screen. See Graphics section under to find example
 * bitmap. */
void graphics_print_bitmap(const uint8_t *bm);

// Graphics. Probably generated on the Internet.
static const uint8_t PROGMEM OV[512] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xFF, 0x0F,
    0x00, 0x00, 0x00, 0x00, 0x70, 0x38, 0xDE, 0x3F, 0x3E, 0x18, 0x00, 0x00,
    0x00, 0xF0, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x00, 0xD8, 0x78, 0xDE, 0x3B,
    0x33, 0x1C, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x00,
    0x8C, 0x79, 0x8E, 0x21, 0x23, 0x1C, 0x00, 0x00, 0x00, 0xFE, 0x00, 0xFE,
    0x00, 0x00, 0x00, 0x00, 0x8C, 0x79, 0x8E, 0xA9, 0x23, 0x3C, 0x00, 0x00,
    0x00, 0x3F, 0x00, 0xF8, 0x01, 0x00, 0x00, 0x00, 0x8C, 0x79, 0x8F, 0x89,
    0x03, 0x3C, 0x00, 0x00, 0x00, 0x1F, 0x00, 0xF0, 0x01, 0x00, 0x00, 0x00,
    0x8C, 0x79, 0x8D, 0x8F, 0x03, 0x36, 0x00, 0x00, 0x80, 0x0F, 0x00, 0xE0,
    0x03, 0x00, 0x00, 0x00, 0x8C, 0xF9, 0x8D, 0x8B, 0x7B, 0x32, 0x00, 0x00,
    0xC0, 0x07, 0x00, 0xC0, 0x07, 0x00, 0x00, 0x00, 0x8C, 0xD9, 0x8D, 0x89,
    0x33, 0x3E, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00,
    0x8C, 0xD9, 0x8D, 0xA1, 0x33, 0x72, 0x00, 0x00, 0xE0, 0x03, 0x00, 0x80,
    0x0F, 0x00, 0x00, 0x00, 0x8C, 0xD9, 0x8D, 0xA1, 0x33, 0x72, 0x00, 0x00,
    0xE0, 0xFF, 0xC7, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0xD8, 0xD9, 0x8D, 0x31,
    0x33, 0x63, 0x00, 0x00, 0xE0, 0xFF, 0xC7, 0xFF, 0x0F, 0x00, 0x00, 0x00,
    0xF8, 0xFC, 0xDE, 0x3F, 0x3F, 0xF7, 0x00, 0x00, 0xE0, 0xFF, 0xC7, 0xFF,
    0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xE0, 0xFF, 0xC7, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xE0, 0xE1, 0x00, 0x0E, 0x0E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE1, 0x00, 0x0E,
    0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xE0, 0xC1, 0x01, 0x07, 0x0F, 0x00, 0xC0, 0xF3, 0x7F, 0x3F, 0xBC, 0xE3,
    0xFB, 0xF7, 0xEF, 0x07, 0xE0, 0xC1, 0x01, 0x07, 0x0F, 0x00, 0x80, 0x33,
    0x67, 0x6E, 0x38, 0x33, 0xDB, 0xE7, 0xEC, 0x0F, 0xE0, 0x81, 0x83, 0x03,
    0x0F, 0x00, 0x80, 0x33, 0x47, 0xC6, 0x18, 0x19, 0xCA, 0x64, 0xC8, 0x0C,
    0xE0, 0x83, 0x83, 0x83, 0x0F, 0x00, 0x80, 0x13, 0x57, 0xC6, 0x98, 0x38,
    0xCA, 0x64, 0xCA, 0x1C, 0xC0, 0x03, 0xC7, 0x81, 0x07, 0x00, 0x00, 0x13,
    0x17, 0xC6, 0xD8, 0x70, 0xC0, 0x60, 0xC2, 0x1C, 0xC0, 0x07, 0xC7, 0xC1,
    0x07, 0x00, 0x00, 0x13, 0x1F, 0x7E, 0xF8, 0xE0, 0xC1, 0xE0, 0xC3, 0x1C,
    0x80, 0x0F, 0xEE, 0xE0, 0x03, 0x00, 0x00, 0x13, 0x17, 0x7E, 0xF8, 0xC0,
    0xC3, 0xE0, 0xC2, 0x1C, 0x02, 0x1F, 0xFE, 0xF0, 0x83, 0x00, 0x00, 0x1F,
    0x17, 0x66, 0xD8, 0x81, 0xC3, 0x60, 0xC2, 0x1C, 0x1E, 0x3F, 0x7C, 0xF8,
    0xF1, 0x00, 0x00, 0x0F, 0x47, 0x66, 0x98, 0x19, 0xC3, 0x60, 0xC8, 0x1C,
    0xFE, 0x7F, 0xFE, 0xFD, 0xFF, 0x00, 0x00, 0x0E, 0x47, 0x66, 0x98, 0x1B,
    0xC2, 0x60, 0xC8, 0x0C, 0xFE, 0x7F, 0xFE, 0xFD, 0xFF, 0x00, 0x00, 0x0E,
    0x47, 0x6E, 0x99, 0x1B, 0xC3, 0x61, 0xCC, 0x0C, 0xFE, 0x7F, 0xFE, 0xFD,
    0xFF, 0x00, 0x00, 0x8E, 0x7F, 0xFF, 0xBD, 0xFF, 0xE3, 0xF3, 0xEF, 0x07,
    0xFE, 0x7F, 0xFE, 0xFD, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

#endif /* OLED_GRAPHIC_H_ */