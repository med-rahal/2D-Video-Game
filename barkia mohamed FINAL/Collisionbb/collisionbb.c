/**
 * @file collisionbb.c
 * @brief Testing Program.
 * @author Barkia Mohamed
 * @version 0.1
 * @date June 15, 2020
 *
 * Testing program for collisionBB
 *
 */



/**
 * @file collisionbb.c
*/




#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "object.h"







/**
 * @brief To collisionbb
 * @param posj the player position 
 * @param posobj the enemy position
 * @return x
*/


int collisionbb( SDL_Rect posj , SDL_Rect posobj )
{
 int x ; 
if ( ((posj.y+posj.h>=posobj.y)&&(posj.y<=posobj.y+posobj.h)&&(posj.x+posj.w>=posobj.x)&&(posj.x<=posobj.x+posobj.w)) )
{
	x=1 ; 
}

else x=0 ; 
return x ;
}


