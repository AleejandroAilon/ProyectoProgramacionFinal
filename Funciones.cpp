#include <iostream>
#include <complex>
using namespace std;

complex<double> crearComplejo(double real, double imaginario) {
    complex<double> numeroComplejo(real, imaginario);
    return numeroComplejo;
}

complex<double> sumarComplejos(complex<double> c1, complex<double> c2) {
    return c1 + c2;
}

complex<double> restarComplejos(complex<double> c1, complex<double> c2) {
    return c1 - c2;
}

complex<double> multiplicarComplejos(complex<double> c1, complex<double> c2) {
    return c1 * c2;
}

complex<double> dividirComplejos(complex<double> c1, complex<double> c2) {
    return c1 / c2;
}

void mostrarComplejo(complex<double> numeroComplejo) {
    cout << "Resultado: " << numeroComplejo << endl;
}

void solicitarDatos(double &real, double &imaginario, const string &descripcion) {
    cout << "Ingrese la parte real de " << descripcion << ": ";
    cin >> real;
    cout << "Ingrese la parte imaginaria de " << descripcion << ": ";
    cin >> imaginario;
}

int main() {
    double real1, imag1, real2, imag2;
    solicitarDatos(real1, imag1, "c1");
    solicitarDatos(real2, imag2, "c2");

    complex<double> c1 = crearComplejo(real1, imag1);
    complex<double> c2 = crearComplejo(real2, imag2);

    cout << "Seleccione la operación a realizar: " << endl;
    cout << "1. Sumar" << endl;
    cout << "2. Restar" << endl;
    cout << "3. Multiplicar" << endl;
    cout << "4. Dividir" << endl;

    int opcion;
    cin >> opcion;

    complex<double> resultado;

    switch(opcion) {
        case 1:
            resultado = sumarComplejos(c1, c2);
            mostrarComplejo(resultado);
            break;
        case 2:
            resultado = restarComplejos(c1, c2);
            mostrarComplejo(resultado);
            break;
        case 3:
            resultado = multiplicarComplejos(c1, c2);
            mostrarComplejo(resultado);
            break;
        case 4:
            resultado = dividirComplejos(c1, c2);
            mostrarComplejo(resultado);
            break;
        default:
            cout << "Opcion no valida" << endl;
    }

    return 0;
}

