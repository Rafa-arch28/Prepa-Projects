#include <iostream>
#include <string>
using namespace std;

struct Cancion
{
	string artista;
	string titulo;
	long int duracion;
	double tamanoFichero;
};

int main()
{

    Cancion cancion;

    cout << "Ingrese el artista: ";
    cin >> ws;
    getline(cin, cancion.artista);

    cout << "Ingrese el titulo: ";
    cin >> ws;
    getline(cin, cancion.titulo);

    cout << "Ingrese la duracion en segundos: ";
    cin >> cancion.duracion;

    cout << "Ingrese el tamano del fichero (kB): ";
    cin >> cancion.tamanoFichero;

    cout << "Titulo: " << cancion.titulo << endl;
    cout << "Artista: " << cancion.artista << endl;
    cout << "Duracion (s): " << cancion.duracion << endl;
    cout << "Tamano del fichero (kB): " << cancion.tamanoFichero << " kB" << endl;

    return 0;
}