#include <iostream>
using namespace std;

struct Registro
{
    int edad;
    int estatura;
    float peso;
};

int main()
{
    Registro rafa;

    cout << "Ingrese su edad: ";
    cin >> rafa.edad;

    cout << "Ingrese su estatura (CM): ";
    cin >> rafa.estatura;

    cout << "Ingrese su peso (KG): ";
    cin >> rafa.peso;

    cout << "Edad: " << rafa.edad << "\nEstatura: " << rafa.estatura << "cm \nPeso: " << rafa.peso << "Kg\n";

    return 0;
}