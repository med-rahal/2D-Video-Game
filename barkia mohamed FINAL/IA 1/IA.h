#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>


/**
 * @struct circle
 * @brief struct for circle
*/

typedef struct 
{
  int x ;
  int y ;
  float rayon ;

}Circle;



/**
 * @struct objet
 * @brief struct for object
*/



typedef struct 
{

  SDL_Surface *img ;     /*!< Surface. */
  SDL_Rect pos ;         /*!< Rectangle*/
  Circle c ;
  SDL_Rect pos_text ;    /*!< Rectangle*/
  
}Objet ;

void intialiser(Objet *perso ,Objet *zombie) ;
void setup (SDL_Surface *screen,Objet *objet1,Objet *objet2) ;
void calculer_centre_rayon (Objet *objet1,Objet *objet2) ;
float calculer_distance (Objet *objet1,Objet *objet2) ;
int verif_collision ( Objet *objet1,Objet *objet2,float D1 ) ;
void deplacement_objet(Objet *objet,int *running) ;
