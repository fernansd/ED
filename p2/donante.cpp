#include "donante.hpp"

namespace ed {

/*! 
    \brief Permite modificar el grupo de un donante. Si no se propociona 
            un valor válido, devolverá false. En caso contrario devuelve true.
            Los valores válidos son: [0, A, B, AB]
	\return Devuelve un valor booleano
	\pre El Donante debe existir y se debe proporcionar un valor válido
	\post Ninguna
	\sa Donante::setGrupo()
*/  
bool Donante::setGrupo(string grupo) {

    if ( grupo != "0" && grupo != "A" && grupo != "B" && grupo != "AB" )
        return false;
        
    grupo_ = grupo;
    return true
}

/*! 
    \brief Permite modificar el valor del factor RH de un donante. En caso
            de que el valor proporcionado no se encuentre entre los válidos,
            se devolverá false. En caso contrario true. Los valores posibles
            son: [negativo, positivo]
	\return Devuelve un valor booleano
	\pre El Donante debe existir y se debe proporcionar un valor válido
	\post Ninguna
	\sa Donante::setGrupo()
*/
bool Donante::setFactorRH(string factor) {

    if (factor != "negativo" && factor != "positivo") 
        return false;
        
    factor_ = factor;
    return true;
}

/*! 
    \brief Permite la lectura a través de teclado de todos los datos de un
            donante. Internamente hace uso de la sobrecarga del operador >>.
	\return Nada
	\pre El Donante debe existir
	\post Ninguna
	\sa istream &operator<<(istream &stream, Donante &d)
*/
void Donante::leerDonante() {
    cin >> *this;
}

/*! 
    \brief Escribe por pantalla todos los datos del donante, internamente hace
            uso de la sobrecarga del operador <<.
	\return Nada
	\pre El Donante debe existir
	\post Ninguna
	\sa ostream &operator<<(ostream &stream, Donante &d)
*/       
void Donante::escribirDonante() {
    cout << *this;
}

/*! 
    \brief Sobrecarga del operador de asignación ( = )
	\return Devuelve una referencia a un objeto de la clase Donante
	\pre El Donante debe existir
	\post Ninguna
	\sa Donante::setGrupo()
*/  
Donante& Donante::operator=(Donante const &d) {

    *this = d;
    return *this;
}
        
bool Donante::operator==(Donante const &d) {

    if (this->getNombre() == d.getNombre() &&
        this->getApellidos() == d.getApellidos() &&
        this->getGrupo() == d.getGrupo() &&
        this->getFactorRH() == d.getFactorRH()    
        ) return true;
    else
        return false;
}

bool operator<=(Donante const &d1, Donante const &d2) {
    if (d1.getApellidos() == d2.getApellidos()) {
        if (d1.getNombre() < d2.getNombre()) {
            return false;
        }
    } else {
        if (d1.getApellidos() == d2.getApellidos()) {
            return false;
        }
    }
    
    return true;
}

/*! 
    \brief Sobrecarga del operador >> para permitir la lectura de todos las
            variables del donante a través de teclado
	\return Devuelve un istream
	\pre El Donante debe existir
	\post Ninguna
	\sa ostream &operator<<(ostream &stream, Donante &d)
*/
istream &operator>>(istream &stream, Donante &d) {
    
    // Variable auxiliar para obtener las cadenas introducidas
    string aux;
    // Variable para tratar el estado de éxito de las funciones
    bool exito;
    
    cout << "Lectura de datos de donante" << endl;
    
    cout << "Introduce el nombre: ";
    cin >> aux;
    d.setNombre(aux);
    
    cout << "Introduce los apellidos: ";
    cin >> aux;
    d.setApellidos(aux);
    
    cout << "Introduce el grupo: ";
    cin >> aux;
    exito = d.setGrupo(aux);
    // En caso de que no se introduzca un valor adecuado lo indica y proporciona
    // cuales son los valores posibles para la variable grupo
    while (exito == false) {
    
        cout << "Valor incorrecto para el grupo" << endl;
        cout << "Los valores posibles son: [0, A, B, AB]" << endl;
        cout << "Introduce un nuevo valor: " << endl;
        cin >> aux;
        exito = d.setGrupo(aux);
    }
    
    cout << "Introduce el factor RH: ";
    cin >> aux;
    exito = d.setFactorRH(aux);
    // En caso de que no se introduzca un valor adecuado lo indica y proporciona
    // cuales son los valores posibles para la variable factorRH
    while (exito == false ) {
    
        cout << "Valor incorrecto para factor RH" << endl;
        cout << "Los valores posibles son: [negativo, positivo]" << endl;
        cout << "Introduce un nuevo valor: " << endl;
        cin >> aux;
        exito = d.setFactorRH(aux);
    }
    
    return stream;
}

/*! 
    \brief Sobrecarga del operador >> que permite la escritura por pantalla
            de todos los datos del donante
	\return Devuelve un ostream
	\pre El Donante debe existir
	\post Ninguna
	\sa istream &operator<<(istream &stream, Donante &d)
*/
ostream &operator<<(ostream &stream, Donante &d) {

    stream << "Datos de donante: " << endl << endl;
    
    stream << "\tNombre: " << d.getNombre() << endl;
    stream << "\tApellidos: " << d.getApellidos() << endl;
    stream << "\tGrupo: " << d.getGrupo() << endl;
    stream << "\tFactor RH: " << d.getFactorRH() << endl;
    
    return stream;
}

}// Fin namespace ed
