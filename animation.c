#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "animation.h"
void setrects(SDL_Rect* clip){
clip[0].x=0;
clip[0].y=0;
clip[0].w=80;
clip[0].h=150;

clip[1].x=80;
clip[1].y=0;
clip[1].w=80;
clip[1].h=200;

clip[2].x=160;
clip[2].y=0;
clip[2].w=100;
clip[2].h=200;

clip[3].x=240;
clip[3].y=0;
clip[3].w=100;
clip[3].h=200;
}
ennemi initennemi (){
ennemi e;
  e.sprite = IMG_Load("10.png");
  return e;
}

void animationennemie(ennemi e ,int frame, SDL_Surface *screen)
{
 int continuer=1;
 SDL_Rect rects[4];
 e=initennemi();
 screen=SDL_SetVideoMode(960,600,32,SDL_SWSURFACE);
 setrects(rects);
 SDL_SetColorKey(e.sprite, SDL_SRCCOLORKEY, SDL_MapRGB(e.sprite->format, 0x00, 0xff, 0xff));
while(continuer)
{

                SDL_Event event;
                while(SDL_PollEvent(&event)) {
                        switch(event.type) {
                                case SDL_QUIT:
                                        continuer = 0;
                                        break;
						}
					}
SDL_FillRect(screen,&screen->clip_rect,0x00);
SDL_FillRect(screen,&e.position,0x00);
e.position.x=250;
e.position.y=150;
SDL_BlitSurface(e.sprite,&rects[frame],screen,&e.position);
SDL_Flip(screen);
frame++;
if(frame==3){
frame=0;
}
}
SDL_FreeSurface(e.sprite);
SDL_Quit();
}
