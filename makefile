prog: p2.o mainnnnnnn.o 
	gcc mainnnnnnn.o p2.o -o prog -lSDL -lSDL_image -lm -lSDL_mixer
mainnnnnnn.o:mainnnnnnn.c
	gcc -c mainnnnnnn.c 
p2.o:p2.c
	gcc -c p2.c 

