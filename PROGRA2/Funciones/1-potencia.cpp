#include <iostream>
using namespace std;

int cuadrado(int a)
{
    return a*a;
}

int main() 
{
    int in = 0;
    cout << "Ingrese el numero que quiere elevar al cuadrado: ";
    cin >> in;

    int resultado = cuadrado(in);

    cout << resultado;
    
    return 0;
}