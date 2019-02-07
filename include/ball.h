#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include <stdbool.h>
#include "window.h"
#include "platform.h"
#include "wall.h"

#define PI 3.14159265
#define MAX_ANGLE (PI / 8)

typedef struct
{
    float x;
    float y;
    float angle;
    float speed;
} Ball;

void initBall(Ball *ball, Window *window);
void moveBallForward(Ball *ball, Window *window);
bool platformCollision(Ball *ball, Platform *platform);
void wallCollision(Ball *ball, Wall *wall);

#endif