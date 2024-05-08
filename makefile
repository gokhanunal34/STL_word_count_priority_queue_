#Project 7 STL word count makefile

CC = g++ -std=c++11

proj7.x: proj7.cpp pqueue.h
	$(CC) -o proj7.x proj7.cpp
clean:
	rm -f *.o proj7.x
	

