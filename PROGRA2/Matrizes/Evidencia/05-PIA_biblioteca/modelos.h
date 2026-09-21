#ifndef MODELOS_H
#define MODELOS_H

#include <string>
using namespace std;

struct Turno
{
    float hora_entrada;      // hora de entrada escrita como decimal (8.30 = 8:30)
    float hora_salida;       // hora de salida escrita como decimal (17.30 = 17:30)
    int minutos_trabajados;  // hotal de minutos trabajados en el turno
};

struct Alumno
{
    string nombre;
    int matricula;
    string nombre_libro;
    int codigo_libro = 0;
};

struct AlumnoTrabajador
{
    string nombre;
    int id;
    Turno turno;
    bool enTurno;
};

#endif