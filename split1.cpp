#include <iostream>
using namespace std;

void split(int* inicio, int* final) {
    int* impar = final - 1;
    int* par = inicio;
    while (par < impar) {
        if (*par % 2 == 0) {
            par++;  
        } else {
            swap(*par, *impar);  
            impar--;
        }
    }

    for (int* i = inicio; i < par - 1; i++) {
        for (int* j = i + 1; j < par; j++) {
            if (*i > *j) {
                swap(*i, *j);
            }
        }
    }
    
    for (int* i = par; i < final - 1; i++) {
        for (int* j = i + 1; j < final; j++) {
            if (*i > *j) {
                swap(*i, *j);
            }
        }
    }
}

int main() {
    int lista[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int* ptr_inicio = lista;
    int* ptr_final = lista + 8;

    cout << "Arreglo inicial:" << endl;
    for (int* B = ptr_inicio; B < ptr_final; B++) {
        cout << "[" << *B << "] ";
    }
    cout << endl;

    split(ptr_inicio, ptr_final);
    
    cout << "Arreglo final (pares e impares ordenados):" << endl;
    for (int* B = ptr_inicio; B < ptr_final; B++) {
        cout << "[" << *B << "] ";
    }
    cout << endl;

    return 0;
}
