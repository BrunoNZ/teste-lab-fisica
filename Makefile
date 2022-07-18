all: main_c

entradas.o: entradas.c entradas.h
	gcc -c -o entradas.o entradas.c

main_c: main.c entradas.o
	gcc -o main_c main.c entradas.o -Wall