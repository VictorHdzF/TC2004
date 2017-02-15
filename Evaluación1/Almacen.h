// Victor Hernandez Ferzuli A01022166
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "Videojuego.h"

class Almacen
{
private:
	//static vector<Videojuego> *inv;

public:
	Almacen()
	{
	}
	int no_serie = 0;
	int g, j, op, num;
	float p, num2;
	string n, c;

	Videojuego* V;
	Videojuego* CL;

	vector <Videojuego*> inv;
	vector <Videojuego*> eli;

	/*static vector<Videojuego> *crearInventario()
	{
		if (!inv)
			inv = new vector<Videojuego>;
		return inv;
		cout << "Se creo inventario" << endl;
	}*/

	void crearInventario();
	void agregarVideojuego();
    void eliminarVideojuego();
	void undo();
	void ordenarVideojuegos();
	void buscarVideojuegos();
	void total();
    void imprimir();
	void modPrecio();

	int findNumero(int num);
	int findNombre(string n);

	void system();
};

void Almacen::crearInventario()
{
	cout << "Inventario ya creado" << endl;
}

void Almacen::agregarVideojuego()
{
	cout << "Genero: " << endl << "1. Estrategia" << endl << "2. Aventura" << endl << "3. Aprendizaje" << endl;
	cin >> g;
	if (g == 1) 
	{
		Videojuego* v = FactoryVideojuegos::crearVideojuego<Estrategia>();
		V = v;
	}
	else if (g == 2) 
	{
		Videojuego* v = FactoryVideojuegos::crearVideojuego<Aventura>();
		V = v;
	}
	else if (g == 3) 
	{
		Videojuego* v = FactoryVideojuegos::crearVideojuego<Aprendizaje>();
		V = v;
	}
	else if (g > 3)
	{
		cout << "Opcion Invalida" << endl << endl;
	}

	cout << "Nombre :  ";
	cin >> n;
	V->setNombre(n);

	cout << "Precio :  $ ";
	if (cin >> p) 
	{
		cin.clear();
		cin.ignore(numeric_limits < streamsize>::max(), '\n');
	}
	else 
	{
		cout << "Operacion cancelada, el precio debe contar SOLO con digitos" << endl << endl;
		return system();
	}
	V->setPrecio(p);

	cout << "Clasifiacion :  ";
	cin >> c;
	V->setClas(c);

	cout << "Jugadores :  ";
	cin >> j;
	V->setJugadores(j);

	V->setNumeroDeSerie(no_serie);
	no_serie++;

	cout << endl << "Listo!" << endl << endl;
	inv.push_back(V);
}

void Almacen::eliminarVideojuego()
{
	if (inv.size() > 0)
	{
		cout << "Eliminar por: " << endl << "1. Numero de Serie" << endl << "2. Nombre" << endl;
		cout << "Numero de Serie : ";
		cin >> g;
		if (g == 1)
		{
			cin >> num;
			if (findNumero(num) != -1)
			{
				eli.push_back(inv[findNumero(num)]);
				inv.erase(inv.begin() + (findNumero(num)));
			}
			else
				cout << "NO se encontro el Numero de Serie." << endl << endl;
		}
		else if (g == 2)
		{
			cout << "Nombre : ";
			cin >> n;
			if (findNombre(n) != -1)
			{
				eli.push_back(inv[findNombre(n)]);
				inv.erase(inv.begin() + (findNombre(n)));
			}
			else
				cout << "NO se encontro el Nombre." << endl << endl;
		}
		else if (g > 2)
			cout << "Opcion Invalida." << endl << endl;
	}
	else
		cout << "No hay videojuegos en el inventario." << endl << endl;
}

void Almacen::undo()
{
	if (eli.size() > 0) 
	{
		inv.push_back(eli.back());
		eli.pop_back();
		cout << "Operacion Undo." << endl << endl;
	}
	else
		cout << "No hay operaciones por re-hacer." << endl << endl;
}

void Almacen::ordenarVideojuegos()
{
	if (inv.size() > 0)
	{
		cout << "Ordenar por precio de: " << endl << "1. Menor a Mayor " << endl << "2. Mayor a Menor" << endl;
		cin >> g;
		if (g == 1)
		{
			sort(inv.begin(), inv.end(), [](Videojuego* a, Videojuego* b)
			{
				return (a->getPrecio() > b->getPrecio());
			});

		}
		else if (g == 2)
		{
			sort(inv.begin(), inv.end(), [](Videojuego* a, Videojuego* b)
			{
				return (a->getPrecio() < b->getPrecio());
			});
		}
		else if (g > 2)
			cout << "Opcion Invalida." << endl << endl;
	}
	else
		cout << "No hay videojuegos en el inventario." << endl << endl;
}

