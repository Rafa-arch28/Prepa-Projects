#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    ofstream archivo("prueba2.txt", ios::app);

    if (!archivo.is_open())
    {
        cerr << "EL archivo no se pudo abrir" << endl;
        return 1;
    }

    string mensaje;

    while (true)
    {
        cout << "> ";
        cin >> ws;
        getline(cin, mensaje);
        if (mensaje == "salir")
        {
            break;
        }
        archivo << mensaje << endl;
    }
    archivo.close();



    return 0;
}