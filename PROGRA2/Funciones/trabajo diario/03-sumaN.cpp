#include <iostream>
using namespace std;

int suma_digitos(int a, int digitos);

int main()
{
    int numero = 0;
    int digitos = 0;
    int resultado = 0;

    cout << "De cuantos digitos es su numero: ";
    cin >> digitos;

    cout << "Ingrese su numero: ";
    cin >> numero;

    resultado = suma_digitos(numero, digitos);

    cout << "El resultado es: " << resultado;

    return 0;
}

int suma_digitos(int a, int digitos)
{
    bool bandera = true;
    int ultimo = 0;
    int suma = 0;

    if (digitos > 2)
    {
        while (a != 0)
        {
            ultimo = a % 10;
            suma += ultimo;
            a /= 10;
        }
    }
    else
    {
        suma = (a / 10) + (a % 10);
    }
    return suma;
}