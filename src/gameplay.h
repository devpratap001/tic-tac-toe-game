#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#define BOARD_SIZE 3
#define PLAYER 'X'
#define COMPUTER 'O'

extern char board[BOARD_SIZE][BOARD_SIZE];

typedef struct
{
    int win, lost, draw;
}score;

void play_game(int);

#endif