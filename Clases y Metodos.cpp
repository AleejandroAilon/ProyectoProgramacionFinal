#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Clase Plato
class Plato {
private:
    string nombre;
    double precio;
    int calorias;

public:
    // Constructor
    Plato(string _nombre, double _precio, int _calorias)
        : nombre(_nombre), precio(_precio), calorias(_calorias) {}

    // Métodos para obtener los atributos del plato
    string obtenerNombre() const {
        return nombre;
    }

    double obtenerPrecio() const {
        return precio;
    }

    int obtenerCalorias() const {
        return calorias;
    }

    // Métodos para establecer los atributos del plato
    void establecerNombre(const string& _nombre) {
        nombre = _nombre;
    }

    void establecerPrecio(double _precio) {
        precio = _precio;
    }

    void establecerCalorias(int _calorias) {
        calorias = _calorias;
    }

    // Método para mostrar el estado del plato
    void mostrarEstado() const {
        cout << "Nombre: " << nombre << " - Precio: $" << precio << " - Calorias: " << calorias << " cal" << endl;
    }
};

// Clase Restaurante
class Restaurante {
private:
    vector<Plato> menu;

public:
    // Método para agregar un plato al menú
    void agregarPlato(const Plato& plato) {
        menu.push_back(plato);
    }

    // Método para mostrar el menú completo
    void mostrarMenu() const {
        cout << "Menu del Restaurante:" << endl;
        for (const auto& plato : menu) {
            plato.mostrarEstado();
        }
    }

    // Método para actualizar un plato del menú
    void actualizarPlato(const string& nombre) {
        for (auto& plato : menu) {
            if (plato.obtenerNombre() == nombre) {
                string nuevoNombre;
                double nuevoPrecio;
                int nuevasCalorias;

                cout << "Ingrese el nuevo nombre del plato: ";
                cin.ignore();
                getline(cin, nuevoNombre);
                cout << "Ingrese el nuevo precio del plato: ";
                cin >> nuevoPrecio;
                cout << "Ingrese las nuevas calorías del plato: ";
                cin >> nuevasCalorias;

                plato.establecerNombre(nuevoNombre);
                plato.establecerPrecio(nuevoPrecio);
                plato.establecerCalorias(nuevasCalorias);

                cout << "Plato actualizado exitosamente." << endl;
                return;
            }
        }
        cout << "Plato no encontrado en el menu." << endl;
    }
};

// Función principal
int main() {
    Restaurante restaurante;
    int opcion;

    do {
        cout << "------------------------------MENu DE OPCIONES------------------------------\n";
        cout << "1 - Agregar un plato" << endl;
        cout << "2 - Mostrar el menu completo" << endl;
        cout << "3 - Actualizar un plato" << endl;
        cout << "4 - Salir" << endl;
        cout << "----------------------------------------------------------------------------\n";
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombre;
                double precio;
                int calorias;

                cout << "Ingrese el nombre del plato: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese el precio del plato: ";
                cin >> precio;
                cout << "Ingrese las calorias del plato: ";
                cin >> calorias;

                Plato nuevoPlato(nombre, precio, calorias);
                restaurante.agregarPlato(nuevoPlato);
                cout << "Plato agregado exitosamente." << endl;
                break;
            }
            case 2:
                restaurante.mostrarMenu();
                break;
            case 3: {
                string nombre;

                cout << "Ingrese el nombre del plato a actualizar: ";
                cin.ignore();
                getline(cin, nombre);

                restaurante.actualizarPlato(nombre);
                break;
            }
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);

    return 0;
}
