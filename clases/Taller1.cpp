/* 
	Taller de Multilistas
	Crear una multilista en c++ que permita almacenar información de estudiantes y sus notasen diferentes asignaturas. 
	La multilista deberá permitir las siguientes operaciones:
	1.Insertar estudiantes y notas en diferentes asignaturas
	2.Eliminar estudiantes y notas de una asignatura específica
	3.Buscar estudiantes en una asignatura y obtener sus notas
	4.Obtener el promedio de notas de un estudiante en todas las asignaturas
	5.Obtener el promedio de notas de una asignatura en todos los estudiantes
	6.Editar una nota específica de la asignatura de un estudiante. 
	Se te pide que implementes las siguientes clases:
	1.La estructura Estudiante, que debe tener los siguientes atributos:
	·Nombre del estudiante ·Edad del estudiante ·DNI del estudiante
	2.La estructura Asignatura, que debe tener los siguientes atributos:·Nombre de la asignatura ·Código de la asignatura
	3.La estructura Nota, que debe tener los siguientes atributos:·Valor de la nota·Fecha de la nota
	4.LaMultilista, que debe tener las siguientes funciones:
	·Insertar un estudiante en una asignaturacon una nota específica
	·Editar una nota específica de la asignaturade un estudiante.
	·Eliminar un estudiante y sus notas de unaasignatura específica
	·Buscar un estudiante en una asignatura yobtener sus notas
	·Obtener el promedio de notas de un estudianteen todas las asignaturas
	·Obtener el promedio de notas de una asignaturaen todos los estudiantes 
*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
typedef struct asig{
	char nombreA [20];
	int id;
	int nota;
	struct asig *sgt;
}Asignatura;
typedef struct nota{
	int VNota;
	char fecha [20];
	struct nota *sgt;
	Asignatura *a;
}Notas;
typedef struct relEA{
	Asignatura *ea;
	struct relEA *sgt;
}RelacionEA;
typedef struct est{
	char nombre [20];
	int edad;
	int id;
	int nota;
	RelacionEA *as;
	struct est *sgt;
}Estudiante;



Estudiante *buscar_est(Estudiante *e,int id){
	for(;e!=NULL;e=e->sgt){
		if(e->id==id){
		}
			return e;
	}
	return NULL;
}
Asignatura *buscar_asg(Asignatura *a,int id){
	for(;a!=NULL;a=a->sgt){
		if(a->id==id)
			return a;
	}
	return NULL;
}
void imprimir_est(Estudiante *e){
	system("cls");
	int aux;
	for(;e!=NULL;e=e->sgt){
		cout<<"*...........................................................*"<<endl;
		cout<<"			 Codigo del estudiante: "<<e->id<<endl;
		cout<<"          Nombre del estudiante: "<<e->nombre<<endl;
		cout<<"          Edad del estudiante: "<<e->edad<<endl;
		cout<<"          Nota: "<<e->nota<<endl;
		cout<<"*...........................................................*"<<endl;
		RelacionEA *q;
		for(q=e->as;q!=NULL;q=q->sgt){
			cout<<"*===========================================================*"<<endl;
			cout<<"			 Codigo de la asignatura: "<<q->ea->id<<endl;
			cout<<"			 Nombre de la asignatura: "<<q->ea->nombreA<<endl;
			cout<<"			 Nota: "<<q->ea->nota<<endl;
			cout<<"*===========================================================*"<<endl;
		}
	}
	system("pause");

}
void insertar_est(Estudiante *&cab){
	system("cls");
	Estudiante *e=(Estudiante*)malloc(sizeof(Estudiante));
	cout<<"Codigo del estudiante: ";cin>>e->id;
	cout<<"Nombre del estudiante: ";cin>>e->nombre;
	cout<<"Edad del estudiante: ";cin>>e->edad;
	e->sgt=cab;
	cab=e;
}
void insertar_asg(Asignatura *&cab, Notas *&cabn){
	Asignatura *a=(Asignatura*)malloc(sizeof(Asignatura));
	cout<<"Codigo de la asignatura: ";cin>>a->id;
	cout<<"Nombre de la asignatura: ";cin>>a->nombreA;
	a->sgt=cab;
	cab=a;
}
void imprimir_asg(Asignatura *a){
	system("cls");
	for(;a!=NULL;a=a->sgt){
		cout<<"Codigo de la asignatura: "<<a->id<<endl;
		cout<<"Nombre de la asignatura: "<<a->nombreA<<endl;
	}
	system("pause");
}
void insertar_nota(Notas *&cab, Asignatura *&a,Estudiante *&e){
	Notas *p=(Notas*)malloc(sizeof(Notas));
	cout<<"Fecha de la nota: ";cin>>p->fecha;
	cout<<"Valor de la nota: ";cin>>p->VNota;
	p->sgt=cab;
	cab=p;
	a->nota=p->VNota;
	e->nota=p->VNota;
}
void prom_asignatura(Asignatura *cab){
    float prom=0, cant=0, total;
    Asignatura *aux=cab;
    if(aux->id==aux->id){
        while(aux!=NULL){
        	Notas *n;
            prom = n->VNota + prom;
            cant++;
            n=n->sgt;
        }
        total = prom/cant;
        cout<<"El promedio es: "<< total<<endl; 
    }
    system("pause");
}

Estudiante *deleteE(Estudiante *cab, int id) {
    if (cab == NULL) {
        return cab;
    }
    if (cab->id == id) {
        Estudiante *temp = cab;
        cab = cab->sgt;
        delete temp;
        return cab;
    }
    Estudiante *prev = cab;
    while (prev->sgt != NULL && prev->sgt->id != id) {
        prev = prev->sgt;
    }
    if (prev->sgt == NULL) {
        return cab;
    }
    Estudiante *temp = prev->sgt;
    prev->sgt = prev->sgt->sgt;
    delete temp;
    return cab;
}
void prom_estudiante(Estudiante *cab){
    float prom=0, cant=0, total;
    Estudiante *aux=cab;
    while(aux!=NULL){
    	Notas *n;
        prom = n->VNota + prom;
        cant++;
        aux=aux->sgt;
    }
    total = prom/cant;
    cout<<"El promedio es: "<< total<<endl;
}
RelacionEA *RelacionarEstuAsig(RelacionEA *cab, Asignatura *cabA, Estudiante *cabE){
	int auxe;
    cout<<"id: ";cin>>auxe;
    Estudiante *e=buscar_est(cabE,auxe);
    if(e!=NULL){
        int auxa;
        cout<<"id: ";cin>>auxa;
        Asignatura *a=buscar_asg(cabA,auxa);
        if(a!=NULL){
        	RelacionEA *r=(RelacionEA*)malloc(sizeof(RelacionEA));
            r->ea=a;
            r->sgt=e->as;
            e->as=r;
            cout<<"relacionado"<<endl;
        }else{
            cout<<""<<endl;
        }
    }else{
        cout<<""<<endl;
    }
    system("pause");
}

int main(){
	system("color F0");
    Estudiante *cabE=NULL;
    Asignatura *cabA=NULL;
    RelacionEA *cabr=NULL;
    //RelacionEAN *cabR=NULL;
    Notas *cabN=NULL;
    int op=0;
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
                insertar_est(cabE);
                break;
            }
            case 2:{
                insertar_asg(cabA,cabN);
                break;
            }
            case 3:{
                RelacionEA *p=RelacionarEstuAsig(cabr,cabA,cabE);
                break;
            }
            case 4:{
            	insertar_nota(cabN,cabA,cabE);
            	break;
            }
            case 5:{
            	imprimir_est(cabE);
				break;
			}
			case 6:{
				int id;
				Estudiante *est=buscar_est(cabE,id);
				if(est!=NULL){
					imprimir_est(cabE);
				}else{
					cout<<"Estudiante no encontrado"<<endl;
				}
				break;
			}
			case 7:{
				prom_estudiante(cabE);
				break;
			}
			case 8:{
				prom_asignatura(cabA);
				break;
			}
			case 9:{
				int id;
				cin>>id;
				*deleteE(cabE,id);
				break;
			}
        }
    }while(op!=0);
    return 0;
}
