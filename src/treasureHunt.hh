/********************************************************************************************
 * Project: Treasure Hunt
 * File: treasureHunt.h
 * ------------------------------------------------------------------------------------------
 * Authors: Pierre Lethuillier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <string>

SDL_Window *window;
SDL_Renderer *renderer;

//size of the plate
const int PLATE_SIZE = 7;

//number of fps
const int FPS = 30;

//size of the screen
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 420;

//the values of the coins
const int P1 = 100;
const int P2 = 10;
const int P3 = 20;
const int P4 = 30;
const int P5 = 50;

//the number of coins for each value
const int P1_NB = 1;
const int P2_NB = 14;
const int P3_NB = 14;
const int P4_NB = 14;
const int P5_NB = 5;

#endif
