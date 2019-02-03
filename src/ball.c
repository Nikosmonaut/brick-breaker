#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "ball.h"

void initBall(Ball *ball, Window *window)
{
    ball->x = window->x / 2;
    ball->y = window->y - 2;
    ball->angle = 1;
    ball->direction = -1;
    ball->speed = 0.2;
    ball->offset = ball->y - (ball->angle * ball->x);
}

void moveBallForward(Ball *ball, Window *window)
{
    ball->y += ball->direction * ball->speed;
    ball->x = (ball->y - ball->offset) / ball->angle;

    if (ball->y >= window->y || ball->y <= 0)
    {
        ball->angle *= -1;
        ball->direction *= -1;
        ball->offset = ball->offset + (ball->y - ball->offset) * 2;
    }

    if (ball->x >= window->x || ball->x <= 0)
    {
        ball->angle *= -1;
        ball->offset = ball->offset + (ball->y - ball->offset) * 2;
    }
}

bool platformCollision(Ball *ball, Platform *platform)
{
    if (ball->y < platform->y)
    {
        return true;
    }

    float platformLeft = platform->x;
    float platformRight = platform->x + platform->size;

    if (ball->x >= platformLeft && ball->x <= platformRight)
    {
        ball->angle *= -1;
        ball->direction *= -1;
        ball->offset = ball->offset + (ball->y - ball->offset) * 2;

        return true;
    }

    return false;
}
