#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string.h>
#include "p2.h"

int main ()
{
    int cont=1;
    int sauv;
    enigme e;
    charac p;
    vie v;
    score s;
    temps t;
    ennemie en;
    BackGround back;
    SDL_Surface *ecran =NULL;
    SDL_Init(SDL_INIT_VIDEO); 
    ecran = SDL_SetVideoMode(1366, 678,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("sous menu", NULL);
    	
while (cont)
{
save(ecran,&sauv, p ,v, s,t,en,back, e);
}
SDL_FreeSurface(ecran);
SDL_Quit();
return EXIT_SUCCESS;
}
