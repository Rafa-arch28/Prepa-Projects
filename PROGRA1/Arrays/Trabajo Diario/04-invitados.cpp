#include <iostream>
using namespace std;

int main() {

    string arreglo[5];


    for (int k = 0; k <= 4; k++) {
        cout << "Ingrese el nombre del invitado " << k + 1 << ": ";
        cin >> arreglo[k];
    }

    cout << "La lista de invitados: " << endl;

    for (int k = 0; k <= 4; k++) {
        cout << arreglo[k] << endl;
    }

    return 0;
}