#ifndef P3_FUNCIONES_HPP
#define P3_FUNCIONES_HPP

// Función para detener la ejecución hasta que el usuario presione ENTER
void esperarUsuario(int opc = 0);

void leerMonticuloFichero(MonticuloDonantes& m);

void grabarMonticulo(MonticuloDonantes& m);

void simularDonaciones(MonticuloDonantes& m);

#endif
