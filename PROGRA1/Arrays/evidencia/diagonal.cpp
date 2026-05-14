/* 4. Escriba un programa para llenar una matriz de 5 x 5 y que este 
almacene la diagonal principal en un arreglo.
 */

#include <iostream>
#include <cstdlib> // es mi primera vez usando esta libreria, es para generar randoms
#include <ctime>  // esta es para generar una semilla que simepre sea distinta, habl mas de esto abajo
using namespace std;

int main() {

    srand(time(0)); //esta es la semilla

    int matriz[5][5];
    int arreglo_diagonal[5];

    // este for es para llenar la matriz con los numeros random
    for (int i = 0; i < 5; i++) {

        for (int k = 0; k < 5; k++) {

            matriz[i][k] =rand() % 100 + 1;

        }

    }

    cout << "MATRIZ ORIGINAL \n";
    // este como dice arriba es la matriz llena
    for (int i = 0; i < 5; i++) {

        for (int k = 0; k < 5; k++) {

            cout << matriz[i][k] << "\t";


        }

        cout << endl;

    }
    cout << "\n\n";
    cout << "DIAGONAL DE LA MATRIZ \n\n";

    // este for es mas para que se vea bonito aunque el ejercicio no lo pida
    for (int i = 0; i < 5; i++) {

        for (int k = 0; k < i; k++) {

            cout << "\t";

        }

        arreglo_diagonal[i] = matriz[i][i]; // aqui guardo la diagonal en el arreglo que pide el ejercicio
        cout << matriz[i][i] << endl;

    }

    return 0;
}

/* Este es el ejercicio creo yo con el que mas he aprendido de matrizes, siempre se ma ha complicado pero
ya se como manejarlas, usar la libreria cstdlib es un plus porque no queria llenar yo el arreglo jajaja 
pero pues ya me llevo algo nuevo. Aprendi a identificar filas y columnas y tambien como mostrarlas
a mi gusto. INTERESANTEEEEEEE fue que tenia que usar los segundos desde el 1 de enero de 1970, y que
si no no existirian los aleatorios en mi maquina.*/