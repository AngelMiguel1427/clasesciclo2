/*## Ejercicio 1.2. Separar una lista por posición

Una lista doblemente enlazada almacena números enteros. Se necesita separar sus nodos en dos listas distintas, según la posición original de cada nodo, comenzando desde la posición `0`.

Implemente la siguiente función:

```
void SplitByPosition(
    Node*& head,
    Node*& even_head,
    Node*& odd_head);
```

La función debe cumplir las siguientes condiciones:

- `even_head` debe contener los nodos que originalmente estaban en las posiciones `0, 2, 4, 6...`.
- `odd_head` debe contener los nodos que originalmente estaban en las posiciones `1, 3, 5, 7...`.
- Ambas listas deben conservar el orden relativo original de sus nodos.
- Se deben reutilizar los nodos existentes. No se permite crear nodos nuevos ni copiar sus valores.
- Se deben actualizar correctamente los punteros `next` y `prev`.
- Al finalizar, `head` debe quedar en `nullptr`.
- La función debe funcionar con una lista vacía y con una lista que contenga un solo nodo.

Código para probar la función:

```
Node* head = nullptr;
Node* even_head = nullptr;
Node* odd_head = nullptr;

Append(head, 10);
Append(head, 20);
Append(head, 30);
Append(head, 40);
Append(head, 50);
Append(head, 60);
Append(head, 70);

SplitByPosition(head, even_head, odd_head);

PrintForward(even_head);
PrintBackward(even_head);

PrintForward(odd_head);
PrintBackward(odd_head);
```

Resultado esperado:

```
10 30 50 70
70 50 30 10
20 40 60
60 40 20
```

Preguntas de análisis:

a. ¿Por qué se debe guardar el siguiente nodo antes de modificar `current->next`?
R. porque al modificar `current->next`, se pierde la referencia al siguiente nodo en la lista original. Guardar el siguiente nodo antes de hacer cambios permite continuar iterando correctamente a través de la lista sin perder acceso a los nodos restantes.

b. ¿Qué problema puede ocurrir si se actualizan los punteros `next`, pero no los punteros `prev`?
R. Si se actualizan los punteros `next` pero no los punteros `prev`, la lista doblemente enlazada puede quedar en un estado inconsistente. Esto puede causar problemas al intentar recorrer la lista hacia atrás, ya que los nodos no tendrán referencias correctas a sus nodos anteriores. Como resultado, operaciones que dependen de la integridad de la lista, como la impresión hacia atrás o la eliminación de nodos, pueden fallar o producir resultados incorrectos.

c. ¿Cuál es la complejidad temporal esperada de una solución que procesa cada nodo una sola vez? Justifique su respuesta.
R. La complejidad temporal esperada de una solución que procesa cada nodo una sola vez es O(n), donde n es el número de nodos en la lista original. Esto se debe a que cada nodo se visita exactamente una vez durante la iteración a través de la lista, y las operaciones realizadas en cada nodo (como actualizar punteros y mover nodos a las listas correspondientes) se realizan en tiempo constante O(1). Por lo tanto, el tiempo total de ejecución crece linealmente con el tamaño de la lista.
*/

#include <iostream>

struct Node {
  int data;
  Node* next;
  Node* prev;
};

void SplitByPosition(Node*& head, Node*& even_head, Node*& odd_head) {
  Node* current = head;
  int position = 0;

  while (current != nullptr) {
    Node* next_node = current->next; // Guardar el siguiente nodo antes de modificar los punteros

    if (position % 2 == 0) {
      // Insertar en la lista de posiciones pares
      if (even_head == nullptr) {
        even_head = current;
        current->prev = nullptr;
      } else {
        Node* last_even = even_head;
        while (last_even->next != nullptr) {
          last_even = last_even->next;
        }
        last_even->next = current;
        current->prev = last_even;
      }
    } else {
      // Insertar en la lista de posiciones impares
      if (odd_head == nullptr) {
        odd_head = current;
        current->prev = nullptr;
      } else {
        Node* last_odd = odd_head;
        while (last_odd->next != nullptr) {
          last_odd = last_odd->next;
        }
        last_odd->next = current;
        current->prev = last_odd;
      }
    }

    current->next = nullptr; // Desconectar el nodo actual de la lista original
    current = next_node; // Avanzar al siguiente nodo
    position++;
  }

  head = nullptr; // La lista original queda vacía
}

void Append(Node*& head, int value) {
  Node* new_node = new Node{value, nullptr, nullptr};

  if (head == nullptr) {
    head = new_node;
    return;
  }

  Node* current = head;

  while (current->next != nullptr) {
    current = current->next;
  }

  current->next = new_node;
  new_node->prev = current;
}

void PrintForward(Node* head) {
  Node* current = head;

  while (current != nullptr) {
    std::cout << current->data << " ";
    current = current->next;
  }

  std::cout << '\n';
}

void PrintBackward(Node* head) {
  if (head == nullptr) {
    return;
  }

  Node* current = head;

  while (current->next != nullptr) {
    current = current->next;
  }

  while (current != nullptr) {
    std::cout << current->data << " ";
    current = current->prev;
  }

  std::cout << '\n';
}

int main()
{
    Node *head = nullptr;
    Node *even_head = nullptr;
    Node *odd_head = nullptr;

    Append(head, 10);
    Append(head, 20);
    Append(head, 30);
    Append(head, 40);
    Append(head, 50);
    Append(head, 60);
    Append(head, 70);

    SplitByPosition(head, even_head, odd_head);

    PrintForward(even_head);
    PrintBackward(even_head);

    PrintForward(odd_head);
    PrintBackward(odd_head);
}