/* Author: Tom Hotz
* Program Name: Brainfck TicTacToe
* Start: 04.11.2022
* 
* Target: Playable 2 player game with a tictactoe field in each tic tac toe field
* placed field defines where next player has to place his char.
*/

#include <stdint.h>
#include <stdio.h>
#include <Windows.h>
#include "ansiStuff.h"
#include "BFTic.h"
#pragma warning(disable:4996)

void setSmall(void) {
	/*if (CurrentPlayer == 'X') {
		ansiSetForeground(acRed, 1); 
	}
	else if (CurrentPlayer == 'O') {
		ansiSetForeground(acGreen, 1);
	}
	printf("Player %c enter Field Number in Field %d to set your Symbol:\n ", CurrentPlayer, big);
	ansiReset();
	(void)scanf("%c", &smoll);*/
	do {
		if (CurrentPlayer == 'X') {
			ansiSetForeground(acRed, 1);

		}
		else if (CurrentPlayer == 'O') {
			ansiSetForeground(acGreen, 1);
		}
		printf("Player %c enter smoll Field in Field %d to set your Symbol:\n ", CurrentPlayer, big);
		ansiReset();
		(void)scanf(" %c", &smoll);
		smoll = smoll - '0';
		printf("%d\n", smoll);
	} while (smoll > 8 || smoll < 0 || bigField[big][smoll] != 0 );
	return;
	//smoll = smoll - '0';
}

void setBig(void) {
	/*if (CurrentPlayer == 'X') {
		ansiSetForeground(acRed, 1);
	}
	else if (CurrentPlayer == 'O') {
		ansiSetForeground(acGreen, 1);
	}
	printf("Player %c enter Field Number for a Big Field to set your Symbol:\n ", CurrentPlayer);
	ansiReset();
	(void)scanf("%c", &big);*/
	do  {
		if (CurrentPlayer == 'X') {
			ansiSetForeground(acRed, 1);

		}
		else if (CurrentPlayer == 'O') {
			ansiSetForeground(acGreen, 1);
		}
		printf("Player %c enter Field Number for a Big Field to set your Symbol:\n ", CurrentPlayer);
		ansiReset();
		(void)scanf(" %c", &big);
	} while (big > '8' || big < '0' || bigFieldWon[big - '0'] != 0);
	big = big - '0';
	return;
}



void main(void) {
	_Bool gameOver = 0;
	system("cls");
	system("pause");
	drawField();
	do {
		printf("Player %c enter Starting Field (between 0 and 8) to set your Symbol:\n ", CurrentPlayer);
		(void)scanf(" %c", &smoll);
	} while ((smoll > '8') || smoll < '0');
	//handle invalid numbers
	smoll = smoll - '0';
	while (!gameOver) {
		// If the forwarded field is already occupied, ask the player to choose a new big field
		if (checkFieldB(smoll)) {
			setBig();
		}
		// If the forwarded field is not occupied, use it as the big field
		else {
			big = smoll;
		}
		setSmall();
		bigField[big][smoll] = CurrentPlayer;
		checkTieS(big);
		if (checkWinS(big)) {
			printf("Player %c Won Field %d\n", CurrentPlayer, big);
			for (int i = 0; i < 9; i++) {
				bigField[big][i] = CurrentPlayer;
			}
			bigFieldWon[big] = CurrentPlayer;
			system("pause");
		}
		if (checkWinB()) {
			gameOver = 1;
			printf("Player %c Won!!", CurrentPlayer);
		}
		else if (checkTieB()) {
			gameOver = 1;
		}

		switchPlayer();
		system("cls");
		drawField();

	}
	
	if (checkWinB()) {
		switchPlayer();
		printf("\nPlayer %c WON!!!!\n", CurrentPlayer);
	}
	else if (checkTieB) {
		printf("its a tie!!!");
	}
	return;
}