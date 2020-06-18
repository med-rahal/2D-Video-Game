/**
 * @file main.c
 * @brief Testing Program.
 * @author Barkia Mohamed
 * @version 0.1
 * @date June 15, 2020
 *
 * Testing program for partage ecran
 *
 */


#include"partage.h"
#include<stdio.h>
#include <stdlib.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include<time.h>


int main(int argc, char *argv[])
{

SDL_Surface*screen;
SDL_Rect positionecran;
SDL_Event event;
int run =1;
SDL_Init(SDL_INIT_EVERYTHING);
screen = SDL_SetVideoMode(900,522,32,SDL_HWSURFACE|SDL_RESIZABLE);
backgr bg, bg1;
perso p, p1;
SDL_EnableKeyRepeat(10,10);
p.posper.x=10;
p.posper.y=123;
p1.posper.x=460;
p1.posper.y=123;
while(run)
{
while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT)
					run = 0;
			if(event.type == SDL_KEYDOWN) {
				if(event.key.keysym.sym == SDLK_ESCAPE)
						run = 0;
				if(event.key.keysym.sym == SDLK_RIGHT) {
					p.posper.x += 5;
				}
				if(event.key.keysym.sym == SDLK_LEFT) {
					p.posper.x -= 5;
				}
				if(event.key.keysym.sym == SDLK_d) {
					p1.posper.x += 5;
				}
				if(event.key.keysym.sym == SDLK_s) {
					p1.posper.x -= 5;
				}
			}
		}

afficher_background(bg,screen);
afficher_background1(bg1,screen);
afficher_perso(p,screen);
afficher_perso1(p1,screen);
SDL_Flip(screen);
}
    SDL_Quit();

    return EXIT_SUCCESS;

}
