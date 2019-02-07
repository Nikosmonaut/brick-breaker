#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

#include "cli_brick.h"

void drawBrick(Brick *brick)
{
    if (brick->life == 0)
    {
        return;
    }

    char *brickShape = malloc(brick->size * sizeof(char) + 1);
    for (int i = 0; i < brick->size; i++)
    {
        brickShape[i] = '=';
    }

    brickShape[brick->size] = '\0';

    mvprintw(brick->y, brick->x, brickShape);
    free(brickShape);
}