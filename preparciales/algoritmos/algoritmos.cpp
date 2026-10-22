/*
## Ejercicio 3.1. Ordenar únicamente un segmento



```
```
Modifique el algoritmo para que reciba dos parámetros adicionales, `start` y `end`, y ordene únicamente el segmento comprendido entre ambos índices, incluidos los extremos.


```
int values[] = {9, 7, 5, 4, 3, 8, 1, 6};

InsertionSort(values, 8, 2, 5);
```

Resultado esperado:

```
9 7 3 4 5 8 1 6
```

Requisitos:

- Ordenar el segmento de forma ascendente.
- No modificar los elementos que están fuera del segmento.
- No utilizar `std::sort`.
- Verificar que los índices recibidos sean válidos para el arreglo.

*/


#include <iostream>

// Ordena de menor a mayor solamente el segmento indicado por start y end.
// Los dos índices son inclusivos, es decir, ambos forman parte del ordenamiento.
void InsertionSort(int values[], int size, int start, int end) {

    // Verifica que el arreglo exista, que tenga elementos
    // y que los índices estén dentro de sus límites.
    // Si algún dato es inválido, termina la función sin modificar el arreglo.
    if (values == nullptr || size <= 0 ||
        start < 0 || end >= size || start > end) {
        return;
    }

    // Comienza desde el segundo elemento del segmento,
    // porque el primer elemento se considera ordenado inicialmente.
    for (int i = start + 1; i <= end; ++i) {

        // Guarda el elemento que se va a colocar en su posición correcta.
        int key = values[i];

        // Comienza a comparar con el elemento anterior.
        int j = i - 1;

        // Mientras no se salga del segmento y encuentre elementos
        // mayores que key, desplaza esos elementos una posición a la derecha.
        while (j >= start && values[j] > key) {
            values[j + 1] = values[j];
            --j;
        }

        // Coloca key en el espacio que quedó disponible.
        values[j + 1] = key;
    }
}

// Muestra todos los elementos del arreglo en pantalla.
void PrintArray(const int values[], int size) {

    // Recorre el arreglo desde el primer índice hasta el último.
    for (int i = 0; i < size; ++i) {
        std::cout << values[i] << " ";
    }

    // Finaliza la línea después de mostrar todos los elementos.
    std::cout << std::endl;
}

int main() {

    // Arreglo original de ocho elementos.
    int values[] = {9, 7, 5, 4, 3, 8, 1, 6};

    // Ordena únicamente los índices del 2 al 5, incluidos.
    // Los elementos de los índices 0, 1, 6 y 7 permanecen iguales.
    InsertionSort(values, 8, 2, 5);

    // Resultado esperado: 9 7 3 4 5 8 1 6
    PrintArray(values, 8);

    // Pruebas con índices inválidos.
    // Ninguna de estas llamadas debe modificar el arreglo.
    InsertionSort(values, 8, -1, 5); // start es negativo.
    InsertionSort(values, 8, 2, 8);  // end supera el último índice.
    InsertionSort(values, 8, 5, 2);  // start es mayor que end.

    // Comprueba que el arreglo sigue igual después de las pruebas.
    PrintArray(values, 8);

    return 0;
}
