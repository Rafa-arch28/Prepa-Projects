/* Realice un programa que imprima las tablas del 1 al 10 usando FOR */

/* Principalmente aprendi a simplificar todo con un segundo loop,
 al principio pense en hacerlo poniendo pues cada tabla pero me di cuenta
 que era muuchisimo mas facil si usaba un segundo bucle, al principio tuve 
 errores porque usaba el array tablas[] en el segundo bucle pero era sin el
 asi que todo bien :) */

#include <iostream>
using namespace std;

int main() {

    int tablas[] = {0,1,2,3,4,5,6,7,8,9,10};

    for (int i = 0; i <= 10; i++) {

        cout << "Tabla del " << tablas[i] << ":" << endl;
        
        for (int e = 0; e <= 10; e++) {

            cout << i * e << endl;

        }

    }

    return 0;
}