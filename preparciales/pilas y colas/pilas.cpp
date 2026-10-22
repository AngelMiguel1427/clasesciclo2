/*
Al extraer los elementos de la pila resultante mediante `pop()`, el orden esperado es:

```
40
30
10
```

Requisitos:

- Eliminar todas las apariciones del valor indicado.
- Mantener los elementos restantes en el orden relativo original.
- Utilizar operaciones de pila y una pila auxiliar.
- No utilizar contenedores adicionales distintos de las pilas.

Pregunta: ¿por qué es necesario devolver los elementos de la pila auxiliar a la pila original?

*/


#include <stack>
#include <iostream>

// Elimina todas las apariciones de target sin cambiar
// el orden relativo de los elementos que permanecen.
void RemoveFromStack(std::stack<int>& tasks, int target) {
    // La pila auxiliar guarda temporalmente los elementos
    // que no coinciden con el valor que queremos eliminar.
    std::stack<int> auxiliary;

    // Recorremos la pila original desde su elemento superior.
    while (!tasks.empty()) {
        int value = tasks.top(); // Consultamos el elemento superior.
        tasks.pop();             // Lo retiramos de la pila original.

        // Solo conservamos los elementos diferentes de target.
        if (value != target) {
            auxiliary.push(value);
        }
    }

    // Devolvemos los elementos a la pila original.
    // Esto permite recuperar el orden original de los elementos restantes.
    while (!auxiliary.empty()) {
        tasks.push(auxiliary.top());
        auxiliary.pop();
    }
}

int main() {
    std::stack<int> tasks;

    // Agregamos los elementos a la pila.
    // El último elemento agregado queda en la parte superior.
    tasks.push(10);
    tasks.push(20);
    tasks.push(30);
    tasks.push(20);
    tasks.push(40);

    // Eliminamos todas las apariciones del número 20.
    RemoveFromStack(tasks, 20);

    // Mostramos los elementos desde la parte superior hacia abajo.
    std::cout << "Elementos de la pila (de arriba hacia abajo):"
              << std::endl;

    while (!tasks.empty()) {
        std::cout << tasks.top() << std::endl;
        tasks.pop();
    }

    return 0;
}
