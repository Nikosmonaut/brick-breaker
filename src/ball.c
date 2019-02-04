#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ball.h"

#define PI 3.14159265

/**
 * Calculate next angle after a wall collision
 */
static float calculateReflexionAngle(float angle, char contactAxis);

/**
 * Calculate next angle after platform collision
 * It differs from classic collision
 * by a different reflexion angle depending
 * on the collision place on the platform
 * Near the center little angle
 * Near border wide angle
 */
static float calculateBiasedReflexionAngle(Platform *platform, float ballX);

void initBall(Ball *ball, Window *window)
{
    ball->x = window->x / 2;
    ball->y = window->y - 2;
    ball->angle = 5 * PI / 4;
    ball->speed = 0.2;
}

void moveBallForward(Ball *ball, Window *window)
{
    ball->y += ball->speed * sin(ball->angle);
    ball->x += ball->speed * cos(ball->angle);

    if (ball->y >= window->y || ball->y <= 0)
    {
        ball->angle = calculateReflexionAngle(ball->angle, 'x');
    }

    if (ball->x >= window->x || ball->x <= 0)
    {
        ball->angle = calculateReflexionAngle(ball->angle, 'y');
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
        ball->angle = calculateReflexionAngle(ball->angle, 'x');

        return true;
    }

    return false;
}

static float calculateReflexionAngle(float angle, char contactAxis)
{
    if (contactAxis == 'y')
    {
        if (angle <= PI)
        {
            return PI - angle;
        }
        if (angle > PI)
        {
            float normalizedAngle = 2 * PI - angle;
            return PI - normalizedAngle;
        }
    }

    if (contactAxis == 'x')
    {
        return 2 * PI - angle;
    }

    return PI;
}

static float calculateBiasedReflexionAngle(Platform *platform, float ballX)
{
    float platformLeft = platform->x;
    float platformRight = platform->x + platform->size;
    float platformMiddle = platformLeft + platform->size / 2;

    if (ballX < platformMiddle)
    {
        ballX += (platformMiddle - ballX);
    }

    float percent = (ballX - platformLeft) / (platformRight - platformLeft) * 100;

    return percent;
}
