#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string.h>
typedef struct {

  SDL_Surface *sprite;
  SDL_Rect position;
}ennemi;
void setrects(SDL_Rect* clip);
ennemi initennemi();
void animationennemie(ennemi e, int frame, SDL_Surface *screen);
#endif
