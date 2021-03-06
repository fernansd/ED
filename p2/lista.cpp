#include "lista.hpp"

namespace ed {

/*
 *  Parte privada
 */

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
    if (pos_ == 0) {
        cursor_ = head_->getNext();
        pos_++;
        return true;
    }

    assert(cursor_ != nullptr);
    if ( cursor_->getNext() == nullptr )
        return false;
        
    cursor_ = cursor_->getNext();
    pos_++;
    return true;
}

/*! 
\brief Mueve el cursor de la lista al elemento anterior al cual apunta
        actualmente el cursor.
\warning Método privado
\return Valor booleano que valdrá false, si ya está el cursor en el inicio
\post El cursor debe habe retrocedido una posición o devolver false
        si ya está en la cabeza de la lista
*/
template <class T>
bool Lista<T>::prev() {
    if ( cursor_ == head_ )
        return false;
        
    cursor_ = cursor_->getPrev();
    pos_--;
    return true;
}

/*
 *  Parte pública
 */


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
bool Lista<T>::setPos(int pos) {
    if ( pos >= size_ || pos < 0 ) {
        return false;
    } else {
        this->pos_ = pos;
        return true;
    }
}

template <class T>
bool Lista<T>::goTo(int pos) {

    // El cursor ya está en la posición proporcionada
    if ( pos == pos_ )
        return true;
    // La posición proporcionada está fuera de los límites
    if ( pos >= size_ || pos < 0 )
        return false;
         
    if ( pos > pos_ ) {
        while ( this->getPos() != pos ) {
            next();
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
    
    this->setPos(0);
    // Situa el cursor para comenzar desde el principio de la lista
    cursor_ = head_;
    
    // Pasa al node siguiente hasta que llegue al final de la lista
    // o encuentre un nodo que coincida con el parámetro
    do {
        if ( *(cursor_->getItem()) == item ) {
            encontrado = true;
            break;
        }
    } while ( next() );
    
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
    
    // Lista vacía
    if (cursor_ == nullptr) {
        cursor_ = new Node<T>(nullptr, nullptr, new T(item) );
        head_ = cursor_;
    }
    
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
    
    // Lista vacía
    if (cursor_ == nullptr) {
        cursor_ = new Node<T>(nullptr, nullptr, new T(item) );
        head_ = cursor_;
    }
    
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
        delete cursor_;
        cursor_ = head_;
        
    // Cuando el nodo a eliminar es el último de la lista
    } else if ( cursor_->getNext() == nullptr ) {
        Node<T>* aux = cursor_->getPrev();
        aux->setNext(nullptr);
        delete cursor_;
        cursor_ = aux;
        pos_--;
        
    } else {
        Node<T>* aux = cursor_->getNext();
        aux->setPrev(cursor_->getPrev());
        aux = cursor_->getPrev();
        aux->setNext(cursor_->getNext());
        delete cursor_;
        cursor_ = aux;
        pos_--;
    }
    
    // Disminuimos el tamaño en 1
    size_--;
}
        
} // Fin namespace ed
