#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "animation1.h"


int main()
{
SDL_Init(SDL_INIT_EVERYTHING);
SDL_Surface*screen;
charac c;
int continuer=1;
int frame=0;
SDL_Rect rects[4];

while(continuer)
{
animation1(c,frame,screen);
}					
SDL_Quit();
return 0;
}
