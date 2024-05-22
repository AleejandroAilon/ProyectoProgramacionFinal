#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // Para formatear la salida de los precios

using namespace std;

// Estructura para los artículos del menú
struct Item {
    string nombre;
    double precio;
};

// Función para mostrar el menú
void mostrarMenu(const vector<Item>& menu) {
    cout << "Menu del Restaurante" << endl;
    cout << "-------------------" << endl;
    for (size_t i = 0; i < menu.size(); ++i) {
        cout << i + 1 << ". " << menu[i].nombre << " - Q" << fixed << setprecision(2) << menu[i].precio << endl;
    }
    cout << "-------------------" << endl;
}

// Función para registrar una venta
void registrarVenta(const vector<Item>& menu, double& ventasTotales) {
    char seguirComprando;
    do {
        int opcion;
        cout << "Ingrese el numero del articulo vendido: ";
        cin >> opcion;

        if (opcion > 0 && opcion <= static_cast<int>(menu.size())) {
            double precioVenta = menu[opcion - 1].precio;
            cout << "Aplicar descuento? (s/n): ";
            char aplicarDescuento;
            cin >> aplicarDescuento;

            if (aplicarDescuento == 's' || aplicarDescuento == 'S') {
                double descuento;
                cout << "Ingrese el porcentaje de descuento (0-100): ";
                cin >> descuento;
                if (descuento > 0 && descuento <= 100) {
                    precioVenta -= (precioVenta * (descuento / 100));
                } else {
                    cout << "Descuento no valido. No se aplicara descuento." << endl;
                }
            }

            ventasTotales += precioVenta;
            cout << "Venta registrada: " << menu[opcion - 1].nombre << " - Q" << fixed << setprecision(2) << precioVenta << endl;
        } else {
            cout << "Opcion no valida. Por favor, ingrese un numero de articulo valido." << endl;
        }

        cout << "Desea registrar otra venta? (s/n): ";
        cin >> seguirComprando;
    } while (seguirComprando == 's' || seguirComprando == 'S');
}

int main() {
    // Variables para el control del programa
    char opcion;
    bool continuar = true;

    // Variables para el registro de ventas
    double ventasTotales = 0.0;

    // Menú del restaurante
    vector<Item> menu = {
        {"Hamburguesa", 8.50},
        {"Pizza", 12.00},
        {"Ensalada", 7.25},
        {"Taco", 3.75},
        {"Refresco", 1.50}
    };

    // Ciclo principal del programa
    while (continuar) {
        // Menú de opciones
        cout << "Bienvenido al sistema de ventas del Restaurante" << endl;
        cout << "1. Mostrar menu" << endl;
        cout << "2. Registrar venta" << endl;
        cout << "3. Mostrar ventas totales" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        // Condicionales para manejar las opciones del usuario
        switch(opcion) {
            case '1':
                // Mostrar menú
                mostrarMenu(menu);
                break;
            case '2':
                // Registrar venta
                registrarVenta(menu, ventasTotales);
                break;
            case '3':
                // Mostrar ventas totales
                cout << "Las ventas totales son: Q" << fixed << setprecision(2) << ventasTotales << endl;
                break;
            case '4':
                // Salir del programa
                cout << "Saliendo del programa..." << endl;
                continuar = false;
                break;
            default:
                cout << "Opcion no valida. Por favor, ingrese una opción valida." << endl;
                break;
        }
    }

    return 0;
}


