CC = gcc
LD = gcc
CFLAGS = -O3  -Wall -lm -pedantic -ansi -std=gnu99 
LDFLAGS = -O3 -o
MC = gcc -o Main main.c -lm -pedantic -ansi -std=gnu99 

all: 	main.c
	$(CC) -o prog main.c $(CFLAGS)
clean: Main
	rm Main
