#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct vh{
	char marca[20];
	int anio;
	char modelo[20];
	struct vh*sgt;
}vehiculo;


typedef struct per{
	char nombre[20];
	int id;
	char email[20];
	struct per*sgt;
	vehiculo *lv;
}Persona;

Persona * crearPersona(int id, char n[20], char e[20], Persona *s);
void insertar_persona(Persona *&cab, int id, char n[20], char e[20]);
void imprimir_persona(Persona *p);
Persona *bucar_per(Persona *p, int id);
void insertar_veh(vehiculo *&cab);
void imprimir_veh(vehiculo *p);

int main(){
	Persona *cabp=NULL;
	int op=0;
	
	system("color F0");
	
	do{
		system("cls");
		cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*"<<endl;
		cout<<"|       1. Insertar estudiantes                                             |"<<endl;
		cout<<"|       2. Insertar asignaturas del estudiante                              |"<<endl;
		cout<<"|       3. Insertar notas del estudiante                                    |"<<endl;
		cout<<"|       4. Mostrar un estudiante con sus asignaturas y notas                |"<<endl;
		cout<<"|       5. Buscar estudiantes en una asignatura y obtener sus notas         |"<<endl;
		cout<<"|       6. Eliminar estudiantes y notas de una asignatura especifica        |"<<endl;
		cout<<"|       7. Promedio de notas de un estudiante en todas las asignaturas      |"<<endl;
		cout<<"|       8. Promedio de notas de una asignatura en todos los estudiantes     |"<<endl;
		cout<<"|       9. Editar una nota especifica de la asignatura de unestudiante.     |"<<endl;
		cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*"<<endl;
		cin>>op;
		switch(op){
			case 1:{
				int id;
				char n[20];
				char e[20];
				cout<<"Id: ";cin>>id;
				cout<<"Nombre: ";cin>>n;
				cout<<"Email: ";cin>>e;
				insertar_persona(cabp,id,n,e);
				break;
			}
			case 2:{
				imprimir_persona(cabp);
				break;
			}
			case 3:{
				int aux;
				cout<<"digite el id:";cin>>aux;
				Persona *p=bucar_per(cabp,aux);
				if(p==NULL){
					cout<<"No encontrado"<<endl;
					system("pause");
				}else{
					insertar_veh(p->lv);
				}
				break;
			}
			case 4:{
				int aux;
				cout<<"digite el id:";cin>>aux;
				Persona *p=bucar_per(cabp,aux);
				if(p==NULL){
					cout<<"No encontrado"<<endl;
					system("pause");
				}else{
					imprimir_veh(p->lv);
				}
				break;
			}
		}
	}while(op!=0);
}

void insertar_veh(vehiculo *&cab){
	vehiculo *p=(vehiculo*)malloc(sizeof(vehiculo));
	cout<<"Marca: ";cin>>p->marca;
	cout<<"Modelo: ";cin>>p->modelo;
	cout<<"Año: ";cin>>p->anio;
	p->sgt=cab;
	cab=p;
}

void imprimir_veh(vehiculo *p){
	system("cls");
	cout<<"/////////////////////////////"<<endl;
	for(;p!=NULL;p=p->sgt){
		cout<<p->marca<<"\t"<<p->modelo<<"\t"<<p->anio<<endl;
		cout<<"/////////////////////////////"<<endl;
	}
	int tmp;
	cout<<"Digite 0 para continuar...";
	cin>>tmp;
}

Persona * crearPersona(int id, char n[20], char e[20], Persona *s){
	Persona *p =(Persona*)malloc(sizeof(Persona));
	p->id=id;
	strcpy(p->nombre, n);
	strcpy(p->email, e);
	p->sgt = s;
	return p;
}

void insertar_persona(Persona *&cab, int id, char n[20], char e[20]){
	Persona *p = crearPersona(id,n,e,cab);
	cab=p;
}

void imprimir_persona(Persona *p){
	system("cls");
	for(;p!=NULL;p=p->sgt){
		cout<<"Id: "<<p->id<<endl;
		cout<<"Nombre: "<<p->nombre<<endl;
		cout<<"Email: "<<p->email<<endl;
	}
	int tmp;
	cout<<"Digite 0 para continuar ";cin>>tmp;
}

Persona *bucar_per(Persona *p, int id){
	for(;p!=NULL;p=p->sgt){
		if(p->id==id)
		return p;
	}
	return NULL;
}



