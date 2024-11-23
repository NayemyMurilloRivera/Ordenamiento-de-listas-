#include <iostream>
using namespace std;

struct asc {
    bool operator()(int a, int b) const {
        return a < b;
    }
};

struct desc {
    bool operator()(int a, int b) const {
        return a > b;
    }
};


template <class O>
class pivot {
    
public:
    O decision;
    int pivote;
    pivot(int p) : pivote(p) {}
    bool operator()(int valor) const {
        return decision(valor, pivote);
    }
};
template <class T, class FunctorPivot>
void transformar(T* inicio, T* fin, FunctorPivot functor) {
    T* i = inicio;
    T* j = fin;
    int* position= nullptr;
    for (int* a = i; a < j; ) {
        bool opcion = true;
        if (functor(*a)) {
            a++;
        }
        if (*a==functor.pivote) {
            position = a;
            a++;
        }
        else {
            
            while (opcion) {
                if (!functor(*j)) {
                    j--;
                }
                if (*j == functor.pivote) {
                    position =j;
                    j--;

                }
                else {
                    opcion = false;
                    swap(*j, *a);

                }
            }
        }
    }

    if (functor(*j)) {
        swap(*j, *position);
        cout << *j << endl;
    }
}


int main() {

    int arr[] = { 1 , 13 , 28 , 15 , 3 , 5 , 30 , 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int pivote = 15;

    pivot<asc> ordenarAsc( pivote);
    transformar(arr, arr + n - 1, ordenarAsc);

    for (int* ptr = arr; ptr != arr + n; ++ptr) {
        cout << *ptr << " ";
    }
    cout << endl;

    int arr2[] = { 1 , 13 , 28 , 15 , 3 , 5 , 30 , 8 };
    pivot<desc> ordenarDesc( pivote);


    transformar(arr2, arr2 + n - 1, ordenarDesc);
    ;
    for (int* ptr = arr2; ptr != arr2 + n; ++ptr) {
        cout << *ptr << " ";
    }
    cout << endl;

    return 0;
}
