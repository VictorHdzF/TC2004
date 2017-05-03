// Victor Hernandez Ferzuli	A01022166
#include <iostream>
#include <string>

using namespace std;

class Spacecrafts;
class PlanetsExplorationShips;
class ColonizationShips;
class PlanetObservationShips;
class Asteroids;
class Stony;
class Iron;
class Planets;
class Desert;
class EarthAnalog;

class Spacecrafts
{
public:
	Spacecrafts()
	{
		cout << "	Spacecraft: " << endl;
	}
	string id;
	virtual void colision() = 0;
	virtual Spacecrafts* clonar() = 0;
	virtual void accept(Asteroids* a) = 0;
	virtual void accept(Planets* p) = 0;
	virtual void visit(Asteroids* a) = 0;
	virtual void visit(Planets* p) = 0;
};

template <class SubClase>
class ClonSpacecrafts : public Spacecrafts
{
public:
	virtual Spacecrafts* clonar()
	{
		return new SubClase(dynamic_cast<SubClase&>(*this));
	}
};

class PlanetsExplorationShips : public ClonSpacecrafts<PlanetsExplorationShips>
{
public:
	PlanetsExplorationShips()
	{
		cout << "		Planet Exploration Ships" << endl;
		id = "Planet Exploration Ships";
	}
	void colision()
	{
		cout << "PlanetsExplorationShips colisiono" << endl;
	}
	virtual void accept(Asteroids* v);
	virtual void accept(Planets* v);
	virtual void visit(Asteroids* a);
	virtual void visit(Planets* p);
};

class ColonizationShips : public ClonSpacecrafts<ColonizationShips>
{
public:
	ColonizationShips()
	{
		cout << "		Colonization Ships" << endl;
		id = "Colonization Ships";
	}
	void colision()
	{
		cout << "ColonizationShips colisiono" << endl;
	}
	virtual void accept(Asteroids* v);
	virtual void accept(Planets* v);
	virtual void visit(Asteroids* a);
	virtual void visit(Planets* p);
};

class PlanetObservationShips: public ClonSpacecrafts<PlanetObservationShips>
{
public:
	PlanetObservationShips()
	{
		cout << "		Planet Observation Ships" << endl;
		id = "Planet Observation Ships";
	}
	void colision()
	{
		cout << "PlanetObservationShips colisiono" << endl;
	}
	virtual void accept(Asteroids* v);
	virtual void accept(Planets* v);
	virtual void visit(Asteroids* a);
	virtual void visit(Planets* p);
};

class Asteroids
{
public:
	Asteroids()
	{
		cout << "	Asteroids: " << endl;
	}
	string id;
	virtual void colision() = 0;
	virtual Asteroids* clonar() = 0;

	virtual void accept(Spacecrafts* s) = 0;
	virtual void accept(Planets* p) = 0;
	virtual void visit(Spacecrafts* s) = 0;
	virtual void visit(Planets* p) = 0;
};

template <class SubClase>
class ClonAsteroids : public Asteroids
{
public:
	virtual Asteroids* clonar()
	{
		return new SubClase(dynamic_cast<SubClase&>(*this));
	}
};

class Stony : public ClonAsteroids<Stony>
{
public:
	Stony()
	{
		cout << "		Stony" << endl;
		id = "Asteroid Stony";
	}
	void colision()
	{
		cout << "Asteroid Stony colisiono" << endl;
	}

	virtual void accept(Spacecrafts* v);
	virtual void accept(Planets* v);
	virtual void visit(Spacecrafts* s);
	virtual void visit(Planets* p);
};

class Iron : public ClonAsteroids<Iron>
{
public:
	Iron()
	{
		cout << "		Iron" << endl;
		id = "Asteroid Iron";
	}
	void colision()
	{
		cout << "Asteroid Iron colisiono" << endl;
	}

	virtual void accept(Spacecrafts* v);
	virtual void accept(Planets* v);
	virtual void visit(Spacecrafts* s);
	virtual void visit(Planets* p);
};

class Planets
{
public:
	Planets()
	{
		cout << "	Planets: " << endl;
	}
	string id;
	virtual void colision() = 0;
	virtual Planets* clonar() = 0;

	virtual void accept(Spacecrafts* s) = 0;
	virtual void accept(Asteroids* a) = 0;
	virtual void visit(Spacecrafts* s) = 0;
	virtual void visit(Asteroids* a) = 0;
};

template <class SubClase>
class ClonPlanets: public Planets
{
public:
	virtual Planets* clonar()
	{
		return new SubClase(dynamic_cast<SubClase&>(*this));
	}
};

class Desert : public ClonPlanets<Desert>
{
public:
	Desert()
	{
		cout << "		Desert" << endl;
		id = "Planet Desert";
	}
	void colision()
	{
		cout << "Planet Desert Iron colisiono" << endl;
	}

	virtual void accept(Spacecrafts* v);
	virtual void accept(Asteroids* v);
	virtual void visit(Spacecrafts* s);
	virtual void visit(Asteroids* a);
};

class EarthAnalog : public ClonPlanets<EarthAnalog>
{
public:
	EarthAnalog()
	{
		cout << "		Earth Analog" << endl;
		id = "Planet EarthAnalog";
	}
	void colision()
	{
		cout << "EarthAnalog colisiono" << endl;
	}

