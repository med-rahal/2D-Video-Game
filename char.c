#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string.h>
#include "char.h"
 
charac initChar (){
charac c;
  c.spriteleft = IMG_Load("perso_l.png");
	c.spriteright = IMG_Load("perso_r.png");
  return c;
}
void showChar(charac *cp, charac c, SDL_Surface * screen){
  SDL_Rect camera;
  camera.x = 0;
  camera.y = 0;
  camera.h = 61;
  camera.w = 61;
cp->position.x = 150;
cp->position.y = 200;
 SDL_BlitSurface(c.spriteleft, &camera, screen, &cp->position);
}




