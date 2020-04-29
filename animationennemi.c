#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include"animationennemi.h"
SDL_Event event;
void setrects(SDL_Rect* clip){
clip[0].x=0;
clip[0].y=0;
clip[0].w=90;
clip[0].h=300;

clip[1].x=228;
clip[1].y=0;
clip[1].w=90;
clip[1].h=300;

clip[2].x=228;
clip[2].y=0;
clip[2].w=80;
clip[2].h=300;

clip[3].x=342;
clip[3].y=0;
clip[3].w=80;
clip[3].h=300;

clip[4].x=456;
clip[4].y=0;
clip[4].w=90;
clip[4].h=300;

clip[5].x=570;
clip[5].y=0;
clip[5].w=90;
clip[5].h=300;

clip[6].x=684;
clip[6].y=0;
clip[6].w=90;
clip[6].h=300;

clip[7].x=798;
clip[7].y=0;
clip[7].w=90;
clip[7].h=300;



}


