#include <iostream>
using namespace std;

int funcion(int &n, int &m);

int main()
{
    int a = 10;
    int b = 20;
    
    funcion(a,b);

    cout << a << " , " << b;

    return 0;
}

int funcion(int &n, int &m)
{
    n = n + 5;
    m = m + 5;

    return n + m;
}