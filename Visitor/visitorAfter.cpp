#include<iostream>

using namespace std;

template<class T>
class Visitor;

template<class T>
class Number
{
protected:
	string quienSoy;
public:
	string getQuienSoy() { return quienSoy; }
	virtual void accept(Visitor<T>*) = 0;
};

class Integer : public Number<class T>
{
public:
	Integer()
	{
		quienSoy = "Integer";
	}
	static int countInts;
	void accept(Visitor<T>*);
};
int Integer::countInts = 0;

class Double : public Number<class T>
{
public:
	Double()
	{
		quienSoy = "Double";
	}
	static int countDouble;
	void accept(Visitor<T>*);
};
int Double::countDouble = 0;

template<class T>
class Visitor
{
public:
	Visitor() { inst = this; }
	static Visitor* inst;

	virtual void visit(Integer*) = 0;
	virtual void visit(Double*) = 0;

	static Visitor* getInstance() 
	{
		if (inst != 0)
			return inst;
		else
		{
			Visitor();
			return inst;
		}
	}
};

class PresentVisitor : public Visitor<class T>
{
public:

	void visit(Integer* i)
	{
		cout << i->getQuienSoy();
	}
	void visit(Double* d)
	{
		cout << d->getQuienSoy();
	}
};

class CountVisitor : public Visitor<class T>
{
public:
	void visit(Integer* i)
	{
		cout << Integer::countInts;
	}
	void visit(Double* i)
	{
		cout << Double::countDouble;
	}
};

class AddVisitor : public Visitor<class T>
{
public:
	void visit(Integer*)
	{
		Integer::countInts++;
	}
	void visit(Double*)
	{
		Double::countDouble++;
	}
};

void Double::accept(Visitor<T>* v)
{
	v->visit(this);
}

void Integer::accept(Visitor<T>* v)
{
	v->visit(this);
}


int main()
{
	/*AddVisitor a;
	CountVisitor c;
	PresentVisitor* p = PresentVisitor::getInstance();*/

	Visitor<AddVisitor>* add = Visitor<AddVisitor>::getInstance();

	Number<T>* n[] = { new Integer, new Double};

	for (int i = 0; i< 5; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			n[j]->accept(add);
		}
	}

	/*n[0]->accept(p);
	n[0]->accept(&c);
	cout << endl;
	n[1]->accept(p);
	n[1]->accept(&c);*/
}
