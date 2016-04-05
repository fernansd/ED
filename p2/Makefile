.PHONY: clean dist

PROJECT_NAME = ed-practica2

CC = g++
OBJECT_FLAGS = -c -Wall -g
EXE_FLAGS = -g -Wall
INCLUDES = -I.

MAIN = donante.o pruebaDonante.out

all:    $(MAIN)
	@echo  Terminado
	
donante.o: donante.cpp donanteInterfaz.hpp donante.hpp
	$(CC) $(OBJECT_FLAGS) $(INCLUDES) $<  -o $@
	
lista.o: lista.cpp listaInterfaz.hpp lista.hpp
	$(CC) $(OBJECT_FLAGS) $(INCLUDES) $<  -o $@

donantes.o: donantes.cpp donantes.hpp
	$(CC) $(OBJECT_FLAGS) $(INCLUDES) $<  -o $@
	
pruebaDonante.out: pruebaDonante.cpp donante.o
	$(CC) $(EXE_FLAGS) $^ -o $@

pruebaDonantes.out: pruebaDonantes.cpp donantes.o lista.o
	$(CC) $(EXE_FLAGS) $^ -o $@

clean:
	$(RM) *.o *~ $(MAIN) log-*.txt

dist: 
	tar zcvf $(PROJECT_NAME).tar.gz *.cpp *.hpp Makefile Doxyfile

