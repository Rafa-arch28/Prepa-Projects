#include <iostream>
using namespace std;

struct Empleado
{
    string nombre;
    string a_paterno;
    string a_materno;
    long int sueldo; // por si acaso pq ya me paso que el programa muere por no poder con un entero grande jaja
};

int main()
{

    Empleado empleado;

    cout << "Ingrese el nombre del empleado: ";
    cin >> ws;
    getline(cin, empleado.nombre);

    cout << "Ingrese el apelldio paterno del empleado: ";
    cin >> ws;
    getline(cin, empleado.a_paterno);

    cout << "Ingrese el apellido materno del empleado: ";
    cin >> ws;
    getline(cin, empleado.a_materno);

    cout << "Ingrese el sueldo del empleado: ";
    cin >> empleado.sueldo;
    cout << endl;

    cout << "DATOS DEL EMPLEADO" << endl;
    cout << "Nombre: " << empleado.nombre << endl;
    cout << "Apellido Paterno: " << empleado.a_paterno << endl;
    cout << "Apellido Materno: " << empleado.a_materno << endl;
    cout << "Sueldo: $" << empleado.sueldo << endl;

    return 0;
}