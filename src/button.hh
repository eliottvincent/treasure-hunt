#ifndef BUTTON_H
#define BUTTON_H

#include <SDL2/SDL.h>
#include "../lib/sdl.hh"
#include <cstdlib>
#include <string>

/**************** Name of the structure *********************
∗ Button						                            *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It defines the parameters of the buttons        	        *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ Nothing                                                   *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ Nothing                                                   *
************************************************************/
struct Button
{
    int x;
    int y;
    int width;
    int height;

    SDL_Texture *sprite;
    TTF_Font *font;

    string text;
};

/**************** Name of the function **********************
∗ createButton  			                                *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It builds a button with the parameters set by the	        *
* strcture "Button"                                         *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ The surface, a text string, coordinates, font name        *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ A button                                                   *
************************************************************/
Button createButton(SDL_Texture *psprite, string text, int px, int yp, TTF_Font *font);

/**************** Name of the function **********************
∗ drawButton						                        *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It draws a button        	                                *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ The button's surface, the screen's surface                *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ A button                                                  *
************************************************************/
void drawButton(Button *pbutton);

/**************** Name of the function **********************
∗ buttonEvent   			                                *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It manages the mouse's events on the button     	        *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ A SDL event, the button's surface                         *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ a bool                                                    *
************************************************************/
bool buttonEvent(SDL_Event *event, Button *button);

#endif
