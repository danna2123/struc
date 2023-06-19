#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct n{
	int dato;
	struct n*sgt;
}Nodo;

Nodo *crearNodo(int dato, Nodo* sgt);
void insertar_cab(Nodo *&cab, int dato);
void insertar_desp(Nodo *cab, int datoi, int datob);
void insertar_antes(Nodo *&cab, int datoi, int datob);
void eliminar(Nodo *&cab int dato);
Nodo * buscar(Nodo *cab, int dato);
void imprimir(Nodo *cab);

int main (){
	
	Nodo *cab=NULL;
	insertar_cab(cab,15);
	insertar_cab(cab,16);
	insertar_cab(cab,18);
	insertar_desp(cab,17,16);
	
	imprimir(cab);
	
	return 0;
}

Nodo *crearNodo(int dato, Nodo* sgt){
	Nodo* nuevo_nodo =(Nodo*)malloc(sizeof(Nodo));
	nuevo_nodo->dato = dato;
	nuevo_nodo->sgt = sgt;
	return nuevo_nodo;
}

void insertar_desp(Nodo *cab, int datoi, int datob){
	Nodo *p = buscar(cab, datob);
	if(p!=NULL){
		Nodo *q=crearNodo(datoi,p->sgt);
		p->sgt=q;
	}
}

void insertar_cab(Nodo *&cab, int dato){
	Nodo *p = crearNodo(dato,NULL);
	if(cab==NULL){
		cab=p;
		cab->sgt=cab;
	}else{
		Nodo *p=crearNodo(dato,NULL);
		p->sgt=cab->sgt;
		cab->sgt=p;
		cab=p;
	}
}

Nodo * buscar(Nodo *cab, int dato){
	if(cab!=NULL){
		Nodo *p=cab;
		do{
			if(p->dato==dato){
				return p;
			}
			p=p->sgt;
		}while(p!=cab);
	}
	return NULL;
}

void eliminar(Nodo *&cab int dato){
	Nodo *p=cab, *ant=NULL;
	int sw=0;
	do{
		if(p->dato==dato){
			sw=1;
			break
		}
		p=p->sgt;
	}while(p!=cab);
	if(sw!=0){
		if(ant==NULL){
		}
	}
}

void imprimir(Nodo *cab){
    if(cab!=NULL){
        Nodo *p = cab->sgt;
        while(p!=cab){
            cout<<p->dato<<"->";
            p=p->sgt;
        }
        cout<<p->dato<<"->NULL ";
    }
}







