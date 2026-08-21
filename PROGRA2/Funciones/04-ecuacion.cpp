#include <iostream>
#include <cmath>
using namespace std;

double cuadratica_p(double a, double b, double c);
double cuadratica_n(double a, double b, double c);
double v_discriminante(double a, double b, double c);

int main()
{
    double a = 0, b = 0, c = 0;
    double resultado_p = 0;
    double resultado_n = 0;

    cout << "Ingrese el termino a: "; cin >> a;
    cout << "Ingrese el termino b: "; cin >> b;
    cout << "Ingrese el termino c: "; cin >> c;

    resultado_p = cuadratica_p(a, b, c);
    resultado_n = cuadratica_n(a, b, c);

    if (resultado_p == 0 || resultado_n == 0)
    {
        cout << "No hay resultados reales" << endl;
    }
    else
    {
    cout << "EL resultado positivo es: " << resultado_p << endl;
    cout << "El resultado negativo es: " << resultado_n << endl;
    }

    return 0;
}

double v_discriminante(double a, double b, double c)
{
    double d = 0;
    d = sqrt((b*b) - (4 * (a * c)));

    if (d <= 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


double cuadratica_p(double a, double b, double c)
{
    double r = 0;
    bool v;
    v = v_discriminante(a,b,c);
    if (v == false)
    {
        return 0;
    }
    else
    {
        r = ((b * -1) + (sqrt((b*b) - (4 * (a * c))))) / (2 * a);
        return r;
    }
}

double cuadratica_n(double a, double b, double c)
{
    double r = 0;
    bool v;
    v = v_discriminante(a,b,c);
    if (!v)
    {
        return 0;
    }
    else
    {
        r = ((b * -1) - (sqrt((b*b) - (4 * (a * c))))) / (2 * a);
        return r;
    }
}
