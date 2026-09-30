/*
Escriba un programa que calcule el promedio de 5 materias para 20 alumnos y ademas envie el promedio grupal
*/

#include <iostream>
using namespace std;

int main() {

    int alumnos = 20;
    int contador = 0;

    double calificacion = 0;
    double suma_calificaciones = 0;
    double promedio_individual = 0;
    double promedio_grupal = 0;

    // variables para ir guardando la suma de cada calificacion de cada materia
    double m1 = 0, m2 = 0, m3 = 0, m4 = 0, m5 = 0;

    while(contador < alumnos) {

        cout << "ALUMNO NUMERO: " << contador + 1 << endl;
        
        // simplifique muucho con este for jajaja 
        for (int k = 0; k < 5; k++) {

            cout << "Ingrese la calificacion numero " << k + 1 << ": ";
            cin >> calificacion;
            suma_calificaciones += calificacion;
            // uso if separados para evaluar cada una de las opciones
            if (k == 0) {m1 += calificacion;}
            if (k == 1) {m2 += calificacion;}
            if (k == 2) {m3 += calificacion;}
            if (k == 3) {m4 += calificacion;}
            if (k == 4) {m5 += calificacion;}

        }

        cout << "\n";

        promedio_individual = suma_calificaciones / 5;
        promedio_grupal += promedio_individual;
        suma_calificaciones = 0;

        contador++;

    }

    promedio_grupal /= alumnos;

    cout << "PROMEDIO GRUPAL: " << endl;
    cout << "El promedio grupal es de: " << promedio_grupal << "\n\n";

    cout << "PROMEDIOS POR MATERIA:" << endl;
    cout << "Materia 1: " << m1 / alumnos << endl;
    cout << "Materia 2: " << m2 / alumnos << endl;
    cout << "Materia 3: " << m3 / alumnos << endl;
    cout << "Materia 4: " << m4 / alumnos << endl;
    cout << "Materia 5: " << m5 / alumnos << endl;

    return 0;
}

/* 
Siendo totalmente honesto... solo copie y pegue del programa de la evidencia solo cambiando la variable
de alumnos a 20 y agregue la logica del problema pero sin el promedio grupal ajjaaj asi que esta bien facil 
pero ya entiendo la logica asi que sin problema... :)
*/