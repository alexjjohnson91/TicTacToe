all: main

main: main.o tic.o
	g++ -std=c++11 -o main main.o tic.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp

tic.o: tic.cpp tic.hpp
	g++ -std=c++11 -c tic.cpp tic.hpp

pch.h.gch: pch.h
	g++ -x c++-header -o pch.h.gch -c pch.h

clean:
	rm *.o main
	rm -rf pch.h.gch
