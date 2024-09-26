#include <iostream>
using namespace std;

int obtener_longitud_array(int* inicio, int* medio) {
    return (medio - inicio) * 2;
}

void merge(int* inicio, int* medio) {
    int* ptr_inicio = inicio;
    int* ptr_medio = medio;
    int longi = obtener_longitud_array(ptr_inicio, ptr_medio);
    int* ptr_final = inicio + longi;  

    while (ptr_medio < ptr_final) {
        int* p = ptr_inicio;
        while (p < ptr_medio) {
            if (*p > *ptr_medio) {
                swap(*p, *ptr_medio);
            }
            p++;
        }
        ptr_medio++;
    }
}

int main() {
    int lista[10] = {2, 1155, 10, 20, 303, 7, 11, 15, 17, 21};
    int* ptr_inicio = lista;
    int* ptr_medio = lista + 5;
    int longi = obtener_longitud_array(ptr_inicio, ptr_medio);  
    int* ptr_final = ptr_inicio + longi; 

    cout << "Arreglo inicial:" << endl;
    for (int* B = ptr_inicio; B < ptr_final; B++) {  
        cout << "[" << *B << "] ";
    }
    cout << endl;

    merge(ptr_inicio, ptr_medio); 

    cout << "Arreglo resultante:" << endl;
    for (int* B = ptr_inicio; B < ptr_final; B++) {  
        cout << "[" << *B << "] ";
    }

    return 0;
}

