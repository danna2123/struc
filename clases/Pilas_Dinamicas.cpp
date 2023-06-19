#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;
typedef int Tdato;
typedef struct nodo{
	Tdato dato;
	struct nodo*sgt;
}Nodo;

typedef struct pila{
	Nodo *cab;
	void inicializar(){
		cab=NULL;
	}
	bool vacia(){
		return cab==NULL;
	}
	void insertar(Tdato d){
		Nodo *p=(Nodo*)malloc(sizeof(Nodo));
		p->dato=d;
		p->sgt=cab;
		cab=p;
	}
	Tdato quitar(){
		if(!vacia()){
			Tdato aux=cab->dato;
			Nodo *p=cab;
			cab=cab->sgt;
			delete(p);
			return aux;
		}
		return NULL;
	}
	int tamPila(){
		int cont=0;
		for(Nodo *p=cab;p!=NULL;p=p->sgt){
			cont++;
		}
		return cont;
	}
	void imprimir(){
		for(Nodo *p=cab;p!=NULL;p=p->sgt){
			cout<<"["<<p->dato<<"]"<<endl;	
		}
	}
}Pila;

/*void imprimir_pila(Pila p){
	pila p_aux;
	Tdato aux;
	p_aux.inicializar();
	while(!p.vacia()){
		aux=p.quitar();
		cout<<"["<<aux<<"]"<<endl;
		p_aux.insetar(aux);
	}
	while(!p_aux.vacia()){
		p.insertar(p_aux.quitar());
	}
}*/

void generar_numeros(){
	int n;
	cout<<"cuandos numeros quiere generar: "; cin>>n;
	for(int i=0;i<=n;i++){
		
	}
}

void numeros_aleatorio(){
	int n,aux;
	cout<<"cuandos numeros quiere generar: "; cin>>n;
	pila p1,p2;
	p1.inicializar();
	p2.inicializar();
	for(int i=0;i<n;i++){
		aux=rand()%100;
		if(aux%2==0){
			p1.insertar(aux);
		}else{
			p2.insertar(uax);
		}
	}
	cout<<"pares"<<endl;
	p1.imprimir();
	cout<<"impares"<<endl;
	p2.imprimir();
}

int main(){
	Pila p1;
	p1.inicializar();
	p1.insertar(1);
	p1.insertar(2);
	p1.insertar(3);
	p1.imprimir();
	
	cout<<p1.quitar()<<endl;
	cout<<p1.quitar()<<endl;
	p1.imprimir();
	
	return 0;
}


