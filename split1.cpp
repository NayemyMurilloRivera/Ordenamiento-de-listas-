#include <iostream>
using namespace std;

// Función para separar los pares e impares y "ordenarlos" de manera secuencial
void split(int* inicio, int* final) {
    int* impar = final - 1;
    int* par = inicio;

    // Primera parte: separar pares e impares
    while (par < impar) {
        if (*par % 2 == 0) {
            par++;  // Avanza si es par
        } else {
            swap(*par, *impar);  // Coloca los impares al final
            impar--;
        }
    }

    // Segunda parte: Reorganizar los pares de forma secuencial
    for (int* i = inicio; i < par - 1; i++) {
        for (int* j = i + 1; j < par; j++) {
            if (*i > *j) {
                swap(*i, *j);
            }
        }
    }
    
    // Tercera parte: Reorganizar los impares de forma secuencial
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
    
    // Separar pares e impares y luego organizarlos secuencialmente
    split(ptr_inicio, ptr_final);
    
    cout << "Arreglo final (pares e impares ordenados):" << endl;
    for (int* B = ptr_inicio; B < ptr_final; B++) {
        cout << "[" << *B << "] ";
    }
    cout << endl;

    return 0;
}
