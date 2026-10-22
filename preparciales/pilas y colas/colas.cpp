/*
## Ejercicio 2.2. Rotar una cola

Implemente la función:

```
#include <queue>

void RotateQueue(std::queue<int>& requests, int k) {
  // Implemente la rotación.
}
```

La función debe mover los primeros `k` elementos de la cola al final, conservando su orden.

Prueba:

Cola inicial, de frente a final:

```
10 20 30 40 50
```

Con `k = 2`, el resultado debe ser:

```
30 40 50 10 20
```

Requisitos:

- Utilizar las operaciones propias de `std::queue`.
- Mantener el orden de los elementos que se mueven.
- Manejar una cola vacía y el caso `k = 0`.
- Si `k` supera el tamaño de la cola, efectuar únicamente las rotaciones equivalentes necesarias. Por ejemplo, una rotación de 7 posiciones en una cola de 5 elementos equivale a 2 rotaciones.

Pregunta: ¿qué elemento queda al frente después de la rotación y cómo cambia su posición respecto de la cola original?
*/

#include <iostream>
#include <queue>

// Mueve los primeros k elementos de la cola al final,
// conservando el orden en que aparecen.
void RotateQueue(std::queue<int>& requests, int k) {

    // Si la cola está vacía o k es cero o negativo,
    // no es necesario realizar ninguna rotación.
    if (requests.empty() || k <= 0) {
        return;
    }

    // Calcula las rotaciones necesarias sin repetir ciclos innecesarios.
    // Por ejemplo, rotar 7 posiciones una cola de 5 elementos
    // equivale a realizar solamente 2 rotaciones.
    int rotations = k % static_cast<int>(requests.size());

    // Repite el proceso la cantidad de rotaciones calculada.
    for (int i = 0; i < rotations; ++i) {

        // Copia el elemento que está al frente y lo coloca al final.
        // Así se conserva el orden relativo de los elementos movidos.
        requests.push(requests.front());

        // Elimina el elemento que estaba originalmente al frente.
        // Como ya se agregó al final, no se pierde ningún elemento.
        requests.pop();
    }
}

// Imprime los elementos de la cola desde el frente hasta el final.
// Recibe una copia para que la cola original no se modifique.
void PrintQueue(std::queue<int> requests) {

    // Mientras queden elementos, muestra el primero y lo elimina
    // de la copia para poder avanzar al siguiente.
    while (!requests.empty()) {
        std::cout << requests.front() << " ";
        requests.pop();
    }

    // Termina la línea después de imprimir todos los elementos.
    std::cout << std::endl;
}

int main() {

    // Crea una cola vacía para almacenar las solicitudes.
    std::queue<int> requests;

    // Agrega los elementos en el orden inicial.
    requests.push(10);
    requests.push(20);
    requests.push(30);
    requests.push(40);
    requests.push(50);

    // Muestra la cola original antes de realizar las rotaciones.
    std::cout << "Original: ";
    PrintQueue(requests);

    // Mueve los primeros dos elementos al final.
    RotateQueue(requests, 2);

    // Resultado esperado: 30 40 50 10 20
    std::cout << "k = 2:    ";
    PrintQueue(requests);

    // Comprueba que k = 0 no modifica la cola.
    RotateQueue(requests, 0);

    // La cola debe permanecer igual.
    std::cout << "k = 0:    ";
    PrintQueue(requests);

    // Como la cola tiene 5 elementos, 7 % 5 = 2.
    // Por tanto, solo se necesitan dos rotaciones.
    RotateQueue(requests, 7);

    // Resultado esperado: 50 10 20 30 40
    std::cout << "k = 7:    ";
    PrintQueue(requests);

    // Comprueba que la función funciona con una cola vacía.
    std::queue<int> empty;
    RotateQueue(empty, 3);

    // No imprime elementos porque la cola está vacía.
    std::cout << "Vacia:    ";
    PrintQueue(empty);

    return 0;
}
