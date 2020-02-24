#include"menu.h"
void menu(SDL_Surface *ecran, Mix_Music *musique,int *i)
{  
    SDL_Surface *background = NULL,*playy=NULL,*settingg=NULL,*quit,*play2=NULL,*play3=NULL,*play4=NULL,*g=NULL,*u=NULL;
    SDL_Rect positionbackground,positionplay,positionsetting,positionquit,positionplay2,positionplay3,positionplay4,positiong,positionu;
    SDL_Event event;
    int previous_volume;
    Mix_Volume(1, MIX_MAX_VOLUME/2);
    Mix_Chunk *son;
    son = Mix_LoadWAV("Button.wav");
    previous_volume=Mix_VolumeChunk(son, MIX_MAX_VOLUME/2);
    int continuer = 1,x=1,y=1;
  //Inistialisation
    background = IMG_Load("backgroundmenu.png");
    positionbackground.x = 0;
    positionbackground.y = 0;
   

    playy=IMG_Load("boutton_play.png");
    positionplay.x=349;
    positionplay.y=315;

    settingg=IMG_Load("boutton_setting.png");
    positionsetting.x=770;
    positionsetting.y=315;

    quit=IMG_Load("boutton_exit.png");
    positionquit.x=570;
    positionquit.y=465;

    positionplay2.x=349;
    positionplay2.y=315;

    positionplay3.x=770;
    positionplay3.y=315;

    positionplay4.x=570;
    positionplay4.y=470;
g=IMG_Load("G.png");
positiong.x=-100;
    positiong.y=-100;

u=IMG_Load("u.png");
positionu.x=0;
    positionu.y=550;

while (continuer)
{ 

SDL_PollEvent(&event);
        switch(event.type)
        {
case SDL_QUIT:
continuer = 0;
break;
           
case SDL_KEYDOWN:
switch(event.key.keysym.sym)
                {
case SDLK_ESCAPE:
continuer = 0;
break;

case SDLK_DOWN :
			if(x==1)
			{
			playy=IMG_Load("boutton_play.png");
			quit=IMG_Load("exit_gr.png");
			SDL_BlitSurface(quit, NULL, ecran, &positionquit);
			Mix_PlayChannel(1, son, 0);
			x=2;y=1;
			}

			else if(x==2)
			{
			quit=IMG_Load("boutton_exit.png");
			settingg=IMG_Load("setting_gr.png");
			SDL_BlitSurface(settingg, NULL, ecran, &positionsetting);
			Mix_PlayChannel(1, son, 0);						
			x=3;y=3;		
			}

			else if(x==3)
			{
			settingg=IMG_Load("boutton_setting.png");
			playy=IMG_Load("play_gr.png");
			Mix_PlayChannel(1, son, 0);					
			SDL_BlitSurface(playy, NULL, ecran, &positionplay);
			x=1;y=2;			
			}
		break;
		case SDLK_UP :
			if(y==1)
			{
			quit=IMG_Load("boutton_exit.png");
			playy=IMG_Load("play_gr.png");
			SDL_BlitSurface(playy, NULL, ecran, &positionplay);
			Mix_PlayChannel(1, son, 0);					
			y=2;x=1;
			}
			
			else if(y==2)
			{	
			playy=IMG_Load("boutton_play.png");
			settingg=IMG_Load("setting_gr.png");
			SDL_BlitSurface(settingg, NULL, ecran, &positionsetting);
			Mix_PlayChannel(1, son, 0);						
			y=3;x=3;		
			}

			else if(y==3)
			{
			settingg=IMG_Load("boutton_setting.png");
			quit=IMG_Load("exit_gr.png");
			SDL_BlitSurface(quit, NULL, ecran, &positionquit);
			Mix_PlayChannel(1, son, 0);					
			y=1;x=2;			
			}
		break;
case SDLK_RETURN :
if(y==1)
{continuer=0;}

else if(y==2)
{play(ecran,son,musique,i);}

else if (y==3)
{setting(ecran,son,musique,i);}
break;

}
                break;
case SDL_MOUSEBUTTONDOWN:
if (event.button.button == SDL_BUTTON_LEFT)
        {
                             if ((event.button.x >positionplay.x) && (event.button.x < positionplay.x +positionplay.w) && (event.button.y >positionplay.y) && (event.button.y <positionplay.x+positionplay.h))
                            {play(ecran,son,musique,i);}

else if ((event.button.x >positionsetting.x) && (event.button.x < positionsetting.x +positionsetting.w) && (event.button.y >positionsetting.y) && (event.button.y <positionsetting.x+positionsetting.h))
                            {setting(ecran,son,musique,i);}

                else if ((event.button.x >positionquit.x) && (event.button.x < positionquit.x +positionquit.w) && (event.button.y >positionquit.y) && (event.button.y <positionquit.x+positionquit.h))
                                {continuer=0; }

        }
              
 
         
                
case SDL_MOUSEMOTION:
if((event.button.x>positionplay.x)&&(event.button.x<positionplay.x+positionplay.w)&&(event.button.y>positionplay.y)&&(event.button.y<positionplay.x+positionplay.h))
    			{        
			play2=IMG_Load("NewGame_T.png");
                        }
                      else
                       {
                         play2=NULL;
                         SDL_Flip(ecran);
                       }



                  


if((event.button.x>positionsetting.x)&&(event.button.x<positionsetting.x+positionsetting.w)&&(event.button.y>positionsetting.y)&&(event.button.y<positionsetting.x+positionsetting.h))
    {        
play3=IMG_Load("setting2.png");
                        }
                      else
                       {
                         play3=NULL;
                         SDL_Flip(ecran);
                       }


if((event.button.x>positionquit.x)&&(event.button.x<positionquit.x+positionquit.w)&&(event.button.y>positionquit.y)&&(event.button.y<positionquit.x+positionquit.h))
    {        
play4=IMG_Load("quit2.png");
                        }
                      else
                       {
                         play4=NULL;
                         SDL_Flip(ecran);
                       }

break;

}
SDL_BlitSurface(background, NULL, ecran, &positionbackground);
SDL_BlitSurface(g, NULL, ecran, &positiong);
SDL_BlitSurface(u, NULL, ecran, &positionu);
SDL_BlitSurface(playy, NULL, ecran, &positionplay);
SDL_BlitSurface(settingg, NULL, ecran, &positionsetting);
SDL_BlitSurface(quit, NULL, ecran, &positionquit);
SDL_BlitSurface(play2,NULL,ecran,&positionplay2);
SDL_BlitSurface(play3,NULL,ecran,&positionplay3);
SDL_BlitSurface(play4,NULL,ecran,&positionplay4);
        SDL_Flip(ecran);positiong.x++; if (positiong.x>1000)positiong.x=0;positionu.x++; if (positionu.x>1000)positionu.x=0;
}
    
SDL_FreeSurface(background);
   SDL_FreeSurface(g);
SDL_FreeSurface(u);   
SDL_FreeSurface(playy);
    SDL_FreeSurface(settingg);
    SDL_FreeSurface(quit);
        SDL_FreeSurface(play2);
SDL_FreeSurface(play3);
SDL_FreeSurface(play4);
    SDL_Quit();
}


 
void play(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique,int *i)
{
    SDL_Surface *background=NULL,*newgame = NULL, *continuer = NULL,*back=NULL;
    SDL_Rect positionbackground,positionback,positioncontinuer,positionnewgame;
    SDL_Event event;
    int continuee = 1,x=1,y=1,l,j;

background=IMG_Load("background.png");
    positionbackground.x = 0;
    positionbackground.y = 0;

    newgame=IMG_Load("newgame_boutton.png");
    positionnewgame.x = 340;
    positionnewgame.y = 310;

    continuer=IMG_Load("Continue_boutton.png");
    positioncontinuer.x = 750;
    positioncontinuer.y = 310;

    back=IMG_Load("Back_boutton.png");
    positionback.x = 20;
    positionback.y = 25;

while(continuee)
{
SDL_WaitEvent(&event);
        switch(event.type)
        {
case SDL_QUIT:
continuee = 0;
break;
case SDL_KEYDOWN:
switch(event.key.keysym.sym)
                {
case SDLK_ESCAPE:
menu(ecran,musique,i);
                break;
case SDLK_DOWN :
if(x==1)
{
back=IMG_Load("Back_boutton.png");
continuer=IMG_Load("continuer_gr.png");
SDL_BlitSurface(continuer, NULL, ecran, &positioncontinuer);
Mix_PlayChannel(1, son, 0);
x=2;y=1;
}

else if(x==2)
{
continuer=IMG_Load("Continue_boutton.png");
newgame=IMG_Load("Newgame_gr.png");
SDL_BlitSurface(newgame, NULL, ecran, &positionnewgame);
Mix_PlayChannel(1, son, 0);
x=3;y=3;
}

else if(x==3)
{
newgame=IMG_Load("newgame_boutton.png");
back=IMG_Load("back_gr.png");
SDL_BlitSurface(back, NULL, ecran, &positionback);
Mix_PlayChannel(1, son, 0);
x=1;y=2;
}

break;
case SDLK_UP:
if(y==1)
{
continuer=IMG_Load("Continue_boutton.png");
back=IMG_Load("back_gr.png");
SDL_BlitSurface(back, NULL, ecran, &positionback);
Mix_PlayChannel(1, son, 0);
y=2;x=1;
}

else  if(y==2)
{
back=IMG_Load("Back_boutton.png");
newgame=IMG_Load("Newgame_gr.png");
SDL_BlitSurface(newgame, NULL, ecran, &positionnewgame);
Mix_PlayChannel(1, son, 0);
y=3;x=3;
}

else if(y==3)
{
newgame=IMG_Load("newgame_boutton.png");
continuer=IMG_Load("continuer_gr.png");
SDL_BlitSurface(continuer, NULL, ecran, &positioncontinuer);
Mix_PlayChannel(1, son, 0);
y=1;x=2;
}
break;
case SDLK_RETURN :
if(y==1)
{menu(ecran,musique,i);}
else if(y==2)
{l=0;}


break;


}
break;
                case SDL_MOUSEBUTTONDOWN:
if (event.button.button == SDL_BUTTON_LEFT)
        {
if ((event.button.x >positionnewgame.x) && (event.button.x < positionnewgame.x +positionnewgame.w) && (event.button.y >positionnewgame.y) && (event.button.y <positionnewgame.x+positionnewgame.h))
                     { }

else if ((event.button.x >positionback.x) && (event.button.x < positionback.x +positionback.w) && (event.button.y >positionback.y) && (event.button.y <positionback.x+positionback.h))
                                {menu(ecran,musique,i);}

}
break;

        }

SDL_BlitSurface(background, NULL, ecran, &positionbackground);
        SDL_BlitSurface(newgame, NULL, ecran, &positionnewgame);
        SDL_BlitSurface(continuer, NULL, ecran, &positioncontinuer);
        SDL_BlitSurface(back, NULL, ecran, &positionback);
SDL_Flip(ecran);
    }
SDL_FreeSurface(background);
    SDL_FreeSurface(newgame);
    SDL_FreeSurface(continuer);
    SDL_FreeSurface(back);
SDL_Quit();
}





