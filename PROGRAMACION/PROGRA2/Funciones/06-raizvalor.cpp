#include <iostream>
#include <cmath>
using namespace std;

double raiz(float a, float b);
double valor_absoluto(float a, float b);

int main()
{
    double a = 0;
    double b = 0;

    cout << "Ingrese el valor de a: ";
    cin >> a;

    cout << "Ingrese el valor de b: ";
    cin >> b;

    double src = raiz(a, b);
    double sva = valor_absoluto(a, b);

    cout << "Suma de raizes cuadradas: " << src << endl;
    cout << "Suma de valores absolutos: " << sva << endl;

    return 0;
}

double raiz(float a, float b)
{
    float x = 0;
    double y = 0;

    x = a + b;

    y = sqrt(x);

    return y;
}

double valor_absoluto(float a, float b)
{
    float x;
    double y;

    x = a + b;
    
    y = fabs(x);

    return y;
}