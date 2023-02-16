#include <iostream>
//#include <cctype>
#include <cmath>

using namespace std;

//bool esNumero(char c);
double Raiz(double dato);
double potencia(double base, double exponente);
int resta(int A, int B);
int suma(int A, int B);

int main() {
	
	int Ax, Ay, Bx, By, resX, resY, sum, Px, Py, dis;
	
	cout<<"Ingrese el x del primer punto: "; cin >> Ax;
	cout<<"Ingrese el y del primer punto: "; cin >> Ay;
	cout<<"Ingrese el x del segundo punto: "; cin >> Bx;
	cout<<"Ingrese el y del segundo punto: "; cin >> By;
	
	resX = resta(Ax, Bx);
	resY = resta(Ay, By);
	Px= potencia(resX, 2);
	Py = potencia(resY, 2);
	sum = Px + Py;
	dis = Raiz(sum); 
	
	cout<< "la distancia es: "<<dis;
  
  /*char caracter;
  cout << "Introduce un caracter: ";
  cin >> caracter;

  if (esNumero(caracter)) {
    cout << "El caracter introducido es un numero." << endl;
  } else {
    cout << "El caracter introducido no es un numero." << endl;
  }*/

	return 0;
}

int resta(int A, int B){
	int resultado;
	resultado = A - B;
	
	return resultado;
}

int suma(int A, int B){
	int resultado;
	resultado = A + B;
	
	return resultado;
}
double Raiz(double dato){
	double resultado;
	resultado = sqrt(dato);
	
	return resultado;
}

double potencia(double base, double exponente){
	double resultado;
	resultado = pow(base, exponente);
	
	return resultado;
}

/*bool esNumero(char c) {
  return isdigit(c);
}*/
