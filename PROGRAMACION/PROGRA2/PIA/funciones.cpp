#include "funciones.h"
#include <iostream>
#include <fstream>

using namespace std;

void registrar(Alumno alumnos[MAXIMO], int& total, int& LIBROS, int& libros_p)
{
        if (total < MAXIMO)
        {
                int opc = 0;
                char opc2;
                cout << "Ingrese la cantidad de alumnos que quira registrar: ";
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
                                alumnos[total] = Alumno{};
                                cout << "ALUMNO #" << total + 1 << endl;

                                cin >> ws;
                                cout << "Ingrese el nombre del alumno: ";
                                getline(cin, alumnos[total].nombre);

                                cout << "Ingrese la matricula: ";
                                cin >> alumnos[total].matricula;

                                cout << "Ingrese la hora de entrada (8:30 = 8.30): ";
                                cin >> alumnos[total].hora_entrada;

                                cout << "Ingrese la hora de salida (8:30 = 8.30): ";
                                cin >> alumnos[total].hora_salida;

                                cout << "Ingrese el dia en numero: ";
                                cin >> alumnos[total].fecha.dia;

                                cout << "Ingrese el mes en numero: ";
                                cin >> alumnos[total].fecha.mes;

                                cout << "Ingrese el anio en numero: ";
                                cin >> alumnos[total].fecha.anio;

                                do
                                {
                                        cout << "Va a querer pedir un prestamo para un libro? (s/n): ";
                                        cin >> opc2;

                                        if (opc2 == 's')
                                        {
                                                if (LIBROS == 0)
                                                {
                                                        cout << "NO HAY LIBROS DISPONIBLES" << endl;
                                                        continue;
                                                }
                                                cin >> ws;
                                                cout << "Ingrese el nombre del libro: ";
                                                getline(cin, alumnos[total].nombre_libro);

                                                cout << "Ingrese el codigo del libro: ";
                                                cin >> alumnos[total].codigo_libro;

                                                LIBROS -= 1;
                                                libros_p++;
                                                break;
                                        }
                                        else if (opc2 == 'n')
                                        {
                                                cout << "OKEY" << endl;
                                                break;
                                        }
                                        else
                                        {
                                                cout << "ASEGURESE DE INGRESAR CORRECTAMENTE 's' o 'n', si quiere registrar de nuevo, solo escriba 'OKEY' en la siguiente opcion :)";
                                                cout << endl;
                                        }
                                } while (true);

                                do
                                {
                                        cout << "Va a querer usar alguna computadora? (s/n): ";
                                        cin >> opc2;

                                        if (opc2 == 's')
                                        {
                                                cout << "Ingrese el numero de la computadora: ";
                                                cin >> alumnos[total].num_computadora;
                                                break;
                                        }
                                        else if (opc2 == 'n')
                                        {
                                                cout << "OKEY" << endl;
                                                break;
                                        }
                                        else
                                        {
                                                cout << "ESA OPCION NO EXISTE, VUELVA A INGRESAR TODO PARA Q SE LE QUITE";
                                                cout << endl;
                                        }
                                } while (true);
                                total++;
                        }
                        // Aqui es algo raro que se llame la funcion dentro del if pero funciona
                        // guardatelo para futuros proyectos
                        if (!guardar_alumnos(alumnos, total))
                        {
                                cout << "ERROR: NO SE PUDIERON GUARDAR LOS ALUMNOS" << endl;
                        }
                }
        }
        else
        {
                cout << "\tREGISTROS LLENOS, LO SIENTO" << endl;
                cout << endl;
        }
}

bool cargar_alumnos(Alumno alumnos[MAXIMO], int& total)
{
        ifstream archivo("alumnos.txt");
        if (!archivo.is_open())
        {
                total = 0;
                return false;
        }

        int cantidad = 0;
        if (!(archivo >> cantidad) || cantidad < 0 || cantidad > MAXIMO)
        {
                cerr << "ERROR EL FORMATO DE ALUMNOS.TXT NO ES VALIDO" << endl;
                total = 0;
                return false;
        }

        archivo.ignore(1000, '\n');
        total = 0;
        for (int i = 0; i < cantidad; i++)
        {
                Alumno alumno{};
                // Este if sirve para revisar si cada dato se pudo leer correctamente
                // Uso OR para detectar si al menos una lectura fallo
                if (!getline(archivo, alumno.nombre)
                || !(archivo >> alumno.matricula)
                || !(archivo >> alumno.hora_entrada)
                || !(archivo >> alumno.hora_salida)
                || !(archivo >> alumno.fecha.dia)
                || !(archivo >> alumno.fecha.mes)
                || !(archivo >> alumno.fecha.anio)
                || !(archivo >> alumno.codigo_libro)
                || !(archivo >> alumno.num_computadora))
                {
                        cout << "ERROR NO SE PUDO LEER EL REGISTRO #" << i + 1 << " DE ALUMNOS.TXT" << endl;
                        total = 0;
                        return false;
                }
                archivo.ignore(1000, '\n');
                if (!getline(archivo, alumno.nombre_libro))
                {
                        cout << "ERROR FALTA EL NOMBRE DEL LIBRO DEL REGISTRO #" << i + 1 << endl;
                        total = 0;
                        return false;
                }
                alumnos[total] = alumno;
                total++;
        }
        return true;
}

