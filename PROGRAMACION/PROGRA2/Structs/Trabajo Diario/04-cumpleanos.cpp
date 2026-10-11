#include <iostream>
using namespace std;

struct Fecha
{
    int dia;
    int mes;
    int anio;
};

struct Persona
{
    string nombre;
    Fecha fecha;
};

int main()
{
    Persona personas[8];
    int xmes;

    for (int i = 0; i < 8; i++)
    {
        cout << "Ingrese su nombre: ";
        cin >> ws; getline(cin, personas[i].nombre);

        cout << "Ingrese su dia de nacimiento: ";
        cin >> personas[i].fecha.dia;

        cout << "Ingrese su mes de nacimiento en numero: ";
        cin >> personas[i].fecha.mes;

        cout << "Ingrese su anio de nacimiento: ";
        cin >> personas[i].fecha.anio;
    }

    cout << "Ingrese cualquier numero de mes para ver los datos de una persona que cumpla ese mes: ";
    cin >> xmes;

    cout << "\n\tDATOS DE PERSONAS QUE CUMPLEN EN EL MES " << xmes << endl;
    for (int i = 0; i < 8; i++)
    {
        if (personas[i].fecha.mes == xmes)
        {
            cout << "PERSONA #" << i + 1 << endl;
            cout << "Nombre: " << personas[i].nombre << endl;
            cout << "Fecha de nacimiento: ";
            cout << personas[i].fecha.dia << "/" << personas[i].fecha.mes << "/" << personas[i].fecha.anio << '\n' << endl;
        }
    }
}