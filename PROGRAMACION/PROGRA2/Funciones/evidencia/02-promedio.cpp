#include <iostream>
using namespace std;

void v_notas(float nota1, float nota2, float nota3);

int main()
{

    float nota1 = 0;
    float nota2 = 0;
    float nota3 = 0;

    cout << "Ingrese la calificacion 1: "; cin >> nota1;
    cout << "Ingrese la calificacion 2: "; cin >> nota2;
    cout << "Ingrese la calificacion 3: "; cin >> nota3;

    v_notas(nota1, nota2, nota3);

    return 0;
}

void v_notas(float nota1, float nota2, float nota3)
{
    float promedio = (nota1 + nota2 + nota3) / 3;

    if (promedio > 7)
    {
        cout << "APROBADO" << endl;
    }
    else
    {
        cout << "MEJORE LA NOTA" << endl;
    }
}