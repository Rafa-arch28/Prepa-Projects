#include <iostream>
using namespace std;

void tabla(int a);

int main()
{
    int numero = 0;
    cout << "Ingrese un numero: ";
    cin >> numero;

    tabla(numero);

    return 0;
}

void tabla(int a)
{
    for (int i = 1; i <= 10; i++)
    {
        cout << a  << " * " << i  << " = " << a * i << endl;
    }
}