.PHONY: clean dist

PROJECT_NAME = ed-practica2

CC = g++ -std=c++11
OBJECT_FLAGS = -c -Wall -g
EXE_FLAGS = -g -Wall
INCLUDES = -I.

MAIN = donante.o pruebaDonante.out donantes.o pruebaDonantes.out

all:    $(MAIN)
	@echo  Terminado
	
donante.o: donante.cpp donanteInterfaz.hpp donante.hpp
	$(CC) $(OBJECT_FLAGS) $(INCLUDES) $<  -o $@

donantes.o: donantes.cpp donantesInterfaz.hpp donantes.hpp donante.o
	$(CC) $(OBJECT_FLAGS) $(INCLUDES) $<  -o $@
	
pruebaDonante.out: pruebaDonante.cpp donante.o
	$(CC) $(EXE_FLAGS) $^ -o $@

pruebaDonantes.out: pruebaDonantes.cpp donantes.o donante.o
	$(CC) $(EXE_FLAGS) $^ -o $@

clean:
	$(RM) -r *.o *~ $(MAIN) log-*.txt html/

dist: 
	tar zcvf $(PROJECT_NAME).tar.gz *.cpp *.hpp Makefile Doxyfile

