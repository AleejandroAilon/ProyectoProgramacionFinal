#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Empleado {
protected:
    string nombre;
    double salario;

public:
    Empleado(const string& nombre, double salario)
        : nombre(nombre), salario(salario) {}

    virtual void describirTrabajo() const = 0; // Método virtual puro

    void mostrarInformacion() const {
        cout << "Nombre: " << nombre << endl;
        cout << "Salario: " << salario << endl;
    }

    virtual ~Empleado() {}
};

class Cocinero : public Empleado {
private:
    string especialidad;

public:
    Cocinero(const string& nombre, double salario, const string& especialidad)
        : Empleado(nombre, salario), especialidad(especialidad) {}

    void describirTrabajo() const {
        cout << "Soy un cocinero especializado en " << especialidad << ".\n";
    }
};

class Camarero : public Empleado {
private:
    string seccion;

public:
    Camarero(const string& nombre, double salario, const string& seccion)
        : Empleado(nombre, salario), seccion(seccion) {}

    void describirTrabajo() const {
        cout << "Soy un camarero y trabajo en la seccion " << seccion << ".\n";
    }
};

class Gerente : public Empleado {
public:
    Gerente(const string& nombre, double salario)
        : Empleado(nombre, salario) {}

    void describirTrabajo() const {
        cout << "Soy el gerente del restaurante.\n";
    }
};

int main() {
    vector<Empleado*> empleados;
    empleados.push_back(new Cocinero("Juan", 3000, "postres"));
    empleados.push_back(new Camarero("Pedro", 2000, "exterior"));
    empleados.push_back(new Gerente("María", 5000));

    for (vector<Empleado*>::iterator it = empleados.begin(); it != empleados.end(); ++it) {
        (*it)->mostrarInformacion();
        (*it)->describirTrabajo();
        cout << endl;
    }

    for (vector<Empleado*>::iterator it = empleados.begin(); it != empleados.end(); ++it) {
        delete *it;
    }

    cout << "Presiona ENTER para finalizar...";
    cin.get(); // Espera a que el usuario presione ENTER
    return 0;
}
