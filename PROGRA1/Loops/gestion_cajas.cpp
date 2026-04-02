

#include <iostream>
using namespace std;
int main() {

    // variables para guardar la cantidad de clientes (por caja y totales)
    int clientes_totales = 0;
    int clientes_caja1 = 0;
    int clientes_caja2 = 0;
    int clientes_caja3 = 0;

    // estas variables son solo para el input de clientes y efectivo
    int clientes = 0;
    double efectivo = 0;

    // variables para guardar el efectivo (por caja y total)
    double efectivo_total = 0;
    double efectivo_caja1 = 0;
    double efectivo_caja2 = 0;
    double efectivo_caja3 = 0;

    int opcion = 0;

    do {

        cout << "Seleccione la caja donde va a cobrar: " << endl;
        cout << "1. Caja 1" << endl;
        cout << "2. Caja 2" << endl;
        cout << "3. Caja 3" << endl;
        cout << "4. Finalizar Turno" << endl;
        cin >> opcion;

        if (opcion >= 1 && opcion <= 3) {

            cout << "Ingrese el efectivo de la compra: $";
                cin >> efectivo;
                cout << "Ingrese el numero de clientes: ";
                cin >> clientes;

        }

        switch (opcion) {

            case 1:
                efectivo_caja1 += efectivo;
                clientes_caja1 += clientes;
                break;

            case 2:
                efectivo_caja2 += efectivo;
                clientes_caja2 += clientes;
                break;

            case 3:
                efectivo_caja3 += efectivo;
                clientes_caja3 += clientes;
                break;

            case 4:
                efectivo_total = efectivo_caja1 + efectivo_caja2 + efectivo_caja3;
                clientes_totales = clientes_caja1 + clientes_caja2 + clientes_caja3;

                cout << "Imprimiento Reporte Final:" << endl;
                cout << "Efectivo en Caja 1: $" << efectivo_caja1 << endl;
                cout << "Efectivo en Caja 2: $" << efectivo_caja2 << endl;
                cout << "Efectivo en Caja 3: $" << efectivo_caja3 << endl << endl;

                cout << "Clientes en Caja 1: " << clientes_caja1 << endl;
                cout << "Clientes en Caja 2: " << clientes_caja2 << endl;
                cout << "Clientes en Caja 3: " << clientes_caja3 << endl << endl;

                cout << "CLIENTES TOTALES: " << clientes_totales << endl;
                cout << "EFECTIVO TOTAL: " << efectivo_total;
                break;
            
            default:
                cout << "Opcion no valida, intente de nuevo" << endl;

        }

    } while( opcion != 4);


    return 0;
}