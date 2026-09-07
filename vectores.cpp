#include <iostream>
using namespace std;

int main (){

    do{
        cout << "Ingrese la cantidad de elementos: ";
        cin >> n;
        int *vector = new int[n];
        cout << "Ingrese los elementos del vector: ";
        for(int i = 0; i < n; i++){
            cin >> vector[i];
        }

        cout << "Los elementos del vector son: ";
        for(int i = 0; i < n; i++){
            cout << vector[i] << " ";
        }

        delete[] vector;

    }while(true);

}
