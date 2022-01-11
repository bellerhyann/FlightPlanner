OPTS= -g -Wall -ansi -pedantic -std=c++17

OBJS = Graph.o main.o Flight.o

CC = g++ -c $(OPTS) 
LN = g++

runMe: $(OBJS)
	$(LN) -o runMe $(OBJS)

main.o: main.cpp Graph.hpp Flight.hpp
	$(CC) main.cpp

Graph.o: Graph.cpp Graph.hpp 
	$(CC) Graph.cpp
	
Flight.o: Flight.cpp Flight.hpp 
	$(CC) Flight.cpp
	
clean:
	/bin/rm -f $(OBJS) runMe *~
