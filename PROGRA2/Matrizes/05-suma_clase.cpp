#include <iostream>
using namespace std;

int main()
{
    int a[3][2];
    int suma = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "Ingrese el numero en la posicion " << i << "," << j << ": " << endl;
            cin >> a[i][j];
            
            suma += a[i][j];
        }
    }

    cout << "La suma de los numeros de los arreglos es de: " << suma;

    return 0;
}

