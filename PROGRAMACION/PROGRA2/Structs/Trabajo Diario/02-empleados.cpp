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
    int n = 0;

    cout << "Ingrese un numero de trabajadores: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "El numero de trabajadores debe ser mayor que cero." << endl;
        return 0;
    }

    Empleado empleados[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Ingrese el nombre del empleado: ";
        cin >> ws;
        getline(cin, empleados[i].nombre);

        cout << "Ingrese el apelldio paterno del empleado: ";
        cin >> ws;
        getline(cin, empleados[i].a_paterno);

        cout << "Ingrese el apellido materno del empleado: ";
        cin >> ws;
        getline(cin, empleados[i].a_materno);

        cout << "Ingrese el sueldo del empleado: ";
        cin >> empleados[i].sueldo;
        cout << endl;
    }

    long int mayor = empleados[0].sueldo;
    long int menor = empleados[0].sueldo;

    for (int i = 1; i < n; i++)
    {
        if (empleados[i].sueldo > mayor)
        {
            mayor = empleados[i].sueldo;
        }
        if (empleados[i].sueldo < menor)
        {
            menor = empleados[i].sueldo;
        }
    }

    cout << "DATOS DEL EMPLEADO CON MAYOR SUELDO" << endl;
    for (int i = 0; i < n; i++)
    {
        if (empleados[i].sueldo == mayor)
        {
            cout << "Nombre: " << empleados[i].nombre << endl;
            cout << "Apellido Paterno: " << empleados[i].a_paterno << endl;
            cout << "Apellido Materno: " << empleados[i].a_materno << endl;
            cout << "Sueldo: $" << empleados[i].sueldo << endl << endl;
        }
    }

    cout << "DATOS DEL EMPLEADO CON MENOR SUELDO" << endl;
    for (int i = 0; i < n; i++)
    {
        if (empleados[i].sueldo == menor)
        {
            cout << "Nombre: " << empleados[i].nombre << endl;
            cout << "Apellido Paterno: " << empleados[i].a_paterno << endl;
            cout << "Apellido Materno: " << empleados[i].a_materno << endl;
            cout << "Sueldo: $" << empleados[i].sueldo << endl << endl;
        }
    }

    return 0;
}