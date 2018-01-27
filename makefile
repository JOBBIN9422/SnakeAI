all: game

game: game.o segment.o snake.o food.o node.o pathfinder.o
	g++ -std=c++11 -lfltk -lfltk_images segment.o main.o snake.o food.o node.o pathfinder.o -o game
	
game.o: main.cpp snake.h food.h
	g++ -std=c++11 -g -c -lfltk -lfltk_images main.cpp
	
segment.o: segment.cpp segment.h
	g++ -std=c++11 -g -c -lfltk -lfltk_images segment.cpp
	
snake.o: snake.cpp snake.h segment.h food.h pathfinder.h
	g++ -std=c++11 -g -c -lfltk -lfltk_images snake.cpp
	
food.o: food.cpp food.h
	g++ -std=c++11 -g -c -lfltk -lfltk_images food.cpp

node.o: node.cpp node.h
	g++ -std=c++11 -g -c -lfltk -lfltk_images node.cpp
	
pathfinder.o: pathfinder.cpp pathfinder.h snake.h node.h
	g++ -std=c++11 -g -c -lfltk -lfltk_images pathfinder.cpp
	
clean:
	rm *.o game
	
