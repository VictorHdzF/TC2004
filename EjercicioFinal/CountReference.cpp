// Victor Hernandez Ferzuli A01022166
#include <iostream>

using namespace std;

class Child
{
public:
	int* p;
	Child(const Child& source);
	Child & operator = (const Child &source);

	Child()
	{
		p = new int;
	}
	~Child()
	{
		delete p; 
		p = NULL;
	}
};

Child::Child(const Child & source)
{
	p = new int[1];
	for (int i = 0; i < 1; i++)
		p[i] = source.p[i];
	//*(p) = *(source.p); // Otra forma
}

Child & Child::operator = (const Child & source)
{
	//delete p;
	if (this != &source)
		for (int i = 0; i < 1; i++)
			p[i] = source.p[i];
	/*else
		p = 0;*/

	return *this;
}

int main()
{
	Child a;
	Child b = a;
	*(a.p) = 5;
	cout << *(b.p) << endl;
}

