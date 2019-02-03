#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "ball.h"
#include "window.h"
typedef struct
{
    int level;
    int life;
    Ball ball;
    Window window;
} Game;

#endif