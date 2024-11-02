
#include <iostream>
using namespace std;

struct nodo {
    int valor;
    nodo* next;
    nodo(int v, nodo* n = nullptr) {
        valor = v;
        next = n;
    }
};

void merge(nodo*& A, nodo*& B) {
    nodo* i = A;
    nodo* j = B;
    nodo* inicio = nullptr;

    if (i && j) {
        if (i->valor < j->valor) {
            inicio = i;
            i = i->next;
        }
        else {
            inicio = j;
            j = j->next;
        }
    }
    else if (i) {
        inicio = i;
        i = i->next;
    }
    else {
        inicio = j;
        j = j->next;
    }

    // Realizar la fusión
    nodo* p = inicio;
    while (i != nullptr || j != nullptr) {
        if (i != nullptr && (j == nullptr || i->valor < j->valor)) {
            p->next = i;
            i = i->next;
        }
        else if (j != nullptr) {
            p->next = j;
            j = j->next;
        }
        p = p->next;
    }

    // Asigna el inicio de la lista fusionada a `A` y vacía `B`
    A = inicio;
    B = nullptr;  // Vaciar B después de la fusión
}

void creacion_nodo(int* begin, int* end, nodo*& nodo1) {
    for (int* i = end; i >= begin; i--)
        nodo1 = new nodo(*i, nodo1);
}

void impresion_nodo(nodo* nodo1) {
    cout << "Head->";
    nodo* tmp = nodo1;
    while (tmp) {
        cout << tmp->valor << "->";
        tmp = tmp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    nodo* nodo1 = nullptr;
    nodo* nodo2 = nullptr;
    int A[6] = { 13, 17, 20, 25, 30, 38 };
    int B[9] = { 1, 8, 13, 20, 23, 31, 38, 40, 53 };

    creacion_nodo(A, A + 5, nodo1);
    creacion_nodo(B, B + 8, nodo2);

    cout << "Lista A: " << endl;
    impresion_nodo(nodo1);
    cout << "Lista B: " << endl;
    impresion_nodo(nodo2);

    cout << "Merge:" << endl;
    merge(nodo1, nodo2);

    // Muestra el resultado de la fusión
    cout << "Lista fusionada (A): ";
    impresion_nodo(nodo1);

    // Verificar que B esté vacío
    cout << "Lista B después del merge: ";
    impresion_nodo(nodo2);

    return 0;
}