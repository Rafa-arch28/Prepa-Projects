#include <iostream>
using namespace std;

int main() {

    int arreglo[5];
    int suma = 0;

    for (int k = 0; k <= 4; k++) {
        cout << "Ingrese un numero entero: ";
        cin >> arreglo[k];
        suma += arreglo[k];
    }

    cout << "La suma es: " << suma << endl;

    return 0;
}