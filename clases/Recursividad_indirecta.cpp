#include <iostream>

using namespace std;

void funcionA(char c);
void funcionB(char c);
int sumaInt(int n);

int main(){
	cout << "Alfabeto: ";
	funcionA('Z');
	cout<< endl;
	cout<<"Suma: ";
	cout<<sumaInt(345)<<endl;
	return 0;
}

void funcionA(char c){
	if(c>'A'){
		funcionB(c);
	}
	cout<<c;
}

void funcionB(char c){
	funcionA(--c);
}

int sumaInt(int n){
	if(n<=9){
		return n;
	}else{
		return sumaInt(n/10)+(n%10);
	}
}
