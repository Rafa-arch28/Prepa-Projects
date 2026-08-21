#include <iostream>
using namespace std;

float pago(int horas, float sueldo);

int main()
{
    int horas;
    float sueldo;
    float resultado;

    cout << "Ingrese las horas que trabajo: ";
    cin >> horas;

    cout << "Ingrese el precio por hora: ";
    cin >> sueldo;

    resultado = pago(horas, sueldo);

    cout << "Su paga por las horas trabjadas es: " << resultado;
    
    return 0;
}

float pago(int horas, float sueldo)
{
    return horas * sueldo;
}