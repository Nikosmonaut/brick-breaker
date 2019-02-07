#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ball.h"

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
static float calculateBiasedReflexionAngle(float distance, float x, float angle);

void initBall(Ball *ball, Window *window)
{
    ball->x = window->x / 2;
    ball->y = window->y - 2;
    float randomAngle = (float)rand() / (float)(RAND_MAX / (PI - 2 * MAX_ANGLE));
    ball->angle = randomAngle;
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
        ball->angle = calculateBiasedReflexionAngle(platform->size, ball->x - platform->x, ball->angle);
        ball->y = platform->y - 1;

        return true;
    }

    return false;
}

void wallCollision(Ball *ball, Wall *wall)
{
    Brick *brick;
    float brickLeft = 0.0;
    float brickRight = 0.0;

    for (int i = 0; i < wall->brickCount; i++)
    {
        brick = &wall->brickList[i];
        if (brick->life == 0)
        {
            continue;
        }
        brickLeft = brick->x;
        brickRight = brick->x + brick->size;

        if (floor(ball->y) == floor(brick->y) && ball->x < brickRight && ball->x > brickLeft)
        {
            brick->life--;
            ball->angle = calculateReflexionAngle(ball->angle, 'x');
        }
    }
}

static float calculateReflexionAngle(float angle, char contactAxis)
{
    if (contactAxis == 'y')
    {
        return PI - angle;
    }

    if (contactAxis == 'x')
    {
        return 2 * PI - angle;
    }

    return PI;
}

static float calculateBiasedReflexionAngle(float distance, float x, float angle)
{
    float nextReflexionAngle = calculateReflexionAngle(angle, 'x');

    float halfDistance = distance / 2;
    float distanceFromMiddle = fabs(x - halfDistance);

    float percentDistanceFromMiddle = 100 - (distanceFromMiddle / halfDistance * 100);
    float stepAngle = (PI / 2 - MAX_ANGLE) / 100;
    float relativeAngle = percentDistanceFromMiddle * stepAngle;

    if (nextReflexionAngle < PI / 2)
    {
        return relativeAngle + MAX_ANGLE;
    }

    if (nextReflexionAngle < PI)
    {
        return 5 * MAX_ANGLE - relativeAngle;
    }

    if (nextReflexionAngle < 3 * PI / 2)
    {
        return PI + relativeAngle + MAX_ANGLE;
    }

    return 2 * PI - relativeAngle - MAX_ANGLE;
}
