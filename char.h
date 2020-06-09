#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string.h>
typedef struct vie
{
  int nbr;
  SDL_Rect position;

  SDL_Surface *image;
}vie;
typedef struct {
  SDL_Surface *spriteleft;
  SDL_Surface *spriteright;
  int score;
  vie Vie;
  SDL_Rect position;
}charac;
charac initChar ();
void showChar(charac *cp, charac c, SDL_Surface * screen);

#endif
