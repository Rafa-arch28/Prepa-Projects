#include <iostream>
#include <string>

using namespace std;

const int MAXIMO_REGISTROS = 5;

struct FechaNaciemiento
{
    int dia;
    int mes;
    int anio;
};

struct Registro 
{
    string nombre;
    FechaNaciemiento fecha; // struct anidado para poder poner la fecha formateada :)
    int estatura;
};

void llenar_registro(Registro registros[], int &total); // uso paso por referencia para evitar return todo mas facil
void imprimir_registros(Registro registros[], int total); // los arreglos pasan directo por referencia en c++
void imprimir_mayor_7(Registro registros[], int total); // en las funciones donde solo imprimo o leo el total no ocupo por referencia
void buscar_registro(Registro registros[], int total);

int main()
{

    Registro registros[MAXIMO_REGISTROS];
    int total_registros = 0;
    int opc;
    bool salir = true;

    cout << "\t\tREGISTROS" << endl;
    do
    {
        cout << "INGRESE EL NUMERO DE LA OPCION DEL MENU QUE DESEE: " << endl;
        cout << "1. Llenar registros\n2. Imprimir todos los registros\n3. Imprimir registros con nombres con mas de 7 caracteres\n4. Buscar un registro por nombre\n5. Salir\n: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
        {
            llenar_registro(registros, total_registros);
            break;
        }
        case 2:
        {
            imprimir_registros(registros, total_registros);
            break;
        }
        case 3:
        {
            imprimir_mayor_7(registros, total_registros);
            break;
        }
        case 4:
        {
            buscar_registro(registros, total_registros);
            break;
        }
        case 5:
        {
            cout << "GRACIAS POR USAR EL PROGRAMA ADIOOOSS" << endl;
            salir = false;
            break;
        }
        default:
        {
            cout << "ESA OPCION NO ESTA EN EL MENU" << endl;
        }
        }
    } while (salir);
    
    return 0;
}

void llenar_registro(Registro registros[], int &total)
{
    int opc = 0;
    string nombre;
    
    if (total < 5)
    {
        cout << "Cuantos registros desea llenar? : ";
        cin >> opc;

        if (opc <= 0 || (total + opc) > 5)
        {
            cout << "CANTIDAD INCORRECTA, SON MAXIMO 5" << endl;
            cout << endl;
        }
        else
        {
            cout << "\t\tLLENE SUS REGISTROS" << endl;
            for (int i = 0; i < opc; i++)
            {
                cout << "REGISTRO #" << total + 1 << endl;
                cin.ignore();
                cout << "NOMBRE" << endl;
                cout << "Ingrese su nombre (MAXIMO 40 CARACTERES): ";
                getline(cin, nombre);
                if (nombre.length() > 40)
                {
                    cout << "Nombre invalido, vuelva a intentar en el menu" << endl;
                    return;
                }
                else
                {
                    registros[total].nombre = nombre;
                }

                cout << "FECHA DE NACIMIENTO" << endl;
                cout << "Ingrese el dia: ";
                cin >> registros[total].fecha.dia;

                cout << "Ingrese el mes: ";
                cin >> registros[total].fecha.mes;

                cout << "Ingrese el anio: ";
                cin >> registros[total].fecha.anio;

                cout << "ESTATURA (CM)" << endl;
                cout << "Ingrese su estatura en centimetros: ";
                cin >> registros[total].estatura;
                total++;
            }
            cout << endl;
        }
    }
    else
    {
        cout << "\t\tREGISTROS LLENOS, NO PUEDO HACER NADA :)" << endl;
        cout << endl;
    }
}

void imprimir_registros(Registro registros[], int total)
{
    if (total == 0)
    {
        cout << "NO HAY REGISTROS POR MOSTRAR" << endl;
        cout << endl;
    }
    else
    {
        cout << "\t\tREPORTE DE REGISTROS" << endl;
        for (int i = 0; i < total; i++)
        {
            cout << "REGISTRO #" << i + 1 << endl;
            cout << "NOMBRE: " << registros[i].nombre << endl;
            cout << "FECHA DE NACIMIENTO: " << registros[i].fecha.dia << "/" << registros[i].fecha.mes << "/" << registros[i].fecha.anio << endl;
            cout << "ESTATURA (CM): " << registros[i].estatura << endl;
        }
        cout << endl;
    }
}

void imprimir_mayor_7(Registro registros[], int total)
{
    bool encontrado = false;

    if (total == 0)
    {
        cout << "NO HAY REGISTROS" << endl;
        cout << endl;
    }
    else
    {
        cout << "\t\tREGISTROS CON NOMBRES CON MAS DE 7 CARACTERES " << endl;
        for (int i = 0; i < total; i++)
        {
            if (registros[i].nombre.length() > 7)
            {
                cout << "REGISTRO #" << i + 1 << endl;
                cout << "NOMBRE: " << registros[i].nombre << endl;
                cout << "FECHA DE NACIMIENTO: " << registros[i].fecha.dia << "/" << registros[i].fecha.mes << "/" << registros[i].fecha.anio << endl;
                cout << "ESTATURA (CM): " << registros[i].estatura << endl;

                encontrado = true;
            }
        }
        cout << endl;
    }
    if (!encontrado)
    {
        cout << "\t\tNO HAY NINGUN REGISTRO CON NOMBRE CON MAS DE 7 CARACTERES" << endl;
        cout << endl;
    }
}

void buscar_registro(Registro registros[], int total)
{
    string nombre;
    if (total == 0)
    {
        cout << "NO HAY REGISTROS" << endl;
    }
    else
    {
        cout << "\t\tBUSQUEDA DE REGISTROS" << endl;
        cout << "Ingrese el nombre del registro que quiere buscar: ";
        cin.ignore();
        getline(cin, nombre);
        for (int i = 0; i < total; i++)
        {
            if (registros[i].nombre == nombre)
            {
                cout << "ENCONTRADOOOO" << endl;
                cout << "REGISTRO #" << i + 1 << endl;
                cout << "NOMBRE: " << registros[i].nombre << endl;
                cout << "FECHA DE NACIMIENTO: " << registros[i].fecha.dia << "/" << registros[i].fecha.mes << "/" << registros[i].fecha.anio << endl;
                cout << "ESTATURA (CM): " << registros[i].estatura << endl;
            }
        }
        cout << endl;
    }
}