all: main

main: main.o capp.o cplayer.o barrier.o timer.o
	g++ -std=gnu++11 capp.o timer.o cplayer.o barrier.o main.o -o main -lSDL2

main.o: main.cpp
	g++ -std=gnu++11 -c main.cpp -o main.o

capp.o: capp.cpp capp.hpp
	g++ -std=gnu++11 -I/usr/include/SDL2 -c capp.cpp

cplayer.o: cplayer.hpp cplayer.cpp
	g++ -std=gnu++11 -c cplayer.cpp

barrier.o: barrier.cpp barrier.hpp
	g++ -std=gnu++11 -c barrier.cpp

timer.o: timer.cpp timer.hpp
	g++ -std=gnu++11 -I/usr/include/SDL2 -c timer.cpp

clean:
	rm main.o capp.o cplayer.o barrier.o timer.o main
