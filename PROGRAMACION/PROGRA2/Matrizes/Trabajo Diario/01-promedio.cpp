#include <iostream>
using namespace std;

int main()
{
    float numeros[10];
    float prom = 0;


    for (int i = 0; i < 10; i++)
    {
        cout << "Ingrese el numero: "; cin >> numeros[i];
        prom += numeros[i];
    }
    prom /= 10;

    cout << "EL promedio es: " << prom;
    
    return 0;
}