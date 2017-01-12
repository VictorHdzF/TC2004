#include <iostream>
#include <ctime>
#include <string>

using namespace std;

void main()
{
	static time_t timeNow;

	time(&timeNow);

	cout << ctime(&timeNow) << endl;
}
