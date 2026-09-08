#include <iostream>
using namespace std;

int main()
{


    int matriculas[5];
    float califs[5][3];

    for (int i = 0; i < 5; i++)
    {
        cout << "Ingrese la matricula del alumno " << i + 1 << ": ";
        cin >> matriculas[i];

        for (int j = 0; j < 3; j++)
        {
            cout << "Ingrese la calificacion " << j + 1 << " del alumno: ";
            cin >> califs[i][j];
        }
    }

    for (int i = 0; i < 5; i++)
    {
        cout << "Matricula del alumno " << i + 1 << ": " << matriculas[i] << endl;

        for (int j = 0; j < 3; j++)
        {
            cout << "Califiacion " << j + 1 << ": "<< califs[i][j] << endl;
        }
    }

    return 0;
}