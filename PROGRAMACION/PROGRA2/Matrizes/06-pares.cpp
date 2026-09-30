#include <iostream>
using namespace std;
int main()
{
    int pares[50];
    int c = 0;

    for (int i = 0; i < 50; i++)
    {
        c += 2;
        pares[i] = c;

        cout << pares[i] << endl;
    }
}