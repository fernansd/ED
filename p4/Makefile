.PHONY: clean dist

PROJECT_NAME = ed-practica4

CC = g++ -std=c++11
OBJECT_FLAGS = -c -Wall -g
EXE_FLAGS = -g -Wall
INCLUDES = -I.

MAIN = vertice.o grafo.o

all:    $(MAIN)
	@echo  Terminado

vertice.o: vertice.hpp
	$(CC) $(OBJECT_FLAGS) $(INCLUDES) $<  -o $@
	
grafo.o: grafo.cpp grafo.hpp vertice.o
	$(CC) $(OBJECT_FLAGS) $(INCLUDES) $<  -o $@
		
main.out: main.cpp grafo.cpp grafo.hpp vertice.hpp funciones.hpp funciones.cpp
	$(CC) $(EXE_FLAGS) $^ -o $@

clean:
	$(RM) *.o *~ $(MAIN) log-*.txt

dist: 
	tar zcvf $(PROJECT_NAME).tar.gz *.cpp *.hpp Makefile Doxyfile

