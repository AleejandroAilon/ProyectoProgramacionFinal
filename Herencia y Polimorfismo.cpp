#include <iostream>

using namespace std;

// Clase base Figura
class Figura {
public:
    virtual double calcularArea() const = 0; // Método virtual puro para calcular el área
};

// Clase derivada Rectangulo
class Rectangulo : public Figura {
private:
    double base;
    double altura;

public:
    Rectangulo(double b, double h) : base(b), altura(h) {}

    double calcularArea() const override {
        return base * altura;
    }
};

// Clase derivada Triangulo
class Triangulo : public Figura {
private:
    double base;
    double altura;

public:
    Triangulo(double b, double h) : base(b), altura(h) {}

    double calcularArea() const override {
        return (base * altura) / 2.0;
    }
};

int main() {
    char opcion;
    double base, altura;

    cout << "Seleccione la figura:" << endl;
    cout << "R - Rectangulo" << endl;
    cout << "T - Triangulo" << endl;
    cin >> opcion;

    if (opcion == 'R' || opcion == 'r') {
        cout << "Ingrese la base del rectangulo: ";
        cin >> base;
        cout << "Ingrese la altura del rectangulo: ";
        cin >> altura;

        Figura* figura = new Rectangulo(base, altura);
        cout << "Area del Rectangulo: " << figura->calcularArea() << endl;
        delete figura;
    } else if (opcion == 'T' || opcion == 't') {
        cout << "Ingrese la base del triangulo: ";
        cin >> base;
        cout << "Ingrese la altura del triangulo: ";
        cin >> altura;

        Figura* figura = new Triangulo(base, altura);
        cout << "Area del Triangulo: " << figura->calcularArea() << endl;
        delete figura;
    } else {
        cout << "Opcion invalida." << endl;
    }

    return 0;
}

