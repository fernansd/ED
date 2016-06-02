#ifndef DONANTES_HPP
#define DONANTES_HPP

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#include "donantesInterfaz.hpp"
#include "donante.hpp"
#include "lista.hpp"

using namespace std;

namespace ed {

/*!
    \class Donantes donantes.hpp "./donantes.hpp"
    \brief Clase que implementa la interfaz abstracta DonantesInterfaz. 
            Se trata de una lista formada por elementos de tipo ed::Donante.
*/
class Donantes : public DonantesInterfaz {
    private:
        /// Lista de donantes donde se guarda los datos
        Lista<Donante> lista_;
        
    public:
        Donantes() {}
        
        /*!
            \brief Constructor de la clase Donantes que permite rellenar la
                    lista con los datos donantes almacenados en un fichero.
            \param archivo_donantes Nombre del archivo donde están los datos
        */
        Donantes(string archivo_donantes);
        
        /*!
            \brief Comprueba si la lista contiene elementos.
            \return Devuelve true si la lista está vacía       
        */
        bool estaVacia() const;
    
        /*!
            \brief Función que busca un donante en la lista por nombre y lo
                    devuelve 
            \param nombre Nombre del donante. Tipo std::string
            \param apellidos Apellidos del donante. Tipo std::string.
            \return El donante que encuentre. Tipo ed::Donante
        */
        Donante buscaDonante(string nombre, string apellidos);

        /*!
            \brief Inserta un nuevo donante al final de la lista
            \param d Donante que se va a insertar en la lista pasado como
                    referencia constante
        */
        void insertaDonante(const Donante &d);
        
        /*!
            \brief Obtiene el donante que se encuentra en la posición dada
            \param pos Posición donde está el donante que se quiere
            \return Donante que está en la posición pos
        */
        Donante getDonante(const int pos);

        /*!
            \brief Función que busca el donante proporcionado y lo borra
            \param d Donante para buscar y borrar
            \return Si no encuentra el donante devuelve false
        */
        bool borrarDonante(Donante &d);
        
        /*!
            \brief Función que devuelve la posición dentro de la lista del
                    donante que recibe como parámetro
            \param d Donante cuya posición se desea saber
            \return Posición del donante. Si no se encuentra devuelve -1.
        */
        int posicionDonante(const Donante &d);
        
        /*!
            \brief Función que se encarga de actualizar los datos del donante
                    en la posición proporcionada con los del donante pasado.
            \param posicion_donante Posición a actualizar
            \param d Donante con los datos que se desean actualizar
        */
        void actualizaDonante(int posicion_donante, const Donante &d);
        
        /// Función que escribe por pantalla la lista de donantes
        void escribirDonantes();
        
        /// Función que permite insertar donantes nuevos en la lista
        void leerDonantes();
        
        /// Devuelve el número de donantes que hay en la lista
        int getNumeroDonantes() { return lista_.size(); }
};
} // Fin namespace ed
#endif
