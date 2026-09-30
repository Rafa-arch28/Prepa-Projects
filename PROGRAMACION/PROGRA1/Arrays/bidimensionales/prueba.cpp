#include <iostream>
using namespace std;
int main() {

    int arreglo[10][3];

    for (int k = 0; k <= 9; k++){
        cout << "Vuelta " << k + 1 << ": \n";
        for (int p = 0; p<= 2; p++){
            cin >> arreglo[k][p];
        }
    }

    for (int k = 0; k <= 9; k++){
        for (int p = 0; p<= 2; p++){
            cout << arreglo[k][p] << endl;
        }
    }

    return 0;
}