void setting(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique,int *i)
{
    SDL_Surface *background=NULL,*resoluton = NULL, *control = NULL, *sound = NULL,*back=NULL;
    SDL_Rect positionresoluton,positioncontrols,positionsound,positionbackground,positionback;
    SDL_Event event;
    int continuer = 1,x=1,y=1;

    background=IMG_Load("background.png");
    positionbackground.x = 0;
    positionbackground.y = 0;

    resoluton=IMG_Load("Resolution_boutton.png");
    positionresoluton.x = 100;
    positionresoluton.y = 310;

    sound=IMG_Load("sound_boutton.png");
    positionsound.x = 958;
    positionsound.y = 310;

    control=IMG_Load("Contols_boutton.png");
    positioncontrols.x = 530;
    positioncontrols.y = 310;

back=IMG_Load("Back_boutton.png");
    positionback.x = 20;
    positionback.y = 25;

while (continuer)
{
SDL_WaitEvent(&event);
        switch(event.type)
        {
case SDL_QUIT:
                continuer = 0;
break;
case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
case SDLK_DOWN :
if(x==1)
{
back=IMG_Load("Back_boutton.png");
sound=IMG_Load("sound_gr.png");
SDL_BlitSurface(sound, NULL, ecran, &positionsound);
Mix_PlayChannel(1, son, 0);
x=2;y=1;
}

  else  if(x==2)
{
sound=IMG_Load("sound_boutton.png");
control=IMG_Load("controls_gr.png");
SDL_BlitSurface(control, NULL, ecran, &positioncontrols);
Mix_PlayChannel(1, son, 0);
x=3;y=4;
}

else if(x==3)
{
control=IMG_Load("Contols_boutton.png");
resoluton=IMG_Load("Resolution_gr.png");
SDL_BlitSurface(resoluton, NULL, ecran, &positionresoluton);
Mix_PlayChannel(1, son, 0);
x=4;y=3;
}
else if(x==4)
{
resoluton=IMG_Load("Resolution_boutton.png");
back=IMG_Load("back_gr.png");
SDL_BlitSurface(back, NULL, ecran, &positionback);
Mix_PlayChannel(1, son, 0);
x=1;y=2;
}
break;
case SDLK_UP :
if(y==1)
{
sound=IMG_Load("sound_boutton.png");
back=IMG_Load("back_gr.png");
SDL_BlitSurface(back, NULL, ecran, &positionback);
Mix_PlayChannel(1, son, 0);
y=2;x=1;
}

else  if(y==2)
{
back=IMG_Load("Back_boutton.png");
resoluton=IMG_Load("Resolution_gr.png");
SDL_BlitSurface(resoluton, NULL, ecran, &positionresoluton);
Mix_PlayChannel(1, son, 0);
y=3;x=4;
}

else if(y==3)
{
resoluton=IMG_Load("Resolution_boutton.png");
control=IMG_Load("controls_gr.png");
SDL_BlitSurface(control, NULL, ecran, &positioncontrols);
Mix_PlayChannel(1, son, 0);
y=4;x=3;
}

else if(y==4)
{
control=IMG_Load("Contols_boutton.png");
sound=IMG_Load("sound_gr.png");
SDL_BlitSurface(sound, NULL, ecran, &positionsound);
Mix_PlayChannel(1, son, 0);
y=1;x=2;
}
break;
case SDLK_RETURN :
if(y==1)
{sounds(ecran,son,musique,i);}
else if(y==2)
{menu(ecran,musique,i);}
else if (y==3)
{resolution(ecran,son,musique,i);}
else if (y==4)
{controls(ecran,son,musique,i);}
break;
case SDLK_ESCAPE:
menu(ecran,musique,i);
        break;

}

break;
        case SDL_MOUSEBUTTONDOWN:
if (event.button.button == SDL_BUTTON_LEFT)
        {
if ((event.button.x >positionresoluton.x) && (event.button.x < positionresoluton.x +positionresoluton.w) && (event.button.y >positionresoluton.y) && (event.button.y <positionresoluton.x+positionresoluton.h))
                            {resolution(ecran,son,musique,i);}

else if ((event.button.x >positioncontrols.x) && (event.button.x < positioncontrols.x +positioncontrols.w) && (event.button.y >positioncontrols.y) && (event.button.y <positioncontrols.x+positioncontrols.h))
                            {controls(ecran,son,musique,i);}

else if ((event.button.x >positionsound.x) && (event.button.x < positionsound.x +positionsound.w) && (event.button.y >positionsound.y) && (event.button.y <positionsound.x+positionsound.h))
                            {sounds(ecran,son,musique,i);}

else if ((event.button.x >positionback.x) && (event.button.x < positionback.x +positionback.w) && (event.button.y >positionback.y) && (event.button.y <positionback.x+positionback.h))
                                {menu(ecran,musique,i);}

}    
break;  
}
SDL_BlitSurface(background, NULL, ecran, &positionbackground);
        SDL_BlitSurface(resoluton, NULL, ecran, &positionresoluton);
        SDL_BlitSurface(control, NULL, ecran, &positioncontrols);
        SDL_BlitSurface(sound, NULL, ecran, &positionsound);
        SDL_BlitSurface(back, NULL, ecran, &positionback);
SDL_Flip(ecran);
}

    SDL_FreeSurface(background);
    SDL_FreeSurface(resoluton);
    SDL_FreeSurface(control);
