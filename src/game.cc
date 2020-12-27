#include <stdio.h>
#include <SDL2/SDL.h>

#include "game.hh"
#include "state.hh"

void Game::init()
{
  // Init SDL
  SDL_Init(SDL_INIT_EVERYTHING);
  IMG_Init(IMG_INIT_PNG);
  TTF_Init();

  // Create SDL objects
  window = SDL_CreateWindow("Treasure Hunt", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  m_running = true;
}

void Game::cleanup()
{
  // Clean all states
  while (!states.empty())
  {
    states.back()->cleanup();
    states.pop_back();
  }

  // Destroy the window and the renderer
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);

  // Clean up
  IMG_Quit();
  TTF_Quit();
  SDL_Quit();
}

void Game::changeState(State *state)
{
  // Clean current state
  if (!states.empty())
  {
    states.back()->cleanup();
    states.pop_back();
  }

  // Store and initialize new state
  states.push_back(state);
  states.back()->init();
}

void Game::pushState(State *state)
{
  // Pause current state
  if (!states.empty())
  {
    states.back()->pause();
  }

  // Store and initialize new state
  states.push_back(state);
  states.back()->init();
}

void Game::popState()
{
  // Clean current state
  if (!states.empty())
  {
    states.back()->cleanup();
    states.pop_back();
  }

  // Resume previous state
  if (!states.empty())
  {
    states.back()->resume();
  }
}

void Game::handleEvents()
{
  // Let the state handle the events
  if (!states.empty())
  {
    states.back()->handleEvents(this);
  }
}

void Game::draw()
{
  // Let the state draw
  if (!states.empty())
  {
    states.back()->draw(this);
  }
}

void Game::update()
{
  // Let the state update
  if (!states.empty())
  {
    states.back()->update(this);
  }
}
