#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib> // Para EXIT_FAILURE
using namespace std;

void puntuacion(vector<string>& pilotos, vector<int>& puntos, const string& nombre_fichero);
int calcula_puntuacion(const vector<int>& puestos);
void muestra_puntuacion(const vector<string>& pilotos, const vector<int>& puntos);

int main()
{
    vector<string> pilotos;
    vector<int> puntos;
    puntuacion(pilotos, puntos, "pilotos_clasificaciones.txt");
    muestra_puntuacion(pilotos, puntos);
}

void puntuacion(vector<string>& pilotos, vector<int>& puntos, const string& nombre_fichero)
{
    ifstream fich(nombre_fichero.c_str());
    if (!fich.is_open())
    {
        cout <<"Error al abrir " << nombre_fichero << "\n";
        exit(EXIT_FAILURE);
    }

    int num_carreras;
    fich >> num_carreras;
    int num_pilotos;
    fich >> num_pilotos;

    pilotos.clear();
    puntos.clear();

    for (int i = 0; i < num_pilotos; ++i)
    {
        string piloto;
        fich >> piloto;
        pilotos.push_back(piloto);
        vector<int> puestos;
        for (int j = 0; j < num_carreras; ++j)
        {
            int puesto; // <- Aquí estaba el error
            fich >> puesto;
            puestos.push_back(puesto);
        }
        puntos.push_back(calcula_puntuacion(puestos));
    }
}

int calcula_puntuacion(const vector<int>& puestos)
{
    const int puntos[] = {10, 8, 6, 5, 4, 3, 2, 1};
    const int num_puntos = sizeof(puntos) / sizeof(puntos[0]);

    int suma = 0;
    for (auto puesto : puestos)
    {
        if (puesto > 0 && puesto <= num_puntos)
        {
            suma += puntos[puesto - 1];
        }
    }
    return suma;
}

void muestra_puntuacion(const vector<string>& pilotos, const vector<int>& puntos)
{
    cout << "\nLa puntuación actual es:\n\n";
    for (int i = 0; i < pilotos.size(); ++i)
    {
        cout << pilotos[i] << " " << puntos[i] << endl;
    }
    cout << endl << endl;
}
