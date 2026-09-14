/* Intercambio de valores: se define un struct Persona con edad y altura; una funcion recibe dos personas mediante referencias y determina cual es mayor, Intercambiando sus edades
si la primera es menor */
#include <iostream>
using namespace std;

struct Persona{
    int edad;
    float altura;
};

void intercambiarEdades(Persona& p1, Persona& p2) {
    if (p1.edad < p2.edad) {
        int temp = p1.edad;
        p1.edad = p2.edad;
        p2.edad = temp;
    }
}

int main(){
    Persona p1 = {25, 1.75};
    Persona p2 = {30, 1.80};
    
    cout << "Antes del intercambio:" << endl;
    cout << "Persona 1 - Edad: " << p1.edad << ", Altura: " << p1.altura << endl;
    cout << "Persona 2 - Edad: " << p2.edad << ", Altura: " << p2.altura << endl;

    intercambiarEdades(p1, p2);

    cout << "Despues del intercambio:" << endl;
    cout << "Persona 1 - Edad: " << p1.edad << ", Altura: " << p1.altura << endl;
    cout << "Persona 2 - Edad: " << p2.edad << ", Altura: " << p2.altura << endl;

    return 0;
}