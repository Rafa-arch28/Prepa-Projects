#include <iostream>
using namespace std;

double v_sueldo(double sueldo);

int main()
{   
    double sueldo;
    double nuevo_sueldo;

    cout << "Ingrese su sueldo: ";
    cin >> sueldo;
    
    nuevo_sueldo = v_sueldo(sueldo);
    cout << "Su nuevo sueldo es: " << nuevo_sueldo;

    return 0;
}

double v_sueldo(double sueldo)
{
    if (sueldo <= 1000)
    {
        cout << "Por su mal rendimiento, se le rebajo un 10%" << endl;
        return sueldo * 0.9;
    }
    else if (sueldo <= 2000)
    {
        cout << "Por su buen rendimiento, se le aumento un 5%" << endl;
        return sueldo * 1.05;
    }
    else
    {
        cout << "Por su excelente rendimiento, se le aumento un 3%" << endl;
        return sueldo * 1.03;
    }
}