/**
 * @file enemy.c
 * @brief Testing Program.
 * @author Barkia Mohamed
 * @version 0.1
 * @date June 15, 2020
 *
 * Testing program for init & aff enemy
 *
 */



#include"game.h"
#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include<time.h>


/**
 * @file enemy.c
*/

/**
 * @brief To initialize enemy
 * @param E the enemy
 * @return Nothing
*/






void initialiser_enemy(enemy *E)
{
  E->image_enemy =IMG_Load ("zombie.png");
  
    E->position_enemy.x = 0;
    E->position_enemy.y = 0;
}




/**
 * @brief To show enemy
 * @param E the enemy
 * @param screen the screen
 * @return EXIT_SUCCESS
*/



int afficher_enemy(enemy E,SDL_Surface*screen)
{
SDL_Event event;

    int continuer = 1;
    int tempsPrecedent = 0, tempsActuel = 0;
    
char temps[20];



  
    SDL_SetColorKey(E.image_enemy, SDL_SRCCOLORKEY, SDL_MapRGB(E.image_enemy->format, 0, 0, 255));
   


    E.position_enemy.x = screen->w / 2 - E.image_enemy->w / 2;
    E.position_enemy.y = 0;

    SDL_EnableKeyRepeat(10, 10);

   while (continuer)
    {
        SDL_PollEvent(&event); 
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }

        tempsActuel = SDL_GetTicks();

        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
        SDL_BlitSurface(E.image_enemy, NULL, screen, &E.position_enemy);
        SDL_Flip(screen);
    }

    SDL_FreeSurface(E.image_enemy);
    SDL_Quit();

   return EXIT_SUCCESS;

}
