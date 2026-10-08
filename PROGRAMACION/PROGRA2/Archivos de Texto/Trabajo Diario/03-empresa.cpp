#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int MAXIMO = 100;

struct Direccion
{
    string colonia;
    string calle;
    int num_casa;
};

struct Cliente
{
    string nombre;
    Direccion direccion;
    string telefono;
    float estado_pago;
};

void guardar(Cliente clientes[], int& total);
void mostrar_todos(Cliente clientes[], int& total);
void menu(Cliente clientes[], int& total);

int main()
{
    Cliente clientes[MAXIMO];
    int total = 0;

    menu(clientes, total);

    return 0;
}

void guardar(Cliente clientes[], int& total)
{
    ifstream archivo_lectura("clientes_empresa.txt");
    string linea;

    total = 0;
    while (getline(archivo_lectura, linea))
    {
        if (linea.starts_with("CLIENTE #"))
        {
            total++;
        }
    }
    archivo_lectura.close();

    if (total >= MAXIMO)
    {
        cout << "\tREGISTROS LLENOS, NO PUEDES REGISTRAR MAS CLIENTES" << endl;
        cout << endl;
    }
    else
    {
        int n = 0;
        cout << "Ingrese el numero de clientes que quiere registrar: ";
        cin >> n;

        if (n <= 0 || (n+total) > MAXIMO)
        {
            cout << "\tLO SIENTO CANTIDAD INCORRECTA O REGISTROS LLENOS" << endl;
            cout << endl;
        }
        else
        {
            ofstream archivo("clientes_empresa.txt", ios::app);

            for (int i = 0; i < n; i++)
            {
                cout << "CLIENTE #" << total + 1 << endl;
                archivo << "CLIENTE #" << total + 1 << endl;

                cout << "Ingrese el nombre del cliente: ";
                cin >> ws;
                getline(cin, clientes[total].nombre);
                archivo << clientes[total].nombre << endl;

                cout << "DIREECION DEL CLIENTE" << endl;
                cout << "Ingrese la calle del cliente: ";
                cin >> ws;
                getline(cin, clientes[total].direccion.calle);
                archivo << clientes[total].direccion.calle << endl;

                cout << "Ingrese la colonia del cliente: ";
                cin >> ws;
                getline(cin, clientes[total].direccion.colonia);
                archivo << clientes[total].direccion.colonia << endl;

                cout << "Ingrese el numero de casa del cliente: ";
                cin >> clientes[total].direccion.num_casa;
                archivo << clientes[total].direccion.num_casa << endl;

                cout << "Ingrese el telefono del cliente: +52 ";
                cin >> clientes[total].telefono;
                archivo << clientes[total].telefono << endl;

                cout << "Dinero que debe el cliente: ";
                cin >> clientes[total].estado_pago;
                archivo << clientes[total].estado_pago << endl << endl;

                total++;
            }

            archivo.close();
        }
    }
}
void mostrar_todos(Cliente clientes[], int& total)
{
    // Con esta linea se abre el archivo para leer los clientes guardados
    ifstream archivo("clientes_empresa.txt");
    string linea;

    // El contador indica la posicion del cliente dentro del arreglo y tambien la cantidad de clientes
    int contador = 0;

    if (!archivo)
    {
        cout << "\tNO HAY CLIENTES REGISTRADOS" << endl;
        cout << endl;
    }
    else
    {
        // getline lee una linea completa mientras haya datos en el archivo
        // se usa porque algunos datos, como el nombre y la calle, tienen espacios
        while (getline(archivo, linea))
        {
            // Esta linea indica el inicio de los datos de un cliente
            if (linea.starts_with("CLIENTE #"))
            {
                // Los primeros tres datos son texto, por eso se leen directamente como string
                getline(archivo, clientes[contador].nombre);
                getline(archivo, clientes[contador].direccion.calle);
                getline(archivo, clientes[contador].direccion.colonia);

                // getline() siempre lee texto, stoi convierte ese texto a int porque el numero de casa es un numero entero
                // se traduce como String To Int
                getline(archivo, linea);
                clientes[contador].direccion.num_casa = stoi(linea);

                // El telefono se conserva como string para aceptar telefonos largos o que comiencen con cero
                getline(archivo, clientes[contador].telefono);

                // el estado de pago se lee como texto y stof() lo convierte a float porque puede contener decimales
                getline(archivo, linea);
                clientes[contador].estado_pago = stof(linea);

                // mostramos todos los datos del cliente que acabamos de leer
                cout << "CLIENTE #" << contador + 1 << endl;
                cout << "Nombre: " << clientes[contador].nombre << endl;
                cout << "Calle: " << clientes[contador].direccion.calle << endl;
                cout << "Colonia: " << clientes[contador].direccion.colonia << endl;
                cout << "Numero de casa: "
                    << clientes[contador].direccion.num_casa << endl;
                cout << "Telefono: +52 " << clientes[contador].telefono << endl;
                cout << "Dinero que debe: "
                    << clientes[contador].estado_pago << endl;
                cout << endl;

                // aqui aumenta el contador para guardar el siguiente cliente en la siguiente posicion del arreglo
                contador++;
            }
        }

        // cuando no encuentra mas clientes total queda con la cantidad de clientes encontrados
        total = contador;
        archivo.close();
    }
}

void menu(Cliente clientes[], int& total)
{
    int opcion = 0;

    do
    {
        cout << "\tMENU" << endl;
        cout << "1. Registrar clientes" << endl;
        cout << "2. Mostrar todos los clientes" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << endl;

        switch (opcion)
        {
            case 1:
                guardar(clientes, total);
                break;

            case 2:
                mostrar_todos(clientes, total);
                break;

            case 3:
                cout << "PROGRAMA FINALIZADO" << endl;
                break;

            default:
                cout << "\tOPCION INCORRECTA" << endl;
                cout << endl;
        }
    } while (opcion != 3);
}