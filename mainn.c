#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "personnage.h"

int main(int argc,char** argv)
{
SDL_Init(SDL_INIT_EVERYTHING);
SDL_Surface*screen;
SDL_Surface*image;

screen=SDL_SetVideoMode(960,600,32,SDL_SWSURFACE);
int done=1;
SDL_Rect rect;
int frame=0;
image=IMG_Load("58.png");
SDL_Rect rects[8];
setrects(rects);
SDL_SetColorKey(image, SDL_SRCCOLORKEY, SDL_MapRGB(screen->format, 0x00, 0xff, 0xff));
while(done)
{

                SDL_Event event;
                while(SDL_PollEvent(&event)) {
                        switch(event.type) {
                                case SDL_QUIT:
                                        done = 0;
                                        break;
						}
					}
SDL_FillRect(screen,&screen->clip_rect,0x00);
SDL_FillRect(screen,&rect,0x00);
SDL_Rect rect;
rect.x=150;
rect.y=250;
SDL_BlitSurface(image,&rects[frame],screen,&rect);
SDL_Flip(screen);
frame++;
if(frame==7){
frame=0;
}
}
SDL_FreeSurface(image);
SDL_Quit();

return 0;
}
