# This is the makefile
# use make to build the project

HEADER_FILE = GameMap.h Snake.h Position.h enviroment.h

Snake: main.o Position.o GameMap.o Snake.o
	g++ main.o Position.o GameMap.o Snake.o -o Snake -O2 -g -lpthread

main.o: main.cpp $(HEADER_FILE)
	g++ main.cpp -o main.o -O2 -c -g

Position.o: Position.cpp Position.h
	g++ Position.cpp -o Position.o -O2 -c -g

Snake.o: Snake.h Snake.cpp Position.h dataStructure/*
	g++ Snake.cpp -o Snake.o -O2 -c -g

GameMap.o: GameMap.cpp GameMap.h Snake.h Position.h
	g++ GameMap.cpp -o GameMap.o -O2 -c -g

clean:
	rm *.o Snake
