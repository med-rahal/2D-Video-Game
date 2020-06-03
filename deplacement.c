#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include<SDL/SDL_audio.h>
#include "perso.h"


void init_perso(perso *p)
{



p->image=IMG_Load("ezraa.png");
   if  ( p->image ==  NULL )  {
        printf ( "Can not load image of tux: %s \n " , SDL_GetError ());
        exit ( 1 );
    }
p->pos.x=20;
p->pos.y=30;
p->pos.w= p->image->w;
p->pos.h= p->image->h;


p->vi = 4;
p->argent=0;

}
void affiche_perso(perso *p,SDL_Surface *screen)
{  
SDL_SetColorKey(p->image,SDL_SRCCOLORKEY,SDL_MapRGB(p->image->format,255,255,255));
SDL_BlitSurface(p->image, NULL,screen, &p->pos);

}

void deplacerclaviersouris(SDL_Event event,perso *p,SDL_Surface *screen)
{
while(SDL_PollEvent(&event))
    {
     switch(event.type)
     {
        case SDL_KEYDOWN:
          if((event.key.keysym.sym == SDLK_LEFT )|| (event.key.keysym.sym ==SDLK_q))
          {
           p->pos.x -= 5;
            affiche_perso(p,screen);
         }
          if((event.key.keysym.sym == SDLK_RIGHT)|| (event.key.keysym.sym ==SDLK_d))
          {
            p->pos.x += 5;
            affiche_perso(p,screen);
         }
         if((event.key.keysym.sym == SDLK_UP)|| (event.key.keysym.sym ==SDLK_z))
          {
           p->pos.x+=10;
           p->pos.y -= 20;
             affiche_perso(p,screen);
         }
          if((event.key.keysym.sym == SDLK_DOWN)|| (event.key.keysym.sym ==SDLK_s))
          {
          p->pos.y += 5;
            //affichage d image
           affiche_perso(p,screen);
         }
        break;
        case SDL_MOUSEBUTTONUP:
          if(event.button.button == SDL_BUTTON_LEFT )
          {
            p->pos.x -= 5;
            affiche_perso(p,screen);
          }
          if(event.button.button == SDL_BUTTON_RIGHT)
          {
           p->pos.x += 5;
            affiche_perso(p,screen);
          }
          if(event.button.button== SDL_BUTTON_WHEELUP)
          {
            p->pos.x+=10;
            p->pos.y -= 20;
             affiche_perso(p,screen);
          }
          if(event.button.button == SDL_BUTTON_WHEELDOWN)
          {
            p->pos.y += 5;
            //affichage d image
          affiche_perso(p,screen);
          }
        break;
        case SDL_QUIT:

        break;
      }
    }
}
