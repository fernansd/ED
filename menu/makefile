# Fichero makefile
# Crea un menú que usa "macros de pantalla"

menu.exe: menu.o funciones.o
	g++ menu.o funciones.o -lm -o menu.exe

menu.o: menu.cpp funciones.hpp
	g++ -c menu.cpp

funciones.o: funciones.cpp funciones.hpp
	g++ -c funciones.cpp

clean:
	rm *.o
