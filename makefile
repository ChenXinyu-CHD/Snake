# This is the makefile
# use make to build the project

HEADER_HOME = include
GAME_MAP = $(HEADER_HOME)/GameMap.h
SNAKE = $(HEADER_HOME)/Snake.h
ENVIROMENT = $(HEADER_HOME)/enviroment.h
TYPES = $(HEADER_HOME)/Types.h
HEADER_FILE = $(GAME_MAP) $(SNAKE) $(ENVIROMENT)

CC = g++ -I $(HEADER_HOME)

Snake: main.o GameMap.o Snake.o
	$(CC) main.o GameMap.o Snake.o -o Snake -O2 -lpthread

main.o: main.cpp $(HEADER_FILE)
	$(CC) main.cpp -o main.o -O2 -c

Snake.o: Snake.cpp $(SNAKE) $(TYPES)
	$(CC) Snake.cpp -o Snake.o -O2 -c

GameMap.o: GameMap.cpp $(GAME_MAP) $(SNAKE)
	$(CC) GameMap.cpp -o GameMap.o -O2 -c

clean:
	rm *.o Snake
