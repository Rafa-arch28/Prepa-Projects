/*
Escriba un programa que calcule el promedio de 5 materias para 20 alumnos
*/

#include <iostream>
using namespace std;

int main() {

    int alumnos = 20;
    int contador = 0;

    double suma_m1 = 0, suma_m2 = 0, suma_m3 = 0, suma_m4 = 0, suma_m5 = 0;
    double calificacion = 0;

    while (contador < alumnos) {

        cout << "ALUMNO: " << contador + 1 << endl;

        cout << "Ingrese la calificacion de la materia 1: " << endl;
        cin >> calificacion;
        suma_m1 += calificacion;

        cout << "Ingrese la calificacion de la materia 2: " << endl;
        cin >> calificacion;
        suma_m2 += calificacion;

        cout << "Ingrese la calificacion de la materia 3: " << endl;
        cin >> calificacion;
        suma_m3 += calificacion;

        cout << "Ingrese la calificacion de la materia 4: " << endl;
        cin >> calificacion;
        suma_m4 += calificacion;

        cout << "Ingrese la calificacion de la materia 5: " << endl;
        cin >> calificacion;
        suma_m5 += calificacion;

        cout << "\n";
        contador++;

    }
    
    cout << "PROMEDIOS POR MATERIA:" << endl;
    cout << "Materia 1: " << suma_m1 / alumnos << endl;
    cout << "Materia 2: " << suma_m2 / alumnos << endl;
    cout << "Materia 3: " << suma_m3 / alumnos << endl;
    cout << "Materia 4: " << suma_m4 / alumnos << endl;
    cout << "Materia 5: " << suma_m5 / alumnos << endl;

    return 0;
}

/*
Programa sencillito con la logica de guardar las calificaciones, no fue nada complicado y la verdad no tengo
mucho que decir jajaja. :)
*/