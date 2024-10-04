#include <iostream>
using namespace std;


void split1(int* inicio, int* final) {
    int* f = final - 1;
    while (inicio < f) {
        for (int* i = inicio; i < f; f--) {
            swap(*i, *f);
        }
    }
    int* impar = final - 1;
    int* p = inicio;

    while (p < impar) {
        if (*p % 2 != 0) {
            swap(*p, *impar);
            impar--;
        }
        else {
            p++;
            
        }
    }

    final = f;

    

}

int main() {
    int lista[8] = { 1, 2, 3, 4, 5, 6 , 7 , 8};
    int* ptr_inicio = lista;
    int* ptr_final = lista + 8;

    cout << "Arreglo inicial:" << endl;
    for (int* B = ptr_inicio; B < ptr_final; B++) {
        cout << "[" << *B << "] ";
    }
    cout << endl;

    split1(ptr_inicio, ptr_final);
    cout << "Arreglo final:" << endl;
    for (int* B = ptr_inicio; B < ptr_final; B++) {
        cout << "[" << *B << "] ";
    }
    cout << endl;

    return 0;
}
