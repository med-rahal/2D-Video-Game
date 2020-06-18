/**
 * @file InitObjet.c
 * @brief Testing Program.
 * @author Barkia Mohamed
 * @version 0.1
 * @date June 15, 2020
 *
 * Testing program for collisionBB
 *
 */


/**
 * @file InitObjet.c
*/

#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "object.h"




/**
 * @brief To initialize object
 * @param obj the object 
 * @param name[] the name
 * @param x position in x
 * @param y position in y 
 * @return Nothing
*/

void initialiserObj( Objet *obj , char name[] , int x , int y ) 
{

	       obj->image =  IMG_Load(name); 
	      if  ( obj->image  ==  NULL )  { 
         printf ( "Can not load image of tux: %s \n " , SDL_GetError ()); 
         exit ( 1 ); 
     } 
     else 
     {
 
     obj->position.x  =  x ; 
     obj->position.y  =  y ; 
     obj->position.h  =  obj->image->h ;
obj->position.w = obj->image->w ;
}

}
