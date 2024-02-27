#ifndef BFTIC_H
#define BFTIC_H

#include <stdint.h>
#include <stdio.h>
#include <Windows.h>
#include "ansiStuff.h"
#include <stdbool.h>

#define VLINE 186
#define HLINE 205

extern char bigField[9][9];
extern char big;
extern char smoll;
extern char CurrentPlayer;
extern char bigFieldWon[9];

void switchPlayer(void);
void drawthickLine(void);
void drawthinLine(void);
void colorField(char x, char y);
void drawField(void);
bool checkFieldB(uint8_t big);
bool checkWinS(uint8_t big);
bool checkWinB(void);
bool checkTieB(void);
void checkTieS(uint8_t big);

#endif