/********************************************************************************************
 * Project: Treasure Hunt
 * File: button.cc
 * ------------------------------------------------------------------------------------------
 * Authors: Pierre Lethuillier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#include "button.h"

using namespace std;

Button createButton(SDL_Surface *psurface, std::string text, int px, int py, TTF_Font *font)
{
    Button b;
    b.sprite = psurface;
    b.x = px;
    b.y = py;
    b.width = 200;
    b.height = 56;
    b.font = font;
    b.text = text;
    return b;
}

void drawButton(Button *pbutton, SDL_Surface *screen)
{
    applySurface(pbutton->x, pbutton->y, pbutton->sprite, screen, NULL);
    Vector2 size = getTextSize(pbutton->text, pbutton->font);
    RGBA r;
    r.b = 255;r.g=255; r.r=255; r.a = 255;

    //we draw the text on the button's surface
    drawText(pbutton->text, pbutton->x + pbutton->width/2 - size.x/2, pbutton->y + pbutton->height/2 - size.y/2 +5, pbutton->font, 20,r,screen);
}

bool buttonEvent(SDL_Event *event, Button *button)
{
    //we search if the button has been clicked or not
    if(event->type==SDL_MOUSEBUTTONDOWN)
    {
        int x = event->button.x;
        int y = event->button.y;
        if(x >= button->x && x <= button->x + button->width && y >= button->y && y <=button->y + button->height)
        {
            return true;
        }
    }
    return false;
}
