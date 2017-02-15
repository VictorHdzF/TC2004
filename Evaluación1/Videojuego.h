// Victor Hernandez Ferzuli	A01022166
#include <iostream>
using namespace std;

class Videojuego
{
public:
	string nombre;
	int numeroDeSerie;
	float precio;
	string clasificacion;
	int jugadores;

	string getNombre();
	void setNombre(string n);

	int getNumeroDeSerie();
	void setNumeroDeSerie(int noS);

	float getPrecio();
	void setPrecio(float p);

	string getClas();
	void setClas(string c);

	int getJugadores();
	void setJugadores(int j);

	virtual Videojuego* clonar() = 0;

	virtual void concepcion() = 0;
	virtual void diseño() = 0;
	virtual void planificacion() = 0;
	virtual void produccion() = 0;
	virtual void pruebasDeAceptacion() = 0;

};


string Videojuego::getNombre()
{
	return nombre;
}

void Videojuego::setNombre(string n)
{
	nombre = n;
}

int Videojuego::getNumeroDeSerie()
{
	return numeroDeSerie;
}

void Videojuego::setNumeroDeSerie(int noS)
{
	numeroDeSerie = noS;
}

float Videojuego::getPrecio()
{
	return precio;
}

void Videojuego::setPrecio(float p)
{
	precio = p;
}

string Videojuego::getClas()
{
	return clasificacion;
}

void Videojuego::setClas(string c)
{
	clasificacion = c;
}

int Videojuego::getJugadores()
{
	return jugadores;
}

void Videojuego::setJugadores(int j)
{
	jugadores = j;
}

template <class SubClase>
class ClonVideojuego : public Videojuego
{
public:
	virtual Videojuego* clonar()
	{
		return new SubClase(dynamic_cast<SubClase&>(*this));
	}
};

class FactoryVideojuegos
{
public:
	template<class SubClase>
	static SubClase* crearVideojuego()
	{
		SubClase* productoFinal = new SubClase;

		productoFinal->nombre;
		productoFinal->numeroDeSerie;
		productoFinal->precio;
		productoFinal->clasificacion;
		productoFinal->jugadores;

		productoFinal->concepcion();
		productoFinal->diseño();
		productoFinal->planificacion();
		productoFinal->produccion();
		productoFinal->pruebasDeAceptacion();

		return productoFinal;
	}
};

class Estrategia : public ClonVideojuego<Estrategia>
{
public:

	void concepcion()
	{
		cout << "Concepcionando el videojuego de estrategia" << endl;
	}
	void diseño()
	{
		cout << "Diseñando el videojuego de estrategia" << endl;
	}
	void planificacion()
	{
		cout << "Planificando el videojuego de estrategia" << endl;
	}
	void produccion()
	{
		cout << "Produciendo el videojuego de estrategia" << endl;
	}
	void pruebasDeAceptacion()
	{
		cout << "Probando el videojuego de estrategia" << endl;
	}

};

class Aventura : public ClonVideojuego<Aventura>
{
public:

	void concepcion()
	{
		cout << "Concepcionando el videojuego de aventura" << endl;
	}
	void diseño()
	{
		cout << "Diseñando el videojuego de aventura" << endl;
	}
	void planificacion()
	{
		cout << "Planificando el videojuego de aventura" << endl;
	}
	void produccion()
	{
		cout << "Produciendo el videojuego de aventura" << endl;
	}
	void pruebasDeAceptacion()
	{
		cout << "Probando el videojuego de aventura" << endl;
	}

};

class Aprendizaje : public ClonVideojuego<Aprendizaje>
{
public:

	void concepcion()
	{
		cout << "Concepcionando el videojuego de aprendizaje" << endl;
	}
	void diseño()
	{
		cout << "Diseñando el videojuego de aprendizaje" << endl;
	}
	void planificacion()
	{
		cout << "Planificando el videojuego de aprendizaje" << endl;
	}
	void produccion()
	{
		cout << "Produciendo el videojuego de aprendizaje" << endl;
	}
	void pruebasDeAceptacion()
	{
		cout << "Probando el videojuego de aprendizaje" << endl;
	}

};
