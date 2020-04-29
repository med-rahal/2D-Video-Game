#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include"personnage.h"
void setrects(SDL_Rect* clip){
clip[0].x=0;
clip[0].y=0;
clip[0].w=100;
clip[0].h=120;

clip[1].x=70;
clip[1].y=0;
clip[1].w=100;
clip[1].h=120;

clip[2].x=140;
clip[2].y=0;
clip[2].w=100;
clip[2].h=120;

clip[3].x=210;
clip[3].y=0;
clip[3].w=100;
clip[3].h=120;



clip[4].x=210;
clip[4].y=125;
clip[4].w=100;
clip[4].h=120;

clip[5].x=140;
clip[5].y=125;
clip[5].w=100;
clip[5].h=120;

clip[6].x=70;
clip[6].y=125;
clip[6].w=100;
clip[6].h=120;

clip[7].x=0;
clip[7].y=125;
clip[7].w=100;
clip[7].h=120;



} 

