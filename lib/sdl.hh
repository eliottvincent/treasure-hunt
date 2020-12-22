/********************************************************************************************
 * Project: Treasure Hunt
 * File: sdl.hh
 * ------------------------------------------------------------------------------------------
 * Authors: Pierre Lethuillier, Eliott Vincent, Nicholas Journet
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#ifndef SDL_H
#define SDL_H

#include <stdlib.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <sstream>
#include <iostream>
#include <math.h>

using namespace std;

extern SDL_Renderer *renderer;

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

// Loads an image
SDL_Texture *load_image(string filepath);

//Charge une image avec la transparence
SDL_Texture *load_image_transparent(string filepath, int r, int g , int b);

//Colle une image � l'�cran
void apply_surface(int x, int y, SDL_Texture *toapply, SDL_Rect *clip);

//affiche du texte � l'�cran
void drawText(string message,int x,int y,TTF_Font *font,int fontSize,RGBA textColor);

Vector2 getTextSize(string text, TTF_Font *font);

int randInt(int mi, int ma);

void manageFrames(int startTicks);

string convertToString(int e);
#endif
