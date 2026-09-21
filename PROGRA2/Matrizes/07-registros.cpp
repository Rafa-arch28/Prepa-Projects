#include <iostream>
using namespace std;
int main()
{

    int registros[10][2];
    int aula = 0, grupo = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 0)
            {
                cout << "Ingrese el grupo del alumno " << i + 1 << ": ";
                cin >> registros[i][j];
            }
            else
            {
                cout << "Ingrese el aula del alumno " << i + 1 << ": ";
                cin >> registros[i][j];
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        cout << endl << "ALUMNO " << i + 1 << endl;
        for (int j = 0; j < 2; j++)
        {
            if (j == 0)
            {
                cout << "el grupo del alumno " << i + 1 << ": ";
                cout << registros[i][j] << endl;
            }
            else
            {
                cout << "el aula del alumno " << i + 1 << ": ";
                cout << registros[i][j] << endl;
            }
        }
    }

// hola es para probar el github
    return 0;
}