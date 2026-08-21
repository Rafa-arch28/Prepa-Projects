#include <iostream>
using namespace std;

int main()
{

    int matriz[2][2];
    int dato;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "Ingrese el numero en " << i << "," << j << ": ";
            cin >> dato;
            matriz[i][j] = dato;
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << matriz[i][j];
            cout << " ";
        }
        cout << endl;
    }
    

    return 0;
}