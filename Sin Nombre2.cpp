#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Definición de la clase Persona
class Persona {
private:
    string nombre;
    int edad;
    string ocupacion;
public:
    // Constructor
    Persona(string n, int e, string o) : nombre(n), edad(e), ocupacion(o) {}

    // Métodos para establecer y obtener los valores de los atributos
    void setNombre(string n) { 
	nombre = n; 
	}
    void setEdad(int e){
	edad = e;
	}
    void setOcupacion(string o) {
	ocupacion = o;
	}
    string getNombre() const {
	return nombre; 
	}
    int getEdad() const {
	return edad;
	}
    string getOcupacion() const {
	return ocupacion;
	}
};

// Función para almacenar los datos de las personas en un archivo de texto
void guardarPersonas(const vector<Persona>& personas) {
    ofstream archivo("personas.txt");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }
    archivo  void (const auto& persona : personas) {
        archivo << "Nombre: " << persona.getNombre() << ", Edad: " << persona.getEdad() << ", Ocupacion: " << persona.getOcupacion() << endl;
    }
    archivo.close();
    cout << "Datos guardados en el archivo personas.txt" << endl;
}

// Función para leer los datos de las personas desde un archivo de texto y mostrarlos en pantalla
void mostrarPersonas() {
    ifstream archivo("personas.txt");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }
    string linea;
    cout << "Datos de las personas almacenadas:" << endl;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }
    archivo.close();
}

int main() {
    vector<Persona> personas;

    cout << "Ingrese los datos de las personas (nombre, edad y ocupacion), o escriba 'fin' para terminar:" << endl;
    while (true) {
        string nombre, ocupacion;
        int edad;
        cout << "Nombre: ";
        getline(cin, nombre);
        if (nombre == "fin") {
            break;
        }
        cout << "Edad: ";
        cin >> edad;
        cin.ignore(); // Limpiar el buffer del salto de línea
        cout << "Ocupacion: ";
        getline(cin, ocupacion);

        personas.push_back(Persona(nombre, edad, ocupacion));
    }

    // Guardar los datos de las personas en un archivo
    guardarPersonas(personas);

    // Mostrar los datos de las personas almacenadas en el archivo
    mostrarPersonas();

    return 0;
}