void Almacen::buscarVideojuegos()
{
	if (inv.size() > 0)
	{
		cout << "Buscar por: " << endl << "1. Numero de Serie" << endl << "2. Nombre" << endl;
		cin >> g;
		if (g == 1)
		{
			cout << "Numero de Serie : ";
			cin >> num;
			if (findNumero(num) != -1)
			{
				cout << setw(10) << "No_Serie" <<
					setw(11) << "Nombre" <<
					setw(13) << "Precio" << 
					setw(12) << "Clasificacion" << 
					setw(11) << "Jugadores" << "\n";
				cout << setw(10) << "# " << inv[findNumero(num)]->getNumeroDeSerie() <<
					setw(10) << inv[findNumero(num)]->getNombre() <<
					setw(10) << "$ " << inv[findNumero(num)]->getPrecio() <<
					setw(12) << inv[findNumero(num)]->getClas() <<
					setw(10) << inv[findNumero(num)]->getJugadores() << "\n";
			}
			else
				cout << "NO se encontro el Numero de Serie." << endl << endl;
		}
		else if (g == 2)
		{
			cout << "Nombre : ";
			cin >> n;
			if (findNombre(n) != -1)
			{
				cout << setw(10) << "No_Serie" <<
					setw(11) << "Nombre" <<
					setw(13) << "Precio" <<
					setw(12) << "Clasificacion" <<
					setw(11) << "Jugadores" << "\n";
				cout << setw(10) << "# " << inv[findNombre(n)]->getNumeroDeSerie() <<
					setw(10) << inv[findNombre(n)]->getNombre() <<
					setw(10) << "$ " << inv[findNombre(n)]->getPrecio() <<
					setw(12) << inv[findNombre(n)]->getClas() <<
					setw(10) << inv[findNombre(n)]->getJugadores() << "\n";
			}
			else
				cout << "NO se encontro el Nombre." << endl << endl;
		}
		else if (g > 2)
			cout << "Opcion Invalida." << endl << endl;
	}
	else
		cout << "No hay videojuegos en el inventario." << endl << endl;
}

void Almacen::total()
{
	cout << "Numero de videojuegos en el inventario: " << inv.size() << endl << endl;
}

void Almacen::imprimir()
{
	cout << "Inventario : " << inv.size() << endl;

	cout << setw(10) << "No_Serie" <<
		setw(11) << "Nombre" <<
		setw(13) << "Precio" << "\n";

	for (int i = inv.size() - 1; i >= 0; i--) {

		cout << setw(10) << "# " << inv[i]->getNumeroDeSerie() <<
			setw(10) << inv[i]->getNombre() <<
			setw(10) << "$ " << inv[i]->getPrecio() << "\n";
	}
}

void Almacen::modPrecio()
{
	if (inv.size() > 0)
	{
		cout << "Modificar precio: " << endl << "1. Aumentar" << endl << "2. Reducir" << endl;
		cin >> g;
		if (g <= 2 && g > 0)
		{
			cout << "Numero de Serie del Videojuego precio: ";
			cin >> num;
			if (findNumero(num) != -1)
			{
				if (g == 1)
				{
					cout << "Porcentaje de aumento :  %";
					cin >> num2;
					inv[findNumero(num)]->setPrecio((num2 / 100)*(inv[findNumero(num)]->getPrecio()) + (inv[findNumero(num)]->getPrecio()));
				}
				else if (g == 2)
				{
					cout << "Porcentaje de reduccion :  %";
					cin >> num2;
					inv[findNumero(num)]->setPrecio((inv[findNumero(num)]->getPrecio()) - (num2 / 100)*(inv[findNumero(num)]->getPrecio()));
				}
			}
			else
				cout << "NO se encontro el Numero de Serie." << endl << endl;
		}
		else
			cout << "Opcion Invalida." << endl << endl;
	}
	else
		cout << "No hay videojuegos en el inventario." << endl << endl;
}

int Almacen::findNumero(int num)
{
	for (int i = inv.size() - 1; i >= 0; i--)
	{
		if (num == inv[i]->getNumeroDeSerie())
			return i;
	}
	return -1;
}

int Almacen::findNombre(string n)
{
	for (int i = inv.size() - 1; i >= 0; i--) 
	{
		if (n == inv[i]->getNombre())
			return i;
	}
	return -1;
}

void Almacen::system()
{
	cout << "Chell A.S Inventario" << endl << "1.	Crear Inventario" << endl << "2.	Agregar videojuegos al inventario" << endl << "3.	Eliminar videojuegos del inventario" << endl << "4.	Undo" << endl << "5.	Ordenar inventario" << endl << "6.	Buscar Videojuegos" << endl << "7.	# Total de Elementos" << endl << "8.	Imprimir inventario" << endl << "9.	Modificar precio de producto"  << endl << "0.	Salir" << endl;
	cout << endl << "Chell A.S Videojuegos" << endl << "10.	Crear Videojuego" << endl << "11.	Clonar Videojuego" << endl;

	int opc = 1;

	while (opc != 0) {
		cin >> op;
		switch (op)
		{
		case 1:
		{
			crearInventario();
			return system();
			break;
		}
		case 2:
		{
			agregarVideojuego();
			return system();
			break;
		}
		case 3:
		{
			eliminarVideojuego();
			return system();
			break;
		}
		case 4:
		{
			undo();
			return system();
			break;
		}
		case 5:
		{
			ordenarVideojuegos();
			return system();
			break;
		}
		case 6:
		{
			buscarVideojuegos();
			return system();
			break;
		}
		case 7:
		{
			total();
			return system();
			break;
		}
		case 8:
		{
			imprimir();
			return system();
			break;
		}
		case 9:
		{
			modPrecio();
			return system();
			break;
		}
		case 10:
		{
			agregarVideojuego();
			return system();
			break;
		}
		case 11:
		{
			if (inv.size() != NULL)
			{
				cout << "Numero de Serie de Videojuego que desea Clonar:  ";
				cin >> num;
				if (inv.size() > num)
				{
					Videojuego* clon = inv[num]->clonar();
					CL = clon;
					inv.push_back(CL);
					cout << "Juego clonado y anadido al inventario" << endl << endl;
				}
				else
				{
					cout << "El numero de serie no es correcto" << endl;
				}

			}
			else
			{
				cout << "No hay juegos en el inventario" << endl << endl;
			}
			return system();
			break;
		}

		case 0:
			opc = 0;
			break;

		default:
			if (!(cin >> op)) {
				cin.clear();
				cin.ignore(numeric_limits < streamsize>::max(), '\n');
			}
			cout << "Elija una opcion" << endl;
			break;
		}
	}
}
