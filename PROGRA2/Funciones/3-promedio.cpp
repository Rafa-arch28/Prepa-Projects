#include <iostream>
using namespace std;

float promedio(float c1, float c2, float c3);

int main()
{
    float prom = 0;
    float c1 = 0, c2 = 0, c3 = 0;

    cout << "Ingresa la calificacion de tu examen 1: "; cin >> c1;
    cout << "Ingresa la calificacion de tu examen 2: "; cin >> c2;
    cout << "Ingresa la calificacion de tu examen 3: "; cin >> c3;

    prom = promedio(c1, c2, c3);

    cout << "EL promedio es: " << prom;

    return 0;
}

float promedio(float c1, float c2, float c3)
{
    float prom = 0;
    return prom = (c1 + c2 + c3) / 3;
}
