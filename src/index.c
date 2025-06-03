#include <stdio.h>
#include "utils.h"
#include "gameplay.h"

int main(void)
{
    int choice, is_valid;
    is_valid = 0;
    do
    {
        clear_screen();
        printf("Welcome to TIC-TAC-TOE\n");
        printf("choose difficulty:\n\t1. Normal\n\t2. Hard\n\t3. Exit\n");
        if (is_valid && (choice < 1 || choice > 3))
            printf("Bad input!!\n");
        scanf("%d", &choice);
        clear_buffer();
        is_valid = 1;
    }while (choice < 1 || choice > 3);

    if (choice == 3)
    {
        printf("exiting...\n");
        return 0;
    }
    play_game(choice);

    return 0;
};