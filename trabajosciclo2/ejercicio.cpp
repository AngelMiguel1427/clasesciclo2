#include <iostream>
using namespace std;
struct contacto{
    string nombre;
    string telefono;
    string correo;
}
const int contactos_maximos = 100; 
Contacto agenda[contactos_maximos];
int totalcontactos = 0;

void mostrarAgenda(Contacto agenda[], int n){
    cout << "Agenda de contactos:" << endl;
    if (n == 0){
        cout << "No hay contactos en la agenda." << endl;
        return;
    }
    for (int i = 0 ; i < n; i++){
        cout << "Nombre: " << agenda[i].nombre << endl;
        cout << "Telefono: " << agenda[i].telefono << endl;
        cout << "Correo: " << agenda[i].correo << endl;
    }
}
  
int agregarContacto(Contacto agenda[], int n){
    if (n >= contactos_maximos){
        cout << "La agenda esta llena." << endl;
        return n;
    }
    Contacto nuevoContacto;
    cout << "Ingrese el nombre: ";
    getline(cin>>ws, nuevoContacto.nombre);
    cout << "Ingrese el telefono: ";
    getline(cin, nuevoContacto.telefono);
    cout << "Ingrese el correo: ";
    getline(cin, nuevoContacto.correo); 

    agenda[n] = nuevoContacto;

    return n + 1;git
 
}

int buscarContacto(Contacto agenda[], int n, string nombre){
    for (int i = 0; i < n; i++){
        if (agenda[i].nombre == nombre){
            return i;
        }
    }
    //el for termino y jamas se eoncontro el contacto
    return -1;
}
void mostrarEncontrado(Contacto agenda[], int n){
    
void mostrarMenu(){
    cout << "Menu de opciones:" << endl;
    cout << "1. Agregar contacto" << endl;
    cout << "2. Buscar contacto" << endl;
    cout << "3. Mostrar agenda" << endl;
    cout << "4. Salir" << endl;

}
void ejecutaragenda(){
    int opcion;
    do{
        mostrarMenu();
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion){
            case 1:
                totalcontactos = agregarContacto(agenda, totalcontactos);
                break;
            case 2:
                string nombre;
                cout << "Ingrese el nombre del contacto a buscar: ";
                getline(cin>>ws, nombre);
                int indice = buscarContacto(agenda, totalcontactos, nombre);
                if (indice != -1){
                    cout << "Contacto encontrado:" << endl;
                    cout << "Nombre: " << agenda[indice].nombre << endl;
                    cout << "Telefono: " << agenda[indice].telefono << endl;
                    cout << "Correo: " << agenda[indice].correo << endl;
                } else {
                    cout << "Contacto no encontrado." << endl;
                }
                break;
            case 3:
                mostrarAgenda(agenda, totalcontactos);
                break;
            case 4:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);
}
int main (){

}
