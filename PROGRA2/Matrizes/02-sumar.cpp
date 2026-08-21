#include <iostream>
using namespace std;

int main() 
{

    int datos[2][3] = 
    {
        {5, 10, 15},
        {2,  4,  6}
    };

    int suma = 0;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            suma += datos[i][j];
        }
    }

    cout << "La suma de los datos de la matriz es de: " << suma << endl;

    return 0;
}