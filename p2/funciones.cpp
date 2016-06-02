#include "funciones.hpp"
#include "donantes.hpp"
namespace ed {

/*! 
    \brief Detiene la ejecución del programa hasta que el usuario presione la
            la tecla ENTER. Además se lo indica mediante un mensaje en la parte
            inferior de la pantalla. 
            Puede recibir un parámetro cuyo valor por
            defecto es 0. En este caso dejará no borrará el contenido del
            terminal antes de imprimir el mensaje. En caso de que valga 1,
            si lo borrará.
	\params opc Si vale 1, borrará la pantalla pantalla antes de seguir
	\return Nada
*/
void esperarUsuario(int opc) {

    if (opc == 1) 
        BORRAR;
        
    LUGAR(23,25);
    printf("pulse ");
    SUBRAYADO;
    printf("ENTER");
    APAGA;
    printf(" para ");
    INVERSO;
    printf("continuar");
    APAGA;
    getchar();
}

void cargarLista(Donantes& lista) {
    string nombre_fichero;
    
    LUGAR(10,10);
    printf("Nombre del fichero (lista-donantes.txt): ");
    cin >> nombre_fichero;
    
    BORRAR;
    
    // Comprueba si existe el fichero, si no existe vuelve sin hacer nada
    ifstream fichero(nombre_fichero);
    if ( !fichero.is_open() ) {
        LUGAR(10,10);
        INVERSO;
        printf("No existe el fichero");
        APAGA;
        getchar();
        return;
    }
    fichero.close();
    getchar();
    
    LUGAR(10,10);
    printf("Se lee la lista del fichero ");
    SUBRAYADO;
    printf("%s", nombre_fichero.c_str());
    APAGA;
    
    Donantes lista_aux("lista-donantes.txt");
    lista = lista_aux;
}

void grabarLista(Donantes& lista) {
    
    if (lista.estaVacia()) {
        LUGAR(10,10);
        printf("Operación inválida, la lista está vacía.");
        return;
    }
    
    string nombre_fichero;
    
    LUGAR(10,10);
    printf("Nombre del fichero (lista-donantes.txt): ");
    cin >> nombre_fichero;
    
    BORRAR;
    
    int n_donantes = lista.getNumeroDonantes();
    
    ofstream archivo(nombre_fichero.c_str());
    if ( archivo.is_open() ) {
        Donante d;
        for (int i = 0; i < n_donantes; i++) {
            d = lista.getDonante(i);
            
            archivo << d.getApellidos() << ",";
            archivo << d.getNombre() << ",";
            archivo << d.getGrupo() << ",";
            archivo << d.getFactorRH() << "\n";
            
        }
        archivo.close();

    } else {
        LUGAR(10,10);
        printf("Error escribiendo la lista");
        return;
    }
    
    LUGAR(10,10);
    printf("Se escribe la lista en el fichero ");
    SUBRAYADO;
    printf("%s", nombre_fichero.c_str());
    APAGA;
    return;
    

}

void insertarDonante(Donantes& lista) {
    LUGAR(0,10);
    printf("Introduce los datos del donante:");
    LUGAR(0,12);
    
    LUGAR(10,12);
    Donante d;
    
    d.leerDonante();
    lista.insertaDonante(d);
    
    BORRAR;
    LUGAR(10,10);
    cout << "Donante insertado";
}

void modificaDonante(Donantes& lista) {
    
    if (lista.estaVacia()) {
        LUGAR(10,10);
        printf("Operación inválida, la lista está vacía.");
        return;
    }
    
    string nombre, apellidos;

    LUGAR(10,10);
    SUBRAYADO;
    printf("Introduce los datos del donante:");
    APAGA;
    
    LUGAR(11,10);
    printf("Nombre: ");
    cin >> nombre;
    LUGAR(12,10);
    printf("Apellidos: ");
    cin.clear();
    cin.ignore(10000,'\n');
    getline(cin, apellidos);
    
    // Obtenemos la posición que ocupa el donante en la lista
    Donante d = lista.buscaDonante(nombre, apellidos);
    int pos = lista.posicionDonante(d); 
    
    if ( pos == -1 ) {
        BORRAR;
        LUGAR(10,10);
        printf("El donante no existe");
        return;
    }
    
    int opcion;
    // Menú de modificación de los datos del donante
    do {
        BORRAR;
        
        // Opciones del menu
        LUGAR(5,10);
        printf("Elige que atributo del donante modificar: ");
        LUGAR(7,10);
        printf("1) Nombre");
        LUGAR(8,10);
        printf("2) Apellidos");
        LUGAR(9,10);
        printf("3) Grupo Sanguíneo");
        LUGAR(10,10);
        printf("4) Factor RH");
        
        LUGAR(12,10);
        printf("0) Fin modificación");
        
        LUGAR(15,10);
        printf("Introduce la opcion -> ");
        scanf("%d", &opcion);
        getchar();
                
        BORRAR;       

            // Evalúa la opcion introducida y elige el comportamiento correspondiente
            switch (opcion) {
            
                case 0: // Acaba de modificar y vuelve al programa principal
                    LUGAR(10,10);
                    INVERSO;
                    printf("Fin modificación\n");
                    APAGA;
                    break;
                    
                case 1: {// Modifica el nombre
                    string str;
                    LUGAR(10,10);
                    printf("Introduce el nombre: ");
                    getline(cin, str);
                    cin.clear();
                    d.setNombre(str);
                    break;
                }
                case 2: {// Modificar los apellidos
                    string str;
                    LUGAR(10,10);
                    printf("Introduce los apellidos: ");
                    getline(cin, str);
                    cin.clear();
                    d.setApellidos(str);
                    break;
                }
                case 3: {// Modifica el grupo
                    string str;
                    LUGAR(10,10);
                    printf("Introduce el nuevo grupo [0, A, B, AB]: ");
                    cin >> str;
                    d.setGrupo(str);
                    break;
                }
                case 4: {// Modifica el factorRH
                    string str;
                    LUGAR(10,10);
                    printf("Introduce el nuevo factorRH [negativo, positivo]: ");
                    cin >> str;
                    d.setFactorRH(str);
                    break;
                }      
                default: // Captura las opciones inválidas
                    BORRAR;
                    LUGAR(21,25);
                    printf("Opción incorrecta");
            }
            
        } while(opcion != 0);
        
    lista.actualizaDonante(pos, d);
    BORRAR;
    LUGAR(10,10);
    INVERSO;
    printf("Donante modificado");
    APAGA;
    d.escribirDonante();
    
    return;
}

void eliminaDonante(Donantes& lista) {
    if (lista.estaVacia()) {
        LUGAR(10,10);
        printf("Operación inválida, la lista está vacía.");
        return;
    }
    
    string nombre, apellidos;

    BORRAR;
    LUGAR(10,10);
    printf("Introduce los apellidos del donante: ");
    cin >> apellidos;
    LUGAR(12,10);
    printf("Introduce el nombre: ");
    cin >> nombre;
    
    Donante d = lista.buscaDonante(nombre, apellidos);
    Donante vacio;
    if ( d == vacio ) {
        BORRAR;
        LUGAR(10,10);
        printf("El donante no existe");
    } else {
        lista.borrarDonante(d);
        BORRAR;
        LUGAR(10,10);
        printf("Donante borrado");
    }
    return;
}

} // Fin namespace ed
