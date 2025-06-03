#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"
#include "gameplay.h"
#include "game_logic.h"
#include "computer_logic.h"

char board[BOARD_SIZE][BOARD_SIZE] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

void play_game(int choice)
{
    srand(time(NULL));
    score game_score = {0,0,0};
    int row, col;
    int turn = rand()%2;
    while (1)
    {
        clear_screen();
        printf("Win: %d; Lost: %d; Draw: %d\n", game_score.win, game_score.lost, game_score.draw);
        print_board();
        int status = analyse_board();
        switch (status)
        {
        case 2:
            printf("Hurray!!, You won\n");
            game_score.win++;
            reset_board();
            break;
        case 1:
            printf("Oops!!, you lost\n");
            game_score.lost++;
            reset_board();
            break;
        case 0:
            printf("That's a tie!!\n");
            game_score.draw++;
            reset_board();
            break;
        case -1:
            break;
        }
        if (status == 2 || status == 1 || status == 0)
        {
            printf("press 'q' to quit or enter to continue\n");
            char option = getchar();
            if (option != '\n')
                clear_buffer();
            if (option == 'q' || option == 'Q')
                break;
            else
                continue;
        }

        if (turn)
        {
            printf("your turn [row col]: ");
            scanf("%d %d", &row, &col);
            clear_buffer();
            if (row < 1 || row > 3 || col < 1 || col > 3)
                continue;
            if (!set_value(--row, --col, PLAYER))
                continue;
            turn = turn^1;
        }
        else
        {
            computer_normal(choice, board);
            turn = turn^1;
        }
    };
};