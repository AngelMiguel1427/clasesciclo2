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

void RemoveFromStack(std::stack<int>& tasks, int target) {
  std::stack<int> auxiliary;

  while (!tasks.empty()) {
    int value = tasks.top();
    tasks.pop();

    if (value != target) {
      auxiliary.push(value);
    }
  }

  while (!auxiliary.empty()) {
    tasks.push(auxiliary.top());
    auxiliary.pop();
  }
}

int main()
{
    std::stack<int> tasks;

    tasks.push(10);
    tasks.push(20);
    tasks.push(30);
    tasks.push(20);
    tasks.push(40);

    RemoveFromStack(tasks, 20);

    std::cout << "Elementos de la pila (de arriba hacia abajo):\n";
    while (!tasks.empty()) {
        std::cout << tasks.top() << '\n';
        tasks.pop();
    }
}