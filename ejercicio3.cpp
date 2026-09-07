//intercambiar dados 10, 20, 30, 40, 50 a 50, 40, 30, 20, 10 con punteros

#include <iostream>
using namespace std;
void intercambiar(int *p, int cantidad){
    for(int i=0; i < cantidad/2; i++){//recorre la mitad del arreglo
        int temp = *(p + i); //almacena el valor del elemento actual
        *(p + i) = *(p + cantidad - 1 - i);//asigna el valor del elemento opuesto al actual
        *(p + cantidad - 1 - i) = temp; //almacena el nuevo numero
    }
}
int main (){
    int numeros[]= {10,20,30,40,50};
    int cantidad= 5;
    int *p = numeros;
    cout << "Numeros originales: ";
    for(int i=0; i < cantidad; i++){//recorre el arreglo
        cout << *(p + i) << " ";//imprime el valor del elemento actual
    }
    cout << endl;
    intercambiar(p, cantidad);
    cout << "Numeros intercambiados: ";
    for(int i=0; i < cantidad; i++){
        cout << *(p + i) << " ";//imprime el valor del elemento actual
    }
    cout << endl;
    return 0;
}