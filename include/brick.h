#ifndef BRICK_H_INCLUDED
#define BRICK_H_INCLUDED

typedef struct
{
    float x;
    float y;
    int size;
    int life;
} Brick;

void touchBrick(Brick *brick);

#endif