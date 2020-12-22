/********************************************************************************************
 * Project: Treasure Hunt
 * File: sdlFunctions.cc
 * ------------------------------------------------------------------------------------------
 * Authors: Pierre Lethuillier, Eliott Vincent, Nicholas Journet
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#include "sdlFunctions.h"

using namespace std;

// -- loadImage ---------------------------------
// chargement d'une image
// ----------------------------------------------
SDL_Surface *load_image(std::string filename)
{

    //Temporary storage for the image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;
     //Load the image

    loadedImage = IMG_Load( filename.c_str() );
    //If nothing went wrong in loading the image
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old image
        SDL_FreeSurface( loadedImage );
    }

      //Return the optimized image
    return optimizedImage;
}


// -- loadImageTransparent ---------------------
// chargement d'une image
// * param�tres entr�es :
// - "filename" : nom de l'image
// - "r,g,b"    : couleur de la ColorKey; cette
//   couleur devient transparente !
// * param�tre de sortie : SDL_Surface contenant
//   l'image.
// ----------------------------------------------
SDL_Surface * LoadImageTransparent(string filename, int r, int g, int b)
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old image
        SDL_FreeSurface( loadedImage );

        //If the image was optimized just fine
        if( optimizedImage != NULL )
        {
            //Map the color key
            Uint32 colorkey = SDL_MapRGB( optimizedImage->format, r, g, b );

             //Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
        }


     }
   //Return the optimized image
   return optimizedImage;

}

void applySurface(int x, int y, SDL_Surface* source,
         SDL_Surface* destination, SDL_Rect* clip)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface( source, clip, destination, &offset );
}


void drawText(std::string message,int x,int y, TTF_Font *font,int fontSize,RGBA textColor,SDL_Surface* &screen)
{
  string mot="";
  string space=" ";
  int i=0,j;
  SDL_Surface *mes=NULL;

  j = message.find(space);
      SDL_Color texColor;
      texColor.r = textColor.r;
      texColor.g = textColor.g;
      texColor.b = textColor.b;
  while( j != string::npos )
    {
      mot=message.substr(i,j-i);
      if(mot != "")
    {

      mes=TTF_RenderText_Solid(font,mot.c_str(),texColor);
      SDL_SetAlpha(mes,SDL_SRCALPHA,textColor.a);
      applySurface(x,y,mes,screen,NULL);
      x+=mes->w;
      SDL_FreeSurface(mes);
    }
      x+=fontSize;
      i=j+1;
      j = message.find(space,i);
    }

  mot=message.substr(i);
  mes=TTF_RenderText_Solid(font,mot.c_str(),texColor);
  SDL_SetAlpha(mes,SDL_SRCALPHA,textColor.a);
  applySurface(x,y,mes,screen,NULL);
  SDL_FreeSurface(mes);
}

Vector2 getTextSize(std::string text, TTF_Font *font)
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

string convertToString(int e)
{
    string s;
    stringstream t;
    t << e;
    s = t.str();
    return s;
}
