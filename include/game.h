#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

typedef struct
{
    int level;
    int life;
} Game;

void initGame();
void startGame();
void endGame();

#endif