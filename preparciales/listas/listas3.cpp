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

// Representa un nodo de una lista doblemente enlazada.
struct Node {
    int data;       // Valor almacenado en el nodo.
    Node* next;     // Apunta al siguiente nodo.
    Node* prev;     // Apunta al nodo anterior.
};

// Agrega un nuevo nodo al final de la lista.
void Append(Node*& head, int value) {

    // Crea un nodo con el valor indicado y sin enlaces iniciales.
    Node* new_node = new Node{value, nullptr, nullptr};

    // Si la lista está vacía, el nuevo nodo será el primero.
    if (head == nullptr) {
        head = new_node;
        return;
    }

    // Recorre la lista hasta encontrar el último nodo.
    Node* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    // Conecta el último nodo actual con el nuevo nodo.
    current->next = new_node;

    // Conecta el nuevo nodo con el que ahora es su anterior.
    new_node->prev = current;
}

// Muestra la lista desde el primer nodo hasta el último.
void PrintForward(Node* head) {

    // Comienza desde el inicio de la lista.
    Node* current = head;

    // Recorre los nodos e imprime sus valores separados por flechas.
    while (current != nullptr) {
        std::cout << current->data;

        // Avanza al siguiente nodo.
        current = current->next;

        // Imprime una flecha solamente si quedan nodos por mostrar.
        if (current != nullptr) {
            std::cout << " <-> ";
        }
    }

    std::cout << std::endl;
}

// Muestra la lista desde el último nodo hasta el primero.
void PrintBackward(Node* head) {

    // Si la lista está vacía, no hay nada que imprimir.
    if (head == nullptr) {
        std::cout << std::endl;
        return;
    }

    // Comienza desde el primer nodo para encontrar el último.
    Node* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    // Recorre la lista hacia atrás usando el puntero prev.
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->prev;
    }

    std::cout << std::endl;
}

// Mueve el último nodo de la lista al inicio.
void MoveLastToFront(Node*& head) {

    // Si la lista está vacía o tiene un solo nodo,
    // no es necesario realizar ningún cambio.
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    // Recorre la lista hasta encontrar el último nodo.
    Node* last = head;

    while (last->next != nullptr) {
        last = last->next;
    }

    // Guarda el nodo anterior al último.
    // Este nodo se convertirá en el nuevo último.
    Node* new_last = last->prev;

    // Desconecta el último nodo de su anterior.
    // El nuevo último ya no tendrá un nodo siguiente.
    new_last->next = nullptr;

    // El último nodo deja de apuntar hacia su anterior.
    last->prev = nullptr;

    // Conecta el antiguo último nodo con el inicio actual.
    last->next = head;

    // El inicio actual ahora tiene un nodo anterior: last.
    head->prev = last;

    // Actualiza head para que apunte al nodo que se movió.
    head = last;
}

int main() {

    // Inicializa una lista vacía.
    Node* head = nullptr;

    // Agrega los valores de la lista original.
    Append(head, 10);
    Append(head, 20);
    Append(head, 30);
    Append(head, 40);
    Append(head, 50);

    // Muestra la lista antes de mover el último nodo.
    std::cout << "Antes:" << std::endl;
    PrintForward(head);

    // Mueve el último nodo al inicio sin crear ni eliminar nodos.
    MoveLastToFront(head);

    // Comprueba el orden de la lista después del movimiento.
    std::cout << "\nDespues:" << std::endl;
    PrintForward(head);

    // Comprueba que también se puede trabajar con una lista vacía.
    Node* empty = nullptr;
    MoveLastToFront(empty);

    // Comprueba que una lista con un solo nodo permanece igual.
    Node* single = nullptr;
    Append(single, 7);
    MoveLastToFront(single);

    // Libera la memoria de todos los nodos de la lista principal.
    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }

    // Libera el único nodo de la lista de prueba.
    delete single;

    return 0;
}
