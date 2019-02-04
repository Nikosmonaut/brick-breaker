#ifndef WALL_H_INCLUDED
#define WALL_H_INCLUDED

#include "brick.h"

#define BRICK_SIZE 10

typedef struct
{
    Brick *brickList;
} Wall;

void initWall(Wall *wall);

#endif