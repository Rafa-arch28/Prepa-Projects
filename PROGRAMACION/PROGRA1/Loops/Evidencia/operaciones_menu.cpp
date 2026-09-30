/* Realiza un algoritmo que muestre en pantalla un menú de opciones como el siguiente:
1.Suma.
2.Resta.
3.Multiplicación.
4.División.
5.Salir.
Cada opción del menú debe realizar la operación indicada, 
además de que se debe repetir hasta que el usuario lo indique
pues debe preguntar si desea continuar después de ejecutar cada opción. */

/* Este programa estaba facil pero tuve un problema, al principio pedia los numeros
fuera del switch pero cuando el usuario deseaba salir seguia pidiendo numeros. Mi primera
solucion fue meter pedir los numeros en cada case pero se me hizo demasiado repetitivo,
entonces mejor puse un condicional para evaluar la opcion seleccionada pera evitar ser 
repetitivo, aprendi mucho a dejar de hacer eso porque solo hace el codigo menos fluido :) */

#include <iostream>
using namespace std;

int main() {

    double num1 = 0;
    double num2 = 0;
    double resultado = 0;
    int opcion = 0;

    do {

        cout << "Seleccione la opcion del menu: " << endl;
        cout << "1. Suma" << endl;
        cout << "2. Resta" << endl;
        cout << "3. Multiplicacion" << endl;
        cout << "4. Division" << endl;
        cout << "5. Salir" << endl;
        cin >> opcion;

        if (opcion >= 1 && opcion <= 4) {
            cout << "Ingrese el primer numero: " << endl;
            cin >> num1;
            cout << "Ingrese el segundo numero: " << endl;
            cin >> num2;
        }

        switch (opcion) {

            case 1:
                resultado = num1 + num2;
                cout << "Operacion Seleccionada: Suma" << endl;
                cout << "Resultado: " << resultado << endl;
                break;

            case 2:
                resultado = num1 - num2;
                cout << "Operacion Seleccionada: Resta" << endl;
                cout << "Resultado: " << resultado << endl;
                break;

            case 3:
                resultado = num1 * num2;
                cout << "Operacion Seleccionada: Multiplicacion" << endl;
                cout << "Resultado: " << resultado << endl;
                break;

            case 4:
                resultado = num1 / num2;
                cout << "Operacion Seleccionada: Division" << endl;
                cout << "Resultado: " << resultado << endl;
                break;
            case 5:
                cout << "Saliendo del programa" << endl;
                break;
            default:
                cout << "La opcion no esta en el menu, intentelo de nuevo"<<endl;

        }

    } while (opcion != 5);

    return 0;
}