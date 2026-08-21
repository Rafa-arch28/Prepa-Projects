#include <iostream>
using namespace std;

int main()
{

    int mapa[3][3] = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int b;

    cout << "Ingrese el numero a buscar de la matriz: ";
    cin >> b;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (mapa[i][j] == b)
            {
                cout << "Encontrado en la posicion: " << i + 1 << "," << j + 1 << endl;
                return 0;
            }
        }
    }

    return 0;
}