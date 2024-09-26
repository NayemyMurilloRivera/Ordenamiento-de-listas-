include <iostream> 
using namespace std; 

bool palindromo(char * p){
   int contador=0;
   bool sigue = true;
   char *i=p+0;
   while (true){
       if (*i !='\0') {
          contador ++;
       }
   }    
   
   char * f= p+ contador;
   while ((i<f) && sigue){
       if (i == f) {
           sigue = true;
           return true;
       
       }
       else{    
           break;
           return false;
       }
       
   
   }
   
   
}

 
 int main() {
    char * frase ;
    cout << "Ingrese una frase"; cin >> frase;
    bool quees= palindromo(frase);
    if (quees==true){
        cout <<"Es un palindromo";
    
    }
    else{
        cout << "pipipi";
    
    
    }

    return 0;
}