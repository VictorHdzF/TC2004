#include <iostream>
#include <string>
#include <vector>

using namespace std;

class DNS
{
	DNS *next;
public:
	DNS()
	{
		next = 0;
	}

	void add(DNS *n)
	{
		if (next)
			next->add(n);
		else
			next = n;
	}

	virtual void handle(string i)
	{
		if (next)
			next->handle(i);
		else
			cout << "No server has the domain :" << i << endl;
	}
};

class dominio
{
public:
	string ip;
	string url;
};

class Server1 : public DNS
{
public:
	Server1()
	{
		dominio d1; d1.ip = "8.8.8.8"; d1.url = "www.google.com"; dominios1.push_back(d1);
		dominio d2; d2.ip = "208.80.152.201"; d2.url = "www.wikipedia.org"; dominios1.push_back(d2);
	}

	vector<dominio> dominios1;

	void handle(string url)
	{
		for (int i = 0; i < 2; i++)
			if (dominios1[i].url == url)
			{
				cout << dominios1[i].ip << endl;
				break;
			}
			else
				DNS::handle(url);
	}
};

class Server2 : public DNS
{
public:
	Server2()
	{
		dominio d1; d1.ip = "72.247.244.88"; d1.url = "www.reddit.com"; dominios2.push_back(d1);
		dominio d2; d2.ip = "74.125.65.91"; d2.url = "www.youtube.com"; dominios2.push_back(d2);
	}

	vector<dominio> dominios2;

	void handle(string url)
	{
		for (int i = 0; i < 2; i++)
			if (dominios2[i].url == url)
			{
				cout << dominios2[i].ip << endl;
				break;
			}
			else
				DNS::handle(url);
	}
};

class Server3 : public DNS
{
public:
	Server3()
	{
		dominio d1; d1.ip = "98.137.149.56"; d1.url = "www.yahoo.com"; dominios3.push_back(d1);
		dominio d2; d2.ip = "69.10.25.46"; d2.url = "www.ign.com"; dominios3.push_back(d2);
	}

	vector<dominio> dominios3;

	void handle(string url)
	{
		for (int i = 0; i < 2; i++)
			if (dominios3[i].url == url)
			{
				cout << dominios3[i].ip << endl;
				break;
			}
			else
				DNS::handle(url);
	}
};

class Server4 : public DNS
{
public:
	Server4()
	{
		dominio d1; d1.ip = "199.59.149.230"; d1.url = "www.twitter.com"; dominios4.push_back(d1);
		dominio d2; d2.ip = "72.21.211.176"; d2.url = "www.amazon.com"; dominios4.push_back(d2);
	}

	vector<dominio> dominios4;

	void handle(string url)
	{
		for (int i = 0; i < 2; i++)
			if (dominios4[i].url == url)
			{
				cout << dominios4[i].ip << endl;
				break;
			}
			else
				DNS::handle(url);
	}
};

class Server5 : public DNS
{
public:
	Server5()
	{
		dominio d1; d1.ip = "65.55.175.254"; d1.url = "www.bing.com"; dominios5.push_back(d1);
		dominio d2; d2.ip = "207.97.227.239"; d2.url = "www.github.com"; dominios5.push_back(d2);
	}

	vector<dominio> dominios5;

	void handle(string url)
	{
		for (int i = 0; i < 2; i++)
			if (dominios5[i].url == url)
			{
				cout << dominios5[i].ip << endl;
				break;
			}
			else
				DNS::handle(url);
	}
};

int main()
{
	DNS* A = new Server1();
	DNS* B = new Server2();
	DNS* C = new Server3();
	DNS* D = new Server4();
	DNS* E = new Server5();

	A->add(B);
	A->add(C);
	A->add(D);
	A->add(E);

	A->handle("www.bing.com");
	A->handle("www.twitter.com");
}