/**
 * @file AffichageObj.c
 * @brief Testing Program.
 * @author Barkia Mohamed
 * @version 0.1
 * @date June 15, 2020
 *
 * Testing program for collisionBB
 *
 */



/**
 * @file AffichageObj.c
*/



#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "object.h"



/**
 * @brief To show object
 * @param posj the player position 
 * @param posobj the enemy position
 * @return x
*/


void affichageObj ( Objet obj , SDL_Surface *screen) 
{

SDL_BlitSurface(obj.image, NULL, screen, &(obj.position));
SDL_Flip(screen);

}
