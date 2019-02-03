#ifndef PLATFORM_H_INCLUDED
#define PLATFORM_H_INCLUDED

#include "window.h"

typedef struct
{
    int x;
    int y;
    int size;
} Platform;

void initPlatform(Platform *platform, Window *window);

#endif