prog: condition.o main.o 
	gcc main.o condition.o -o prog -lSDL -lSDL_image -lm -lSDL_mixer
main.o:main.c
	gcc -c main.c 
condition.o:condition.c
	gcc -c condition.c 

