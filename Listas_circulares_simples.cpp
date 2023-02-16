#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct Nodo{
    int dato;
    struct Nodo* sig;
}NodoA;


NodoA* crear_nodo(NodoA* cabecera, int dato);
void insertar_cabeza(NodoA*& cabecera, int dato);
void insertar_cola(NodoA*& cabecera, int dato);
NodoA* buscar(NodoA* cabecera, int dato);
void mostrar(NodoA* cabecera);
void eliminar(NodoA*& cabecera, int dato);
void insertar_despues(NodoA*& cabecera, int despues_de, int dato_nuevo);
void insertar_antes(NodoA*& cabecera, int antes_de, int dato_nuevo);
void repetir_lista(NodoA* cabecera, int cantidad);

int main() {
    NodoA* puntero_lista = NULL;
    mostrar(puntero_lista);
    insertar_cola(puntero_lista, 1);
    mostrar(puntero_lista);
    insertar_cola(puntero_lista, 2);
    mostrar(puntero_lista);
    insertar_cola(puntero_lista, 3);
    mostrar(puntero_lista);
    insertar_cola(puntero_lista, 4);
    mostrar(puntero_lista);
    insertar_cola(puntero_lista, 5);
    mostrar(puntero_lista);
    cout << "a repetir lista..." << endl;
    repetir_lista(puntero_lista, 3);


    return 0;
}

NodoA* crear_nodo(NodoA* cabecera, int dato){
    NodoA* nuevo_nodo = (NodoA*) malloc (sizeof(NodoA));
    nuevo_nodo->dato = dato;
    nuevo_nodo->sig = cabecera;
    return nuevo_nodo;
}

void insertar_cabeza(NodoA*& cabecera, int dato){
    if(cabecera == NULL){
        cabecera = crear_nodo(NULL, dato);
        cabecera->sig = cabecera;
    }
    else{
        NodoA* nuevo_nodo = crear_nodo(cabecera->sig, dato);
        cabecera->sig = nuevo_nodo;
        cabecera = nuevo_nodo;
    }
}

void insertar_cola(NodoA*& cabecera, int dato){
    if(cabecera == NULL){
        cabecera = crear_nodo(NULL, dato);
        cabecera->sig = cabecera;
    }
    else{
        NodoA* aux = cabecera;
        do{
            aux = aux->sig;
        } while(aux->sig != cabecera);
        aux->sig = crear_nodo(cabecera, dato);
    }
}

NodoA* buscar(NodoA* cabecera, int dato){
    NodoA* aux = cabecera;
    if(cabecera != NULL){
        do{
            if(aux->dato == dato){
                return aux;
            }
            aux = aux->sig;
        } while(aux != cabecera);
    }
    return NULL;
}

void eliminar(NodoA*& cabecera, int dato){
    NodoA* nodo_eliminar = buscar(cabecera, dato);
    if (nodo_eliminar != NULL){
        if(nodo_eliminar == cabecera && nodo_eliminar->sig == cabecera){
            cabecera = NULL;
            delete(nodo_eliminar);
        }
        else{
            NodoA* aux = cabecera;
            do{
                aux = aux->sig;
            } while(aux->sig != nodo_eliminar);
            aux->sig = nodo_eliminar->sig;
            if(nodo_eliminar == cabecera){
                cabecera = cabecera->sig;
            }
            delete(nodo_eliminar);
        }
    }
    else{
        cout << "No encontrado!" << endl;
    }
}

void mostrar(NodoA* cabecera){
    NodoA* aux = cabecera;
    cout << "CAB->";
    if(cabecera != NULL){
        do{
            cout << "[" << aux->dato << "]->";
            aux = aux->sig;
        }while(aux != cabecera);
    }
    cout << "CAB" << endl;
}

void insertar_despues(NodoA*& cabecera, int despues_de, int dato_nuevo){
    NodoA* nodo_objetivo = buscar(cabecera, despues_de);
    if (nodo_objetivo != NULL){
        NodoA* nuevo_nodo = crear_nodo(nodo_objetivo->sig, dato_nuevo);
        nodo_objetivo->sig = nuevo_nodo;
    }
    else{
        cout << "No encontrado" << endl;
    }
}

void insertar_antes(NodoA*& cabecera, int antes_de, int dato_nuevo){
    NodoA* nodo_objetivo = buscar(cabecera, antes_de);
    if (nodo_objetivo != NULL){
        NodoA* aux = cabecera;
        do{
            aux = aux->sig;
        } while(aux->sig != nodo_objetivo);
        NodoA* nuevo_nodo = crear_nodo(nodo_objetivo, dato_nuevo);
        aux->sig = nuevo_nodo;
        if (nuevo_nodo->sig == cabecera){
            cabecera = nuevo_nodo;
        }
    }
    else{
        cout << "No encontrado" << endl;
    }
}

void repetir_lista(NodoA* cabecera, int cantidad){
    NodoA* aux = cabecera;
    if(aux != NULL){
        for(int i = 0; i < cantidad; i++){
            mostrar(cabecera);
        }
        cout << "Se ha repetido la lista: " << cantidad << " veces." << endl;
    }
    else{
        cout << "lista vacia" << endl;
    }

}
