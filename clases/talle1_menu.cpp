#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct est{
	int id;
	char marca[20];
	int anio;
	char modelo[20];
	struct vh *sgt;
}Estudiante;

typedef struct rel{
	vehiculo *pv;
	struct rel *sgt;
}Materia;

typedef struct per{
	int id;
	char nombre[20];
	char email[20];
	struct per*sgt;
	vehiculo *lv;
}Nota;

int main(){
	Estudiante *cabE=NULL;
	Asignatura *cabA=NULL;
	Nota *cabN=NULL;
	int op=0;
	system("color F0");
	
	do{
		system("cls");
		cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*"<<endl;
        cout<<"|       1. Insertar estudiantes                                             |"<<endl;
        cout<<"|       2. Insertar asignaturas                                             |"<<endl;
        cout<<"|       3. Insertar asignaturas a un  estudiante                            |"<<endl;
        cout<<"|       4. Insertar notas del estudiante                                    |"<<endl;
        cout<<"|       5. Mostrar un estudiante con sus asignaturas y notas                |"<<endl;
        cout<<"|       6. Buscar estudiantes en una asignatura y obtener sus notas         |"<<endl;
		cout<<"|       7. Promedio de notas de un estudiante en todas las asignaturas      |"<<endl;
		cout<<"|       8. Promedio de notas de una asignatura en todos los estudiantes     |"<<endl;
        cout<<"|       9. Eliminar estudiantes y notas de una asignatura específica        |"<<endl;
        cout<<"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*"<<endl;
		cin>>op;
		switch(op){
			case 1:{
				//insetar estudiante
				break;
			}
			case 2:{
				//insetar asignatura 
				break;
			}
			case 3:{
				//insertar nota
				break;
			}
			case 4:{
			/*	int auxp;
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
				break; */
			}
		}
	}while(op!=0);
	return 0;
}
