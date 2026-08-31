//un sistema bancario almacena el saldo de una cuenta . Crear una funcion despositar() 
// que reciba mediante un puntero el saldo y una cantidad a depositar la funcion debe modificar el saldo original


#include <iostream>
#include <windows.h>
using namespace std;
void depositar(int *saldo, int cantidad) {
    *saldo += cantidad;
}

int main (){
    SetConsoleOutputCP(CP_UTF8);
    int saldo = 1000;
    int cantidad = 500;
    cout << "Saldo original: " << saldo << endl;
    depositar(&saldo, cantidad);
    cout << "Saldo después del depósito: " << saldo << endl;
    return 0;
}