/* REQUERIMIENTOS DEL SISTEMA
Entrada: Grupo de alumnos con 4 calificaciones cada uno (Rango: 0 - 100).

Interfaz: Menú interactivo con 4 opciones (Controlado por do-while).

Funciones por Opción:
Captura: Pedir 4 notas, validar rango y mostrar si el alumno Aprobó/Reprobó.

Reporte Grupal: Mostrar totales (aprobados/reprobados), porcentajes, Promedio Grupal y total de alumnos.

Lista: Tabla con las 4 notas de cada alumno y su Promedio Individual.

Salir: Finalizar ejecución solo al presionar esta opción. */

#include <iostream>
using namespace std;

int main() {

    // Las variables para guardar alumnos en una matriz >:)
    int numero_alumnos = 0;

    // variables para contar todo lo demas
    int alumnos_reprobados = 0;
    int alumnos_aprobados = 0;
    double suma_grupal = 0;
    // esta variable no estaba antes pero la uso para dividir suma grupal, crei que era lo mismo :(
    double promedio_grupal;

    // me molesta un poco tener variables para todo pero asi tiene que ser
    double porcentaje_aprobados = 0;
    double porcentaje_reprobados = 0;

    int opcion = 0;
    int alumnos_totales = 0;

    cout << "Ingrese la cantidad de alumnos del grupo: " << endl;
    cin >> numero_alumnos;

    double total_calificaciones[numero_alumnos][4]; // 4 es el numero de calificaciones
    double promedio_individual[numero_alumnos];

    do {
    
        cout << "Ingrese la opcion del menu deseada: " << endl;
        cout << "1. Capturar alumno" << endl;
        cout << "2. Imprimir reporte grupal" << endl;
        cout << "3. Imprimir Lista de Calificaciones" << endl;
        cout << "4. Salir y cerrar" << endl;
        cin >> opcion;

        /* TUVE UN PROBLEMAAAAAA, la terminal decia algo de Jump to case lebel, investigando
        en google vi que era por que estaba declarando la variable dentro del case y el compilador
        piensa que es peligroso porque si va directo a case 2 no crea la variable, es raro pero lo
        comprendo, buscando como agregarlo vi que tenia que poner corchetes {}, al principio no
        sabia porque pero vi que era para crear algo llamado "scope", que es literal encerrar la 
        variable para que solo viva en el case 1, creo que voy a empezar a usar mas llaves para evitar
        cosas asi */

        switch (opcion) {

            case 1: {
                double suma_alumno = 0; // tuve un error porque no se limpiaba la variable, mejor la declaro en el case
                cout << "Alumno " << alumnos_totales + 1 << endl;

                for (int i = 0; i < 4; i++) {

                    cout << "Parcial " << i + 1 << ": " << endl;
                    cin >> total_calificaciones[alumnos_totales][i];

                    // Valido que sea entre 0 y 100 las calificaciones
                    // ACTUALIZACION: tuve un error al poner 0 y 100, le voy a quitar el =
                    while (total_calificaciones[alumnos_totales][i] < 0 or total_calificaciones[alumnos_totales][i] >    100) {
                        cout << "Calificacion no valida, reingrese entre 0 y 100" << endl;
                        cin >> total_calificaciones[alumnos_totales][i];
                    }
                    suma_alumno += total_calificaciones[alumnos_totales][i];
                }

                promedio_individual[alumnos_totales] = suma_alumno / 4;

                if (promedio_individual[alumnos_totales] >= 70) {
                    cout << "alumno aprobado" << endl;
                    alumnos_aprobados++;
                } else {
                    cout << "alumno reprobado" << endl;
                    alumnos_reprobados++;
                }

                suma_grupal += promedio_individual[alumnos_totales];
                alumnos_totales++;
                break;
            }
            case 2:
                cout << "Alumnos aprobados: " << alumnos_aprobados << endl;
                cout << "Alumnos reprobados: " << alumnos_reprobados << endl;

                porcentaje_aprobados = (alumnos_aprobados * 100.0) / alumnos_totales;
                porcentaje_reprobados = (alumnos_reprobados * 100.0) / alumnos_totales;

                cout << "Porcentaje de aprobados: %" << porcentaje_aprobados << endl;
                cout << "Porcentaje de reprobados: %" << porcentaje_reprobados << endl;

                promedio_grupal = suma_grupal / alumnos_totales;
                cout << "Promedio grupal: " << promedio_grupal << endl;

                cout << "Total de alumnos en el grupo: " << alumnos_totales << endl;
                break;
            // ES MI PRIMERA VEZ USANDO MATRIZES Y NO ENTENDIA MUY BIEN AJAJAJAJ
            case 3:
                for (int i = 0; i < alumnos_totales; i++) {
                cout << "Alumno " << i + 1 << " Notas: ";
                    
                    for (int j = 0; j < 4; j++) {
                        cout << total_calificaciones[i][j] << " ";
                    }
                cout << "Promedio Final: " << promedio_individual[i] << endl;
                }
                break;
            
            case 4:
                cout << "Saliendo del programa " << endl;
                break;
            
            default:
                cout << "Opcion no en el menu, vuelve a intentar nub" << endl;
        }   

    } while (opcion != 4);

    return 0;
}

/* RAZONAMIENTO FINAL: Hasta ahora el programa mas dificil que eh hecho, usar matrizes, saber donde se guardan
los datos en cada cuadrito de la cuadricula es muuuy dificl, empiezo a extranar los diccionarios de 
python pero pues asi es. Ademas de dificil aprendi MUUUCHSISISIMO, no sabia que se podian
crear matrizes poniendo [][], interesante pero tiene sentido.

Ademas de eso tambien aprendi a sacar porcentajes solo multiplicando, al principio lo hice solo restando
pero no funciono entoces ya tuve que hacer la multiplicacion y eso de la validacion con WHILE fue UFF
super interesante, no sabia que se podia validar con bucles cuando normalmente usamos condicionales.

Creo que tambien podria poner una validacion para cuando entren directo al case 2 o 3 y no hayan capturado
alumnos pero eso lo dejare para despues.

Programa dificil pero para aprender estuvo muy bien.

POSTDATA: Se que no interesa mucho pero me tarde unas 3 horas en hacer el programa entre pausar para 
pensar en la logica, errores que tuve y variables que usaba pero se me olvidaba declarar :)

POSTDATA 2: Viendo codigos en github vi que usaban comentarios como TODO, quiero empezar a usarlo en
un futuro (manana) JJAJAJ */