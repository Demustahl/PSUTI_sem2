#include <iostream>
#include <locale.h>

using namespace std;

class Mod_int {
private:
	int v;
public:
	Mod_int(int vv = 0)
	{
		v = vv;
	}
	void print()
	{
		cout << "v = " << v << endl;
	}
	void add(int i);
};