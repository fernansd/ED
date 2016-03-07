.PHONY: clean dist

CC = g++
CFLAGS = -c #-Wall -g
INCLUDES = #-I.
LFLAGS = #-L.
LIBS = #-lrt #-lpthread

MAIN = monomio.out polinomio.out

all:    $(MAIN)
	@echo  Terminado

%.out:	%.cpp
	$(CC) $(CFLAGS) $(INCLUDES) $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN) log-*.txt

dist: 
	tar zcvf ed-practica1.tar.gz *.cpp *.hpp Makefile htdocs/*

