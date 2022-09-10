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
	insertar_cabeza(cab,"juan");
	insertar_cabeza(cab,"pedro");
	insertar_cabeza(cab,"ana");
	insertar_cabeza(cab,"maria");
	imprimir(cab);
	cout<<buscar(cab,"ana")->cad<<endl;
	
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
	char nombre;
	cout<<"ingrese la cantidad de jugadores"<<endl;cin>>n;
 	for(int i=0;i<n;i++){
 		cout<<"ingrese el nombre del jugador"<<endl;cin>>nombre;
 		cab = crear_nodo(NULL,nombre,aux->sig);
	 }
	imprimir(cab);	 
}

void imprimir(NodoCD *cab){
	NodoCD *aux = cab->ant;
	while(aux!=cab){
		cout << "[" << aux->cad << "]"<<endl;
        aux = aux->ant;
	}
	if(aux==cab){
		cout << "[" << cab->cad << "]"<<endl;	
	}
}
