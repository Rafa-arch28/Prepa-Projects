#include <iostream>
#include "funciones.h"

using namespace std;

int LIBROS = 100;

int main()
{
        Alumno alumnos[MAXIMO];
        int libros_p = 0;
        int total = 0;

        if (!cargar_alumnos(alumnos, total))
        {
                cout << "ERROR NO SE PUDIERON CARGAR LOS ALUMNOS GUARDADOS EL PROGRAMA COMENZARA SIN REGISTROS" << endl;
        }

        for (int i = 0; i < total; i++)
        {
                if (alumnos[i].codigo_libro != 0)
                {
                        libros_p++;
                }
        }
        LIBROS = 100 - libros_p;

        mostrar_menu(alumnos, total, LIBROS, libros_p);
        if (!guardar_alumnos(alumnos, total))
        {
                cout << "ERROR NO SE PUDIERON GUARDAR LOS DATOS, TERMINARA EN ERROR EL PROGRAMA" << endl;
                return 1;
        }

        return 0;
}
