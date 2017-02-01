// Victor Hernandez Ferzuli	A01022166
#include <iostream>
using namespace std;

class Personaje
{
public:
	virtual void correr() = 0;
	virtual Personaje* clonar() = 0;
};

template <class SubClase>
class ClonPersonaje : public Personaje
{
public:
	virtual Personaje* clonar()
	{
		return new SubClase(dynamic_cast<SubClase&>(*this));
	}
};

class Principe : public ClonPersonaje<Principe>
{
public:
	void seleccionarArma()
	{
		cout << "El principe Selecciona su arma" << endl;
	}
	void atacar()
	{
		cout << "El principe ataca lentisimo" << endl;
	}
	void correr()
	{
		cout << "El principe corre rápido" << endl;
	}
};

class Princesa : public ClonPersonaje<Princesa>
{
public:
	void gritar()
	{
		cout << "La princesa grita mucho" << endl;
	}
	void correr()
	{
		cout << "La princesa corre medio lento" << endl;
	}
};

class Villano : public ClonPersonaje<Villano>
{
public:
	void atacar()
	{
		cout << "El villano ataca" << endl;
	}
	void atraparPrincesa()
	{
		cout << "El villano atrapa a la princesa" << endl;
	}
	void correr()
	{
		cout << "El villano no necesita correr" << endl;
	}
};

class VillanoVolador : public ClonPersonaje<VillanoVolador>
{
public:
	void correr()
	{
		cout << "También puede volar" << endl;
	}
};

class FactorySingleton
{
public:
	template<class T>
	static T* crearPersonaje()
	{
		T* personaje = new T;
		personaje->correr();
		return personaje;
	}
};

class FactoryPersonaje
{
protected:
	virtual Personaje* factoryMethod(string) = 0;
public:
	Personaje* fabricarPersonaje(string tipo)
	{
		Personaje* personaje = factoryMethod(tipo);
		personaje->correr();
		return personaje;
	}
};

class LazyInitialization : public FactoryPersonaje
{
public:
	Personaje* factoryMethod(string tipo)
	{
		if (tipo == "villano")
			return new Villano();
		if (tipo == "principe")
			return new Principe();
		if (tipo == "princesa")
			return new Princesa();
		if (tipo == "villanoVolador")
			return new VillanoVolador();
	}
};

int main()
{
	// Prototype
	Villano v;
	Princesa p;
	Principe pri;

	Personaje* pe = v.clonar();
	pe->correr();
	cout << endl;

	//FactoryMethod con Templates y Static
	Villano* enemigo = FactorySingleton::crearPersonaje<Villano>();
	Princesa* obejtivo = FactorySingleton::crearPersonaje<Princesa>();
	Principe* usuario = FactorySingleton::crearPersonaje<Principe>();
	cout << endl;

	//FactoryMethod con LazyInitialization
	FactoryPersonaje* personaje = new LazyInitialization();
	Personaje* pp = personaje->fabricarPersonaje("villano");
	personaje->fabricarPersonaje("principe");
	personaje->fabricarPersonaje("princesa");
	personaje->fabricarPersonaje("villanoVolador");
	cout << endl;

	return 1;
}