all: main

main: main.o capp.o cplayer.o
	g++ -std=gnu++11 capp.o cplayer.o main.o -o main -lSDL2

main.o: main.cpp
	g++ -std=gnu++11 -c main.cpp -o main.o

capp.o: capp.cpp capp.hpp
	g++ -std=gnu++11 -I/usr/include/SDL2 -c capp.cpp

cplayer.o: cplayer.hpp cplayer.cpp
	g++ -std=gnu++11 -c cplayer.cpp

clean:
	rm main.o capp.o
