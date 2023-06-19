#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int Tdato;
typedef struct nodo{
	Tdato dato;
	struct nodo *sgt;
}Nodo;

typedef struct bicola{
	Nodo *fr;
	Nodo *fin;
	Nodo *ant;
	void inicializar(){
		fr=fin=NULL;
		ant=NULL;
	}
	bool vacia(){
		return frn ==NULL;
	}
	void insertar_frente(Tdato dato){
		Nodo *p =(Nodo*)malloc(sizeof(Nodo));
		p->dato=dato;
		p->sgt=fr;
		if(vacia()){
			fr=fin=p
		}else{
			fr=p;
		}
	}
	Tdato quitar_frente(){
		if(!vacia()){
			Tdato aux=fr->dato;
			Nodo *p=fr;
			fr=fr->sgt;
			free(p);
			return aux	
		} 
		return NULL;
	}
	
	void insertar_fin(Tdato dato){
		Nodo *p =(Nodo*)malloc(sizeof(Nodo));
		p->dato=dato;
		if(vacia()){
			fr=fin=p;
			p->sgt=NULL;
		}else{
			fin->sgt=p;
			ant=fin;
			fin=p;
		}
	}
	
	Tdato quitar_dato(){
		if(!vacia()){
			Tdato aux=fin->dato;
			Nodo *p=fin;
			fin=ant;
			free(p);
			return aux;
		}
		return NULL;
	}
	
	void imprimir(){
		for(Nodo *p=fr;p!=NULL;p=p->sgt){
			cout<<"["<<p->dato<<"]";
		}
		cout<<endl;
	}
}Bicola;





