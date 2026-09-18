#include <iostream>
using namespace std;

int main()
{
    string opinion[3];
    int v_exc = 0;

    cout << "GRACIAS POR ASISTIR A NUESTRA CAFETERIA !!! \n Porfavor, ayudenos a mejorar nuestro servicio" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Ingrese su calificacion cliente #" << i + 1 << "\nExcelente \nBueno \nRegular \nNo fue de mi agrado \n: ";
        getline(cin, opinion[i]);

        if (opinion[i] == "excelente" or opinion[i] == "Excelente")
        {
            v_exc++;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        cout << "La calificacion del cliente " << i + 1 << ": " << opinion[i] << endl;
    }

    cout << "GRACIAS POR SUS CALIFICACIONES !!!!!" << endl;
    cout << "Las veces que eligieron excelente fueron: " << v_exc;
}