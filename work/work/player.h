#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
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

void gestion_vie(vie *v,int i);
Player InitPlayer(Player Hero);
Player update(Player Hero,int i);

void  afficher_vie(vie v,SDL_Surface *screen);
