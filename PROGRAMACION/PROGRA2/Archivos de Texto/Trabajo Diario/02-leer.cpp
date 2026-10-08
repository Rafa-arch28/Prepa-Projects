#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{

    ifstream archivo("prueba.txt");

    if (!archivo)
    {
        cout << "El archivo no se pudo abrir :(" << endl;
        return 1;
    }

    string linea;

    while(getline(archivo, linea))
    {
        cout << linea << endl;
    }

    archivo.close();
    
    return 0;
}