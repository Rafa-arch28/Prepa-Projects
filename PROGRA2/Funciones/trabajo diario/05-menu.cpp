#include <iostream>
#include <cmath>
using namespace std;

float area_t(float base, float altura);
float area_rombo(float d_mayor, float _menor);
float volumen_cubo(float lado);

int main()
{
    float base = 0;
    float altura = 0;

    float d1 = 0;
    float d2 = 0;

    float lado = 0;

    int opc = 0;

    cout << "Ingrese la opcion del menu que desee: \n1. Calcular area de triangulo Equilatero \n2. Calcular area de un rombo \n3. Calcular volumen de un cubo \n: ";
    cin >> opc;

    switch (opc)
    {
    case 1:
    {
        cout << "Ingrese la base del triangulo: ";
        cin >> base;
        cout << "Ingrese la altura del triangulo: ";
        cin >> altura;

        float resultado = area_t(base, altura);

        cout << "El area es: " << resultado;
        break;
    }
    case 2:
    {
        cout << "Ingrese la diaginal mayor: ";
        cin >> d1;
        cout << "Ingrese la diagonal menor: ";
        cin >> d2;

        float resultado = area_rombo(d1, d2);

        cout << "El area del rombo es: " << resultado;
        break;
    }
    case 3:
    {
        cout << "Ingrese el lado del cuadrado: ";
        cin >> lado;

        float resultado = volumen_cubo(lado);

        cout << "El volumen del cubo es: " << resultado;
        break;
    }
    default:
    {
        cout << "Esa opcion no esta, vete!!";
    }
    }

    return 0;
}

float area_t(float base, float altura)
{
    return (base * altura) / 2;
}

float area_rombo(float d_mayor, float d_menor)
{
    return (d_mayor * d_menor) / 2;
}

float volumen_cubo(float lado)
{
    return pow(lado, 3);
}