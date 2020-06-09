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
void init_perso2(perso2 *p2)
{



p2->image2=IMG_Load("G.png");
   if  ( p2->image2 ==  NULL )  {
        printf ( "Can not load image of tux: %s \n " , SDL_GetError ());
        exit ( 1 );
    }
p2->pos2.x=100;
p2->pos2.y=100;
p2->pos2.w= p2->image2->w;
p2->pos2.h= p2->image2->h;


p2->vi2 = 4;
p2->argent2=0;
}


void affiche_perso(perso *p,SDL_Surface *screen)
{  
SDL_SetColorKey(p->image,SDL_SRCCOLORKEY,SDL_MapRGB(p->image->format,255,255,255));
SDL_BlitSurface(p->image, NULL,screen, &p->pos);

}
void affiche_perso2(perso2 *p2,SDL_Surface *screen)
{  
SDL_SetColorKey(p2->image2,SDL_SRCCOLORKEY,SDL_MapRGB(p2->image2->format,255,255,255));
SDL_BlitSurface(p2->image2, NULL,screen, &p2->pos2);

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
}
}
}
void deplacerclaviersouris2(SDL_Event event2,perso2 *p2,SDL_Surface *screen)
{
while(SDL_PollEvent(&event2))
    {
     switch(event2.type)
     {
        case SDL_KEYDOWN:
          if((event2.key.keysym.sym == SDLK_j )|| (event2.key.keysym.sym ==SDLK_n))
          {
           p2->pos2.x -= 5;
            affiche_perso2(p2,screen);
         }
          if((event2.key.keysym.sym == SDLK_k)|| (event2.key.keysym.sym ==SDLK_b))
          {
            p2->pos2.x += 5;
            affiche_perso2(p2,screen);
         }
         if((event2.key.keysym.sym == SDLK_l)|| (event2.key.keysym.sym ==SDLK_a))
          {
           p2->pos2.x+=10;
           p2->pos2.y -= 20;
             affiche_perso2(p2,screen);
         }
          if((event2.key.keysym.sym == SDLK_m)|| (event2.key.keysym.sym ==SDLK_c))
          {
          p2->pos2.y += 5;
            //affichage d image
           affiche_perso2(p2,screen);
         }
        break;
        case SDL_MOUSEBUTTONUP:
          if(event2.button.button == SDL_BUTTON_LEFT )
          {
            p2->pos2.x -= 5;
            affiche_perso2(p2,screen);
          }
          if(event2.button.button == SDL_BUTTON_RIGHT)
          {
           p2->pos2.x += 5;
            affiche_perso2(p2,screen);
          }
          if(event2.button.button== SDL_BUTTON_WHEELUP)
          {
            p2->pos2.x+=10;
            p2->pos2.y -= 20;
             affiche_perso2(p2,screen);
          }
          if(event2.button.button == SDL_BUTTON_WHEELDOWN)
          {
            p2->pos2.y += 5;
            //affichage d image
          affiche_perso2(p2,screen);}

   

}
   
      }
    }
