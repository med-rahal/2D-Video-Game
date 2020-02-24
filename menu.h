#ifndef MENU_H_
#define MENU_H_

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include <time.h>



void sounds(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique,int *i);
void controls(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique,int *i);
void resolution(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique,int *i);
void sounds(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique,int *i);
void menu(SDL_Surface *ecran,Mix_Music *musique,int *i);
void play(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique,int *i);
void setting(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique,int *i);
void choose(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique,int *i,int l);









#endif 

