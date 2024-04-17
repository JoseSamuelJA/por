#include <iostream>
#include <string>

using namespace std;

class Personal {
private:
    string nombre;
    int edad;
    string ocupacion;
public:
    Personal(string n, int e, string o) {
        nombre = n;
        edad = e;
        ocupacion = o;
    }
    
    void mostrarInfo() {
        cout << "Nombre: " << nombre << ", Edad: " << edad << ", Ocupacion: " << ocupacion << endl;
    }
};

int main() {
    string n, o; // Declarar las variables para almacenar el nombre y la ocupaci�n
    int e; // Declarar la variable para almacenar la edad
    
    cout << "Ingrese el nombre: ";
    cin >> n;
    cout << "Ingrese la edad: ";
    cin >> e;
    cout << "Ingrese la ocupacion: ";
    cin >> o;
    
    Personal persona(n, e, o); // Crear un objeto de la clase Personal
    
    // Llamar al m�todo mostrarInfo() para mostrar la informaci�n de la persona
    persona.mostrarInfo();
    
    return 0;
}
