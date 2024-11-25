#include <iostream>
using namespace std;

struct asc {
    bool operator()(int a, int b) const {
        return a < b;
    }
};

struct desc {
    bool operator()(int a, int b) const {
        return a > b;
    }
};

template <class O>
class pivot {
public:
    O decision;
    int pivote;
    pivot(int p) : pivote(p) {}
    bool operator()(int valor) const {
        return decision(valor, pivote);
    }
};

template <class T, class FunctorPivot>
void transformar(T* inicio, T* fin, FunctorPivot functor) {
    T* i = inicio;
    T* j = fin;

    // Buscar la posición del pivote
    T* posPivote = nullptr;
    for (T* ptr = inicio; ptr <= fin; ++ptr) {
        if (*ptr == functor.pivote) {
            posPivote = ptr;
            break;
        }
    }

    if (!posPivote) {
        cout << "Error: Pivote no encontrado en el arreglo.\n";
        return;
    }

    // Mover el pivote al final temporalmente
    swap(*posPivote, *fin);

    // Reorganizar elementos alrededor del pivote
    T* nuevaPosPivote = inicio;
    for (T* ptr = inicio; ptr < fin; ++ptr) {
        if (functor(*ptr)) {
            swap(*ptr, *nuevaPosPivote);
            ++nuevaPosPivote;
        }
    }

    // Colocar el pivote en su posición final
    swap(*nuevaPosPivote, *fin);
}

int main() {
    int arr[] = { 1, 13, 28, 15, 3, 5, 30, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int pivote = 8;

    // Orden ascendente
    pivot<asc> ordenarAsc(pivote);
    transformar(arr, arr + n - 1, ordenarAsc);

    for (int* ptr = arr; ptr != arr + n; ++ptr) {
        cout << *ptr << " ";
    }
    cout << endl;

    // Orden descendente
    int arr2[] = { 1, 13, 28, 15, 3, 5, 30, 8 };
    pivot<desc> ordenarDesc(pivote);
    transformar(arr2, arr2 + n - 1, ordenarDesc);

    for (int* ptr = arr2; ptr != arr2 + n; ++ptr) {
        cout << *ptr << " ";
    }
    cout << endl;

    return 0;
}
