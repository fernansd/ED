#include "lista.hpp"

#include "donante.hpp"
#include "donantes.hpp"

namespace ed {

    Donantes::Donantes(string archivo_donantes) {
        ifstream archivo(archivo_donantes.c_str());
        if ( archivo.is_open() ) {
            Donante d;
            string cadena;
            while ( getline(archivo, cadena, ',') ) {
                d.setApellidos(cadena);
                getline(archivo, cadena, ',');
                d.setNombre(cadena);
                getline(archivo, cadena, ',');
                d.setGrupo(cadena);
                getline(archivo, cadena, ',');
            }
            archivo.close();

        } else {
            cout << "Error leyendo archivo de donantes\n" <<
                    "La lista de donantes comenzará vacía\n" << endl;
        }
    }

    bool Donantes::estaVacia() const {
        return lista_.isEmpty();
    }

    Donante Donantes::buscaDonante(string nombre, string apellidos) const {
        // Donante variable auxiliar para comprobar el valor del donante
        Donante* aux;
        for (int i = 0; i < lista_.size(); i++) {
            lista_.goTo(i);
            aux = lista_.getItem();
            if ( aux->getNombre() == nombre && aux->getApellidos() == apellidos){
                return *aux;
            }
        }
        Donante d;
        return d;
    }

    void Donantes::insertaDonante(const Donante &d) {
        lista_.goTo(lista_.size()-1 );
        lista_.insertAfter(d);
    }

    void Donantes::borrarDonante(Donante &d) {
        if ( lista_.search(d) )
            lista_.removeItem();
        else
            cout << "Error borrando donante, no existe" << endl;
    }
    
    /// Devuelve -1 si no encuentra el donante
    int Donantes::posicionDonante(const Donante &d) const {
        if ( lista_.search(d) )
            return lista_.getPos();
        else
            return -1;
    }
    
    void Donantes::actualizaDonante(int posicion_donante, const Donante &d) {
        lista_.goTo(posicion_donante);
        
        Donante* aux = lista_.getItem();
        *aux = d;
    }
    
    void Donantes::escribirDonantes() const {
        Donante* aux;
        cout << "Lista de donantes:\n" << endl;
        for (int i = 0; i < lista_.size(); i++) {
            lista_.goTo(i);
            aux = lista_.getItem();
            
            aux->escribirDonante();
        }
    }
    
    void Donantes::leerDonantes() {
        Donante d;
        string opc = "no";
        do {
            d.leerDonante();
            insertaDonante(d);
            cout << "¿Quieres introducir otro? (s/n): ";
            cin >> opc;
        } while ( opc != "s" && opc != "S");
        
        
    }

} // Fin namespace ed
