#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

#include "cli_platform.h"

void drawPlatform(Platform *platform)
{
    char *platformShape = malloc(platform->size * sizeof(char));
    for (int i = 0; i < platform->size; i++)
    {
        strcat(platformShape, "=");
    }

    mvprintw(platform->y, platform->x, platformShape);
    free(platformShape);
}