game: main.o Game.o
	g++ main.o Game.o -o game -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp

Game.o: Game.cpp
	g++ -c Game.cpp

clean:
	rm *.o game