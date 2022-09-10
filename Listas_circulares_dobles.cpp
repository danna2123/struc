#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct Nodo{
    char cad[20];
    struct Nodo* sig;
    struct Nodo* ant;
}NodoCD;

NodoCD* crear_nodo(NodoCD *a, char dato[20], NodoCD *s);
void insertar_cabeza(NodoCD *&cab, char dato[20]);
void imprimir(NodoCD *cab);
NodoCD *buscar(NodoCD *cab, char dato[20]);
void ingresar_datos(NodoCD *&cab);

int main(){
	
	NodoCD * cab=NULL;
	
	ingresar_datos(cab);
	imprimir(cab);
	cout<<buscar(cab,dato)->cad<<endl;
	
	return 0;
}

NodoCD* crear_nodo(NodoCD *a, char dato[20], NodoCD *s){
    NodoCD *nuevo_nodo = (NodoCD*) malloc (sizeof(NodoCD));
    strcpy(nuevo_nodo->cad,dato);
    nuevo_nodo->sig = s;
    nuevo_nodo->ant = a;
    return nuevo_nodo;
}

void insertar_cabeza(NodoCD *&cab, char dato[20]){
	NodoCD *aux = crear_nodo(NULL, dato, NULL);
    if(cab == NULL){
    	aux->sig = aux;
    	aux->ant = aux;
    }
    else{
        aux->sig= cab->sig;
        cab->sig = aux;
        aux->sig->ant = aux;
        aux->ant = cab;
    }
    cab = aux;
}

NodoCD *buscar(NodoCD *cab, char dato[20]){
	if(cab != NULL){
		NodoCD *aux = cab;
		do{
			if(strcmp(aux->cad,dato)==0){
				return aux;
			}
			aux=aux->sig;
		}while(aux!=cab);
	}
	return NULL;
}

void ingresar_datos(NodoCD *&cab){
	NodoCD *aux = cab;
	int n;
	cout<<"ingrese la cantidad de jugadores: ";
    cin>>n;
    if(n>=1 && n<=12){

	 	for(int i=0;i<n;i++){
		    char nombre[20];
	 		cout<<"ingrese el nombre del jugador: ";
	        cin>>nombre;
	 		insertar_cabeza(cab,nombre);
	    }
	    if(n<7){
	 			cout<<"Se jugara con un dado"<<endl;
			 }else{
			 	cout<<"Se jugara con dos dados"<<endl;
			 }
	}else{
		cout<<"numero de jugadores no permitidos ";
	}
}

void imprimir(NodoCD *cab){
	NodoCD *aux = cab->ant;
	while(aux!=cab){
		cout << "[" << aux->cad << "]-> ";
        aux = aux->ant;
	}
	if(aux==cab){
		cout << "[" << cab->cad << "]"<<endl;	
	}
}

