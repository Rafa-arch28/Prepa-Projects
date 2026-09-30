#include <iostream>
using namespace std;

string verificar_edad(int edad)
{
    if (edad >= 18)
    {
        return "Usted es mayor de edad";
    }
    else
    {
        return "Usted no es mayor de edad";
    }
}

int main() 
{
    int edad;
    cout << "Ingrese su edad: ";
    cin >> edad;

    string resultado = verificar_edad(edad);

    cout << resultado << endl;
}