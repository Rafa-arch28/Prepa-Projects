#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>
using namespace std;

struct Fecha
{
        int dia;
        int mes;
        int anio;
};

struct Alumno
{
        int matricula;
        string nombre;
        Fecha fecha;
        float hora_entrada;
        float hora_salida;
        string nombre_libro;
        int codigo_libro = 0; // en caso de que no haya querido un libro y solo haya venido a la compu, se queda en 0
        int num_computadora = 0; // En caso de que no use la computadora, se quede vacio en 0
};

#endif
