#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string.h>
#include "condition.h"

int main ()
{ 
    SDL_Surface *ecran =NULL;
    Player p; 

    int continuer=1;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetIcon(IMG_Load("logo.png"), NULL); 
    ecran = SDL_SetVideoMode(1366, 678,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("sous menu", NULL);
    	
while (continuer)
{condition(ecran);
}

SDL_FreeSurface(ecran);
SDL_Quit();
return 0;
}
