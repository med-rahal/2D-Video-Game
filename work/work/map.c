#include "map.h"
BackGround InitBackGround(BackGround map)
{
  map.image=IMG_Load("calque.png");
  map.position.x=0;
  map.position.y=0;
  map.camera.x=0;
  map.camera.y=10;
  map.camera.h=600;
  map.camera.w=1000;

  return map;
}
BackGround ScorllingBackGround(BackGround map,int direction)
{
  if(direction==0)
  {
    if(map.camera.x<6119)
    {
      map.camera.x+=20;
     
    }
  }
  else if(direction==1)
  {
    if(map.camera.x>0)
    {
      map.camera.x-=20;
  
    }

  }

  return map;
}
void AfficherBackGround(BackGround map,SDL_Surface *screen)
{
  SDL_BlitSurface(map.image,&map.camera,screen,&map.position);
}
