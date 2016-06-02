#ifndef DONANTESINTERFAZ_HPP
#define DONANTESINTERFAZ_HPP

#include "donante.hpp"

using namespace std;

namespace ed {

/*!
    \class DonantesInterfaz donantesInterfaz.hpp "./donantesInterfaz.hpp"
    \brief Clase abstracta que define una interfaz de interacción con una lista
            de elementos de tipo ed::Donante. Como estructura interna de la
            lista hace uso de la clase ed::Lista.
*/
class DonantesInterfaz {
    
    /*!
        \brief Comprueba si la lista contiene elementos.
        \return Devuelve true si la lista está vacía       
    */
    virtual bool estaVacia() const = 0;
    
    /*!
        \brief Función que busca un donante en la lista por nombre y lo
                devuelve 
        \param nombre Nombre del donante. Tipo std::string
        \param apellidos Apellidos del donante. Tipo std::string.
        \return El donante que encuentre. Tipo ed::Donante
    */
    virtual Donante buscaDonante(string nombre, string apellidos) = 0;
    
    /*!
        \brief Inserta un nuevo donante al final de la lista
        \param d Donante que se va a insertar en la lista pasado como
                referencia constante
    */
    virtual void insertaDonante(const Donante &d) = 0;
    
    /*!
        \brief Función que busca el donante proporcionado y lo borra
        \param d Donante para buscar y borrar
        \return Si no encuentra el donante devuelve false
    */
    virtual bool borrarDonante(Donante &d) = 0;
    
};
} // Fin namespace ed
#endif
