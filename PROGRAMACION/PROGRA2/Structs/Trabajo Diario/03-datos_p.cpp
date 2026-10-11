#include <iostream>
using namespace std;

struct Persona
{
    string nombre;
    string apellido;
    int edad;
};

int main()
{

    Persona persona;

    cout << "Ingrese su nombre: ";
    cin >> ws;
    getline(cin, persona.nombre);

    cout << "Ingrese su apellido: ";
    cin >> ws;
    getline(cin, persona.apellido);

    cout << "Ingrese su edad: ";
    cin >> persona.edad;

    cout << persona.nombre << ", " << persona.apellido << ", " << persona.edad;

    return 0;
}