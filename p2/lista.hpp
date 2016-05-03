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

/*! 
\brief Comprueba si la lista está vacía.
\pre Ninguna
\warning Método privado
\return Valor booleano que indica el estado de la lista.
\post Devuelve true si size() == 0
\post Devuelve false si size() > 0
*/
template <class T>
bool Lista<T>::next() {
    if ( cursor_->getNext() == nullptr )
        return false;
        
    cursor_ = cursor_->getNext();
    pos_++;
}

/*! 
\brief Comprueba si la lista está vacía.
\pre Ninguna
\warning Método privado
\return Valor booleano que indica el estado de la lista.
\post Devuelve true si size() == 0
\post Devuelve false si size() > 0
*/
template <class T>
bool Lista<T>::prev() {
    if ( cursor_->getPrev() == nullptr )
        return false;
        
    cursor_ = cursor_->getPrev();
    pos_--;
}

/*! 
\brief Comprueba si la lista está vacía.
\pre Ninguna
\return Valor booleano que indica el estado de la lista.
\post Devuelve true si size() == 0
\post Devuelve false si size() > 0
*/
template <class T>
bool Lista<T>::isEmpty() const {
    if (size_ == 0)
        return true;
    else 
        return false;
}

template <class T>
bool Lista<T>::goTo(int pos) {

    // El cursor ya está en la posición proporcionada
    if ( pos == pos_ )
        return true;
    // La posición proporcionada está fuera de los límites
    if ( pos >= size_ || pos < 0 )
        return false;
        
    if ( pos < pos_ ) {
        while ( this->getPos() != pos ) {
            this->next();
        }
        
    } else {
        while ( this->getPos() != pos ) {
            prev();
        }
    }
    
    return true; // Finaliza con éxito
    
}

template <class T>
bool Lista<T>::search(T item) {
    // Indica si se ha encontrado el nodo pasado por parámetro
    bool encontrado = false;
    
    // Guarda el estado de la lista para restablecerlo al acabar
    int prev_pos = this->getPos();
    
    // Situa el cursor para comenzar desde el principio de la lista
    cursor_ = head_;
    
    // Pasa al node siguiente hasta que llegue al final de la lista
    // o encuentre un nodo que coincida con el parámetro
    while ( next() ) {
        if ( *cursor_ == item )
            encontrado;
            break;
    }
    
    // Devuelve la lista a su estado anterior
    this->goTo(prev_pos);
    
    return encontrado;
}

template <class T>
T* Lista<T>::getPrev() const {
    
    if ( cursor_->getPrev() == nullptr )
        return nullptr;
        
    Node<T>* aux = cursor_->getPrev();
        
    return aux->getItem();
}

template <class T>
T* Lista<T>::getNext() const {
    
    if ( cursor_->getNext() == nullptr )
        return nullptr;
        
    Node<T>* aux = cursor_->getNext();
    
    return aux->getItem();
}

template <class T>
void Lista<T>::insertBefore(T const& item) {
    
    // En el caso de que se inserte delante del nodo cabeza de lista
    if ( cursor_ == head_ ) {
        head_ = new Node<T>(nullptr, head_, new T(item));
        
    } else {    
        Node<T>* aux; // Variable auxiliar para referenciar el nodo anterior
        aux = cursor_->getPrev();
        
        // Crea el nuevo nodo y cambia el valor del puntero en el nodo anterior
        aux->setNext(new Node<T>(aux, cursor_, new T(item) ));
        
        // Cambia el valor del puntero previo en el nodo siguiente al insertado
        cursor_->setPrev(aux->getNext());
    
    }
    
    // Al insertar un nodo se incrementa el tamaño. Ya que se ha insertado 
    // antes, incrementamos el valor de la posición del cursor en 1
    size_++;
    pos_++;
}

template <class T>
void Lista<T>::insertAfter(T const& item) {
    
    // En el caso de que inserte después del último nodo de la lista
    if ( cursor_->getNext() == nullptr ) {
        
        cursor_->setNext(new Node<T>(cursor_, nullptr, new T(item) ));
        
    } else {
    
        // Cambia el valor del puntero next en el nodo del cursor al del nuevo
        // nodo creado. Cuyo puntero prev es el del cursor y next es el anterior
        // que tenía el nodo del cursor
        Node<T>* aux = cursor_->getNext();
        aux->setPrev(new Node<T>(cursor_, aux, new T(item) ));
        cursor_->setNext(aux->getPrev());
        
    }
    
    // Incrementa el tamaño al insertar aunque la posición del cursor
    // permanece igual ya que se ha insertado después del cursor
    size_++;
}

template <class T>
void Lista<T>::removeItem() {

    // Si el nodo a eliminar es la cabeza
    if ( cursor_ == head_ ) {
        head_ = cursor_->getNext();
        head_->setPrev(nullptr);
        delete *cursor_;
        cursor_ = head_;
        
    // Cuando el nodo a eliminar es el último de la lista
    } else if ( cursor_->getNext() == nullptr ) {
        Node<T>* aux = cursor_->getPrev();
        aux->setNext(nullptr);
        delete *cursor_;
        cursor_ = aux;
        pos_--;
        
    } else {
        Node<T>* aux = cursor_->getNext();
        aux->setPrev(cursor_->getPrev());
        aux = cursor_->getPrev();
        aux->setNext(cursor_->getNext());
        delete *cursor_;
        cursor_ = aux;
        pos_--;
    }
    
    // Disminuimos el tamaño en 1
    size_--;
}
} // Fin namespace ed
#include "lista.cpp"
#endif

