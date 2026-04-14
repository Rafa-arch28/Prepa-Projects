/*
1. Desarrolle un programa que calcule el promedio general de una materia de cada estudiante, 
con base en 5 calificaciones parciales.
Al calcular el promedio, deberá imprimirse por cada estudiante si el estudiante "Aprobó" o "Reprobó" 
según su promedio. Un estudiante aprueba si su calificación es mayor o igual a 70. Este proceso se ejecutará, 
cada vez que el usuario seleccione la Opción 1 del menú.
El programa solo finalizará cuando el usuario así lo determine, para saberlo, se controlará por medio de 
un menú de DOS OPCIONES:

1.- Capturar calificaciones de un estudiante

2.- Salir

Al finalizar, el programa deberá imprimir un reporte FINAL con los siguientes datos:

a) Promedio General del Grupo

b) Alumnos Aprobados

c) Alumnos Reprobados

d) Porcentaje de Alumnos Aprobados

e) Porcentaje de Alumnos Reprobados

f) Total de Estudiantes 
*/

#include <iostream>
using namespace std;

int main() {

    double promedio_grupo = 0;

    int alumnos_aprobados = 0;
    int alumnos_reprobados = 0;

    double porcentaje_aprobados = 0;
    double porcentaje_reprobados = 0;

    int total_estudiantes = 0;

    double promedio_individual = 0;

    int opc;

    double calificaciones[5];
    double suma_calificaciones = 0;

    do {

        cout << "Ingrese la opcion del menu que desee: " << endl;
        cout << "1. Capturar calificacion de un alumno \n2. Salir\n";
        cin >> opc;
        
        switch (opc) {

            case 1: {
                total_estudiantes += 1;

                for (int k = 0; k < 5; k++){
                    cout << "Ingrese la calificacion " << k + 1 << ":\n";
                    cin >> calificaciones[k];
                    suma_calificaciones += calificaciones[k];
                }

                promedio_individual = suma_calificaciones / 5;

                if (promedio_individual >= 70) {
                    cout << "Aprobado\n";
                    alumnos_aprobados += 1;
                } else {
                    cout << "Reprobado\n";
                    alumnos_reprobados += 1;
                }
                suma_calificaciones = 0;
                promedio_grupo += promedio_individual;
                break;
            }
            case 2: {
                if (total_estudiantes > 0) {
                    promedio_grupo /= total_estudiantes;
                    porcentaje_aprobados = (alumnos_aprobados * 100.0) / total_estudiantes; // esta es la formula para sacar el porcentaje, esta si tengo que recordarla
                    porcentaje_reprobados = (alumnos_reprobados * 100.0) / total_estudiantes; // tengo que recordar que esta es una regla de tres

                    cout << "Imprimiendo Reporte Final: \n";
                    cout << "Promedio General del grupo: " << promedio_grupo << endl;
                    cout << "Alumnos aprobados: " << alumnos_aprobados << endl;
                    cout << "Alumnos reprobados: " << alumnos_reprobados << endl;
                    cout << "Porcentaje de aprobados: " << porcentaje_aprobados << "%" << endl;
                    cout << "Porcentaje de reprobados: " << porcentaje_reprobados << "%" << endl;
                    cout << "Total de Alumnos en el grupo: " << total_estudiantes;
                } else {
                    cout << "No hay alumnos en el grupo, adios :)";
                }
                break;
            }
        }

    } while (opc != 2);

    return 0;
}

/*
Este es otro ejercicio parecido a uno que hice en los arrays con la diferencia de que en este no tenia que
mostrar las calificaciones aunque aun asi se me hizo mucho mas facil guardarlas en un array para facilitar
el proceso de recolectarlas y es mas facil de entender.

Siempre tengo problemas con la regla de tres pero ya estoy practicando mas porque luego tambien me va mal en
matematicas jajajaj pero dejando eso de lado, si fuiste muy observador notaste que en la multiplicacion para
sacar el porcentaje use 100.0 con el .0 al final en vez de 100 normal, esto por que?, Por que si haces una 
division con enteros C++ se salta ese ultimo decimal, no se porque pero como que le da hambre y le gusta
arruinarme mis programas de formas que ni siquiera tienen sentido para mi, pero bueno es parte del proceso.

Ademas de los problemas antes de eso y que se me olvido por completo la estructura de switch y no puse breaks
pues todo bien. Algo de lo que estoy muy orgulloso es que cada vez este tipo de ejercicios se me van haciendo
mas y mas sencillos cuando antes se me complicaba mucho mucho muucho la logica y tambien me senti muy realizado
porque ya pienso en como agilizar los procesos aunque sean mas simples como el de guardar las calificaciones
en un arreglo cuando antes hubiera preferido irme a la segura sin experimentar, pero me di cuenta que de lo que
se aprende es de los errores y no de las cosas que salen bien a la primera. Me siento muy realizado :)
*/