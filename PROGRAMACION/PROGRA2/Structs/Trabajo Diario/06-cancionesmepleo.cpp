#include <iostream>
#include <string>
using namespace std;

const int MAXIMO = 100;

struct Cancion
{
	string artista;
	string titulo;
	long int duracion;
	double tamanoFichero;
};

void guardar(Cancion canciones[MAXIMO], int& total);
void menu(Cancion canciones[MAXIMO], int& total);

int main()
{
	Cancion canciones[MAXIMO];
	int total = 0;

	menu(canciones, total);

	return 0;
}

void guardar(Cancion canciones[MAXIMO], int& total)
{
	if (total >= MAXIMO)
	{
		cout << "REGISTROS LLENOS" << endl;
	}
	else
	{
		int opc = 0;
		cout << "BIENVENIDO A GUARDAR" << endl;
		cout << "CUANTAS CANCIONES QUIERE GUARDAR? :";
		cin >> opc;
		if (opc <= 0 or (opc + total) > MAXIMO)
		{
			cout << "NO PUEDE GUARDAR ESAS CANCIONES" << endl;
		}
		else
		{
			for (int i = 0; i < opc; i++)
			{
				cout << "CANCION #" << total + 1 << endl;
				cout << "Ingrese el nombre de la cancion: ";
				cin >> ws;
				getline(cin, canciones[total].titulo);

				cout << "Ingrese el artista: ";
				cin >> ws;
				getline(cin, canciones[total].artista);

				cout << "Ingrese la duracion en segundos: ";
				cin >> canciones[total].duracion;

				cout << "Ingrese el peso en KB: ";
				cin >> canciones[total].tamanoFichero;

				total++;
			}
		}
	}
}

void menu(Cancion canciones[MAXIMO], int& total)
{
	int opcion;

	do
	{
		cout << "\nMENU DE CANCIONES" << endl;
		cout << "1. Guardar canciones" << endl;
		cout << "2. Imprimir los datos de todas las canciones" << endl;
		cout << "3. Imprimir los titulos de todas las canciones" << endl;
		cout << "4. Buscar texto en titulo o artista" << endl;
		cout << "5. Salir" << endl;
		cout << "Seleccione una opcion: ";
		cin >> opcion;

		switch (opcion)
		{
			case 1:
				guardar(canciones, total);
				break;

			case 2:
				if (total == 0)
				{
					cout << "NO HAY CANCIONES REGISTRADAS" << endl;
					break;
				}

				for (int i = 0; i < total; i++)
				{
					cout << "\nCANCION #" << i + 1 << endl;
					cout << "Titulo: " << canciones[i].titulo << endl;
					cout << "Artista: " << canciones[i].artista << endl;
					cout << "Duracion: " << canciones[i].duracion
						<< " segundos" << endl;
					cout << "Tamano: " << canciones[i].tamanoFichero
						<< " KB" << endl;
				}
				break;

			case 3:
				if (total == 0)
				{
					cout << "NO HAY CANCIONES REGISTRADAS" << endl;
					break;
				}

				cout << "\nTITULOS DE LAS CANCIONES:" << endl;
				for (int i = 0; i < total; i++)
				{
					cout << i + 1 << canciones[i].titulo << endl;
				}
				break;

			case 4:
			{
				string texto;
				bool encontrada = false;

				cout << "Ingrese el texto a buscar: ";
				cin >> ws;
				getline(cin, texto);

				for (int i = 0; i < total; i++)
				{
					if (canciones[i].artista == texto ||
						canciones[i].titulo == texto)
					{
						cout << "\nCANCION #" << i + 1 << endl;
						cout << "Titulo: " << canciones[i].titulo << endl;
						cout << "Artista: " << canciones[i].artista << endl;
						encontrada = true;
					}
				}

				if (!encontrada)
				{
					cout << "NO SE ENCONTRARON COINCIDENCIAS" << endl;
				}
				break;
			}

			case 5:
				cout << "Saliendo del menu, gracias por visitar" << endl;
				break;

			default:
				cout << "OPCION INVALIDA. ELIJA UNA OPCION DEL 1 AL 5"
					<< endl;
		}
	} while (opcion != 5);
}
