#include <iostream>
using namespace std;

template <class T>
class nodo {
  public:
    T valor;
    nodo* next;
    nodo(T v, nodo* n = nullptr) {
      valor = v;
      next = n;
    }
};

template <class T>
class LE {
  nodo<T> *head = nullptr;

  public:
    void print();
    bool find(T v, nodo<T> *&pos);
    void add(T v);
    void del(T v);
    ~LE();
};

template <class T>
void LE<T>::print() {
  if (!head) {
    cout << "Head->NULL" << endl;
    return;
  }

  cout << "Head->";
  nodo<T>* p = head;
  do {
    cout << p->valor << "->";
    p = p->next;
  } while (p != head);
  cout << "Head" << endl; // Indica que es circular
}

template <class T>
bool LE<T>::find(T v, nodo<T> *&pos) {
  bool encontrado = false;
  pos = nullptr;

  if (!head) return false; // La lista está vacía

  nodo<T>* p = head;
  do {
    if (p->valor == v) {
      encontrado = true;
      break;
    }
    pos = p;
    p = p->next;
  } while (p != head && p->valor <= v);
  
  return encontrado;
}

template <class T>
void LE<T>::add(T v) {
  nodo<T>* pos_ant;
  if (!find(v, pos_ant)) {
    if (pos_ant) {
      pos_ant->next = new nodo<T>(v, pos_ant->next);
      if (pos_ant->next->next == head) {
        pos_ant->next->next = head;
      }
    } else {
      head = new nodo<T>(v);
      head->next = head; // Punto clave para hacerla circular
    }
  }
}

template <class T>
void LE<T>::del(T v) {
  nodo<T> *pos_ant, *pos_del;
  if (find(v, pos_ant)) {
    if (pos_ant) {
      pos_del = pos_ant->next;
      pos_ant->next = pos_del->next;
      if (pos_del == head) { // Si el nodo a eliminar es la cabeza
        head = head->next;
      }
      delete pos_del;
    } else {
      pos_del = head;
      if (head->next == head) { // Caso de un solo elemento
        delete head;
        head = nullptr;
      } else {
        nodo<T>* temp = head;
        while (temp->next != head) temp = temp->next;
        head = pos_del->next;
        temp->next = head;
        delete pos_del;
      }
    }
  }
}

template <class T>
LE<T>::~LE() {
  while (head) del(head->valor);
}

// Main para probar la lista circular
int main() {
  LE<int> lista;

  cout << "Agregando elementos a la lista: 1-2-3-4-5" << endl;
  lista.add(1);
  lista.add(2);
  lista.add(3);
  lista.add(4);
  lista.add(5);
  lista.print();

  cout << "Eliminando el elemento 2:" << endl;
  lista.del(2);
  lista.print();

  cout << "Agregando elementos a la lista: 6-7" << endl;
  lista.add(6);
  lista.add(7);
  lista.print();

  cout << "Eliminando head:" << endl;
  lista.del(1);
  lista.print();

  return 0;
}
