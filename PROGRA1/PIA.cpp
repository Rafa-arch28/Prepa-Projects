#include <iostream>
using namespace std;

int main() {

    const int sueldo_base_dep[4] = {7000, 9000, 10000, 12000};
    // [0] = ventas, [1] = contabilidad, [2] = recursos humanos, [3] = soporte y sistemas

    // constantes de bonos por antigüedad
    const double de_10_a_20 = 0.20;
    const double de_21_a_35 = 0.25;
    const double mas_de_35 = 0.40;

    int empleados_dep[4] = {0, 0, 0, 0};
    // [0] = ventas, [1] = contabilidad, [2] = recursos humanos, [3] = soporte y sistemas

    // variables para los totales
    int empleados_con_bono = 0;
    double sueldos_iniciales = 0;
    double sueldos_finales = 0;
    double monto_bonos = 0;

    // variables de control del programa
    int opcion = 0;
    int total_empleados = 0;
    int antiguedad;
    int departamento;
    int sueldo_base = 0;
    double bono = 0;

    do {

        cout << "1. Guardar empleado" << endl;
        cout << "2. Ver reporte final" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione la opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "\nSELECCIONE DEPARTAMENTO" << endl;
            cout << "1. Ventas" << endl;
            cout << "2. Contabilidad" << endl;
            cout << "3. Recursos Humanos" << endl;
            cout << "4. Soporte y Sistemas" << endl;
            cout << "Seleccione el departamento: ";
            cin >> departamento;

            // Validacion del departamento
            if (departamento < 1 || departamento > 4) {
                cout << "ERROR 667: Departamento no valido. Intente de nuevo" << endl;
                break;
            }

            cout << "Ingrese la antiguedad del empleado (en anos): "; // NO SE PUEDE PONER Ñ JAJA
            cin >> antiguedad;

            // Validacion de antigüedad
            if (antiguedad < 0) {
                cout << "ERROR 6767: La antiguedad no puede ser negativa" << endl;
                break;
            }

            // Uso un array para contar empleados por departamento
            empleados_dep[departamento - 1]++;

            // Uso de nuevo un array para obtener el sueldo base
            sueldo_base = sueldo_base_dep[departamento - 1];

            // calculo el bono segun la antigüedad
            bono = 0;
            if (antiguedad >= 10 && antiguedad <= 20) {
                bono = sueldo_base * de_10_a_20;
                empleados_con_bono++;
            }
            else if (antiguedad >= 21 && antiguedad <= 35) {
                bono = sueldo_base * de_21_a_35;
                empleados_con_bono++;
            }
            else if (antiguedad > 35) {
                bono = sueldo_base * mas_de_35;
                empleados_con_bono++;
            }

            // Sumo el sueldo base y el bono a los totales
            sueldos_iniciales += sueldo_base;
            monto_bonos += bono;
            sueldos_finales = sueldos_iniciales + monto_bonos;

            total_empleados++;
            cout << "Empleado capturado exitosamente." << endl;
            break;

        case 2:
            // Reporte completo con todos los 9 campos requeridos
            cout << "\nREPORTE FINAL" << endl;
            cout << "Empleados en Total: " << total_empleados << endl;
            
            // Uso por tercera vez un array para mostrar los empleados por departamento
            cout << "Empleados en Ventas: " << empleados_dep[0] << endl;
            cout << "Empleados en Contabilidad: " << empleados_dep[1] << endl;
            cout << "Empleados en Recursos Humanos: " << empleados_dep[2] << endl;
            cout << "Empleados en Soporte y Sistemas: " << empleados_dep[3] << endl;
            
            cout << "Empleados que reciben bono extra: " << empleados_con_bono << endl;
            cout << "Sueldos iniciales a pagar: $" << sueldos_iniciales << endl;
            cout << "Monto de los bonos otorgados: $" << monto_bonos << endl;
            cout << "Sueldos reales a pagar: $" << sueldos_finales << endl;
            break;

        case 3:
            cout << "\nLa ejecucion ha terminado" << endl;
            break;

        default:
            cout << "ERROR 67: Opcion no valida. Intente de nuevo." << endl;
            break;
        }

    } while (opcion != 3);

    return 0;
}