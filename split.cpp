#include <iostream>
using namespace std;

void split(int* inicio, int* final) {
    int *primerImpar = final;
    bool sigue = true;
    while(inicio < final || sigue==true){
        sigue = false;
        for (int* p = inicio; p < final; ) {
            if (*p % 2 != 0) {
                int valorImpar = *p;
                for (int* q = p; q < final; q++) {
                
                    if ( *(q+1) == 9) {
                        sigue=false;
                    }
                    *q = *(q + 1);
                
                }
                *(final - 1) = valorImpar;
                final = primerImpar;
                sigue = true;
            
            }
            else {
                p++;
            }
        }
    }
}


void split1(int* inicio, int* final) {
    //int *primerImpar = final;
        for (int* p = inicio; p < final-1;) {
            if (*p % 2 != 0) {
                int valorImpar = *p;
                for (int* q = p; q < final; q++) {
                   /* if ( *(q+1) < *(final-1)) {
                        sigue=false;
                    }*/
                   *q = *(q + 1);
                
                }
                *(final - 1) = valorImpar;
                final --;
                
            
            }
            else {
                p++;
            }
        }
    
}



int main() {
    int lista[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int* ptr_inicio = lista;
    int* ptr_final = lista + 10;

    cout << "Arreglo inicial:" << endl;
    for (int* B = ptr_inicio; B < ptr_final; B++) {
        cout << "[" << *B << "] ";
    }
    cout << endl;

    split1(ptr_inicio, ptr_final);
    split(ptr_inicio, ptr_final);


    cout << "Arreglo final:" << endl;
    for (int* B = ptr_inicio; B < ptr_final; B++) {
        cout << "[" << *B << "] ";
    }
    cout << endl;

    return 0;
}