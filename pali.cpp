#include <cstring>
#include <iostream>
using namespace std;

void mayus(char *p, int total) {
  for (int i = 0; i < total; i++) {
    if (*(p + i) >= 'a' && *(p + i) <= 'z') {
      *(p + i) = *(p + i) - 32;
    }
  }
}

bool palindromo(char *p, int total) {
  char *i = p;
  char *f = p + total - 1;

  for (char *r = i; r < f; r++, f--) {
    if (*r == ' ') {
      r++;
    }

    if (*f == ' ') {
      f--;
    }

    if (*r != *f) {
      return false; 
    }
  }
  return true; 
}

int main() {
  char frase[100];
  cout << "Ingrese una frase: ";
  cin.getline(frase, 100);
  char *p = frase;
  int total = strlen(frase);
  mayus(p, total);
    
  bool quees = palindromo(frase, total);
  if (quees == true) {
    cout << "Es un palíndromo" << endl;
  } else {
    cout << "No es un palíndromo" << endl;
  }

  return 0;
}

// ejemplo A luna ese anula
//Aji traga la lagartija
