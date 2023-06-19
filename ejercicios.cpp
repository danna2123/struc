#include <iostream>
#include <conio.h>

using namespace std;

int main(){
	int n, mayor=0, sum;
	int numero[n];
	cout<<"Digite el numero de elementos que va tener su arreglo: "; cin>>n;
	
	for(int i=0;i<n;i++){
		cout<<i+1<<". Digite un numero: "; cin>>numero[i];
		if(numero[i]>mayor){
			mayor=numero[i];
		}
	}
	
	cout<<"El mayor elemento es: "<<mayor<<endl;	
	
	
//	for(int i=n-1;i>=0;i--){
//		cout<<i<<" -> "<<numero[i]<<endl;
//	}
	
	return 0;
}
