// Victor Hernandez Ferzuli		A01022166
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class timeStamp{
private:
	static timeStamp *inst;

public:
	timeStamp()
	{
	
	}

	static timeStamp *instance();

	virtual string getValue()
	{
		static time_t timeNow;
		time(&timeNow);
		return (ctime(&timeNow));
	}
};

timeStamp *timeStamp::inst = 0;

timeStamp *timeStamp::instance()
{
	if (!inst)
		inst = new timeStamp();

	return inst;
}

int main()
{
	cout << "El tiempo es: " << timeStamp::instance()->getValue() << endl;
	return 0;
}
