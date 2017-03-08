// Victor Hernandez Ferzuli A01022166
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Subject 
{
private:
	vector < class Observer * > views;
	string value, name;

public:
	void attach(Observer *obs) 
	{
		views.push_back(obs);
	}

	void setVal(string val)
	{
		value = val;
		notify();
	}

	string getVal() 
	{
		return value;
	}

	void setSubName(string _name)
	{
		name = _name;
	}

	string getSubName()
	{
		return name;
	}

	void notify();
};

class Observer 
{
protected:
	Subject *getSubject()
	{
		return subject;
	}

public:
	Subject *subject;

	Observer(Subject *sub) 
	{
		subject = sub;
		subject->attach(this);
	}

	void update() 
	{
		string content = getSubject()->getVal();
		string who = getSubject()->getSubName();
		cout << who << " said this: " << content << '\n';
	}
};

void Subject::notify() 
{

	for (int i = 0; i < views.size(); i++)
		views[i]->update();
}


int main()
{
	Subject Presidente;
	
	Observer Reforma(&Presidente);
	Observer Televisa(&Presidente);
	Observer NBC(&Presidente);

	Presidente.setSubName("Donald Trump");
	Presidente.setVal("Tremendous!");
	
	Presidente.setSubName("Pena Nieto");
	Presidente.setVal("Infrastuctrucshurr");
}