#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "window.h"
#include "platform.h"

void initPlatform(Platform *platform, Window *window)
{
    platform->size = 11;
    platform->speed = 4.2;
    platform->x = (window->x / 2) - (platform->size / 2);
    platform->y = window->y - 1;
}

void movePlatform(Platform *platform, Window *window, int userCommand)
{
    float nextX = 0;
    if (userCommand == 'l' && platform->x <= window->x)
    {
        nextX = platform->x + platform->speed;
        if (nextX <= (window->x - platform->size))
        {
            platform->x = nextX;
        }
        else
        {
            platform->x = window->x - platform->size;
        }
    }

    if (userCommand == 'h' && platform->x >= 0)
    {
        nextX = platform->x - platform->speed;
        if (nextX > 0)
        {
            platform->x = nextX;
        }
        else
        {
            platform->x = 0;
        }
    }
}