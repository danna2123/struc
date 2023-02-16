#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct n{
	int dato;
	struct n*sgt;
}Nodo;

Nodo *crearNodo(int dato, Nodo* sgt);
Nodo *buscar(Nodo *cab, int dato);
void insertar_cab(Nodo *&cab, int dato);
void insertar_cola(Nodo *&cab, int dato);
void insertar_desp(Nodo *&cab, int di, int db);
void insertar_antes(Nodo *&cab, int di, int db);
void imprimir(Nodo *p);

int main (){
	
	Nodo *cab=NULL;
	insertar_cab(cab,15);
	insertar_cab(cab,16);
	insertar_cab(cab,17);
	insertar_cola(cab,18);
	
	imprimir(cab);
	
	insertar_desp(cab,19,18);
	insertar_antes(cab,20,17);
	
	imprimir(cab);
	cout<<buscar(cab,5);
	
	return 0;
}

Nodo *crearNodo(int dato, Nodo* sgt){
	Nodo* nuevo_nodo =(Nodo*)malloc(sizeof(Nodo));
	nuevo_nodo->dato = dato;
	nuevo_nodo->sgt = sgt;
	return nuevo_nodo;
}



void insertar_cab(Nodo *&cab, int dato){
	Nodo *p = crearNodo(dato, cab);
	cab = p;
}

void insertar_cola(Nodo *&cab, int dato){
	/*
	if(cab==NULL){
		cab=cearNodo(d,NULL);
	}else{
		Nodo *p;
		for(p=cab;p->sgt!=NULL;p=p->sgt);
		p->sgt=crearNodo(d,NULL);
	}
	
	*/
	if(cab == NULL){
		crearNodo(dato, NULL);
	}else{
		Nodo* aux = cab;
		while(aux->sgt != NULL){
			aux = aux->sgt; 
		}
		aux->sgt = crearNodo(dato, NULL);
	}
}

void insertar_desp(Nodo *&cab, int di, int db){
	Nodo *p = buscar(cab,db);
	if(p != NULL){
		Nodo *q = crearNodo(di,NULL);
		q->sgt = p->sgt;
		p->sgt = q;
	}else{
		cout<<"No encontrado"<<endl;
	}
}

void insertar_antes(Nodo *&cab, int di, int db){
	Nodo *p=cab, *ant=NULL;
	while(p!=NULL){
		if(p->dato==db){
			break;
		}else{
			ant = p;
			p=p->sgt;
		}
	}
	if(ant !=NULL){
		Nodo *q=crearNodo(di,p);
		ant->sgt=q;
	}else{
		cab=crearNodo(di,cab);
	}
}

Nodo * buscar(Nodo *cab, int dato){
	Nodo *p;
	for(p=cab;p!=NULL;p=p->sgt){
		if(p->dato==dato){
			return p;
		}
	}
	return NULL;
}

void imprimir(Nodo *p){
	/*
	for(Nodo *p=cab; p!NULL;p=p->sgt){
	cout<<p->dato<<endl;
	}
	*/
	while(p!=NULL){
		cout<<"["<<p->dato<<"]-> ";
		p=p->sgt;
	}
	cout<<"NULL"<<endl;
}
