run: main.cpp Gusano.o gfx.o
	g++ gfx.o main.cpp Gusano.o gfx.o -o main -lX11

gfx.o: gfx.c gfx.h
	gcc gfx.c -c

Gusano.o: Gusano.cpp Gusano.h
	g++ Gusano.cpp -c