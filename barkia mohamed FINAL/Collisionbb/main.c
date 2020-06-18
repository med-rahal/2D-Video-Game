/**
 * @file main.c
 * @brief Testing Program.
 * @author Barkia Mohamed
 * @version 0.1
 * @date June 15, 2020
 *
 * Testing program for collisionBB
 *
 */





#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "object.h"
#include "object.h"

int main()
{
SDL_Surface *screen ;
SDL_Surface *image;
SDL_Rect posimage; 
Objet obj, obj1 ; 
SDL_Event event ; 
int done=0 , x ; 


 if  ( SDL_Init ( SDL_INIT_VIDEO )  == -1 )  { 
         printf ( "Can not init SDL \n " ); 
 
     } 

     screen  =  SDL_SetVideoMode ( 1280 ,  720 ,  32 ,  SDL_HWSURFACE  |  SDL_DOUBLEBUF ); 
     if  ( screen  ==  NULL )  { 
         printf ( "Can not set video mode: \n "); 
         
     } 
     SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  255 , 255)); 

    initialiserObj( &obj ,"1.png" ,  0 ,  0 ) ; 
    affichageObj (obj ,screen) ;
    initialiserObj( &obj1 ,"zombie.png" ,  500 ,  200 ) ; 
    affichageObj (obj1 ,screen) ;
   SDL_EnableKeyRepeat(10,10) ; 
    while  ( done==0 )  { 
         while  (SDL_PollEvent ( &event ))  { 
             switch  ( event.type )  { 
             case  SDL_QUIT : 
                 done  =  1 ; 
                 break ;  
    case SDL_KEYDOWN:

        switch(event.key.keysym.sym)

        {
      case SDLK_ESCAPE : 
done=1 ; 

case SDLK_LEFT : 

obj.position.x-=10 ; 
SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  255 , 255));
affichageObj (obj ,screen) ;
affichageObj (obj1 ,screen) ;

break ; 

case SDLK_RIGHT : 

obj.position.x+=10 ; 
SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  255 , 255));
affichageObj (obj ,screen) ;
affichageObj (obj1 ,screen) ;
break ; 
case SDLK_UP : 

obj.position.y-=10 ; 
SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  255 , 255));
affichageObj (obj ,screen) ;
affichageObj (obj1 ,screen) ;
break ; 
case SDLK_DOWN : 

obj.position.y+=10 ; 
SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  255 , 255));
affichageObj (obj ,screen) ;
affichageObj (obj1 ,screen) ;
break ; 


                 
			 }
posimage.x=5;
posimage.y=6;

x=collisionbb(obj.position,obj1.position);

if(x==1) 
{
image=IMG_Load ("collision.png");
SDL_BlitSurface(image, NULL, screen, &(posimage));
}

break ; 

		 }
	 }

SDL_Flip(screen) ; 
}
SDL_FreeSurface(image); 
SDL_FreeSurface(obj.image); 
SDL_FreeSurface(obj1.image); 
SDL_Quit();
return 0 ; 
}
