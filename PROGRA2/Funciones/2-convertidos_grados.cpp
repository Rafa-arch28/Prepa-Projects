#include <iostream>
using namespace std;

float convertir_grados(float grados); 
// este es un aviso al compilador para declarar la funcion antes, abajo del main escribes el codigo de la funcion
// Si escribes una funcion asi nadamas abajo del main no la va a leer :)

int main() 
{
    float grados;
    cout << "Ingrese los grados celisus para convertirlos a fahrenheit: ";
    cin >> grados;

    float fahrenheit = convertir_grados(grados);

    cout << "Los fahrenheit son: " << fahrenheit << endl;

    return 0;
}

float convertir_grados(float grados)
{
    return (grados * 1.8) + 32;
}