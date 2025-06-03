#include <stdio.h>
#include "utils.h"
#include "game_logic.h"
#include "gameplay.h"


int analyse_board(void)
{
    // win : 2; lose: 1; draw: 0; default: -1;
    if (check_win(PLAYER))
        return 2;
    if (check_win(COMPUTER))
        return 1;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == ' ')
                return -1;
        }
    }
    return 0;
};

int check_win(char player)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        int status = 1;
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] != player)
                status = 0;
        }
        if (status)
            return status;
    }

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        int status = 1;
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[j][i] != player)
                status = 0;
        }
        if (status)
            return status;
    }
    
    int status = 1;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i][i] != player)
            status = 0;
    }
    if (status)
        return status;
    
    status = 1;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i][BOARD_SIZE - i -1] != player)
            status = 0;
    }
    return status;
};

int set_value(int row, int col, char value)
{
    if (board[row][col] != ' ')
        return 0;
    board[row][col] = value;
    return 1;
};

void print_board()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf(" %c", board[i][j]);
            if (j != BOARD_SIZE -1)
                printf(" |");
        }
        printf("\n");
        if (i != BOARD_SIZE -1)
            printf("---+---+---\n");
    }
};

void reset_board(void)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
            board[i][j] = ' ';
    }
}