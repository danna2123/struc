/*Lauren Dayanna González Cárdenas 2020114016
Danna Lozano Caselles 2022214106*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;

typedef struct Nodo{
    char cad[20];
    struct Nodo* sig;
    struct Nodo* ant;
}NodoCD;

NodoCD* crear_nodo(NodoCD *a, char dato[20], NodoCD *s);
void insertar_cabeza(NodoCD *&cab, char dato[20]);
void imprimir(NodoCD *cab);
NodoCD *buscar(NodoCD *cab, int pos);
void ingresar_datos(NodoCD *&cab);
void limpiar_pantalla();
void eliminar(NodoCD *&cab, char pos);
void Numero_aleatorio();

int main(){
	
	NodoCD * cab=NULL;
	
	ingresar_datos(cab);
	
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

NodoCD *buscar(NodoCD *cab, int pos){
	NodoCD *aux = cab;
	if(cab != NULL){
		for(int i=1; i<pos; i++)
			aux=aux->sig;
	}
	return aux;
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
	    
	    limpiar_pantalla();
	    cout<<"Estos son los jugadores: ";
	    imprimir(cab); 
	    cout<<"El jugador que incia es: "<<buscar(cab, 2)->cad<<endl;
	    imprimir(cab);
		    if(n<7){
		 		cout<<"Se jugara con un dado"<<endl;
		 		for(int i=0;i<6;i++){
			 	    int dado = Numero_aleatorio();
					cout<<"Usted debe moverse "<<dado<<"posicion"<<endl;
				}
			}else{
				cout<<"Se jugara con dos dados"<<endl;
				Numero_aleatorio();
				cout<<"Usted debe moverse "<<Numero_aleatorio()<<" pocisiones"<<endl;
			}
	}else{
		cout<<"numero de jugadores no permitidos ";
	}
}

void Numero_aleatorio(){
	srand(time(NULL));
	int dado;
	dado = rand()%6;
	return dado;
}

void eliminar(NodoCD *&cab, int pos){
	NodoCD* nodo_eliminar = buscar(cabecera, pos);
	 if (nodo_eliminar  != NULL){
        if(nodo_eliminar == cab && nodo_eliminar->sig == cab){
            cab = NULL;
            delete(nodo_eliminar );
            
        }else{
        	NodoCD* aux = cab;
        	aux->ant->sig = aux->sig;
        	aux->sig->ant = aux->ant;
        	aux=aux->sig;
        	delete(nodo_eliminar );
		}
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

void limpiar_pantalla(){
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}
