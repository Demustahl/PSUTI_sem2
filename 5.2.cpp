#include <iostream>
#include <locale.h>
#include "My_string.h"

using namespace std;

int My_string::strcmp(const My_string& str) const
{
	return len - str.len;
}

void My_string::strrev()
{
	char c;
	for (int i = 0, ii = len - 1; i < ii; i++, ii--) {
		c = s[i];
		s[i] = s[ii];
		s[ii] = c;
	}
}

void My_string::print(int num) const
{
	if (num >= len) num = len;
	for (int i = 0; i != num; i++) {
		cout << s[i];
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "");
	My_string w1("qwerty");
	My_string w2(w1);
	w2.assign("123");
	w2.concat("zxc", "123 $");
	cout << "w1:" << endl;
	w1.print();
	cout << "w2:" << endl;
	w2.print();
	cout << w1.strcmp(w2) << endl; // -
	cout << w2.strcmp(w1) << endl; // +
	cout << w1.strcmp("123456") << endl; // 0
	cout << "w1:" << endl;
	w1.print();
	w1.strrev();
	cout << "w1:" << endl;
	w1.print();
	cout << "w1(2):" << endl;
	w1.print(2);
	cout << "w2:" << endl;
	w2.print();
	cout << "w2(4):" << endl;
	w2.print(4);
	cout << "w2(20):" << endl;
	w2.print(20);
}