#include "funciones.h"
#include <iostream>
#include <fstream> // para leer y escribir archivos (.txt)
#include <cctype> // esta es para usar static_cast<tipo>

using namespace std;

void llenar_prestamo(Alumno alumnos[MAXIMO], int &total)
{
    int opc = 0;

    if (total < MAXIMO)
    {
        cout << "Cuantos registros quiere llenar?: ";
        cin >> opc;

        if (opc <= 0 || (total + opc) > MAXIMO)
        {
            cout << "CANTIDAD INCORRECTA, SON MAXIMO 100" << endl;
            cout << endl;
        }
        else
        {
            cout << "\tLLENE SUS REGISTROS" << endl;
            for (int i = 0; i < opc; i++)
            {
                cout << endl << "REGISTRO #" << total + 1 << endl;
                cin.ignore();
                cout << "Ingrese el nombre del estudiante: ";
                getline(cin, alumnos[total].nombre);

                cout << "Ingrese la matricula del alumno: ";
                cin >> alumnos[total].matricula;

                cin.ignore();
                cout << "Ingrese el nombre del libro: ";
                getline(cin, alumnos[total].nombre_libro);

                cout << "Ingrese el codigo del libro: ";
                cin >> alumnos[total].codigo_libro;
                total++;
            }
            cout << endl;
        }
    }
    else
    {
        cout << "\tREGISTROS LLENOS NO PUEDO HACER NADA" << endl;
        cout << endl;
    }
}

void mostrar_prestamo(Alumno alumnos[MAXIMO], int &total)
{
    if (total != 0)
    {
        for (int i = 0; i < total; i++)
        {
            cout << endl << "\tPRESTAMO #" << i + 1 << endl;
            cout << "Nombre: " << alumnos[i].nombre << endl;
            cout << "Matricula: " << alumnos[i].matricula << endl;
            cout << "Libro que pidio: " << alumnos[i].nombre_libro << endl;
            cout << "Codigo del libro que pidio: " << alumnos[i].codigo_libro << endl;
        }
        cout << endl;
    }
    else
    {
        cout << "\tNO HAY REGISTROS" << endl;
        cout << endl;
    }
}

void crear_alumno_trabajador(AlumnoTrabajador alumnos_trabajadores[MAXIMO], int &total_t)
{
    int opc = 0;
    if (total_t < MAXIMO)
    {
        cout << "Ingrese cuantos alumnos trabajadores va a registrar: ";
        cin >> opc;

        if (opc <= 0 || (total_t + opc) > MAXIMO)
        {
            cout << "\tCANTIDAD INCORRECTA, SON MAXIMO 100" << endl;
            cout << endl;
        }
        else
        {
            for (int i = 0; i < opc; i++)
            {
                cout << "\tALUMNO TRABAJADOR #" << i + 1 << endl;
                cout << "Ingrese el nombre del alumno: ";
                cin >> alumnos_trabajadores[total_t].nombre;

                alumnos_trabajadores[total_t].id = total_t;
                cout << "SU ID ES: " << alumnos_trabajadores[total_t].id << endl;
                total_t++;
            }
            cout << endl;
        }
    }
    else
    {
        cout << "\tREGISTROS LLENOS" << endl;
    }
}

// Convierte una hora escrita como decimal (8.30 = 8:30) a minutos totales (8*60+30 = 510)
// La parte decimal se interpreta como minutos y se redondea para evitar errores
int convertir_a_minutos(float hora)
{
    int horas = static_cast<int>(hora); // separa la parte entera del decimal (por ejemplo 8.30 pasa a 8) 
    int minutos = static_cast<int>((hora - horas) * 100 + 0.5); // toma los decimales x 100 y redondea con 0.5, se suma 0.5 porque static_cast corta la parte decimal (si es 7.3 es + 0.5, da 7.8 y aun asi devuelve 7)
    return horas * 60 + minutos; // aqui devuevlo los minutos totales
}

void registrar_entrada(AlumnoTrabajador &alumno_trabajador, float &hora_inicio)
{
    char opc;

    do
    {
        if (alumno_trabajador.enTurno == true)
        {
            cout << "SIGUES EN TURNO, SIGUELE A LA CHAMBA" << endl;
            return;
        }
        cout << "Desea iniciar su turno? (S/n): ";
        cin >> opc;
        opc = tolower(opc);

        if (opc == 's')
        {
            cout << "\tINICIANDO TURNO" << endl;

            cout << "Igrese su hora de entrada en 24 hrs (8pm = 20:00) con este formato (8:30 = 8.30): " << alumno_trabajador.nombre << ": ";
            cin >> alumno_trabajador.turno.hora_entrada;

            alumno_trabajador.enTurno = true;
            cout << "ESTAS EN TURNO, RECUERDA TRABAJAR TODAS TUS HORAS :)" << endl;
            hora_inicio = alumno_trabajador.turno.hora_entrada;
            return;
        }
        else
        {
            cout << "OKEY ENTONCES PARA QUE LE DAS A REGISTRAR ENTRADA JAJAJA" << endl;
            cout << endl;
            return;
        }
    } while (alumno_trabajador.enTurno == false);
}

