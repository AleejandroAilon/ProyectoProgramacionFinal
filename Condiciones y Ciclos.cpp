#include <iostream>
using namespace std;

int main() {
    // Variables para el control del programa
    char opcion;
    bool continuar = true;

    // Variables para el registro de ventas
    int ventasTotales = 0;
    int ventaActual;
    
    // Ciclo principal del programa
    while (continuar) {
        // Menú de opciones
        cout << "Bienvenido al sistema de ventas" << endl;
        cout << "1. Registrar venta" << endl;
        cout << "2. Mostrar ventas totales" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        // Condicionales para manejar las opciones del usuario
        switch(opcion) {
            case '1':
                // Registro de venta
                cout << "Ingrese el monto de la venta: $";
                cin >> ventaActual;
                ventasTotales += ventaActual;
                cout << "Venta registrada correctamente." << endl;
                break;
            case '2':
                // Mostrar ventas totales
                cout << "Las ventas totales son: $" << ventasTotales << endl;
                break;
            case '3':
                // Salir del programa
                cout << "Saliendo del programa..." << endl;
                continuar = false;
                break;
            default:
                cout << "Opcion no valida. Por favor, ingrese una opción valida." << endl;
                break;
        }
    }
}