SDL_FreeSurface(sound);
SDL_FreeSurface(back);
SDL_Quit();
}


void resolution(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique,int *i)
{
    SDL_Surface *background=NULL,*resoluton_1 = NULL, *resoluton_2 = NULL, *resoluton_3 = NULL,*back=NULL;
    SDL_Rect positionresoluton_1,positionresoluton_2,positionresoluton_3,positionbackground,positionback;
    SDL_Event event;
    int continuer = 1,y=1,x=1;

background=IMG_Load("background.png");
positionbackground.x = 0;
positionbackground.y = 0;

resoluton_2=IMG_Load("full.png");
positionresoluton_2.x = 750;
positionresoluton_2.y = 310;

resoluton_3=IMG_Load("1366x768.png");
positionresoluton_3.x = 350;
positionresoluton_3.y = 310;

back=IMG_Load("Back_boutton.png");
positionback.x = 20;
positionback.y = 25;

while (continuer)
{
SDL_WaitEvent(&event);
        switch(event.type)
        {
case SDL_QUIT:
continuer = 0;
        break;
        case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
case SDLK_DOWN :
if(x==1)
{
back=IMG_Load("Back_boutton.png");
resoluton_2=IMG_Load("fullgr.png");
SDL_BlitSurface(resoluton_2, NULL, ecran, &positionresoluton_2);
Mix_PlayChannel(1, son, 0);
x=2;y=1;

}

else  if(x==2)
{
resoluton_2=IMG_Load("full.png");
resoluton_3=IMG_Load("1366x768_gr.png");
SDL_BlitSurface(resoluton_3, NULL, ecran, &positionresoluton_3);
Mix_PlayChannel(1, son, 0);
x=3;y=4;
}
 
else if(x==3)
{
resoluton_3=IMG_Load("1366x768.png");
resoluton_1=IMG_Load("800x600_gr.png");

Mix_PlayChannel(1, son, 0);
x=4;y=3;
}
 
else if(x==4)
{

back=IMG_Load("back_gr.png");
SDL_BlitSurface(back, NULL, ecran, &positionback);
Mix_PlayChannel(1, son, 0);
x=1;y=2;
}
break;
case SDLK_UP :
if(y==1)
{
resoluton_2=IMG_Load("full.png");
back=IMG_Load("back_gr.png");
SDL_BlitSurface(back, NULL, ecran, &positionback);
Mix_PlayChannel(1, son, 0);
y=2;x=1;
}

else  if(y==2)
{
back=IMG_Load("Back_boutton.png");
resoluton_1=IMG_Load("800x600_gr.png");

Mix_PlayChannel(1, son, 0);
y=3;x=4;
}

else if(y==3)
{
resoluton_1=IMG_Load("800x600.png");
resoluton_3=IMG_Load("1366x768_gr.png");
SDL_BlitSurface(resoluton_3, NULL, ecran, &positionresoluton_3);
Mix_PlayChannel(1, son, 0);
y=4;x=3;
}

else if(y==4)
{
resoluton_3=IMG_Load("1366x768.png");
resoluton_2=IMG_Load("fullgr.png");
SDL_BlitSurface(resoluton_2, NULL, ecran, &positionresoluton_2);
Mix_PlayChannel(1, son, 0);
y=1;x=2;
}
break;
case SDLK_RETURN :
if(y==1)
{ecran = SDL_SetVideoMode(1366, 678,32, SDL_HWSURFACE |SDL_FULLSCREEN);}
else if(y==2)
{setting(ecran,son,musique,i);}
else if (y==3)
{SDL_FULLSCREEN;}
else if (y==4)
{ecran = SDL_SetVideoMode(1366, 678,32, SDL_HWSURFACE | SDL_DOUBLEBUF);}
break;
case SDLK_ESCAPE:
                        setting(ecran,son,musique,i);
                break;

}
                break;
                case SDL_MOUSEBUTTONDOWN:

                         if (event.button.button == SDL_BUTTON_LEFT)
        {

if ((event.button.x >positionresoluton_2.x) && (event.button.x < positionresoluton_2.x +positionresoluton_2.w) && (event.button.y >positionresoluton_2.y) && (event.button.y <positionresoluton_2.x+positionresoluton_2.h))
                            {ecran = SDL_SetVideoMode(1366, 678,32, SDL_HWSURFACE | SDL_DOUBLEBUF);}

else if ((event.button.x >positionresoluton_3.x) && (event.button.x < positionresoluton_3.x +positionresoluton_3.w) && (event.button.y >positionresoluton_3.y) && (event.button.y <positionresoluton_3.x+positionresoluton_3.h))
                            {ecran = SDL_SetVideoMode(1366, 678,32, SDL_HWSURFACE | SDL_DOUBLEBUF);}

else if ((event.button.x >positionback.x) && (event.button.x < positionback.x +positionback.w) && (event.button.y >positionback.y) && (event.button.y <positionback.x+positionback.h))
                                {setting(ecran,son,musique,i);}

        }    
break;  

}

        SDL_BlitSurface(background, NULL, ecran, &positionbackground);
        
        SDL_BlitSurface(resoluton_2, NULL, ecran, &positionresoluton_2);
        SDL_BlitSurface(resoluton_3, NULL, ecran, &positionresoluton_3);
        SDL_BlitSurface(back, NULL, ecran, &positionback);
        SDL_Flip(ecran);
}

