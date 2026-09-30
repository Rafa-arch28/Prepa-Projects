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