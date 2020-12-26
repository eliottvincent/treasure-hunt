#ifndef item
#define item

#include "../lib/sdl.hh"

/**************** Name of the structure *********************
∗ Item						                                *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It defines the parameters of the items        	        *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ Nothing                                                   *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ Nothing                                                   *
************************************************************/
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

/**************** Name of the function **********************
∗ createPlayer()			                                *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It creates a player with the help of the structure "Item" *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ The coordinates                                           *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ The player                                                *
************************************************************/
Item createPlayer(int x, int y);

/**************** Name of the function **********************
∗ createCoin()			                                    *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Description ****************************
∗ It creates a coin with the help of the structure "Item"   *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Input *************************************
∗ The coordinates                                           *
∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗ Output ********************************
∗ The coin                                                *
************************************************************/
Item createCoin(int x, int y, int value);

#endif
