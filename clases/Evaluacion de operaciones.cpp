/*
NOTACION: es la forma en que esta espresada dicha ecucion, dicho notacion se llama infija se utiliza normalmente, es la que necesita parentesis 
y corchetes para realizar operaciones. parenticis (), potencia ^, Multiplicacion/divicion *,/, suma/resta +-.
Notacion prefija: se le da prioridad a lo operadores y va antes
a*b/(a+c) => a*b/+ac => *ab/+ac => /*ab+ac
a*b/a+c => *ab/a+c => /*aba+c => +/*abac
(a-b)^c+d => +^-abcd
Notacion posfija:  se le da prioridad a lo operadores y va despues
a*b/(a+c) => a*b/ac+ => a*bac+/ => ab*ac/+
a*b/a+c => a*b/ac+ => a*bac+/ => ab*a/c+
(a-b)^c+d => ab-c^d+
si tiene la misma prioridad el signo anterior debe salir de la pila.
cuando el el que entra tiene menor prioridad que el esta adentro este se saca y se pone adentro.
Prioridades ^,( ), *./,+-
*/

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
typedef char Tdato;
typedef struct nodo{
	Tdato dato;
	struct nodo *sgt;
}Nodo;
typedef struct pila{
	Nodo *cima;
	void inicializar(){
		cima=NULL;
	}
	void insertar(Tdato d){
		Nodo *p=(Nodo*)malloc(sizeof(Nodo));
		p->dato=d;
		p->sgt=cima;
		cima=p;
	}
	bool vacia(){
		return cima==NULL;
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
	Tdato datoCima(){
		if(!vacia())
			return cima->dato;	
		return NULL;	
	}
	void imprimir(){
		for(Nodo *p=cima;p!=NULL;p=p->sgt){
			cout<<"["<<p->dato<<"]"<<endl;
		}
	}
	int tam(){
		int cont =0;
		for(Nodo *p=cima;p!=NULL;p=p->sgt){
		   cont++;
		}
		return cont;
	}
}Pila;


int prioridad_dentro(char c){
	switch(c){
		case '^':
			return 3;
		case '*' :
			return 2;
		case '/' :
			return 2;
		case '+':
			return 1;
		case '-':
			return 1;
		case '(':
			return 0;	
	}
}
int prioridad_fuera(char c){
	switch(c){
		case '^':
			return 4;
		case '*' :
			return 2;
		case '/' :
			return 2;
		case '+':
			return 1;
		case '-':
			return 1;
		case '(':
			return 5;	
	}
}

void posfija(char in[50]){
	int tam=strlen(in);
	char pos[50];
	int j=0;
	Pila p1;
	p1.inicializar();
	for(int i=0;i<tam;i++){
		if(in[i]>='a' && in[i]<='z'){
			pos[j]=in[i];
			j++;
		}else{
			if(in[i]!=')'){					
				if(p1.vacia()){
					p1.insertar(in[i]);
				}else{
					if(prioridad_fuera(in[i])>prioridad_dentro(p1.datoCima())){
						p1.insertar(in[i]);
					}else{
						while(prioridad_fuera(in[i])<=prioridad_dentro(p1.datoCima()))
						{
							pos[j]=p1.quitar();
							j++;
						}
					}
				}
					
			}else{
				while(p1.datoCima()!='('){
					pos[j]=p1.quitar();
					j++;
				}
				p1.quitar();
			}
		}
	}
	while(!p1.vacia()){
		pos[j]=p1.quitar();
		j++;
	}
	pos[j]='\0';
	cout<<"dato:"<<p1.datoCima()<<endl;
	cout<<endl<<"Exp pos_:"<<pos<<endl;
	
}

int main(){
	Pila p;
	p.inicializar();
	p.insertar('A');
	p.insertar('B');
	p.insertar('c');
	p.insertar('d');
	p.imprimir();
	cout<<prioridad_dentro('*');
	char *cad="a*(b+c-(d/e^f)-g)-h";
	posfija(cad);
}




