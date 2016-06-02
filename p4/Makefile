.PHONY: clean dist

PROJECT_NAME = ed-practica4

CC = g++ -std=c++11
OBJECT_FLAGS = -c -Wall -g
EXE_FLAGS = -g -Wall
INCLUDES = -I.

MAIN = vertice.o grafo.o funciones.o main.out

all:    $(MAIN)
	@echo  Terminado

vertice.o: vertice.hpp
	$(CC) $(OBJECT_FLAGS) $(INCLUDES) $<  -o $@
	
grafo.o: grafo.cpp grafo.hpp vertice.o
	$(CC) $(OBJECT_FLAGS) $(INCLUDES) $<  -o $@
	
funciones.o: funciones.hpp funciones.cpp grafo.o vertice.hpp macros.hpp
	$(CC) $(OBJECT_FLAGS) $(INCLUDES) $<  -o $@
		
main.out: main.cpp grafo.cpp grafo.hpp grafoInterfaz.hpp vertice.hpp funciones.hpp funciones.cpp macros.hpp
	$(CC) $(EXE_FLAGS) $(INCLUDES) $^ -o $@

clean:
	$(RM) -r *.o *~ $(MAIN) log-*.txt html/

dist: 
	tar zcvf $(PROJECT_NAME).tar.gz *.cpp *.hpp Makefile Doxyfile

