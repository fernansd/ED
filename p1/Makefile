.PHONY: clean dist

CC = g++
CFLAGS = -c -Wall -g
CPPFLAGS = -g -Wall -ansi
INCLUDES = #-I.
LFLAGS = #-L.
LIBS = #-lrt #-lpthread

MAIN = monomio.o polinomio.o pruebaMonomio.out pruebaPolinomio.out

all:    $(MAIN)
	@echo  Terminado

%.o:	%.cpp
	$(CC) $(CFLAGS) $(INCLUDES) $<  -o $@
	
pruebaMonomio.out: pruebaMonomio.cpp monomio.cpp
	$(CC) $(CPPFLAGS) pruebaMonomio.cpp monomio.o -o $@
	
pruebaPolinomio.out: pruebaPolinomio.cpp polinomio.cpp
	$(CC) $(CPPFLAGS) pruebaPolinomio.cpp polinomio.o -o $@

clean:
	$(RM) *.o *~ $(MAIN) log-*.txt

dist: 
	tar zcvf ed-practica1.tar.gz *.cpp *.hpp Makefile htdocs/*

