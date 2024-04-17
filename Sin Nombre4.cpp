#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // Para EXIT_FAILURE

using namespace std;

void muestra_vector(const vector<string>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }
}

int main() {
    ifstream fich("nombre_apellidos.txt");
    if (!fich.is_open()) {
        cout << "Error al abrir el archivo nombre_apellidos.txt" << endl;
        return EXIT_FAILURE;
    }

    int num_elementos;
    fich >> num_elementos;
    vector<string> datos;
    datos.reserve(num_elementos);
    for (int i = 0; i < num_elementos; ++i) {
        string valor;
        fich >> valor;
        datos.push_back(valor);
    }
    muestra_vector(datos);

    return 0;
}
