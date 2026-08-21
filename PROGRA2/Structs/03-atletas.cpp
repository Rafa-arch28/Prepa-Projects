#include <iostream>
#include <string>
using namespace std;

struct Atleta
{
    string nombre;
    string deporte;
    int puntos;
};

int main()
{

    Atleta atletas[4];

    for (int i = 0; i < 4; i++)
    {
        cout << "ATLETA #" << i + 1 << endl;

        cout << "Ingrese el nombre: ";
        cin >> atletas[i].nombre; cout << endl;

        cout << "Ingrese el deporte: ";
        cin >> atletas[i].deporte; cout << endl;
        
        cout << "Ingrese los puntos que gano: ";
        cin >> atletas[i].puntos; cout << endl;
    }

    Atleta temporal;

    for (int i = 0; i < 4; i++)
    {
        if (atletas[i].puntos < atletas[i + 1].puntos)
        {
            temporal = atletas[i];
            atletas[i] = atletas[i + 1];
            atletas[i + 1] = temporal;
        }
    }

    cout << "REPORTE FINAL DE ATLETAS (ORDENADO)" << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << atletas[i].nombre << " | Puntuacion: " << atletas[i].puntos << endl;
    }

    return 0;
}