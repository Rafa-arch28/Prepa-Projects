#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "structs.h"

const int MAXIMO = 100;

void registrar(Alumno alumnos[MAXIMO], int& total, int& LIBROS, int& libros_p);
void reporte(Alumno alumnos[MAXIMO], int& total, int& LIBROS, int& libros_p);
void mostrar_menu(Alumno alumnos[MAXIMO], int& total, int& LIBROS, int& libros_p);

/*
esta funcion lee los alumnos guardados en alumnos.txt y los coloca en el arreglo
devuelve un boolean porque necesitamos saber si la lectura del archivo funciono:
true significa que se leyeron los datos correctamente y false significa
que el archivo no existe o que tiene un formato incorrecto
*/
bool cargar_alumnos(Alumno alumnos[MAXIMO], int& total);

/*
esta funcion guarda todos los alumnos del arreglo en alumnos.txt
devuelve un bool para avisar si el guardado fue exitoso:
true significa que el archivo se pudo abrir y false significa que no
se pudo abrir el archivo para guardar
*/
bool guardar_alumnos(const Alumno alumnos[MAXIMO], int total);

#endif
