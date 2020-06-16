#include"tetric.h"

int main(int argc,char** argv)
{
    Tetris T;
    srand((unsigned int)time(NULL));
    SDL_Init(SDL_INIT_VIDEO);
    SDL_SetVideoMode(XRES,YRES,32,SDL_DOUBLEBUF);
    Tetris_Init(&T);
    RenderFond(&T);
    Jeu(&T);
    Tetris_End(&T);
    SDL_Quit();
    return 0;
}
