#include"tetric.h"

/*
 colors:0xFF0000FF red, 0x00FF00FF  green 0x0000FFFF blue.
*/

int SetPixel32(SDL_Surface* srf,int x,int y,Uint32 color)
{
    Uint32 *p = (Uint32*)(((Uint8*)srf->pixels) + y * srf->pitch + x * 4);
    *p = color;
    return 0;
}

int BuildTileSet(SDL_Surface* srf)
{
    Uint32 colors[NBPIECES+2][3]={{0,0,0},
        {128,128,128},{255,0,0},{0,255,0},{0,0,255},
        {255,255,0},{255,0,255},{0,255,255},{255,128,0}
    };
    Uint32 Tileshem[TILESIZE]={
        0xFFFFFFFD,0xFFFFFFF5,0xFAAAAAA5,0xFAAAAAA5,
        0xFAAAAAA5,0xFAAAAAA5,0xFAAAAAA5,0xFAAAAAA5,
        0xFAAAAAA5,0xFAAAAAA5,0xFAAAAAA5,0xFAAAAAA5,
        0xFAAAAAA5,0xFAAAAAA5,0xD5555555,0x55555555
    };
    int i,j,k;
    SDL_LockSurface(srf);
    for(k=0;k<NBPIECES+2;k++)
    {
        Uint32 LocalPalette[4];
        for(i=0;i<4;i++)
            LocalPalette[i] = SDL_MapRGBA(srf->format,(colors[k][0]/3)*i,(colors[k][1]/3)*i,(colors[k][2]/3)*i,0);
        DOUBLEFOR(i,TILESIZE,j,TILESIZE)
        {
            int ndat = j*TILESIZE+i;
            Uint32 ind = ((Tileshem[ndat/16]<<((ndat%16)*2))&0xC0000000)>>30;
            SetPixel32(srf,k*TILESIZE+i,j,LocalPalette[ind]);
        }
    }
    SDL_UnlockSurface(srf);
    //SDL_SaveBMP(srf,"plouf.bmp");
    return 0;
}

int BuildPieces(Tetris* T)
{
    Uint16 shem[NBPIECES][4] = {
        {0xC600,0x2640,0xC600,0x2640},
        {0x6C00,0x4620,0x6C00,0x4620},
        {0x8E00,0x6440,0x0E20,0x44C0},
        {0x6600,0x6600,0x6600,0x6600},
        {0x4E00,0x4640,0x0E40,0x4C40},
        {0x0F00,0x2222,0x0F00,0x2222},
        {0x2E00,0x4460,0x0E80,0xC440}
    };
    int i,j,k,l;
    DOUBLEFOR(i,NBPIECES,j,4)
        DOUBLEFOR(k,4,l,4)
        {
            int dat = ((shem[i][j]<<(l*4+k))&0x8000)>>15;
            T->pieces[i][j][k][l] = dat*(i+2);
        }
    return 0;
}

int NouvellePiece(Tetris* T)
{
    T->numpiece = T->numpiecenext;
    T->numpiecenext = rand()%NBPIECES;
    T->Scurrent.rotate = 0;
    T->Scurrent.x = (NCOL-4)/2;
    T->Scurrent.y = 0;
    T->nextmove = SDL_GetTicks()+T->vitesse;
    return 0;
}

int Tetris_Init(Tetris* T)
{
    int i;
    T->numpiecenext = T->gameover = T->nextmove = 0;
    T->vitesse = VITESSE;
    NouvellePiece(T);
    NouvellePiece(T);
    T->tiles = SDL_CreateRGBSurface(0,(NBPIECES+2)*TILESIZE,TILESIZE,32,0,0,0,0);
    BuildTileSet(T->tiles);
    BuildPieces(T);
    memset(T->zone,0,NCOL*NLINE);
    for(i=0;i<NCOL;i++)
        T->zone[i][NLINE-1] = 1; // ligne de protection basse
    for(i=0;i<NLINE;i++)
    {
        T->zone[0][i] = 1; // lignes de protections latérales.
        T->zone[NCOL-1][i] = 1;
    }
    return 0;
}

int Tetris_End(Tetris* T)
{
    SDL_FreeSurface(T->tiles);
    return 0;
}

int Cube(SDL_Surface* srf,int i,int j,int numcube)
{
    SDL_Rect Rsrc,Rdest;
    Rdest.x = i*TILESIZE;
    Rdest.y = j*TILESIZE;
    Rsrc.x = numcube*TILESIZE;
    Rsrc.y = 0;
    Rsrc.w = TILESIZE;
    Rsrc.h = TILESIZE;
    SDL_BlitSurface(srf,&Rsrc,SDL_GetVideoSurface(),&Rdest);
    return 0;
}

