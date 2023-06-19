#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int Tdato;
typedef struct cola{
	Tdato *v;
	int frente;
	int final;
	int tam;
	void inicializar(int n){
		tam=n;
        v=new Tdato[n];
		frente = 0;
		final = -1;
	}
	int siguente(int x){
		return(x+1)%tam;
	}
	bool vacia(){
		return frente==siguente(final);
	}
	bool llena(){
		return frente==siguente(siguente(fin));
	}
	void insertar(Tdato dato){
		if(!llena){
			fin=siguente(fin);
			v[fin]=dato;
		}else{
			cout<<"Overflow"<<endl;
		}
	}
	Tdato quitar(){
		if(!vacia()){
			Tdato aux=v[frente];
			frente=siguente(frente);
			return aux;
		}else{
			cout<<"Overflow"<<endl;
			return NULL;
		}
	}
	void imprimir(){
		for(int i=frente;i!=final;i=siguente(i)){
			cout<<"["<<v[i]<<"]";
		}
		cout<<endl;
	}
}ColaC;

int main(){
	ColaC c1;
	c1.inicializar(10);
	c1.insertar(1);
	c1.insertar(2);
	c1.insertar(3);
	c1.insertar(4);
	c1.insertar(5);
	c1.insertar();
	c1.imprimir();
	
	return 0;
}




















