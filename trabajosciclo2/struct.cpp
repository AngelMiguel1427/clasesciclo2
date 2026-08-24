//retroalimentacion de structs
#include <iostream>
using namespace std;
struct direccion{
    string calle;
    string ciudad;
};

struct persona{
    string nombre;
    int edad;
    direccion direccion;
};
// DIRECCION ES UN STRUCT DENTRO DE PERSONA, SE PUEDE ACCEDER A SUS ATRIBUTOS CON EL PUNTO

int main(){
    persona p1;
    p1.nombre = "Juan";
    p1.edad = 25;
    p1.direccion.calle = "Calle 123";
    p1.direccion.ciudad = "Ciudad ABC";
    cout << "Nombre: " << p1.nombre << endl;
    cout << "Edad: " << p1.edad << endl;
    cout << "Calle: " << p1.direccion.calle << endl;
    cout << "Ciudad: " << p1.direccion.ciudad << endl;
}