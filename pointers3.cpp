#include <iostream>
using namespace std;
void swap (int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << "Direccion de a: " << a << endl;
    cout << "Direccion de b: " << b << endl;

}



int main (){
    int x = 5;
    int y = 6;
    cout << "Antes del swap: " << endl;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;

    swap(&x, &y);
    cout << "Despues del swap: " << endl;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
}