game: main.o player.o ball.o
	g++ main.o player.o ball.o -o game -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp

player.o: player.cpp
	g++ -c player.cpp

ball.o: ball.cpp
	g++ -c ball.cpp

clean:
	rm *.o game