int RenderFond(Tetris* T)
{ // 2 fois pour toutes, double buffering, 
    int i,j,k;
    for(k=0;k<2;k++)
    {
        DOUBLEFOR(i,XRES/TILESIZE,j,YRES/TILESIZE)
            Cube(T->tiles,i,j,1);
        SDL_Flip(SDL_GetVideoSurface());
    }
    return 0;
}

int RenderPiece(Tetris* T,int x,int y,int npiece,int rotate,int transparence)
{
    int i,j;
    DOUBLEFOR(i,4,j,4)
    {
        if (transparence && T->pieces[npiece][rotate][i][j]==0)
            continue;
        Cube(T->tiles,x+i,y+j,T->pieces[npiece][rotate][i][j]);
    }
    return 0;
}

int Render(Tetris* T)
{
    int i,j;
    DOUBLEFOR(i,NCOL,j,NLINE)
        Cube(T->tiles,i+STARTXZONEJEU,j+STARTYZONEJEU,T->zone[i][j]);
    RenderPiece(T,STARTXZONEJEU+NCOL+2,4,T->numpiecenext,0,0);
    RenderPiece(T,STARTXZONEJEU+T->Scurrent.x,STARTYZONEJEU+T->Scurrent.y,T->numpiece,T->Scurrent.rotate,1);
    SDL_Flip(SDL_GetVideoSurface());
    SDL_Delay(1);
    return 0;
}

#define PIECECARRE(T,i,j) (T->pieces[T->numpiece][T->Scand.rotate][i][j])

int Valide(Tetris* T)
{
    int i,j;
    DOUBLEFOR(i,4,j,4)
    {
        Uint8 carre = PIECECARRE(T,i,j);
        if (carre!=0 && T->zone[T->Scand.x+i][T->Scand.y+j]!=0)
             return 0;
    }
    T->Scurrent = T->Scand;
    return 1;
}

int AncrePiece(Tetris* T)
{
    int i,j;
    T->Scand = T->Scurrent;
    DOUBLEFOR(i,4,j,4)
    {
        Uint8 carre = PIECECARRE(T,i,j);
        if (carre!=0)
            T->zone[T->Scand.x+i][T->Scand.y+j] = carre;
    }
    return 0;
}

int VirerLigne(Tetris* T,int y)
{
    int i,j;
    for(i=0;i<NCOL;i++)
    {
        for(j=y;j>0;j--)
            T->zone[i][j] = T->zone[i][j-1];
        T->zone[i][0] = 0;
    }
    T->zone[0][0] = 1;
    T->zone[NCOL-1][0] = 1;
    return 0;
}

int VirerLignes(Tetris* T,int ystart)
{
    int i,j;
    for(i=0;i<4;i++)
    {
        int cpt = 0;
        if (i+ystart==NLINE-1)
            break; // on ne vire pas la ligne de protection basse.
        for(j=0;j<NCOL;j++)
            if (T->zone[j][i+ystart]!=0)
                cpt++;
        if (cpt==NCOL)
            VirerLigne(T,i+ystart);
    }
    return 0;
}

int Descente(Tetris* T)
{
    T->Scand.y++;
    if (Valide(T))
    {
        T->nextmove = SDL_GetTicks()+T->vitesse;
        return 0;
    }
    else
    {
        if (T->Scurrent.y == 0)
            T->gameover = 1;
        AncrePiece(T);
        VirerLignes(T,T->Scurrent.y);
        NouvellePiece(T);
    }
    return 0;
}

int Jeu(Tetris* T)
{  
    SDL_Event E;
    SDL_EnableKeyRepeat(200,50);
    while(!T->gameover)
    {
        T->Scand = T->Scurrent;
        if (SDL_GetTicks()>=T->nextmove)
            Descente(T);
        while (SDL_PollEvent(&E))
        {
            if (E.type!=SDL_KEYDOWN)
                continue;
            if (E.key.keysym.sym == SDLK_DOWN && T->nextmove-SDL_GetTicks()>20) // drop
                T->nextmove = SDL_GetTicks()+20;
            if (E.key.keysym.sym == SDLK_LEFT)
                T->Scand.x--;
            if (E.key.keysym.sym == SDLK_RIGHT)
                T->Scand.x++;
            if (E.key.keysym.sym == SDLK_SPACE)
                T->Scand.rotate = (T->Scand.rotate+1)%4;
            Valide(T);
        }
        Render(T);
    }
    return 0;
}


