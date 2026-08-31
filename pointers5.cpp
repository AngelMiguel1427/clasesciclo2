#include <iostream>
using namespace std;    


// Función que cambia el valor de una variable por valor
void cambiarValor(int a){
    a = 20;
}

// Función que cambia el valor de una variable por referencia
void cambiarValorPorReferencia(int &b){
    b = 0;
}

void cambiarValorReferenciaPtr(int *& a){
    a = nullptr;
}

int main (){

    int a = 10;
    int *ptr = &a;
    /*
    cout << "Valor original: " << a << endl;
    cambiarValor(a);
    cout << "Valor después de la función: " << a << endl;
    
    cambiarValorPorReferencia(a);
    cout << "Valor después de la función por referencia: " << a << endl;
    */

  cout << "ptr: " << ptr << endl;
  cambiarValorReferenciaPtr(ptr);
  cout << "Valor apuntado por ptr: " << *ptr << endl;
    return 0;
}