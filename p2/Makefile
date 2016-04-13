.PHONY: clean dist

PROJECT_NAME = ed-practica2

CC = g++ -std=c++11
OBJECT_FLAGS = -c -Wall -g
EXE_FLAGS = -g -Wall
INCLUDES = -I.

MAIN = donante.o pruebaDonante.out lista.o donantes.o pruebaDonantes.out

all:    $(MAIN)
	@echo  Terminado
	
donante.o: donante.cpp donanteInterfaz.hpp donante.hpp
	$(CC) $(OBJECT_FLAGS) $(INCLUDES) $<  -o $@
	
lista.o: lista.cpp listaInterfaz.hpp lista.hpp
	$(CC) $(OBJECT_FLAGS) $(INCLUDES) $<  -o $@

donantes.o: donantes.cpp donantesInterfaz.hpp donantes.hpp donante.o lista.o
	$(CC) $(OBJECT_FLAGS) $(INCLUDES) $<  -o $@
	
pruebaDonante.out: pruebaDonante.cpp donante.o
	$(CC) $(EXE_FLAGS) $^ -o $@

pruebaDonantes.out: pruebaDonantes.cpp donantes.o lista.o donante.o
	$(CC) $(EXE_FLAGS) $^ -o $@

clean:
	$(RM) *.o *~ $(MAIN) log-*.txt

dist: 
	tar zcvf $(PROJECT_NAME).tar.gz *.cpp *.hpp Makefile Doxyfile

