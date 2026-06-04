/*
Pide una receta. ingresa el numero de ingredientes e imprime el nombre de la receta y los ingredientes
*/

#include <iostream>
using namespace std;

int main() {

    string nombre;
    int cantidad;

    cout << "Ingrese el nombre de la receta: ";
    getline(cin, nombre);

    cout << "Ingrese la cantidad de ingredientes: ";
    cin >> cantidad; cout << endl;

    string ingredientes[cantidad];

    for (int k = 0; k < cantidad; k++) {
        cout << "Ingrese el ingrediente " << k + 1 << ": ";
        cin >> ingredientes[k]; cout << endl;
    }

    cout << "NOMBRE DE LA RECETA: " << nombre << endl;
    cout << "INGREDIENTES: " << endl;

    for (int k = 0; k < cantidad; k++) {
        cout << ingredientes[k] << endl;
    }

    return 0;
}