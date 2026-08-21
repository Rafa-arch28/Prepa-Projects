#include <iostream>
#include <string>
using namespace std;

string caracter(string cadena);

int main()
{
    string cadena;

    cout << "Ingrese una cadena de texto: ";
    getline(cin, cadena);

    cout << "El primer caracter de la cadena es: " << caracter(cadena);

    return 0;
}

string caracter(string cadena)
{
    string s = cadena.substr(0, 1);
    return s;
}