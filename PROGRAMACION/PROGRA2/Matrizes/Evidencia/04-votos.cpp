#include <iostream>
using namespace std;

const int ESTUDIANTES = 2;
const int COLUMNAS = 2; // 0. Nombre, 1. Voto

void registrar_voto(string votos[][COLUMNAS]);
void imprimir_votos(string votos[][COLUMNAS]);

int main()
{

    string votos[ESTUDIANTES][COLUMNAS];

    registrar_voto(votos);
    imprimir_votos(votos);

    return 0;
}

void registrar_voto(string votos[][COLUMNAS])
{
    for (int i = 0; i < ESTUDIANTES; i++)
    {
        cout << "ESTUDIANTE #" << i + 1 << endl;

        cout << "Ingrese su nombre: ";
        getline(cin, votos[i][0]);

        cout << "Ingrese el numero de planilla \n1. Planilla Roja \n2. Planilla verde \n3. Planilla azul \n:  ";
        cin >> votos[i][1];

        cin.ignore();

    }
}

void imprimir_votos(string votos[][COLUMNAS])
{
    int r = 0,v = 0,a = 0;
    for (int i = 0; i < ESTUDIANTES; i++)
    {
        cout << "ESTUDIANTE #" << i + 1 << endl;
        cout << "NOMBRE: " << votos[i][0] << endl;
        
        if (votos[i][1] == "1")
        {
            cout << "VOTO POR PLANILLA ROJA" << endl;
            r++;
        }
        else if (votos[i][1] == "2")
        {
            cout << "VOTO POR PLANILLA VERDE" << endl;
            v++;
        }
        else if (votos[i][1] == "3")
        {
            cout << "VOTO POR PLANILLA AZUL" << endl;
            a++;
        }
        else
        {
            cout << "VOTO INVALIDO O NO VOTO" << endl;
        }
    }
    cout << endl << "VOTOS PLANILLA" << endl;
    cout << "PLANILLA ROJA: " << r << endl;
    cout << "PLANILLA VERDE: " << v << endl;
    cout << "PLANILLA AZUL: " << a << endl;
}
