#ifndef DONANTEINTERFAZ_HPP
#define DONANTEINTERFAZ_HPP

#include <string>
#include <iostream>

using namespace std;

namespace ed {

class DonanteInterfaz {
    public:
    
    //! \name Funciones de modificación de Donante
    
		/*! 
		\brief Devuelve el nombre de un Donante
		\return nombre del Donante (tipo std::string)
		\pre El Donante debe existir
		\post Ninguna
		\sa getApellidos()
		*/
        virtual string getNombre() const = 0;
        
		/*! 
		\brief Asigna un valor nombre al nombre del Donante
		\param nombre de tipo std::string
		\pre El Donante debe existir
		\post Ninguna
		\sa setApellidos()
		*/
        virtual void setNombre(string nombre) = 0;

		/*! 
		\brief Devuelve los apellidos de un Donante
		\return apellidos del Donante (tipo std::string)
		\pre El Donante debe existir
		\post Ninguna
		\sa getNombre()
		*/
        virtual string getApellidos() const = 0;
        
		/*! 
		\brief Asigna un valor apellidos a los apellidos de un Donante
		\param apellidos de tipo std::string
		\pre El Donante debe existir
		\post Ninguna
		\sa setNombre()
		*/
        virtual void setApellidos(string apellidos) = 0;
        
        /*! 
		\brief Devuelve el grupo de un Donante
		\return grupo del Donante (tipo std::string)
		\pre El Donante debe existir
		\post Ninguna
		\sa getFactorRH()
		*/
        virtual string getGrupo() const = 0;
        
        /*! 
		\brief Asigna un valor grupo al grupo del Donante
		\param grupo de tipo std::string
		\pre El Donante debe existir
		\post Ninguna
		\return Duelve un valor booleano que indica si ha tenido éxito
		        la modificación de la variable
		\sa setFactorRH()
		*/
        virtual bool setGrupo(string grupo) = 0;
        
		/*! 
		\brief Devuelve el factorRH de un Donante
		\return factorRh del Donante (tipo std::string)
		\pre El Donante debe existir
		\post Ninguna
		\sa getGrupo()
		*/
        virtual string getFactorRH() const = 0;
        
        /*! 
		\brief Asigna un valor factor al factorRH del Donante
		\param factor de tipo std::string
		\pre El Donante debe existir
		\post Ninguna
		\return Duelve un valor booleano que indica si ha tenido éxito
		        la modificación de la variable
		\sa setGrupo()
		*/
        virtual bool setFactorRH(string factor) = 0;
        
        /*! 
		\brief Devuelve el número de donaciones hechas por el Donante
		\pre El Donante debe existir
		\post Ninguna
		\return Duelve un valor entero que representa el número de donaciones.
				Está comprendido en el rango [0, entero_positivo]
		\sa setDonaciones()
		*/
        virtual int getDonaciones() const = 0;
        
        /*! 
		\brief Asigna un valor num al atributo donaciones del Donante
		\param num tipo entero que representa el número de donaciones
		\pre El Donante debe existir
		\post Ninguna
		\return Duelve un valor booleano que indica si ha tenido éxito
		        la modificación de la variable
		\sa getDonaciones()
		*/
        virtual bool setDonaciones(int num) = 0;
        
		/*! 
		\brief Asigna a un Donante nombre, apellidos, grupo y factorRh leídos
		 		desde el teclado
		\pre El Donante debe existir
		\post Ninguna
		\sa getNombre(), getApellidos(), getGrupo(), getFactorRH()
		*/
        virtual void leerDonante() = 0;
        
        /*! 
		\brief Escribe por pantalla los datos de un Donante. De la forma:\n
				\tApellidos, Nombre\n \tGrupo: grupo\n \tFactorRH: factorRH\n
		\pre El Donante debe existir
		\post Ninguna
		\sa setNombre(), setApellidos(), setGrupo(), setFactorRH()
		*/
        virtual void escribirDonante() = 0;

};
}// Fin namespace ed
#endif