SDL_FreeSurface(background);

SDL_FreeSurface(resoluton_2);
SDL_FreeSurface(resoluton_3);
SDL_FreeSurface(back);
SDL_Quit();
}


void controls(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique, int *i)
{
TTF_Init();
TTF_Font *police=NULL ;
    SDL_Surface *background=NULL,*back=NULL,*helpp=NULL;
    SDL_Rect positionbackground,positionback,positionhelpp ;
    SDL_Event event;
    int continuer = 1,y=1,x=1;
  back=IMG_Load("Back_boutton.png");
    positionback.x = 20;
    positionback.y = 25;
background=IMG_Load("background.png");
positionbackground.x = 0;
positionbackground.y = 0;
police=TTF_OpenFont("SIXTY.TTF",80);
SDL_Color noir={0,0,0};
helpp=TTF_RenderText_Blended(police,"this game was made by dominators",noir);
positionhelpp.x=300; positionhelpp.y=200;

while (continuer)
{
SDL_WaitEvent(&event);
        switch(event.type)
        {
case SDL_QUIT:
        continuer = 0;
        break;

case SDLK_RETURN :

 if(y==1)
{setting(ecran,son,musique,i);}

break;
        case SDLK_ESCAPE:
        setting(ecran,son,musique,i);
        break;

case SDL_MOUSEBUTTONDOWN:

 if ((event.button.x >positionback.x) && (event.button.x < positionback.x +positionback.w) && (event.button.y >positionback.y) && (event.button.y <positionback.x+positionback.h))
                                {setting(ecran,son,musique,i);}

  
break;  
}

        SDL_BlitSurface(background, NULL, ecran, &positionbackground);
SDL_BlitSurface(helpp,NULL,ecran,&positionhelpp);
        SDL_BlitSurface(back, NULL, ecran, &positionback);
SDL_Flip(ecran);
}

    SDL_FreeSurface(background);
  
    SDL_FreeSurface(back);

SDL_Quit();
}


