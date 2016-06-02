#ifndef DONANTE_HPP
#define DONANTE_HPP

#include "donanteInterfaz.hpp"

namespace ed {

/*!
    \class Donante donante.hpp "./donante.hpp"
    \brief Clase que implementa la interfaz abstracta DonanteInterfaz.
            Esta clase representa un donante de sangre, para lo cual almacena
            algunos datos personales como el nombre y el tipo de sangre.
*/
class Donante : public DonanteInterfaz {

    private:
        /// Datos sobre el nombre del donante [nombre, apellidos]
        string nombre_, apellidos_;
        /// Datos sobre el grupo sanguíneo del donante
        string grupo_;
        /// Datos sobre el factor RH del donante
        string factor_;
    
    public:
        /*!
            \brief Constructor de la clase Donante, permite como parámetros
                    opcionales: nombre, apellidos, grupo sanguíneo y factor RH.
                    Todos de tipo std::string.
            \param nombre Nombre del donante. Valor por defecto "-".
            \param apellidos Apellidos del donante. Valor por defecto "-".
            \param grupo Grupo sanguíneo del donante. Valor por defecto "-".
            \param factor Factor RH del donante. Valor por defecto "-".
        */
        Donante(string nombre = "-", string apellidos = "-", string grupo = "-",
            string factor = "-") {
            
            if ( grupo != "0" && grupo != "A" && grupo != "B" && grupo != "AB" 
                && grupo != "-")
                grupo = "";            
            
            if (factor != "negativo" && factor != "positivo" && factor != "-") 
                factor = "";            
            
            nombre_ = nombre;
            apellidos_ = apellidos;
            grupo_ = grupo;
            factor_ = factor;
        }
        
        /*!
            \brief Constructor de copia de la clase ed::Donante.
                    Solo necesita copiar los miembros uno a uno.
        */
        Donante(const Donante &d) {
            nombre_ = d.getNombre();
            apellidos_ = d.getApellidos();
            grupo_ = d.getGrupo();
            factor_ = d.getFactorRH();
        }
        
        ~Donante() {}
        
        /*! 
		\brief Devuelve el nombre de un Donante
		\return nombre del Donante (tipo std::string)
		\pre El Donante debe existir
		\post Ninguna
		\sa getApellidos()
		*/
        string getNombre() const { return nombre_; }
        
        /*! 
		\brief Asigna un valor nombre al nombre del Donante
		\param nombre de tipo std::string
		\pre El Donante debe existir
		\post Ninguna
		\sa setApellidos()
		*/
        void setNombre(string nombre) { nombre_ = nombre; }

        /*! 
		\brief Devuelve los apellidos de un Donante
		\return apellidos del Donante (tipo std::string)
		\pre El Donante debe existir
		\post Ninguna
		\sa getNombre()
		*/
        string getApellidos() const { return apellidos_; }
        
        /*! 
		\brief Asigna un valor apellidos a los apellidos de un Donante
		\param apellidos de tipo std::string
		\pre El Donante debe existir
		\post Ninguna
		\sa setNombre()
		*/
        void setApellidos(string apellidos) { apellidos_ = apellidos; }
        
        /*! 
		\brief Devuelve el grupo de un Donante
		\return grupo del Donante (tipo std::string)
		\pre El Donante debe existir
		\post Ninguna
		\sa getFactorRH()
		*/
        string getGrupo() const { return grupo_; }
        
        /*! 
		\brief Asigna un valor grupo al grupo del Donante
		\param grupo de tipo std::string
		\pre El Donante debe existir
		\post Ninguna
		\return Duelve un valor booleano que indica si ha tenido éxito
		        la modificación de la variable
		\sa setFactorRH()
		*/
        bool setGrupo(string grupo);
        
        /*! 
		\brief Devuelve el factorRH de un Donante
		\return factorRh del Donante (tipo std::string)
		\pre El Donante debe existir
		\post Ninguna
		\sa getGrupo()
		*/
        string getFactorRH() const { return factor_; }
        
        /*! 
		\brief Asigna un valor factor al factorRH del Donante
		\param factor de tipo std::string
		\pre El Donante debe existir
		\post Ninguna
		\return Duelve un valor booleano que indica si ha tenido éxito
		        la modificación de la variable
		\sa setGrupo()
		*/
        bool setFactorRH(string factor);
        
        /*! 
		\brief Asigna a un Donante nombre, apellidos, grupo y factorRh leídos
		 		desde el teclado
		\pre El Donante debe existir
		\post Ninguna
		\sa getNombre(), getApellidos(), getGrupo(), getFactorRH()
		*/
        void leerDonante();
        
        /*! 
		\brief Escribe por pantalla los datos de un Donante. De la forma:\n
				Apellidos, Nombre\n Grupo: grupo\n FactorRH: factorRH\n
		\pre El Donante debe existir
		\post Ninguna
		\sa setNombre(), setApellidos(), setGrupo(), setFactorRH()
		*/
        void escribirDonante();
        
        /// Sobrecarga del operador de asignación
        Donante &operator=(Donante const &d);
        
        /// Sobrecarga del operador de comparación ==
        bool operator==(Donante const &d) const;
        
        /*!
            \brief Sobrecarga del operador de comparación <=.
                    Realiza una comparación lexicográfica
        */
        friend bool operator<=(Donante const &d1, Donante const &d2);
        
        /*!
            \brief Sobrecarga del operador >>. Permite la lectura de un donante
                    por teclado interaccionando con el usuario.
        */
        friend istream &operator>>(istream &stream, Donante &d);
        
        /*!
            \brief Sobrecarga del operador <<. Permite imprimir por pantalla 
                    los datos del donante.
        */
        friend ostream &operator<<(ostream &stream, Donante &d);
};
}
#endif
