#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <limits>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> Position;

struct Posiciones{
	int x;
    int y;
    Posiciones(int x,int y) : x(x), y(y){}
};

vector<vector<int> > leerMatrixFile();
void Encontrar_camino(vector<vector<int> >& matriz, int x1, int y1, int x2, int y2, vector<Posiciones>& cam, vector<vector<Posiciones> >& camino);
void Imprimir_camino(const vector<vector<Posiciones> > &cam);
void ImprimirCaminoCorto(const vector<vector<Posiciones> >& Camino);
ostream& operator<<(ostream& os, const vector<vector<int> >& matriz);

int main(){
	
    string NombreArchivo = "matriz.txt";
    vector<vector<int> > matriz;
    
    ifstream Archivo(NombreArchivo.c_str());
    if (!Archivo){
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }
    cout<<leerMatrixFile();
 	// Leer la matriz
 	matriz = leerMatrixFile();
    // Cerrar el archivo
    Archivo.close();

	//Posiciones de origen y destino
    int x1, y1, x2, y2;
    cout << "Ingrese la posicion x de origen: ";
    cin >> x1;
    cout << "Ingrese la posicion y de origen: ";
    cin >> y1;
    cout << "Ingrese la posicion x de destino: ";
    cin >> x2;
    cout << "Ingrese la posicion y de destino: ";
    cin >> y2;
    
    int filas= matriz.size();
    int columnas= matriz[0].size();
    
	// Validar las posiciones de origen y destino
    if (x1 < 0 || x1 >= filas || y1 < 0 || y1 >= columnas || x2 < 0 || x2 >= filas || y2 < 0 || y2 >= columnas){
        cerr << "Las posiciones de origen y destino estan fuera de los limites de la matriz." << endl;
        return 1;
    }

	// Crear una matriz auxiliar para marcar las posiciones visitadas
    vector<vector<int> > visited(filas, vector<int>(columnas, 0));
    
	//Encontrar los caminos posibles
    vector<Posiciones> camino;
    vector<vector<Posiciones> >Camino;
    Encontrar_camino(matriz, x1, y1, x2, y2, camino, Camino);

    //Imprimir los caminos posibles
    Imprimir_camino(Camino);

    //Imprimir el camino mas corto
    ImprimirCaminoCorto(Camino);

    return 0;
}

vector<vector<int> > leerMatrixFile() {
    vector<vector<int> > matriz;
    ifstream f("matriz.txt");
    if (f.is_open()) {
        string linea;
        while (getline(f, linea)) {
            vector<int> fila;
            stringstream ss(linea);
            string valor;
            while (getline(ss, valor, ',')) {
                int numero;
                istringstream iss(valor);
                if (iss >> numero) {
                    fila.push_back(numero);
                }
            }
            matriz.push_back(fila);
        }
        f.close();
    }
    return matriz;
}


void Encontrar_camino(vector<vector<int> >& matriz, int x1, int y1, int x2, int y2, vector<Posiciones>& cam, vector<vector<Posiciones> >& camino) {
    int filas = matriz.size();
    int columnas = matriz[0].size();

    //Marcar la posición actual como visitada
    matriz[x1][y1] = 0;

    //Agregar la posición actual al camino
    cam.push_back(Posiciones(x1, y1));

    //Verificar la posición de destino
    if (x1 == x2 && y1 == y2) {
        camino.push_back(cam);
    }else{
        //Cuatro direcciones
        vector<pair<int, int> > direccion;
        direccion.push_back(make_pair(0, 1));
        direccion.push_back(make_pair(0, -1));
        direccion.push_back(make_pair(1, 0));
        direccion.push_back(make_pair(-1, 0));
        for (size_t i = 0; i < direccion.size(); i++) {
            int nueva_x = x1 + direccion[i].first;
            int nueva_y = y1 + direccion[i].second;

            if (nueva_x >= 0 && nueva_x < filas && nueva_y >= 0 && nueva_y < columnas && matriz[nueva_x][nueva_y] != 0) {
                Encontrar_camino(matriz, nueva_x, nueva_y, x2, y2, cam, camino);
            }
        }
    }
    
	//Retroceder un paso
    matriz[x1][y1] = 1;
    cam.pop_back();   
}

//Imprimir todos los caminos posibles
void Imprimir_camino(const vector<vector<Posiciones> > &cam){
    cout<<"Los caminos posibles son:"<<endl;
    for (size_t i = 0; i < cam.size(); i++) {
    cout << "Camino => ";
    	for (size_t j = 0; j < cam[i].size(); j++) {
        	cout << "(" << cam[i][j].x << ", " << cam[i][j].y << ") ";
    	}
    	cout << endl;
	}
}

	//Imprimir el camino mas corto
void ImprimirCaminoCorto(const vector<vector<Posiciones> >& Camino){
    cout << "Camino mas corto es ;):" << endl;
    if (Camino.empty()) {
        cout << "No se encontraron caminos :(" << endl;
        return;
    }
    int caminoCorto = numeric_limits<int>::max();
    const vector<Posiciones>* CaminoCorto = NULL;
    for (size_t i = 0; i < Camino.size(); i++) {
        const vector<Posiciones>& caminoActual = Camino[i];
        if (caminoActual.size() < caminoCorto) {
            caminoCorto = caminoActual.size();
            CaminoCorto = &caminoActual;
        }
    }
    // Imprimir el camino más corto
    if (CaminoCorto != NULL) {
        for (size_t i = 0; i < CaminoCorto->size(); i++) {
            const Posiciones& pos = (*CaminoCorto)[i];
            cout << "(" << pos.x << ", " << pos.y << ") ";
        }
    }
    cout << endl;
}
	//sobrecargar el operador de inserción para 
ostream& operator<<(ostream& os, const vector<vector<int> >& matriz) {
    for (vector<vector<int> >::const_iterator it = matriz.begin(); it != matriz.end(); ++it) {
    	const vector<int>& fila = *it;
    	for (vector<int>::const_iterator it2 = fila.begin(); it2 != fila.end(); ++it2) {
        	int valor = *it2;
        	os << valor << " ";
    	}
    	os << endl;
	}
    return os;
}

