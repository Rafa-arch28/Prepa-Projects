#include <iostream>
using namespace std;

int main() {

    int arreglo[5];

    for (int k = 0; k <= 4; k++) {
        arreglo[k] = 0;
    }

    for (int k = 0; k <= 4; k++) {
        cout << arreglo[k] << endl;
    }
    
    return 0;
}