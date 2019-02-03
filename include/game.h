#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "ball.h"
#include "window.h"
#include "platform.h"
typedef struct
{
    int level;
    int life;
    Ball ball;
    Window window;
    Platform platform;
} Game;

#endif