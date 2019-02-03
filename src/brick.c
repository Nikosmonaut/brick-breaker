#include "brick.h"

void initBrick(Brick *brick)
{
    brick->x = 0;
    brick->y = 0;
    brick->size = 5;
    brick->life = 1;
}

void touchBrick(Brick *brick)
{
    brick->life--;
}