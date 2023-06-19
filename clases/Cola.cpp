/*
almacena y recupera sus elementos atendiendo a un estricto escrito orden 
first-in -> primero que entra, first-out -> ultimo en salir 
gestion de memoria intermedia buffering 
si la cola esta vacia final esta en -1 y frente en 0, si estan los en la misma pocicion es porque solo hay un elemento.
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int Tdato;
typedef struct cola{
	Tdato *v;
	int frente;
	int final;
	int tam;
	void inicializar(int dato){
		tam=dato;
        v=new Tdato[tam];
		frente = 0;
		final = -1;
	}
	bool vacia(){
		return final<frente;
	}
	bool llena(){
		return final==(tam-1);
	}
	
	void insertar(Tdato dato){
		if(!llena()){
			final++;
			v[final]=dato;
		}else{
			cout<<"Overflow"<<endl;
		}
	}
	
	Tdato quitar(){
		if(!vacia()){
			Tdato aux=v[frente];
			frente++;
			return aux;
		}else{
			cout<<"Overflow"<<endl;
			return NULL;	
		}
	}
	
	void imprimir(){
		cout<<"Frente: "<<frente<<" - Final: "<<final<<endl;
		for(int i=0;i<tam;i++){
			cout<<"["<<v[i]<<"]";
		}
		cout<<endl;
	}
	
	
}Cola;

int main(){
	Cola c;
	c.inicializar(5);
	c.insertar(5);
	c.insertar(7);
	c.insertar(1);
	c.imprimir();
	cout<<c.quitar()<<endl;
	cout<<c.quitar()<<endl;
	cout<<c.quitar()<<endl;
	c.imprimir();
	c.insertar(9);
	c.insertar(3);
	c.insertar(4);
	cout<<c.quitar()<<endl;
	cout<<c.quitar()<<endl;
	
	return 0;
}


