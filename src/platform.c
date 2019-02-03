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