void registrar_salida(AlumnoTrabajador &alumno_trabajador, float &hora_final)
{
    char opc;

    do
    {
        if (alumno_trabajador.enTurno == false)
        {
            cout << "\tNO ESTAS EN TURNO, INICIA TU TURNO ANTES PORFAVOR" << endl;
            return;
        }
        cout << "Desea TERMINAR su turno? (S/n): ";
        cin >> opc;
        opc = tolower(opc);

        if (opc == 's')
        {
            cout << endl << "\tITERMINANDO TURNO" << endl;

            cout << "Igrese su hora de salida en 24 hrs (8pm = 20:00) con este formato (8:30 = 8.30): " << alumno_trabajador.nombre << ": ";
            cin >> alumno_trabajador.turno.hora_salida;

            cout << "HORA DE ENTRADA: " << alumno_trabajador.turno.hora_entrada << endl;
            cout << "HORA DE SALIDA: " << alumno_trabajador.turno.hora_salida << endl;

            // Convierte ambas horas a minutos para restarlas sin errores de punto flotante
            int minutos_entrada = convertir_a_minutos(alumno_trabajador.turno.hora_entrada);
            int minutos_salida = convertir_a_minutos(alumno_trabajador.turno.hora_salida);

            // Guarda el total trabajado (en minutos) y lo muestra en horas y minutos
            alumno_trabajador.turno.minutos_trabajados = minutos_salida - minutos_entrada;
            int horas = alumno_trabajador.turno.minutos_trabajados / 60;
            int minutos = alumno_trabajador.turno.minutos_trabajados % 60;
            cout << "HORAS TRABAJADAS: " << horas << " horas con " << minutos << " minutos" << endl;

            alumno_trabajador.enTurno = false;
            cout << "DEJAS DE ESTAR EN TURNO, GRACIAS POR LAS HORAS TRABAJADAS :)" << endl;

            hora_final = alumno_trabajador.turno.hora_salida;
            return;
        }
        else
        {
            cout << " \tENTONCES PARA QUE LE DAS A LA OPCIOOOONNN AGHHH " << endl;
            cout << endl;
            return;
        }
    } while (alumno_trabajador.enTurno == true);
}

void imprimir_trabajadores(AlumnoTrabajador alumnos_trabajadores[MAXIMO], int &total_t)
{
    if (total_t == 0)
    {
        cout << "\tNO EXISTEN REGISTROS" << endl;
        cout << endl;
    }
    else
    {
        for (int i = 0; i < total_t; i++)
        {
            cout << "\tALUMNO TRABAJADOR #" << i + 1 << endl;
            cout << "El nombre del alumno #" << i + 1 << "es: " << alumnos_trabajadores[i].nombre << endl;
            cout << "SU ID ES: " << alumnos_trabajadores[i].id << endl;
        }
        cout << endl;
    }
}

