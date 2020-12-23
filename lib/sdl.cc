/********************************************************************************************
 * Project: Treasure Hunt
 * File: sdl.cc
 * ------------------------------------------------------------------------------------------
 * Authors: Pierre Lethuillier, Eliott Vincent, Nicholas Journet
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#include "sdl.hh"
#include "../src/treasureHunt.hh"
#include <string>
#include <functional>
#include <iostream>

using namespace std;

// -- loadImage ---------------------------------
// chargement d'une image
// ----------------------------------------------
SDL_Texture *load_image(string file_path)
{
  SDL_Surface *tmp_image = IMG_Load(file_path.c_str());
  SDL_Texture *image     = NULL;

  if(tmp_image != NULL)
  {
    // Filling texture with the image using a surface
    image = SDL_CreateTextureFromSurface(renderer, tmp_image);

    // Deleting the temporary surface
    SDL_FreeSurface(tmp_image);
  }

  return image;
}


// -- loadImageTransparent ---------------------
// chargement d'une image
// * param�tres entr�es :
// - "filename" : nom de l'image
// - "r,g,b"    : couleur de la ColorKey; cette
//   couleur devient transparente !
// * param�tre de sortie : SDL_Texture contenant
//   l'image.
// ----------------------------------------------
SDL_Texture *load_image_transparent(string file_path, int r, int g, int b)
{
  SDL_Surface *tmp_image = IMG_Load(file_path.c_str());
  SDL_Texture *image     = NULL;

  if(tmp_image != NULL)
  {
    // Map the color key
    Uint32 colorkey = SDL_MapRGB(tmp_image->format, r, g, b);

     // Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
    SDL_SetColorKey(tmp_image, SDL_TRUE, colorkey);

    // Filling texture with the image using a surface
    image = SDL_CreateTextureFromSurface(renderer, tmp_image);

    // Deleting the temporary surface
    SDL_FreeSurface(tmp_image);
  }

  return image;
}

void apply_texture(SDL_Texture *source, int x, int y, SDL_Rect *clip)
{
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;
  offset.w = 640;
  offset.h = 420;

  refresh_screen(
    [source, offset]() {
      // SDL1.2
      // SDL_BlitSurface( source, clip, destination, &offset );

      // SDL2
      // Move the texture's contents to the video framebuffer
      SDL_RenderCopy(renderer, source, NULL, &offset);

      // SDL_RenderCopy(renderer, source, clip, &offset);
    }
  );
}


void drawText(
  string message,
  int x,
  int y,
  TTF_Font *font,
  int fontSize,
  RGBA textColor
)
{
  string word  = "";
  string space = " ";
  int i        = 0;
  int j        = message.find(space);

  SDL_Surface *mes            = NULL;
  SDL_Texture *mes_as_texture = NULL;
  SDL_Color texColor;

  texColor.r = textColor.r;
  texColor.g = textColor.g;
  texColor.b = textColor.b;

  while(j != string::npos)
  {
    word = message.substr(i, j-i);

    if(word != "")
    {
      mes = TTF_RenderText_Solid(font, word.c_str(), texColor);
      SDL_SetSurfaceAlphaMod(mes, textColor.a);

      mes_as_texture = SDL_CreateTextureFromSurface(renderer, mes);

      apply_texture(mes_as_texture, x, y, NULL);

      x += mes->w;

      SDL_FreeSurface(mes);
    }

    x += fontSize;
    i = j + 1;
    j = message.find(space, i);
  }

  word = message.substr(i);
  mes  = TTF_RenderText_Solid(font, word.c_str(), texColor);

  SDL_SetSurfaceAlphaMod(mes, textColor.a);
  mes_as_texture = SDL_CreateTextureFromSurface(renderer, mes);

  apply_texture(mes_as_texture, x, y, NULL);

  SDL_FreeSurface(mes);
}

Vector2 getTextSize(string text, TTF_Font *font)
{
    Vector2 p;
    SDL_Color c;
    c.r = 0;
    c.b = 0;
    c.g = 0;
    SDL_Surface *mes=TTF_RenderText_Solid(font,text.c_str(),c);
    p.x = mes->w;
    p.y = mes->h;
    return p;
}

int randInt(int mi, int ma)
{
    return mi + rand() % ((ma) - (mi) +1);
}

void manageFrames(int startTicks)
{
    int endMs = SDL_GetTicks();
    int delayMs = FPS - (endMs - startTicks);
    SDL_Delay(delayMs);
}

void refresh_screen(std::function<void()> operation)
{
  // Wipe out the existing video framebuffer
  SDL_RenderClear(renderer);

  // Run operation (i.e. write a texture to the video framebuffer)
  operation();

  // Put the video framebuffer on the screen
  SDL_RenderPresent(renderer);
}

string convertToString(int e)
{
    string s;
    stringstream t;
    t << e;
    s = t.str();
    return s;
}
