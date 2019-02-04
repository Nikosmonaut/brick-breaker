#ifndef PLATFORM_H_INCLUDED
#define PLATFORM_H_INCLUDED

#include "window.h"

#define PLATFORM_SIZE 11
typedef struct
{
    float x;
    float y;
    float speed;
    int size;
} Platform;

void initPlatform(Platform *platform, Window *window);
void movePlatform(Platform *platform, Window *window, int userCommand);

#endif