void mostrar_menu_normal(Alumno alumnos[MAXIMO], int &total)
{
    int opc = 0;
    bool salir = true;

    do
    {
        cout << "\tIngrese la opcion que desee: ";
        cout << "1. Llenar prestamos\n2. Imprimir los prestamos\n3. Salir al menu\n: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
        {
            llenar_prestamo(alumnos, total);
            break;
        }
        case 2:
        {
            mostrar_prestamo(alumnos, total);
            break;
        }
        case 3:
        {
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
}

void mostrar_menu_registrar_trabajador(AlumnoTrabajador alumnos_trabajadores[MAXIMO], int& total_t)
{
    int opc = 0;
    bool salir = true;

    cout << "\tMENU PARA REGISTRAR TRABAJADORES" << endl;
    cout << endl;

    do
    {
        cout << "Ingrese la Opcion del menu que desee: ";
        cout << "1. Registrar nuevo trabajador\n2. Imprimir alumnos trabajadores\n3. Salir\n: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
        {
            crear_alumno_trabajador(alumnos_trabajadores, total_t);
            break;
        }
        case 2:
        {
            imprimir_trabajadores(alumnos_trabajadores, total_t);
            break;
        }
        case 3:
        {
            salir = false;
            break;
        }
        default:
        {
            cout << "\tESA OPCION NO ESTA EN EL MENU :(" << endl;
        }
        }
        cout << endl;
    } while (salir);
    
}

void mostrar_menu_trabajador(AlumnoTrabajador alumnos_trabajadores[MAXIMO], int& total_t, float& hora_inicio, float& hora_final)
{
    int opc = 0;
    bool salir = true;
    bool encontrado = false;
    int id_v = 0;

    cout << "Ingrese su ID porfavor: ";
    cin >> id_v;

    for (int i = 0; i < total_t; i++)
    {
        if (id_v == alumnos_trabajadores[i].id)
        {
            encontrado = true;
            cout << "\tBIENVENIDO " << alumnos_trabajadores[i].nombre << endl;

            do
            {
                cout << endl << "Ingrese la opcion del menu que desee: ";
                cout << "1. Empezar turno\n2. Terminar turno\n3. Salir\n: ";
                cin >> opc;

                switch (opc)
                {
                case 1:
                {
                    registrar_entrada(alumnos_trabajadores[i], hora_inicio);
                    break;
                }
                case 2:
                {
                    registrar_salida(alumnos_trabajadores[i], hora_final);
                    break;
                }
                case 3:
                {
                    salir = false;
                    break;
                }
                default:
                {
                    cout << "\tESA OPCION NO ESTA EN EL MENU :(" << endl;
                    break;
                }
                }
                cout << endl;
            } while (salir);
            cout << endl;
            break;
        }
    }

    if (encontrado == false)
    {
        cout << "\tLo siento no hay un ID como el tuyo en el registro, volveras al menu principal :)" << endl;
        cout << endl;
    }
}

// GUARDADO Y LECTURA DE DATOS (.txt)

// Escribe todos los prestamos en prestamos.txt
void guardar_prestamos(Alumno alumnos[MAXIMO], int total)
{
    ofstream archivo("prestamos.txt"); // ESCRITURA DE ARCHUVOS
    if (!archivo.is_open())
    {
        cout << "\tERROR: NO SE PUDO ABRIR prestamos.txt PARA GUARDAR" << endl;
        return;
    }

    archivo << total << endl; // primero guardo cuantos registros hay
    for (int i = 0; i < total; i++)
    {
        archivo << alumnos[i].nombre << endl;
        archivo << alumnos[i].matricula << endl;
        archivo << alumnos[i].nombre_libro << endl;
        archivo << alumnos[i].codigo_libro << endl;
    }
    archivo.close();
}

// Lee los prestamos guardados y los mete de vuelta al arreglo
void cargar_prestamos(Alumno alumnos[MAXIMO], int& total)
{
    ifstream archivo("prestamos.txt");
    if (!archivo.is_open())
    {
        return; // si no existe el archivo es porque es la primera vez que se corre
    }

    total = 0;
    int n = 0;
    archivo >> n;

    for (int i = 0; i < n && i < MAXIMO; i++)
    {
        archivo.ignore(); // el enter que deja la linea del total
        getline(archivo, alumnos[i].nombre);
        archivo >> alumnos[i].matricula;
        archivo.ignore(); // el enter que deja la matricula
        getline(archivo, alumnos[i].nombre_libro);
        archivo >> alumnos[i].codigo_libro;
        total++;
    }
    archivo.close();
    cout << "\tSE CARGARON " << total << " PRESTAMOS GUARDADOS" << endl;
}

// Escribe todos los alumnos trabajadores en trabajadores.txt (incluye su turno)
void guardar_trabajadores(AlumnoTrabajador alumnos_trabajadores[MAXIMO], int total_t)
{
    ofstream archivo("trabajadores.txt");
    if (!archivo.is_open())
    {
        cout << "\tERROR: NO SE PUDO ABRIR trabajadores.txt PARA GUARDAR" << endl;
        return;
    }

    archivo << total_t << endl;
    for (int i = 0; i < total_t; i++)
    {
        archivo << alumnos_trabajadores[i].nombre << endl;
        archivo << alumnos_trabajadores[i].id << endl;
        archivo << alumnos_trabajadores[i].turno.hora_entrada << endl;
        archivo << alumnos_trabajadores[i].turno.hora_salida << endl;
        archivo << alumnos_trabajadores[i].turno.minutos_trabajados << endl;
        archivo << alumnos_trabajadores[i].enTurno << endl; // 0 = false, 1 = true
    }
    archivo.close();
}

// Lee los alumnos trabajadores guardados y los restaura
void cargar_trabajadores(AlumnoTrabajador alumnos_trabajadores[MAXIMO], int& total_t)
{
    ifstream archivo("trabajadores.txt");
    if (!archivo.is_open())
    {
        return; // si no existe el archivo es porque es la primera vez que se corre
    }

    total_t = 0;
    int n = 0;
    archivo >> n;

    for (int i = 0; i < n && i < MAXIMO; i++)
    {
        archivo.ignore(); // el enter que deja la linea del total
        getline(archivo, alumnos_trabajadores[i].nombre);
        int enTurno = 0;
        archivo >> alumnos_trabajadores[i].id;
        archivo >> alumnos_trabajadores[i].turno.hora_entrada;
        archivo >> alumnos_trabajadores[i].turno.hora_salida;
        archivo >> alumnos_trabajadores[i].turno.minutos_trabajados;
        archivo >> enTurno;
        alumnos_trabajadores[i].enTurno = (enTurno != 0); // vuelvo a convertir 1/0 a true/false
        total_t++;
    }
    archivo.close();
    cout << "\tSE CARGARON " << total_t << " TRABAJADORES GUARDADOS" << endl;
}