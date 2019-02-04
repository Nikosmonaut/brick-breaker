#include "cli_wall.h"
#include "cli_brick.h"

void drawWall(Wall *wall)
{
    for (int i = 0; i < wall->brickCount; i++)
    {
        drawBrick(&wall->brickList[i]);
    }
}