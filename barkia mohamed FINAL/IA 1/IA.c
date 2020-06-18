/**
 * @file IA.c
 * @brief Testing Program.
 * @author Barkia Mohamed
 * @version 0.1
 * @date June 15, 2020
 *
 * Testing program for IA 1
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "IA.h"

/**
 * @file IA.c
*/


/**
 * @brief To initialize object
 * @param perso the player
 * @param zombie the enemy
 * @return Nothing
*/


void intialiser(Objet *perso ,Objet *zombie)
{
  perso->img=IMG_Load("1.png") ;
  perso->pos.x=50 ;
  perso->pos.y=50 ;

  zombie->img=IMG_Load("zombie.png") ;
  zombie->pos.x=600 ;
  zombie->pos.y=50 ;

}

/**
 * @brief To show screen
 * @param screen the screen
 * @param objet1 the object 1
 * @param objet2 the object 2
 * @return Nothing
*/


void setup (SDL_Surface *screen,Objet *objet1,Objet *objet2)
{
 SDL_WM_SetCaption("IA1", NULL);
 SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255)) ;
 SDL_BlitSurface(objet1->img,NULL,screen,&(objet1->pos)) ;
 SDL_BlitSurface(objet2->img,NULL,screen,&(objet2->pos)) ;
 SDL_Flip(screen) ;

}


/**
 * @brief To calculate r
 * @param objet1 the object 1
 * @param objet2 the object 2
 * @return Nothing
*/


void calculer_centre_rayon (Objet *objet1,Objet *objet2)
{

 objet1->c.x=objet1->pos.x+ (objet1->img->w)/2 ;
 objet1->c.y=objet1->pos.y+ (objet1->img->h)/2 ;
 objet1->c.rayon=sqrt( pow( (objet1->img->w)/2 , 2) + pow( (objet1->img->h)/2 , 2) ) ;

 objet2->c.x=objet2->pos.x+ (objet2->img->w)/2 ;
 objet2->c.y=objet2->pos.y+ (objet2->img->h)/2 ;
 objet2->c.rayon=sqrt( pow( (objet2->img->w)/2 , 2) + pow( (objet2->img->h)/2 , 2) ) ;

}


/**
 * @brief To calculate distance
 * @param objet1 the object 1
 * @param objet2 the object 2
 * @return D
*/



float calculer_distance (Objet *objet1,Objet *objet2) 
{
  float D ;

  D=sqrt( pow( (objet1->c.x) - (objet2->c.x) ,2 ) + pow ( (objet1->c.y) - (objet2->c.y) , 2  ) ) ;

  return D ;
}


/**
 * @brief To verify collision
 * @param objet1 the object 1
 * @param objet2 the object 2
 * @param D1 the distance 1
 * @return collision
*/



int verif_collision ( Objet *objet1,Objet *objet2,float D1 )
{
  float D2 ;
  int collision=0 ;

  D2=objet1->c.rayon + objet2->c.rayon ;

  if(abs(D2-D1)<50 )
    collision= 1 ;
  
  return collision ;
}





/**
 * @brief To move 
 * @param objet the object 
 * @param running the kl
 * @return Nothing
*/




void deplacement_objet(Objet *objet,int *running)
  {
    SDL_Event event ;


  
  SDL_PollEvent(&event);
      switch(event.type)
        {
          case SDL_QUIT:
                *running=0;
          break;
          case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                  case SDLK_DOWN:
                      objet->pos.y+=2;
                  break;
                  case SDLK_UP:
                      objet->pos.y-=2;
                  break;
                  case SDLK_RIGHT:
                      objet->pos.x+=4;
                  break;
                  case SDLK_LEFT:
                      objet->pos.x-=4;
                  break;
                }
        }
    }
