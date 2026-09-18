#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// FUNCION CON PASO POR REFERENCIA PARA MODIFICAR DIRECTO EL ORIGINAL
void guardar_valor(vector<double>& vec);
double convertir_d_r(int numero);
void imprimir_valores(const vector<double>& vec);

int main()
{

    // FORMA DE DECLARAR UN VECTOR
    vector<double> numeros(10);
    double valor = 0;

    guardar_valor(numeros);
    imprimir_valores(numeros);

    return 0;
}

void guardar_valor(vector<double>& vec)
{
    int numero = 0;
    for (int i = 0; i < 10; i++)
    {
        do
        {
            cout << "Ingrese un numero del 0 al 100: ";
            cin >> numero;

            if (numero < 0 || numero > 100)
            {
                cout << "Incorrecto, tiene que volver a ingresarlo " << endl;
            }
        } while (numero < 0 || numero > 100);

        // sin() espera valores en radianes, la forumla de abajo es para convertir grados a radianes para pasarlos directo
        double radianes = convertir_d_r(numero);

        double valor = sin(radianes);
        cout << "Valor del seno del numero: " << valor << endl;
        // numeros.push_back(valor); ESTA LINEA PODRIA SER USADA SI NO TUVIERA DECLARADOS LOS INDICES DEL VECTOR
        // CUANDO ESTAN DECLARADOS LOS INDICES LO MEJOR ES HACERLO COMO UN ARREGLO NORMAL: 
        vec[i] = valor;
    }
}

double convertir_d_r(int numero)
{
    double radianes = numero * (M_PI / 180.0);
    return radianes;
}

/*
Algo interesante de las funciones con los vectores ademas de su paso por referencia es que cuando se necesiten 
imprimir, es mucho mejor usar igual el paso por referencia y el candado CONST. EL paso por referencia hace que 
el compilador haga un acceso directo al vector original, sin hacer copias y optimizando el uso de la memoria 
(ahorita porque son muy pocos elementos no se nota pero en programas con millones de indices talvez si) y el
candado CONST le dice a c++ "Oye, este es solo un valor de lectura para que no vayas a hacer nada raro", es la misma
funcion de cuando se usa en un programa normal, prohibe modificar el valor haciendolo constante :)
*/
void imprimir_valores(const vector<double>& vec)
{
    cout << "--- Imprimir valores entre 0 y 0.5 ---" << endl;

    for (const auto& n : vec)
    {
        if (n >= 0 && n <= 0.5)
        {
            cout << "Valor: " << n << endl;
        }
    }
}