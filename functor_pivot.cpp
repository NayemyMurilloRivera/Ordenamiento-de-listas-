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


template <class T, class O>
class pivot {
    O decision;  
    T pivote;    
public:
    pivot(O dec, T p) : decision(dec), pivote(p) {}
    bool operator()(T valor) const {
        return decision(valor, pivote);
    }
};
template <class T, class FunctorPivot>
void transformar(T* inicio, T* fin, FunctorPivot functor) {
    T* i = inicio;
    T* j = fin;

    while (i <= j) {
        while (i <= j && functor(*i)) {
            ++i;
        }
  
        while (i <= j && !functor(*j)) {
            --j;
        }
        
        if (i < j) {
            T temp = *i;
            *i = *j;
            *j = temp;
            ++i;
            --j;
        }
    }
}


int main() {
    
    int arr[] = { 1 , 13 , 28 , 15 , 3 , 5 , 30 , 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int pivote = 15;  

    pivot<int, asc> ordenarAsc(asc(), pivote);
    transformar(arr, arr + n - 1, ordenarAsc);

    for (int* ptr = arr; ptr != arr + n; ++ptr) {
        cout << *ptr << " ";
    }
    cout << endl;

    int arr2[] = { 1 , 13 , 28 , 15 , 3 , 5 , 30 , 8 };
    pivot<int, desc> ordenarDesc(desc(), pivote);

 
    transformar(arr2, arr2 + n - 1, ordenarDesc);
;
    for (int* ptr = arr2; ptr != arr2 + n; ++ptr) {
        cout << *ptr << " ";
    }
    cout << endl;

    return 0;
}
