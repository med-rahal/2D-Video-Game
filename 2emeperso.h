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
typedef struct perso2
{
SDL_Surface *image2;
SDL_Rect pos2;
    int vi2;
    int argent2;
}perso2;
void init_perso(perso *p);
void affiche_perso(perso *p,SDL_Surface *screen);
void deplacerclaviersouris(SDL_Event event,perso *p,SDL_Surface *screen);
void init_perso2(perso2 *p2);
void affiche_perso2(perso2 *p2,SDL_Surface *screen);
void deplacerclaviersouris2(SDL_Event event2,perso2 *p2,SDL_Surface *screen);
