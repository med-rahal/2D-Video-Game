#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string.h>
#include "condition.h"
Player update(Player p,int i)
{

  p.vie.nbr=i;
  p.vie.position.x=20;
  p.vie.position.y=20;
  return p;
}
void condition(SDL_Surface *ecran)
{ SDL_Surface *background = NULL,*gameover = NULL, *super = NULL;
  SDL_Rect positionbackground,positiongameover,positionsuper;
 Player p;
 int i;
 int continuer=1;
  
    background=IMG_Load("back.png");
    positionbackground.x = 500;
    positionbackground.y = 200;
    gameover=IMG_Load("gameover.png");
    positiongameover.x = 250;
    positiongameover.y = 100;
    super=IMG_Load("super.png");
    positionsuper.x=250;
    positionsuper.y=100;
while(continuer)
{  p=update(p,i);
   if(p.vie.nbr<=0)
   {SDL_BlitSurface(gameover, NULL, ecran, &positiongameover);
    SDL_BlitSurface(background, NULL, ecran, &positionbackground);
    SDL_Flip(ecran);
   }
   else if(p.score==300&&p.vie.nbr>0)
   {SDL_BlitSurface(super, NULL, ecran, &positionsuper);
     SDL_BlitSurface(background, NULL, ecran, &positionbackground);
    SDL_Flip(ecran);
   }
SDL_Event event;   
SDL_PollEvent(&event);
      	switch(event.type)
		{	
            case SDL_QUIT:
                continuer = 0;
            break;
                 }

}
    SDL_FreeSurface(background);
    SDL_FreeSurface(gameover);
    SDL_FreeSurface(super);

}
