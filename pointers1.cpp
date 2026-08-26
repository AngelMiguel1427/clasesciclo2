#include <iostream>
using namespace std;

int main(){
    int n = 5;
    int *pointer1 = &n;
    int *pointer2 = pointer1;

    cout<< " Valor: " << n << endl;
    cout << "Ubicacion: " << &n << endl;
    cout << "Direccion de pointer1: " << &pointer1 << endl;
    cout << "Direccion de pointer2: " << &pointer2 << endl;
    cout << "Valor apuntado por pointer1: " << *pointer1 << endl;
    cout << "Valor apuntado por pointer2: " << *pointer2 << endl;
    *pointer1 = 10;

    return 0;
}