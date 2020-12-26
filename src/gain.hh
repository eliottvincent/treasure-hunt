#ifndef GAIN_H
#define GAIN_H

#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include "treasureHunt.hh"
#include "../lib/sdl.hh"
#include "button.hh"
#include "player.hh"

int gain(Player *winner);
int gainEvents(Button *replay, Button *quit);

#endif
