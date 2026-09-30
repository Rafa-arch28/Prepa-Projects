/*
4. Realiza un programa para obtener el promedio semestral de un grupo de “N” alumnos los cuales cursan 
5 materias este semestre, usando While.
*/

#include <iostream>
using namespace std;

int main() {

    int alumnos = 0;
    int contador = 0;

    double calificacion = 0;
    double suma_calificaciones = 0;
    double promedio_individual = 0;
    double promedio_grupal = 0;

    cout << "Ingrese el numero de alumnos en el grupo: " << endl;
    cin >> alumnos;

    while(contador < alumnos) {

        cout << "ALUMNO NUMERO: " << contador + 1 << endl;

        for (int k = 0; k < 5; k++) {

            cout << "Ingrese la calificacion numero " << k + 1 << ": ";
            cin >> calificacion;
            suma_calificaciones += calificacion;

        }

        cout << "\n";

        promedio_individual = suma_calificaciones / 5;
        promedio_grupal += promedio_individual;
        suma_calificaciones = 0;

        contador++;

    }

    promedio_grupal /= alumnos;

    cout << "El promedio grupal es de: " << promedio_grupal;

    return 0;
}

/*
Con este ejercicio aprendi mas de los bucles y que hay cosas que no son necesariamente necesarias (vaya la
rebundancia). En este ejercicio yo ya tenia contemplado usar un arreglo para guardar las calificacione porque
ya estoy acostumbrado a eso pero es que no es necesario porque no necesito esas calificaciones para nada 
despues asi que ya lo elimine. Lo del promedio ya lo sabia asi que de novedad fue que en vez de usar un menu
ahora uso solo while pidiendo antes el numero de alumnos y la verdad es mucho mas sencillo pero no 
necesariamente mas practico asi que todo bien :).
*/