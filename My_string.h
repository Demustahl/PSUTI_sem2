#include <iostream>
#include <locale.h>
#include <assert.h>
#define CRT_SECURE_NO_WARNINGS

using namespace std;

class My_string {
public:
	My_string() :len(0)
	{
		s = new char[1];
		assert(s != 0);
		s[0] = 0;
	}
	My_string(const My_string& str); // копирующий конструктор
	My_string(const char* p); // преобразующий конструктор
	~My_string()
	{
		delete[] s;
	}
	void assign(const My_string& str);
	void print() const
	{
		cout << s << endl;
	}
	void concat(const My_string& a, const My_string& b);
	int strcmp(const My_string& str) const;
	void strrev();
	void print(int num) const;
private:
	char* s;
	int len;
};

My_string::My_string(const My_string& str) :len(str.len)
{
	s = new char[len + 1];
	assert(s != 0);
	strcpy(s, str.s);
}

My_string::My_string(const char *p) :len(strlen(p))
{
	s = new char[len + 1];
	assert(s != 0);
	strcpy(s, p);
}

void My_string::assign(const My_string& str)
{
	if (this == &str) return;
	delete[] s;
	len = str.len;
	s = new char[len + 1];
	assert(s != 0);
	strcpy(s, str.s);
}

void My_string::concat(const My_string& a, const My_string& b)
{
	char* temp = new char[a.len + b.len + 1];
	len = a.len + b.len;
	strcpy(temp, a.s);
	strcat(temp, b.s);
	delete[] s;
	s = new char[len + 1];
	assert(s != 0);
	strcpy(s, temp);
}