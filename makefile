mentester:  menu1.o main.o 
	gcc main.o menu1.o -o testermenu1 -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf 
main.o:main.c
	gcc -c main.c 
menu1.o:menu1.c
	gcc -c menu1.c 



