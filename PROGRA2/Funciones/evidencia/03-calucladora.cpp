#include <iostream>
#include <cmath>
#include <string>

using namespace std;

float suma(float a, float b);
float resta(float a, float b);
float multiplicacion(float a, float b);
float division(float a, float b);
float raiz_c(float a);
float potencia(float a, float exponente);

int main()
{
    float a = 0;
    float b = 0;
    int opc = 0;
    float resultado = 0;
    bool bandera = true;
    string decision;


    while (bandera)
    {
        resultado = 0;

        cout << "Ingrese la opcion del menu que desee: \n1. Suma \n2. Resta \n3. Multiplicacion \n4. Division \n5. Raiz cuadrada \n6. Potencia \n: ";
        cin >> opc;

        if (opc >= 1 && opc <= 4)
        {
            cout << "Ingrese el primer numero: ";
            cin >> a;

            cout << "Ingrese el segundo numero: ";
            cin >> b;

            switch(opc)
            {
            case 1:
            {
                resultado = suma(a, b);
                break;
            }
            case 2:
            {
                resultado = resta(a, b);
                break;
            }
            case 3:
            {
                resultado = multiplicacion(a, b);
                break;
            }
            case 4:
            {
                resultado = division(a, b);
                if (resultado == 0)
                {
                    break;
                }
                else
                {
                    cout << "EL resultado es: " << resultado << endl;
                    break;
                }
            }
            default:
            {
                cout << "ESE NUMERO NO ESTA EN EL MENU NO SEA MENSOOO !!!";
                break;
            }
            } 
            cout << "El resultado es: " << resultado << endl;
        }
        else if (opc == 5)
        {
            cout << "Ingrese el numero para la raiz: ";
            cin >> a;

            if (a >= 0)
            {
                cout << "EL resultado es: " << raiz_c(a) << endl;
            }
            else
            {
                cout << "No se puede calcular la raiz de un numero negativo." << endl;
            }
        }
        else if (opc == 6)
        {
            cout << "Ingrese el numero: ";
            cin >> a;

            cout << "Ingrese el exponente: ";
            cin >> b;

            resultado = potencia(a, b);
            cout << "EL resultado es: " << resultado << endl;
        }
        else
        {
            cout << "ESA OPCION NO ESTA EN EL MENUUUU NO SEA MENSO JAAJJA !!!" << endl;
        }

        cout << "Desea salir del programa? si / no: ";
        cin >> decision;

        if (decision == "si")
        {
            bandera = false;
        }
        else
        {
            bandera = true;
            cout << "HOLA DE VUELTA !!! " << endl;
        }
    }

    cout << "Gracias por entrar al programa, adios!!!!";
    
    return 0;
}

float suma(float a, float b)
{
    return a + b;
}

float resta(float a, float b)
{
    return a - b;
}

float multiplicacion(float a, float b)
{
    return a * b;
}

float division(float a, float b)
{
    if (b == 0)
    {
        cout << "ERROORRR NO PUDES DIVIDIR ENTRE 0" << endl;
        return 0;
    }
    return a / b;
}

float raiz_c(float a)
{
    return sqrt(a);
}

float potencia(float a, float exponente)
{
    return pow(a, exponente);
}