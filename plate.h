/********************************************************************************************
 * Project: Treasure Hunt
 * File: plate.h
 * ------------------------------------------------------------------------------------------
 * Authors: Pierre Lethuillier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#ifndef PLATE_H
#define PLATE_H

#include <SDL2/SDL.h>
#include <iostream>
#include <cstdlib>
#include "treasureHunt.h"
#include "sdlFunctions.h"

/**************** Name of the type **************************
∗ Coin          			                                *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It defines the parameters of the structure "Coin"         *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ Nothing                                                   *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ Nothing                                                   *
************************************************************/
typedef struct
{
    int value;
}Coin;

/**************** Name of the type **************************
∗ Map           			                                *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It creates the map's parameters                           *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ Nothing                                                   *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ Nothing                                                   *
************************************************************/
typedef Coin Map[PLATE_SIZE][PLATE_SIZE];

/**************** Name of the function **********************
∗ initPlate()			                                *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It creates a player with the help of the strcture "Item"  *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ The coordinates                                           *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ The player                                                *
************************************************************/
void initPlate(Map myplate);

/**************** Name of the function **********************
∗ createOccurrences()			                            *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It creates the occurrences for the coins's position       *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ The position, the lenght                                  *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ The positions (index)                                     *
************************************************************/
void createOccurrences(int position[], int &length);

/**************** Name of the function **********************
∗ deleteOccurrences()			                            *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It delete the occurrence each time it is attributed to a  *
* coin                                                      *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ The coordinates                                           *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ The player                                                *
************************************************************/
void deleteOccurence(int m[], int &length, int index);

int getIndexInSpriteSheet(int value);

/**************** Name of the function **********************
∗ drawPlate()			                                    *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It draws the plate                                        *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ The plate, the coins's surface, the screen's surface      *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ The plate                                                *
************************************************************/
void drawPlate(Map myplate, SDL_Surface *coins, SDL_Surface *screen);

#endif
