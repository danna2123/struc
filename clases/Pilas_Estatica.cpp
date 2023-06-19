#include<iostream>
using namespace std;
typedef  struct e{
	int info;
}Est;
int Tmax=100;
int tope=-1;

void insertar_fin(Est v[100],int dato){
	if(tope<Tmax){
		tope++;
		v[tope].info=dato;
	}else{
		cout<<"No se puede insertar"<<endl;
	}
}
void insertar_ini(Est v[100],int dato){
	if(tope<Tmax){
		for(int i=tope;i>=0;i--){
			v[i+1]=v[i];
		}
		v[0].info=dato;
		tope++;
	}else{
		cout<<"no se puede insertar"<<endl;
	}
}
int buscar (Est v[100],int dato){
	int pos=-1;
	for(int i=0;i<=tope and pos==-1;i++){
		if(v[i].info==dato){
			pos=i;
		}
	}
	if(pos==-1){
		cout<<"No encontrado"<<endl;
	}else{
		cout<<"Si lo encontro"<<endl;
	}
	return pos;
}
void eliminar(Est v[100],int dato){
	int pos=buscar(v,dato);
	if(pos==-1){
		cout<<"no se puede eliminar porqur no lo encontro"<<endl;
	}else{
		for(int i=pos;i<=tope;i++){
			v[i]=v[i+1];
		}
		tope--;
	}
}
void imprimir(Est v[100]){
	for(int i=0;i<=tope;i++){
		cout<<"["<<v[i].info<<"]";
	}
	cout<<endl;
}
int main(){
	Est v[Tmax];
	insertar_fin(v,7);
	insertar_fin(v,8);
	insertar_fin(v,9);
	insertar_ini(v,10);
	imprimir(v);
	eliminar(v,8);
	imprimir(v);
	return 0;
}
