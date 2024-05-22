#include <iostream>
#include <string>
#include <vector>

class Empleado {
protected:
    std::string nombre;
    double salario;

public:
    Empleado(const std::string& nombre, double salario)
        : nombre(nombre), salario(salario) {}

    virtual void describirTrabajo() const = 0; // Método virtual puro

    void mostrarInformacion() const {
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Salario: " << salario << std::endl;
    }

    virtual ~Empleado() {}
};

class Cocinero : public Empleado {
private:
    std::string especialidad;

public:
    Cocinero(const std::string& nombre, double salario, const std::string& especialidad)
        : Empleado(nombre, salario), especialidad(especialidad) {}

    void describirTrabajo() const {
        std::cout << "Soy un cocinero especializado en " << especialidad << ".\n";
    }
};

class Camarero : public Empleado {
private:
    std::string seccion;

public:
    Camarero(const std::string& nombre, double salario, const std::string& seccion)
        : Empleado(nombre, salario), seccion(seccion) {}

    void describirTrabajo() const {
        std::cout << "Soy un camarero y trabajo en la seccion " << seccion << ".\n";
    }
};

class Gerente : public Empleado {
public:
    Gerente(const std::string& nombre, double salario)
        : Empleado(nombre, salario) {}

    void describirTrabajo() const {
        std::cout << "Soy el gerente del restaurante.\n";
    }
};

int main() {
    std::vector<Empleado*> empleados;
    empleados.push_back(new Cocinero("Juan", 3000, "postres"));
    empleados.push_back(new Camarero("Pedro", 2000, "exterior"));
    empleados.push_back(new Gerente("María", 5000));

    for (std::vector<Empleado*>::iterator it = empleados.begin(); it != empleados.end(); ++it) {
        (*it)->mostrarInformacion();
        (*it)->describirTrabajo();
        std::cout << std::endl;
    }

    for (std::vector<Empleado*>::iterator it = empleados.begin(); it != empleados.end(); ++it) {
        delete *it;
    }

    return 0;
}
