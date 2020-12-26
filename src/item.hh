#ifndef item
#define item

#include "../lib/sdl.hh"

struct Item
{
    int x;
    int y;
    Vector2 velocity;
    int combo;
    int lastCoin;
    int points;
    bool isPlayer;
};

Item createPlayer(int x, int y);
Item createCoin(int x, int y, int value);

#endif
