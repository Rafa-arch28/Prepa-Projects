#include <iostream>
using namespace std;

int main() {

    int alumnos = 20;
    int contador = 0;

    double calificacion = 0;
    double suma_calificaciones = 0;
    double promedio_individual = 0;
    double promedio_grupal = 0;

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
Siendo totalmente honesto... solo copie y pegue del programa de la evidencia solo cambiando la variable
de alumnos a 20 ajjaaj asi que esta bien facil pero ya entiendo la logica asi que sin problema... :)
*/