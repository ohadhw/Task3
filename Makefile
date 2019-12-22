CC=gcc
AR=ar
OBJECTS_TXTFIND=txtfind.o
OBJECTS_ISORT=isort.o
FLAGS= -Wall -g

all: txtfind isort

txtfind.o: txtfind.c
	$(CC) $(FLAGS) -c txtfind.c

isort.o: isort.c
	$(CC) $(FLAGS) -c isort.c



.PHONY: clean all

clean:
	rm -f *.o txtfind isort 
