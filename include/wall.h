#ifndef WALL_H_INCLUDED
#define WALL_H_INCLUDED

#include "brick.h"

#define BRICK_SIZE 10
#define BRICK_COUNT 3

typedef struct
{
    Brick *brickList;
    int brickCount;
} Wall;

void initWall(Wall *wall);

#endif