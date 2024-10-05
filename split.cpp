#include <iostream>
using namespace std;

/*Esta función recorre el elemento *inicio hasta *(final - 1)*/
void arreglar(int* inicio, int* final) {
    int *f = final - 1;
    while (inicio < f) {
        swap(*inicio, *f);
        f--;
    }
}

/*Función split*/
void split(int* inicio, int* final) {
    while (inicio < final-2) { /*Esta condicional solo funciona para este array tienes que encontrar una condicional general*/
        if (*inicio % 2 != 0) { /*Si *inicio es impar, entonces lo intercambia con *final y luego llama a la función arreglar*/
            swap(*inicio, *final);
            arreglar(inicio, final); /*Llamada a la función arreglar*/
        }
        inicio++; /*Hace que inicio apunte al siguiente elemento del array*/
    }
}

int main() {
    int lista[8] = { 1, 2, 3, 4, 5, 6 , 8 ,  };
    int* ptr_inicio = lista;
    int* ptr_final = lista + 8; /*Corrección realizada para que el puntero no se salga del array*/

    cout << "Arreglo inicial:" << endl; 
    for (int* B = ptr_inicio; B <= ptr_final; B++) { /*Imprime el arreglo (recomiendo declararlo como función)*/
        cout << "[" << *B << "] ";
    }
    cout << endl;

    split(ptr_inicio, ptr_final); /*Llamada a función split*/

    cout << "Arreglo final:" << endl;
    for (int* B = ptr_inicio; B <= ptr_final; B++) { /*Imprime el arreglo modificado (recomiendo declararlo como función)*/
        cout << "[" << *B << "] ";
    }
    cout << endl;

    return 0;
}