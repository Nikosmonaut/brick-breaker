#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include <window.h>

typedef struct
{
    int x;
    int y;
    int angle;
    int direction;
    int speed;
    int offset;
} Ball;

void drawBall(Ball *ball);
void initBall(Ball *ball, WindowSize *windowSize);
void nextStep(Ball *ball, WindowSize *windowSize);

#endif