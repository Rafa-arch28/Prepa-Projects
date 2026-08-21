#include <iostream>
using namespace std;

struct Producto
{
    string nombre;
    float precio;
    int stock;
};

int main()
{
    int t;
    float p;

    float total_inventario = 0;

    cout << "Ingrese el tamano del inventario: ";
    cin >> t;

    Producto inventario[t];

    for (int i = 0; i < t; i++)
    {
        cout << "\nPRODUCTO #" << i + 1 << endl;
        cout << "Ingrese el nombre del producto: ";
        cin >> inventario[i].nombre; cout << endl;

        cout << "Ingrese el precio del producto: ";
        cin >> inventario[i].precio; cout << endl;

        cout << "Ingrese el stock del producto: ";
        cin >> inventario[i].stock; cout << endl;

        total_inventario = (inventario[i].precio * inventario[i].stock);
    }

    cout << "Ingrese un precio limite: $" << endl;
    cin >> p;

    for (int i = 0; i < t; i++)
    {
        if (inventario[i].precio <= p)
        {
            cout << inventario[i].nombre << endl;
        }
    }

    cout << "Precio total del inventario: " << total_inventario << endl;

    return 0;
}