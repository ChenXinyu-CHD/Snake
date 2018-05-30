# This is the makefile
# use make to build the project

HEADER_FILE = GameMap.h Snake.h Plyer.h Position.h enviroment.h

Snake: main.o 
	g++ main.o -o Snake -O2 -lpthread

main.o: main.cpp enviroment.h
	g++ main.cpp -o main.o -O2 -c

clean:
	rm *.o Snake
