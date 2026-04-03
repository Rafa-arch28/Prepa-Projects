/* Crear un arreglo de “n” posiciones en el cual el usuario introduzca 
los números que desee y realice la suma de los mismos.
Al finalizar en pantalla se deberá de mostrar: 
La cantidad de elementos en el arreglo.
Los elementos del arreglo.
La suma de todos los elementos. */

 #include <iostream>
 using namespace std;

 int main() {

    double suma = 0;
    int tamano_arreglo;

    cout << "Ingrese el tamano de su arreglo: ";
    cin >> tamano_arreglo;

    double arreglo[tamano_arreglo];

    for (int i = 0; i < tamano_arreglo; i++) {

        cout << "Ingrese el numero en la posicion " << i + 1 << ": " << endl;
        cin >> arreglo[i];

        suma += arreglo[i];

    }
    
    cout << "Los elementos del arreglo son: " << endl;

    for (int i = 0; i < tamano_arreglo; i++) {

        cout << arreglo[i] << endl;

    }

    cout << "La suma de los elementos del arreglo es: " << suma << endl;
    cout << "La cantidad de elementos del arreglo es: " << tamano_arreglo << endl;

    return 0;
 }

 /* Es mi primera vez con arreglos y tuve muchos errores con el for porque se me olvido la condicion,
 primero pedi 3 numeros si ponias de tamano 2 pero lo corregi cambiando la condicion de: i <= tamano_arreglo
 a i < tamano_arreglo. Ademas de eso todo bien y creo que ya le estoy entendiendo, es interesante 
 aprender de esto porque creo que los arreglos es lo que se usa en ciencia de datos asi que quiero aprender
 mucho mas de este tema, tambien aprendi a que se pueden hacer arreglos con un tamano no especificado, creo
 que no es la mejor forma de hacerlo pero lo resolvi bien asi que todo bien :)*/