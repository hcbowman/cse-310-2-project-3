CC=g++
CPPFLAGS=--std=c++11 -pedantic -Wall -g

all: ice

ice: main.cpp file_handler.o hash_entry.o hash_table.o
	$(CC) $(CPPFLAGS) main.cpp file_handler.o hash_entry.o hash_table.o -o ice

file_handler.o: file_handler.cpp
	$(CC) $(CPPFLAGS) -c file_handler.cpp

hash_entry.o: hash_entry.cpp
	$(CC) $(CPPFLAGS) -c hash_entry.cpp

hash_table.o: hash_table.cpp
	$(CC) $(CPPFLAGS) -c hash_table.cpp

clean:
	rm -f *.o *.out *.exe *.stackdump ice