#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include <stdbool.h>
#include "window.h"
#include "platform.h"

typedef struct
{
    float x;
    float y;
    float angle;
    float direction;
    float speed;
    float offset;
} Ball;

void initBall(Ball *ball, Window *window);
void moveBallForward(Ball *ball, Window *window);
bool platformCollision(Ball *ball, Platform *platform);

#endif