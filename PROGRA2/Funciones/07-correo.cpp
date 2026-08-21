#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string DOMINIO = "@uanl.edu.mx";

string generar_correo(string nombre, string a1, string a2);

int main()
{
    
    string nombre;
    string a1;
    string a2;
    string correo;

    cout << "Ingrese el nombre: ";
    getline(cin, nombre);

    cout << "Ingrese su appelido materno: ";
    getline(cin, a1);

    cout << "Ingrese su apellido paterno: ";
    getline(cin, a2);

    correo = generar_correo(nombre, a1, a2);

    cout << correo;

    return 0;
}

string generar_correo(string nombre, string a1, string a2)
{
    string a1p = a1.substr(0,1);
    string a2p = a2.substr(0,1);

    string correo = nombre + a1p + a2p + DOMINIO;

    transform(
        correo.begin(), // Valor donde empieza a leer
        correo.end(), // Valor donde va a terminar de leer
        correo.begin(), // Valor donde empieza a GUARDAR los resultados
        [](unsigned char c) {return tolower(c);} // LAMBDA para cambiar cada char
    );

    // Estructura de una funcion LAMBDA: [variables que hereda del codigo CAPTURA](PARAMETROS){codigo con su return}

    return correo;
}