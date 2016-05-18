.PHONY: clean dist

PROJECT_NAME = ed-practica2

CC = g++ -std=c++11
OBJECT_FLAGS = -c -Wall -g
EXE_FLAGS = -g -Wall
INCLUDES = -I.

MAIN = donante.o monticulo.o pruebaMonticulo.out

all:    $(MAIN)
	@echo  Terminado
	
donante.o: donante.cpp donanteInterfaz.hpp donante.hpp
	$(CC) $(OBJECT_FLAGS) $(INCLUDES) $<  -o $@
	
monticulo.o: monticuloDonantes.cpp monticuloDonantesInterfaz.hpp monticuloDonantes.hpp donante.hpp donanteInterfaz.hpp
	$(CC) $(OBJECT_FLAGS) $(INCLUDES) $<  -o $@
	
pruebaMonticulo.out: pruebaMonticulo.cpp donante.o monticulo.o funciones.hpp funciones.cpp
	$(CC) $(EXE_FLAGS) $^ -o $@

clean:
	$(RM) *.o *~ $(MAIN) log-*.txt

dist: 
	tar zcvf $(PROJECT_NAME).tar.gz *.cpp *.hpp Makefile Doxyfile

