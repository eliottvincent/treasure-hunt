#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <vector>

#include "../lib/sdl.hh"
#include "treasureHunt.hh"

class State;

class Game
{
  private:
    // Make constructor private
    Game() {};

    std::vector <State*> states;
    bool m_running;

  public:
    // Singleton
    static Game &getInstance()
    {
      static Game instance;

      return instance;
    }

    // Methods we don't want
    Game(Game const&)           = delete;
    void operator=(Game const&) = delete;

    // Other variables and methods
    SDL_Window *window;
    SDL_Surface *screen;
    SDL_Renderer *renderer;

    void init();
    void cleanup();

    void changeState(State *state);
    void pushState(State *state);
    void popState();

    void handleEvents();
    void draw();
    void update();

    void quit() { m_running = false; };

    bool running() { return m_running; };
};

#endif