bool guardar_alumnos(const Alumno alumnos[MAXIMO], int total)
{
        ofstream archivo("alumnos.txt");
        if (!archivo.is_open())
        {
                cout << "ERROR NO SE PUDO ABRIR EL ARCHIVO" << endl;
                return false;
        }

        archivo << total << '\n';
        for (int i = 0; i < total; i++)
        {
                archivo << alumnos[i].nombre << '\n'
                        << alumnos[i].matricula << '\n'
                        << alumnos[i].hora_entrada << '\n'
                        << alumnos[i].hora_salida << '\n'
                        << alumnos[i].fecha.dia << '\n'
                        << alumnos[i].fecha.mes << '\n'
                        << alumnos[i].fecha.anio << '\n'
                        << alumnos[i].codigo_libro << '\n'
                        << alumnos[i].num_computadora << '\n'
                        << alumnos[i].nombre_libro << '\n';
        }
        archivo.close();
        return true;
}

void reporte(Alumno alumnos[MAXIMO], int& total, int& LIBROS, int& libros_p)
{
        int a = 0;
        bool bl = false;
        bool bc = false;

        cout << endl << "\tREPORTE" << endl;
        cout << "Libros prestados: " << libros_p << endl;
        cout << "Libros en stock: " << LIBROS << endl;

        cout << "\tALUMNOS CON LIBROS EN PRESTAMO" << endl;
        for (int i = 0; i < total; i++)
        {
                if (alumnos[i].codigo_libro != 0)
                {
                        cout << endl << "ALUMNO #" << i + 1 << endl;
                        cout << "Nombre: " << alumnos[i].nombre << endl;
                        cout << "Matricula: " << alumnos[i].matricula << endl;
                        cout << "Fecha en la que pidio el prestamo: " << alumnos[i].fecha.dia << "/" << alumnos[i].fecha.mes << "/" << alumnos[i].fecha.anio << endl;
                        cout << "Hora de entrada: " << alumnos[i].hora_entrada << endl;
                        cout << "Hora de salida: " << alumnos[i].hora_salida << endl;
                        cout << "Nombre del libro que tiene: " << alumnos[i].nombre_libro << endl;
                        cout << "Codigo del libro que tiene: #" << alumnos[i].codigo_libro << endl;

                        if (alumnos[i].num_computadora != 0)
                        {
                                cout << "TAMBIEN USO COMPUTADORAAAAA" << endl;
                                cout << "Numero de la computadora que uso: " << alumnos[i].num_computadora << endl;
                                bc = false;
                        }
                        bl = true;
                        cout << endl;
                }
        }
        if (!bl)
        {
                cout << endl << "\tNO HAY ALUMNOS CON LIBROS" << endl;
        }

        cout << endl << "\tALUMNOS QUE USAN LAS COMPUTADORAS" << endl;
        for (int i = 0; i < total; i++)
        {
                if (alumnos[i].num_computadora != 0)
                {
                        cout << endl << "ALUMNO #" << i + 1 << endl;
                        cout << "Nombre: " << alumnos[i].nombre << endl;
                        cout << "Matricula: " << alumnos[i].matricula << endl;
                        cout << "Fecha en la que pidio el prestamo: " << alumnos[i].fecha.dia << "/" << alumnos[i].fecha.mes << "/" << alumnos[i].fecha.anio << endl;
                        cout << "Hora de entrada: " << alumnos[i].hora_entrada << endl;
                        cout << "Hora de salida: " << alumnos[i].hora_salida << endl;
                        cout << "Numero de la computadora que uso: " << alumnos[i].num_computadora << endl;

                        if (alumnos[i].codigo_libro != 0)
                        {
                                cout << "TAMBIEN TIENE LIBROOOSS EN PRESTAMOOO" << endl;
                                cout << "Nombre del libro que tiene: " << alumnos[i].nombre_libro << endl;
                                cout << "Codigo del libro que tiene: #" << alumnos[i].codigo_libro << endl;
                                bl = true;
                        }
                        a++;
                        bc = true;
                        cout << endl;
                }
        }
        if (!bc)
        {
                cout << endl << "\tNO HAY ALUMNOS CON COMPUTADORAS" << endl;
        }
        cout << endl << "Numero de alumnos que usan las computadoras: " << a << endl;
}

void mostrar_menu(Alumno alumnos[MAXIMO], int& total, int& LIBROS, int& libros_p)
{
        int opc = 0;
        bool bandera = true;

        do
        {
                cout << "Ingrese una opcion del menu: \n1. Visita a la blibioteca\n2. Imprimir reporte de la biblioteca\n3. Salir\n: ";
                cin >> opc;
                switch (opc)
                {
                case 1:
                {
                        int opc2 = 0;
                        bool salir = true;
                        do
                        {
                                cout << endl << "\tBIENVENIDO A LA BIBLIOTECA PAPTAPIM" << endl;
                                cout << "Ingrese una opcion: \n1. Vine a consultar libros\n2. Vine a hacer tareas\n3. Salir\n: ";
                                cin >> opc2;
                                switch (opc2)
                                {
                                case 1:
                                {
                                        registrar(alumnos, total, LIBROS, libros_p);
                                        break;
                                }
                                case 2:
                                {
                                        registrar(alumnos, total, LIBROS, libros_p);
                                        break;
                                }
                                case 3:
                                {
                                        cout << endl << "\tGRACIAS POR VENIR A LA BIBLIOTECA, VOLVIENDO AL MENU PRINCIPAL" << endl;
                                        salir = false;
                                        break;
                                }
                                }
                        } while (salir);
                        break;
                }
                case 2:
                {
                        reporte(alumnos, total, LIBROS, libros_p);
                        break;
                }
                case 3:
                {
                        bandera = false;
                        break;
                }
                default:
                {
                        cout << "\tESA OPCION NO ESTA EN EL MENU, INTENTE DE NUEVO" << endl;
                }
                }
        } while(bandera);
}
