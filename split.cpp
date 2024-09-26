#include <iostream> 
using namespace std; 

void split( int * inicio , int * final){
  int * p=inicio;
  int * q= final; 
  while (p< q ){
     if (*p % 2!=0){
        int  temp = *p;
        for ( int * r = p ; r <q ; r++){
            *r = *(r+1); 
        }
        *q=temp;
     }
     else {
        p++;
     
     }
 }    
 
 int main() {
    int lista[10] = {1,2,3,4,5,6,7,8,9,10};
    int* ptr_inicio = lista;
    int* ptr_medio = lista + 5;
    int longi = obtener_longitud_array(ptr_inicio, ptr_medio);  
    int* ptr_final = ptr_inicio + longi; 

    cout << "Arreglo inicial:" << endl;
    for (int* B = ptr_inicio; B < ptr_final; B++) {  
        cout << "[" << *B << "] ";
    }
    cout << endl;

    split(ptr_inicio, ptr_final ); 

    cout << "Arreglo resultante:" << endl;
    for (int* B = ptr_inicio; B < ptr_final; B++) {  
        cout << "[" << *B << "] ";
    }

    return 0;
}