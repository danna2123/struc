#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int Tdato;
typedef struct nodo{
	Tdato dato;
	struct nodo *sgt;
}Nodo;

typedef struct cola{
	Nodo *frente;
	Nodo *fin;
	void inicializar(){
		frente=fin=NULL;
	}
	bool vacia(){
		return frente==NULL;
	}
	void insertar(Tdato dato){
		Nodo *p=(Nodo*)malloc(sizeof(Nodo));
		p->dato=dato;
		p->sgt=NULL;
		if(vacia()){
			frente=fin=p;
		}else{
			fin->sgt=p;
			fin=p;
		}
	}
	void imprimir(){
		for(Nodo *p=frente;p!=NULL;p=p->sgt){
			cout<<"["<<p->dato<<"]";
		}
		cout<<endl;
	}
	Tdato quitar(){
		if(!vacia()){
			Tdato aux=frente->dato;
			Nodo *p=frente;
			frente=frente->sgt;
			free(p);
			return aux;
		}else{
			cout<<"Undeflow"<<endl;
			return NULL;
		}
	}
	int tamano(){
		int cont=0;
		for(Nodo *p=frente;p!=NULL;p=p->sgt){
			cont++;
		}
		return cont;
	}
	Tdato datfrente(){
		if(!vacia()){
			return frente->dato;
		}else{
			return NULL;
		}
	}
	bool buscar(Tdato dato){
		for(Nodo *p=frente;p!=NULL;p=p->sgt){
			if(p->dato==dato){
				return true;
			}else{
				return false;
			}
		}
	}
}Cola;

bool buscar_fuera(Cola c, Tdato dato){
	int t=c.tamano();
	bool r=false;
	for(int i=0;i<t;i++){
		if(c.datfrente()==d){
			r=true;
		}
		c.inicializar(c.quitar());
	}
	return r;
}

int main(){
	Cola c1;
	c1.inicializar();
	c1.insertar(5);
	c1.insertar(7);
	c1.insertar(6);
	c1.insertar(1);
	cout<<c1.buscar(1)<<endl;
	c1.quitar();
	c1.imprimir();
	cout<<c1.tamano()<<endl;
	
}









