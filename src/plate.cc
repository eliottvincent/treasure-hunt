/********************************************************************************************
 * Project: Treasure Hunt
 * File: plate.cc
 * ------------------------------------------------------------------------------------------
 * Authors: Pierre Lethuillier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#include "plate.hh"

using namespace std;


void createOccurrences(int position[])
{
    int index = 0;
    for(int i = 0; i<P1_NB; i++)
        position[i] = P1;
    index+=P1_NB;
    for(int i = index; i<index+P2_NB; i++)
        position[i] = P2;
    index+=P2_NB;
    for(int i = index; i<index+P3_NB; i++)
        position[i] = P3;
    index+=P3_NB;
    for(int i = index; i<index+P4_NB; i++)
        position[i] = P4;
    index+=P4_NB;
    for(int i = index; i<index+P5_NB; i++)
        position[i] = P5;
    index+=P5_NB;
}

void deleteOccurence(int m[], int &length, int index)
{
    for(int i = index; i < length; i++)
    {
        m[i] = m[i+1];
    }
    length = length-1;
}

void initPlate(Map myplate)
{
    int length = PLATE_SIZE*PLATE_SIZE-1;
    int position[length];
    createOccurrences(position);

    int cmpt = 0;
    for(int i = 0; i< PLATE_SIZE; i++)
    {
        for(int u = 0; u < PLATE_SIZE; u++)
        {
            int index= randInt(0,length-1);

            if(!(i==PLATE_SIZE/2 && u==PLATE_SIZE/2))
            {
                Coin c;
                c.value = position[index];
                if((i==PLATE_SIZE/2 || u==PLATE_SIZE/2) && c.value==P1)
                    u-=1;
                else
                {
                    myplate[i][u] = c;
                    deleteOccurence(position, length, index);
                    cmpt +=1;
                }
            }
        }
    }
    //Placement d'une piece nulle au centre de la grille
    Coin c;
    c.value = 0;
    myplate[PLATE_SIZE/2][PLATE_SIZE/2] = c;
}

int getIndexInSpriteSheet(int value)
{
    int index = 0;
    switch(value)
    {
    case 10:
        index = 0;
        break;
    case 20:
        index = 60;
        break;
    case 30:
        index = 120;
        break;
    case 50:
        index = 180;
        break;
    case 100:
        index = 180+60;
        break;
    default:
        index = -1;
    }
    return index;
}

void drawPlate(Map myplate, SDL_Surface *coins, SDL_Window *screen)
{
    for(int i = 0; i< PLATE_SIZE; i++)
    {
        for(int u=0; u< PLATE_SIZE; u++)
        {

            int index = getIndexInSpriteSheet(myplate[i][u].value);


            SDL_Rect rect;
            if(index > -1)
            {
                rect.x = index;
                rect.y = 0;
                rect.w = 60;
                rect.h = 60;
            }

            else
            {
                rect.x = 0;
                rect.y = 184;
                rect.w = 60;
                rect.h = 60;
            }
            applySurface(i*60,u*60,coins, screen, &rect);

        }
    }
}
