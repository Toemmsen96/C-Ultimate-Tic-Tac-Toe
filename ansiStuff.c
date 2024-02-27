#include <stdint.h>
#include <stdio.h>
#include "ansiStuff.h"




void ansiGotoXY(uint32_t x, uint32_t y) {
	printf("\033[%d;%dH", y, x);
}

void ansiClearScreen(void) {
	printf("\033[2J");
}

void ansiClearLine(void) {
	printf("\033[2K");
}

void ansiReset(void) {
	printf("\033[0m");
}

void ansiSetForeground(tAnsiColor col, uint8_t intensity) {
	if (intensity)
	{
		printf("\033[%dm", col + 90);
	}
	else
	{
		printf("\033[%dm", col + 30);
	}
}

void ansiSetBackground(tAnsiColor col, uint8_t intensity) {
	if (intensity)
	{
		printf("\033[%dm", col + 100);
	}
	else
	{
		printf("\033[%dm", col + 40);
	}
}
