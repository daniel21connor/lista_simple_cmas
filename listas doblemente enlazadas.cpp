#include <iostream>
#include <cctype>
 
using namespace std;
 
const int ASCENDENTE = 1;
const int DESCENDENTE = 0;
 
struct Personal {
    string nombre;
    string direccion;
    int telefono;
    string correo;
};
 
typedef struct Nodo {
    Personal datos;
    struct Nodo *siguiente;
    struct Nodo *anterior;
} tipoNodo;
 
typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;
 
 
void Insertar(Lista *l, Personal v);
void BorrarLista(Lista *);
void MostrarLista(Lista l, int orden);
 
int main() {
 
    Personal v;
    Lista lista = NULL;
    pNodo p;
 
    char c;
    do {
        cout << "\nNombre: "; getline( cin, v.nombre );
        cout << "Direccion: "; getline( cin, v.direccion );
        cout << "Telefono: "; cin >> v.telefono;
        cin.ignore();
        cout << "Correo: "; getline( cin, v.correo );
 
        Insertar(&lista, v);
 
        cout << "\nInsertar mas datos (S/n): "; cin >> c;
        cin.ignore();
        c = toupper( c );
 
    }while( c == 'S');
 
    MostrarLista(lista, ASCENDENTE);
    MostrarLista(lista, DESCENDENTE);
 
    BorrarLista(&lista);
 
   return 0;
}
 
void Insertar(Lista *lista, Personal v) {
   pNodo nuevo, actual;
 
   nuevo = new Nodo;
   nuevo->datos.nombre = v.nombre;
   nuevo->datos.direccion = v.direccion;
   nuevo->datos.telefono = v.telefono;
   nuevo->datos.correo = v.correo;
 
   actual = *lista;
   if(actual) while(actual->anterior) actual = actual->anterior;
 
   if(!actual || actual->datos.nombre > v.nombre) {
      nuevo->siguiente = actual;
      nuevo->anterior = NULL;
      if(actual) actual->anterior = nuevo;
      if(!*lista) *lista = nuevo;
   }
   else {
      while(actual->siguiente &&actual->siguiente->datos.nombre <= v.nombre)
         actual = actual->siguiente;
 
      nuevo->siguiente = actual->siguiente;
      actual->siguiente = nuevo;
      nuevo->anterior = actual;
      if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
   }
}
 
void BorrarLista(Lista *lista) {
   pNodo nodo, actual;
 
   actual = *lista;
   while(actual->anterior) actual = actual->anterior;
 
   while(actual) {
      nodo = actual;
      actual = actual->siguiente;
      delete(nodo);
   }
   *lista = NULL;
}
 
void MostrarLista(Lista lista, int orden) {
   pNodo nodo = lista;
 
   if(!lista) cout << "\nLista vacía";
 
   nodo = lista;
   if(orden == ASCENDENTE) {
      while(nodo->anterior) nodo = nodo->anterior;
      cout << "\nOrden ascendente: ";
      cout << "\n";
      while(nodo) {
         cout << nodo->datos.nombre << " "
              << nodo->datos.direccion << " "
              << nodo->datos.telefono << " "
              << nodo->datos.correo << "\n";
 
         nodo = nodo->siguiente;
      }
   }
   else {
      while(nodo->siguiente) nodo = nodo->siguiente;
      cout << "\nOrden descendente: ";
      cout << "\n";
      while(nodo) {
         cout << nodo->datos.nombre << " "
              << nodo->datos.direccion << " "
              << nodo->datos.telefono << " "
              << nodo->datos.correo << "\n";
 
         nodo = nodo->anterior;
      }
   }
 
   cout << endl;
}
