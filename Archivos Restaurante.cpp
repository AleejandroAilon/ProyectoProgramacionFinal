//ARCHIVOS RESTAURANTE
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

// Estructura para almacenar los datos de los platillos
struct Platillo {
    int codigo;
    char nombre[41];
    char chef[41];
    float precio;
    int cantidad;
};

void pausar() {
    cout << "Presione una tecla para continuar..." << endl;
    cin.get();
    cin.ignore();
    system("cls");
}

void agregar() {
    ofstream arch("restaurante.txt", ios::binary | ios::app);
    if (!arch) {
        exit(1);
    }
    Platillo platillo;
    int numeroPlatillos = 0;
    char continuar = 's';
    while (numeroPlatillos < 10 && (continuar == 's' || continuar == 'S')) {
        cout << "-----------------------------------------" << endl;
        cout << "Ingrese el codigo del platillo: ";
        cin >> platillo.codigo;
        cin.ignore();
        cout << "Ingrese el nombre del platillo: ";
        cin.getline(platillo.nombre, 41);
        cout << "Ingrese nombre del Chef: ";
        cin.getline(platillo.chef, 41);
        cout << "Ingrese el precio del platillo: ";
        cin >> platillo.precio;
        cout << "Ingrese la cantidad: ";
        cin >> platillo.cantidad;
        cout << "-----------------------------------------" << endl;
        arch.write(reinterpret_cast<char*>(&platillo), sizeof(Platillo));
        numeroPlatillos++;
        if (numeroPlatillos < 10) {
            cout << "Desea agregar otro platillo? (s/n): ";
            cin >> continuar;
            cin.ignore();
        }
    }
    arch.close();
    pausar();
    system("cls");
}

void listado() {
    ifstream arch("restaurante.txt", ios::binary);
    if (!arch) {
        exit(1);
    }
    Platillo platillo;
    int numeroPlatillo = 1;
    while (arch.read(reinterpret_cast<char*>(&platillo), sizeof(Platillo))) {
        cout << "-----------------------------------------" << endl;
        cout << "//PLATILLO " << numeroPlatillo << "//" << endl << endl;
        cout << "Codigo: " << platillo.codigo << endl;
        cout << "Nombre: " << platillo.nombre << endl;
        cout << "Chef: " << platillo.chef << endl;
        cout << "Precio: " << platillo.precio << endl;
        cout << "Cantidad: " << platillo.cantidad << endl << endl;
        numeroPlatillo++;
    }
    arch.close();
    // Preguntar al usuario si desea guardar la información en un archivo de texto
    string respuesta;
    cout << "Desea guardar esta informacion en un archivo de texto? (s/n): ";
    cin >> respuesta;
    if (respuesta == "s" || respuesta == "S") {
        string nombreArchivo;
        cout << "Ingrese un nombre para el archivo (sin extension): ";
        cin >> nombreArchivo;
        string rutaEscritorio = getenv("USERPROFILE");
        rutaEscritorio += "\\Desktop\\" + nombreArchivo + ".txt";
        ofstream archivoTexto(rutaEscritorio.c_str()); // Convertir std::string a const char*
        if (!archivoTexto) {
            cout << "No se pudo crear el archivo de texto en el escritorio." << endl;
        } else {
            ifstream arch("restaurante.txt", ios::binary);
            if (!arch) {
                exit(1);
            }
            while (arch.read(reinterpret_cast<char*>(&platillo), sizeof(Platillo))) {
                archivoTexto << "Codigo: " << platillo.codigo << endl;
                archivoTexto << "Nombre: " << platillo.nombre << endl;
                archivoTexto << "Chef: " << platillo.chef << endl;
                archivoTexto << "Precio: " << platillo.precio << endl;
                archivoTexto << "Cantidad: " << platillo.cantidad << endl << endl;
            }
            archivoTexto.close();
            cout << "La informacion se ha guardado en el escritorio en el archivo " << nombreArchivo << ".txt" << endl;
        }
    }
    pausar();
    system("cls");
}

