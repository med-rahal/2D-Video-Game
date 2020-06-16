#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string.h>
#include "p2.h"
void save(SDL_Surface *ecran,int *sauv, charac p ,vie v,score s, temps t,ennemie en,BackGround back, enigme e)
{
	SDL_Surface  *yes=NULL, *no=NULL,*background=NULL;
	SDL_Rect positionbackground,positionyes,positionno;
FILE *f=NULL;
f=fopen("save.bin","rb+");
int cont=1,x=1,y=1;

    background=IMG_Load("sousmenu.png");
    positionbackground.x = 0;
    positionbackground.y = 0;

    yes=IMG_Load("yes.png");
    positionyes.x = 529;
    positionyes.y = 330;

    no=IMG_Load("no.png");
    positionno.x = 720;
    positionno.y = 330;
SDL_Event event;

while(cont==1)
{
SDL_WaitEvent(&event);
switch(event.type)
        {
case SDL_QUIT:
                cont = 0;
                break;
	
	case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                   
		   case SDLK_LEFT :
			if(x==1)
				{
					
                                        no=IMG_Load("no_gr.png");
					SDL_BlitSurface(no, NULL, ecran, &positionno);
					x=2;		
				}
			else if(x==2)
					{
		                         
					yes=IMG_Load("yes_gr.png");
					SDL_BlitSurface(yes, NULL, ecran, &positionyes);
					x=1;			
					}
			break;
			case SDLK_RIGHT :
			 if(y==1)
				{	
			                 
					yes=IMG_Load("yes_gr.png");
					SDL_BlitSurface(yes, NULL, ecran, &positionyes);
					y=2;	
				}
			else if(y==2)
					{
		                    
					no=IMG_Load("no_gr.png");
					SDL_BlitSurface(no, NULL, ecran, &positionno);
					y=1;			
					}
			break;
			case SDLK_RETURN :
					if(y==1)
					   {cont=0;}
					
					else if(y==2)
					{
							fwrite((&p),sizeof(charac),1,f);
                                                        fread((&p),sizeof(charac),1,f);
							fwrite((&s),sizeof(score),1,f);
		                                        fread((&s),sizeof(score),1,f);
							fwrite((&back),sizeof(BackGround),1,f);    
                                                        fread((&back),sizeof(BackGround),1,f);						
                                                        fwrite((&en),sizeof(ennemie),1,f);
                                                        fread((&en),sizeof(ennemie),1,f);
							fwrite((&t),sizeof(temps),1,f);
                                                        fread((&t),sizeof(temps),1,f);
	                                                fwrite((&v),sizeof(vie),1,f);
                                                        fread((&v),sizeof(vie),1,f);
							fwrite((&e),sizeof(enigme),1,f);
                                                        fread((&e),sizeof(enigme),1,f);

					 *sauv=0;
					
					}
                        break;
default : break;
                }
                break;
	case  SDL_MOUSEBUTTONDOWN :
     	
	if(event.button.button == SDL_BUTTON_LEFT )
           {
if((event.button.x>positionno.x)&&(event.button.x<positionno.x+positionno.w)&&(event.button.y>positionno.y)&&(event.button.y <positionno.y+positionno.h))
		{


							fwrite((&p),sizeof(charac),1,f);
                                                        fread((&p),sizeof(charac),1,f);
							fwrite((&s),sizeof(score),1,f);
		                                        fread((&s),sizeof(score),1,f);
							fwrite((&back),sizeof(BackGround),1,f);    
                                                        fread((&back),sizeof(BackGround),1,f);						
                                                        fwrite((&en),sizeof(ennemie),1,f);
                                                        fread((&en),sizeof(ennemie),1,f);
							fwrite((&t),sizeof(temps),1,f);
                                                        fread((&t),sizeof(temps),1,f);
	                                                fwrite((&v),sizeof(vie),1,f);
                                                        fread((&v),sizeof(vie),1,f);
							fwrite((&e),sizeof(enigme),1,f);
                                                        fread((&e),sizeof(enigme),1,f);
                                 *sauv=0;
		}
else if ((event.button.x > positionyes.x) && (event.button.x < positionyes.x + positionyes.w) && (event.button.y > positionyes.y) && (event.button.y < positionyes.y + positionyes.h))
	{cont=0;}
        
	}
break;default : break;
     }

        SDL_BlitSurface(background, NULL, ecran, &positionbackground);
        SDL_BlitSurface(yes, NULL, ecran, &positionyes);
        SDL_BlitSurface(no, NULL, ecran, &positionno);
SDL_Flip(ecran);
}
    SDL_FreeSurface(background);
    SDL_FreeSurface(yes);
    SDL_FreeSurface(no);

fclose(f);

}
