#include <iostream>
using namespace std;


void split1(int* inicio, int* final) {
    int* f = final;
    for (int* p = inicio; p < f; p++, f--) {
        swap(p, f);
    }
    final = f;
    int* inicioImpar = final;

    for (int* q = inicio; q < final; q++) {
        if (q < inicioImpar) {
            if (*q % 2 != 0) {
                swap(*q, *inicioImpar);
                inicioImpar--;
            }
        }
    }
    
    
}



int main() {
    int lista[9] = {9, 7, 5 , 3 , 1 , 2, 4 , 8, 10};
    //int lista[5] = { 1, 3 , 5 , 7 , 10 };
    //int lista[8] = { 1, 1 , 3 , 5 ,7, 9, 15, 10 };
    int* ptr_inicio = lista;
    int* ptr_final = lista + 9;
    //int* ptr_final = lista + 8;


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
