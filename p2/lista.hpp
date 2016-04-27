#ifndef LISTA_HPP
#define LISTA_HPP

#include "listaInterfaz.hpp"

using namespace std;

namespace ed {

template <class T> class listaInterfaz;

template < class T >
class Node {

    private:
        T* item_;
        Node<T>* prev_;
        Node<T>* next_;
        
    public:
        Node(Node* prev = nullptr, Node* next = nullptr, T* item = nullptr) {
            item_ = item;
            prev_ = prev;
            next_ = next;
        }
        
        ~Node() { delete *item_; }
        
        Node* getNext() const { return next_; }
        
        Node* getPrev() const { return prev_; }
        
        T* getItem() const { return item_; }
        
        void setNext(Node* next) { next_ = next; }
        
        void setPrev(Node* prev) { prev_ = prev; }
        
        void setItem(T* item) { item_ = item; }
};

template <class T> 
class Lista : public listaInterfaz<T> { 
   
    private:
        int pos_, size_;
        Node<T>* cursor_;
        Node<T>* head_;
        bool next();
        bool prev();
    
    public:
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

        int getPos() const { return pos_; }

        bool goTo(int pos);

        bool search(T item);

        T* getItem() const { return cursor_->getItem(); }

        T* getPrev() const;

        T* getNext() const;

        void insertBefore(T const& item);

        void insertAfter(T const& item);

        void removeItem();


}; // Fin clase Lista
} // Fin namespace ed
#include "lista.cpp"
#endif

