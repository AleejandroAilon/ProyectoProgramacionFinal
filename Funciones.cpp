#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Estructura para almacenar los elementos del menú
struct MenuItem {
    string nombre;
    double precio;
};

// Declaración de funciones
void mostrarMenu(const vector<MenuItem>& menu);
void agregarPedido(vector<MenuItem>& pedidos, const vector<MenuItem>& menu, int indice);
double calcularTotal(const vector<MenuItem>& pedidos);

int main() {
    // Inicialización del menú del restaurante
    vector<MenuItem> menu = {
        {"Pizza", 8.99},
        {"Hamburguesa", 5.49},
        {"Pasta", 7.99},
        {"Ensalada", 4.99},
        {"Soda", 1.99}
    };

    vector<MenuItem> pedidos;
    int opcion;

    do {
        cout << "\nBienvenido al Restaurante\n";
        cout << "1. Mostrar Menu\n";
        cout << "2. Agregar Pedido\n";
        cout << "3. Calcular Total\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                mostrarMenu(menu);
                break;
            case 2: {
                int indice;
                mostrarMenu(menu);
                cout << "Ingrese el número del ítem que desea agregar al pedido: ";
                cin >> indice;
                if (indice > 0 && indice <= menu.size()) {
                    agregarPedido(pedidos, menu, indice - 1);
                } else {
                    cout << "Ítem inválido.\n";
                }
                break;
            }
            case 3:
                cout << "El total de su cuenta es: $" << calcularTotal(pedidos) << endl;
                break;
            case 4:
                cout << "Gracias por visitar nuestro restaurante.\n";
                break;
            default:
                cout << "Opción inválida. Inténtelo de nuevo.\n";
        }
    } while(opcion != 4);

    return 0;
}

// Definición de funciones
void mostrarMenu(const vector<MenuItem>& menu) {
    cout << "\nMenu del Restaurante:\n";
    for (size_t i = 0; i < menu.size(); ++i) {
        cout << i + 1 << ". " << menu[i].nombre << " - $" << menu[i].precio << endl;
    }
}

void agregarPedido(vector<MenuItem>& pedidos, const vector<MenuItem>& menu, int indice) {
    pedidos.push_back(menu[indice]);
    cout << menu[indice].nombre << " ha sido agregado a su pedido.\n";
}

double calcularTotal(const vector<MenuItem>& pedidos) {
    double total = 0.0;
    for (const auto& item : pedidos) {
        total += item.precio;
    }
    return total;
}
