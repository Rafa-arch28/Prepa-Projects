/* 3. Escribir un programa que lea un arreglo de 10 elementos y lo llene, 
después debe buscar un número en dicho arreglo e indicar su posición(es), utilice una bandera.
 */

#include <iostream>
using namespace std;

int main() {

    double arreglo[10];
    // me gusto tener bonito el arreglo y sin investigar ni nada descubri que puede haber arreglos de strings
    string posicion[] = {"primer","segundo","tercero","cuarto","quinto","sexto", 
    "septimo", "octavo", "noveno", "decimo"};
    
    // el ejercicio pedia una bandera y crei que era como los punteros pero es un simple bool
    double numero_para_encontrar = 0;
    bool encontrado = false;

    for (int i = 0; i < 10; i++) {

        cout << "Ingrese el " << posicion[i] << " numero: ";
        cin >> arreglo[i];

    }

    // aqui la validacion, la verdad muy facil solo que no sabia si el if iba adentro a afuera del for
    cout << "Ingrese el numero que quiere encontrar: ";
    cin >> numero_para_encontrar;

    for (int i = 0; i < 10; i++) {

        if (numero_para_encontrar == arreglo[i]) {
            // aqui antes de usar la bandera usaba un break entonces solo encontraba la primera posicion
            cout << "Numero encontrado en el indice: " << i << " posicion: " << i + 1 << endl;
            encontrado = true;

        }

    }

    // es en caso de error, el not voltea el valor del encontrado
    if (not encontrado) {

        cout << "El numero no se encuentra en el arreglo" << endl;
        
    }

    return 0;
}

/* Un ejercicio sencillo pero divertido, la verdad no hay mucho que comentar pero descubri
lo de las banderas con los booleans y el uso que tienen con and, or y not. Ademas de eso el uso
de strings dentro de los arreglos es interesante y muy util la verdad.

Lo de las banderas como los punteros, crei que era un simbolo raro pero no son solo booleans, 
desconozco si se pueden hacer banderas con otros tipos de datos pero eso lo dejare para futuros ejercicios.*/