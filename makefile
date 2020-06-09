prog: char.o mainnnnn.o 
	gcc mainnnnn.o char.o -o prog -lSDL -lSDL_image -lm -lSDL_mixer
mainnnnn.o:mainnnnn.c
	gcc -c mainnnnn.c 
char.o:char.c
	gcc -c char.c 

