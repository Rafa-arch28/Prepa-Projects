/* Objetivo: Desarrollar un programa en C++ que administre el flujo de efectivo y el conteo de 
clientes de una tienda de informática con tres puntos de venta independientes.

Requerimientos Funcionales:

Ciclo Indefinido: El programa debe ejecutarse continuamente (do-while) ya que el número de 
clientes diarios es desconocido.

Interfaz de Usuario: Menú interactivo con 4 opciones (Caja 1, 2, 3 y Finalizar Turno).

Captura de Datos: Para cada venta, el sistema debe registrar el monto en efectivo y el número de 
clientes atendidos.

Acumulación Selectiva: Los datos deben sumarse únicamente a la caja seleccionada mediante una 
estructura de control (switch).

Reporte de Cierre (Output Final):
Al terminar el turno, el sistema debe generar un desglose detallado que incluya:

Por Caja: Total de efectivo y total de clientes para la Caja 1, Caja 2 y Caja 3.

Globales: Sumatoria total de efectivo recaudado y cantidad total de clientes atendidos en toda la tienda */


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
                cout << "EFECTIVO TOTAL: " << efectivo_total << endl;
                break;
            
            default:
                cout << "Opcion no valida, intente de nuevo" << endl;

        }

    } while( opcion != 4);


    return 0;
}

/* Un ejercicio que me ayudo con mi desarrollo del PIA, fue increible que lograra que funcionara
a la primera pero tenia errores de logica, por ejemplo el que mas perjudicaba el programa era este: 

    case 1:

        efectivo_caja1 += efectivo;
        clientes_caja1 += clientes;

        clientes_totales += clientes_caja1;
        efectivo_total += efectivo_caja1;
        break; 
    
Como pueden ver sumaba el efectivo de cada caja a el total directamente en el case, lo que hacia 
que el total aumentara una vez de mas obviamente arruinando el calculo y algo de lo que estoy muy
feliz fue que pude usar por primera vez el debugger de vscode para darme cuenta del error porque no
lo encontraba, lo solucione cambiando el calculo total hasta case 4, donde se imprime el reporte final.

Tambien si estuviste viendo mis codigos anteriores, pudiste darte cuenta que use la misma logica del 
condicional para no tener que pedir los datos cada vez que entraba en el switch.
*/