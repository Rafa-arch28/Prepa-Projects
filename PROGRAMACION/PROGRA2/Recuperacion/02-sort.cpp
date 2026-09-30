#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    int a[6];

    for (int i = 0; i < 6; i++)
    {
        cout << "Ingrese un numero: ";
        cin >> a[i];
    }

    sort(a, a + 6);
    int repetidos = 0;

    for (int i = 0; i < 6; i++)
    {   
        if (a[i] == a[i - 1])
        {
            repetidos++;
        }
    }
    cout << repetidos;

    return 0;
}