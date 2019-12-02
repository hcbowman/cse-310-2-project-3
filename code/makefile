CC=g++
CPPFLAGS=--std=c++11 -pedantic -Wall -g

all: seaice

seaice: main.cpp node.o adjacency_list.o
	$(CC) $(CPPFLAGS) main.cpp node.o adjacency_list.o -o seaice

node.o: node.cpp
	$(CC) $(CPPFLAGS) -c node.cpp

adjacency_list.o: adjacency_list.cpp
	$(CC) $(CPPFLAGS) -c adjacency_list.cpp

clean:
	rm -f *.o *.out *.exe *.stackdump ice seaice