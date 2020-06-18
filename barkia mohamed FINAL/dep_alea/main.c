/**
 * @file main.c
 * @brief Testing Program.
 * @author Barkia Mohamed
 * @version 0.1
 * @date June 15, 2020
 *
 * Testing program for Dep alea
 *
 */



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include"game.h"

int  main()
{

SDL_Surface*screen;
SDL_Rect positionecran;
SDL_Event event;



enemy E;


    SDL_Init(SDL_INIT_VIDEO);
    

    screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Afficher Ennemie en Mvt Aleatoire", NULL);
 initialiser_enemy(&E);
   

deplacement_aleatoire(E,screen);

  SDL_FreeSurface(E.image_enemy);
    SDL_Quit();




}
