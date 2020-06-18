#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>



/**
 * @struct backgr
 * @brief struct for background
*/



typedef struct backgr
{
    SDL_Surface *image;    /*!< Surface. */
    SDL_Rect pos;          /*!< Rectangle*/
    int stage;
}backgr;


/**
 * @struct perso
 * @brief struct for perso
*/


typedef struct perso
{
  SDL_Surface *image;       /*!< Surface. */
  SDL_Surface *per;         /*!< Surface. */
  SDL_Surface *per1;        /*!< Surface. */
  SDL_Rect posper;          /*!< Rectangle*/
  SDL_Rect posper1;         /*!< Rectangle*/
}perso;

void afficher_background(backgr bg,SDL_Surface*screen);
void afficher_perso(perso p,SDL_Surface*screen);
void afficher_perso1(perso p1,SDL_Surface*screen);
void afficher_background1(backgr bg1,SDL_Surface*screen);


#endif // MAIN_H_INCLUDED

