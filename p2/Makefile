.PHONY: clean dist

PROJECT_NAME = ed-practica2

CC = g++ -std=c++11
OBJECT_FLAGS = -c -Wall -g
EXE_FLAGS =  -Wall -g
INCLUDES = -I.

MAIN = donante.o pruebaDonante.out donantes.o pruebaDonantes.out

all:    $(MAIN)
	@echo  Terminado
	
donante.o: donante.cpp donanteInterfaz.hpp donante.hpp
	$(CC) $(OBJECT_FLAGS) $<  -o $@

donantes.o: donantes.cpp donantesInterfaz.hpp donantes.hpp donante.o lista.hpp lista.cpp
	$(CC) $(OBJECT_FLAGS) $<  -o $@
	
funciones.o: funciones.cpp funciones.hpp donantes.o
	$(CC) $(OBJECT_FLAGS) $<  -o $@
	
pruebaDonante.out: pruebaDonante.cpp donante.o
	$(CC) $(EXE_FLAGS) $^ -o $@

pruebaDonantes.out: pruebaDonantes.cpp donante.o donantes.o funciones.o
	$(CC) $(EXE_FLAGS) $^ -o $@

clean:
	$(RM) -r *.o *~ $(MAIN) log-*.txt html/

dist:
	tar czvf sanchez_delgado_fernando_Practica2_ED.tar.gz donante.?pp donanteInterfaz.hpp donantes.?pp donantesInterfaz.hpp Doxyfile funciones.?pp lista.?pp lista-donantes.txt listaInterfaz.hpp macros.hpp Makefile pruebaDonante.cpp pruebaDonantes.cpp

