#include <iostream>
#include <string>
using namespace std;

int main()
{
    string cadena;
    char caracter;

    cout << "Ingresa una cadena: ";
    getline(cin, cadena);

    cout << "Ingresa un caracter: ";
    cin >> caracter;

    int contador = 0;
    size_t pos = cadena.find(caracter); // size_t es un tipo de dato entero, pero que no acepta megativos

    // EL while solo inicia si sis encontro algo
    while (pos != string::npos) // npos es una cosa de string, es como decir, hay algo en la posicion? si pos no tiene nada, pues no hace nada
    {
        contador++;
        pos = cadena.find(caracter, pos + 1); // Aqui agrego la posicion, el while evalua si hay algo en la posiicon, si no solo sale
    }

    cout << "El caracter '" << caracter << "' aparece " << contador << " veces." << endl;

    return 0;
}