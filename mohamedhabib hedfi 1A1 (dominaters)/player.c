#include "player.h"
Player InitPlayer(Player Hero)
{

 
  Hero.vie.image=IMG_Load("coeur.png");
  Hero.score=0;
  Hero.vie.nbr=5;

  Hero.vie.position.x=20;
  Hero.vie.position.y=20;
  return Hero;
}
Player update(Player Hero,int i)
{

  Hero.vie.nbr=i;
  Hero.vie.position.x=20;
  Hero.vie.position.y=20;
  return Hero;
}


void gestion_vie(vie *v,int i)
{
  if(i==1)
 v->nbr--;

}
void  afficher_vie(vie v,SDL_Surface *screen)
{
  int i;
  SDL_Rect position;
  for(i=0;i<v.nbr;i++)
  {
    position.x=v.position.x+(v.image->w*i);
    position.y=20;
    SDL_BlitSurface(v.image,NULL,screen,&position);
  }
}
