#include "map.h"
#include "player.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>



int main (void)
{ int i;
SDL_Event event;
 SDL_Rect score;
  score.x=800;
  score.y=10;
  TTF_Init();
  TTF_Font *police = NULL;
  police = TTF_OpenFont("beela.ttf", 25);
  SDL_Color couleurNoire = {0, 0, 0};
  SDL_Surface *texte;
  

 SDL_Surface *ecran =NULL;
  SDL_Init(SDL_INIT_VIDEO);
char str[50];
  //Les BackGround
    BackGround bg;
    bg=InitBackGround(bg);
  
  
  ecran = SDL_SetVideoMode(1000,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
  int direction=0;
  int continuer=1;
  Player Joueur;
    Joueur=InitPlayer(Joueur);
i=Joueur.vie.nbr;

  while (continuer) {

    direction=3;
  Joueur.score++;
    SDL_PollEvent(&event);
        if(event.type==SDL_QUIT)
          continuer=0;
        else if(event.type==SDL_KEYDOWN)
        {
            if(event.key.keysym.sym==SDLK_RIGHT) direction=0;
            if(event.key.keysym.sym==SDLK_LEFT)  direction=1;
            if(event.key.keysym.sym==SDLK_UP)    {direction=2;}
            if(event.key.keysym.sym==SDLK_DOWN)  {direction=3;}
  SDL_Delay(15);
if(event.key.keysym.sym==SDLK_r){i--;} 

        } Joueur=update(Joueur,i); 


sprintf(str, "%d", Joueur.score);
texte = TTF_RenderText_Blended(police, str, couleurNoire);
       bg=ScorllingBackGround(bg,direction);
        
        AfficherBackGround(bg,ecran);
afficher_vie(Joueur.vie,ecran);
 SDL_BlitSurface(texte,NULL,ecran,&score);
        SDL_Delay(15);
     if(Joueur.vie.nbr==0)
          {continuer=0;}
        SDL_Flip(ecran);
      


 }
}
