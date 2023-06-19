#include <iostream>
#include <stdlib.h>

using namespace std;

typedef int Tdato;
Tdato *v;
typedef struct pila{
int cima, tam;
    void inicializar(int dato){
        tam=dato;
        v=new Tdato[tam];
		cima = -1;
    }
    bool llena(){
        return cima==tam-1;
    } 
    bool vacia(){
        return cima==-1;
    }
    void insertar(Tdato d){
        if(!llena()){
            cima++;
            v[cima]=d;
        }else{
            cout<<"overflow"<<endl;
        }
    }
    
Tdato quitar(){
	if(!vacia()){
        Tdato aux=v[cima];
        cima--;
        return aux;
    }else{
        cout<<"underflow"<<endl;
        return NULL;
    }
}
    int tamPila(){
        return cima+1;
    }
    Tdato cimaPila(){
    	if(!vacia()){
    		return v[cima];
		}
		return NULL;
	}
	void imprimir(){
		for(int i=cima;i>=0;i--){
			cout<<"["<<v[i]<<"]"<<endl;
		}
	}
	void vaciar(){
		cima=-1;
	}
}Pila;

int main(){
	Pila p1;
	p1.inicializar(5);
	p1.insertar(1);
	p1.insertar(2);
	p1.insertar(3);
	p1.insertar(4);
	p1.insertar(5);
	p1.vaciar();
	p1.imprimir();
	return 0;
}
