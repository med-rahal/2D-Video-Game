 /**
 * @file integration.c
 */
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string.h>
#include "perso.h"
#include "map.h"
#include "collision.h"
#include "enigmeElaa.h"
#include "Game.h"
#include "player.h"
#include "Char.h"
#include "animation1.h"
#include "animation2.h"
#include "animation.h"



int main (void)
{ int i;
int n=0;int fact,int r;
 int direction=0;
 int continuer=1;
int  collision;
int frame=0;
char str[50];
SDL_Event event;
SDL_Rect score;
SDL_Rect rects[4];
SDL_Rect persoPos;
characPos cp;
SDL_Rect pos;
 SDL_Rect positionecran;

SDL_Rect rect;


 score.x=800;
 score.y=10;
 TTF_Init();
 TTF_Font *police = NULL;
 police = TTF_OpenFont("beela.ttf", 25);
 SDL_Color couleurNoire = {0, 0, 0};
 SDL_Surface *texte;

 

SDL_Surface *ecran =NULL;
 SDL_Init(SDL_INIT_VIDEO);

 
    BackGround bg;
  Player Joueur;
charac c;
perso p;
Enemy E;
ennemi e;
   bg=InitBackGround(bg,"calque.png","calque.png");
 
 
 ecran = SDL_SetVideoMode(1000,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

bg=InitBackGround(bg,"calque.png","calque.png");
c = initChar();
init_affichier_question( n,&screen);
initialiser_enemy(&E);
i=Joueur.vie.nbr;

 while (continuer) {
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
       
 if(collision_Parfaite(bg.calque,Joueur.imageActuel,Joueur.position,bg.camera.x,direction)==0)
{
  bg=ScorllingBackGround(bg,direction);
 deplacerclaviersouris( event,&p,&screen);
animation1(c,frame,screen)
animation2(c,frame,screen);}             //pas de collision
 if (direction==0)
{

if  (collision_Parfaite(bg.calque,Joueur.imageActuel,Joueur.position,bg.camera.x,0)==1)
      {i--;}SDL_Delay(15); }            //le nombre de vie diminue



if (direction==1){
       
if  (collision_Parfaite(bg.calque,Joueur.imageActuel,Joueur.position,bg.camera.x,1)==1)
      {i--;}SDL_Delay(15); }



if (direction==2){
       
 if  (collision_Parfaite(bg.calque,Joueur.imageActuel,Joueur.position,bg.camera.x,2)==1)
      {i--;}SDL_Delay(15); }





if (direction==3){
         
if  (collision_Parfaite(bg.calque,Joueur.imageActuel,Joueur.position,bg.camera.x,3)==1)
      {i--;}SDL_Delay(15);
}

if(event.key.keysym.sym==SDLK_r){i--;}
 


sprintf(str, "%d", Joueur.score);
texte = TTF_RenderText_Blended(police, str, couleurNoire);
     
       
AfficherBackGround(bg,ecran);
afficher_vie(Joueur.vie,ecran);
showChar(&cp,c, ecran);
afficher_enemy(&E);
deplacement_aleatoire(E,screen);
animationennemie(e,frame,screen);




SDL_BlitSurface(texte,NULL,ecran,&score);

       SDL_Delay(15);
if(Joueur.vie.nbr==1)
{
n=generate_question(&n);
fact=resolution(n);
r=reponse(&r);
printf("%d %d",r,fact);
 afficher_resultat (& screen, solution, r);          
 if (r==solution)

{

i++;

}
}

Joueur=update(Joueur,i);
    if(Joueur.vie.nbr==0)
         {continuer=0;}
       SDL_Flip(ecran);
     


}
SDL_QUIT(0);
return 0;
}

