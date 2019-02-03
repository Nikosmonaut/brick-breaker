#include <ncurses.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "window.h"
#include "platform.h"

void initPlatform(Platform *platform, Window *window)
{
    platform->x = window->x / 2 - 5;
    platform->y = window->y - 1;
    platform->size = 10;
}

void movePlatform(Platform *platform, Window *window, int userCommand)
{
    if (userCommand == 'l' && platform->x <= window->x)
    {
        platform->x += 3;
    }

    if (userCommand == 'h' && platform->x >= 0)
    {
        platform->x -= 3;
    }
}