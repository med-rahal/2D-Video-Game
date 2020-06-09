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
typedef struct Player
{

  int score;
  vie vie;

}Player;
Player update(Player p,int i);
void condition(SDL_Surface *ecran);
#endif
