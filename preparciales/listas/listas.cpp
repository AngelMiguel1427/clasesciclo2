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

// Representa un nodo de una lista doblemente enlazada.
struct Node {
    int data;       // Valor almacenado en el nodo.
    Node* next;     // Apunta al siguiente nodo de la lista.
    Node* prev;     // Apunta al nodo anterior de la lista.
};

// Agrega un nodo al final de la lista.
void Append(Node*& head, int value) {

    // Crea un nuevo nodo con el valor indicado.
    // Como se agrega al final, inicialmente no tiene siguiente ni anterior.
    Node* new_node = new Node{value, nullptr, nullptr};

    // Si la lista está vacía, el nuevo nodo será el primero.
    if (head == nullptr) {
        head = new_node;
        return;
    }

    // Comienza desde el primer nodo para buscar el último.
    Node* current = head;

    // Avanza hasta encontrar un nodo que no tenga sucesor.
    while (current->next != nullptr) {
        current = current->next;
    }

    // Conecta el último nodo con el nuevo nodo.
    current->next = new_node;

    // Conecta el nuevo nodo con el que anteriormente era el último.
    new_node->prev = current;
}

// Inserta un nodo con value inmediatamente después de la primera
// aparición de target. Devuelve true si logra insertarlo.
bool InsertAfter(Node* head, int target, int value) {

    // Comienza la búsqueda desde el primer nodo.
    Node* current = head;

    // Avanza mientras existan nodos y no encuentre el valor buscado.
    while (current != nullptr && current->data != target) {
        current = current->next;
    }

    // Si current es nullptr, se llegó al final sin encontrar target.
    // La lista permanece sin cambios.
    if (current == nullptr) {
        return false;
    }

    // Crea el nuevo nodo después de current.
    // Su siguiente será el sucesor actual y su anterior será current.
    Node* new_node = new Node{value, current->next, current};

    // Si current tenía un nodo después, actualiza su puntero prev
    // para que apunte al nuevo nodo.
    if (current->next != nullptr) {
        current->next->prev = new_node;
    }

    // Actualiza el puntero next de current para enlazarlo con
    // el nuevo nodo y completar la inserción.
    current->next = new_node;

    // Indica que la inserción se realizó correctamente.
    return true;
}

// Recorre la lista desde el primero hasta el último nodo.
void PrintForward(Node* head) {

    // Comienza desde la cabeza de la lista.
    Node* current = head;

    // Muestra el valor de cada nodo y avanza al siguiente.
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }

    // Termina la línea después de mostrar la lista.
    std::cout << std::endl;
}

// Recorre la lista desde el último nodo hasta el primero.
void PrintBackward(Node* head) {

    // Si la lista está vacía, no hay nada que mostrar.
    if (head == nullptr) {
        return;
    }

    // Comienza desde el primer nodo para localizar el último.
    Node* current = head;

    // Avanza hasta el último nodo de la lista.
    while (current->next != nullptr) {
        current = current->next;
    }

    // Recorre la lista hacia atrás utilizando el puntero prev.
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->prev;
    }

    // Termina la línea después de mostrar la lista.
    std::cout << std::endl;
}

int main() {

    // Inicializa una lista vacía.
    Node* head = nullptr;

    // Agrega los valores iniciales en orden.
    Append(head, 10);
    Append(head, 20);
    Append(head, 30);
    Append(head, 40);
    Append(head, 50);

    // Muestra la lista antes de realizar la inserción.
    std::cout << "Lista original: ";
    PrintForward(head);

    // Intenta insertar 25 inmediatamente después de 20.
    if (InsertAfter(head, 20, 25)) {

        // Si la inserción fue exitosa, muestra la lista actualizada.
        std::cout << "Despues de insertar 25 despues de 20: ";
        PrintForward(head);

    } else {

        // Informa si el valor objetivo no existe en la lista.
        std::cout << "El valor objetivo no se encontro en la lista."
                  << std::endl;
    }

    return 0;
}
