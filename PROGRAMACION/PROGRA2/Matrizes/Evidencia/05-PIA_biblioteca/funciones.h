#ifndef FUNCIONES_H
#define FUNCIONES_H

const int MAXIMO = 100;

#include "modelos.h"
#include <string>
using namespace std;

void llenar_prestamo(Alumno alumnos[MAXIMO], int& total);
void mostrar_prestamo(Alumno alumnos[MAXIMO], int& total);

void crear_alumno_trabajador(AlumnoTrabajador alumnos_trabajadores[MAXIMO], int& total_t);
void imprimir_trabajadores(AlumnoTrabajador alumnos_trabajadores[MAXIMO], int& total_t);
void registrar_entrada(AlumnoTrabajador &alumno_trabajador, float &hora_inicio);
void registrar_salida(AlumnoTrabajador &alumno_trabajador, float &hora_final);

void mostrar_menu_normal(Alumno alumnos[MAXIMO], int& total);
void mostrar_menu_registrar_trabajador(AlumnoTrabajador alumnos_trabajadores[MAXIMO], int& total_t);
void mostrar_menu_trabajador(AlumnoTrabajador alumnos_trabajadores[MAXIMO], int& total_t, float& hora_inicio, float& hora_final);

// funciones de guardado y lectura en archivos .txt
void guardar_prestamos(Alumno alumnos[MAXIMO], int total);
void cargar_prestamos(Alumno alumnos[MAXIMO], int& total);
void guardar_trabajadores(AlumnoTrabajador alumnos_trabajadores[MAXIMO], int total_t);
void cargar_trabajadores(AlumnoTrabajador alumnos_trabajadores[MAXIMO], int& total_t);

#endif