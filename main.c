#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include<SDL/SDL_audio.h>
#include "perso.h"

void main()
{
int cont=1;
SDL_Surface *menu=NULL;
SDL_Surface *ecran=NULL;

perso p; SDL_Event event;
SDL_Event even;
SDL_Rect positionmenu;

menu=IMG_Load("background.png");

positionmenu.x=0;
positionmenu.y=0;

SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO);
ecran=SDL_SetVideoMode(1600,600, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if (ecran==NULL)
printf ("Erreur");



 init_perso(&p);
while (cont)
{


SDL_BlitSurface(menu,NULL,ecran,&positionmenu);




 affiche_perso(&p,ecran);
 deplacerclaviersouris(event,&p,ecran);

SDL_Flip (ecran);


}
SDL_Quit();
}
