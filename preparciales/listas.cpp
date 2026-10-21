/*Implemente la función:

```
bool InsertAfter(Node* head, int target, int value);
```

La función debe insertar un nodo con el valor `value` inmediatamente después de la primera aparición de `target`.

Requisitos:

- Si `target` existe, insertar el nuevo nodo y retornar `true`.
- Si `target` no existe, retornar `false` sin modificar la lista.
- Actualizar correctamente los punteros `next` y `prev`.
- No reconstruir la lista ni modificar los valores de los nodos existentes.

Prueba esperada: insertar `25` después de `20` en la lista inicial.

Resultado:

```
10 20 25 30 40 50
```*/


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

bool InsertAfter(Node* head, int target, int value) {
  Node* current = head;

  while (current != nullptr && current->data != target) {
    current = current->next;
  }

  if (current == nullptr) {
    return false;
  }

  Node* new_node = new Node{value, current->next, current};
  if (current->next != nullptr) {
    current->next->prev = new_node;
  }
  current->next = new_node;

  return true;
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

int main (){
    Node* head = nullptr;
    
    Append(head, 10);
    Append(head, 20);
    Append(head, 30);
    Append(head, 40);
    Append(head, 50);
    
    std::cout << "Lista original: ";
    PrintForward(head);
    
    if (InsertAfter(head, 20, 25)) {
        std::cout << "Despues de insertar 25 despues de 20: ";
        PrintForward(head);
    } else {
        std::cout << "El valor objetivo no se encontro en la lista.\n";
    }
    
    return 0;
}