#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include<SDL/SDL_audio.h>

typedef struct perso
{
SDL_Surface *image;
SDL_Rect pos;
    int vi;
    int argent;
}perso;
void init_perso(perso *p);
void affiche_perso(perso *p,SDL_Surface *screen);
void deplacerclaviersouris(SDL_Event event,perso *p,SDL_Surface *screen);
