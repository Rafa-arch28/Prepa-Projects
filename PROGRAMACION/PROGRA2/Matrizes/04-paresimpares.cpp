#include <iostream>
using namespace std;
int main()
{

    int a[3][2];
    int pares = 0;
    int impares = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "Ingrese el numero de la posicion " << i << "," << j << ": ";
            cin >> a[i][j];

            if (a[i][j] % 2 == 0)
            {
                pares++;
            }
            else
            {
                impares++;
            }
        }
    }

    cout << "Los pares son: " << pares << endl;
    cout << "Los impares son: " << impares << endl;

    return 0;
}