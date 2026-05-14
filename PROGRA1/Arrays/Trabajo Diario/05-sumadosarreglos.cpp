#include <iostream>
using namespace std;

int main() {

    int tamano = 0;

    do {
        cout << "Ingrese el tamano de los arreglos (del 1 al 10): ";
        cin >> tamano;
    } while (tamano < 1 || tamano > 10);

    int arreglo1[tamano], arreglo2[tamano], suma[tamano];

    cout << "\nDatos del Arreglo 1:" << endl;
    for(int i = 0; i < tamano; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> arreglo1[i];
    }

    cout << "\nDatos del Arreglo B:" << endl;
    for(int i = 0; i < tamano; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> arreglo2[i];
    }

    cout << "\nLa suma de los arreglos es:" << endl;
    for(int i = 0; i < tamano; i++) {
        suma[i] = arreglo1[i] + arreglo2[i];
        cout << arreglo1[i] << " + " << arreglo2[i] << " = " << suma[i] << endl;
    }
    
    return 0;
}