#ifndef ANSISTUFF_H
#define ANSISTUFF_H

#include <stdint.h>
#include <stdio.h>

typedef enum {
    acBlack = 0,
    acRed = 1,
    acGreen = 2,
    acYellow = 3,
    acBlue = 4,
    acMagenta = 5,
    acCyan = 6,
    acWhite = 7,
} tAnsiColor;

void ansiGotoXY(uint32_t x, uint32_t y);
void ansiClearScreen(void);
void ansiClearLine(void);
void ansiReset(void);
void ansiSetForeground(tAnsiColor col, uint8_t intensity);
void ansiSetBackground(tAnsiColor col, uint8_t intensity);

#endif