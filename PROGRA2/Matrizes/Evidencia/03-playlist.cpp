#include <iostream>
using namespace std;

const int MAXIMOS = 10;
const int COLUMNAS = 2;

void guardar_canciones(string playlist[][COLUMNAS]);
void imprimir_playlist(string playlist[][COLUMNAS], string nombre);

int main()
{

    string playlist[10][COLUMNAS];
    string nombre;

    cout << "Ingrese su nombre para crear su playlist: ";
    cin >> nombre;

    guardar_canciones(playlist);
    imprimir_playlist(playlist, nombre);

    return 0;
}

void guardar_canciones(string playlist[][COLUMNAS])
{
    cin.ignore();
    for (int i = 0; i < MAXIMOS; i++)
    {
        cout << "CANCION #" << i + 1 << endl;

        cout << "Ingrese el nombre de la cancion: ";
        getline(cin, playlist[i][0]);

        cout << "Ingrese el nombre del artista o grupo: ";
        getline(cin, playlist[i][1]);
    }
}

void imprimir_playlist(string playlist[][COLUMNAS], string nombre)
{
    cout << "PLAYLIST DE " << nombre << endl << endl;
    for (int i = 0; i < MAXIMOS; i++)
    {
        cout << "CANCION #" << i + 1 << endl;
        cout << playlist[i][0] << endl;
        cout << "Nombre del artista o grupo: " << playlist[i][1] << endl;
    }
}
