.PHONY: clean dist

CC = g++
CFLAGS = -c -Wall -g
CPPFLAGS = -g -Wall
INCLUDES = #-I.
LFLAGS = #-L.
LIBS = #-lrt #-lpthread

MAIN = monomio.o polinomio.o pruebaMonomio.out pruebaPolinomio.out

all:    $(MAIN)
	@echo  Terminado

%.o:	%.cpp
	$(CC) $(CFLAGS) $(INCLUDES) $<  -o $@
	
pruebaMonomio.out: pruebaMonomio.cpp monomio.o
	$(CC) $(CPPFLAGS) $^ -o $@
	
pruebaPolinomio.out: pruebaPolinomio.cpp polinomio.o monomio.o
	$(CC) $(CPPFLAGS) $^ -o $@

clean:
	$(RM) *.o *~ $(MAIN) log-*.txt

dist: 
	tar zcvf ed-practica1.tar.gz *.cpp *.hpp Makefile htdocs/*

