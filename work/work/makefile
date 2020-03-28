prog:main.o  map.o player.o
	gcc main.o  map.o player.o -o -lm -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -o prog
main.o:main.c
	gcc -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -c main.c

map.o:map.c
	gcc -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -c map.c
player.o:player.c
	gcc -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -c player.c


