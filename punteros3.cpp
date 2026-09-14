/* Buscar el mayor: Se define un struct Numero con un valor entero; una función
recibe un arreglo de estructuras mediante puntero y determina cuál contiene el
valor más grande, retornando un puntero hacia dicha estructura. */

#include <iostream>
using namespace std;

struct Numero{
    int valor;
};

Numero* buscarMayor(Numero* numeros, int size) {
    Numero* mayor = &numeros[0];
    for (int i = 1; i < size; ++i) {
        if (numeros[i].valor > mayor->valor) {
            mayor = &numeros[i];
        }
    }
    return mayor;
}

int main(){

    const int size = 5;
    Numero numeros[size] = {{10}, {25}, {15}, {30}, {20}};


    return 0;
}