#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_rotozoom.h>


#define TILESIZE 16
#define NBPIECES 7
#define XRES 400
#define YRES 400
#define NLINE 21
#define NCOL 12
#define STARTXZONEJEU 4
#define STARTYZONEJEU 2
#define VITESSE 500   // temps en millisecondes avant prochaine descente.

#define DOUBLEFOR(i,imax,j,jmax) for(i=0;i<imax;i++) for(j=0;j<jmax;j++)

struct State
{
    int x,y,rotate;
};

struct STetris
{
    SDL_Surface* tiles;
    Uint8 zone[NCOL][NLINE];
    Uint8 pieces[NBPIECES][4][4][4];
    int numpiece,numpiecenext;
    struct State Scurrent;
    struct State Scand;
    int gameover,vitesse;
    Uint32 nextmove;
};

typedef struct STetris Tetris;

int Tetris_Init(Tetris* T);
int RenderFond(Tetris* T);
int Jeu(Tetris* T);
int Tetris_End(Tetris* T);
