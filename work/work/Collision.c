#include "collision.h"
#include <math.h>


int collision_Parfaite(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,int decalage,int d)
{

  SDL_Color col;
  if(d==0)//imin
  {
    col=GetPixel(calque,posperso.x+perso->w +decalage,posperso.y+(perso->h/2));
  }
else  if(d==1)//issarr
  {
    col=GetPixel(calque,posperso.x +decalage,posperso.y+(perso->h/2));
  }
else  if(d==2)//fog
  {
    col=GetPixel(calque,posperso.x+(perso->w/2)+decalage ,posperso.y);
  }
else  if(d==3)//lota
  {
    col=GetPixel(calque,posperso.x+(perso->w/2) +decalage,posperso.y+perso->h);
  }
 
if ((col.r==255)&&(col.b==255)&&(col.g==255))
{
  return 1;
}
else return 0;
}
