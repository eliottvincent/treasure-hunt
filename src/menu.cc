#include <stdio.h>

#include "game.hh"
#include "state.hh"
#include "menu.hh"

Menu Menu::m_menu;
TTF_Font *small = TTF_OpenFont("assets/font.ttf", 20);

void Menu::init()
{
  // We first load all the assets that are necessary to the menu
  SDL_Texture *button_sprite = load_image_transparent("assets/button.png", 0, 255, 255);
  SDL_Texture *background    = load_image("assets/background.png");

  Button play                = createButton(
    button_sprite,
    "Jouer",
    WINDOW_WIDTH/2 - 500/2,
    WINDOW_HEIGHT - 150,
    small
  );

  Button quit                = createButton(
    button_sprite,
    "Quitter",
    WINDOW_WIDTH/2 + 80/2,
    WINDOW_HEIGHT-150,
    small
  );
}

void Menu::cleanup()
{

}

void Menu::pause()
{

}

void Menu::resume()
{

}

void Menu::handleEvents(Game *game)
{

}

void Menu::update(Game *game)
{

}

void Menu::draw(Game *game)
{
  // Draw background color
  draw_color(228, 207, 71);

  RGBA color;
  color.r = 150;
  color.g = 150;
  color.b = 150;
  color.a = 255;

  // Draw title
  drawTextBis("Treasure Hunt", 10, 100, small, 20, color);
}
