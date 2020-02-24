/**
* @file main.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Mai 05, 2019
*
* Testing program for background scrollilng
*
*/

#include "menu.h"


int main (void)
{
    int continuee=1,i;
    SDL_Surface *ecran =NULL;
    Mix_Music *musique;
    Mix_Chunk *son;
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(1366, 678,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Jeux video", NULL);
    

if (ecran==NULL)
{
printf("error: %s ",SDL_GetError());
exit(EXIT_FAILURE);
}
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
  {printf("%s",Mix_GetError()); }
          	
	   musique=Mix_LoadMUS("music2.mp3");
           Mix_PlayMusic(musique,-1);

	
while (continuee)
{
menu(ecran,musique,&i);
}

Mix_FreeMusic(musique);
Mix_CloseAudio();
SDL_FreeSurface(ecran);
SDL_Quit();
return EXIT_SUCCESS;
}




