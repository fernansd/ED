#include <sstream>
#include <fstream>

#include "lista.hpp"
#include "donante.hpp"
#include "donantes.hpp"

#include "macros.hpp"

using namespace std;

namespace ed {

    Donantes::Donantes(string archivo_donantes) {
        ifstream archivo(archivo_donantes.c_str());
        string linea;
        
        if ( archivo.is_open() ) {
            
            // Obtiene las líneas completas y luego extrae de ellas los datos
            while ( getline(archivo, linea) ) {
                Donante d;
                string valor;
                stringstream stream_linea(linea);
                
                // Obtiene de la línea leída cada uno de los valores necesarios
                getline(stream_linea, valor, ',');
                d.setApellidos(valor);
                getline(stream_linea, valor, ',');
                d.setNombre(valor);
                getline(stream_linea, valor, ',');
                d.setGrupo(valor);
                getline(stream_linea, valor, ',');
                d.setFactorRH(valor);
                
                // Añade el donante a la lista
                this->insertaDonante(d);
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

    Donante Donantes::buscaDonante(string nombre, string apellidos) {
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
        if (!(lista_.size() == 0)) {
            lista_.goTo(lista_.size()-1 );
        }
        lista_.insertAfter(d);
    }
    
    Donante Donantes::getDonante(const int pos) {

        lista_.goTo(pos);        
        Donante* d = lista_.getItem();
        
        lista_.goTo(0);
        
        return *d;
    }

    bool Donantes::borrarDonante(Donante &d) {
    
        if ( lista_.search(d) ) {
            lista_.removeItem();
            return true;
        } else {
            return false;
        }
    }
    
    /// Devuelve -1 si no encuentra el donante
    int Donantes::posicionDonante(const Donante &d) {
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
    
    void Donantes::escribirDonantes() {

        Donante* aux;
        SUBRAYADO;
        printf("Lista de donantes:\n");
        APAGA;
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
