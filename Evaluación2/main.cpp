#include<iostream>

using namespace std;

class Main
{
public:
	void printAllDocuments(Documents** d, int countDocs, Printers** p, int countPrinters)
	{
		for (int i = 0; i < countDocs; i++)
		{
			for (int j = 0; j < countPrinters; j++)
			{
				d[i].accept(p[i]);
			}
		}
	}
};

class Visitor;
class Documents; 

class Printers
{
public:
	string quienSoy;
	virtual void accept(Visitor*, Documents* d) = 0;
};

class Laser : public Printers
{
public:
	Laser()
	{
		quienSoy = "Laser";
	}
	void accept(Visitor* v, Documents* d);
};

class Inyeccion : public Printers
{
public:
	Inyeccion()
	{
		quienSoy = "Inyeccion";
	}
	void accept(Visitor* v, Documents* d);
};

class PDF : public Printers
{
public:
	PDF()
	{
		quienSoy = "PDF";
	}
	void accept(Visitor* v, Documents* d);
};

class Postscript : public Printers
{
public:
	Postscript()
	{
		quienSoy = "Postscript";
	}
	void accept(Visitor* v, Documents* d);
};


void Laser::accept(Visitor* v, Documents* d)
{
	v->visit(this, d);
}

void Inyeccion::accept(Visitor* v, Documents* d)
{
	v->visit(this, d);
}

void PDF::accept(Visitor* v, Documents* d)
{
	v->visit(this, d);
}

void Postscript::accept(Visitor* v, Documents* d)
{
	v->visit(this, d);
}

class Documents
{
public:
	string quienSoy;
	virtual void printOn(Printers* p) = 0;
	static int countDocs;
};
int Documents::countDocs = 0;

class TextoSimple : public Documents
{
public:
	TextoSimple()
	{
		quienSoy = "TextoSimple";
	}
	void printOn(Printers* p);
};

class TextoFormato : public Documents
{
public:
	TextoFormato()
	{
		quienSoy = "TextoFormato";
	}
	void printOn(Printers* p);
};

class Imagenes : public Documents
{
public:
	Imagenes()
	{
		quienSoy = "Imagenes";
	}
	void printOn(Printers* p);
};

void TextoSimple::printOn(Printers* p)
{
	p->accept(this);
}

void TextoFormato::printOn(Printers* p)
{
	p->accept(this);
}

void Imagenes::printOn(Printers* p)
{
	p->accept(this);
}

class Visitor
{
public:
	string quienSoy;

	virtual void visit(TextoSimple* ts) = 0;
	virtual void visit(TextoFormato* tf) = 0;
	virtual void visit(Imagenes* i) = 0;

	virtual void visit(Laser* la, Documents *d) = 0;
	virtual void visit(Inyeccion* in, Documents *d) = 0;
	virtual void visit(PDF* pdf, Documents *d) = 0;
	virtual void visit(Postscript* pos, Documents *d) = 0;

	template <class T>
	static Visitor* getInstance() {
		static T instance;
		return &instance;
	}
};

class Print : public Visitor
{
public:
	void visit(Printers* p, Documents* d)
	{
		cout << "Printing document: " << d->quienSoy << endl;
		cout << "On printer: " << p->quienSoy << endl;
	}
};


int main() {
	/*Visitor* a = Visitor::getInstance<AddDocuments>();
	Visitor* c = Visitor::getInstance<CountDocuments>();
	Visitor* p = Visitor::getInstance<ImpresionDoc>();*/
	Visitor* laser;

	//Main m;
	
	Laser la;
	TextoSimple ts;

	 ts.quienSoy;

	Documents* d[] = { new TextoSimple, new TextoFormato, new Imagenes };

	//m.printAllDocuments(d[],c, )

	//d[0]->accept(laser);


}