#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void clear_buffer(void)
{
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;
};

void clear_screen(void)
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
};