void sounds(SDL_Surface* ecran,Mix_Chunk *son,Mix_Music *musique,int *i)
{
    SDL_Surface *background=NULL,*augmenter = NULL, *diminuer = NULL,*back=NULL,*couper=NULL;
    SDL_Rect positionaugmenter,positiondiminuer,positionbackground,positioncouper,positionback;
    SDL_Event event;
    int continuer = 1,x=1,y=1,a=0;
    int previous_volume;

    background=IMG_Load("background.png");
    positionbackground.x = 0;
    positionbackground.y = 0;

    augmenter=IMG_Load("augmenter_volume.png");
    positionaugmenter.x = 450;
    positionaugmenter.y = 310;

    diminuer=IMG_Load("diminuer_volume.png");
    positiondiminuer.x = 750;
    positiondiminuer.y = 310;

    couper=IMG_Load("couper_son.png");
    positioncouper.x = 590;
    positioncouper.y = 310;

    back=IMG_Load("Back_boutton.png");
    positionback.x = 20;
    positionback.y = 25;

while (continuer)
{
SDL_WaitEvent(&event);
        switch(event.type)
        {
case SDL_QUIT:
                continuer = 0;
        break;
        case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
                {
case SDLK_DOWN :
if(x==1)
{
back=IMG_Load("Back_boutton.png");
diminuer=IMG_Load("diminuer_gr.png");
SDL_BlitSurface(diminuer, NULL, ecran, &positiondiminuer);
Mix_PlayChannel(1, son, 0);
x=2;y=1;
}

  else  if(x==2)
{
diminuer=IMG_Load("diminuer_volume.png");
couper=IMG_Load("couper_gr.png");
SDL_BlitSurface(couper, NULL, ecran, &positioncouper);
Mix_PlayChannel(1, son, 0);
x=3;y=4;
}

else if(x==3)
{
couper=IMG_Load("couper_son.png");
augmenter=IMG_Load("augmenter_gr.png");
SDL_BlitSurface(augmenter, NULL, ecran, &positionaugmenter);
Mix_PlayChannel(1, son, 0);
x=4;y=3;
}
 
else if(x==4)
{
augmenter=IMG_Load("augmenter_gr.png");
back=IMG_Load("back_gr.png");
SDL_BlitSurface(back, NULL, ecran, &positionback);
Mix_PlayChannel(1, son, 0);
x=1;y=2;
}

break;
case SDLK_UP :
if(y==1)
{
diminuer=IMG_Load("diminuer_volume.png");
back=IMG_Load("back_gr.png");
SDL_BlitSurface(back, NULL, ecran, &positionback);
Mix_PlayChannel(1, son, 0);
y=2;x=1;
}

else if(y==2)
{
back=IMG_Load("Back_boutton.png");
augmenter=IMG_Load("augmenter_gr.png");
SDL_BlitSurface(augmenter, NULL, ecran, &positionaugmenter);
Mix_PlayChannel(1, son, 0);
y=3;x=4;
}

else if(y==3)
{
augmenter=IMG_Load("augmenter_volume.png");
couper=IMG_Load("couper_gr.png");
SDL_BlitSurface(couper, NULL, ecran, &positioncouper);
Mix_PlayChannel(1, son, 0);
y=4;x=3;
}

else if(y==4)
{
couper=IMG_Load("couper_son.png");
diminuer=IMG_Load("diminuer_gr.png");
SDL_BlitSurface(diminuer, NULL, ecran, &positiondiminuer);
Mix_PlayChannel(1, son, 0);
y=1;x=2;
}
break;
case SDLK_RETURN :
if(y==1)
{Mix_VolumeChunk(son, MIX_MAX_VOLUME);Mix_VolumeMusic(MIX_MAX_VOLUME/2);}
else if(y==2)
{setting(ecran,son,musique,i);}
else if (y==3)
{Mix_VolumeChunk(son, MIX_MAX_VOLUME);Mix_VolumeMusic(MIX_MAX_VOLUME*2);}
else if (y==4)
{
if(a==0)
{Mix_PauseMusic();a=1;}
else if(a==1)
{Mix_ResumeMusic();a=0;}
}

break;
case SDLK_ESCAPE:
                        setting(ecran,son,musique,i);
                break;

}
                break;
                case SDL_MOUSEBUTTONDOWN:

                         if (event.button.button == SDL_BUTTON_LEFT)
        {
 if ((event.button.x >positionaugmenter.x) && (event.button.x < positionaugmenter.x +positionaugmenter.w) && (event.button.y >positionaugmenter.y) && (event.button.y <positionaugmenter.x+positionaugmenter.h))
                            {
            previous_volume=Mix_VolumeChunk(son, MIX_MAX_VOLUME);
             Mix_VolumeMusic(MIX_MAX_VOLUME*4);
                               }

                     
else if ((event.button.x >positioncouper.x) && (event.button.x < positioncouper.x +positioncouper.w) && (event.button.y >positioncouper.y) && (event.button.y <positioncouper.x+positioncouper.h))
                            {
if(a==0)
{Mix_PauseMusic();a=1;}
else if(a==1)
{Mix_ResumeMusic();a=0;}
   }
else if ((event.button.x >positiondiminuer.x) && (event.button.x < positiondiminuer.x +positiondiminuer.w) && (event.button.y >positiondiminuer.y) && (event.button.y <positiondiminuer.x+positiondiminuer.h))
                            {previous_volume=Mix_VolumeChunk(son, MIX_MAX_VOLUME/2);Mix_VolumeMusic(MIX_MAX_VOLUME/4);}

else if ((event.button.x >positionback.x) && (event.button.x < positionback.x +positionback.w) && (event.button.y >positionback.y) && (event.button.y <positionback.x+positionback.h))
                                {setting(ecran,son,musique,i);}


        }    
break;  
}

        SDL_BlitSurface(background, NULL, ecran, &positionbackground);
        SDL_BlitSurface(augmenter, NULL, ecran, &positionaugmenter);
SDL_BlitSurface(couper, NULL, ecran, &positioncouper);
        SDL_BlitSurface(diminuer, NULL, ecran, &positiondiminuer);
        SDL_BlitSurface(back, NULL, ecran, &positionback);
SDL_Flip(ecran);
}

SDL_Quit();
}
