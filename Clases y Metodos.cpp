#include <iostream>
#include <string>

using namespace std;

// Clase Personaje
class Personaje {
private:
    string name;
    int health;
    int attack;

public:
    // Constructor
    Personaje(string _name, int _health, int _attack) {
        name = _name;
        health = _health;
        attack = _attack;
    }

    // M�todo para obtener el nombre del personaje
    string obtenerNombre() {
        return name;
    }

    // M�todo para obtener la salud del personaje
    int obtenerSalud() {
        return health;
    }

    // M�todo para recibir da�o
    void recibirDanio(int cantidad) {
        health -= cantidad;
        if (health < 0) {
            health = 0;
        }
    }

    // M�todo para atacar a otro personaje
    void atacar(Personaje &objetivo) {
        cout << name << " ataca a " << objetivo.obtenerNombre() << " y causa " << attack << " de danio." << endl;
        objetivo.recibirDanio(attack);
    }

    // M�todo para mostrar el estado del personaje
    void mostrarEstado() {
        cout << name << " - Salud: " << health << ", Ataque: " << attack << endl;
    }
};

// Funci�n principal
int main() {
    string name;
    int health, attack;

    // Ingresar caracter�sticas del h�roe
    cout << "Ingrese el nombre del heroe: ";
    getline(cin, name);
    cout << "Ingrese la salud del heroe: ";
    cin >> health;
    cout << "Ingrese el ataque del heroe: ";
    cin >> attack;
    Personaje heroe(name, health, attack);

    // Limpiar el buffer de entrada
    cin.ignore();
    
    cout << "\n-------------------------------" << endl;

    // Ingresar caracter�sticas del enemigo
    cout << "Ingrese el nombre del enemigo: ";
    getline(cin, name);
    cout << "Ingrese la salud del enemigo: ";
    cin >> health;
    cout << "Ingrese el ataque del enemigo: ";
    cin >> attack;
    Personaje enemigo(name, health, attack);
    
    cout << "\n----------------------------------------" << endl;

    // Mostrar el estado inicial de los personajes
    cout << "\nEstado inicial:" << endl;
    heroe.mostrarEstado();
    enemigo.mostrarEstado();

    // Simulaci�n de combate
    cout << "\nCombate:" << endl;
    heroe.atacar(enemigo);
    enemigo.atacar(heroe);
    heroe.atacar(enemigo);

    // Mostrar el estado final de los personajes
    cout << "\nEstado final:" << endl;
    heroe.mostrarEstado();
    enemigo.mostrarEstado();
}
