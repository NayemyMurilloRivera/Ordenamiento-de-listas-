#include <iostream>
using namespace std;

// Función para ordenar en rango de punteros (utiliza el algoritmo de burbuja)
void arreglar(int* inicio, int* final) {
    for (int* i = inicio; i < final - 1; i++) {
        for (int* j = i + 1; j < final; j++) {
            if (*i > *j) {
                swap(*i, *j);
            }
        }
    }
}

// Función para separar los pares e impares
void split(int* inicio, int* final) {
    int* impar = final - 1;
    int* par = inicio;

    while (par < impar) {
        if (*par % 2 == 0) {
            par++;  // Avanza si es par
        } else {
            swap(*par, *impar);  // Coloca los impares al final
            impar--;
        }
    }

    // Ordenar los pares (desde el inicio hasta el puntero `par`)
    arreglar(inicio, par);
    
    // Ordenar los impares (desde `par` hasta el final)
    arreglar(par, final);
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
    
    // Separar pares e impares y luego ordenar cada parte
    split(ptr_inicio, ptr_final);
    
    cout << "Arreglo final (pares e impares ordenados):" << endl;
    for (int* B = ptr_inicio; B < ptr_final; B++) {
        cout << "[" << *B << "] ";
    }
    cout << endl;

    return 0;
}
