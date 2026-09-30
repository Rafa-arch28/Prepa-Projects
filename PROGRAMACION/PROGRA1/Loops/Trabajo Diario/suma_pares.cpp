/*
Programa que calcula la suma de los Números Impares comprendidos entre el 10 y el 50, utilizando mod (%).
*/

#include <iostream>
using namespace std;

int main() {

    int suma = 0;

    for (int i = 10; i <= 50; i++) {
        if (i % 2 != 0) {
            suma += i;
        }
    }

    cout << "La suma es: " << suma;

    return 0;
}

/*
De lo mas sencillo del mundo jaja, sin mucho que decir, solo que ya se mas jajaja
*/