#include <iostream>

using namespace std;
void funcion(int &x);

int main (){
	int n= 75;
	int *p;
	p=&n;
	
	cout<<"n: "<<n<<endl;
	cout<<"n: "<<&n<<endl;
	cout<<"p: "<<p<<endl;
	cout<<"&p: "<<&p<<endl;
	char a = 'a';
	char cad[] ="Hola";
	cout<<cad<<endl;
	int y = 5;
	funcion(y);
	cout<<y<<endl;
	
	return 0;
}

void funcion(int &x){
	x=x*3;
	cout<<"X: "<<x<<endl;
}
