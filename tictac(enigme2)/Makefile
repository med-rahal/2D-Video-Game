all : prog execute clean
execute:
	./Tic-Tac-Toe
prog : main.o graphics.o core.o store.o
	gcc main.c graphics.c core.c store.c -o Tic-Tac-Toe -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
clean:
	rm *.o
