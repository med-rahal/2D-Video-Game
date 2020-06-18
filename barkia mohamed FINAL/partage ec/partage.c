/**
 * @file partage.c
 * @brief Testing Program.
 * @author Barkia Mohamed
 * @version 0.1
 * @date June 15, 2020
 *
 * Testing program for partage ecran
 *
 */




/**
 * @file partage.c
*/



#include "partage.h"

/**
 * @brief To show background 1
 * @param bg the background 1
 * @param screen the screen
 * @return Nothing
*/

void afficher_background(backgr bg,SDL_Surface*screen)
{
bg.pos.x=0;
bg.pos.y=0;
bg.image=IMG_Load("backg.jpg");
SDL_BlitSurface(bg.image,NULL,screen,&bg.pos);
}

/**
 * @brief To show background 2
 * @param bg1 the background 2
 * @param screen the screen
 * @return Nothing
*/

void afficher_background1(backgr bg1,SDL_Surface*screen)
{
bg1.pos.x=450;
bg1.pos.y=0;
bg1.image=IMG_Load("backg.jpg");
SDL_BlitSurface(bg1.image,NULL,screen,&bg1.pos);
}

/**
 * @brief To show player 1
 * @param p the player 1
 * @param screen the screen
 * @return Nothing
*/
void afficher_perso(perso p,SDL_Surface*screen)
{

p.image=IMG_Load("1.png");
SDL_BlitSurface(p.image,NULL,screen,&p.posper);

}


/**
 * @brief To show player 2
 * @param p1 the player 2
 * @param screen the screen
 * @return Nothing
*/
void afficher_perso1(perso p1,SDL_Surface*screen)
{
p1.image=IMG_Load("2.png");
SDL_BlitSurface(p1.image,NULL,screen,&p1.posper);

}

