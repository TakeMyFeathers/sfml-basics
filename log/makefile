log: main.o log.o
	g++ main.o log.o -o log

main.o: main.cpp
	g++ -c main.cpp

log.o: log.cpp
	g++ -c log.cpp

clean:
	rm *.o log