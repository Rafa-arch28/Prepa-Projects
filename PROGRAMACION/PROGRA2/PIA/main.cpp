#include <iostream>
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

void registrar(Alumno alumnos[MAXIMO], int& total, int& LIBROS, int& libros_p);
void reporte(Alumno alumnos[MAXIMO], int& total, int& LIBROS, int& libros_p);
void mostrar_menu(Alumno alumnos[MAXIMO], int& total, int& LIBROS, int& libros_p);

int main()
{
        Alumno alumnos[MAXIMO];
        int libros_p = 0;
        int total = 0;

        mostrar_menu(alumnos, total, LIBROS, libros_p);


        return 0;
}

void registrar(Alumno alumnos[MAXIMO], int& total, int& LIBROS, int& libros_p)
{
if (total < MAXIMO)
        {
                int opc = 0;
                char opc2;
                bool bandera = true;

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
                                cout << "ALUMNO #" << i + 1 << endl;
                                cin.ignore();
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
                                                cin.ignore();
                                                cout << "Ingrese el nombre del libro: ";
                                                getline(cin, alumnos[total].nombre_libro);

                                                cout << "Ingrese el codigo del libro: ";
                                                cin >> alumnos[total].codigo_libro;

                                                LIBROS -= 1;
                                                libros_p++;
                                        }
                                        else if (opc2 == 'n')
                                        {
                                                cout << "OKEY" << endl;
                                        }
                                        else
                                        {
                                                cout << "ASEGURESE DE INGRESAR CORRECTAMENTE 's' o 'n', si quiere registrar de nuevo, solo escriba 'OKEY' en la siguiente opcion :)";
                                                cout << endl;
                                        }

                                        cout << "Va a querer usar alguna computadora? (s/n): ";
                                        cin >> opc2;

                                        if (opc2 == 's')
                                        {
                                                cout << "Ingrese el numero de la computadora: ";
                                                cin >> alumnos[total].num_computadora;
                                                bandera = false;
                                        } 
                                        else if (opc2 == 'n')
                                        {
                                                cout << "OKEY" << endl;
                                                bandera = false;
                                        }
                                        else
                                        {
                                                cout << "ESA OPCION NO EXISTE, VUELVA A INGRESAR TODO PARA Q SE LE QUITE";
                                                cout << endl;
                                        }
                                } while (bandera);
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

//HOLAA
