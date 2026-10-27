#include <iostream>
#include <fstream>
using namespace std;

void guarda_entero(int valor);

int main()
{

    for (int i = 0; i < 10; i++)
    {
        guarda_entero(i);
    }

    return 0;
}
void guarda_entero(int valor)
{
    ofstream fich("ejemplo.txt", ios::app);
    if (!fich)
    {
        cout << "error al abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }
    fich << valor << endl;
}