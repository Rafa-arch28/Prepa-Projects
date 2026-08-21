#include <iostream>
#include <string>
using namespace std;

struct Alumno
{
    string nombre;
    int matricula;
    float calificaciones[3];
};

int main()
{

    Alumno alumnos[3];
    float promedios[3];
    float suma_calificaciones;
    float mayor;
    string alumno_mayor;
    int matricula;
    bool encontrado = false;

    for (int i = 0; i < 3; i++)
    {
        cout << "Ingrese el nombre del alumno: ";
        cin >> alumnos[i].nombre; cout << endl;

        cout << "Ingrese la matricula del alumno: ";
        cin >> alumnos[i].matricula; cout << endl;

        for (int j = 0; j < 3; j++)
        {
            cout << "Ingrese la calificacion #" << j + 1 << " del alumno: ";
            cin >> alumnos[i].calificaciones[j];
            suma_calificaciones += alumnos[i].calificaciones[j];
        }

        promedios[i] = suma_calificaciones / 3;
        suma_calificaciones = 0;
    }

    mayor = promedios[0];

    for (int i = 0; i < 3; i++)
    {
        if (promedios[i] >= mayor)
        {
            mayor = promedios[i];
            alumno_mayor = alumnos[i].nombre;
        }
    }

    cout << "El alumno con mayor promedio es: " << alumno_mayor << endl;

    cout << "Ingrese una matricula para buscarla entre los alumnos: ";
    cin >> matricula;

    
    for (int i = 0; i < 3; i++)
    {
        if (alumnos[i].matricula == matricula)
        {
            cout << "Alumno encontrado: " << endl;
            cout << alumnos[i].nombre << "\n" << alumnos[i].matricula << "\n";
            for (int j = 0; j < 3; j++)
            {
                cout << "calificacione #" << i + 1 << alumnos[i].calificaciones[j] << endl;
            }
            encontrado = true;
            break;
        }
    }
    if (!encontrado)
    {
        cout << "No lo encontramos "; encontrado = false;
    }

    return 0;
}