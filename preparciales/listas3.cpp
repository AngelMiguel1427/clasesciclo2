/*
## Ejercicio 1.3. Mover el último nodo al inicio

Implemente la función:

```
void MoveLastToFront(Node*& head);
```

La función debe mover el último nodo de la lista al inicio, sin crear ni eliminar nodos y sin modificar los valores almacenados.

Ejemplo:

```
Antes:
10 <-> 20 <-> 30 <-> 40 <-> 50

Después:
50 <-> 10 <-> 20 <-> 30 <-> 40
```

Requisitos:

- Actualizar correctamente `head`.
- Actualizar los punteros `next` y `prev`.
- Manejar una lista vacía y una lista con un solo nodo.
- Evitar la creación de ciclos.
- No copiar los valores para simular el movimiento.

Compruebe el resultado con `PrintForward` y `PrintBackward`.


*/

#include <iostream>

struct Node {
  int data;
  Node* next;
  Node* prev;
};

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
    std::cout << current->data;
    current = current->next;
    if (current != nullptr) {
      std::cout << " <-> ";
    }
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

void MoveLastToFront(Node*& head) {
  if (head == nullptr || head->next == nullptr) {
    return;
  }

  Node* last = head;
  while (last->next != nullptr) {
    last = last->next;
  }

  Node* new_last = last->prev;
  new_last->next = nullptr;
  last->prev = nullptr;
  last->next = head;
  head->prev = last;
  head = last;
}

int main() {
  Node* head = nullptr;
  Append(head, 10);
  Append(head, 20);
  Append(head, 30);
  Append(head, 40);
  Append(head, 50);

  std::cout << "Antes:\n";
  PrintForward(head);

  MoveLastToFront(head);

  std::cout << "\nDespues:\n";
  PrintForward(head);

  Node* empty = nullptr;
  MoveLastToFront(empty);

  Node* single = nullptr;
  Append(single, 7);
  MoveLastToFront(single);

  while (head != nullptr) {
    Node* next = head->next;
    delete head;
    head = next;
  }
  delete single;
}