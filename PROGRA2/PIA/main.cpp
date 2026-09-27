#include <iostream>
#include <cctype> // esta es para usar static_cast<tipo>

using namespace std;

const int MAXIMO = 100;
int LIBROS = 100;

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

void guardar_alumnos_libros(Alumno alumnos_libros[MAXIMO], int& total, int& LIBROS);
void guardar_alumnos_compus(Alumno alumnos_compus[MAXIMO], int& total);
void mostrar_menu();

int main()
{
        Alumno alumnos_libros[MAXIMO];
        Alumno alumnos_compus[MAXIMO];
        int total = 0;
        return 0;
}

void guardar_alumnos_libros(Alumno alumnos_libros[MAXIMO], int& total, int& LIBROS)
{       
        if (total < MAXIMO)
        {
                int opc = 0;
                cout << "Ingrese la cantidad de alumnos que quira registrar para prestamos de libros: ";
                cin >> opc;

                if (opc <= 0 || (opc + total) > MAXIMO)
                {
                        cout << "\tCANTIDAD INCORRECTA, REGISTROS MAXIMOS ALCANZADOS O CANTIDAD ES 0" << endl;
                        cout << endl;
                }
                else
                {
                        cout << "\tLLENE SUS REGISTROS" << endl;
                        for (int i = 0; i < opc; i++)
                        {
                                cout << "ALUMNO #" << i + 1 << endl;
                                cin.ignore();
                                cout << "Ingrese el nombre del alumno: ";
                                getline(cin, alumnos_libros[total].nombre);

                                cout << "Ingrese la matricula: ";
                                cin >> alumnos_libros[total].matricula;

                                cout << "Ingrese la hora de entrada (8:30 = 8.30): ";
                                cin >> alumnos_libros[total].hora_entrada;

                                cout << "Ingrese la hora de salida (8:30 = 8.30): ";
                                cin >> alumnos_libros[total].hora_salida;

                                cout << "Ingrese el dia en numero: ";
                                cin >> alumnos_libros[total].fecha.dia;

                                cout << "Ingrese el mes en numero: ";
                                cin >> alumnos_libros[total].fecha.mes;

                                cout << "Ingrese el anio en numero: ";
                                cin >> alumnos_libros[total].fecha.anio;

                                cout << "Ingrese el nombre del libro: ";
                                getline(cin, alumnos_libros[total].nombre_libro);

                                cout << "Ingrese el codigo del libro: ";
                                cin >> alumnos_libros[total].codigo_libro;

                                total++;
                        }
                }
        }
        else
        {
                cout << "\tREGISTROS LLENOS, LO SIENTO" << endl;
                cout << endl;
        }
}

void guardar_alumnos_compus(Alumno alumnos_compus[MAXIMO], int& total)
{
        // holaaa
}
