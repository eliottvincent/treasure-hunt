#include "combo.hh"

Combo createCombo(int x, int y, Player *player)
 {
     Combo j;
     j.x = x;
     j.y = y;
     j.player = player;
     j.frame = 0;
     return j;
 }

void drawCombo(Combo combo, TTF_Font *font)
{
    int d = 10*pow(2, (combo.player->combo-1));
    if(combo.player->combo == 0)
        d = 0;
    std::string m = "+"+convertToString(d);
    RGBA color;
    color.r = 150;
    color.g = 150;
    color.b = 150;
    color.a = 255;
    drawText(m, combo.x+10, combo.y+40, font, 32, color);
}
