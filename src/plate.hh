#ifndef PLATE_H
#define PLATE_H

#include <SDL2/SDL.h>
#include <iostream>
#include <cstdlib>
#include "treasureHunt.hh"
#include "../lib/sdl.hh"

typedef struct
{
    int value;
}Coin;


typedef Coin Map[PLATE_SIZE][PLATE_SIZE];

void initPlate(Map myplate);
void createOccurrences(int position[], int &length);
void deleteOccurence(int m[], int &length, int index);

int getIndexInSpriteSheet(int value);
void drawPlate(Map myplate, SDL_Texture *coins);

#endif
