#include <iostream>
using namespace std;

// mientras mas facil sea para nosotros es mas dificil para la computadora 
void bubbleSort(int arr[], int n) {//Funcion para ordenar un arreglo de enteros usando el algoritmo de ordenamiento burbuja
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
// mientras mas facil sea para nosotros es mas dificil para la computadora 
void insertionSort(int arr[], int n) {//Funcion para ordenar un arreglo de enteros usando el algoritmo de ordenamiento por insercion
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}
// mientras mas facil sea para nosotros es mas dificil para la computadora 
void selectionSort(int arr[], int n) {//Funcion para ordenar un arreglo de enteros usando el algoritmo de ordenamiento por seleccion
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// mientras mas facil sea para nosotros es mas dificil para la computadora 

//RECURSIVIDAD
//iterativa: se repite un bloque de instrucciones hasta que se cumpla una condicion
//recursiva: una funcion se llama a si misma hasta que se cumpla una condicion
 
int contarHastaN(int n) {
    for (int i = 1; i <= n; ++i) {
        cout << i << " " << endl;
    }
}

void contarHastaNRecursivo(int n) {
    //Encontrar caso base
    if (n > 0) {
        //encontrar el caso y condicion recursiva
        contarHastaNRecursivo(n - 1);
        cout << n << " " << endl;
    }
}

int main() {

    int n = 5;


}