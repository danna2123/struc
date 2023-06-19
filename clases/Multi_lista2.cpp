#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct vh{
	int id;
	char marca[20];
	int anio;
	char modelo[20];
	struct vh *sgt;
}vehiculo;

typedef struct rel{
	vehiculo *pv;
	struct rel *sgt;
}Relacion;

typedef struct per{
	int id;
	char nombre[20];
	char email[20];
	struct per *sgt;
	Relacion *lv;
}Persona;

Persona * agregar_Persona(Persona *&cab);
void imprimir_persona(Persona *p);
Persona *buscar_per(Persona *p, int id);
vehiculo *buscar_veh(vehiculo *p, int id);
void insertar_veh(vehiculo *&cab);
void imprimir_veh(vehiculo *p);

int main(){
	system("color F0");
	Persona *cabp=NULL;
	vehiculo *cabv=NULL;
	int op=0;
	
	do{
		system("cls");
		cout<<"+--------------------------------------+"<<endl;
		cout<<"|         1. Agregar persona           |"<<endl;
		cout<<"|         2. Agregar vehiculo          |"<<endl;
		cout<<"|         3. Imprimir persona          |"<<endl;
		cout<<"|         4. Imprimir vehiculo         |"<<endl;
		cout<<"|         5. Relacionar                |"<<endl;
		cout<<"+--------------------------------------+"<<endl;
		cin>>op;
		switch(op){
			case 1:{
				agregar_Persona(cabp);
				break;
			}
			case 2:{
				insertar_veh(cabv);
				break;
			}
			case 3:{
				imprimir_persona(cabp);
				break;
			}
			case 4:{
				imprimir_veh(cabv);
				break;
			}
			case 5:{
				int auxp;
				cout<<"id: ";cin>>auxp;
				Persona *p= buscar_per(cabp,auxp);
				if(p!=NULL){
					int auxv;
					cout<<"Placa: ";cin>>auxv;
					vehiculo *q=buscar_veh(cabv,auxv);
					if(q!=NULL){
						Relacion *pr=(Relacion*)malloc(sizeof(Relacion));
						pr->pv=q;
						pr->sgt=p->lv;
						p->lv=pr;
						cout<<"relacionado";
					}else{
						cout<<"vehiculo no encontrado";
					}
				}else{
					cout<<"persona no encontrada";
				}
				system("pause");
				break;
			}
		}
	}while(op!=0);
	return 0;
}

void insertar_veh(vehiculo *&cab){
	vehiculo *p=(vehiculo*)malloc(sizeof(vehiculo));
	cout<<"Placa: ";cin>>p->id;
	cout<<"Marca: ";cin>>p->marca;
	cout<<"Modelo: ";cin>>p->modelo;
	cout<<"Año: ";cin>>p->anio;
	p->sgt=cab;
	cab=p;
}

void imprimir_veh(vehiculo *p){
	system("cls");
	cout<<"Vehiculos"<<endl;
	for(;p!=NULL;p=p->sgt){
		cout<<"+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+"<<endl;
		cout<<"                   Placa: "<<p->id<<endl;
		cout<<"                   Marca: "<<p->marca<<endl;
		cout<<"                   Modelo: "<<p->modelo<<endl;
		cout<<"                   Año: "<<p->anio<<endl;
	}
	cout<<"+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+"<<endl;
	system("pause");
}

Persona * agregar_Persona(Persona *&cab){
	Persona *p =(Persona*)malloc(sizeof(Persona));
	cout<<"Id: "; cin>>p->id;
	cout<<"Nombre: "; cin>>p->nombre;
	cout<<"Email: "; cin>>p->email;
	p->sgt = cab;
	p->lv=NULL;
	cab=p;	
}

void imprimir_persona(Persona *p){
	system("cls");
	for(;p!=NULL;p=p->sgt){
		cout<<"+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+"<<endl;
		cout<<"                    Id: "<<p->id<<"                    "<<endl;
		cout<<"                    Nombre: "<<p->nombre<<"            "<<endl;
		cout<<"                    Email: "<<p->email<<"              "<<endl;
		for(Relacion *q=p->lv;q!=NULL;q=q->sgt){
			cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
			cout<<"                    Placa: "<<q->pv->id<<endl;
			cout<<"                    Marca: "<<q->pv->marca<<endl;
			cout<<"                    Modelo: "<<q->pv->modelo<<endl;
			cout<<"                    Año: "<<q->pv->anio<<endl;
		}
		cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
	}
	cout<<"+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+"<<endl;
	system("pause");
}

Persona *buscar_per(Persona *p, int id){
	for(;p!=NULL;p=p->sgt){
		if(p->id==id)
		return p;
	}
	return NULL;
}

vehiculo *buscar_veh(vehiculo *p, int id){
	for(;p!=NULL;p=p->sgt){
		if(p->id==id)
		return p;
	}
	return NULL;
}