void buscar() {
    ifstream arch("restaurante.txt", ios::binary);
    if (!arch) {
        exit(1);
    }
    int codigoBuscado;
    cout << "-----------------------------------------------" << endl;
    cout << "Ingrese el codigo del platillo a buscar: ";
    cin >> codigoBuscado;
    Platillo platillo;
    int encontrado = 0;
    while (arch.read(reinterpret_cast<char*>(&platillo), sizeof(Platillo))) {
        if (codigoBuscado == platillo.codigo) {
            cout << "-----------------------------------------------" << endl;
            cout << "Codigo: " << platillo.codigo << endl;
            cout << "Nombre: " << platillo.nombre << endl;
            cout << "Chef: " << platillo.chef << endl;
            cout << "Precio: " << platillo.precio << endl;
            cout << "Cantidad: " << platillo.cantidad << endl;
            cout << "-----------------------------------------------" << endl;
            encontrado = 1;
            break;
        }
    }
    if (encontrado == 0) {
        cout << "No se encontro ningun platillo con ese codigo" << endl;
    }
    arch.close();
    pausar();
    system("cls");
}

void modificarListado() {
    fstream arch("restaurante.txt", ios::binary | ios::in | ios::out);
    if (!arch) {
        exit(1);
    }
    int codigoModificar;
    cout << "-----------------------------------------" << endl;
    cout << "Ingrese el codigo del platillo a modificar: ";
    cin >> codigoModificar;
    cout << "-----------------------------------------" << endl;
    Platillo platillo;
    int encontrado = 0;
    fstream temp("temp.txt", ios::binary | ios::out);
    while (arch.read(reinterpret_cast<char*>(&platillo), sizeof(Platillo))) {
        if (codigoModificar == platillo.codigo) {
            cout << "-----------------------------------------" << endl;
            cout << "//Registro a modificar//" << endl;
            cout << "Codigo: " << platillo.codigo << endl;
            cout << "Nombre: " << platillo.nombre << endl;
            cout << "Chef: " << platillo.chef << endl;
            cout << "Precio: " << platillo.precio << endl;
            cout << "Cantidad: " << platillo.cantidad << endl;
            cout << "-----------------------------------------" << endl;
            cout << "Ingrese el nuevo codigo del platillo: ";
            cin >> platillo.codigo;
            cin.ignore();
            cout << "Ingrese el nuevo nombre del platillo: ";
            cin.getline(platillo.nombre, 41);
           
cout << "Ingrese el nuevo precio del platillo: ";
            cin >> platillo.precio;
            cout << "Ingrese la nueva cantidad: ";
            cin >> platillo.cantidad;
            cout << "-----------------------------------------" << endl;
            temp.write(reinterpret_cast<char*>(&platillo), sizeof(Platillo));
            cout << "Se modificaron los datos del platillo exitosamente " << endl;
            encontrado = 1;
        } else {
            temp.write(reinterpret_cast<char*>(&platillo), sizeof(Platillo));
        }
    }
    arch.close();
    temp.close();
    remove("restaurante.txt");
    rename("temp.txt", "restaurante.txt");
    if (encontrado == 0) {
        cout << "No se encontro ningun platillo con ese codigo" << endl;
    }
    pausar();
    system("cls");
}

void eliminar() {
    ifstream archEntrada("restaurante.txt", ios::binary);
    ofstream archSalida("temp.txt", ios::binary | ios::out);
    if (!archEntrada || !archSalida) {
        exit(1);
    }
    int codigoEliminar;
    cout << "-----------------------------------------" << endl;
    cout << "Ingrese el codigo del platillo a eliminar: ";
    cin >> codigoEliminar;
    cout << "-----------------------------------------" << endl;
    Platillo platillo;
    int eliminado = 0;
    while (archEntrada.read(reinterpret_cast<char*>(&platillo), sizeof(Platillo))) {
        if (codigoEliminar == platillo.codigo) {
            cout << "//Se ha eliminado el registro del platillo exitosamente//" << endl;
            eliminado = 1;
        } else {
            archSalida.write(reinterpret_cast<char*>(&platillo), sizeof(Platillo));
        }
    }
    archSalida.close();
    archEntrada.close();
    remove("restaurante.txt");
    rename("temp.txt", "restaurante.txt");
    pausar();
    system("cls");
}

int main() {
    int opcion;
    do {
        cout <<"------------------------------MENU DE OPCIONES------------------------------\n";
        cout << "1 - Agregar un platillo" << endl;
        cout << "2 - Leer el listado de platillos y guardar informacion" << endl;
        cout << "3 - Buscar un platillo por su codigo" << endl;
        cout << "4 - Modificar un platillo" << endl;
        cout << "5 - Eliminar un platillo" << endl;
        cout << "6 - Salir";
        cout <<"\n----------------------------------------------------------------------------\n";
        cout << "Ingrese su opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                agregar();
                break;
            case 2:
                listado();
                break;
            case 3:
                buscar();
                break;
            case 4:
                modificarListado();
                break;
            case 5:
                eliminar();
                break;
        }
    } while (opcion != 6);
    return 0;
}