	virtual void accept(Spacecrafts* v);
	virtual void accept(Asteroids* v);
	virtual void visit(Spacecrafts* s);
	virtual void visit(Asteroids* a);
};

class FactorySingleton
{
private:
	static FactorySingleton *inst;
public:
	static FactorySingleton *getInstance();
	template<class T>
	static T* crear()
	{
		cout << "Creando: " << endl;
		T* Elemento= new T;
		return Elemento;
	}
};
FactorySingleton * FactorySingleton::inst = nullptr;
FactorySingleton * FactorySingleton::getInstance()
{
	if (!inst)
		inst = new FactorySingleton();

	return inst;
}

void PlanetsExplorationShips::accept(Asteroids* v)
{
	v->visit(this);
}
void PlanetsExplorationShips::accept(Planets* v)
{
	v->visit(this);
}
void PlanetsExplorationShips::visit(Asteroids* a)
{	
	cout << a->id << "  collided with: " << id << endl;
}
void PlanetsExplorationShips::visit(Planets* p)
{
	cout << p->id << "  collided with: " << id << endl;
}
void ColonizationShips::accept(Asteroids* v)
{
	v->visit(this);
}
void ColonizationShips::accept(Planets* v)
{
	v->visit(this);
}
void ColonizationShips::visit(Asteroids* a)
{
	cout << a->id << "  collided with: " << id << endl;
}
void ColonizationShips::visit(Planets* p)
{
	cout << p->id << "  collided with: " << id << endl;
}
void PlanetObservationShips::accept(Asteroids* v)
{
	v->visit(this);
}
void PlanetObservationShips::accept(Planets* v)
{
	v->visit(this);
}
void PlanetObservationShips::visit(Asteroids* a)
{
	cout << a->id << "  collided with: " << id << endl;
}
void PlanetObservationShips::visit(Planets* p)
{
	cout << p->id << "  collided with: " << id << endl;
}
void Stony::accept(Spacecrafts* v)
{
	v->visit(this);
}
void Stony::accept(Planets* v)
{
	v->visit(this);
}
void Stony::visit(Spacecrafts* s)
{
	cout << s->id << " collided with: " << id << endl;
}
void Stony::visit(Planets* p)
{
	cout << p->id << " collided with: " << id << endl;
}
void Iron::accept(Spacecrafts* v)
{
	v->visit(this);
}
void Iron::accept(Planets* v)
{
	v->visit(this);
}
void Iron::visit(Spacecrafts* s)
{
	cout << s->id << " collided with: " << id << endl;
}
void Iron::visit(Planets* p)
{
	cout << p->id << " collided with: " << id << endl;
}
void Desert::accept(Spacecrafts* v)
{
	v->visit(this);
}
void Desert::accept(Asteroids* v)
{
	v->visit(this);
}
void Desert::visit(Spacecrafts* s)
{
	cout << s->id << " collided with: " << id << endl;
}
void Desert::visit(Asteroids* a)
{
	cout << a->id << " collided with: " << id << endl;
}
void EarthAnalog::accept(Spacecrafts* v)
{
	v->visit(this);
}
void EarthAnalog::accept(Asteroids* v)
{
	v->visit(this);
}
void EarthAnalog::visit(Spacecrafts* s)
{
	cout << s->id << " collided with: " << id << endl;
}
void EarthAnalog::visit(Asteroids* a)
{
	cout << a->id << " collided with: " << id << endl;
}

int main()
{
	//FactoryMethod con Templates y Static
	Spacecrafts* Nautillus = FactorySingleton::getInstance()->crear<PlanetsExplorationShips>();
	Spacecrafts* Enterprise = FactorySingleton::getInstance()->crear<ColonizationShips>();
	Spacecrafts* MilleniumFalcon = FactorySingleton::getInstance()->crear<PlanetObservationShips>();

	Asteroids* Phobos = FactorySingleton::getInstance()->crear<Stony>();
	Asteroids* Eros = FactorySingleton::getInstance()->crear<Iron>();
	Asteroids* BigS = FactorySingleton::getInstance()->crear<Iron>();

	Planets* Mars = FactorySingleton::getInstance()->crear<Desert>();
	Planets* Earth = FactorySingleton::getInstance()->crear<EarthAnalog>();
	Planets* Venus = FactorySingleton::getInstance()->crear<EarthAnalog>();
	cout << endl;

	Spacecrafts **sp= new Spacecrafts*[3];
	Asteroids **as = new Asteroids*[3];
	Planets **pl = new Planets*[3];

	sp[0] = Nautillus;
	sp[1] = Enterprise;
	sp[2] = MilleniumFalcon;

	as[0] = Phobos;
	as[1] = Eros;
	as[2] = BigS;

	pl[0] = Mars;
	pl[1] = Earth;
	pl[2] = Venus;

	for (int i = 0; i < 3; i++)
	{
		sp[i]->accept(as[i]);
		sp[i]->accept(pl[i]);
		as[i]->accept(sp[i]);
		as[i]->accept(pl[i]);
		pl[i]->accept(sp[i]);
		pl[i]->accept(as[i]);
	}

}