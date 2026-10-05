#include <iostream>
#include <limits>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};
//una funcion para poder insertar al final 
// Insertar al final: tail siempre representa el ultimo elemento insertado.
void InsertEnd(Node*& head, Node*& tail, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};
    if (tail == nullptr) {
        head = tail = newNode;
        newNode->prev = newNode->next = newNode;
        return;
    }

    newNode->prev = tail;
    newNode->next = head;
    tail->next = newNode;
    head->prev = newNode;
    tail = newNode;
}

// start = head y adelante = true  -> izquierda a derecha (usa next)
// start = tail y adelante = false -> derecha a izquierda (usa prev)
void Print(Node* start, bool adelante) {
    if (start == nullptr) {
        cout << "La lista esta vacia." << endl;
        return;
    }

    Node* current = start;
    do {
        cout << current->data;
        current = adelante ? current->next : current->prev;
        if (current != start) cout << " -> ";
    } while (current != start);
    cout << endl;
}

void PeekLast(Node* tail) {
    if (tail == nullptr) {
        cout << "No hay elementos para consultar: la lista esta vacia." << endl;
        return;
    }

    cout << "Proximo elemento a eliminar: " << tail->data << endl;
}

void DeleteLast(Node*& head, Node*& tail) {
    if (tail == nullptr) {
        cout << "No hay elementos para eliminar: la lista esta vacia." << endl;
        return;
    }

    Node* current = tail;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        tail = current->prev;
    }

    delete current;
    cout << "Ultimo elemento insertado eliminado." << endl;
}

void freeList(Node*& head, Node*& tail) {
    if (tail != nullptr) {
        tail->next = nullptr;   // rompe el anillo para poder terminar el while
    }

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    cout << "Lista liberada correctamente." << endl;
}

// ---------------------------------------------------------------
// HERRAMIENTAS PARA OBSERVAR LA LISTA
// ---------------------------------------------------------------

// Muestra cada nodo con sus vecinos: [prev | dato | next]
void PrintDebug(Node* head, Node* tail) {
    cout << "--- Estructura interna ---" << endl;
    if (head == nullptr) {
        cout << "head = nullptr, tail = nullptr (lista vacia)" << endl;
        return;
    }

    Node* current = head;
    int i = 0;
    do {
        cout << "Nodo " << i++ << ": [prev=" << current->prev->data
             << " | " << current->data
             << " | next=" << current->next->data << "]";
        if (current == head) cout << "  <- head";
        if (current == tail) cout << "  <- tail";
        cout << endl;
        current = current->next;
    } while (current != head);
}

// Comprueba las reglas que debe cumplir siempre el anillo
bool Verify(Node* head, Node* tail) {
    if (head == nullptr && tail == nullptr) {
        cout << "[OK] Lista vacia." << endl;
        return true;
    }
    if (head == nullptr || tail == nullptr) {
        cout << "[ERROR] Solo uno de head/tail es nullptr." << endl;
        return false;
    }
    if (head->prev != tail) {
        cout << "[ERROR] head->prev no apunta a tail." << endl;
        return false;
    }
    if (tail->next != head) {
        cout << "[ERROR] tail->next no apunta a head." << endl;
        return false;
    }

    Node* current = head;
    int count = 0;
    do {
        if (current->next == nullptr || current->prev == nullptr) {
            cout << "[ERROR] Hay un nodo con prev o next en nullptr." << endl;
            return false;
        }
        if (current->next->prev != current || current->prev->next != current) {
            cout << "[ERROR] Enlaces inconsistentes en el nodo " << current->data << "." << endl;
            return false;
        }
        current = current->next;
        if (++count > 100000) {
            cout << "[ERROR] El anillo no vuelve a head." << endl;
            return false;
        }
    } while (current != head);

    cout << "[OK] Anillo consistente con " << count << " nodo(s)." << endl;
    return true;
}

bool leerEntero(int& n) {
    cin >> n;
    if (!cin) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida." << endl;
        return false;
    }
    return true;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int opcion = 0, numero;
    bool traza = false;   // si esta activa, muestra la estructura despues de cada cambio

    do {
        cout << "\nMENU LISTA (ULTIMO EN ENTRAR, PRIMERO EN SALIR)" << endl;
        cout << "1. Insertar elemento" << endl;
        cout << "2. Imprimir de izquierda a derecha" << endl;
        cout << "3. Imprimir de derecha a izquierda" << endl;
        cout << "4. Consultar proximo elemento a eliminar" << endl;
        cout << "5. Eliminar ultimo elemento insertado" << endl;
        cout << "6. Liberar la memoria" << endl;
        cout << "7. Ver estructura interna y verificar" << endl;
        cout << "8. Modo traza: " << (traza ? "ACTIVADO" : "desactivado") << " (cambiar)" << endl;
        cout << "9. Salir" << endl;
        cout << "Seleccione una opcion: ";
        if (!leerEntero(opcion)) {
            opcion = 0;
            continue;
        }

        bool cambio = false;   // true si la opcion modifico la lista

        switch (opcion) {
            case 1:
                cout << "Ingrese un numero: ";
                if (!leerEntero(numero)) break;
                InsertEnd(head, tail, numero);
                cout << "Numero insertado." << endl;
                cambio = true;
                break;

            case 2:
                Print(head, true);
                break;

            case 3:
                Print(tail, false);
                break;

            case 4:
                PeekLast(tail);
                break;

            case 5:
                DeleteLast(head, tail);
                cambio = true;
                break;

            case 6:
                freeList(head, tail);
                cambio = true;
                break;

            case 7:
                PrintDebug(head, tail);
                Verify(head, tail);
                break;

            case 8:
                traza = !traza;
                cout << "Modo traza " << (traza ? "activado." : "desactivado.") << endl;
                break;

            case 9:
                cout << "Saliendo..." << endl;
                break;

            default:
                cout << "Opcion invalida." << endl;
        }

        if (traza && cambio) {
            PrintDebug(head, tail);
            Verify(head, tail);
        }

    } while (opcion != 9);

    if (head != nullptr) {
        freeList(head, tail);   // evita fugas de memoria al salir
    }
    return 0;
}