#include <fstream>  // Para ifstream
#include <iostream> // Para cout
#include <vector>
#include <cstdlib>  // Para EXIT_FAILURE
using namespace std;

void muestra_vector(const vector<int>&);

int main()
{
    ifstream fich("ejemplo.dat");
    if (!fich.is_open())
    {
        cout <<"Error al abrir ejemplo.dat\n";
        exit(EXIT_FAILURE); // Utilizamos EXIT_FAILURE de la biblioteca cstdlib
    }

    int num_elementos;
    fich >> num_elementos;

    vector<int> datos;
    datos.reserve(num_elementos);

    for (int i = 0; i < num_elementos; ++i)
    {
        int valor;
        fich >> valor;
        datos.push_back(valor);
    }

    muestra_vector(datos);
}

void muestra_vector(const vector<int>& v)
{
    for (size_t i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
