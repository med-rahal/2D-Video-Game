#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "animation2.h"
void setrects2(SDL_Rect* clip){
clip[0].x=0;
clip[0].y=0;
clip[0].w=70;
clip[0].h=100;

clip[1].x=70;
clip[1].y=0;
clip[1].w=70;
clip[1].h=100;

clip[2].x=100;
clip[2].y=0;
clip[2].w=70;
clip[2].h=100;

clip[3].x=170;
clip[3].y=0;
clip[3].w=70;
clip[3].h=100;
}
charac initChar (){
charac c;
  c.spriteleft = IMG_Load("58.png");
  c.spriteright = IMG_Load("57.png");
  return c;
}

void animation2(charac c,int frame, SDL_Surface *screen)
{
 int continuer=1;
 SDL_Rect rects[4];
 c=initChar();
 screen=SDL_SetVideoMode(960,600,32,SDL_SWSURFACE);
 setrects2(rects);
 SDL_SetColorKey(c.spriteright, SDL_SRCCOLORKEY, SDL_MapRGB(c.spriteright->format, 0x00, 0xff, 0xff));
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
SDL_FillRect(screen,&c.position,0x00);
c.position.x=250;
c.position.y=150;
SDL_BlitSurface(c.spriteright,&rects[frame],screen,&c.position);
SDL_Flip(screen);
frame++;
if(frame==3){
frame=0;
}
}
SDL_FreeSurface(c.spriteright);
SDL_Quit();
}








