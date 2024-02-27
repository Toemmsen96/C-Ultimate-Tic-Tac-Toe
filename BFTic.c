

#include <stdint.h>
#include <stdio.h>
#include <Windows.h>
#include "ansiStuff.h"
#include <stdbool.h>

#define VLINE 186
#define HLINE 205

//own code:
//Brainfck TicTacToe aka ultimate TicTacToe
char bigField[9][9] = { 0 };
char big = 0;
char smoll = 0;
char CurrentPlayer = 'X';
char bigFieldWon[9] = { 0 };


void switchPlayer(void) {
	if (CurrentPlayer == 'X') {
		CurrentPlayer = 'O';
	}
	else {
		CurrentPlayer = 'X';
	}
}
void drawthickLine(void) {
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 17; i++) {
			printf("%c", HLINE);
		}
		if (j < 2) {
			printf("%c", 206);
		}
	}
}

void drawthinLine(void) {
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 17; i++) {
			if (i == 5 || i == 11) {
				printf("%c", 197);
			}
			else {
				printf("%c", 196);

			}
		}
		if (j < 2) {
			printf("%c", 206);
		}

	}
}
void colorField(char x, char y) {
	if (bigField[x][y] == 'X') {
		ansiSetForeground(acRed, 1);

	}
	else if (bigField[x][y] == 'O') {
		ansiSetForeground(acGreen, 1);
	}
	else {
		ansiReset();
	}
}

void drawField(void) {
	//noch viel zu lang -> kürzen / vereinfachen


	printf("\n");
	for (char bigf = 0; bigf < 9; bigf += 3) {
		printf("Field: %d\t %cField: %d\t   %cField: %d\n", bigf, VLINE, bigf + 1, VLINE, bigf + 2);
		for (char norf = 0; norf < 9; norf += 3) {
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					colorField(bigf + k, norf + l);
					printf("  %c  ", (bigField[bigf + k][norf + l] == 0 ? norf + l + 48 : bigField[bigf + k][norf + l]));
					ansiReset();
					if (l < 2) {
						printf("%c", 179);
					}
				}
				if (k < 2) {
					ansiReset();
					printf("%c", VLINE);
				}
			}
			if (norf < 6) {
				printf("\n");
				drawthinLine();
				printf("\n");
			}
		}
		printf("\n");
		if (bigf < 6) {
			drawthickLine();
		}
		printf("\n");
	}
}

bool checkWinS(uint8_t big) {
	// Check rows
	for (int i = 0; i < 3; i++) {
		if (bigField[big][i] == bigField[big][i + 3] && bigField[big][i + 3] == bigField[big][i + 6] && bigField[big][i] != 0) {
			return 1;
		}
	}

	// Check columns
	for (int i = 0; i < 3; i++) {
		if (bigField[big][i * 3] == bigField[big][i * 3 + 1] && bigField[big][i * 3 + 1] == bigField[big][i * 3 + 2] && bigField[big][i * 3] != 0) {
			return 1;
		}
	}

	// Check diagonals
	if ((bigField[big][0] == bigField[big][4] && bigField[big][4] == bigField[big][8]) && (bigField[big][0] != 0)) {
		return 1;
	}
	else if ((bigField[big][2] == bigField[big][4] && bigField[big][4] == bigField[big][6]) && (bigField[big][2] != 0)) {
		return 1;
	}

	return 0;
}


bool checkWinB(void) {
	// Array of winning combinations
	int winning_combinations[8][3] = {
		{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // rows
		{0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // columns
		{0, 4, 8}, {2, 4, 6} // diagonals
	};

	for (int i = 0; i < 8; i++) {
		if (bigFieldWon[winning_combinations[i][0]] == bigFieldWon[winning_combinations[i][1]] &&
			bigFieldWon[winning_combinations[i][1]] == bigFieldWon[winning_combinations[i][2]] &&
			(bigFieldWon[winning_combinations[i][0]] == 'X' || bigFieldWon[winning_combinations[i][0]] == 'O'))
		{
			return true;
		}
	}
	return false;
}


bool checkFieldB(uint8_t big) {
	return (bigFieldWon[big] != 0);
}

bool checkTieB(void) {
	int check = 0;
	for (int i = 0; i < 9; i++) {
		if (bigFieldWon[i] != 0) {
			check++;
		}
	}
	//if ((bigFieldWon[0] == 'X' || bigFieldWon[0] == 'O') && (bigFieldWon[1] == 'X' || bigFieldWon[1] == 'O') && (bigFieldWon[2] == 'X' || bigFieldWon[2] == 'O') && (bigFieldWon[3] == 'X' || bigFieldWon[3] == 'O') && (bigFieldWon[4] == 'X' || bigFieldWon[4] == 'O') && (bigFieldWon[5] == 'X' || bigFieldWon[5] == 'O') && (bigFieldWon[6] == 'X' || bigFieldWon[6] == 'O')&&(bigFieldWon[7] == 'X' || bigFieldWon[7] == 'O')&& (bigFieldWon[8] == 'X' || bigFieldWon[8] == 'O')) {
	return (check == 9);
}
void checkTieS(uint8_t big) {
	int check = 0;
	for (int i = 0; i < 9; i++) {
		if (bigField[big][i] == 'X' || bigField[big][i] == 'O') {
			check++;
		}
	}
	if (check == 9) {
		bigFieldWon[big] = 'N';
		return;
	}
	else {
		return;
	}
}