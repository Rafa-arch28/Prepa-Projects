#include <iostream>
using namespace std;

int main() {

    int arreglo[5];

    for (int k = 0; k <= 4; k++) {
        cout << "Ingrese un numero entero: ";
        cin >> arreglo[k];
    }

    for (int k = 0; k <= 4; k++) {
        cout << arreglo[k] << endl;
    }

    return 0;
}