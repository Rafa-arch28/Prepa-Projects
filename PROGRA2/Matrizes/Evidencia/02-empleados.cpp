#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

const int COLUMNAS = 3; // 0. numero de empleado, 1. Nombre, 2. Curso y todo en strings

void inscribirse(string empleados[][COLUMNAS], int filas);
void imprimir_inscritos(string empleados[][COLUMNAS], int filas);

int main()
{
    const int MAXIMO_EMPLEADOS = 100;
    int num_empleados;

    cout << "Ingrese el numero de empleados que se inscribiran: ";
    cin >> num_empleados;

    string empleados[MAXIMO_EMPLEADOS][COLUMNAS];

    inscribirse(empleados, num_empleados);
    imprimir_inscritos(empleados, num_empleados);

    return 0;
}

void inscribirse(string empleados[][COLUMNAS], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        cout << "Empleado #" << i + 1 << endl;

        cout << "Ingrese su numero de empleado: ";
        cin >> empleados[i][0];

        cin.ignore();

        cout << "Ingrese su nombre: ";
        getline(cin, empleados[i][1]);

        cout << "Escriba el nombre del curso se quiere inscribir empleado (el nombre de curso)\n";
        cout << "ADMINISTRACION DE PROYECTOS\nLIDERAZGO\nCOMUNICACION ACERTIVA \n: ";
        getline(cin, empleados[i][2]);
    }
}

void imprimir_inscritos(string empleados[][COLUMNAS], int cantidad)
{
    int admp = 0;
    int lid = 0;
    int comacer = 0;

    for (int i = 0; i < cantidad; i++)
    {
        cout << endl << "EMPLEADO #" << i + 1 << endl;
        cout << "Numero de empleado: " << empleados[i][0] << endl;
        cout << "Nombre: " << empleados[i][1] << endl;
        cout << "Curso al que se inscribio: " << empleados[i][2] << endl;

        string texto = empleados[i][2];

        // LAMBDA PARA PASAR LOS STRINGS A MINUSCULAS
        transform(texto.begin(), texto.end(), texto.begin(), [](unsigned char c) {
            return tolower(c);
        });
        
        if (texto == "administracion de proyectos")
        {
            admp++;
        }
        else if (texto == "liderazgo")
        {
            lid++;
        }
        else if (texto == "comunicacion acertiva")
        {
            comacer++;
        }
        else
        {
            cout << "ESE CURSO NO EXISTEEEEEEEEE" << endl;
        }

        cout << endl;
    }

    cout << "CONTEO DE INSCRITOS " << endl << endl;

    cout << "Numero de inscritos en el taller de ADMON DE PROYECTOS: " << admp << endl;
    cout << "Numero de inscritos en el taller de LIDERAZGO: " << lid << endl;
    cout << "Numero de inscritos en el taller de COMUNICACION ACERTIVA: " << comacer << endl;
}

/*
Aqui me hubiera gustado usar STRUCTS pero pues todavia no lo vemos (tampoco vemos lambdas pero pues eso ya lo aprendi yo)
*/