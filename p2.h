#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string.h>
typedef struct {
  SDL_Surface *spriteleft;
  SDL_Surface *spriteright;
  SDL_Surface *bas;
  SDL_Surface *haut;
  SDL_Rect position;
}charac;

struct ennemie
{
SDL_Surface *sprite;
SDL_Rect position;
};
typedef struct ennemie ennemie;

struct vie
{
  int nbr;
  SDL_Rect position;
  SDL_Surface *image;
};
typedef struct vie vie;

struct score
{
TTF_Font *police;
int tempsActuel;
int tempsPrecedent;
int compteur ;
SDL_Surface *texte;
SDL_Rect position;
};

typedef struct score score ;

/**
* @struct temps
* @brief struct for temps
*/

struct temps
{
TTF_Font *police;
int tempsActuel;
int tempsPrecedent;
int compteur ;
SDL_Surface *texte;
SDL_Rect position;
};

typedef struct temps temps ;

/**
* @struct fond
* @brief struct for fond
*/

struct fond
{
SDL_Rect position1;
SDL_Rect position2;
SDL_Surface *image1;
SDL_Surface *image2;
};
typedef struct fond fond;


struct enigme 
{
	SDL_Surface *img[3];
	SDL_Rect position;

};
typedef struct enigme enigme ;


typedef struct BackGround
{
  SDL_Surface *image;
   SDL_Surface *calque;
  SDL_Rect position;
  SDL_Rect camera;
}BackGround;
void save(SDL_Surface *ecran,int *continuer, charac p ,vie v,score s, temps t,ennemie en,BackGround back, enigme e);
#endif







