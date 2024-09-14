#include <iostream>
using namespace std;

void merge1(int* inicio, int* medio, int* final) {
    int* ptr_inicio = inicio;
    int* ptr_medio = medio;
    int* ptr_final = final;

    while (ptr_medio < ptr_final +1) {
        for (int* p = ptr_inicio; p < ptr_final; p++) {
            while (*p > *ptr_medio) {
                swap(*p, *ptr_medio);
                break;
                if (*p == *ptr_medio) {
                    ptr_medio++;
                    break;
                }
            }
        }

        ptr_medio++;
    }
    cout << "Arreglo resultante:" << endl;
    for (int* A = ptr_inicio ; A < ptr_final+1 ; A++) {
        cout << "[" << *A << "] ";
    }
}

void merge2(int* inicio, int* medio, int* final) {
    int* ptr_inicio = inicio;
    int* ptr_medio = medio;
    int* ptr_final = final;


    while (ptr_medio <= ptr_final) {
        int* p = ptr_inicio;  
        while (p < ptr_medio){
            if (*p > *ptr_medio) {
                swap(*p, *ptr_medio);
            }
            p++;  
        }
        ptr_medio++;
    }

    cout << "Arreglo resultante:" << endl;
    for (int* B = inicio; B <= final; B++) {
        cout << "[" << *B << "] ";
    }
}

int main() {
    //int lista[10] = { 2,6,8 ,10, 20, 1, 3,7, 11,15 };
    int lista[10] = { 2,678,10, 20, 303,7, 11,15 , 17, 21 };
    int* ptr_inicio = lista;
    int* ptr_medio = lista + 5;
    int* ptr_final = lista + 9;
    //merge1(ptr_inicio, ptr_medio, ptr_final);
    merge2(ptr_inicio, ptr_medio, ptr_final);

    return 0;
}
