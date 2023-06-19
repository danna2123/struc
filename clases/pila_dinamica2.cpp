#include <iostream>
#include <stdlib.h>

using namespace std;

typedef int Tdato;
typedef struct nodo{
	Tdato dato;
	struct nodo *sgt;
}Nodo;

typedef struct lista{
	Nodo *cima;
	void inicializar(){
		cima=NULL;
	}
	
	bool vacia(){
		return cima==NULL;
	}
	
	void insertar(Tdato d){
		Nodo *p=(Nodo*)malloc(sizeof(Nodo));
		p->dato=d;
		p->sgt=cima;
		cima=p;
	}
	
	Tdato quitar(){
		if(!vacia()){
			Tdato aux=cima->dato;
			Nodo *p=cima;
			cima=cima->sgt;
			free(p);
			return aux;
		}
		return NULL;
	}
	
	int tamPila(){
		int cont=0;
		Nodo *p=cima;
		while(p!=NULL){
			cont++;
			p=p->sgt;
		}
		return cont;
	}
	
	Tdato cimaPila(){
		if(!vacia()){
			return cima->dato;
		}
		return NULL;
	}
	
	void imprimir(){
		for(Nodo *p=cima;p!=NULL;p=p->sgt){
			cout<<"["<<p->dato<<"]"<<endl;
		}
	}
	void vaciar(){
		while(!vacia()){
			quitar();
		}
	}
}Lista;

int main(){
	Lista p1;
	p1.inicializar();
	p1.insertar(1);
	p1.insertar(2);
	p1.insertar(3);
	p1.insertar(4);
	p1.insertar(5);
	p1.imprimir();
	return 0;
}

