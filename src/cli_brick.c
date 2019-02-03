#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

#include "cli_brick.h"

void drawBrick(Brick *brick)
{
    char *brickShape = malloc(brick->size * sizeof(char));
    for (int i = 0; i < brick->size; i++)
    {
        strcat(brickShape, "=");
    }

    mvprintw(brick->y, brick->x, brickShape);
    free(brickShape);
}