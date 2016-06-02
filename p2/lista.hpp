#ifndef LISTA_HPP
#define LISTA_HPP

#include <cassert>

#include "listaInterfaz.hpp"

using namespace std;

namespace ed {

template <class T> class listaInterfaz;

/*!
    \class Node lista.hpp "./lista.hpp"
    \brief Clase que representa un nodo dentro de una lista doblemente
            enlazada. Para ello posee dos punteros (anterior y siguiente),
            así como un campo que permite almacenar datos de cualquier tipo.
    \warning Esta clase está diseñada para integrarse dentro de la clase Lista
*/
template < class T >
class Node {

    private:
        /// Puntero hacia un elemento de tipo T
        T* item_;
        /// Puntero hacia un nodo anterior de tipo Node<T>
        Node<T>* prev_;
        /// Puntero hacia un nodo posterior de tipo Node<T>
        Node<T>* next_;
        
    public:
        /*!
            \brief Constructor por defecto de la clase Node.
                    Permite parámetros opcionales para todos sus campos.
            \param prev Puntero hacia nodo anterior. Valor por defecto nullptr
            \param next Puntero a nodo posterior. Valor por defecto nullptr
            \param item Puntero hacia un elemento tipo T. Valor por defecto nullptr
        */
        Node(Node<T>* prev = nullptr, Node<T>* next = nullptr, T* item = nullptr) {
            item_ = item;
            prev_ = prev;
            next_ = next;
        }
        
        ~Node() { delete item_; }
        
        /// Devuelve el puntero al siguiente
        Node<T>* getNext() const { return next_; }
        
        /// Devuelve el puntero al anterior
        Node<T>* getPrev() const { return prev_; }
        
        /// Devuelve un puntero a un elemento tipo T
        T* getItem() const { return item_; }
        
        /// Cambia el valor del puntero al siguente
        void setNext(Node<T>* next) { next_ = next; }
        
        /// Cambia el valor de puntero al anterior
        void setPrev(Node<T>* prev) { prev_ = prev; }
        
        /// Cambia el valor del puntero al dato tipo T
        void setItem(T* item) { item_ = item; }
};

/*!
    \class Lista lista.hpp "./lista.hpp"
    \brief Clase que implementa la interfaz abstraca listaInterfaz. La clase
            se trata de una lista doblemente enlazada con cursor. Y permite el
            uso de cualquier tipo de dato como elemento de la lista.
*/
template <class T> 
class Lista : public listaInterfaz<T> { 
   
    private:
        /// Cursor de posición de la lista
        int pos_;
        /// Número de elementos en la lista
        int size_;
        /// Cursor de la lista
        Node<T>* cursor_;
        /// Puntero que apunta al primer nodo
        Node<T>* head_;
        /*!
            \brief Permite mover el cursor a una posición más.
                    Es seguro usarlo al final de la lista (no se mueve).
            \return Si no se mueve devuelve false
        */
        bool next();
        
        /*!
            \brief Permite mover el cursor a una posición anterior.
                    Es seguro usarlo al principio de la lista (no se mueve).
            \return Si no se mueve devuelve false
        */
        bool prev();
    
    public:
        Lista() {
            cursor_ = nullptr;
            head_ = nullptr;
            pos_ = 0;
            size_ = 0;
        }
        
        /*! 
        \brief Devuelve el número de elementos en la lista.    
        \note Los parámetros tienen valores por defecto
        \pre Ninguna
        \post El valor devuelto está comprendido en [0, capacity()]
        */
        int size() const { return size_; }
	
        /*! 
        \brief Comprueba si la lista está vacía.
        \pre Ninguna
        \return Valor booleano que indica el estado de la lista.
        \post Devuelve true si size() == 0
        \post Devuelve false si size() > 0
        */
        bool isEmpty() const;
        
        /*! 
		\brief Devuelve la posición del cursor
		\return Posición del cusor tipo entero
		*/
        int getPos() const { return pos_; }
        
        /*! 
		\brief Modifica la posición del cursor
		\param pos Posición a la cual cambiar pos_
		\return Devuelve true si es una posición válida
		*/
        bool setPos(int pos);
        
        /*! 
		\brief Mueve el puntero a la posición proporcionada
		\param pos Posición donde mover el cursor
		\return Devuelve true si la posición es válida
		*/
        bool goTo(int pos);

        /*!
		\brief Situa el puntero en el elemento proporcionado
		\param item Elemento a buscar en la lista
		\return Devuelve false si no lo encuentra
		*/
        bool search(T item);

        /*!
		\brief Devuelve un puntero al elemento donde apunta el cursor
		\return Devuelve el puntero
		*/
        T* getItem() const { return cursor_->getItem(); }

        /*!
		\brief Devuelve un puntero al elemento siguiente donde apunta el cursor
		\return Devuelve el puntero
		*/
        T* getPrev() const;

        /*!
		\brief Devuelve unpuntero al elemento anterior donde apunta el cursor
		\return Devuelve el puntero
		*/
        T* getNext() const;

        /*!
		\brief Inserta el elemento proporcionado antes del elemento al cual
		        apunta el cursor
		\param item Elemento a insertar
		*/
        void insertBefore(T const& item);

        /*!
		\brief Inserta el elemento proporcionado después del elemento al cual
		        apunta el cursor
		\param item Elemento a insertar
		*/
        void insertAfter(T const& item);

        /// Elimina el elemento al cual apunta el cursor
        void removeItem();


}; // Fin clase Lista
} // Fin namespace ed
#include "lista.cpp"
#endif

