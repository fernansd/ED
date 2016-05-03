#ifndef DONANTE_HPP
#define DONANTE_HPP

#include "donanteInterfaz.hpp"

namespace ed {

/*! 
\brief Clase que representa los datos de un donante, implementa la interfaz
        definida en DonanteInterfaz
\sa ed::DonanteInterfaz
*/
class Donante : public DonanteInterfaz {

    private:
        /// Datos personales del donante
        string nombre_, apellidos_, grupo_, factor_;
        /// Número de donaciones que el donante ha realizado
        int donaciones_;
    
    public:
    	/*!
			\brief Contructor por defecto. Admite inicialización de los valores,
			        aunque incluye valores por defecto para todos los parametros.
			\param nombre Nombre del donante. Por defecto "-".
			\param apellidos Apellidos del donante. Por defecto "-".
			\param grupo Grupo sanguíneo del donante. Por defecto "-".
			\param factor Factor RH del donante. Por defecto "-".
			\param donaciones Número de donanciones realizadas. Por defecto "0".
		    \return Nada
		*/
        Donante(string nombre = "-", string apellidos = "-", string grupo = "-",
            string factor = "-", int donaciones = 0) {
            
            if ( grupo != "0" && grupo != "A" && grupo != "B" && grupo != "AB" 
                && grupo != "-")
                grupo = "-";            
            
            if (factor != "negativo" && factor != "positivo" && factor != "-") 
                factor = "-";            
            
            if (donaciones < 0)
            	donaciones = 0;
            
            nombre_ = nombre;
            apellidos_ = apellidos;
            grupo_ = grupo;
            factor_ = factor;
            donaciones_ = donaciones;
        }
        
        Donante(const Donante &d) {
            nombre_ = d.getNombre();
            apellidos_ = d.getApellidos();
            grupo_ = d.getGrupo();
            factor_ = d.getFactorRH();
            donaciones_ = d.getDonaciones();
        }
        
		/*!
			\brief Obtiene el nombre del donante
			\return Devuelve el nombre del donante
			\sa setNombre()
		*/
        string getNombre() const { return nombre_; }

		/*!
			\brief Permite cambiar el valor del nombre del donante
			\param nombre Valor para el nuevo nombre
			\return Nada
			\sa getNombre()
		*/
        void setNombre(string nombre) { nombre_ = nombre; }

		/*!
			\brief Devuelve los apellidos del donante
			\return Devuelve los apellidos con tipo std::string
			\sa setApellidos()
		*/
        string getApellidos() const { return apellidos_; }

		/*!
			\brief Permite cambiar los apellidos del donante
			\param apellidos Valor para los nuevos apellidos
			\return Nada
			\sa getApellidos()
		*/        
        void setApellidos(string apellidos) { apellidos_ = apellidos; }

		/*!
			\brief Devuelve el grupo sanguíneo del donante
			\return Devuelve el grupo sanguíneo con tipo std::string
			\sa setGrupo()
		*/        
        string getGrupo() const { return grupo_; }

		/*!
			\brief Permite cambiar el grupo sanguíneo del donante. Los valores
			        posibles son: 0, A, B, AB
			\param grupo Valor para cambiar el grupo sanguíneo
			\return Devuelve en caso de cambiar el valor devuelve true
			\sa getGrupo()
		*/        
        bool setGrupo(string grupo);

		/*!
			\brief Devuelve el factor RH del donante
			\return Devuelve el factor RH con tipo std::string
			\sa setFactorRH()
		*/        
        string getFactorRH() const { return factor_; }

		/*!
			\brief Permite cambiar el valor del factor RH del donante.
			        Los valores permitidos son: "negativo" y "positivo"
			\param factor Valor para cambiar el factor RH
			\return Devuelve true si cambia el valor con exito
			\sa getFactorRH()
		*/        
        bool setFactorRH(string factor);

		/*!
			\brief Devuelve el número de donaciones realizadas por el donante
			\return Devuelve el número de donaciones con tipo int
			\sa setDonaciones()
		*/        
        int getDonaciones() const { return donaciones_; }

		/*!
			\brief Permite cambiar el número de donaciones realizadas por un
			        donante, solo los valores positivos son válidos
			\param num Valor para el número de donaciones
			\return Devuelve true en caso de cambiar el valor
		*/        
        bool setDonaciones(int num);

		/*!
			\brief Permite la lectura de los datos de un donante por teclado.
			        Usa como implementación la sobrecarga del operador>>
			\return Nada
			\sa escribirDonante(), operator>>
		*/        
        void leerDonante();

		/*!
			\brief Escribe los datos del donante por pantalla. Usa como
			        implementación la sobrecarga del operador<<
			\return Nada
			\sa leerDonante(), operator<<
		*/        
        void escribirDonante();

		/*!
			\brief Sobrecarga del operador de asignación. Realizar la copia
			        campo por campo. Permite encadenar asignaciones al devolver
			         referencia.
			\return Devuelve una referencia al donante modificado
		*/        
        Donante &operator=(Donante const &d);

		/*!
			\brief Operador de comparación de igualdad. Compara todos los campos
			        excepto el de donaciones
			\return Devuelve un valor booleano resultado de la comparación
			\sa operator<=, operator>
		*/        
        bool operator==(const Donante &d) const;

		/*!
			\brief La comparación tiene éxito si el donante izquierdo es menor
			        o igual que el donante derecho, según una comparación
			         lexicográfica.
			\return Devuelve true si la condición se cumple
			\sa operator==, operator>
		*/        
        friend bool operator<=(Donante const &d1, Donante const &d2);

		/*!
			\brief La comparación tiene éxito si el donante izquierdo es mayor
			        que el donante derecho, según una comparación       lexicográfica.
			\pre El montículo no está vacío
			\return Devuelve true si la condición se cumple
			\sa operator==, operator<=
		*/        
        friend bool operator>(Donante const &d1, Donante const &d2);

		/*!
			\brief Lee por pantalla de forma interactiva los datos del donante
			\return Devuelve un stream de entrada
			\sa leerDonante(), operator<<
		*/        
        friend istream &operator>>(istream &stream, Donante &d);

		/*!
			\brief Escribe por pantalla los datos del donante
			\return Devuelve un stream de salida
			\sa escribirDonante(), operator>>
		*/        
        friend ostream &operator<<(ostream &stream, Donante &d);
};
}
#endif
