#ifndef FONCTIONS_H_
#define FONCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>

/**
 * @struct enemy
 * @brief struct for enemy
*/





typedef struct
{

SDL_Rect  position_enemy;     /*!< Rectangle*/
SDL_Surface * image_enemy;    /*!< Surface. */
SDL_Rect positionmax_enemy;   /*!< Rectangle*/
SDL_Rect positionmin_enemy;   /*!< Rectangle*/


} enemy;



void initialiser_enemy(enemy *E);
int afficher_enemy(enemy E,SDL_Surface*screen);







#endif /* FONCTIONS_H_ */
