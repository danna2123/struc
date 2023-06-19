#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct n{
	int dato;
	struct n*sgt;
	struct n*ant;
}NodoD;

NodoD *crearNodo(NodoD *ant, int dato, NodoD *sgt);
NodoD *buscar(NodoD *cab, int dato);
void eliminar(NodoD *&cab, int dato);
void insetar_cab(NodoD *&cab, int dato);
void insetar_cola(NodoD *&cab, int dato);
void insertar_des(NodoD *cab,int datoI, int datoD);
void insertar_antes(NodoD *&,int datoI, int datoD);
void imprimir(NodoD *p);

int main(){
	NodoD *cab=NULL;
	insetar_cab(cab,15);
	insetar_cab(cab,16);
	insetar_cab(cab,17);
	insetar_cola(cab,18);
	insertar_des(cab, 19,15);
	eliminar(cab,16);
	imprimir(cab);
	//cout<<buscar(cab,18)->dato;
	return 0;
}

NodoD * crearNodo(NodoD *ant, int dato, NodoD *sgt){
	NodoD *p = (NodoD*)malloc(sizeof(NodoD));
	p->dato=dato;
	p->ant=ant;
	p->sgt=sgt;
}

NodoD *buscar(NodoD *cab, int dato){
	for(NodoD *p=cab; p!=NULL;p=p->sgt){
		if(p->dato==dato){
			return p;
		}
	}
	return NULL;
}

void insertar_des(NodoD *cab,int datoI, int datoD){
	NodoD *p = buscar(cab,datoD);
	if(p!=NULL){
		NodoD *q=crearNodo(NULL,datoI,NULL);
		q->sgt=p->sgt;
		q->ant=p;
		p->sgt=q;
		if(q->sgt!=NULL)
			q->sgt->ant=q;
	}
} 

void insertar_antes(NodoD *&cab,int datoI, int datoD){
	NodoD *p = buscar(cab,datoD);
	if(p!=NULL){
		NodoD *q = crearNodo(p->ant,datoI,p);
		p->ant=q;
		if(q->ant!=NULL){
			q->ant->sgt=q;
		}else{
		}
	}
}

void insetar_cab(NodoD *&cab, int dato){
	NodoD *p = crearNodo(NULL,dato,cab);
	if(cab !=NULL)
		cab->ant=p;
	cab=p;
}

void insetar_cola(NodoD *&cab, int dato){
	NodoD *p;
	if(cab==NULL){
		cab=crearNodo(NULL,dato,NULL);
	}else{
		for(p=cab;p->sgt!=NULL;p=p->sgt);
		p->sgt=crearNodo(p,dato,NULL);	
	}
}

void eliminar(NodoD *&cab, int dato){
	NodoD *p = buscar(cab, dato);
	if (p!=NULL){
		if(p->ant==NULL){
			cab=cab->sgt;
		}else{
			p->ant->sgt=p->sgt;
		}
		if(p->sgt!=NULL){
			p->sgt->ant=p->ant;
		}
		delete(p);
	}
}

void imprimir(NodoD *p){
	for(;p!=NULL;p=p->sgt){
		cout<<"["<<p->dato<<"]<=>";
		if(p->sgt==NULL)
			break;
	}
	cout<<endl;
	for(;p!=NULL;p=p->ant){
		cout<<"["<<p->dato<<"]<=>";	
	}
	cout<<endl;
}






