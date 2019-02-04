#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "ball.h"
#include "platform.h"
#include "wall.h"
#include "window.h"
typedef struct
{
    int level;
    int life;
    Ball ball;
    Window window;
    Platform platform;
    Wall wall;
} Game;

#endif