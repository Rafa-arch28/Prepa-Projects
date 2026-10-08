#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Si quiero ingresar sin modificar lo otro, solo pon:
    // ofstream archivo("prueba.txt", ios::app);
    ofstream archivo("prueba2.txt");

    if (!archivo)
    {
        cout << "No se pudo crear el archivo qn sabe pq" << endl;
        return 1;
    }


    int c = 0;
    bool bandera = true;
    string linea;

    while (bandera)
    {
        cout << "Ingrese cualquier cosa en la liena " << c << ", si quiere salir ingrese '*': ";
        cin >> linea;

        if (linea != "*")
        {
            archivo << linea << endl;
        }
        else
        {
            archivo.close();
            return 0;
        }
    }
}