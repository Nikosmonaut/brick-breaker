#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include "window.h"

typedef struct
{
    int x;
    int y;
    int angle;
    int direction;
    int speed;
    int offset;
} Ball;

void initBall(Ball *ball, Window *window);
void moveForward(Ball *ball, Window *window);

#endif