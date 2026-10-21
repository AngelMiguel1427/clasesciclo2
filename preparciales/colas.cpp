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

void RotateQueue(std::queue<int>& requests, int k) {
  if (requests.empty() || k <= 0) {
    return;  // Cola vacía o k = 0: no hay nada que rotar.
  }

  // Si k supera el tamaño, solo importan las rotaciones equivalentes.
  int rotations = k % static_cast<int>(requests.size());

  for (int i = 0; i < rotations; ++i) {
    requests.push(requests.front());
    requests.pop();
  }
}

// Imprime la cola de frente a final (trabaja sobre una copia).
void PrintQueue(std::queue<int> requests) {
  while (!requests.empty()) {
    std::cout << requests.front() << " ";
    requests.pop();
  }
  std::cout << "\n";
}

int main() {
  std::queue<int> requests;
  requests.push(10);
  requests.push(20);
  requests.push(30);
  requests.push(40);
  requests.push(50);

  std::cout << "Original:  ";
  PrintQueue(requests);

  RotateQueue(requests, 2);
  std::cout << "k = 2:     ";
  PrintQueue(requests);  // 30 40 50 10 20

  RotateQueue(requests, 0);
  std::cout << "k = 0:     ";
  PrintQueue(requests);  // sin cambios

  RotateQueue(requests, 7);  // 7 % 5 = 2 rotaciones
  std::cout << "k = 7:     ";
  PrintQueue(requests);  // 50 10 20 30 40

  std::queue<int> empty;
  RotateQueue(empty, 3);  // No debe fallar
  std::cout << "Vacia:     ";
  PrintQueue(empty);

  return 0;
}