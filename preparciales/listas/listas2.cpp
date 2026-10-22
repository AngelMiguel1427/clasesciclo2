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

// Representa un nodo de una lista doblemente enlazada.
struct Node {
    int data;       // Valor almacenado en el nodo.
    Node* next;     // Apunta al siguiente nodo.
    Node* prev;     // Apunta al nodo anterior.
};

// Separa la lista original en dos listas según la posición
// de cada nodo, comenzando desde la posición 0.
void SplitByPosition(
    Node*& head,
    Node*& even_head,
    Node*& odd_head
) {
    // Guarda el primer nodo de la lista original.
    Node* current = head;

    // Inicializa los punteros de inicio de ambas listas.
    even_head = nullptr;
    odd_head = nullptr;

    // Mantiene una referencia al último nodo de cada lista.
    // Así podemos agregar nodos al final sin recorrer la lista.
    Node* last_even = nullptr;
    Node* last_odd = nullptr;

    // Lleva la posición original del nodo que se está procesando.
    int position = 0;

    // Recorre cada nodo de la lista original una sola vez.
    while (current != nullptr) {

        // Guarda el siguiente nodo antes de cambiar los enlaces.
        // Esto permite continuar recorriendo la lista original.
        Node* next_node = current->next;

        // Desconecta el nodo actual de sus enlaces anteriores.
        // Después se conectará a la lista que le corresponda.
        current->next = nullptr;
        current->prev = nullptr;

        // Las posiciones 0, 2, 4, 6... van a la lista par.
        if (position % 2 == 0) {

            // Si la lista par está vacía, el nodo será su primero.
            if (even_head == nullptr) {
                even_head = current;
            } else {
                // Conecta el último nodo par con el nodo actual.
                last_even->next = current;

                // Actualiza el enlace hacia atrás del nodo actual.
                current->prev = last_even;
            }

            // El nodo actual pasa a ser el último de la lista par.
            last_even = current;

        } else {

            // Si la lista impar está vacía, el nodo será su primero.
            if (odd_head == nullptr) {
                odd_head = current;
            } else {
                // Conecta el último nodo impar con el nodo actual.
                last_odd->next = current;

                // Actualiza el enlace hacia atrás del nodo actual.
                current->prev = last_odd;
            }

            // El nodo actual pasa a ser el último de la lista impar.
            last_odd = current;
        }

        // Avanza al siguiente nodo de la lista original.
        current = next_node;

        // Incrementa la posición para procesar el próximo nodo.
        ++position;
    }

    // La lista original queda vacía porque sus nodos
    // ahora pertenecen a las dos listas nuevas.
    head = nullptr;
}

// Agrega un nodo al final de la lista.
void Append(Node*& head, int value) {

    // Crea un nodo nuevo sin enlaces iniciales.
    Node* new_node = new Node{value, nullptr, nullptr};

    // Si la lista está vacía, el nodo será el primero.
    if (head == nullptr) {
        head = new_node;
        return;
    }

    // Busca el último nodo de la lista.
    Node* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    // Enlaza el último nodo con el nuevo nodo.
    current->next = new_node;

    // Enlaza el nuevo nodo con su anterior.
    new_node->prev = current;
}

// Imprime los elementos desde el primero hasta el último.
void PrintForward(Node* head) {

    // Comienza desde la cabeza de la lista.
    Node* current = head;

    // Muestra cada valor y avanza hacia adelante.
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;
}

// Imprime los elementos desde el último hasta el primero.
void PrintBackward(Node* head) {

    // Si la lista está vacía, no hay elementos que mostrar.
    if (head == nullptr) {
        std::cout << std::endl;
        return;
    }

    // Comienza desde el primer nodo para buscar el último.
    Node* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    // Recorre los nodos hacia atrás mediante prev.
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->prev;
    }

    std::cout << std::endl;
}

int main() {

    // Inicializa la lista original y las dos listas resultantes.
    Node* head = nullptr;
    Node* even_head = nullptr;
    Node* odd_head = nullptr;

    // Construye la lista original.
    Append(head, 10);
    Append(head, 20);
    Append(head, 30);
    Append(head, 40);
    Append(head, 50);
    Append(head, 60);
    Append(head, 70);

    // Separa los nodos según sus posiciones originales.
    SplitByPosition(head, even_head, odd_head);

    // Muestra la lista de posiciones pares en ambos sentidos.
    PrintForward(even_head);
    PrintBackward(even_head);

    // Muestra la lista de posiciones impares en ambos sentidos.
    PrintForward(odd_head);
    PrintBackward(odd_head);

    return 0;
}
