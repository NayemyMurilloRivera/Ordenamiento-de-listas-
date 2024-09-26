#include <iostream>
using namespace std;

void cok(int* inicio, int* fin) {
    int* ptr_inicio;
    int* ptr_final;
    bool sigue = true; 
    while (sigue) {
        sigue = false;  
        ptr_inicio = inicio;
        ptr_final = fin;
        while (ptr_inicio < ptr_final) {
            
            if (*ptr_inicio > *(ptr_inicio + 1)) {
                swap(*ptr_inicio, *(ptr_inicio + 1));
                sigue = true;  // 
            }
            ptr_inicio++;

            
            if (*ptr_final < *(ptr_final - 1)) {
                swap(*ptr_final, *(ptr_final - 1));
                sigue = true; 
            }
            ptr_final--;
        }
    }
}

int main() {
    int lista[9] = {9, 3, 6, 4, 7, 1, 5, 8, 2}; 
    int* ptr_inicio = lista;
    int* ptr_final = lista + 8;

    cout << "Arreglo inicial:" << endl;
    for (int* B = inicio; B <= fin; B++) {
        cout << "[" << *B << "] ";
    }
    cout << endl;

    cok(ptr_inicio, ptr_final);

    cout << "Arreglo tras split:" << endl;
    for (int* B = inicio; B <= fin; B++) {
        cout << "[" << *B << "] ";
    }
    cout << endl;

    return 0;
}
