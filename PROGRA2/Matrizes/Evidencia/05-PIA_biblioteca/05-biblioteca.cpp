#include <iostream>
#include <string>

// Bibliotecas hechas por mi, las comillas indican que busque en este directorio
#include "modelos.h"
#include "funciones.h"

using namespace std;

int main()
{

    Alumno alumnos[MAXIMO];
    AlumnoTrabajador alumnos_trabajadores[MAXIMO];
    float hora_inicio = 0;
    float hora_final = 0;
    int total_t = 0;
    int total = 0;
    int opc = 0;
    bool salir = true;

    // CARGO LOS DATOS GUARDADOS DE LA ULTIMA VEZ QUE SE CORRIO EL PROGRAMA
    cargar_prestamos(alumnos, total);
    cargar_trabajadores(alumnos_trabajadores, total_t);

    do
    {
        cout << "\tMENU PRINCIPAL DE LA BIBLIOTECA" << endl;
        cout << "1. Menu de prestamos\n2. Menu de registrar trabajadores\n3. Menu de alumno trabajador\n4. Salir\n: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
        {
            mostrar_menu_normal(alumnos, total);
            break;
        }
        case 2:
        {
            mostrar_menu_registrar_trabajador(alumnos_trabajadores, total_t);
            break;
        }
        case 3:
        {
            mostrar_menu_trabajador(alumnos_trabajadores, total_t, hora_inicio, hora_final);
            break;
        }
        case 4:
        {
            // GUARDO TODO ANTES DE SALIR
            guardar_prestamos(alumnos, total);
            guardar_trabajadores(alumnos_trabajadores, total_t);
            salir = false;
            break;
        }
        default:
        {
            cout << "\tESA OPCION NO EXISTE INTENTALO OTRA VEZ" << endl;
            break;
        }
        }
        cout << endl;
    } while (salir);
    return 0;   
}




