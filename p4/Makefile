.PHONY: clean dist

PROJECT_NAME = ed-practica4

CC = g++ -std=c++11
OBJECT_FLAGS = -c -Wall -g
EXE_FLAGS = -g -Wall
INCLUDES = -I.

MAIN = donante.o monticulo.o pruebaMonticulo.out

all:    $(MAIN)
	@echo  Terminado

vertice.o: vertice.cpp vertice.hpp
	$(CC) $(OBJECT_FLAGS) $(INCLUDES) $<  -o $@
	
grafo.o: grafo.cpp grafo.hpp vertice.o
	$(CC) $(OBJECT_FLAGS) $(INCLUDES) $<  -o $@
		
main.out: pruebaMonticulo.cpp donante.o monticulo.o
	$(CC) $(EXE_FLAGS) $^ -o $@

clean:
	$(RM) *.o *~ $(MAIN) log-*.txt

dist: 
	tar zcvf $(PROJECT_NAME).tar.gz *.cpp *.hpp Makefile Doxyfile

