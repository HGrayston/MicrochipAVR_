#ifndef DRIV_OLED_H_
#define DRIV_OLED_H_

#include <avr/io.h>
#include <stdio.h>

/* Initiate and configure OLED */
void oled_init();

/* Hardware reset the screen */
void oled_reset();

/* Set data/command mode */

void oled_set_mode(uint8_t mode);

/* Write command */
void oled_write_c(uint8_t command);

/* Write data*/
void oled_write_d(uint8_t data);


/* Clear the screen */
void oled_clear_screen();

/* Clear one line */
void oled_clear_line(uint8_t line);

/* Go to given row*/
void oled_goto_line(uint8_t line);

/* Go to given row and column*/
void oled_pos(uint8_t row, uint8_t col);

/* Return current row*/
uint8_t oled_get_current_line();

/* Set brightness, 0-255 */
void oled_set_brightness(uint8_t lvl);




/************************************
  Writing text to OLED
  Use ASCII code, Font types: FONT8 (8x8), FONT5 (5x7), FONT4 (4x6)
  Each font has an individual file stream for convenience use with "fprintf()"
  e.g. fprintf(FONT5,"Hello world \n")
 *************************************/

/* Write a character to the screen with font 4 to current position*/
int oled_putchar4(char character, FILE * stream);

/* Write a character to the screen with font 5 to current position*/
int oled_putchar5(char character, FILE* stream);

/* Write a character to the screen with font 8 to current position*/
int oled_putchar8(char character, FILE* stream);

static FILE oled_stream_font4 = FDEV_SETUP_STREAM(oled_putchar4, NULL, _FDEV_SETUP_WRITE);
static FILE oled_stream_font5 = FDEV_SETUP_STREAM(oled_putchar5, NULL, _FDEV_SETUP_WRITE);
static FILE oled_stream_font8 = FDEV_SETUP_STREAM(oled_putchar8, NULL, _FDEV_SETUP_WRITE);

#define FONT4 (&oled_stream_font4)
#define FONT5 (&oled_stream_font5)
#define FONT8 (&oled_stream_font8)


#endif /* DRIV_OLED_H_ */
