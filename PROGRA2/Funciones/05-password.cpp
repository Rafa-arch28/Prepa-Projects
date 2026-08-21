#include <iostream>
using namespace std;

string CONTRA = "hola123";
string USR_P = "rafa";

bool validacion (string usuario, string contrasena);

int main()
{

    bool v;
    string contrasena;
    string usr;

    cout << "Ingrese su nombre de usuario: ";
    cin >> usr;

    cout << "Ingrese la contrasena: ";
    cin >> contrasena;

    v = validacion(usr, contrasena);

    if (!v)
    {
        cout << "Acceso denegado" << endl;
    }
    else
    {
        cout << "Acceso concedido" << endl;
    }

    return 0;
}

bool validacion (string usuario, string contrasena)
{
    if (usuario == USR_P and contrasena == CONTRA)
    {
        return true;
    }
    else
    {
        return false;
    }
}