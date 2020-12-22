/********************************************************************************************
 * Project: Treasure Hunt
 * File: sdlFunctions.h
 * ------------------------------------------------------------------------------------------
 * Authors: Pierre Lethuillier, Eliott Vincent, Nicholas Journet
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#ifndef SDLFUNCTIONS_H
#define SDLFUNCTIONS_H

#include <stdlib.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <sstream>
#include <iostream>
#include <math.h>

#include "treasureHunt.h"


struct Rectangle
{
    float x;
    float y;
    float width;
    float height;
};

struct Vector2
{
    float x;
    float y;
};

struct RGBA
{
    int r;
    int g;
    int b;
    int a;
};

//Charge une image
SDL_Surface *load_image(std::string filename);

//Charge une image avec la transparence
SDL_Surface *LoadImageTransparent(std::string filename, int r, int g , int b);

//Colle une image � l'�cran
void applySurface(int x,int y,SDL_Surface *toapply, SDL_Surface *onapply, SDL_Rect* clip );

//affiche du texte � l'�cran
void drawText(std::string message,int x,int y,TTF_Font *font,int fontSize,RGBA textColor,SDL_Surface* &screen);

Vector2 getTextSize(std::string text, TTF_Font *font);

int randInt(int mi, int ma);

void manageFrames(int startTicks);

std::string convertToString(int e);
#endif
