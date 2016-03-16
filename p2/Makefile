.PHONY: clean dist

CC = g++
OBJECT_FLAGS = -c -Wall -g
EXE_FLAGS = -g -Wall
INCLUDES = -I.
LFLAGS = #-L.
LIBS = #-lrt #-lpthread

MAIN = donante.o #pruebaDonante.out

all:    $(MAIN)
	@echo  Terminado

%.o:	%.cpp
	$(CC) $(OBJECT_FLAGS) $(INCLUDES) $<  -o $@
	
#pruebaDonante.out: pruebaDonante.cpp donante.o
#	$(CC) $(EXE_FLAGS) $^ -o $@

clean:
	$(RM) *.o *~ $(MAIN) log-*.txt

dist: 
	tar zcvf ed-practica2.tar.gz *.cpp *.hpp Makefile htdocs/*

