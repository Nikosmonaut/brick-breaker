#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <ball.h>
#include <window.h>

void drawBall(Ball *ball)
{
    mvprintw(ball->y, ball->x, "o");
}

void initBall(Ball *ball, WindowSize *windowSize)
{
    ball->x = windowSize->x / 2;
    ball->y = windowSize->y;
    ball->angle = 1;
    ball->direction = -1;
    ball->speed = 1;
    ball->offset = ball->y - (ball->angle * ball->x);
}

void nextStep(Ball *ball, WindowSize *windowSize)
{
    ball->y += ball->direction;
    ball->x = (ball->y - ball->offset) / ball->angle;

    if (ball->y >= windowSize->y || ball->y <= 0)
    {
        ball->angle *= -1;
        ball->direction *= -1;
        ball->offset = ball->offset + (ball->y - ball->offset) * 2;
    }

    if (ball->x >= windowSize->x || ball->x <= 0)
    {
        ball->angle *= -1;
        ball->offset = ball->offset + (ball->y - ball->offset) * 2;
    }
}
