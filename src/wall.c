#include <stdlib.h>
#include "wall.h"


void initWall(Wall *wall)
{
    wall->brickList = malloc(3 * sizeof(Brick));
    Brick brickList[3];
    for (int i = 0; i < 3; i++)
    {
        (brickList[i]).x = BRICK_SIZE * (i + 1);
        (brickList[i]).y = 6;
        (brickList[i]).size = BRICK_SIZE;
        (brickList[i]).life = 1;
    }

    wall->brickList = brickList;
}
