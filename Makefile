CC=g++
CFLAGS=-I.

mainmake: hellomake.o hellofunc.o
     $(CC) -o hellomake hellomake.o hellofunc.o -I.
