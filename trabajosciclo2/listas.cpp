#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Inserta al inicio
void Insert(Node*& head, int data) {
    Node* new_Node = new Node{data, head};
    head = new_Node;
}

// Inserta al final
void InsertEnd(Node*& head, int data) {
    Node* new_Node = new Node{data, nullptr};

    if (head == nullptr) {       // == , no =
        head = new_Node;
        return;                  // aquí sí es válido: la función es void
    }

    Node* current = head;
    while (current->next != nullptr) {   // sin el avance previo
        current = current->next;
    }
    current->next = new_Node;
}

void Print(Node* head) {
    for (Node* c = head; c != nullptr; c = c->next) {
        cout << c->data << " -> ";
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = nullptr;   // aquí sí se declara la lista

    Insert(head, 30);       // 30
    Insert(head, 10);       // 10 -> 30
    InsertEnd(head, 99);    // 10 -> 30 -> 99

    Print(head);

    return 0;
}