#ifndef COMBO_H
#define COMBO_H

#include <SDL2/SDL.h>
#include <iostream>
#include "player.hh"
#include "../lib/sdl.hh"

struct Combo
{
    int x;
    int y;
    float frame;
    Player *player;
    int lastCombo;
};

Combo createCombo(int x, int y, Player *player);
void drawCombo(Combo combo, TTF_Font *font);

#endif
