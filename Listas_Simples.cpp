#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct Nodo{
    int dato;
    struct Nodo* sig;
}NodoA;

NodoA* crear_nodo(NodoA* cabecera, int dato); //98
void insertar_cabeza(NodoA*& cabecera, int dato); //105
void insertar_cola(NodoA*& cabecera, int dato); //109
int buscar(NodoA* cabecera, int dato); //122
void mostrar(NodoA* cabecera); //141
void eliminar(NodoA*& cabecera, int dato); //163
void promedio (NodoA* cabecera); //38
void insertar_antes(NodoA*& cabecera, int posicion ,int dato); //50
void insertar_despues(NodoA*& cabecera,int posicion, int dato); //62
void insertar_ordenado(NodoA*& cabecera, int dato); //72

int main() {

    NodoA* puntero_lista = NULL;
    insertar_ordenado(puntero_lista, 12);
    insertar_ordenado(puntero_lista, 3);
    insertar_ordenado(puntero_lista, 4);
    insertar_ordenado(puntero_lista, 5);
    insertar_ordenado(puntero_lista, 20);
    insertar_despues(puntero_lista,0, 30);
    
    mostrar(puntero_lista);
    
    
    return 0;
}

void promedio (NodoA* cabecera){
	float prom=0,cantidad=0, total;
	NodoA* aux = cabecera;
	while (aux != NULL){
		prom = aux->dato + prom;
		cantidad++; 
		aux = aux->sig;
	}
	total= prom /cantidad;
	cout<<"El promedio es: "<<total<<endl;	
}

void insertar_antes(NodoA*& cabecera, int posicion ,int dato){
        NodoA* aux = cabecera;
        if(posicion == 0){
        	cabecera = crear_nodo(cabecera, dato);
        }
        else{
            for(int i = 0; i < posicion-1; i++){
                aux = aux->sig;
            }
        	aux->sig = crear_nodo(aux->sig, dato);	
    	}
}
void insertar_despues(NodoA*& cabecera,int posicion, int dato){
    NodoA* aux = cabecera;
    if(posicion != 0){
    	for(int i = 0; i < posicion; i++){
            aux = aux->sig;
        }
    }else{
		aux->sig = crear_nodo(aux->sig, dato);
	}
}

void insertar_ordenado(NodoA*& cabecera, int dato){
	if(cabecera == NULL){
		cabecera = crear_nodo(NULL, dato);
	}
	else{
		bool insertado = false;
		Nodo* aux = cabecera;
		if (aux->dato > dato){
			cabecera = crear_nodo(cabecera, dato);
		}
		else{
			while(aux->sig != NULL){
				if(aux->sig->dato > dato){
					aux->sig = crear_nodo(aux->sig, dato);
					insertado = true;
					break;
				}
				aux = aux->sig;
			}
			if (insertado == false){
				aux->sig = crear_nodo(aux->sig, dato);
			}
		}
	}
}

NodoA* crear_nodo(NodoA* cabecera, int dato){
    NodoA* nuevo_nodo = (NodoA*) malloc (sizeof(NodoA));
    nuevo_nodo->dato = dato;
    nuevo_nodo->sig = cabecera;
    return nuevo_nodo;
}

void insertar_cabeza(NodoA*& cabecera, int dato){
    cabecera = crear_nodo(cabecera, dato);
}

void insertar_cola(NodoA*& cabecera, int dato){
    if(cabecera == NULL){
        cabecera = crear_nodo(cabecera, dato);
    }
    else{
        NodoA* aux = cabecera;
        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = crear_nodo(NULL, dato);
    }
}

int buscar(NodoA* cabecera, int dato){
    int posicion = 0, encontrado = 0;
    NodoA* aux = cabecera;
    while(aux != NULL){
        if(aux->dato == dato){
            encontrado = 1;
            break;
        }
        posicion++;
        aux = aux->sig;
    }
    if(encontrado == 1){
        return posicion;
    }
    else{
        return -1;
    }
}

void eliminar(NodoA*& cabecera, int dato){
    int posicion = buscar(cabecera, dato);
    if (posicion != -1){
        NodoA* aux = cabecera;
        if(posicion == 0){
            cabecera = cabecera->sig;
            free(aux);
        }
        else{
            for(int i = 0; i < (posicion - 1); i++){
                aux = aux->sig;
            }
            NodoA* nodo_eliminar = aux->sig;
            aux->sig = nodo_eliminar->sig;
            free(nodo_eliminar);
        }
    }
    else{
        cout << "No encontrado!" << endl;
    }
}

void mostrar(NodoA* cabecera){
    cout << "CAB->";
    NodoA* aux = cabecera;
    while(aux != NULL){
        cout << "[" << aux->dato << "]->";
        aux = aux->sig;
    }
    cout << "NULL" << endl;
}
