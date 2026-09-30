#include <iostream>
using namespace std;

int main() {

    for (int k = 0; k < 500; k++) {
        cout << (k + 1) * 2 << endl;
    }
    
    /* int acumulador = 0;
    while (acumulador < 500) {
        cout << (acumulador + 1) * 2 << endl;
        acumulador++;
    } */

    /* int acumulador = 0;
    do {
        cout << (acumulador + 1) * 2 << endl;
        acumulador++;
    } while (acumulador < 500); */
    
    return 0;
}

/*
Lo mismo que el de la serie del 1 al 100 solo que con la diferencia de que ahora se multiplica por dos,
al principio intente modificar la estructura del for para que en vez de que aumentara de 1 en 1 fuera de 
2 en 2 pero no pude hacerlo porque me imprimia puros 1 jajjaja asi que lo deje de la forma mas compleja 
que es hacer la division y solo multiplicar por dos manteniendo el (k + 1) para que vaya en pares :)
*/