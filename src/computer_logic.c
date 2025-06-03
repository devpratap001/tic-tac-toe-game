#include <stdio.h>
#include "gameplay.h"
#include "game_logic.h"
#include "computer_logic.h"

void computer_normal(int choice, char board[BOARD_SIZE][BOARD_SIZE])
{
    //check win
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] != ' ')
                continue;
            board[i][j] = COMPUTER;
            if (check_win(COMPUTER))
                return;
            board[i][j] = ' ';
        }
    }
    // check block
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] != ' ')
                continue;
            board[i][j] = PLAYER;
            if (check_win(PLAYER))
            {
                board[i][j] = COMPUTER;
                return;
            }
            board[i][j] = ' ';
        }
    }
    if (choice == 2)
    {
        //center square
        const int c_row = BOARD_SIZE/2, c_col = BOARD_SIZE/2;
        if (board[c_row][c_col] == ' ')
        {
            board[c_row][c_col] = COMPUTER;
            return;
        }
        //edge square
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            if (board[i][i] != ' ')
                continue;
            board[i][i] = COMPUTER;
            return;
        }
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            if (board[i][BOARD_SIZE - i - 1] != ' ')
                continue;
            board[i][BOARD_SIZE- i - 1] = COMPUTER;
            return;
        }
    }
    // random square
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] != ' ')
                continue;
            board[i][j] = COMPUTER;
            return;
        }
    }
};