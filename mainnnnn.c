#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string.h>
#include "char.h"
int main(){
SDL_Surface *screen;
 charac c;
charac cp;

screen = SDL_SetVideoMode(960,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

SDL_WM_SetCaption( "character", NULL);
int done = 0;
c = initChar();
while (done == 0){
 showChar(&cp, c , screen);
  SDL_Flip(screen);
}
SDL_FreeSurface(screen);
SDL_Quit();
return 0;
}
