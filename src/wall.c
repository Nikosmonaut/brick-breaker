#include <stdlib.h>
#include "wall.h"

void initWall(Wall *wall)
{
    wall->brickList = malloc(BRICK_COUNT * sizeof(Brick));
    wall->brickCount = BRICK_COUNT;

    for (int i = 0; i < BRICK_COUNT; i++)
    {
        wall->brickList[i].x = BRICK_SIZE * (i + 1);
        wall->brickList[i].y = 6;
        wall->brickList[i].size = BRICK_SIZE;
        wall->brickList[i].life = 1;
    }
}
