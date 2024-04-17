#include <fstream>  // Para ofstream
#include <iostream> // Para cout
using namespace std;

void guarda_entero(int valor, string nombre_fichero);
int main()
{
  for (int i = 0; i < 10; ++i)
    guarda_entero(i, "ejemplo.txt");
}

void guarda_entero(int valor, string nombre_fichero)
{
  ofstream fich{nombre_fichero, ios::app};
  if (!fich)
  {
    cout << "Error al abrir " << nombre_fichero << endl;
    exit(EXIT_FAILURE);
  }
  fich << valor << endl;
}
